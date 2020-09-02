#include "latxtest-common.h"
#include "generator/instructions/instruction.h"
#include "generator/instructions/gen-prefix.h"
#include "generator/instructions/gen-opcode.h"
#include "generator/instructions/gen-modrm-sib.h"
#include "generator/instructions/gen-operands.h"

uint8_t gen_random_insn(X86_INSN* insn_seed)
{
  uint8_t prefix_len = 0;
  uint8_t opcode_len = 0;
  uint8_t modrm_len = 0;
  uint8_t operands_len = 0;
  uint8_t insn_len = 0;
  char *insn_buf = insn_seed->bytes;
  struct latxt_i386_insn_predef_info *predef_info = &insn_seed->predef_info;

  if ((prefix_len = gen_prefix(insn_buf, predef_info)) == -1)
    return -1;
  insn_len += prefix_len;
  if ((opcode_len = gen_opcode(insn_buf + insn_len, predef_info)) == -1)
    return -1;
  insn_len += opcode_len;
  if ((modrm_len = gen_modrm_sib(insn_buf + insn_len, predef_info)) == -1)
    return -1;
  insn_len += modrm_len;
  if ((operands_len = gen_operands(insn_buf + insn_len, predef_info)) == -1)
    return -1;
  insn_len += operands_len;
  insn_seed->insn_len = insn_len;
  return insn_len;
}
