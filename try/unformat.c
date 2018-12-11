#include <stdio.h>
#include <vppinfra/format.h>

int main(int argc, char** argv)
{
    unformat_input_t input;
    char *command[] = { "12",  "foo",  "bar", NULL };
    clib_mem_init_thread_safe(0, 1000000);

    u8 x1 = 0;
    u8 x2 = 0;
    printf("%d\n", x1 == x2);

    char *s = "31 foo bar 3.2";
    unformat_init_string(&input, s, strlen(s));
    printf("input=>buffer = %s\n", input.buffer);

    u8 z;
    printf("input=>index = %d\n", input.index);
    uword rc = unformat(&input, "%u", &z);
    printf("rc=%ld [%d]\n", rc, z);

    printf("input=>index = %d\n", input.index);

    char *buf;
    rc = unformat(&input, "%s", &buf);
    printf("rc=%ld [%s]\n", rc, buf);

    char * v;

    v = format(0, "%d %s", 23,  "XXX");
    printf("v=%s\n", v);

    return 0;
}
