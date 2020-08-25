#include "latxtest-common.h"
#include "random-generator/instructions/gen-operand.h"

#define random(x) (rand() % x)

void gen_r8(struct latxt_operand *opnd) {
  return ;
}

/*TODO: realize */
void gen_r16(struct latxt_operand *opnd) {
  return ;
}

/*TODO: realize */
void gen_r32(struct latxt_operand *opnd) {
  return ;
}

void gen_imm8(struct latxt_operand *opnd) {
  opnd->bytes[0] = (uint8_t)random(0x7f);
  opnd->len = 1;
  return ;
}

/*TODO: realize */
void gen_imm16(struct latxt_operand *opnd) {
  return ;
}

/*TODO: realize */
void gen_imm32(struct latxt_operand *opnd) {
  return ;
}

/*TODO: realize */
void gen_mem8(struct latxt_operand *opnd) {
  return ;
}

/*TODO: realize */
void gen_mem16(struct latxt_operand *opnd) {
  return ;
}

/*TODO: realize */
void gen_mem32(struct latxt_operand *opnd) {
  return ;
}

gen_opnd_func_type gen_operand_funcs[OPERAND_LAST] = {
#define latxt_define_operand(a, b) b,
#include "random-generator/instructions/insn-operand.h"
};
#undef latxt_define_operand
