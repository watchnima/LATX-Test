/* latxt_define_opcode is a micro with 3 fields
 *   - Instruction opcode
 *   - Instruction name
 *   - Instruction operands' all possible types
 */

/* TODO: complete */

/* arithmetic */
latxt_define_opcode(X86_ISA_ADC, adc, typical_binary)
latxt_define_opcode(X86_ISA_ADD, add, typical_binary)
latxt_define_opcode(X86_ISA_DEC, dec, typical_binary)
latxt_define_opcode(X86_ISA_DIV, div, typical_binary)
latxt_define_opcode(X86_ISA_IMUL, imul, typical_binary)
latxt_define_opcode(X86_ISA_INC, inc, typical_binary)
latxt_define_opcode(X86_ISA_MUL, mul, typical_binary)
latxt_define_opcode(X86_ISA_NEG, neg, typical_binary)
latxt_define_opcode(X86_ISA_SBB, sbb, typical_binary)
latxt_define_opcode(X86_ISA_SUB, sub, typical_binary)
latxt_define_opcode(X86_ISA_XADD, xadd, typical_binary)
latxt_define_opcode(X86_ISA_XCHG, xchg, typical_binary)
/* logic */
latxt_define_opcode(X86_ISA_AND, and, typical_binary)
latxt_define_opcode(X86_ISA_NOT, not, typical_binary)
latxt_define_opcode(X86_ISA_OR, or, typical_binary)
latxt_define_opcode(X86_ISA_RCL, rcl, typical_binary)
latxt_define_opcode(X86_ISA_RCR, rcr, typical_binary)
latxt_define_opcode(X86_ISA_ROL, rol, typical_binary)
latxt_define_opcode(X86_ISA_ROR, ror, typical_binary)
latxt_define_opcode(X86_ISA_SAR, sar, typical_binary)
latxt_define_opcode(X86_ISA_SHL, shl, typical_binary)
latxt_define_opcode(X86_ISA_SHLD, shld, typical_binary)
latxt_define_opcode(X86_ISA_SHR, shr, typical_binary)
latxt_define_opcode(X86_ISA_SHRD, shrd, typical_binary)
latxt_define_opcode(X86_ISA_XOR, xor, typical_binary)
/* mov */
latxt_define_opcode(X86_ISA_CMOVCC, cmovcc, typical_binary)
latxt_define_opcode(X86_ISA_LEAVE, leave, typical_binary)
latxt_define_opcode(X86_ISA_MOV, mov, typical_binary)
latxt_define_opcode(X86_ISA_MOVSX, movsx, typical_binary)
latxt_define_opcode(X86_ISA_MOVZX, movzx, typical_binary)
latxt_define_opcode(X86_ISA_PUSH, push, typical_binary)
latxt_define_opcode(X86_ISA_POP, pop, typical_binary)
/* jcc */
latxt_define_opcode(X86_ISA_JA, ja, typical_binary)
latxt_define_opcode(X86_ISA_JBE, jbe, typical_binary)
latxt_define_opcode(X86_ISA_JE, je, typical_binary)
latxt_define_opcode(X86_ISA_JGE, jge, typical_binary)
latxt_define_opcode(X86_ISA_JMP, jmp, typical_binary)
latxt_define_opcode(X86_ISA_JNB, jnb, typical_binary)
latxt_define_opcode(X86_ISA_JNE, jne, typical_binary)
latxt_define_opcode(X86_ISA_JNL, jnl, typical_binary)
latxt_define_opcode(X86_ISA_JNP, jnp, typical_binary)
latxt_define_opcode(X86_ISA_JO, jo, typical_binary)
latxt_define_opcode(X86_ISA_JPO, jpo, typical_binary)
latxt_define_opcode(X86_ISA_LOOP, loop, typical_binary)
latxt_define_opcode(X86_ISA_LOOPZ, loopz, typical_binary)
latxt_define_opcode(X86_ISA_JAE, jae, typical_binary)
latxt_define_opcode(X86_ISA_JC, jc, typical_binary)
latxt_define_opcode(X86_ISA_JECXZ, jecxz, typical_binary)
latxt_define_opcode(X86_ISA_JL, jl, typical_binary)
latxt_define_opcode(X86_ISA_JNA, jna, typical_binary)
latxt_define_opcode(X86_ISA_JNBE, jnbe, typical_binary)
latxt_define_opcode(X86_ISA_JNG, jng, typical_binary)
latxt_define_opcode(X86_ISA_JNLE, jnle, typical_binary)
latxt_define_opcode(X86_ISA_JNS, jns, typical_binary)
latxt_define_opcode(X86_ISA_JP, jp, typical_binary)
latxt_define_opcode(X86_ISA_JS, js, typical_binary)
latxt_define_opcode(X86_ISA_LOOPE, loope, typical_binary)
latxt_define_opcode(X86_ISA_JB, jb, typical_binary)
latxt_define_opcode(X86_ISA_JCXZ, jcxz, typical_binary)
latxt_define_opcode(X86_ISA_JG, jg, typical_binary)
latxt_define_opcode(X86_ISA_JLE, jle, typical_binary)
latxt_define_opcode(X86_ISA_JNAE, jnae, typical_binary)
latxt_define_opcode(X86_ISA_JNC, jnc, typical_binary)
latxt_define_opcode(X86_ISA_JNGE, jnge, typical_binary)
latxt_define_opcode(X86_ISA_JNO, jno, typical_binary)
latxt_define_opcode(X86_ISA_JNZ, jnz, typical_binary)
latxt_define_opcode(X86_ISA_JPE, jpe, typical_binary)
latxt_define_opcode(X86_ISA_JZ, jz, typical_binary)
latxt_define_opcode(X86_ISA_LOOPNE, loopnz, typical_binary)
