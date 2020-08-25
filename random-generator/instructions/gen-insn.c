#include "latxtest-common.h"
#include "random-generator/instructions/instruction.h"
#include "random-generator/instructions/gen-operand.h"

/*
 * T Y P I C A L    B I N A R Y
 */

LATXT_OPERANDS_TYPE typical_binary[19] = {
	R8_IMM8,R16_IMM8,R16_IMM16,R32_IMM8,R32_IMM32,
	MEM8_IMM8,MEM16_IMM8,MEM16_IMM16,MEM32_IMM8,MEM32_IMM32,
	R8_R8,R16_R16,R32_R32,
  MEM8_R8,MEM16_R16,MEM32_R32,
  R8_MEM8,R16_MEM16,R32_MEM32
};

struct operands_table {
  LATXT_OPCODE_TYPE src1;
  LATXT_OPCODE_TYPE src2;
};

struct operands_table operandsTable[] = {
#define latxt_define_operands(a, b, c) {b, c},
#include "random-generator/instructions/insn-operands.h"
};
#undef latxt_define_operands

struct opcodeInfo {
  uint8_t len;
  uint8_t bytes[3];
};

struct operandsInfo {
  uint32_t bytes[4];
};

/* operands type in mod r/m form */
typedef enum {
  /*          0x00 .. 0x07 */
  EbGb,
  EvGv,
  GbEb,
  GvEv,
  ALIb,
  eAXIz,

  /*          0x80 .. 0x87 */
  EbIb,
  EvIz,
  //EbIb_i64
  EvIb,

  MODRM_LAST
} LATXT_OPCODE_MODRM;

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
operands_type_to_rmform(struct i386_insn_predef_info *predef_info)
{
  LATXT_OPERANDS_TYPE operandsType = predef_info->operandsType;
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

static uint8_t gen_opcode(uint8_t *opcode_buf, 
                          struct i386_insn_predef_info *predef_info)
{
  uint8_t opcode_len = -1;
  LATXT_OPCODE_MODRM modrm;
  modrm = operands_type_to_rmform(predef_info);
  assert(modrm < MODRM_LAST);
  struct opcodeInfo *curr_opcode = &OpcodeMap[predef_info->opcodeType][modrm];
  opcode_len = curr_opcode->len;
  for (int i = 0; i < curr_opcode->len; ++i) {
    opcode_buf[i] = curr_opcode->bytes[i];
  }
  return opcode_len;
}

extern gen_opnd_func_type gen_operand_funcs[OPERAND_LAST];

static uint8_t gen_operands(uint8_t *operands_buf,
                            struct i386_insn_predef_info *predef_info)
{
  LATXT_OPCODE_TYPE opcodeType = predef_info->opcodeType;
  LATXT_OPERANDS_TYPE operandsType = predef_info->operandsType;
  LATXT_OPERAND_TYPE src1Type, src2Type;
  src1Type = operandsTable[operandsType].src1;
  src2Type = operandsTable[operandsType].src2;
  struct latxt_operand src1 =
  {
    .type = src1Type,
    .len = 0,
    .bytes = operands_buf
  };
  gen_operand_funcs[src1Type](&src1);
  struct latxt_operand src2 =
  {
    .type = src2Type,
    .len = 0,
    .bytes = operands_buf + src1.len
  };
  gen_operand_funcs[src2Type](&src2);
  return src1.len + src2.len;
}

uint8_t gen_random_insn(X86_INSN* insn_seed) {
  uint8_t opcode_len = 0, operands_len = 0;
  char *insn_buf = insn_seed->bytes;
  struct i386_insn_predef_info *predef_info = &insn_seed->predef_info;

  if ((opcode_len = gen_opcode(insn_buf, predef_info)) == -1)
    return false;
  if ((operands_len = gen_operands(insn_buf + opcode_len, predef_info)) == -1)
    return false;
  insn_seed->insn_len = opcode_len + operands_len;
  return true;
}
