
VPP_SRC_DIR = ../src/
VPP_INFRA_DIR = $(VPP_SRC_DIR)/vppinfra

VPP_INFRA_FILES = $(shell find ../src/vppinfra -type f   \
				| grep -E "\.c"						\
				| grep -vE "qhash.c|template|unix-kelog.c|tw_timer|test_|dlm" \
				| sed 's/...src.vppinfra.//' \
				| sed 's/\.c$$//')

VPP_INFRA_OBJS  = $(patsubst %, objs/%.o, $(VPP_INFRA_FILES))
VPP_INFRA_OBJS  += $(VPP_INFRA_DIR)/longjmp.S

_PRGS=vec elog unformat
PRGS=$(patsubst %, bin/%, $(_PRGS))

WARNINGS = -Wno-incompatible-pointer-types
CFLAGS   = -I../build-root/install-vpp_debug-native/vpp/include/ -I$(VPP_SRC_DIR) $(WARNINGS)
LDFLAGS  = -L. -lvppinfra

all: $(PRGS)
	@echo $(VPP_INFRA_FILES)

$(PRGS): bin/% : %.c libvppinfra.a
	@mkdir -p bin
	$(CC) $(CFLAGS) -o bin/$* $< $(LDFLAGS)

test:
	@echo $(PRGS)

libvppinfra.a: $(VPP_INFRA_OBJS)  objs/longjmp.o
	ar -rcs libvppinfra.a `find objs -type f -name *.o`

objs/longjmp.o:
	@echo XX
	gcc -c $(CFLAGS) ../src/vppinfra/longjmp.S -o objs/longjmp.o

$(VPP_INFRA_OBJS): objs/%.o: $(VPP_INFRA_DIR)/%.c
	@mkdir -p objs/linux
	gcc -c $(CFLAGS) ../src/vppinfra/$*.c -o $@

clean:
	rm -f libvppinfra.a
	rm -fr bin objs
