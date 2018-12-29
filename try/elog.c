#include <stdio.h>
#include <vppinfra/elog.h>
#include <vppinfra/longjmp.h>

int
main(int argc, char **argv)
{
    elog_main_t em;

    ELOG_TYPE_DECLARE(e) =
    {
        .format = "bar `%s'", .format_args = "s20",
    };
    struct
    {
        char s[20];
    }  *d;
    u8 *v;

    d = ELOG_DATA(&em, e);
    int i = 3;
    v = format(0, "foo %d%c", i, 0);
    printf("v=[%s]\n", v);
    /* clib_memcpy(d->s, v, clib_min(vec_len(v), sizeof(d->s))); */
    return 0;
}
