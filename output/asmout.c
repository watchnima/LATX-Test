#include "latxtest-common.h"
#include "output/ofmt.h"

static FILE* asmfp;

static void asm_cleanup(void)
{
    if (!asmfp)
        return;
    fclose(asmfp);
    asmfp = NULL;
}

static void asm_init(const char* fname)
{
    if (asmfp)
        asm_cleanup();
    if (!fname || fname[0] == '\0') {
        asmfp = NULL;
        return;
    }
    asmfp = fopen(fname, "w");
    if (!asmfp) {
        printl("Unable to open file %s", fname);
        return;
    }
}

static void asm_out(const char* data)
{
    fprintf(asmfp, "%s\n", data);
}

static const struct ofmt asm_fmt = {
    .init = asm_init,
    .cleanup = asm_cleanup,
    .output = asm_out
};

const struct ofmt *ofmt = &asm_fmt;
