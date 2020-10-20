#include "latxtest-common.h"
#include "unit-tests/insn-test.h"
#include "x86-insn-generator/include/generator.h"
#include "output/ofmt.h"

static const char *buf;
static insn_seed MOV_seed =
{
    .opcode = I_MOV
};

static const char fout_head[] = "section .text\n  global _start\n_start:\n";
static const char fout_tail[] = "\n  mov ax,1\n  mov ebx,0\n  int 80h";

bool gen_test_file_MOV(void)
{
    struct output_data data;
    generator_init(true);

    ofmt->init("test_MOV.s");
    
    data.type = OUTPUT_RAWDATA;
    data.buf = (const char *)fout_head;
    ofmt->output(&data);

    assign_arr5(MOV_seed.opd, REG_GPR|BITS16,REG_SREG,0,0,0);
    while ((buf = generate_str(&MOV_seed)) != NULL) {
        data.type = OUTPUT_INSN;
        data.buf = buf;
        ofmt->output(&data);
    }

    data.type = OUTPUT_RAWDATA;
    data.buf = (const char *)fout_tail;
    ofmt->output(&data);
    
    ofmt->cleanup();

    generator_exit();
    return true;
}
