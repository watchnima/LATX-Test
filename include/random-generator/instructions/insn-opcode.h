/* latxt_define_opcode is a micro with 3 fields
 *   - Instruction opcode
 *   - Instruction name
 *   - Instruction operands' all possible types
 */

/* TODO: complete */

/* arithmetic */
latxt_define_opcode(X86_ISA_ADD, add, typical_binary)
latxt_define_opcode(X86_ISA_ADC, adc, typical_binary)
latxt_define_opcode(X86_ISA_AND, and, typical_binary)
