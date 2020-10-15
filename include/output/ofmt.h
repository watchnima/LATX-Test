#ifndef TEST_SOUT_H
#define TEST_SOUT_H

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
    void (*output)(const char* data);
};

extern const struct ofmt *ofmt;

#endif
