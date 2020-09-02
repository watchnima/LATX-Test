#ifndef TEST_GEN_OPERAND_H
#define TEST_GEN_OPERAND_H

/* x86 instruction operand type */
typedef enum {
#define latxt_define_operand(a, b) a,
#include "generator/instructions/insn-operand.h"
  OPERAND_LAST
} LATXT_OPERAND_TYPE;
#undef latxt_define_operand

struct latxt_operand {
  LATXT_OPERAND_TYPE type;
  uint8_t len;
  union {
    uint8_t *bytes;
    uint8_t reg;
  };
};

#define random(x) (rand() % x)

/* register operand */
void gen_r8(struct latxt_operand *opnd);
void gen_r16(struct latxt_operand *opnd);
void gen_r32(struct latxt_operand *opnd);

/* immediate operand */
void gen_imm8(struct latxt_operand *opnd);
void gen_imm16(struct latxt_operand *opnd);
void gen_imm32(struct latxt_operand *opnd);

/* memory operand */
void gen_mem8(struct latxt_operand *opnd);
void gen_mem16(struct latxt_operand *opnd);
void gen_mem32(struct latxt_operand *opnd);


uint8_t gen_operands(uint8_t *operands_buf,
        struct latxt_i386_insn_predef_info *predef_info);

#endif
