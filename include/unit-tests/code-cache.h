#ifndef TEST_CODE_CACHE
#define TEST_CODE_CACHE

#include <unistd.h>
#include <sys/mman.h>

#define CCACHE_PAGE_SIZE 4096
#define CCACHE_SIZE 200 *  CCACHE_PAGE_SIZE   /* 200 4K-pages */

void ccache_init(void);
void ccache_finish(void);
void ccache_head_wrap(void);
void ccache_tail_wrap(void);
void ccache_execute(void);
uint32_t ccache_put_bytes(char *codes, uint32_t len);

#endif
