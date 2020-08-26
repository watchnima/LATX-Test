#include <stdio.h>
#include "../distorm/include/distorm.h"
#include "tools/distorm-helper.h"

#define MAX_INSTRUCTIONS 1000

bool distorm_display(const unsigned char* code, int codeLen)
{
  _DecodeResult res;
	_DecodedInst decodedInstructions[MAX_INSTRUCTIONS];
  uint32_t decodedInstructionsCount = 0, next;
  _OffsetType offset = 0;

	while (1) {
		res = distorm_decode(offset, code, codeLen, Decode32Bits, decodedInstructions,
            MAX_INSTRUCTIONS, &decodedInstructionsCount);
		if (res == DECRES_INPUTERR) {
			return false;
		}

		for (int i = 0; i < decodedInstructionsCount; i++) {
			printf("%08x (%02d) %-24s %s%s%s\r\n",
        (uint32_t)decodedInstructions[i].offset,
        decodedInstructions[i].size,
        (char*)decodedInstructions[i].instructionHex.p,
        (char*)decodedInstructions[i].mnemonic.p,
        decodedInstructions[i].operands.length != 0 ? " " : "",
        (char*)decodedInstructions[i].operands.p);
    }

		if (res == DECRES_SUCCESS) break; // All instructions were decoded.
		else if (decodedInstructionsCount == 0) break;

		// Synchronize:
		next = (uint32_t)(decodedInstructions[decodedInstructionsCount-1].offset
           - offset);
		next += decodedInstructions[decodedInstructionsCount-1].size;
		// Advance ptr and recalc offset.
		code += next;
		codeLen -= next;
		offset += next;
	}
  return true;
}
