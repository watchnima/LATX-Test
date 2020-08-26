#include "latxtest-common.h"
#include "tools/insn-display.h"
#include "tools/distorm-helper.h"

void display_codes(char *code, uint32_t code_len)
{
  if (!distorm_display((const unsigned char *)code, (int)code_len)) {
    latxwarning("Distorm display error");
  }
}
