#include "latxtest-common.h"
#include "generator/instructions/instruction.h"
#include "generator/instructions/gen-operands.h"


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
  LATXT_OPCODE_TYPE src1_type;
  LATXT_OPCODE_TYPE src2_type;
  LATXT_OPCODE_TYPE src3_type;
  LATXT_OPCODE_TYPE src4_type;
};

struct operands_table operandsTable[] = {
#define latxt_define_operands(a, src1, src2, src3, src4) {src1, src2, src3, src4},
#include "generator/instructions/insn-operands.h"
};
#undef latxt_define_operands

struct operandsInfo {
  uint32_t bytes[4];
};

static void
oprand_init(struct latxt_operand *opnd, LATXT_OPERAND_TYPE opnd_type,
  char *opnd_buf)
{
  opnd->type = opnd_type;
  opnd->len = 0;
  opnd->bytes = opnd_buf;
}

void gen_none(struct latxt_operand *opnd)
{
  return ;
}

typedef void (*gen_opnd_func_type)(struct latxt_operand*);

gen_opnd_func_type gen_operand_funcs[OPERAND_LAST] = {
#define latxt_define_operand(a, b) b,
#include "generator/instructions/insn-operand.h"
};
#undef latxt_define_operand

uint8_t gen_operands(uint8_t *operands_buf,
                            struct latxt_i386_insn_predef_info *predef_info)
{
  uint8_t operands_len = 0;
  LATXT_OPERAND_TYPE src1Type, src2Type, src3Type, src4Type;
  LATXT_OPERANDS_TYPE operandsType = predef_info->operands.type;
  /* decode operand's type from operands type */
  src1Type = operandsTable[operandsType].src1_type;
  src2Type = operandsTable[operandsType].src2_type;
  src3Type = operandsTable[operandsType].src3_type;
  src4Type = operandsTable[operandsType].src4_type;

  /* generate operand src1, src2, src3 */
  struct latxt_operand src1, src2, src3, src4;
  oprand_init(&src1, src1Type, operands_buf + operands_len);
  gen_operand_funcs[src1Type](&src1);
  operands_len += src1.len;
  oprand_init(&src2, src2Type, operands_buf + operands_len);
  gen_operand_funcs[src2Type](&src2);
  operands_len += src2.len;
  oprand_init(&src3, src3Type, operands_buf + operands_len);
  gen_operand_funcs[src3Type](&src3);
  operands_len += src3.len;
  oprand_init(&src4, src4Type, operands_buf + operands_len);
  gen_operand_funcs[src4Type](&src4);
  operands_len += src4.len;

  return operands_len;
}
