#include "latxtest-common.h"
#include "random-generator/instructions/instruction.h"
#include "random-generator/instructions/gen-opcode.h"

struct opcodeInfo {
  uint8_t len;
  uint8_t bytes[3];
};

/* map { opcode type, operands mode r/m form } to opcode bytes */
struct opcodeInfo OpcodeMap[X86_ISA_LAST][MODRM_LAST] = 
{
  [X86_ISA_ADD][EbGb] = 
  {
    .len = 1,
    .bytes = {0x00}
  },
  [X86_ISA_ADD][EvGv] = 
  {
    .len = 1,
    .bytes = {0x01}
  },
  [X86_ISA_ADD][GbEb] = 
  {
    .len = 1,
    .bytes = {0x02}
  },
  [X86_ISA_ADD][GvEv] = 
  {
    .len = 1,
    .bytes = {0x03}
  },
  [X86_ISA_ADD][ALIb] = 
  {
    .len = 1,
    .bytes = {0x04}
  },
  [X86_ISA_ADD][eAXIz] = 
  {
    .len = 1,
    .bytes = {0x05}
  },

  [X86_ISA_ADD][EbIb] = 
  {
    .len = 1,
    .bytes = {0x80}
  },
  [X86_ISA_ADD][EbIb] = 
  {
    .len = 1,
    .bytes = {0x81}
  },
  [X86_ISA_ADD][EbIb] = 
  {
    .len = 1,
    .bytes = {0x83}
  }
};

static LATXT_OPCODE_MODRM 
operands_type_to_rmform(struct latxt_i386_insn_predef_info *predef_info)
{
  LATXT_OPERANDS_TYPE operandsType = predef_info->operands.type;
  LATXT_OPCODE_MODRM modrm = MODRM_LAST;
  switch(operandsType) {
    case R8_R8:
    case MEM8_R8:
      modrm = EbGb;
      break;
    case R16_R16:
    case MEM16_R16:
    case R32_R32:
    case MEM32_R32:
      modrm = EvGv;
      break;
    case R8_MEM8:
    /* TODO: R8_R8 is belong to both EbGb and GbEb */
      modrm = GbEb;
      break;
    case R16_MEM16:
    case R32_MEM32:
    /* TODO: R16_R16 and R32_R32 are belong to both EvGv and GvEv */
      modrm = GvEv;
      break;
    case R8_IMM8:
    case MEM8_IMM8:
      modrm = EbIb;
      break;
    case R16_IMM16:
    case MEM16_IMM16:
    case R32_IMM32:
    case MEM32_IMM32:
      modrm = EvIz;
      break;
    case R16_IMM8:
	  case MEM16_IMM8:
    case R32_IMM8:
    case MEM32_IMM8:
      modrm = EvIb;
      break;
    default:
      perror("Wrong operandsType! Orz");
      abort();
      break;
  }
  return modrm;
}

uint8_t gen_opcode(uint8_t *opcode_buf, 
                          struct latxt_i386_insn_predef_info *predef_info)
{
  uint8_t opcode_len = -1;
  LATXT_OPCODE_MODRM modrm;
  modrm = operands_type_to_rmform(predef_info);
  assert(modrm < MODRM_LAST);
  struct opcodeInfo *curr_opcode = &OpcodeMap[predef_info->opcode.type][modrm];
  opcode_len = curr_opcode->len;
  for (int i = 0; i < curr_opcode->len; ++i) {
    opcode_buf[i] = curr_opcode->bytes[i];
  }
  return opcode_len;
}
