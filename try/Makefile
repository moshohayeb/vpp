
VPP_SRC_DIR = ../src/
VPP_INFRA_DIR = $(VPP_SRC_DIR)/vppinfra

# VPP_INFRA_SRCS =	$(VPP_INFRA_DIR)/error.c  			\
# 					$(VPP_INFRA_DIR)/dlmalloc.c		\
# 					$(VPP_INFRA_DIR)/mem_dlmalloc.c 	\
# 					$(VPP_INFRA_DIR)/format.c   		\
# 				 	$(VPP_INFRA_DIR)/unformat.c		\
# 				 	$(VPP_INFRA_DIR)/std-formats.c		\
# 				 	$(VPP_INFRA_DIR)/backtrace.c		\
# 				 	$(VPP_INFRA_DIR)/hash.c  			\
# 				 	$(VPP_INFRA_DIR)/unix-misc.c		\
# 				 	$(VPP_INFRA_DIR)/elf.c				\
# 				 	$(VPP_INFRA_DIR)/elf_clib.c		\
# 				 	$(VPP_INFRA_DIR)/vec.c

VPP_INFRA_FILES = $(shell find ../src/vppinfra -type f   \
				| grep -E "\.c"						\
				| grep -vE "qhash.c|template|unix-kelog.c|tw_timer|test_|dlm" \
				| sed 's/...src.vppinfra.//' \
				| sed 's/\.c$$//')

VPP_INFRA_OBJS  = $(patsubst %, objs/%.o, $(VPP_INFRA_FILES))

_PRGS=vec
PRGS=$(patsubst %, bin/%, $(_PRGS))

WARNINGS = -Wno-incompatible-pointer-types
CFLAGS   = -I../build-root/install-vpp_debug-native/vpp/include/ -I$(VPP_SRC_DIR) $(WARNINGS)
LDFLAGS  = -L. -lvppinfra

all: $(PRGS)

$(PRGS): bin/% : %.c libvppinfra.a
	@mkdir -p bin
	$(CC) $(CFLAGS) -o bin/$* $< $(LDFLAGS)

test:
	@echo $(PRGS)

libvppinfra.a: $(VPP_INFRA_OBJS)
	ar -rcs libvppinfra.a `find objs -type f -name *.o`

# libvppinfra.a: objs/elog.o
# 	ar -rcs libvppinfra.a `find objs -type f -name *.o`

$(VPP_INFRA_OBJS): objs/%.o: $(VPP_INFRA_DIR)/%.c
	@mkdir -p objs/linux
	gcc -c $(CFLAGS) ../src/vppinfra/$*.c -o $@

clean:
	rm -f libvppinfra.a
	rm -fr bin objs
