#include <stdio.h>
#include <string.h>

#include <setjmp.h>
int setjmp(jmp_buf env) {
  printf ("TIS WARNING: call to 'setjmp' ignored\n");
  return 0;
}

void mbedtls_platform_zeroize( void *buf, size_t len ) {
  memset (buf, 0, len);
}
