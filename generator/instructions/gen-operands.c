#include "latxtest-common.h"
#include "generator/instructions/instruction.h"
#include "generator/instructions/gen-operands.h"

#define random(x) (rand() % x)

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
#include "generator/instructions/insn-operands.h"
};
#undef latxt_define_operands

struct operandsInfo {
  uint32_t bytes[4];
};

void gen_none(struct latxt_operand *opnd)
{
  return ;
}

void gen_r8(struct latxt_operand *opnd)
{
  return ;
}

/*TODO: realize */
void gen_r16(struct latxt_operand *opnd)
{
  return ;
}

/*TODO: realize */
void gen_r32(struct latxt_operand *opnd)
{
  return ;
}

void gen_imm8(struct latxt_operand *opnd)
{
  opnd->bytes[0] = (uint8_t)random(0x7f);
  opnd->len = 1;
  return ;
}

/*TODO: realize */
void gen_imm16(struct latxt_operand *opnd)
{
  return ;
}

/*TODO: realize */
void gen_imm32(struct latxt_operand *opnd)
{
  return ;
}

/*TODO: realize */
void gen_mem8(struct latxt_operand *opnd)
{
  return ;
}

/*TODO: realize */
void gen_mem16(struct latxt_operand *opnd)
{
  return ;
}

/*TODO: realize */
void gen_mem32(struct latxt_operand *opnd)
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
  LATXT_OPCODE_TYPE opcodeType = predef_info->opcode.type;
  LATXT_OPERANDS_TYPE operandsType = predef_info->operands.type;
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
