#include "latxtest-common.h"
#include "generator/instructions/instruction.h"
#include "generator/instructions/gen-operands.h"

typedef enum {
  REG_AL,
  REG_CL,
  REG_DL,
  REG_BL,
  REG_AH,
  REG_CH,
  REG_DH,
  REG_BH,
  LATXT_REG8_LAST
} LATXT_REG8_TYPE;

typedef enum {
  REG_AX,
  REG_CX,
  REG_DX,
  REG_BX,
  REG_SP,
  REG_BP,
  REG_SI,
  REG_DI,
  LATXT_REG16_LAST
} LATXT_REG16_TYPE;

typedef enum {
  REG_EAX,
  REG_ECX,
  REG_EDX,
  REG_EBX,
  REG_ESP,
  REG_EBP,
  REG_ESI,
  REG_EDI,
  LATXT_REG32_LAST
} LATXT_REG32_TYPE;

void gen_r8(struct latxt_operand *opnd)
{
  opnd->reg = random(LATXT_REG8_LAST);
}

void gen_r16(struct latxt_operand *opnd)
{
  opnd->reg = random(LATXT_REG16_LAST);
}

void gen_r32(struct latxt_operand *opnd)
{
  opnd->reg = random(LATXT_REG32_LAST);
}
