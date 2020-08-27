#include "latxtest-common.h"
#include "random-generator/instructions/instruction.h"
#include "random-generator/instructions/gen-prefix.h"
#include "random-generator/instructions/gen-opcode.h"
#include "random-generator/instructions/gen-operands.h"

uint8_t gen_random_insn(X86_INSN* insn_seed) {
  uint8_t opcode_len = 0, operands_len = 0;
  char *insn_buf = insn_seed->bytes;
  struct latxt_i386_insn_predef_info *predef_info = &insn_seed->predef_info;

  if ((opcode_len = gen_opcode(insn_buf, predef_info)) == -1)
    return false;
  if ((operands_len = gen_operands(insn_buf + opcode_len, predef_info)) == -1)
    return false;
  insn_seed->insn_len = opcode_len + operands_len;
  return true;
}
