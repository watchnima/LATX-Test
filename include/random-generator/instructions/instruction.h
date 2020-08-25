#ifndef TEST_INSTRUCTION_H
#define TEST_INSTRUCTION_H

#include "random-generator/instructions/gen-operand.h"

/*
 * O P E R A N D S
 */

/* x86 instruction operands enumeration */
typedef enum {
#define latxt_define_operands(a, b, c) a,
#include "random-generator/instructions/insn-operands.h"
  LATXT_OPERANDS_LAST
} LATXT_OPERANDS_TYPE;
#undef latxt_define_operands


/*
 * O P C O D E
 */

/* x86 instruction set architecture opcodes */
typedef enum {
#define latxt_define_opcode(a, b, c) a,
#include "random-generator/instructions/insn-opcode.h"
  X86_ISA_LAST
} LATXT_OPCODE_TYPE;
#undef latxt_define_opcode


/*
 * I N S T R U C T I O N
 */

struct i386_insn_predef_info {
  /* set default information */
  LATXT_OPCODE_TYPE opcodeType;
  LATXT_OPERANDS_TYPE operandsType;

  bool predef_dst;
  bool predef_src1;
  bool predef_src2;
  bool predef_src3;
  uint32_t operands[4];
};

struct i386_insn {
  struct {
    // 15...0 opcode
    uint16_t ia_opcode;
  
    //  7...4 (unused)
    //  3...0 ilen (0..15)
    uint8_t ilen;
  
    //  7...6 VEX Vector Length (0=no VL, 1=128 bit, 2=256 bit)
    //        repUsed (0=none, 2=0xF2, 3=0xF3)
    //  5...5 extend8bit
    //  4...4 mod==c0 (modrm)
    //  3...3 os64
    //  2...2 os32
    //  1...1 as64
    //  0...0 as32
    uint8_t metaInfo1;
  } metaInfo;

  #define INSTR_METADATA_DST   0
  #define INSTR_METADATA_SRC1  1
  #define INSTR_METADATA_SRC2  2
  #define INSTR_METADATA_SRC3  3
  #define INSTR_METADATA_SEG   4
  #define INSTR_METADATA_BASE  5
  #define INSTR_METADATA_INDEX 6
  #define INSTR_METADATA_SCALE 7
  
  // using 5-bit field for registers (16 regs in 64-bit, RIP, NIL)
  uint8_t metaData[8];

  struct {
    union {
      uint32_t Id;
      uint16_t Iw;
      uint8_t  Ib;
    };
    union {
      uint16_t displ16u; // for 16-bit modrm forms
      uint32_t displ32u; // for 32-bit modrm forms
 
      uint32_t Id2;
      uint16_t Iw2;
      uint8_t  Ib2;
    };
  } modRMForm;

  uint8_t insn_len;

  struct i386_insn_predef_info predef_info;
  
  /* information to return */
  uint8_t bytes[15];
};

typedef struct i386_insn X86_INSN;

#endif
