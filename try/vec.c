#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <vppinfra/vec.h>

typedef struct {
    u8  path[32];
    u32 seek;
} file_t;

typedef struct {
    char *p;
    int x;
} directory_t;

int
main(int argc, char **argv)
{
    clib_mem_init_thread_safe(0, 1000000);
    printf("sizeof file_t=%lu\n", sizeof(file_t));
    printf("sizeof vec_header_t=%lu\n", sizeof(vec_header_t));

    file_t *fv = NULL;


    for (int i = 0; i < 16; i++) {
        file_t f;
        snprintf((char *) f.path, 32, "file_t-%d", i);
        f.seek = i;
        vec_add1_ha(fv, f, sizeof(directory_t), 512);
    }

    vec_header_t *vh = _vec_find (fv);
    directory_t *dh =  vec_header(fv, sizeof(directory_t));
    dh->x = 24;
    printf("dh->x=%d\n", dh->x);

    printf("userhdr=%p, vechdr=%p firstelement=%p\n", dh, vh, &fv[0]);

    printf("d-userhdr-vechdr=%lu\n", (uword) vh - (uword) dh);
    printf("d-vechdr-firstelement=%lu\n", (uword) fv - (uword) vh);


    printf("isPtr aligned on 512: %s\n", (uword) fv % 512 == 0 ? "yes" : "no");

    file_t *iv;
    vec_foreach(iv, fv) {
        printf("iv=%s\n", iv->path);
    }


    file_t *zf16 = vec_elt_at_index(fv, 16);
    file_t *zf17 = vec_elt_at_index(fv, 17);
    printf("Diff between zf16 and zf17 = %lu\n", (uword) zf17 - (uword) zf16);

    // printf("hello\n");
    return 0;
}
