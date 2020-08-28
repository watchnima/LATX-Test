#ifndef TEST_INSTRUCTION_H
#define TEST_INSTRUCTION_H



/* ========================================================================= */
/* P R E F I X                                                               */
/* ========================================================================= */
typedef enum {
  /* Group1: 0xF0H 0xF2H 0xF3H;
   *         0xF2H
   *   -Lock and repeat prefixes
   *   -Bound prefix
   */
  LATXT_PREFIX_TYPE_GRP1,
  /* Group2: 0x2EH 0x36H 0x3EH 0x26H 0x64H 0x65H;
   *         0x2EH 0x3EH
   *   -Segment override prefixes
   *   -Branch hints
   */
  LATXT_PREFIX_TYPE_GRP2,
  /* Group3: 0x66H
   *   -Operand-size override prefix
   */
  LATXT_PREFIX_TYPE_GRP3,
  /* Group3: 0x67H
   *   -Address-size override prefix
   */
  LATXT_PREFIX_TYPE_GRP4,
  LATXT_PREFIX_TYPE_LAST
} LATXT_PREFIX_TYPE;

struct latxt_prefix {
  LATXT_PREFIX_TYPE type;
  uint8_t len;
  char* bytes;
};

#define MAX_PREFIX_COUNT 4


/* ========================================================================= */
/* O P E R A N D S                                                           */
/* ========================================================================= */

/* x86 instruction operands enumeration */
typedef enum {
#define latxt_define_operands(a, b, c) a,
#include "random-generator/instructions/insn-operands.h"
  LATXT_OPERANDS_LAST
} LATXT_OPERANDS_TYPE;
#undef latxt_define_operands

/* 
 * MODRM
 */
struct latxt_modrm {
#define MODRM_MOD_SHIFL 6
#define MODRM_REG_SHIFT 3
#define MODRM_RM_SHIFT 0
  uint8_t mod;
  uint8_t reg;
  uint8_t rm;
};

/*
 * SIB
 */
struct latxt_sib {
#define SIB_SCALE_SHIFL 6
#define SIB_INDEX_SHIFT 3
#define SIB_BASE_SHIFT 0
  uint8_t scale;
  uint8_t index;
  uint8_t base;
};

/*
 * DISPLACEMENT
 */
struct latxt_disp {
  union {
    int8_t disp8;
    int16_t disp16;
    int32_t disp32;
  } value;
  uint8_t size;
};

/*
 * IMMEDIATE
 */
struct latxt_imm {
  bool isSigned;
  union {
    uint32_t uvalue;
    int32_t value;
  } value;
  uint8_t size;
};

struct latxt_operands {
  LATXT_OPERANDS_TYPE type;
  struct latxt_modrm modrm;
  struct latxt_sib sib;
  struct latxt_disp disp;
  struct latxt_imm imm;
};

/* ========================================================================= */
/* O P C O D E                                                               */
/* ========================================================================= */

/* x86 instruction set architecture opcodes */
typedef enum {
#define latxt_define_opcode(a, b, c) a,
#include "random-generator/instructions/insn-opcode.h"
  X86_ISA_LAST
} LATXT_OPCODE_TYPE;
#undef latxt_define_opcode

struct latxt_opcode {
  LATXT_OPCODE_TYPE type;
  char *bytes;
};

/* ========================================================================= */
/* M I S C                                                                   */
/* ========================================================================= */

#include "random-generator/instructions/insn-operands-abbrev.h"

struct latxt_jump_info {
  LATXT_JUMP_TYPE type;
  LATXT_JUMP_CONDITION condition;
};

/* ========================================================================= */
/* I N S T R U C T I O N                                                     */
/* ========================================================================= */

struct latxt_i386_insn_predef_info {
  /* boolean value indicates if the relevant part is predefined */
  struct {
    bool prefixes;
    struct {
      bool type;
      bool bytes;
    } opcode;
    union {
      bool reg;
      struct {
        bool type;
        bool condition;
      } j;
      struct {
        bool type;
        bool modrm;
        bool sib;
        bool disp;
        bool imm;
      } operands;
    };
  } ispredefined;
#define ispredef_prefixes ispredefined.prefixes

#define ispredef_opcode_type ispredefined.opcode.type
#define ispredef_opcode_bytes ispredefined.opcode.bytes

#define ispredef_pp_reg ispredefined.reg

#define ispredef_j_type ispredefined.j.type
#define ispredef_j_condition ispredefined.j.condition

#define ispredef_operands_type ispredefined.operands.type
#define ispredef_operands_modrm ispredefined.operands.modrm
#define ispredef_operands_sib ispredefined.operands.sib
#define ispredef_operands_disp ispredefined.operands.disp
#define ispredef_operands_imm ispredefined.operands.imm

  struct latxt_opcode opcode;
  struct latxt_prefix prefixes[MAX_PREFIX_COUNT];
  union {
    LATXT_PP_REG pp_reg;
    struct latxt_jump_info jump;
    struct latxt_operands operands;
  };
};

struct latxt_i386_insn {
  /* Define the default value of some part of the instruction
   *   exp: set opcodeType = X86_ISA_ADD and/or
   *        set operandsType = R8_IMM8
   */
  struct latxt_i386_insn_predef_info predef_info;

  /* generated instruction bytes */
  uint8_t insn_len;
  char bytes[15];
};

typedef struct latxt_i386_insn X86_INSN;

#endif
