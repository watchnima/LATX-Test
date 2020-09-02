#include "latxtest-common.h"
#include "generator/instructions/instruction.h"
#include "generator/instructions/gen-operands.h"

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

