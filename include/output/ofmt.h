#ifndef TEST_SOUT_H
#define TEST_SOUT_H

enum output_type {
    OUTPUT_RAWDATA,
    OUTPUT_INSN
};

struct output_data {
    enum output_type type;
    const char *buf;
};
/*
 * s-file generators should look like this
 */
struct ofmt {
    /*
     * Initialize the assembly file.
     */
    void (*init)(const char* fname);

    /*
     * Clear stuff up and close the assembly file.
     */
    void (*cleanup)(void);

    /*
     * Print assembly codes into assembly file.
     */
    void (*output)(struct output_data* data);
};

extern const struct ofmt *ofmt;

#endif
