#ifndef TEST_ARITH_SEED_H
#define TEST_ARITH_SEED_H

#define latxt_define_opcode(a, b, c) X86_INSN b##_seed = \
                                  { \
                                    .predef_info = \
                                    { \
                                      .ispredef_opcode_type = true, \
                                      .opcode = \
                                      { \
                                        .type = a \
                                      } \
                                    } \
                                  };
#include "random-generator/instructions/insn-opcode.h"
#undef latxt_define_opcode

#endif
