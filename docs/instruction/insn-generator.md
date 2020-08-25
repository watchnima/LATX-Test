# Instruction Generator

We use a independent module to generate instructions. Every type of instruction have a relevant generation function.

## operands type

* Ev: The ModR/M byte follows the opcode to specify a word or doubleword operand.
* Gv: The reg field of the ModR/M byte selects a general-purpose register.
* Ib: Immediate data is encoded in the subsequent byte of the instruction.

## arithmetic instructions

**ADD:**

| Opcode   | Instruction    | Description       | Function Type |
| -------- | -------------- | ----------------- | ------------- |
| 04 ib    | ADD AL, imm8   | Add imm8 to AL.   | EbIbR         |
| 80 /0 ib | ADD r/m8, imm8 | Add imm8 to r/m8. | EbIbR/M       |
| 00 /r    | ADD r/m8, r8   | Add r8 to r/m8.   | EbGbR/M       |
| 02 /r    | ADD r8, r/m8   | Add r/m8 to r8.   | GbEbR/M       |

note: operands of EbGbR and GbEbR are of the same type.
