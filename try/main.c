#include <stdio.h>
#include <stdint.h>


typedef struct {
    uint64_t x1;
    uint64_t x2;
    uint64_t x3;
    uint64_t x4;
    uint64_t x5;
    uint64_t x6;
    uint64_t x8;
} buffer_t;

int main(int argc, char** argv)
{
    printf("sizeof buffer_t = %lu\n", sizeof(buffer_t));
    buffer_t buffers[100];
    buffer_t *b = buffers;
    buffer_t *voidb = NULL;

    printf("sizeof(buffers)=%lu\n", sizeof(buffers));
    printf("sizeof(b)=%lu\n", sizeof(b));
    printf("sizeof(b[0])=%lu\n", sizeof(b[0]));
    printf("sizeof(voidb[0])=%lu\n", sizeof(b[0]));
    return 0;
}
