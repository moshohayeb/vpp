#include <stdio.h>
#include <vppinfra/vec.h>

int main(int argc, char** argv)
{
    u8 *v = NULL;
    clib_mem_init_thread_safe(0, 1000000);
    vec_add1(v, 1);

    printf("hello\n");
    return 0;
}
