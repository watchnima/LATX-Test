#include "latxtest-common.h"
#include "unit-tests/code-cache.h"

#ifdef CONFIG_DISPLAY
#include "tools/insn-display.h"
#endif

char *ccache_bytes;
uint32_t ccache_len;

#define CCACHE_HEAD_SIZE 0
#define CCACHE_TAIL_SIZE 1

/* To execute the generated codes, I design a code cache, which lokks like:
 *
 *               [instuctions head,
 *                generated codes,
 *                instructions tail]
 *
 * Head and tail in code cache, which is used to wrap the generated codes.
 */

/* ccache_head: before executing the generated codes, do some initializing
 *              things. It is empty now. But I may change this into the
 *              starting of a function call in the future.
 */
char ccache_head[CCACHE_HEAD_SIZE] = {};

/* ccache_tail: after executing the generated codes, do some finishing
 *              things corresponding to ccache_head. Since I use a 'call *eax'
 *              in ccache_execute to enter code cache, so we need only a 'ret'
 *              to return back.
 */
char ccache_tail[CCACHE_TAIL_SIZE] = 
{
  0xc3          /* ret                      */
};

void ccache_init(void)
{
  ccache_bytes = (char *)aligned_alloc(CCACHE_PAGE_SIZE, CCACHE_SIZE);
  mprotect(ccache_bytes, CCACHE_SIZE, PROT_READ|PROT_EXEC|PROT_WRITE);
  ccache_len = 0;
}

void ccache_finish(void)
{
  free(ccache_bytes);
}

void ccache_head_wrap(void)
{
  latxtassert(ccache_bytes != NULL);
  memcpy(ccache_bytes, ccache_head, CCACHE_HEAD_SIZE);
  ccache_len = CCACHE_HEAD_SIZE;
}

void ccache_tail_wrap(void)
{
  latxtassert(ccache_len + CCACHE_TAIL_SIZE <= CCACHE_SIZE);
  memcpy(ccache_bytes + ccache_len, ccache_tail, CCACHE_TAIL_SIZE);
  ccache_len += CCACHE_TAIL_SIZE;
}

void ccache_execute(void)
{
  latxtassert(ccache_len >= CCACHE_HEAD_SIZE + CCACHE_TAIL_SIZE);
#ifdef CONFIG_DISPLAY
  display_codes(ccache_bytes, ccache_len);
#endif
  __asm__ __volatile__ (
    "mov %0, %%eax\n\t"
    "call *%%eax\n\t"
    :"=m"(ccache_bytes)
    :: "%eax"
  );
}

uint32_t ccache_put_bytes(char *codes, uint32_t len)
{
  if ((uint32_t)(CCACHE_SIZE - CCACHE_TAIL_SIZE - ccache_len) < len) {
    /* Can not store more instructions.
     * Not abort. Just execute the codes got so far.*/
    latxtwarning("Generated codes overflow!");
    return 0;
  }
  memcpy(ccache_bytes + ccache_len, codes, len);
  ccache_len += len;
  return len;
}
