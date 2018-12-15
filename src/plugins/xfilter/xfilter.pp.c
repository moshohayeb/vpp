typedef signed char i8;
typedef signed short i16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int i128 __attribute__((mode(TI)));
typedef unsigned int u128 __attribute__((mode(TI)));
typedef signed int i32;
typedef signed long i64;
typedef unsigned int u32;
typedef unsigned long u64;
typedef i64 word;
typedef u64 uword;
typedef u64 clib_address_t;
static inline __attribute__((always_inline)) uword
pointer_to_uword(const void *p)
{
    return (uword)(clib_address_t) p;
}
typedef word any;
typedef double f64;
typedef float f32;
typedef __complex__ float cf32;
typedef __complex__ double cf64;
typedef f64 fword;
static inline __attribute__((__always_inline__)) uword
min_log2(uword x)
{
    uword n;
    n = __builtin_clzll(x);
    return (8 * sizeof(uword)) - n - 1;
}
static inline __attribute__((__always_inline__)) uword
max_log2(uword x)
{
    uword l = min_log2(x);
    if (x > ((uword) 1 << l))
        l++;
    return l;
}
static inline __attribute__((__always_inline__)) u64
min_log2_u64(u64 x)
{
    if ((8 * sizeof(uword)) == 64)
        return min_log2(x);
    else {
        uword l, y;
        y = x;
        l = 0;
        if (y == 0) {
            l += 32;
            x >>= 32;
        }
        l += min_log2(x);
        return l;
    }
}
static inline __attribute__((__always_inline__)) uword
pow2_mask(uword x)
{
    return ((uword) 1 << x) - (uword) 1;
}
static inline __attribute__((__always_inline__)) uword
max_pow2(uword x)
{
    word y = (word) 1 << min_log2(x);
    if (x > y)
        y *= 2;
    return y;
}
static inline __attribute__((__always_inline__)) uword
is_pow2(uword x)
{
    return 0 == (x & (x - 1));
}
static inline __attribute__((__always_inline__)) uword
round_pow2(uword x, uword pow2)
{
    return (x + pow2 - 1) & ~(pow2 - 1);
}
static inline __attribute__((__always_inline__)) u64
round_pow2_u64(u64 x, u64 pow2)
{
    return (x + pow2 - 1) & ~(pow2 - 1);
}
static inline __attribute__((__always_inline__)) uword
first_set(uword x)
{
    return x & -x;
}
static inline __attribute__((__always_inline__)) uword
log2_first_set(uword x)
{
    uword result;
    result = __builtin_ctzll(x);
    return result;
}
static inline __attribute__((__always_inline__)) f64
flt_round_down(f64 x)
{
    return (int) x;
}
static inline __attribute__((__always_inline__)) word
flt_round_nearest(f64 x)
{
    return (word)(x + .5);
}
static inline __attribute__((__always_inline__)) f64
flt_round_to_multiple(f64 x, f64 f)
{
    return f * flt_round_nearest(x / f);
}
uword clib_backtrace(uword *callers, uword max_callers, uword n_frames_to_skip);
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct {
    int __val[2];
} __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef __ssize_t ssize_t;
typedef long unsigned int size_t;
typedef __gid_t gid_t;
typedef __uid_t uid_t;
typedef __off_t off_t;
typedef __useconds_t useconds_t;
typedef __pid_t pid_t;
typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
extern int access(const char *__name, int __type) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int faccessat(int __fd, const char *__file, int __type, int __flag) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern __off_t lseek(int __fd, __off_t __offset, int __whence) __attribute__((__nothrow__, __leaf__));
extern int close(int __fd);
extern ssize_t read(int __fd, void *__buf, size_t __nbytes);
extern ssize_t write(int __fd, const void *__buf, size_t __n);
extern ssize_t pread(int __fd, void *__buf, size_t __nbytes, __off_t __offset);
extern ssize_t pwrite(int __fd, const void *__buf, size_t __n, __off_t __offset);
extern int pipe(int __pipedes[2]) __attribute__((__nothrow__, __leaf__));
extern unsigned int alarm(unsigned int __seconds) __attribute__((__nothrow__, __leaf__));
extern unsigned int sleep(unsigned int __seconds);
extern __useconds_t ualarm(__useconds_t __value, __useconds_t __interval) __attribute__((__nothrow__, __leaf__));
extern int usleep(__useconds_t __useconds);
extern int pause(void);
extern int chown(const char *__file, __uid_t __owner, __gid_t __group) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int fchown(int __fd, __uid_t __owner, __gid_t __group) __attribute__((__nothrow__, __leaf__));
extern int lchown(const char *__file, __uid_t __owner, __gid_t __group) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int fchownat(int __fd, const char *__file, __uid_t __owner, __gid_t __group, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int chdir(const char *__path) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int fchdir(int __fd) __attribute__((__nothrow__, __leaf__));
extern char *getcwd(char *__buf, size_t __size) __attribute__((__nothrow__, __leaf__));
extern char *getwd(char *__buf) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)))
__attribute__((__deprecated__));
extern int dup(int __fd) __attribute__((__nothrow__, __leaf__));
extern int dup2(int __fd, int __fd2) __attribute__((__nothrow__, __leaf__));
extern char **__environ;
extern int execve(const char *__path, char *const __argv[], char *const __envp[]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int fexecve(int __fd, char *const __argv[], char *const __envp[]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern int execv(const char *__path, char *const __argv[]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int execle(const char *__path, const char *__arg, ...) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int execl(const char *__path, const char *__arg, ...) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int execvp(const char *__file, char *const __argv[]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int execlp(const char *__file, const char *__arg, ...) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int nice(int __inc) __attribute__((__nothrow__, __leaf__));
extern void _exit(int __status) __attribute__((__noreturn__));
enum {
    _PC_LINK_MAX,
    _PC_MAX_CANON,
    _PC_MAX_INPUT,
    _PC_NAME_MAX,
    _PC_PATH_MAX,
    _PC_PIPE_BUF,
    _PC_CHOWN_RESTRICTED,
    _PC_NO_TRUNC,
    _PC_VDISABLE,
    _PC_SYNC_IO,
    _PC_ASYNC_IO,
    _PC_PRIO_IO,
    _PC_SOCK_MAXBUF,
    _PC_FILESIZEBITS,
    _PC_REC_INCR_XFER_SIZE,
    _PC_REC_MAX_XFER_SIZE,
    _PC_REC_MIN_XFER_SIZE,
    _PC_REC_XFER_ALIGN,
    _PC_ALLOC_SIZE_MIN,
    _PC_SYMLINK_MAX,
    _PC_2_SYMLINKS
};
enum {
    _SC_ARG_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_STREAM_MAX,
    _SC_TZNAME_MAX,
    _SC_JOB_CONTROL,
    _SC_SAVED_IDS,
    _SC_REALTIME_SIGNALS,
    _SC_PRIORITY_SCHEDULING,
    _SC_TIMERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_PRIORITIZED_IO,
    _SC_SYNCHRONIZED_IO,
    _SC_FSYNC,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_MQ_PRIO_MAX,
    _SC_VERSION,
    _SC_PAGESIZE,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_TIMER_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX,
    _SC_EQUIV_CLASS_MAX,
    _SC_EXPR_NEST_MAX,
    _SC_LINE_MAX,
    _SC_RE_DUP_MAX,
    _SC_CHARCLASS_NAME_MAX,
    _SC_2_VERSION,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_SW_DEV,
    _SC_2_LOCALEDEF,
    _SC_PII,
    _SC_PII_XTI,
    _SC_PII_SOCKET,
    _SC_PII_INTERNET,
    _SC_PII_OSI,
    _SC_POLL,
    _SC_SELECT,
    _SC_UIO_MAXIOV,
    _SC_IOV_MAX = _SC_UIO_MAXIOV,
    _SC_PII_INTERNET_STREAM,
    _SC_PII_INTERNET_DGRAM,
    _SC_PII_OSI_COTS,
    _SC_PII_OSI_CLTS,
    _SC_PII_OSI_M,
    _SC_T_IOV_MAX,
    _SC_THREADS,
    _SC_THREAD_SAFE_FUNCTIONS,
    _SC_GETGR_R_SIZE_MAX,
    _SC_GETPW_R_SIZE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_TTY_NAME_MAX,
    _SC_THREAD_DESTRUCTOR_ITERATIONS,
    _SC_THREAD_KEYS_MAX,
    _SC_THREAD_STACK_MIN,
    _SC_THREAD_THREADS_MAX,
    _SC_THREAD_ATTR_STACKADDR,
    _SC_THREAD_ATTR_STACKSIZE,
    _SC_THREAD_PRIORITY_SCHEDULING,
    _SC_THREAD_PRIO_INHERIT,
    _SC_THREAD_PRIO_PROTECT,
    _SC_THREAD_PROCESS_SHARED,
    _SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN,
    _SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES,
    _SC_ATEXIT_MAX,
    _SC_PASS_MAX,
    _SC_XOPEN_VERSION,
    _SC_XOPEN_XCU_VERSION,
    _SC_XOPEN_UNIX,
    _SC_XOPEN_CRYPT,
    _SC_XOPEN_ENH_I18N,
    _SC_XOPEN_SHM,
    _SC_2_CHAR_TERM,
    _SC_2_C_VERSION,
    _SC_2_UPE,
    _SC_XOPEN_XPG2,
    _SC_XOPEN_XPG3,
    _SC_XOPEN_XPG4,
    _SC_CHAR_BIT,
    _SC_CHAR_MAX,
    _SC_CHAR_MIN,
    _SC_INT_MAX,
    _SC_INT_MIN,
    _SC_LONG_BIT,
    _SC_WORD_BIT,
    _SC_MB_LEN_MAX,
    _SC_NZERO,
    _SC_SSIZE_MAX,
    _SC_SCHAR_MAX,
    _SC_SCHAR_MIN,
    _SC_SHRT_MAX,
    _SC_SHRT_MIN,
    _SC_UCHAR_MAX,
    _SC_UINT_MAX,
    _SC_ULONG_MAX,
    _SC_USHRT_MAX,
    _SC_NL_ARGMAX,
    _SC_NL_LANGMAX,
    _SC_NL_MSGMAX,
    _SC_NL_NMAX,
    _SC_NL_SETMAX,
    _SC_NL_TEXTMAX,
    _SC_XBS5_ILP32_OFF32,
    _SC_XBS5_ILP32_OFFBIG,
    _SC_XBS5_LP64_OFF64,
    _SC_XBS5_LPBIG_OFFBIG,
    _SC_XOPEN_LEGACY,
    _SC_XOPEN_REALTIME,
    _SC_XOPEN_REALTIME_THREADS,
    _SC_ADVISORY_INFO,
    _SC_BARRIERS,
    _SC_BASE,
    _SC_C_LANG_SUPPORT,
    _SC_C_LANG_SUPPORT_R,
    _SC_CLOCK_SELECTION,
    _SC_CPUTIME,
    _SC_THREAD_CPUTIME,
    _SC_DEVICE_IO,
    _SC_DEVICE_SPECIFIC,
    _SC_DEVICE_SPECIFIC_R,
    _SC_FD_MGMT,
    _SC_FIFO,
    _SC_PIPE,
    _SC_FILE_ATTRIBUTES,
    _SC_FILE_LOCKING,
    _SC_FILE_SYSTEM,
    _SC_MONOTONIC_CLOCK,
    _SC_MULTI_PROCESS,
    _SC_SINGLE_PROCESS,
    _SC_NETWORKING,
    _SC_READER_WRITER_LOCKS,
    _SC_SPIN_LOCKS,
    _SC_REGEXP,
    _SC_REGEX_VERSION,
    _SC_SHELL,
    _SC_SIGNALS,
    _SC_SPAWN,
    _SC_SPORADIC_SERVER,
    _SC_THREAD_SPORADIC_SERVER,
    _SC_SYSTEM_DATABASE,
    _SC_SYSTEM_DATABASE_R,
    _SC_TIMEOUTS,
    _SC_TYPED_MEMORY_OBJECTS,
    _SC_USER_GROUPS,
    _SC_USER_GROUPS_R,
    _SC_2_PBS,
    _SC_2_PBS_ACCOUNTING,
    _SC_2_PBS_LOCATE,
    _SC_2_PBS_MESSAGE,
    _SC_2_PBS_TRACK,
    _SC_SYMLOOP_MAX,
    _SC_STREAMS,
    _SC_2_PBS_CHECKPOINT,
    _SC_V6_ILP32_OFF32,
    _SC_V6_ILP32_OFFBIG,
    _SC_V6_LP64_OFF64,
    _SC_V6_LPBIG_OFFBIG,
    _SC_HOST_NAME_MAX,
    _SC_TRACE,
    _SC_TRACE_EVENT_FILTER,
    _SC_TRACE_INHERIT,
    _SC_TRACE_LOG,
    _SC_LEVEL1_ICACHE_SIZE,
    _SC_LEVEL1_ICACHE_ASSOC,
    _SC_LEVEL1_ICACHE_LINESIZE,
    _SC_LEVEL1_DCACHE_SIZE,
    _SC_LEVEL1_DCACHE_ASSOC,
    _SC_LEVEL1_DCACHE_LINESIZE,
    _SC_LEVEL2_CACHE_SIZE,
    _SC_LEVEL2_CACHE_ASSOC,
    _SC_LEVEL2_CACHE_LINESIZE,
    _SC_LEVEL3_CACHE_SIZE,
    _SC_LEVEL3_CACHE_ASSOC,
    _SC_LEVEL3_CACHE_LINESIZE,
    _SC_LEVEL4_CACHE_SIZE,
    _SC_LEVEL4_CACHE_ASSOC,
    _SC_LEVEL4_CACHE_LINESIZE,
    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
    _SC_RAW_SOCKETS,
    _SC_V7_ILP32_OFF32,
    _SC_V7_ILP32_OFFBIG,
    _SC_V7_LP64_OFF64,
    _SC_V7_LPBIG_OFFBIG,
    _SC_SS_REPL_MAX,
    _SC_TRACE_EVENT_NAME_MAX,
    _SC_TRACE_NAME_MAX,
    _SC_TRACE_SYS_MAX,
    _SC_TRACE_USER_EVENT_MAX,
    _SC_XOPEN_STREAMS,
    _SC_THREAD_ROBUST_PRIO_INHERIT,
    _SC_THREAD_ROBUST_PRIO_PROTECT
};
enum {
    _CS_PATH,
    _CS_V6_WIDTH_RESTRICTED_ENVS,
    _CS_GNU_LIBC_VERSION,
    _CS_GNU_LIBPTHREAD_VERSION,
    _CS_V5_WIDTH_RESTRICTED_ENVS,
    _CS_V7_WIDTH_RESTRICTED_ENVS,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS,
    _CS_LFS_LIBS,
    _CS_LFS_LINTFLAGS,
    _CS_LFS64_CFLAGS,
    _CS_LFS64_LDFLAGS,
    _CS_LFS64_LIBS,
    _CS_LFS64_LINTFLAGS,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS,
    _CS_XBS5_ILP32_OFF32_LIBS,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LIBS,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
    _CS_XBS5_LP64_OFF64_CFLAGS,
    _CS_XBS5_LP64_OFF64_LDFLAGS,
    _CS_XBS5_LP64_OFF64_LIBS,
    _CS_XBS5_LP64_OFF64_LINTFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LIBS,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LIBS,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LIBS,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LIBS,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LIBS,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,
    _CS_V6_ENV,
    _CS_V7_ENV
};
extern long int pathconf(const char *__path, int __name) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern long int fpathconf(int __fd, int __name) __attribute__((__nothrow__, __leaf__));
extern long int sysconf(int __name) __attribute__((__nothrow__, __leaf__));
extern size_t confstr(int __name, char *__buf, size_t __len) __attribute__((__nothrow__, __leaf__));
extern __pid_t getpid(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t getppid(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t getpgrp(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t __getpgid(__pid_t __pid) __attribute__((__nothrow__, __leaf__));
extern __pid_t getpgid(__pid_t __pid) __attribute__((__nothrow__, __leaf__));
extern int setpgid(__pid_t __pid, __pid_t __pgid) __attribute__((__nothrow__, __leaf__));
extern int setpgrp(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t setsid(void) __attribute__((__nothrow__, __leaf__));
extern __pid_t getsid(__pid_t __pid) __attribute__((__nothrow__, __leaf__));
extern __uid_t getuid(void) __attribute__((__nothrow__, __leaf__));
extern __uid_t geteuid(void) __attribute__((__nothrow__, __leaf__));
extern __gid_t getgid(void) __attribute__((__nothrow__, __leaf__));
extern __gid_t getegid(void) __attribute__((__nothrow__, __leaf__));
extern int getgroups(int __size, __gid_t __list[]) __attribute__((__nothrow__, __leaf__));
extern int setuid(__uid_t __uid) __attribute__((__nothrow__, __leaf__));
extern int setreuid(__uid_t __ruid, __uid_t __euid) __attribute__((__nothrow__, __leaf__));
extern int seteuid(__uid_t __uid) __attribute__((__nothrow__, __leaf__));
extern int setgid(__gid_t __gid) __attribute__((__nothrow__, __leaf__));
extern int setregid(__gid_t __rgid, __gid_t __egid) __attribute__((__nothrow__, __leaf__));
extern int setegid(__gid_t __gid) __attribute__((__nothrow__, __leaf__));
extern __pid_t fork(void) __attribute__((__nothrow__));
extern __pid_t vfork(void) __attribute__((__nothrow__, __leaf__));
extern char *ttyname(int __fd) __attribute__((__nothrow__, __leaf__));
extern int ttyname_r(int __fd, char *__buf, size_t __buflen) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern int isatty(int __fd) __attribute__((__nothrow__, __leaf__));
extern int ttyslot(void) __attribute__((__nothrow__, __leaf__));
extern int link(const char *__from, const char *__to) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int linkat(int __fromfd, const char *__from, int __tofd, const char *__to, int __flags)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 4)));
extern int symlink(const char *__from, const char *__to) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern ssize_t readlink(const char *__restrict __path, char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int symlinkat(const char *__from, int __tofd, const char *__to) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 3)));
extern ssize_t readlinkat(int __fd, const char *__restrict __path, char *__restrict __buf, size_t __len)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern int unlink(const char *__name) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int unlinkat(int __fd, const char *__name, int __flag) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern int rmdir(const char *__path) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern __pid_t tcgetpgrp(int __fd) __attribute__((__nothrow__, __leaf__));
extern int tcsetpgrp(int __fd, __pid_t __pgrp_id) __attribute__((__nothrow__, __leaf__));
extern char *getlogin(void);
extern int getlogin_r(char *__name, size_t __name_len) __attribute__((__nonnull__(1)));
extern int setlogin(const char *__name) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;
extern int getopt(int ___argc, char *const *___argv, const char *__shortopts) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 3)));
extern int gethostname(char *__name, size_t __len) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int sethostname(const char *__name, size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int sethostid(long int __id) __attribute__((__nothrow__, __leaf__));
extern int getdomainname(char *__name, size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int setdomainname(const char *__name, size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int vhangup(void) __attribute__((__nothrow__, __leaf__));
extern int revoke(const char *__file) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int profil(unsigned short int *__sample_buffer, size_t __size, size_t __offset, unsigned int __scale)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int acct(const char *__name) __attribute__((__nothrow__, __leaf__));
extern char *getusershell(void) __attribute__((__nothrow__, __leaf__));
extern void endusershell(void) __attribute__((__nothrow__, __leaf__));
extern void setusershell(void) __attribute__((__nothrow__, __leaf__));
extern int daemon(int __nochdir, int __noclose) __attribute__((__nothrow__, __leaf__));
extern int chroot(const char *__path) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern char *getpass(const char *__prompt) __attribute__((__nonnull__(1)));
extern int fsync(int __fd);
extern long int gethostid(void);
extern void sync(void) __attribute__((__nothrow__, __leaf__));
extern int getpagesize(void) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int getdtablesize(void) __attribute__((__nothrow__, __leaf__));
extern int truncate(const char *__file, __off_t __length) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int ftruncate(int __fd, __off_t __length) __attribute__((__nothrow__, __leaf__));
extern int brk(void *__addr) __attribute__((__nothrow__, __leaf__));
extern void *sbrk(intptr_t __delta) __attribute__((__nothrow__, __leaf__));
extern long int syscall(long int __sysno, ...) __attribute__((__nothrow__, __leaf__));
extern int lockf(int __fd, int __cmd, __off_t __len);
extern int fdatasync(int __fildes);
int getentropy(void *__buffer, size_t __length);
typedef __mode_t mode_t;
extern void *mmap(void *__addr, size_t __len, int __prot, int __flags, int __fd, __off_t __offset)
    __attribute__((__nothrow__, __leaf__));
extern int munmap(void *__addr, size_t __len) __attribute__((__nothrow__, __leaf__));
extern int mprotect(void *__addr, size_t __len, int __prot) __attribute__((__nothrow__, __leaf__));
extern int msync(void *__addr, size_t __len, int __flags);
extern int madvise(void *__addr, size_t __len, int __advice) __attribute__((__nothrow__, __leaf__));
extern int posix_madvise(void *__addr, size_t __len, int __advice) __attribute__((__nothrow__, __leaf__));
extern int mlock(const void *__addr, size_t __len) __attribute__((__nothrow__, __leaf__));
extern int munlock(const void *__addr, size_t __len) __attribute__((__nothrow__, __leaf__));
extern int mlockall(int __flags) __attribute__((__nothrow__, __leaf__));
extern int munlockall(void) __attribute__((__nothrow__, __leaf__));
extern int mincore(void *__start, size_t __len, unsigned char *__vec) __attribute__((__nothrow__, __leaf__));
extern int shm_open(const char *__name, int __oflag, mode_t __mode);
extern int shm_unlink(const char *__name);
typedef struct {
    u8 *what;
    const u8 *where;
    uword flags;
    any code;
} clib_error_t;
enum {
    CLIB_ERROR_FATAL         = 1 << 0,
    CLIB_ERROR_ABORT         = 1 << 1,
    CLIB_ERROR_WARNING       = 1 << 2,
    CLIB_ERROR_ERRNO_VALID   = 1 << 16,
    CLIB_ERROR_NO_RATE_LIMIT = 1 << 17,
};
extern void _clib_error(int code, char *function_name, uword line_number, char *format, ...);
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __nlink_t nlink_t;
typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __clockid_t clockid_t;
typedef __time_t time_t;
typedef __timer_t timer_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef unsigned int u_int8_t __attribute__((__mode__(__QI__)));
typedef unsigned int u_int16_t __attribute__((__mode__(__HI__)));
typedef unsigned int u_int32_t __attribute__((__mode__(__SI__)));
typedef unsigned int u_int64_t __attribute__((__mode__(__DI__)));
typedef int register_t __attribute__((__mode__(__word__)));
static __inline unsigned int
__bswap_32(unsigned int __bsx)
{
    return __builtin_bswap32(__bsx);
}
static __inline __uint64_t
__bswap_64(__uint64_t __bsx)
{
    return __builtin_bswap64(__bsx);
}
static __inline __uint16_t
__uint16_identity(__uint16_t __x)
{
    return __x;
}
static __inline __uint32_t
__uint32_identity(__uint32_t __x)
{
    return __x;
}
static __inline __uint64_t
__uint64_identity(__uint64_t __x)
{
    return __x;
}
typedef struct {
    unsigned long int __val[(1024 / (8 * sizeof(unsigned long int)))];
} __sigset_t;
typedef __sigset_t sigset_t;
struct timeval {
    __time_t tv_sec;
    __suseconds_t tv_usec;
};
struct timespec {
    __time_t tv_sec;
    __syscall_slong_t tv_nsec;
};
typedef __suseconds_t suseconds_t;
typedef long int __fd_mask;
typedef struct {
    __fd_mask __fds_bits[1024 / (8 * (int) sizeof(__fd_mask))];
} fd_set;
typedef __fd_mask fd_mask;
extern int select(int __nfds, fd_set *__restrict __readfds, fd_set *__restrict __writefds,
                  fd_set *__restrict __exceptfds, struct timeval *__restrict __timeout);
extern int pselect(int __nfds, fd_set *__restrict __readfds, fd_set *__restrict __writefds,
                   fd_set *__restrict __exceptfds, const struct timespec *__restrict __timeout,
                   const __sigset_t *__restrict __sigmask);
extern unsigned int gnu_dev_major(__dev_t __dev) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern unsigned int gnu_dev_minor(__dev_t __dev) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern __dev_t gnu_dev_makedev(unsigned int __major, unsigned int __minor) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
struct __pthread_rwlock_arch_t {
    unsigned int __readers;
    unsigned int __writers;
    unsigned int __wrphase_futex;
    unsigned int __writers_futex;
    unsigned int __pad3;
    unsigned int __pad4;
    int __cur_writer;
    int __shared;
    signed char __rwelision;
    unsigned char __pad1[7];
    unsigned long int __pad2;
    unsigned int __flags;
};
typedef struct __pthread_internal_list {
    struct __pthread_internal_list *__prev;
    struct __pthread_internal_list *__next;
} __pthread_list_t;
struct __pthread_mutex_s {
    int __lock;
    unsigned int __count;
    int __owner;
    unsigned int __nusers;
    int __kind;

    short __spins;
    short __elision;
    __pthread_list_t __list;
};
struct __pthread_cond_s {
    __extension__ union {
        __extension__ unsigned long long int __wseq;
        struct {
            unsigned int __low;
            unsigned int __high;
        } __wseq32;
    };
    __extension__ union {
        __extension__ unsigned long long int __g1_start;
        struct {
            unsigned int __low;
            unsigned int __high;
        } __g1_start32;
    };
    unsigned int __g_refs[2];
    unsigned int __g_size[2];
    unsigned int __g1_orig_size;
    unsigned int __wrefs;
    unsigned int __g_signals[2];
};
typedef unsigned long int pthread_t;
typedef union {
    char __size[4];
    int __align;
} pthread_mutexattr_t;
typedef union {
    char __size[4];
    int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t {
    char __size[56];
    long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef union {
    struct __pthread_mutex_s __data;
    char __size[40];
    long int __align;
} pthread_mutex_t;
typedef union {
    struct __pthread_cond_s __data;
    char __size[48];
    __extension__ long long int __align;
} pthread_cond_t;
typedef union {
    struct __pthread_rwlock_arch_t __data;
    char __size[56];
    long int __align;
} pthread_rwlock_t;
typedef union {
    char __size[8];
    long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union {
    char __size[32];
    long int __align;
} pthread_barrier_t;
typedef union {
    char __size[4];
    int __align;
} pthread_barrierattr_t;
struct dlmallinfo {
    size_t arena;
    size_t ordblks;
    size_t smblks;
    size_t hblks;
    size_t hblkhd;
    size_t usmblks;
    size_t fsmblks;
    size_t uordblks;
    size_t fordblks;
    size_t keepcost;
};
typedef void *mspace;
extern mspace create_mspace(size_t capacity, int locked);
extern size_t destroy_mspace(mspace msp);
extern mspace create_mspace_with_base(void *base, size_t capacity, int locked);
extern int mspace_track_large_chunks(mspace msp, int enable);
extern void *mspace_malloc(mspace msp, size_t bytes);
extern void mspace_free(mspace msp, void *mem);
extern void *mspace_realloc(mspace msp, void *mem, size_t newsize);
extern void *mspace_calloc(mspace msp, size_t n_elements, size_t elem_size);
extern void *mspace_memalign(mspace msp, size_t alignment, size_t bytes);
extern void **mspace_independent_calloc(mspace msp, size_t n_elements, size_t elem_size, void *chunks[]);
extern void **mspace_independent_comalloc(mspace msp, size_t n_elements, size_t sizes[], void *chunks[]);
extern size_t mspace_footprint(mspace msp);
extern size_t mspace_max_footprint(mspace msp);
extern struct dlmallinfo mspace_mallinfo(mspace msp);
extern size_t mspace_usable_size(const void *mem);
extern void mspace_malloc_stats(mspace msp);
extern int mspace_trim(mspace msp, size_t pad);
extern int mspace_mallopt(int, int);
extern void *mspace_get_aligned(mspace msp, unsigned long long n_user_data_bytes, unsigned long long align,
                                unsigned long long align_offset);
extern int mspace_is_heap_object(mspace msp, void *p);
extern void mspace_get_address_and_size(mspace msp, unsigned long long *addrp, unsigned long long *sizep);
extern void mspace_put(mspace msp, void *p);
extern void mspace_put_no_offset(mspace msp, void *p);
extern size_t mspace_usable_size_with_delta(const void *p);
extern void mspace_disable_expand(mspace msp);
extern void *mspace_least_addr(mspace msp);
extern void mheap_get_trace(u64 offset, u64 size);
extern void mheap_put_trace(u64 offset, u64 size);
extern int mspace_enable_disable_trace(mspace msp, int enable);
void os_panic(void);
void os_exit(int code);
void os_puts(u8 *string, uword length, uword is_error);
void os_out_of_memory(void);
f64 os_cpu_clock_frequency(void);
extern __thread uword __os_thread_index;
static inline __attribute__((__always_inline__)) uword
os_get_thread_index(void)
{
    return __os_thread_index;
}
static inline __attribute__((__always_inline__)) uword os_get_cpu_number(void) __attribute__((deprecated));
static inline __attribute__((__always_inline__)) uword
os_get_cpu_number(void)
{
    return __os_thread_index;
}
uword os_get_nthreads(void);
struct sched_param {
    int sched_priority;
};
typedef unsigned long int __cpu_mask;
typedef struct {
    __cpu_mask __bits[1024 / (8 * sizeof(__cpu_mask))];
} cpu_set_t;
extern int __sched_cpucount(size_t __setsize, const cpu_set_t *__setp) __attribute__((__nothrow__, __leaf__));
extern cpu_set_t *__sched_cpualloc(size_t __count) __attribute__((__nothrow__, __leaf__));
extern void __sched_cpufree(cpu_set_t *__set) __attribute__((__nothrow__, __leaf__));
extern int sched_setparam(__pid_t __pid, const struct sched_param *__param) __attribute__((__nothrow__, __leaf__));
extern int sched_getparam(__pid_t __pid, struct sched_param *__param) __attribute__((__nothrow__, __leaf__));
extern int sched_setscheduler(__pid_t __pid, int __policy, const struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__));
extern int sched_getscheduler(__pid_t __pid) __attribute__((__nothrow__, __leaf__));
extern int sched_yield(void) __attribute__((__nothrow__, __leaf__));
extern int sched_get_priority_max(int __algorithm) __attribute__((__nothrow__, __leaf__));
extern int sched_get_priority_min(int __algorithm) __attribute__((__nothrow__, __leaf__));
extern int sched_rr_get_interval(__pid_t __pid, struct timespec *__t) __attribute__((__nothrow__, __leaf__));
static inline __attribute__((__always_inline__)) void
os_sched_yield(void)
{
    sched_yield();
}
typedef i8 i8x8 __attribute__((vector_size(8 / 8 * 8)));
typedef union {
    i8x8 as_i8x8;
    i8 as_i8[8];
} i8x8_union_t;
typedef i16 i16x4 __attribute__((vector_size(16 / 8 * 4)));
typedef union {
    i16x4 as_i16x4;
    i16 as_i16[4];
} i16x4_union_t;
typedef i32 i32x2 __attribute__((vector_size(32 / 8 * 2)));
typedef union {
    i32x2 as_i32x2;
    i32 as_i32[2];
} i32x2_union_t;
typedef u8 u8x8 __attribute__((vector_size(8 / 8 * 8)));
typedef union {
    u8x8 as_u8x8;
    u8 as_u8[8];
} u8x8_union_t;
typedef u16 u16x4 __attribute__((vector_size(16 / 8 * 4)));
typedef union {
    u16x4 as_u16x4;
    u16 as_u16[4];
} u16x4_union_t;
typedef u32 u32x2 __attribute__((vector_size(32 / 8 * 2)));
typedef union {
    u32x2 as_u32x2;
    u32 as_u32[2];
} u32x2_union_t;
typedef f32 f32x2 __attribute__((vector_size(32 / 8 * 2)));
typedef union {
    f32x2 as_f32x2;
    f32 as_f32[2];
} f32x2_union_t;
typedef i8 i8x16 __attribute__((vector_size(8 / 8 * 16)));
typedef union {
    i8x16 as_i8x16;
    i8 as_i8[16];
} i8x16_union_t;
typedef i16 i16x8 __attribute__((vector_size(16 / 8 * 8)));
typedef union {
    i16x8 as_i16x8;
    i16 as_i16[8];
} i16x8_union_t;
typedef i32 i32x4 __attribute__((vector_size(32 / 8 * 4)));
typedef union {
    i32x4 as_i32x4;
    i32 as_i32[4];
} i32x4_union_t;
typedef i64 i64x2 __attribute__((vector_size(64 / 8 * 2)));
typedef union {
    i64x2 as_i64x2;
    i64 as_i64[2];
} i64x2_union_t;
typedef u8 u8x16 __attribute__((vector_size(8 / 8 * 16)));
typedef union {
    u8x16 as_u8x16;
    u8 as_u8[16];
} u8x16_union_t;
typedef u16 u16x8 __attribute__((vector_size(16 / 8 * 8)));
typedef union {
    u16x8 as_u16x8;
    u16 as_u16[8];
} u16x8_union_t;
typedef u32 u32x4 __attribute__((vector_size(32 / 8 * 4)));
typedef union {
    u32x4 as_u32x4;
    u32 as_u32[4];
} u32x4_union_t;
typedef u64 u64x2 __attribute__((vector_size(64 / 8 * 2)));
typedef union {
    u64x2 as_u64x2;
    u64 as_u64[2];
} u64x2_union_t;
typedef f32 f32x4 __attribute__((vector_size(32 / 8 * 4)));
typedef union {
    f32x4 as_f32x4;
    f32 as_f32[4];
} f32x4_union_t;
typedef f64 f64x2 __attribute__((vector_size(64 / 8 * 2)));
typedef union {
    f64x2 as_f64x2;
    f64 as_f64[2];
} f64x2_union_t;
typedef i8 i8x32 __attribute__((vector_size(8 / 8 * 32)));
typedef union {
    i8x32 as_i8x32;
    i8 as_i8[32];
} i8x32_union_t;
typedef i16 i16x16 __attribute__((vector_size(16 / 8 * 16)));
typedef union {
    i16x16 as_i16x16;
    i16 as_i16[16];
} i16x16_union_t;
typedef i32 i32x8 __attribute__((vector_size(32 / 8 * 8)));
typedef union {
    i32x8 as_i32x8;
    i32 as_i32[8];
} i32x8_union_t;
typedef i64 i64x4 __attribute__((vector_size(64 / 8 * 4)));
typedef union {
    i64x4 as_i64x4;
    i64 as_i64[4];
} i64x4_union_t;
typedef u8 u8x32 __attribute__((vector_size(8 / 8 * 32)));
typedef union {
    u8x32 as_u8x32;
    u8 as_u8[32];
} u8x32_union_t;
typedef u16 u16x16 __attribute__((vector_size(16 / 8 * 16)));
typedef union {
    u16x16 as_u16x16;
    u16 as_u16[16];
} u16x16_union_t;
typedef u32 u32x8 __attribute__((vector_size(32 / 8 * 8)));
typedef union {
    u32x8 as_u32x8;
    u32 as_u32[8];
} u32x8_union_t;
typedef u64 u64x4 __attribute__((vector_size(64 / 8 * 4)));
typedef union {
    u64x4 as_u64x4;
    u64 as_u64[4];
} u64x4_union_t;
typedef f32 f32x8 __attribute__((vector_size(32 / 8 * 8)));
typedef union {
    f32x8 as_f32x8;
    f32 as_f32[8];
} f32x8_union_t;
typedef f64 f64x4 __attribute__((vector_size(64 / 8 * 4)));
typedef union {
    f64x4 as_f64x4;
    f64 as_f64[4];
} f64x4_union_t;
typedef i8 i8x64 __attribute__((vector_size(8 / 8 * 64)));
typedef union {
    i8x64 as_i8x64;
    i8 as_i8[64];
} i8x64_union_t;
typedef i16 i16x32 __attribute__((vector_size(16 / 8 * 32)));
typedef union {
    i16x32 as_i16x32;
    i16 as_i16[32];
} i16x32_union_t;
typedef i32 i32x16 __attribute__((vector_size(32 / 8 * 16)));
typedef union {
    i32x16 as_i32x16;
    i32 as_i32[16];
} i32x16_union_t;
typedef i64 i64x8 __attribute__((vector_size(64 / 8 * 8)));
typedef union {
    i64x8 as_i64x8;
    i64 as_i64[8];
} i64x8_union_t;
typedef u8 u8x64 __attribute__((vector_size(8 / 8 * 64)));
typedef union {
    u8x64 as_u8x64;
    u8 as_u8[64];
} u8x64_union_t;
typedef u16 u16x32 __attribute__((vector_size(16 / 8 * 32)));
typedef union {
    u16x32 as_u16x32;
    u16 as_u16[32];
} u16x32_union_t;
typedef u32 u32x16 __attribute__((vector_size(32 / 8 * 16)));
typedef union {
    u32x16 as_u32x16;
    u32 as_u32[16];
} u32x16_union_t;
typedef u64 u64x8 __attribute__((vector_size(64 / 8 * 8)));
typedef union {
    u64x8 as_u64x8;
    u64 as_u64[8];
} u64x8_union_t;
typedef f32 f32x16 __attribute__((vector_size(32 / 8 * 16)));
typedef union {
    f32x16 as_f32x16;
    f32 as_f32[16];
} f32x16_union_t;
typedef f64 f64x8 __attribute__((vector_size(64 / 8 * 8)));
typedef union {
    f64x8 as_f64x8;
    f64 as_f64[8];
} f64x8_union_t;
typedef i8 i8x __attribute__((vector_size(8)));
typedef i16 i16x __attribute__((vector_size(8)));
typedef i32 i32x __attribute__((vector_size(8)));
typedef i64 i64x __attribute__((vector_size(8)));
typedef u8 u8x __attribute__((vector_size(8)));
typedef u16 u16x __attribute__((vector_size(8)));
typedef u32 u32x __attribute__((vector_size(8)));
typedef u64 u64x __attribute__((vector_size(8)));
static inline __attribute__((__always_inline__)) u16
clib_byte_swap_u16(u16 x)
{
    return (x >> 8) | (x << 8);
}
static inline __attribute__((__always_inline__)) i16
clib_byte_swap_i16(i16 x)
{
    return clib_byte_swap_u16(x);
}
static inline __attribute__((__always_inline__)) u32
clib_byte_swap_u32(u32 x)
{
    if (!__builtin_constant_p(x)) {
        asm volatile("bswap %0" : "=r"(x) : "0"(x));
        return x;
    }
    return ((x << 24) | ((x & 0xff00) << 8) | ((x >> 8) & 0xff00) | (x >> 24));
}
static inline __attribute__((__always_inline__)) i32
clib_byte_swap_i32(i32 x)
{
    return clib_byte_swap_u32(x);
}
static inline __attribute__((__always_inline__)) u64
clib_byte_swap_u64(u64 x)
{
    if (!__builtin_constant_p(x)) {
        asm volatile("bswapq %0" : "=r"(x) : "0"(x));
        return x;
    }
    return (
        ((((x) >> (8 * (0))) & 0xff) << (8 * ((8) - (0) - 1))) | ((((x) >> (8 * (1))) & 0xff) << (8 * ((8) - (1) - 1))) |
        ((((x) >> (8 * (2))) & 0xff) << (8 * ((8) - (2) - 1))) | ((((x) >> (8 * (3))) & 0xff) << (8 * ((8) - (3) - 1))) |
        ((((x) >> (8 * (4))) & 0xff) << (8 * ((8) - (4) - 1))) | ((((x) >> (8 * (5))) & 0xff) << (8 * ((8) - (5) - 1))) |
        ((((x) >> (8 * (6))) & 0xff) << (8 * ((8) - (6) - 1))) | ((((x) >> (8 * (7))) & 0xff) << (8 * ((8) - (7) - 1))));
}
static inline __attribute__((__always_inline__)) i64
clib_byte_swap_i64(i64 x)
{
    return clib_byte_swap_u64(x);
}
static inline __attribute__((__always_inline__)) u16
clib_host_to_little_u16(u16 x)
{
    if (!(1))
        x = clib_byte_swap_u16(x);
    return x;
}
static inline __attribute__((__always_inline__)) u16
clib_host_to_little_mem_u16(u16 *x)
{
    u16 v = x[0];
    return clib_host_to_little_u16(v);
}
static inline __attribute__((__always_inline__)) u16
clib_host_to_little_unaligned_mem_u16(u16 *x)
{
    u16 v = (((struct { u16 _data __attribute__((packed)); } *) (x))->_data);
    return clib_host_to_little_u16(v);
}
static inline __attribute__((__always_inline__)) u16
clib_little_to_host_u16(u16 x)
{
    return clib_host_to_little_u16(x);
}
static inline __attribute__((__always_inline__)) u16
clib_little_to_host_mem_u16(u16 *x)
{
    return clib_host_to_little_mem_u16(x);
}
static inline __attribute__((__always_inline__)) u16
clib_little_to_host_unaligned_mem_u16(u16 *x)
{
    return clib_host_to_little_unaligned_mem_u16(x);
}
static inline __attribute__((__always_inline__)) u32
clib_host_to_little_u32(u32 x)
{
    if (!(1))
        x = clib_byte_swap_u32(x);
    return x;
}
static inline __attribute__((__always_inline__)) u32
clib_host_to_little_mem_u32(u32 *x)
{
    u32 v = x[0];
    return clib_host_to_little_u32(v);
}
static inline __attribute__((__always_inline__)) u32
clib_host_to_little_unaligned_mem_u32(u32 *x)
{
    u32 v = (((struct { u32 _data __attribute__((packed)); } *) (x))->_data);
    return clib_host_to_little_u32(v);
}
static inline __attribute__((__always_inline__)) u32
clib_little_to_host_u32(u32 x)
{
    return clib_host_to_little_u32(x);
}
static inline __attribute__((__always_inline__)) u32
clib_little_to_host_mem_u32(u32 *x)
{
    return clib_host_to_little_mem_u32(x);
}
static inline __attribute__((__always_inline__)) u32
clib_little_to_host_unaligned_mem_u32(u32 *x)
{
    return clib_host_to_little_unaligned_mem_u32(x);
}
static inline __attribute__((__always_inline__)) u64
clib_host_to_little_u64(u64 x)
{
    if (!(1))
        x = clib_byte_swap_u64(x);
    return x;
}
static inline __attribute__((__always_inline__)) u64
clib_host_to_little_mem_u64(u64 *x)
{
    u64 v = x[0];
    return clib_host_to_little_u64(v);
}
static inline __attribute__((__always_inline__)) u64
clib_host_to_little_unaligned_mem_u64(u64 *x)
{
    u64 v = (((struct { u64 _data __attribute__((packed)); } *) (x))->_data);
    return clib_host_to_little_u64(v);
}
static inline __attribute__((__always_inline__)) u64
clib_little_to_host_u64(u64 x)
{
    return clib_host_to_little_u64(x);
}
static inline __attribute__((__always_inline__)) u64
clib_little_to_host_mem_u64(u64 *x)
{
    return clib_host_to_little_mem_u64(x);
}
static inline __attribute__((__always_inline__)) u64
clib_little_to_host_unaligned_mem_u64(u64 *x)
{
    return clib_host_to_little_unaligned_mem_u64(x);
}
static inline __attribute__((__always_inline__)) i16
clib_host_to_little_i16(i16 x)
{
    if (!(1))
        x = clib_byte_swap_i16(x);
    return x;
}
static inline __attribute__((__always_inline__)) i16
clib_host_to_little_mem_i16(i16 *x)
{
    i16 v = x[0];
    return clib_host_to_little_i16(v);
}
static inline __attribute__((__always_inline__)) i16
clib_host_to_little_unaligned_mem_i16(i16 *x)
{
    i16 v = (((struct { i16 _data __attribute__((packed)); } *) (x))->_data);
    return clib_host_to_little_i16(v);
}
static inline __attribute__((__always_inline__)) i16
clib_little_to_host_i16(i16 x)
{
    return clib_host_to_little_i16(x);
}
static inline __attribute__((__always_inline__)) i16
clib_little_to_host_mem_i16(i16 *x)
{
    return clib_host_to_little_mem_i16(x);
}
static inline __attribute__((__always_inline__)) i16
clib_little_to_host_unaligned_mem_i16(i16 *x)
{
    return clib_host_to_little_unaligned_mem_i16(x);
}
static inline __attribute__((__always_inline__)) i32
clib_host_to_little_i32(i32 x)
{
    if (!(1))
        x = clib_byte_swap_i32(x);
    return x;
}
static inline __attribute__((__always_inline__)) i32
clib_host_to_little_mem_i32(i32 *x)
{
    i32 v = x[0];
    return clib_host_to_little_i32(v);
}
static inline __attribute__((__always_inline__)) i32
clib_host_to_little_unaligned_mem_i32(i32 *x)
{
    i32 v = (((struct { i32 _data __attribute__((packed)); } *) (x))->_data);
    return clib_host_to_little_i32(v);
}
static inline __attribute__((__always_inline__)) i32
clib_little_to_host_i32(i32 x)
{
    return clib_host_to_little_i32(x);
}
static inline __attribute__((__always_inline__)) i32
clib_little_to_host_mem_i32(i32 *x)
{
    return clib_host_to_little_mem_i32(x);
}
static inline __attribute__((__always_inline__)) i32
clib_little_to_host_unaligned_mem_i32(i32 *x)
{
    return clib_host_to_little_unaligned_mem_i32(x);
}
static inline __attribute__((__always_inline__)) i64
clib_host_to_little_i64(i64 x)
{
    if (!(1))
        x = clib_byte_swap_i64(x);
    return x;
}
static inline __attribute__((__always_inline__)) i64
clib_host_to_little_mem_i64(i64 *x)
{
    i64 v = x[0];
    return clib_host_to_little_i64(v);
}
static inline __attribute__((__always_inline__)) i64
clib_host_to_little_unaligned_mem_i64(i64 *x)
{
    i64 v = (((struct { i64 _data __attribute__((packed)); } *) (x))->_data);
    return clib_host_to_little_i64(v);
}
static inline __attribute__((__always_inline__)) i64
clib_little_to_host_i64(i64 x)
{
    return clib_host_to_little_i64(x);
}
static inline __attribute__((__always_inline__)) i64
clib_little_to_host_mem_i64(i64 *x)
{
    return clib_host_to_little_mem_i64(x);
}
static inline __attribute__((__always_inline__)) i64
clib_little_to_host_unaligned_mem_i64(i64 *x)
{
    return clib_host_to_little_unaligned_mem_i64(x);
}
static inline __attribute__((__always_inline__)) u16
clib_host_to_big_u16(u16 x)
{
    if (!(0))
        x = clib_byte_swap_u16(x);
    return x;
}
static inline __attribute__((__always_inline__)) u16
clib_host_to_big_mem_u16(u16 *x)
{
    u16 v = x[0];
    return clib_host_to_big_u16(v);
}
static inline __attribute__((__always_inline__)) u16
clib_host_to_big_unaligned_mem_u16(u16 *x)
{
    u16 v = (((struct { u16 _data __attribute__((packed)); } *) (x))->_data);
    return clib_host_to_big_u16(v);
}
static inline __attribute__((__always_inline__)) u16
clib_big_to_host_u16(u16 x)
{
    return clib_host_to_big_u16(x);
}
static inline __attribute__((__always_inline__)) u16
clib_big_to_host_mem_u16(u16 *x)
{
    return clib_host_to_big_mem_u16(x);
}
static inline __attribute__((__always_inline__)) u16
clib_big_to_host_unaligned_mem_u16(u16 *x)
{
    return clib_host_to_big_unaligned_mem_u16(x);
}
static inline __attribute__((__always_inline__)) u32
clib_host_to_big_u32(u32 x)
{
    if (!(0))
        x = clib_byte_swap_u32(x);
    return x;
}
static inline __attribute__((__always_inline__)) u32
clib_host_to_big_mem_u32(u32 *x)
{
    u32 v = x[0];
    return clib_host_to_big_u32(v);
}
static inline __attribute__((__always_inline__)) u32
clib_host_to_big_unaligned_mem_u32(u32 *x)
{
    u32 v = (((struct { u32 _data __attribute__((packed)); } *) (x))->_data);
    return clib_host_to_big_u32(v);
}
static inline __attribute__((__always_inline__)) u32
clib_big_to_host_u32(u32 x)
{
    return clib_host_to_big_u32(x);
}
static inline __attribute__((__always_inline__)) u32
clib_big_to_host_mem_u32(u32 *x)
{
    return clib_host_to_big_mem_u32(x);
}
static inline __attribute__((__always_inline__)) u32
clib_big_to_host_unaligned_mem_u32(u32 *x)
{
    return clib_host_to_big_unaligned_mem_u32(x);
}
static inline __attribute__((__always_inline__)) u64
clib_host_to_big_u64(u64 x)
{
    if (!(0))
        x = clib_byte_swap_u64(x);
    return x;
}
static inline __attribute__((__always_inline__)) u64
clib_host_to_big_mem_u64(u64 *x)
{
    u64 v = x[0];
    return clib_host_to_big_u64(v);
}
static inline __attribute__((__always_inline__)) u64
clib_host_to_big_unaligned_mem_u64(u64 *x)
{
    u64 v = (((struct { u64 _data __attribute__((packed)); } *) (x))->_data);
    return clib_host_to_big_u64(v);
}
static inline __attribute__((__always_inline__)) u64
clib_big_to_host_u64(u64 x)
{
    return clib_host_to_big_u64(x);
}
static inline __attribute__((__always_inline__)) u64
clib_big_to_host_mem_u64(u64 *x)
{
    return clib_host_to_big_mem_u64(x);
}
static inline __attribute__((__always_inline__)) u64
clib_big_to_host_unaligned_mem_u64(u64 *x)
{
    return clib_host_to_big_unaligned_mem_u64(x);
}
static inline __attribute__((__always_inline__)) i16
clib_host_to_big_i16(i16 x)
{
    if (!(0))
        x = clib_byte_swap_i16(x);
    return x;
}
static inline __attribute__((__always_inline__)) i16
clib_host_to_big_mem_i16(i16 *x)
{
    i16 v = x[0];
    return clib_host_to_big_i16(v);
}
static inline __attribute__((__always_inline__)) i16
clib_host_to_big_unaligned_mem_i16(i16 *x)
{
    i16 v = (((struct { i16 _data __attribute__((packed)); } *) (x))->_data);
    return clib_host_to_big_i16(v);
}
static inline __attribute__((__always_inline__)) i16
clib_big_to_host_i16(i16 x)
{
    return clib_host_to_big_i16(x);
}
static inline __attribute__((__always_inline__)) i16
clib_big_to_host_mem_i16(i16 *x)
{
    return clib_host_to_big_mem_i16(x);
}
static inline __attribute__((__always_inline__)) i16
clib_big_to_host_unaligned_mem_i16(i16 *x)
{
    return clib_host_to_big_unaligned_mem_i16(x);
}
static inline __attribute__((__always_inline__)) i32
clib_host_to_big_i32(i32 x)
{
    if (!(0))
        x = clib_byte_swap_i32(x);
    return x;
}
static inline __attribute__((__always_inline__)) i32
clib_host_to_big_mem_i32(i32 *x)
{
    i32 v = x[0];
    return clib_host_to_big_i32(v);
}
static inline __attribute__((__always_inline__)) i32
clib_host_to_big_unaligned_mem_i32(i32 *x)
{
    i32 v = (((struct { i32 _data __attribute__((packed)); } *) (x))->_data);
    return clib_host_to_big_i32(v);
}
static inline __attribute__((__always_inline__)) i32
clib_big_to_host_i32(i32 x)
{
    return clib_host_to_big_i32(x);
}
static inline __attribute__((__always_inline__)) i32
clib_big_to_host_mem_i32(i32 *x)
{
    return clib_host_to_big_mem_i32(x);
}
static inline __attribute__((__always_inline__)) i32
clib_big_to_host_unaligned_mem_i32(i32 *x)
{
    return clib_host_to_big_unaligned_mem_i32(x);
}
static inline __attribute__((__always_inline__)) i64
clib_host_to_big_i64(i64 x)
{
    if (!(0))
        x = clib_byte_swap_i64(x);
    return x;
}
static inline __attribute__((__always_inline__)) i64
clib_host_to_big_mem_i64(i64 *x)
{
    i64 v = x[0];
    return clib_host_to_big_i64(v);
}
static inline __attribute__((__always_inline__)) i64
clib_host_to_big_unaligned_mem_i64(i64 *x)
{
    i64 v = (((struct { i64 _data __attribute__((packed)); } *) (x))->_data);
    return clib_host_to_big_i64(v);
}
static inline __attribute__((__always_inline__)) i64
clib_big_to_host_i64(i64 x)
{
    return clib_host_to_big_i64(x);
}
static inline __attribute__((__always_inline__)) i64
clib_big_to_host_mem_i64(i64 *x)
{
    return clib_host_to_big_mem_i64(x);
}
static inline __attribute__((__always_inline__)) i64
clib_big_to_host_unaligned_mem_i64(i64 *x)
{
    return clib_host_to_big_unaligned_mem_i64(x);
}
static inline __attribute__((__always_inline__)) u16
clib_net_to_host_u16(u16 x)
{
    return clib_big_to_host_u16(x);
}
static inline __attribute__((__always_inline__)) u16
clib_net_to_host_mem_u16(u16 *x)
{
    return clib_big_to_host_mem_u16(x);
}
static inline __attribute__((__always_inline__)) u16
clib_net_to_host_unaligned_mem_u16(u16 *x)
{
    return clib_big_to_host_unaligned_mem_u16(x);
}
static inline __attribute__((__always_inline__)) u16
clib_host_to_net_u16(u16 x)
{
    return clib_host_to_big_u16(x);
}
static inline __attribute__((__always_inline__)) u16
clib_host_to_net_mem_u16(u16 *x)
{
    return clib_host_to_big_mem_u16(x);
}
static inline __attribute__((__always_inline__)) u16
clib_host_to_net_unaligned_mem_u16(u16 *x)
{
    return clib_host_to_big_unaligned_mem_u16(x);
};
static inline __attribute__((__always_inline__)) i16
clib_net_to_host_i16(i16 x)
{
    return clib_big_to_host_i16(x);
}
static inline __attribute__((__always_inline__)) i16
clib_net_to_host_mem_i16(i16 *x)
{
    return clib_big_to_host_mem_i16(x);
}
static inline __attribute__((__always_inline__)) i16
clib_net_to_host_unaligned_mem_i16(i16 *x)
{
    return clib_big_to_host_unaligned_mem_i16(x);
}
static inline __attribute__((__always_inline__)) i16
clib_host_to_net_i16(i16 x)
{
    return clib_host_to_big_i16(x);
}
static inline __attribute__((__always_inline__)) i16
clib_host_to_net_mem_i16(i16 *x)
{
    return clib_host_to_big_mem_i16(x);
}
static inline __attribute__((__always_inline__)) i16
clib_host_to_net_unaligned_mem_i16(i16 *x)
{
    return clib_host_to_big_unaligned_mem_i16(x);
};
static inline __attribute__((__always_inline__)) u32
clib_net_to_host_u32(u32 x)
{
    return clib_big_to_host_u32(x);
}
static inline __attribute__((__always_inline__)) u32
clib_net_to_host_mem_u32(u32 *x)
{
    return clib_big_to_host_mem_u32(x);
}
static inline __attribute__((__always_inline__)) u32
clib_net_to_host_unaligned_mem_u32(u32 *x)
{
    return clib_big_to_host_unaligned_mem_u32(x);
}
static inline __attribute__((__always_inline__)) u32
clib_host_to_net_u32(u32 x)
{
    return clib_host_to_big_u32(x);
}
static inline __attribute__((__always_inline__)) u32
clib_host_to_net_mem_u32(u32 *x)
{
    return clib_host_to_big_mem_u32(x);
}
static inline __attribute__((__always_inline__)) u32
clib_host_to_net_unaligned_mem_u32(u32 *x)
{
    return clib_host_to_big_unaligned_mem_u32(x);
};
static inline __attribute__((__always_inline__)) i32
clib_net_to_host_i32(i32 x)
{
    return clib_big_to_host_i32(x);
}
static inline __attribute__((__always_inline__)) i32
clib_net_to_host_mem_i32(i32 *x)
{
    return clib_big_to_host_mem_i32(x);
}
static inline __attribute__((__always_inline__)) i32
clib_net_to_host_unaligned_mem_i32(i32 *x)
{
    return clib_big_to_host_unaligned_mem_i32(x);
}
static inline __attribute__((__always_inline__)) i32
clib_host_to_net_i32(i32 x)
{
    return clib_host_to_big_i32(x);
}
static inline __attribute__((__always_inline__)) i32
clib_host_to_net_mem_i32(i32 *x)
{
    return clib_host_to_big_mem_i32(x);
}
static inline __attribute__((__always_inline__)) i32
clib_host_to_net_unaligned_mem_i32(i32 *x)
{
    return clib_host_to_big_unaligned_mem_i32(x);
};
static inline __attribute__((__always_inline__)) u64
clib_net_to_host_u64(u64 x)
{
    return clib_big_to_host_u64(x);
}
static inline __attribute__((__always_inline__)) u64
clib_net_to_host_mem_u64(u64 *x)
{
    return clib_big_to_host_mem_u64(x);
}
static inline __attribute__((__always_inline__)) u64
clib_net_to_host_unaligned_mem_u64(u64 *x)
{
    return clib_big_to_host_unaligned_mem_u64(x);
}
static inline __attribute__((__always_inline__)) u64
clib_host_to_net_u64(u64 x)
{
    return clib_host_to_big_u64(x);
}
static inline __attribute__((__always_inline__)) u64
clib_host_to_net_mem_u64(u64 *x)
{
    return clib_host_to_big_mem_u64(x);
}
static inline __attribute__((__always_inline__)) u64
clib_host_to_net_unaligned_mem_u64(u64 *x)
{
    return clib_host_to_big_unaligned_mem_u64(x);
};
static inline __attribute__((__always_inline__)) i64
clib_net_to_host_i64(i64 x)
{
    return clib_big_to_host_i64(x);
}
static inline __attribute__((__always_inline__)) i64
clib_net_to_host_mem_i64(i64 *x)
{
    return clib_big_to_host_mem_i64(x);
}
static inline __attribute__((__always_inline__)) i64
clib_net_to_host_unaligned_mem_i64(i64 *x)
{
    return clib_big_to_host_unaligned_mem_i64(x);
}
static inline __attribute__((__always_inline__)) i64
clib_host_to_net_i64(i64 x)
{
    return clib_host_to_big_i64(x);
}
static inline __attribute__((__always_inline__)) i64
clib_host_to_net_mem_i64(i64 *x)
{
    return clib_host_to_big_mem_i64(x);
}
static inline __attribute__((__always_inline__)) i64
clib_host_to_net_unaligned_mem_i64(i64 *x)
{
    return clib_host_to_big_unaligned_mem_i64(x);
};
static inline __attribute__((__always_inline__)) i8x16
i8x16_splat(i8 x)
{
    i8x16 r;
    int i;
    for (i = 0; i < 16; i++)
        r[i] = x;
    return r;
}
static inline __attribute__((__always_inline__)) i16x8
i16x8_splat(i16 x)
{
    i16x8 r;
    int i;
    for (i = 0; i < 8; i++)
        r[i] = x;
    return r;
}
static inline __attribute__((__always_inline__)) i32x4
i32x4_splat(i32 x)
{
    i32x4 r;
    int i;
    for (i = 0; i < 4; i++)
        r[i] = x;
    return r;
}
static inline __attribute__((__always_inline__)) i64x2
i64x2_splat(i64 x)
{
    i64x2 r;
    int i;
    for (i = 0; i < 2; i++)
        r[i] = x;
    return r;
}
static inline __attribute__((__always_inline__)) u8x16
u8x16_splat(u8 x)
{
    u8x16 r;
    int i;
    for (i = 0; i < 16; i++)
        r[i] = x;
    return r;
}
static inline __attribute__((__always_inline__)) u16x8
u16x8_splat(u16 x)
{
    u16x8 r;
    int i;
    for (i = 0; i < 8; i++)
        r[i] = x;
    return r;
}
static inline __attribute__((__always_inline__)) u32x4
u32x4_splat(u32 x)
{
    u32x4 r;
    int i;
    for (i = 0; i < 4; i++)
        r[i] = x;
    return r;
}
static inline __attribute__((__always_inline__)) u64x2
u64x2_splat(u64 x)
{
    u64x2 r;
    int i;
    for (i = 0; i < 2; i++)
        r[i] = x;
    return r;
}
extern void *memcpy(void *__restrict __dest, const void *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern void *memmove(void *__dest, const void *__src, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern void *memccpy(void *__restrict __dest, const void *__restrict __src, int __c, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern void *memset(void *__s, int __c, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int memcmp(const void *__s1, const void *__s2, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern void *memchr(const void *__s, int __c, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern char *strcpy(char *__restrict __dest, const char *__restrict __src) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern char *strncpy(char *__restrict __dest, const char *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char *strcat(char *__restrict __dest, const char *__restrict __src) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern char *strncat(char *__restrict __dest, const char *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int strcmp(const char *__s1, const char *__s2) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
__attribute__((__nonnull__(1, 2)));
extern int strncmp(const char *__s1, const char *__s2, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern int strcoll(const char *__s1, const char *__s2) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
__attribute__((__nonnull__(1, 2)));
extern size_t strxfrm(char *__restrict __dest, const char *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
struct __locale_struct {
    struct __locale_data *__locales[13];
    const unsigned short int *__ctype_b;
    const int *__ctype_tolower;
    const int *__ctype_toupper;
    const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
extern int strcoll_l(const char *__s1, const char *__s2, locale_t __l) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1, 2, 3)));
extern size_t strxfrm_l(char *__dest, const char *__src, size_t __n, locale_t __l)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 4)));
extern char *strdup(const char *__s) __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__))
__attribute__((__nonnull__(1)));
extern char *strndup(const char *__string, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__nonnull__(1)));
extern char *strchr(const char *__s, int __c) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
__attribute__((__nonnull__(1)));
extern char *strrchr(const char *__s, int __c) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
__attribute__((__nonnull__(1)));
extern size_t strcspn(const char *__s, const char *__reject) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern size_t strspn(const char *__s, const char *__accept) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern char *strpbrk(const char *__s, const char *__accept) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern char *strstr(const char *__haystack, const char *__needle) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern char *strtok(char *__restrict __s, const char *__restrict __delim) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern char *__strtok_r(char *__restrict __s, const char *__restrict __delim, char **__restrict __save_ptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern char *strtok_r(char *__restrict __s, const char *__restrict __delim, char **__restrict __save_ptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern size_t strlen(const char *__s) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
__attribute__((__nonnull__(1)));
extern size_t strnlen(const char *__string, size_t __maxlen) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern char *strerror(int __errnum) __attribute__((__nothrow__, __leaf__));
extern int strerror_r(int __errnum, char *__buf, size_t __buflen) __asm__(""
                                                                          "__xpg_strerror_r")
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern char *strerror_l(int __errnum, locale_t __l) __attribute__((__nothrow__, __leaf__));
extern int bcmp(const void *__s1, const void *__s2, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern void bcopy(const void *__src, void *__dest, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern void bzero(void *__s, size_t __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern char *index(const char *__s, int __c) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
__attribute__((__nonnull__(1)));
extern char *rindex(const char *__s, int __c) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
__attribute__((__nonnull__(1)));
extern int ffs(int __i) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int ffsl(long int __l) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
__extension__ extern int ffsll(long long int __ll) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int strcasecmp(const char *__s1, const char *__s2) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern int strncasecmp(const char *__s1, const char *__s2, size_t __n) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1, 2)));
extern int strcasecmp_l(const char *__s1, const char *__s2, locale_t __loc) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1, 2, 3)));
extern int strncasecmp_l(const char *__s1, const char *__s2, size_t __n, locale_t __loc)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__)) __attribute__((__nonnull__(1, 2, 4)));
extern void explicit_bzero(void *__s, size_t __n) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern char *strsep(char **__restrict __stringp, const char *__restrict __delim) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern char *strsignal(int __sig) __attribute__((__nothrow__, __leaf__));
extern char *__stpcpy(char *__restrict __dest, const char *__restrict __src) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern char *stpcpy(char *__restrict __dest, const char *__restrict __src) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern char *__stpncpy(char *__restrict __dest, const char *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern char *stpncpy(char *__restrict __dest, const char *__restrict __src, size_t __n)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
void clib_memswap(void *_a, void *_b, uword bytes);
static inline __attribute__((__always_inline__)) void
clib_memcpy64_x4(void *d0, void *d1, void *d2, void *d3, void *s)
{
    memcpy(d0, s, 64);
    memcpy(d1, s, 64);
    memcpy(d2, s, 64);
    memcpy(d3, s, 64);
}
static inline __attribute__((__always_inline__)) void
clib_memset_u64(void *p, u64 val, uword count)
{
    u64 *ptr = p;
    while (count >= 4) {
        ptr[0] = ptr[1] = ptr[2] = ptr[3] = val;
        ptr += 4;
        count -= 4;
    }
    while (count--)
        ptr++ [0] = val;
}
static inline __attribute__((__always_inline__)) void
clib_memset_u32(void *p, u32 val, uword count)
{
    u32 *ptr = p;
    while (count >= 4) {
        ptr[0] = ptr[1] = ptr[2] = ptr[3] = val;
        ptr += 4;
        count -= 4;
    }
    while (count--)
        ptr++ [0] = val;
}
static inline __attribute__((__always_inline__)) void
clib_memset_u16(void *p, u16 val, uword count)
{
    u16 *ptr = p;
    while (count >= 4) {
        ptr[0] = ptr[1] = ptr[2] = ptr[3] = val;
        ptr += 4;
        count -= 4;
    }
    while (count--)
        ptr++ [0] = val;
}
static inline __attribute__((__always_inline__)) void
clib_memset_u8(void *p, u8 val, uword count)
{
    u8 *ptr = p;
    while (count >= 4) {
        ptr[0] = ptr[1] = ptr[2] = ptr[3] = val;
        ptr += 4;
        count -= 4;
    }
    while (count--)
        ptr++ [0] = val;
}
static inline __attribute__((__always_inline__)) uword
clib_count_equal_u64(u64 *data, uword max_count)
{
    uword count;
    u64 first;
    if (max_count == 1)
        return 1;
    if (data[0] != data[1])
        return 1;
    count = 0;
    first = data[0];
    count += 2;
    data += 2;
    while (count + 3 < max_count && ((data[0] ^ first) | (data[1] ^ first) | (data[2] ^ first) | (data[3] ^ first)) == 0) {
        data += 4;
        count += 4;
    }
    while (count < max_count && (data[0] == first)) {
        data += 1;
        count += 1;
    }
    return count;
}
static inline __attribute__((__always_inline__)) uword
clib_count_equal_u32(u32 *data, uword max_count)
{
    uword count;
    u32 first;
    if (max_count == 1)
        return 1;
    if (data[0] != data[1])
        return 1;
    count = 0;
    first = data[0];
    count += 2;
    data += 2;
    while (count + 3 < max_count && ((data[0] ^ first) | (data[1] ^ first) | (data[2] ^ first) | (data[3] ^ first)) == 0) {
        data += 4;
        count += 4;
    }
    while (count < max_count && (data[0] == first)) {
        data += 1;
        count += 1;
    }
    return count;
}
static inline __attribute__((__always_inline__)) uword
clib_count_equal_u16(u16 *data, uword max_count)
{
    uword count;
    u16 first;
    if (max_count == 1)
        return 1;
    if (data[0] != data[1])
        return 1;
    count = 0;
    first = data[0];
    count += 2;
    data += 2;
    while (count + 3 < max_count && ((data[0] ^ first) | (data[1] ^ first) | (data[2] ^ first) | (data[3] ^ first)) == 0) {
        data += 4;
        count += 4;
    }
    while (count < max_count && (data[0] == first)) {
        data += 1;
        count += 1;
    }
    return count;
}
static inline __attribute__((__always_inline__)) uword
clib_count_equal_u8(u8 *data, uword max_count)
{
    uword count;
    u8 first;
    if (max_count == 1)
        return 1;
    if (data[0] != data[1])
        return 1;
    count = 0;
    first = data[0];
    count += 2;
    data += 2;
    while (count + 3 < max_count && ((data[0] ^ first) | (data[1] ^ first) | (data[2] ^ first) | (data[3] ^ first)) == 0) {
        data += 4;
        count += 4;
    }
    while (count < max_count && (data[0] == first)) {
        data += 1;
        count += 1;
    }
    return count;
}
typedef struct {
    unsigned long long int nraddr;
} OrigFn;
typedef enum {
    VG_USERREQ__RUNNING_ON_VALGRIND  = 0x1001,
    VG_USERREQ__DISCARD_TRANSLATIONS = 0x1002,
    VG_USERREQ__CLIENT_CALL0         = 0x1101,
    VG_USERREQ__CLIENT_CALL1         = 0x1102,
    VG_USERREQ__CLIENT_CALL2         = 0x1103,
    VG_USERREQ__CLIENT_CALL3         = 0x1104,
    VG_USERREQ__COUNT_ERRORS         = 0x1201,
    VG_USERREQ__MALLOCLIKE_BLOCK     = 0x1301,
    VG_USERREQ__FREELIKE_BLOCK       = 0x1302,
    VG_USERREQ__CREATE_MEMPOOL       = 0x1303,
    VG_USERREQ__DESTROY_MEMPOOL      = 0x1304,
    VG_USERREQ__MEMPOOL_ALLOC        = 0x1305,
    VG_USERREQ__MEMPOOL_FREE         = 0x1306,
    VG_USERREQ__MEMPOOL_TRIM         = 0x1307,
    VG_USERREQ__MOVE_MEMPOOL         = 0x1308,
    VG_USERREQ__MEMPOOL_CHANGE       = 0x1309,
    VG_USERREQ__MEMPOOL_EXISTS       = 0x130a,
    VG_USERREQ__PRINTF               = 0x1401,
    VG_USERREQ__PRINTF_BACKTRACE     = 0x1402,
    VG_USERREQ__STACK_REGISTER       = 0x1501,
    VG_USERREQ__STACK_DEREGISTER     = 0x1502,
    VG_USERREQ__STACK_CHANGE         = 0x1503,
    VG_USERREQ__LOAD_PDB_DEBUGINFO   = 0x1601
} Vg_ClientRequest;
static int VALGRIND_PRINTF(const char *format, ...) __attribute__((format(__printf__, 1, 2), __unused__));
static int
VALGRIND_PRINTF(const char *format, ...)
{
    unsigned long _qzz_res;
    va_list vargs;

    __builtin_va_start(vargs, format);
    {
        volatile unsigned long long int _zzq_args[6];
        volatile unsigned long long int _zzq_result;
        _zzq_args[0] = (unsigned long long int) (VG_USERREQ__PRINTF);
        _zzq_args[1] = (unsigned long long int) ((unsigned long) format);
        _zzq_args[2] = (unsigned long long int) ((unsigned long) vargs);
        _zzq_args[3] = (unsigned long long int) (0);
        _zzq_args[4] = (unsigned long long int) (0);
        _zzq_args[5] = (unsigned long long int) (0);
        __asm__ volatile("rolq $3,  %%rdi ; rolq $13, %%rdi\n\t"
                         "rolq $61, %%rdi ; rolq $51, %%rdi\n\t"
                         "xchgq %%rbx,%%rbx"
                         : "=d"(_zzq_result)
                         : "a"(&_zzq_args[0]), "0"(0)
                         : "cc", "memory");
        _qzz_res = _zzq_result;
    };

    __builtin_va_end(vargs);
    return (int) _qzz_res;
}
static int VALGRIND_PRINTF_BACKTRACE(const char *format, ...) __attribute__((format(__printf__, 1, 2), __unused__));
static int
VALGRIND_PRINTF_BACKTRACE(const char *format, ...)
{
    unsigned long _qzz_res;
    va_list vargs;

    __builtin_va_start(vargs, format);
    {
        volatile unsigned long long int _zzq_args[6];
        volatile unsigned long long int _zzq_result;
        _zzq_args[0] = (unsigned long long int) (VG_USERREQ__PRINTF_BACKTRACE);
        _zzq_args[1] = (unsigned long long int) ((unsigned long) format);
        _zzq_args[2] = (unsigned long long int) ((unsigned long) vargs);
        _zzq_args[3] = (unsigned long long int) (0);
        _zzq_args[4] = (unsigned long long int) (0);
        _zzq_args[5] = (unsigned long long int) (0);
        __asm__ volatile("rolq $3,  %%rdi ; rolq $13, %%rdi\n\t"
                         "rolq $61, %%rdi ; rolq $51, %%rdi\n\t"
                         "xchgq %%rbx,%%rbx"
                         : "=d"(_zzq_result)
                         : "a"(&_zzq_args[0]), "0"(0)
                         : "cc", "memory");
        _qzz_res = _zzq_result;
    };

    __builtin_va_end(vargs);
    return (int) _qzz_res;
}
extern void *clib_per_cpu_mheaps[256];
static inline __attribute__((__always_inline__)) void *
clib_mem_get_per_cpu_heap(void)
{
    int cpu = os_get_thread_index();
    return clib_per_cpu_mheaps[cpu];
}
static inline __attribute__((__always_inline__)) void *
clib_mem_set_per_cpu_heap(u8 *new_heap)
{
    int cpu                  = os_get_thread_index();
    void *old                = clib_per_cpu_mheaps[cpu];
    clib_per_cpu_mheaps[cpu] = new_heap;
    return old;
}
static inline __attribute__((__always_inline__)) void *
clib_mem_alloc_aligned_at_offset(uword size, uword align, uword align_offset, int os_out_of_memory_on_failure)
{
    void *heap, *p;
    uword cpu;
    if (align_offset > align) {
        if (align > 0)
            align_offset %= align;
        else
            align_offset = align;
    }
    cpu  = os_get_thread_index();
    heap = clib_per_cpu_mheaps[cpu];
    p    = mspace_get_aligned(heap, size, align, align_offset);
    if (__builtin_expect((p == 0), 0)) {
        if (os_out_of_memory_on_failure)
            os_out_of_memory();
        return 0;
    }
    return p;
}
static inline __attribute__((__always_inline__)) void *
clib_mem_alloc(uword size)
{
    return clib_mem_alloc_aligned_at_offset(size, 1, 0, 1);
}
static inline __attribute__((__always_inline__)) void *
clib_mem_alloc_aligned(uword size, uword align)
{
    return clib_mem_alloc_aligned_at_offset(size, align, 0, 1);
}
static inline __attribute__((__always_inline__)) void *
clib_mem_alloc_or_null(uword size)
{
    return clib_mem_alloc_aligned_at_offset(size, 1, 0, 0);
}
static inline __attribute__((__always_inline__)) void *
clib_mem_alloc_aligned_or_null(uword size, uword align)
{
    return clib_mem_alloc_aligned_at_offset(size, align, 0, 0);
}
static inline __attribute__((__always_inline__)) uword
clib_mem_is_heap_object(void *p)
{
    void *heap = clib_mem_get_per_cpu_heap();
    return mspace_is_heap_object(heap, p);
}
static inline __attribute__((__always_inline__)) void
clib_mem_free(void *p)
{
    u8 *heap = clib_mem_get_per_cpu_heap();
    do {
        if ((0 > 0) && !(clib_mem_is_heap_object(p))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/mem.h", (uword) 210,
                        ((char *) __FUNCTION__), "clib_mem_is_heap_object (p)");
        }
    } while (0);
    mspace_put(heap, p);
}
static inline __attribute__((__always_inline__)) void *
clib_mem_realloc(void *p, uword new_size, uword old_size)
{
    void *q = clib_mem_alloc(new_size);
    if (q) {
        uword copy_size;
        if (old_size < new_size)
            copy_size = old_size;
        else
            copy_size = new_size;
        memcpy(q, p, copy_size);
        clib_mem_free(p);
    }
    return q;
}
static inline __attribute__((__always_inline__)) uword
clib_mem_size(void *p)
{
    do {
        if ((0 > 0) && !(clib_mem_is_heap_object(p))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/mem.h", (uword) 249,
                        ((char *) __FUNCTION__), "clib_mem_is_heap_object (p)");
        }
    } while (0);
    return mspace_usable_size_with_delta(p);
}
static inline __attribute__((__always_inline__)) void *
clib_mem_get_heap(void)
{
    return clib_mem_get_per_cpu_heap();
}
static inline __attribute__((__always_inline__)) void *
clib_mem_set_heap(void *heap)
{
    return clib_mem_set_per_cpu_heap(heap);
}
void *clib_mem_init(void *heap, uword size);
void *clib_mem_init_thread_safe(void *memory, uword memory_size);
void clib_mem_exit(void);
uword clib_mem_get_page_size(void);
void clib_mem_validate(void);
void clib_mem_trace(int enable);
typedef struct {
    uword object_count;
    uword bytes_total, bytes_used, bytes_free;
    uword bytes_overhead;
    uword bytes_free_reclaimed;
    uword bytes_used_sbrk;
    uword bytes_used_mmap;
    uword bytes_max;
} clib_mem_usage_t;
void clib_mem_usage(clib_mem_usage_t *usage);
u8 *format_clib_mem_usage(u8 *s, va_list *args);
static inline __attribute__((__always_inline__)) void *
clib_mem_vm_alloc(uword size)
{
    void *mmap_addr;
    uword flags = 0x02;
    flags |= 0x20;
    mmap_addr = mmap(0, size, 0x1 | 0x2, flags, -1, 0);
    if (mmap_addr == (void *) -1)
        mmap_addr = 0;
    return mmap_addr;
}
static inline __attribute__((__always_inline__)) void
clib_mem_vm_free(void *addr, uword size)
{
    munmap(addr, size);
}
static inline __attribute__((__always_inline__)) void *
clib_mem_vm_unmap(void *addr, uword size)
{
    void *mmap_addr;
    uword flags = 0x02 | 0x10;
    mmap_addr   = mmap(addr, size, 0x0, flags, -1, 0);
    if (mmap_addr == (void *) -1)
        mmap_addr = 0;
    return mmap_addr;
}
static inline __attribute__((__always_inline__)) void *
clib_mem_vm_map(void *addr, uword size)
{
    void *mmap_addr;
    uword flags = 0x02 | 0x10 | 0x20;
    mmap_addr   = mmap(addr, size, (0x1 | 0x2), flags, -1, 0);
    if (mmap_addr == (void *) -1)
        mmap_addr = 0;
    return mmap_addr;
}
typedef struct {
    u32 flags;
    char *name;
    uword size;
    int numa_node;
    void *addr;
    int fd;
    int log2_page_size;
    int n_pages;
    uword requested_va;
} clib_mem_vm_alloc_t;
clib_error_t *clib_mem_vm_ext_alloc(clib_mem_vm_alloc_t *a);
u64 clib_mem_vm_get_page_size(int fd);
int clib_mem_vm_get_log2_page_size(int fd);
u64 *clib_mem_vm_get_paddr(void *mem, int log2_page_size, int n_pages);
typedef struct {
    uword size;
    int fd;
    uword requested_va;
    void *addr;
} clib_mem_vm_map_t;
clib_error_t *clib_mem_vm_ext_map(clib_mem_vm_map_t *a);
void clib_mem_vm_randomize_va(uword *requested_va, u32 log2_page_size);
void mheap_trace(void *v, int enable);
extern int *__errno_location(void) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
typedef void clib_error_handler_func_t(void *arg, u8 *msg, int msg_len);
void clib_error_register_handler(clib_error_handler_func_t func, void *arg);
extern void *clib_error_free_vector(clib_error_t *errors);
extern clib_error_t *_clib_error_return(clib_error_t *errors, any code, uword flags, char *where, char *fmt, ...);
extern clib_error_t *_clib_error_report(clib_error_t *errors);
u8 *format_clib_error(u8 *s, va_list *va);
static inline __attribute__((__always_inline__)) word
unix_error_is_fatal(word error)
{
    switch (error) {
    case 11:
    case 4:
        return 0;
    }
    return 1;
}
typedef struct {
    u32 len;
    u32 dlmalloc_header_offset;
    u8 vector_data[0];
} vec_header_t;
static inline __attribute__((__always_inline__)) uword
vec_header_bytes(uword header_bytes)
{
    return round_pow2(header_bytes + sizeof(vec_header_t), sizeof(vec_header_t));
}
static inline __attribute__((__always_inline__)) void *
vec_header(void *v, uword header_bytes)
{
    return v - vec_header_bytes(header_bytes);
}
static inline __attribute__((__always_inline__)) void *
vec_header_end(void *v, uword header_bytes)
{
    return v + vec_header_bytes(header_bytes);
}
static inline __attribute__((__always_inline__)) uword
vec_aligned_header_bytes(uword header_bytes, uword align)
{
    return round_pow2(header_bytes + sizeof(vec_header_t), align);
}
static inline __attribute__((__always_inline__)) void *
vec_aligned_header(void *v, uword header_bytes, uword align)
{
    return v - vec_aligned_header_bytes(header_bytes, align);
}
static inline __attribute__((__always_inline__)) void *
vec_aligned_header_end(void *v, uword header_bytes, uword align)
{
    return v + vec_aligned_header_bytes(header_bytes, align);
}
void *vec_resize_allocate_memory(void *v, word length_increment, uword data_bytes, uword header_bytes, uword data_align);
static inline __attribute__((__always_inline__)) void *
_vec_resize_inline(void *v, word length_increment, uword data_bytes, uword header_bytes, uword data_align)
{
    vec_header_t *vh = ((vec_header_t *) (v) -1);
    uword new_data_bytes, aligned_header_bytes;
    aligned_header_bytes = vec_header_bytes(header_bytes);
    new_data_bytes       = data_bytes + aligned_header_bytes;
    if (__builtin_expect((v != 0), 1)) {
        void *p = v - aligned_header_bytes;
        do {
            if ((0 > 0) && !(clib_mem_is_heap_object(p))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/vec.h", (uword) 134,
                            ((char *) __FUNCTION__), "clib_mem_is_heap_object (p)");
            }
        } while (0);
        if (new_data_bytes <= clib_mem_size(p)) {
            vh->len += length_increment;
            return v;
        }
    }
    return vec_resize_allocate_memory(v, length_increment, data_bytes, header_bytes, ({
                                          __typeof__(sizeof(vec_header_t)) _x = (sizeof(vec_header_t));
                                          __typeof__(data_align) _y           = (data_align);
                                          _x > _y ? _x : _y;
                                      }));
}
static inline __attribute__((__always_inline__)) int
_vec_resize_will_expand(void *v, word length_increment, uword data_bytes, uword header_bytes, uword data_align)
{
    uword new_data_bytes, aligned_header_bytes;
    aligned_header_bytes = vec_header_bytes(header_bytes);
    new_data_bytes       = data_bytes + aligned_header_bytes;
    if (__builtin_expect((v != 0), 1)) {
        void *p = v - aligned_header_bytes;
        do {
            if ((0 > 0) && !(clib_mem_is_heap_object(p))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/vec.h", (uword) 178,
                            ((char *) __FUNCTION__), "clib_mem_is_heap_object (p)");
            }
        } while (0);
        if (new_data_bytes <= clib_mem_size(p))
            return 0;
    }
    return 1;
}
uword clib_mem_is_vec_h(void *v, uword header_bytes);
static inline __attribute__((__always_inline__)) uword
clib_mem_is_vec(void *v)
{
    return clib_mem_is_vec_h(v, 0);
}
typedef int wchar_t;
typedef enum { P_ALL, P_PID, P_PGID } idtype_t;
typedef struct {
    int quot;
    int rem;
} div_t;
typedef struct {
    long int quot;
    long int rem;
} ldiv_t;
__extension__ typedef struct {
    long long int quot;
    long long int rem;
} lldiv_t;
extern size_t __ctype_get_mb_cur_max(void) __attribute__((__nothrow__, __leaf__));
extern double atof(const char *__nptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
__attribute__((__nonnull__(1)));
extern int atoi(const char *__nptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
__attribute__((__nonnull__(1)));
extern long int atol(const char *__nptr) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
__attribute__((__nonnull__(1)));
__extension__ extern long long int atoll(const char *__nptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__pure__)) __attribute__((__nonnull__(1)));
extern double strtod(const char *__restrict __nptr, char **__restrict __endptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern float strtof(const char *__restrict __nptr, char **__restrict __endptr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern long double strtold(const char *__restrict __nptr, char **__restrict __endptr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern long int strtol(const char *__restrict __nptr, char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern unsigned long int strtoul(const char *__restrict __nptr, char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern long long int strtoq(const char *__restrict __nptr, char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern unsigned long long int strtouq(const char *__restrict __nptr, char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern long long int strtoll(const char *__restrict __nptr, char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
__extension__ extern unsigned long long int strtoull(const char *__restrict __nptr, char **__restrict __endptr, int __base)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern char *l64a(long int __n) __attribute__((__nothrow__, __leaf__));
extern long int a64l(const char *__s) __attribute__((__nothrow__, __leaf__)) __attribute__((__pure__))
__attribute__((__nonnull__(1)));
extern long int random(void) __attribute__((__nothrow__, __leaf__));
extern void srandom(unsigned int __seed) __attribute__((__nothrow__, __leaf__));
extern char *initstate(unsigned int __seed, char *__statebuf, size_t __statelen) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern char *setstate(char *__statebuf) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
struct random_data {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
};
extern int random_r(struct random_data *__restrict __buf, int32_t *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int srandom_r(unsigned int __seed, struct random_data *__buf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern int initstate_r(unsigned int __seed, char *__restrict __statebuf, size_t __statelen,
                       struct random_data *__restrict __buf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 4)));
extern int setstate_r(char *__restrict __statebuf, struct random_data *__restrict __buf)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int rand(void) __attribute__((__nothrow__, __leaf__));
extern void srand(unsigned int __seed) __attribute__((__nothrow__, __leaf__));
extern int rand_r(unsigned int *__seed) __attribute__((__nothrow__, __leaf__));
extern double drand48(void) __attribute__((__nothrow__, __leaf__));
extern double erand48(unsigned short int __xsubi[3]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern long int lrand48(void) __attribute__((__nothrow__, __leaf__));
extern long int nrand48(unsigned short int __xsubi[3]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern long int mrand48(void) __attribute__((__nothrow__, __leaf__));
extern long int jrand48(unsigned short int __xsubi[3]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern void srand48(long int __seedval) __attribute__((__nothrow__, __leaf__));
extern unsigned short int *seed48(unsigned short int __seed16v[3]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern void lcong48(unsigned short int __param[7]) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
struct drand48_data {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;
};
extern int drand48_r(struct drand48_data *__restrict __buffer, double *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int erand48_r(unsigned short int __xsubi[3], struct drand48_data *__restrict __buffer, double *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int lrand48_r(struct drand48_data *__restrict __buffer, long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int nrand48_r(unsigned short int __xsubi[3], struct drand48_data *__restrict __buffer,
                     long int *__restrict __result) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int mrand48_r(struct drand48_data *__restrict __buffer, long int *__restrict __result)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int jrand48_r(unsigned short int __xsubi[3], struct drand48_data *__restrict __buffer,
                     long int *__restrict __result) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int srand48_r(long int __seedval, struct drand48_data *__buffer) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern int seed48_r(unsigned short int __seed16v[3], struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int lcong48_r(unsigned short int __param[7], struct drand48_data *__buffer)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern void *malloc(size_t __size) __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__));
extern void *calloc(size_t __nmemb, size_t __size) __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__));
extern void *realloc(void *__ptr, size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__warn_unused_result__));
extern void free(void *__ptr) __attribute__((__nothrow__, __leaf__));
extern void *alloca(size_t __size) __attribute__((__nothrow__, __leaf__));
extern void *valloc(size_t __size) __attribute__((__nothrow__, __leaf__)) __attribute__((__malloc__));
extern int posix_memalign(void **__memptr, size_t __alignment, size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern void *aligned_alloc(size_t __alignment, size_t __size) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__)) __attribute__((__alloc_size__(2)));
extern void abort(void) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern int atexit(void (*__func)(void)) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int at_quick_exit(void (*__func)(void)) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int on_exit(void (*__func)(int __status, void *__arg), void *__arg) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern void exit(int __status) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void quick_exit(int __status) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern void _Exit(int __status) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
extern char *getenv(const char *__name) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int putenv(char *__string) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int setenv(const char *__name, const char *__value, int __replace) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern int unsetenv(const char *__name) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int clearenv(void) __attribute__((__nothrow__, __leaf__));
extern char *mktemp(char *__template) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int mkstemp(char *__template) __attribute__((__nonnull__(1)));
extern int mkstemps(char *__template, int __suffixlen) __attribute__((__nonnull__(1)));
extern char *mkdtemp(char *__template) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int system(const char *__command);
extern char *realpath(const char *__restrict __name, char *__restrict __resolved) __attribute__((__nothrow__, __leaf__));
typedef int (*__compar_fn_t)(const void *, const void *);
extern void *bsearch(const void *__key, const void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar)
    __attribute__((__nonnull__(1, 2, 5)));
extern void qsort(void *__base, size_t __nmemb, size_t __size, __compar_fn_t __compar) __attribute__((__nonnull__(1, 4)));
extern int abs(int __x) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern long int labs(long int __x) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
__extension__ extern long long int llabs(long long int __x) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern div_t div(int __numer, int __denom) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern ldiv_t ldiv(long int __numer, long int __denom) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
__extension__ extern lldiv_t lldiv(long long int __numer, long long int __denom) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern char *ecvt(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)));
extern char *fcvt(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)));
extern char *gcvt(double __value, int __ndigit, char *__buf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3)));
extern char *qecvt(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)));
extern char *qfcvt(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)));
extern char *qgcvt(long double __value, int __ndigit, char *__buf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3)));
extern int ecvt_r(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf,
                  size_t __len) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4, 5)));
extern int fcvt_r(double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign, char *__restrict __buf,
                  size_t __len) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4, 5)));
extern int qecvt_r(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign,
                   char *__restrict __buf, size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4, 5)));
extern int qfcvt_r(long double __value, int __ndigit, int *__restrict __decpt, int *__restrict __sign,
                   char *__restrict __buf, size_t __len) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3, 4, 5)));
extern int mblen(const char *__s, size_t __n) __attribute__((__nothrow__, __leaf__));
extern int mbtowc(wchar_t *__restrict __pwc, const char *__restrict __s, size_t __n)
    __attribute__((__nothrow__, __leaf__));
extern int wctomb(char *__s, wchar_t __wchar) __attribute__((__nothrow__, __leaf__));
extern size_t mbstowcs(wchar_t *__restrict __pwcs, const char *__restrict __s, size_t __n)
    __attribute__((__nothrow__, __leaf__));
extern size_t wcstombs(char *__restrict __s, const wchar_t *__restrict __pwcs, size_t __n)
    __attribute__((__nothrow__, __leaf__));
extern int rpmatch(const char *__response) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int getsubopt(char **__restrict __optionp, char *const *__restrict __tokens, char **__restrict __valuep)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2, 3)));
extern int getloadavg(double __loadavg[], int __nelem) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
typedef u8 *(format_function_t)(u8 *s, va_list *args);
u8 *va_format(u8 *s, const char *format, va_list *args);
u8 *format(u8 *s, const char *format, ...);
struct _IO_FILE;
typedef struct _IO_FILE __FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef struct {
    int __count;
    union {
        unsigned int __wch;
        char __wchb[4];
    } __value;
} __mbstate_t;
typedef struct {
    __off_t __pos;
    __mbstate_t __state;
} _G_fpos_t;
typedef struct {
    __off64_t __pos;
    __mbstate_t __state;
} _G_fpos64_t;
struct _IO_jump_t;
struct _IO_FILE;
typedef void _IO_lock_t;
struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_FILE *_sbuf;
    int _pos;
};
enum __codecvt_result { __codecvt_ok, __codecvt_partial, __codecvt_error, __codecvt_noconv };
struct _IO_FILE {
    int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;
    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;
    struct _IO_marker *_markers;
    struct _IO_FILE *_chain;
    int _fileno;
    int _flags2;
    __off_t _old_offset;
    unsigned short _cur_column;
    signed char _vtable_offset;
    char _shortbuf[1];
    _IO_lock_t *_lock;
    __off64_t _offset;
    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    size_t __pad5;
    int _mode;
    char _unused2[15 * sizeof(int) - 4 * sizeof(void *) - sizeof(size_t)];
};
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
typedef __ssize_t __io_read_fn(void *__cookie, char *__buf, size_t __nbytes);
typedef __ssize_t __io_write_fn(void *__cookie, const char *__buf, size_t __n);
typedef int __io_seek_fn(void *__cookie, __off64_t *__pos, int __w);
typedef int __io_close_fn(void *__cookie);
extern int __underflow(_IO_FILE *);
extern int __uflow(_IO_FILE *);
extern int __overflow(_IO_FILE *, int);
extern int _IO_getc(_IO_FILE *__fp);
extern int _IO_putc(int __c, _IO_FILE *__fp);
extern int _IO_feof(_IO_FILE *__fp) __attribute__((__nothrow__, __leaf__));
extern int _IO_ferror(_IO_FILE *__fp) __attribute__((__nothrow__, __leaf__));
extern int _IO_peekc_locked(_IO_FILE *__fp);
extern void _IO_flockfile(_IO_FILE *) __attribute__((__nothrow__, __leaf__));
extern void _IO_funlockfile(_IO_FILE *) __attribute__((__nothrow__, __leaf__));
extern int _IO_ftrylockfile(_IO_FILE *) __attribute__((__nothrow__, __leaf__));
extern int _IO_vfscanf(_IO_FILE *__restrict, const char *__restrict, __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf(_IO_FILE *__restrict, const char *__restrict, __gnuc_va_list);
extern __ssize_t _IO_padn(_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn(_IO_FILE *, void *, size_t);
extern __off64_t _IO_seekoff(_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos(_IO_FILE *, __off64_t, int);
extern void _IO_free_backup_area(_IO_FILE *) __attribute__((__nothrow__, __leaf__));
typedef _G_fpos_t fpos_t;
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern int remove(const char *__filename) __attribute__((__nothrow__, __leaf__));
extern int rename(const char *__old, const char *__new) __attribute__((__nothrow__, __leaf__));
extern int renameat(int __oldfd, const char *__old, int __newfd, const char *__new)
    __attribute__((__nothrow__, __leaf__));
extern FILE *tmpfile(void);
extern char *tmpnam(char *__s) __attribute__((__nothrow__, __leaf__));
extern char *tmpnam_r(char *__s) __attribute__((__nothrow__, __leaf__));
extern char *tempnam(const char *__dir, const char *__pfx) __attribute__((__nothrow__, __leaf__))
__attribute__((__malloc__));
extern int fclose(FILE *__stream);
extern int fflush(FILE *__stream);
extern int fflush_unlocked(FILE *__stream);
extern FILE *fopen(const char *__restrict __filename, const char *__restrict __modes);
extern FILE *freopen(const char *__restrict __filename, const char *__restrict __modes, FILE *__restrict __stream);
extern FILE *fdopen(int __fd, const char *__modes) __attribute__((__nothrow__, __leaf__));
extern FILE *fmemopen(void *__s, size_t __len, const char *__modes) __attribute__((__nothrow__, __leaf__));
extern FILE *open_memstream(char **__bufloc, size_t *__sizeloc) __attribute__((__nothrow__, __leaf__));
extern void setbuf(FILE *__restrict __stream, char *__restrict __buf) __attribute__((__nothrow__, __leaf__));
extern int setvbuf(FILE *__restrict __stream, char *__restrict __buf, int __modes, size_t __n)
    __attribute__((__nothrow__, __leaf__));
extern void setbuffer(FILE *__restrict __stream, char *__restrict __buf, size_t __size)
    __attribute__((__nothrow__, __leaf__));
extern void setlinebuf(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int fprintf(FILE *__restrict __stream, const char *__restrict __format, ...);
extern int printf(const char *__restrict __format, ...);
extern int sprintf(char *__restrict __s, const char *__restrict __format, ...) __attribute__((__nothrow__));
extern int vfprintf(FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg);
extern int vprintf(const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf(char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__nothrow__));
extern int snprintf(char *__restrict __s, size_t __maxlen, const char *__restrict __format, ...)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 4)));
extern int vsnprintf(char *__restrict __s, size_t __maxlen, const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__nothrow__)) __attribute__((__format__(__printf__, 3, 0)));
extern int vdprintf(int __fd, const char *__restrict __fmt, __gnuc_va_list __arg)
    __attribute__((__format__(__printf__, 2, 0)));
extern int dprintf(int __fd, const char *__restrict __fmt, ...) __attribute__((__format__(__printf__, 2, 3)));
extern int fscanf(FILE *__restrict __stream, const char *__restrict __format, ...);
extern int scanf(const char *__restrict __format, ...);
extern int sscanf(const char *__restrict __s, const char *__restrict __format, ...)
    __attribute__((__nothrow__, __leaf__));
extern int fscanf(FILE *__restrict __stream, const char *__restrict __format, ...) __asm__(""
                                                                                           "__isoc99_fscanf");
extern int scanf(const char *__restrict __format, ...) __asm__(""
                                                               "__isoc99_scanf");
extern int sscanf(const char *__restrict __s, const char *__restrict __format, ...) __asm__(""
                                                                                            "__isoc99_sscanf")
    __attribute__((__nothrow__, __leaf__));
extern int vfscanf(FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__format__(__scanf__, 2, 0)));
extern int vscanf(const char *__restrict __format, __gnuc_va_list __arg) __attribute__((__format__(__scanf__, 1, 0)));
extern int vsscanf(const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__format__(__scanf__, 2, 0)));
extern int vfscanf(FILE *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg) __asm__(""
                                                 "__isoc99_vfscanf") __attribute__((__format__(__scanf__, 2, 0)));
extern int vscanf(const char *__restrict __format, __gnuc_va_list __arg) __asm__(""
                                                                                 "__isoc99_vscanf")
    __attribute__((__format__(__scanf__, 1, 0)));
extern int vsscanf(const char *__restrict __s, const char *__restrict __format,
                   __gnuc_va_list __arg) __asm__(""
                                                 "__isoc99_vsscanf") __attribute__((__nothrow__, __leaf__))
__attribute__((__format__(__scanf__, 2, 0)));
extern int fgetc(FILE *__stream);
extern int getc(FILE *__stream);
extern int getchar(void);
extern int getc_unlocked(FILE *__stream);
extern int getchar_unlocked(void);
extern int fgetc_unlocked(FILE *__stream);
extern int fputc(int __c, FILE *__stream);
extern int putc(int __c, FILE *__stream);
extern int putchar(int __c);
extern int fputc_unlocked(int __c, FILE *__stream);
extern int putc_unlocked(int __c, FILE *__stream);
extern int putchar_unlocked(int __c);
extern int getw(FILE *__stream);
extern int putw(int __w, FILE *__stream);
extern char *fgets(char *__restrict __s, int __n, FILE *__restrict __stream);
extern __ssize_t __getdelim(char **__restrict __lineptr, size_t *__restrict __n, int __delimiter,
                            FILE *__restrict __stream);
extern __ssize_t getdelim(char **__restrict __lineptr, size_t *__restrict __n, int __delimiter,
                          FILE *__restrict __stream);
extern __ssize_t getline(char **__restrict __lineptr, size_t *__restrict __n, FILE *__restrict __stream);
extern int fputs(const char *__restrict __s, FILE *__restrict __stream);
extern int puts(const char *__s);
extern int ungetc(int __c, FILE *__stream);
extern size_t fread(void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream);
extern size_t fwrite(const void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __s);
extern size_t fread_unlocked(void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream);
extern size_t fwrite_unlocked(const void *__restrict __ptr, size_t __size, size_t __n, FILE *__restrict __stream);
extern int fseek(FILE *__stream, long int __off, int __whence);
extern long int ftell(FILE *__stream);
extern void rewind(FILE *__stream);
extern int fseeko(FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello(FILE *__stream);
extern int fgetpos(FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos(FILE *__stream, const fpos_t *__pos);
extern void clearerr(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int feof(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int ferror(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern void clearerr_unlocked(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int feof_unlocked(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int ferror_unlocked(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern void perror(const char *__s);
extern int sys_nerr;
extern const char *const sys_errlist[];
extern int fileno(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int fileno_unlocked(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern FILE *popen(const char *__command, const char *__modes);
extern int pclose(FILE *__stream);
extern char *ctermid(char *__s) __attribute__((__nothrow__, __leaf__));
extern void flockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern int ftrylockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));
extern void funlockfile(FILE *__stream) __attribute__((__nothrow__, __leaf__));
word va_fformat(FILE *f, char *fmt, va_list *va);
word fformat(FILE *f, char *fmt, ...);
word fdformat(int fd, char *fmt, ...);
static inline __attribute__((__always_inline__)) u32
format_get_indent(u8 *s)
{
    u32 indent = 0;
    u8 *nl;
    if (!s)
        return indent;
    nl = ((s) + ((s) ? (((vec_header_t *) (s) -1)->len) : 0)) - 1;
    while (nl >= s) {
        if (*nl-- == '\n')
            break;
        indent++;
    }
    return indent;
}
u8 *format_vec32(u8 *s, va_list *va);
u8 *format_vec_uword(u8 *s, va_list *va);
u8 *format_ascii_bytes(u8 *s, va_list *va);
u8 *format_hex_bytes(u8 *s, va_list *va);
u8 *format_white_space(u8 *s, va_list *va);
u8 *format_f64(u8 *s, va_list *va);
u8 *format_time_interval(u8 *s, va_list *va);
u8 *format_address_family(u8 *s, va_list *va);
u8 *format_unix_arphrd(u8 *s, va_list *va);
u8 *format_unix_interface_flags(u8 *s, va_list *va);
u8 *format_network_address(u8 *s, va_list *va);
u8 *format_network_protocol(u8 *s, va_list *va);
u8 *format_network_port(u8 *s, va_list *va);
u8 *format_sockaddr(u8 *s, va_list *va);
u8 *format_ip4_tos_byte(u8 *s, va_list *va);
u8 *format_ip4_packet(u8 *s, va_list *va);
u8 *format_icmp4_type_and_code(u8 *s, va_list *va);
u8 *format_ethernet_packet(u8 *s, va_list *va);
u8 *format_hostname(u8 *s, va_list *va);
u8 *format_timeval(u8 *s, va_list *va);
u8 *format_time_float(u8 *s, va_list *va);
u8 *format_signal(u8 *s, va_list *va);
u8 *format_ucontext_pc(u8 *s, va_list *va);
u8 *format_page_map(u8 *s, va_list *va);
typedef struct _unformat_input_t {
    u8 *buffer;
    uword index;
    uword *buffer_marks;
    uword (*fill_buffer)(struct _unformat_input_t *i);
    void *fill_buffer_arg;
} unformat_input_t;
static inline __attribute__((__always_inline__)) void
unformat_init(unformat_input_t *i, uword (*fill_buffer)(unformat_input_t *), void *fill_buffer_arg)
{
    memset(i, 0, sizeof(i[0]));
    i->fill_buffer     = fill_buffer;
    i->fill_buffer_arg = fill_buffer_arg;
}
static inline __attribute__((__always_inline__)) void
unformat_free(unformat_input_t *i)
{
    do {
        if (i->buffer) {
            clib_mem_free(vec_header((i->buffer), (0)));
            i->buffer = 0;
        }
    } while (0);
    do {
        if (i->buffer_marks) {
            clib_mem_free(vec_header((i->buffer_marks), (0)));
            i->buffer_marks = 0;
        }
    } while (0);
    memset(i, 0, sizeof(i[0]));
}
static inline __attribute__((__always_inline__)) uword
unformat_check_input(unformat_input_t *i)
{
    extern uword _unformat_fill_input(unformat_input_t * i);
    if (i->index >= ((i->buffer) ? (((vec_header_t *) (i->buffer) - 1)->len) : 0) && i->index != (~0))
        _unformat_fill_input(i);
    return i->index;
}
static inline __attribute__((__always_inline__)) uword
unformat_is_eof(unformat_input_t *input)
{
    return unformat_check_input(input) == (~0);
}
static inline __attribute__((__always_inline__)) uword
unformat_get_input(unformat_input_t *input)
{
    uword i = unformat_check_input(input);
    if (i < ((input->buffer) ? (((vec_header_t *) (input->buffer) - 1)->len) : 0)) {
        input->index = i + 1;
        i            = input->buffer[i];
    }
    return i;
}
static inline __attribute__((__always_inline__)) void
unformat_put_input(unformat_input_t *input)
{
    input->index -= 1;
}
static inline __attribute__((__always_inline__)) uword
unformat_peek_input(unformat_input_t *input)
{
    uword c = unformat_get_input(input);
    if (c != (~0))
        unformat_put_input(input);
    return c;
}
static inline __attribute__((__always_inline__)) void
unformat_skip_line(unformat_input_t *i)
{
    uword c;
    while ((c = unformat_get_input(i)) != (~0) && c != '\n')
        ;
}
uword unformat_skip_white_space(unformat_input_t *input);
typedef uword(unformat_function_t)(unformat_input_t *input, va_list *args);
uword unformat(unformat_input_t *i, const char *fmt, ...);
uword unformat_user(unformat_input_t *input, unformat_function_t *func, ...);
uword va_unformat(unformat_input_t *i, const char *fmt, va_list *args);
void unformat_init_command_line(unformat_input_t *input, char *argv[]);
void unformat_init_string(unformat_input_t *input, char *string, int string_len);
static inline __attribute__((__always_inline__)) void
unformat_init_cstring(unformat_input_t *input, char *string)
{
    unformat_init_string(input, string, strlen(string));
}
void unformat_init_vector(unformat_input_t *input, u8 *vector_string);
u8 *format_unformat_error(u8 *s, va_list *va);
u8 *format_unformat_input(u8 *s, va_list *va);
unformat_function_t unformat_input;
unformat_function_t unformat_line;
unformat_function_t unformat_line_input;
unformat_function_t unformat_token;
unformat_function_t unformat_hex_string;
unformat_function_t unformat_eof;
unformat_function_t unformat_memory_size;
u8 *format_memory_size(u8 *s, va_list *va);
u8 *format_c_identifier(u8 *s, va_list *va);
u8 *format_hexdump(u8 *s, va_list *va);
void unformat_init_clib_file(unformat_input_t *input, int file_descriptor);
uword unformat_init_unix_env(unformat_input_t *input, char *var);
unformat_function_t unformat_unix_gid;
int test_format_main(unformat_input_t *input);
int test_unformat_main(unformat_input_t *input);
int test_vec_main(unformat_input_t *input);
struct hash_header;
typedef uword(hash_key_sum_function_t)(struct hash_header *, uword key);
typedef uword(hash_key_equal_function_t)(struct hash_header *, uword key1, uword key2);
typedef struct hash_header {
    uword elts;
    u32 flags;
    u32 log2_pair_size;
    hash_key_sum_function_t *key_sum;
    hash_key_equal_function_t *key_equal;
    any user;
    format_function_t *format_pair;
    void *format_pair_arg;
    uword is_user[0];
} hash_t;
static inline __attribute__((__always_inline__)) uword
hash_header_bytes(void *v)
{
    hash_t *h;
    uword is_user_bytes =
        (sizeof(h->is_user[0]) * ((v) ? (((vec_header_t *) (v) -1)->len) : 0)) / (8 * sizeof(h->is_user[0]));
    return sizeof(h[0]) + is_user_bytes;
}
static inline __attribute__((__always_inline__)) hash_t *
hash_header(void *v)
{
    return vec_header(v, hash_header_bytes(v));
}
static inline __attribute__((__always_inline__)) uword
hash_elts(void *v)
{
    hash_t *h = hash_header(v);
    return v ? h->elts : 0;
}
static inline __attribute__((__always_inline__)) uword
hash_capacity(void *v)
{
    return ((v) ? (((vec_header_t *) (v) -1)->len) : 0);
}
static inline __attribute__((__always_inline__)) uword
hash_is_user(void *v, uword i)
{
    hash_t *h = hash_header(v);
    uword i0  = i / (8 * sizeof(h->is_user[0]));
    uword i1  = i % (8 * sizeof(h->is_user[0]));
    return (h->is_user[i0] & ((uword) 1 << i1)) != 0;
}
static inline __attribute__((__always_inline__)) void
hash_set_pair_format(void *v, format_function_t *format_pair, void *format_pair_arg)
{
    hash_t *h          = hash_header(v);
    h->format_pair     = format_pair;
    h->format_pair_arg = format_pair_arg;
}
static inline __attribute__((__always_inline__)) void
hash_set_flags(void *v, uword flags)
{
    hash_header(v)->flags |= flags;
}
typedef struct {
    uword key;
    uword value[0];
} hash_pair_t;
typedef struct {
    hash_pair_t *pairs;
    u8 pad[sizeof(uword) - sizeof(hash_pair_t *)];
    uword alloc_len;
} hash_pair_indirect_t;
typedef union {
    hash_pair_t direct;
    hash_pair_indirect_t indirect;
} hash_pair_union_t;
static inline __attribute__((__always_inline__)) uword
indirect_pair_get_log2_bytes(hash_pair_indirect_t *p)
{
    return p->alloc_len >> ((8 * sizeof(uword)) - (5));
}
static inline __attribute__((__always_inline__)) uword
indirect_pair_get_len(hash_pair_indirect_t *p)
{
    if (!p->pairs)
        return 0;
    else
        return p->alloc_len & (((uword) 1 << ((8 * sizeof(uword)) - (5))) - 1);
}
static inline __attribute__((__always_inline__)) void
indirect_pair_set(hash_pair_indirect_t *p, uword log2_alloc, uword len)
{
    do {
        if ((0 > 0) && !(len < ((uword) 1 << ((8 * sizeof(uword)) - (5))))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/hash.h", (uword) 215,
                        ((char *) __FUNCTION__), "len < ((uword) 1 << PAIR_BITS)");
        }
    } while (0);
    do {
        if ((0 > 0) && !(log2_alloc < ((uword) 1 << (5)))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/hash.h", (uword) 216,
                        ((char *) __FUNCTION__), "log2_alloc < ((uword) 1 << LOG2_ALLOC_BITS)");
        }
    } while (0);
    p->alloc_len = (log2_alloc << ((8 * sizeof(uword)) - (5))) | len;
}
uword *_hash_get(void *v, uword key);
hash_pair_t *_hash_get_pair(void *v, uword key);
void *_hash_unset(void *v, uword key, void *old_value);
void *_hash_set3(void *v, uword key, void *value, void *old_value);
void *hash_resize(void *old, uword new_size);
void *hash_dup(void *old);
uword hash_bytes(void *v);
static inline __attribute__((__always_inline__)) void
hash_set_mem_alloc(uword **h, void *key, uword v)
{
    size_t ksz = hash_header(*h)->user;
    void *copy = clib_mem_alloc(ksz);
    memcpy(copy, key, ksz);
    ({
        uword _v = (uword)((v));
        (*h)     = _hash_set3((*h), (uword)(pointer_to_uword(copy)), (void *) &_v, (0));
    });
}
static inline __attribute__((__always_inline__)) void
hash_unset_mem_free(uword **h, void *key)
{
    hash_pair_t *hp = _hash_get_pair((*h), pointer_to_uword(key));
    if (__builtin_expect((hp != ((void *) 0)), 1)) {
        key = ((void *) (clib_address_t)(hp->key));
        ((*h) = _hash_unset((*h), pointer_to_uword(key), 0));
        clib_mem_free(key);
    }
}
extern void *_hash_free(void *v);
clib_error_t *hash_validate(void *v);
static inline __attribute__((__always_inline__)) uword
hash_value_bytes(hash_t *h)
{
    hash_pair_t *p;
    return (sizeof(p->value[0]) << h->log2_pair_size) - sizeof(p->key);
}
static inline __attribute__((__always_inline__)) uword
hash_pair_log2_bytes(hash_t *h)
{
    uword log2_bytes = h->log2_pair_size;
    do {
        if ((0 > 0) && !((8 * sizeof(hash_pair_t)) == 32 || (8 * sizeof(hash_pair_t)) == 64)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/hash.h", (uword) 327,
                        ((char *) __FUNCTION__), "BITS (hash_pair_t) == 32 || BITS (hash_pair_t) == 64");
        }
    } while (0);
    if ((8 * sizeof(hash_pair_t)) == 32)
        log2_bytes += 2;
    else if ((8 * sizeof(hash_pair_t)) == 64)
        log2_bytes += 3;
    return log2_bytes;
}
static inline __attribute__((__always_inline__)) uword
hash_pair_bytes(hash_t *h)
{
    return (uword) 1 << hash_pair_log2_bytes(h);
}
static inline __attribute__((__always_inline__)) void *
hash_forward1(hash_t *h, void *v)
{
    return (u8 *) v + hash_pair_bytes(h);
}
static inline __attribute__((__always_inline__)) void *
hash_forward(hash_t *h, void *v, uword n)
{
    return (u8 *) v + ((n * sizeof(hash_pair_t)) << h->log2_pair_size);
}
typedef struct {
    uword i, j, f;
} hash_next_t;
hash_pair_t *hash_next(void *v, hash_next_t *hn);
void *_hash_create(uword elts, hash_t *h);
static inline __attribute__((__always_inline__)) void
hash_set_value_bytes(hash_t *h, uword value_bytes)
{
    hash_pair_t *p;
    h->log2_pair_size = max_log2((sizeof(p->key) + value_bytes + sizeof(p->key) - 1) / sizeof(p->key));
}
static inline __attribute__((__always_inline__)) uword
hash32_rotate_left(u32 x, u32 i)
{
    return (x << i) | (x >> ((8 * sizeof(i)) - i));
}
extern uword hash_memory(void *p, word n_bytes, uword state);
extern uword mem_key_sum(hash_t *h, uword key);
extern uword mem_key_equal(hash_t *h, uword key1, uword key2);
extern uword vec_key_sum(hash_t *h, uword key);
extern uword vec_key_equal(hash_t *h, uword key1, uword key2);
extern u8 *vec_key_format_pair(u8 *s, va_list *args);
extern uword string_key_sum(hash_t *h, uword key);
extern uword string_key_equal(hash_t *h, uword key1, uword key2);
extern u8 *string_key_format_pair(u8 *s, va_list *args);
u8 *format_hash(u8 *s, va_list *va);
unformat_function_t unformat_hash_vec_string;
unformat_function_t unformat_hash_string;
int test_hash_main(unformat_input_t *input);
typedef enum {
    ELF_CLASS_NONE,
    ELF_32BIT,
    ELF_64BIT,
    ELF_N_FILE_CLASS,
} elf_file_class_t;
typedef enum {
    ELF_ENCODING_NONE,
    ELF_TWOS_COMPLEMENT_LITTLE_ENDIAN,
    ELF_TWOS_COMPLEMENT_BIG_ENDIAN,
    ELF_N_DATA_ENCODING,
} elf_data_encoding_t;
typedef enum {
    ELF_SYSV         = 0,
    ELF_HPUX         = 1,
    ELF_NETBSD       = 2,
    ELF_LINUX        = 3,
    ELF_SOLARIS      = 6,
    ELF_AIX          = 7,
    ELF_IRIX         = 8,
    ELF_FREEBSD      = 9,
    ELF_COMPAQ_TRU64 = 10,
    ELF_MODESTO      = 11,
    ELF_OPENBSD      = 12,
    ELF_ARM          = 97,
    ELF_STANDALONE   = 255,
} elf_abi_t;
typedef enum {
    ELF_NONE             = 0,
    ELF_RELOC            = 1,
    ELF_EXEC             = 2,
    ELF_SHARED           = 3,
    ELF_CORE             = 4,
    ELF_OS_SPECIFIC_LO   = 0xfe00,
    ELF_OS_SPECIFIC_HI   = 0xfeff,
    ELF_ARCH_SPECIFIC_LO = 0xff00,
    ELF_ARCH_SPECIFIC_HI = 0xffff,
} elf_file_type_t;
typedef enum {
    ELF_ARCH_NONE        = 0,
    ELF_ARCH_M32         = 1,
    ELF_ARCH_SPARC       = 2,
    ELF_ARCH_386         = 3,
    ELF_ARCH_68K         = 4,
    ELF_ARCH_88K         = 5,
    ELF_ARCH_860         = 7,
    ELF_ARCH_MIPS        = 8,
    ELF_ARCH_S370        = 9,
    ELF_ARCH_MIPS_RS3_LE = 10,
    ELF_ARCH_PARISC      = 15,
    ELF_ARCH_VPP500      = 17,
    ELF_ARCH_SPARC32PLUS = 18,
    ELF_ARCH_960         = 19,
    ELF_ARCH_PPC         = 20,
    ELF_ARCH_PPC64       = 21,
    ELF_ARCH_S390        = 22,
    ELF_ARCH_V800        = 36,
    ELF_ARCH_FR20        = 37,
    ELF_ARCH_RH32        = 38,
    ELF_ARCH_RCE         = 39,
    ELF_ARCH_ARM         = 40,
    ELF_ARCH_FAKE_ALPHA  = 41,
    ELF_ARCH_SH          = 42,
    ELF_ARCH_SPARCV9     = 43,
    ELF_ARCH_TRICORE     = 44,
    ELF_ARCH_ARC         = 45,
    ELF_ARCH_H8_300      = 46,
    ELF_ARCH_H8_300H     = 47,
    ELF_ARCH_H8S         = 48,
    ELF_ARCH_H8_500      = 49,
    ELF_ARCH_IA_64       = 50,
    ELF_ARCH_MIPS_X      = 51,
    ELF_ARCH_COLDFIRE    = 52,
    ELF_ARCH_68HC12      = 53,
    ELF_ARCH_MMA         = 54,
    ELF_ARCH_PCP         = 55,
    ELF_ARCH_NCPU        = 56,
    ELF_ARCH_NDR1        = 57,
    ELF_ARCH_STARCORE    = 58,
    ELF_ARCH_ME16        = 59,
    ELF_ARCH_ST100       = 60,
    ELF_ARCH_TINYJ       = 61,
    ELF_ARCH_X86_64      = 62,
    ELF_ARCH_PDSP        = 63,
    ELF_ARCH_FX66        = 66,
    ELF_ARCH_ST9PLUS     = 67,
    ELF_ARCH_ST7         = 68,
    ELF_ARCH_68HC16      = 69,
    ELF_ARCH_68HC11      = 70,
    ELF_ARCH_68HC08      = 71,
    ELF_ARCH_68HC05      = 72,
    ELF_ARCH_SVX         = 73,
    ELF_ARCH_ST19        = 74,
    ELF_ARCH_VAX         = 75,
    ELF_ARCH_CRIS        = 76,
    ELF_ARCH_JAVELIN     = 77,
    ELF_ARCH_FIREPATH    = 78,
    ELF_ARCH_ZSP         = 79,
    ELF_ARCH_MMIX        = 80,
    ELF_ARCH_HUANY       = 81,
    ELF_ARCH_PRISM       = 82,
    ELF_ARCH_AVR         = 83,
    ELF_ARCH_FR30        = 84,
    ELF_ARCH_D10V        = 85,
    ELF_ARCH_D30V        = 86,
    ELF_ARCH_V850        = 87,
    ELF_ARCH_M32R        = 88,
    ELF_ARCH_MN10300     = 89,
    ELF_ARCH_MN10200     = 90,
    ELF_ARCH_PJ          = 91,
    ELF_ARCH_OPENRISC    = 92,
    ELF_ARCH_ARC_A5      = 93,
    ELF_ARCH_XTENSA      = 94,
    ELF_ARCH_ALPHA       = 0x9026,
} elf_architecture_t;
typedef struct {
    u8 magic[4];
    elf_file_class_t file_class : 8;
    elf_data_encoding_t data_encoding : 8;
    u8 file_version_ident;
    elf_abi_t abi : 8;
    u8 abi_version;
    u8 pad[7];
    elf_file_type_t file_type : 16;
    elf_architecture_t architecture : 16;
    u32 file_version;
} elf_first_header_t;
typedef struct {
    u32 entry_point;
    u32 segment_header_file_offset;
    u32 section_header_file_offset;
    u32 flags;
    u16 n_bytes_this_header;
    u16 segment_header_size;
    u16 segment_header_count;
    u16 section_header_size;
    u16 section_header_count;
    u16 section_header_string_table_index;
} elf32_file_header_t;
typedef struct {
    u64 entry_point;
    u64 segment_header_file_offset;
    u64 section_header_file_offset;
    u32 flags;
    u16 n_bytes_this_header;
    u16 segment_header_size;
    u16 segment_header_count;
    u16 section_header_size;
    u16 section_header_count;
    u16 section_header_string_table_index;
} elf64_file_header_t;
typedef struct {
    u32 name;
    u32 type;
    u32 flags;
    u32 exec_address;
    u32 file_offset;
    u32 file_size;
    u32 link;
    u32 additional_info;
    u32 align;
    u32 entry_size;
} elf32_section_header_t;
typedef struct {
    u32 name;
    u32 type;
    u64 flags;
    u64 exec_address;
    u64 file_offset;
    u64 file_size;
    u32 link;
    u32 additional_info;
    u64 align;
    u64 entry_size;
} elf64_section_header_t;
typedef struct {
    u32 type;
    u32 file_offset;
    u32 virtual_address;
    u32 physical_address;
    u32 file_size;
    u32 memory_size;
    u32 flags;
    u32 align;
} elf32_segment_header_t;
typedef struct {
    u32 type;
    u32 flags;
    u64 file_offset;
    u64 virtual_address;
    u64 physical_address;
    u64 file_size;
    u64 memory_size;
    u64 align;
} elf64_segment_header_t;
typedef struct {
    u32 name;
    u32 value;
    u32 size;
    u8 binding_and_type;
    u8 visibility;
    u16 section_index;
} elf32_symbol_t;
typedef struct {
    u32 name;
    u8 binding_and_type;
    u8 visibility;
    u16 section_index;
    u64 value;
    u64 size;
} elf64_symbol_t;
typedef enum {
    ELF_SECTION_UNUSED               = 0,
    ELF_SECTION_PROGRAM_DATA         = 1,
    ELF_SECTION_SYMBOL_TABLE         = 2,
    ELF_SECTION_STRING_TABLE         = 3,
    ELF_SECTION_RELOCATION_ADD       = 4,
    ELF_SECTION_SYMBOL_TABLE_HASH    = 5,
    ELF_SECTION_DYNAMIC              = 6,
    ELF_SECTION_NOTE                 = 7,
    ELF_SECTION_NO_BITS              = 8,
    ELF_SECTION_RELOCATION           = 9,
    ELF_SECTION_DYNAMIC_SYMBOL_TABLE = 11,
    ELF_SECTION_INIT_ARRAY           = 14,
    ELF_SECTION_FINI_ARRAY           = 15,
    ELF_SECTION_PREINIT_ARRAY        = 16,
    ELF_SECTION_GROUP                = 17,
    ELF_SECTION_SYMTAB_SHNDX         = 18,
    ELF_SECTION_OS_SPECIFIC_LO       = 0x60000000,
    ELF_SECTION_GNU_LIBLIST          = 0x6ffffff7,
    ELF_SECTION_CHECKSUM             = 0x6ffffff8,
    ELF_SECTION_SUNW_MOVE            = 0x6ffffffa,
    ELF_SECTION_SUNW_COMDAT          = 0x6ffffffb,
    ELF_SECTION_SUNW_SYMINFO         = 0x6ffffffc,
    ELF_SECTION_GNU_VERDEF           = 0x6ffffffd,
    ELF_SECTION_GNU_VERNEED          = 0x6ffffffe,
    ELF_SECTION_GNU_VERSYM           = 0x6fffffff,
    ELF_SECTION_ARCH_SPECIFIC_LO     = 0x70000000,
    ELF_SECTION_ARCH_SPECIFIC_HI     = 0x7fffffff,
    ELF_SECTION_APP_SPECIFIC_LO      = 0x80000000,
    ELF_SECTION_APP_SPECIFIC_HI      = 0x8fffffff,
    ELF_SECTION_OS_SPECIFIC_HI       = 0x6fffffff,
} elf_section_type_t;
typedef enum {
    ELF_SECTION_FLAG_BIT_WRITE               = 0,
    ELF_SECTION_FLAG_BIT_ALLOC               = 1,
    ELF_SECTION_FLAG_BIT_EXEC                = 2,
    ELF_SECTION_FLAG_BIT_MERGE               = 3,
    ELF_SECTION_FLAG_BIT_STRING_TABLE        = 5,
    ELF_SECTION_FLAG_BIT_INFO_LINK           = 6,
    ELF_SECTION_FLAG_BIT_PRESERVE_LINK_ORDER = 7,
    ELF_SECTION_FLAG_BIT_OS_NON_CONFORMING   = 8,
    ELF_SECTION_FLAG_BIT_GROUP               = 9,
    ELF_SECTION_FLAG_BIT_TLS                 = 10,
    ELF_SECTION_FLAG_BIT_OS_SPECIFIC_LO      = 20,
    ELF_SECTION_FLAG_BIT_OS_SPECIFIC_HI      = 27,
    ELF_SECTION_FLAG_BIT_ARCH_SPECIFIC_LO    = 28,
    ELF_SECTION_FLAG_BIT_ARCH_SPECIFIC_HI    = 31,
} elf_section_flag_bit_t;
typedef enum {
    ELF_SECTION_FLAG_WRITE               = 1 << ELF_SECTION_FLAG_BIT_WRITE,
    ELF_SECTION_FLAG_ALLOC               = 1 << ELF_SECTION_FLAG_BIT_ALLOC,
    ELF_SECTION_FLAG_EXEC                = 1 << ELF_SECTION_FLAG_BIT_EXEC,
    ELF_SECTION_FLAG_MERGE               = 1 << ELF_SECTION_FLAG_BIT_MERGE,
    ELF_SECTION_FLAG_STRING_TABLE        = 1 << ELF_SECTION_FLAG_BIT_STRING_TABLE,
    ELF_SECTION_FLAG_INFO_LINK           = 1 << ELF_SECTION_FLAG_BIT_INFO_LINK,
    ELF_SECTION_FLAG_PRESERVE_LINK_ORDER = 1 << ELF_SECTION_FLAG_BIT_PRESERVE_LINK_ORDER,
    ELF_SECTION_FLAG_OS_NON_CONFORMING   = 1 << ELF_SECTION_FLAG_BIT_OS_NON_CONFORMING,
    ELF_SECTION_FLAG_GROUP               = 1 << ELF_SECTION_FLAG_BIT_GROUP,
    ELF_SECTION_FLAG_TLS                 = 1 << ELF_SECTION_FLAG_BIT_TLS,
    ELF_SECTION_FLAG_OS_SPECIFIC_LO      = 1 << ELF_SECTION_FLAG_BIT_OS_SPECIFIC_LO,
    ELF_SECTION_FLAG_OS_SPECIFIC_HI      = 1 << ELF_SECTION_FLAG_BIT_OS_SPECIFIC_HI,
    ELF_SECTION_FLAG_ARCH_SPECIFIC_LO    = 1 << ELF_SECTION_FLAG_BIT_ARCH_SPECIFIC_LO,
    ELF_SECTION_FLAG_ARCH_SPECIFIC_HI    = 1 << ELF_SECTION_FLAG_BIT_ARCH_SPECIFIC_HI,
} elf_section_flag_t;
typedef struct {
    u16 bound_to;
    u16 flags;
} elf_symbol_info_t;
typedef struct {
    u32 address;
    u32 symbol_and_type;
    i32 addend[0];
} elf32_relocation_t;
typedef struct {
    u64 address;
    u64 symbol_and_type;
    i64 addend[0];
} elf64_relocation_t;
typedef struct {
    u64 address;
    u64 symbol_and_type;
    u64 addend;
} elf_relocation_with_addend_t;
typedef enum {
    ELF_SEGMENT_UNUSED           = 0,
    ELF_SEGMENT_LOAD             = 1,
    ELF_SEGMENT_DYNAMIC          = 2,
    ELF_SEGMENT_INTERP           = 3,
    ELF_SEGMENT_NOTE             = 4,
    ELF_SEGMENT_SEGMENT_TABLE    = 6,
    ELF_SEGMENT_TLS              = 7,
    ELF_SEGMENT_OS_SPECIFIC_LO   = 0x60000000,
    ELF_SEGMENT_GNU_EH_FRAME     = 0x6474e550,
    ELF_SEGMENT_GNU_STACK        = 0x6474e551,
    ELF_SEGMENT_GNU_RELRO        = 0x6474e552,
    ELF_SEGMENT_SUNW_BSS         = 0x6ffffffa,
    ELF_SEGMENT_SUNW_STACK       = 0x6ffffffb,
    ELF_SEGMENT_OS_SPECIFIC_HI   = 0x6fffffff,
    ELF_SEGMENT_ARCH_SPECIFIC_LO = 0x70000000,
    ELF_SEGMENT_ARCH_SPECIFIC_HI = 0x7fffffff,
} elf_segment_type_t;
typedef enum {
    ELF_SEGMENT_FLAG_BIT_EXEC             = 0,
    ELF_SEGMENT_FLAG_BIT_WRITE            = 1,
    ELF_SEGMENT_FLAG_BIT_READ             = 2,
    ELF_SEGMENT_FLAG_BIT_OS_SPECIFIC_LO   = 20,
    ELF_SEGMENT_FLAG_BIT_OS_SPECIFIC_HI   = 27,
    ELF_SEGMENT_FLAG_BIT_ARCH_SPECIFIC_LO = 28,
    ELF_SEGMENT_FLAG_BIT_ARCH_SPECIFIC_HI = 31,
} elf_segment_flag_bit_t;
typedef enum {
    ELF_SEGMENT_FLAG_EXEC             = 1 << ELF_SEGMENT_FLAG_BIT_EXEC,
    ELF_SEGMENT_FLAG_WRITE            = 1 << ELF_SEGMENT_FLAG_BIT_WRITE,
    ELF_SEGMENT_FLAG_READ             = 1 << ELF_SEGMENT_FLAG_BIT_READ,
    ELF_SEGMENT_FLAG_OS_SPECIFIC_LO   = 1 << ELF_SEGMENT_FLAG_BIT_OS_SPECIFIC_LO,
    ELF_SEGMENT_FLAG_OS_SPECIFIC_HI   = 1 << ELF_SEGMENT_FLAG_BIT_OS_SPECIFIC_HI,
    ELF_SEGMENT_FLAG_ARCH_SPECIFIC_LO = 1 << ELF_SEGMENT_FLAG_BIT_ARCH_SPECIFIC_LO,
    ELF_SEGMENT_FLAG_ARCH_SPECIFIC_HI = 1 << ELF_SEGMENT_FLAG_BIT_ARCH_SPECIFIC_HI,
} elf_segment_flag_t;
typedef struct {
    u32 type;
    u32 data;
} elf32_dynamic_entry_t;
typedef struct {
    u64 type;
    u64 data;
} elf64_dynamic_entry_t;
typedef enum {
    ELF_DYNAMIC_ENTRY_END                     = (0),
    ELF_DYNAMIC_ENTRY_NEEDED_LIBRARY          = (1),
    ELF_DYNAMIC_ENTRY_PLT_RELOCATION_SIZE     = (2),
    ELF_DYNAMIC_ENTRY_PLT_GOT                 = (3),
    ELF_DYNAMIC_ENTRY_SYMBOL_HASH             = (4),
    ELF_DYNAMIC_ENTRY_STRING_TABLE            = (5),
    ELF_DYNAMIC_ENTRY_SYMBOL_TABLE            = (6),
    ELF_DYNAMIC_ENTRY_RELA_ADDRESS            = (7),
    ELF_DYNAMIC_ENTRY_RELA_SIZE               = (8),
    ELF_DYNAMIC_ENTRY_RELA_ENTRY_SIZE         = (9),
    ELF_DYNAMIC_ENTRY_STRING_TABLE_SIZE       = (10),
    ELF_DYNAMIC_ENTRY_SYMBOL_TABLE_ENTRY_SIZE = (11),
    ELF_DYNAMIC_ENTRY_INIT_FUNCTION           = (12),
    ELF_DYNAMIC_ENTRY_FINI_FUNCTION           = (13),
    ELF_DYNAMIC_ENTRY_SONAME                  = (14),
    ELF_DYNAMIC_ENTRY_RPATH                   = (15),
    ELF_DYNAMIC_ENTRY_SYMBOLIC                = (16),
    ELF_DYNAMIC_ENTRY_REL                     = (17),
    ELF_DYNAMIC_ENTRY_RELSZ                   = (18),
    ELF_DYNAMIC_ENTRY_RELENT                  = (19),
    ELF_DYNAMIC_ENTRY_PLT_RELOCATION_TYPE     = (20),
    ELF_DYNAMIC_ENTRY_DEBUG                   = (21),
    ELF_DYNAMIC_ENTRY_TEXTREL                 = (22),
    ELF_DYNAMIC_ENTRY_PLT_RELOCATION_ADDRESS  = (23),
    ELF_DYNAMIC_ENTRY_BIND_NOW                = (24),
    ELF_DYNAMIC_ENTRY_INIT_ARRAY              = (25),
    ELF_DYNAMIC_ENTRY_FINI_ARRAY              = (26),
    ELF_DYNAMIC_ENTRY_INIT_ARRAYSZ            = (27),
    ELF_DYNAMIC_ENTRY_FINI_ARRAYSZ            = (28),
    ELF_DYNAMIC_ENTRY_RUN_PATH                = (29),
    ELF_DYNAMIC_ENTRY_FLAGS                   = (30),
    ELF_DYNAMIC_ENTRY_ENCODING                = (31),
    ELF_DYNAMIC_ENTRY_PREINIT_ARRAY           = (32),
    ELF_DYNAMIC_ENTRY_PREINIT_ARRAY_SIZE      = (33),
    ELF_DYNAMIC_ENTRY_GNU_PRELINKED           = (0x6ffffdf5),
    ELF_DYNAMIC_ENTRY_GNU_CONFLICTSZ          = (0x6ffffdf6),
    ELF_DYNAMIC_ENTRY_GNU_LIBLISTSZ           = (0x6ffffdf7),
    ELF_DYNAMIC_ENTRY_CHECKSUM                = (0x6ffffdf8),
    ELF_DYNAMIC_ENTRY_PLTPADSZ                = (0x6ffffdf9),
    ELF_DYNAMIC_ENTRY_MOVEENT                 = (0x6ffffdfa),
    ELF_DYNAMIC_ENTRY_MOVESZ                  = (0x6ffffdfb),
    ELF_DYNAMIC_ENTRY_FEATURE_1               = (0x6ffffdfc),
    ELF_DYNAMIC_ENTRY_POSFLAG_1               = (0x6ffffdfd),
    ELF_DYNAMIC_ENTRY_SYMINSZ                 = (0x6ffffdfe),
    ELF_DYNAMIC_ENTRY_SYMINENT                = (0x6ffffdff),
    ELF_DYNAMIC_ENTRY_GNU_HASH                = (0x6ffffef5),
    ELF_DYNAMIC_ENTRY_GNU_CONFLICT            = (0x6ffffef8),
    ELF_DYNAMIC_ENTRY_GNU_LIBLIST             = (0x6ffffef9),
    ELF_DYNAMIC_ENTRY_CONFIG                  = (0x6ffffefa),
    ELF_DYNAMIC_ENTRY_DEPAUDIT                = (0x6ffffefb),
    ELF_DYNAMIC_ENTRY_AUDIT                   = (0x6ffffefc),
    ELF_DYNAMIC_ENTRY_PLTPAD                  = (0x6ffffefd),
    ELF_DYNAMIC_ENTRY_MOVETAB                 = (0x6ffffefe),
    ELF_DYNAMIC_ENTRY_SYMINFO                 = (0x6ffffeff),
    ELF_DYNAMIC_ENTRY_VERSYM                  = (0x6ffffff0),
    ELF_DYNAMIC_ENTRY_RELACOUNT               = (0x6ffffff9),
    ELF_DYNAMIC_ENTRY_RELCOUNT                = (0x6ffffffa),
    ELF_DYNAMIC_ENTRY_FLAGS_1                 = (0x6ffffffb),
    ELF_DYNAMIC_ENTRY_VERSION_DEF             = (0x6ffffffc),
    ELF_DYNAMIC_ENTRY_VERSION_DEF_COUNT       = (0x6ffffffd),
    ELF_DYNAMIC_ENTRY_VERSION_NEED            = (0x6ffffffe),
    ELF_DYNAMIC_ENTRY_VERSION_NEED_COUNT      = (0x6fffffff),
    ELF_DYNAMIC_ENTRY_AUXILIARY               = (0x7ffffffd),
    ELF_DYNAMIC_ENTRY_FILTER                  = (0x7fffffff),
} elf_dynamic_entry_type_t;
typedef struct {
    u16 version;
    u16 flags;
    u16 index;
    u16 aux_count;
    u32 name_hash;
    u32 aux_byte_offset;
    u32 byte_offset_next_version_definition;
} elf_dynamic_version_definition_t;
typedef struct {
    u32 name;
    u32 next_offset;
} elf_dynamic_version_definition_aux_t;
typedef struct {
    u16 version;
    u16 aux_count;
    u32 file_name_offset;
    u32 first_aux_offset;
    u32 next_offset;
} elf_dynamic_version_need_t;
typedef struct {
    u32 hash;
    u16 flags;
    u16 versym_index;
    u32 name;
    u32 next_offset;
} elf_dynamic_version_need_aux_t;
typedef union {
    elf_dynamic_version_need_t need;
    elf_dynamic_version_need_aux_t aux;
} elf_dynamic_version_need_union_t;
typedef struct {
    u32 name_size;
    u32 descriptor_size;
    u32 type;
} elf_note_t;
typedef struct {
    elf64_symbol_t *symbols;
    u32 section_index;
    u8 *string_table;
    uword *symbol_by_name;
} elf_symbol_table_t;
static inline __attribute__((__always_inline__)) void
elf_symbol_table_free(elf_symbol_table_t *s)
{
    do {
        if (s->symbols) {
            clib_mem_free(vec_header((s->symbols), (0)));
            s->symbols = 0;
        }
    } while (0);
    (s->symbol_by_name) = _hash_free((s->symbol_by_name));
}
static inline __attribute__((__always_inline__)) u8 *
elf_symbol_name(elf_symbol_table_t *t, elf64_symbol_t *sym)
{
    return ({
        do {
            if ((0 > 0) && !((sym->name) < ((t->string_table) ? (((vec_header_t *) (t->string_table) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/elf.h", (uword) 837,
                            ((char *) __FUNCTION__), "(sym->name) < vec_len (t->string_table)");
            }
        } while (0);
        (t->string_table) + (sym->name);
    });
}
typedef struct {
    elf_relocation_with_addend_t *relocations;
    u32 section_index;
} elf_relocation_table_t;
static inline __attribute__((__always_inline__)) void
elf_relocation_table_free(elf_relocation_table_t *r)
{
    do {
        if (r->relocations) {
            clib_mem_free(vec_header((r->relocations), (0)));
            r->relocations = 0;
        }
    } while (0);
}
typedef struct {
    elf64_section_header_t header;
    u32 index;
    uword *segment_index_bitmap;
    u64 align_size;
    i64 exec_address_change;
    u8 *contents;
} elf_section_t;
typedef struct {
    elf64_segment_header_t header;
    uword *section_index_bitmap;
    u32 index;
    u8 *contents;
} elf_segment_t;
typedef struct {
    u8 need_byte_swap;
    u8 parsed_symbols;
    char *file_name;
    elf_first_header_t first_header;
    elf64_file_header_t file_header;
    elf_segment_t *segments;
    elf_section_t *sections;
    uword *section_by_name;
    uword *section_by_start_address;
    elf_symbol_table_t *symbol_tables;
    elf_relocation_table_t *relocation_tables;
    char *interpreter;
    elf64_dynamic_entry_t *dynamic_entries;
    u8 *dynamic_string_table;
    u32 dynamic_string_table_section_index;
    u32 dynamic_symbol_table_section_index;
    u32 dynamic_symbol_table_index;
    u32 dynamic_section_index;
    u16 *versym;
    u32 versym_section_index;
    elf_dynamic_version_need_union_t *verneed;
    u32 verneed_section_index;
} elf_main_t;
static inline __attribute__((__always_inline__)) void
elf_main_init(elf_main_t *em)
{
    memset(em, 0, sizeof(em[0]));
}
static inline __attribute__((__always_inline__)) void
elf_main_free(elf_main_t *em)
{
    uword i;
    for (i = 0; i < ((em->segments) ? (((vec_header_t *) (em->segments) - 1)->len) : 0); i++)
        do {
            if (em->segments[i].contents) {
                clib_mem_free(vec_header((em->segments[i].contents), (0)));
                em->segments[i].contents = 0;
            }
        } while (0);
    do {
        if (em->segments) {
            clib_mem_free(vec_header((em->segments), (0)));
            em->segments = 0;
        }
    } while (0);
    for (i = 0; i < ((em->sections) ? (((vec_header_t *) (em->sections) - 1)->len) : 0); i++)
        do {
            if (em->sections[i].contents) {
                clib_mem_free(vec_header((em->sections[i].contents), (0)));
                em->sections[i].contents = 0;
            }
        } while (0);
    do {
        if (em->sections) {
            clib_mem_free(vec_header((em->sections), (0)));
            em->sections = 0;
        }
    } while (0);
    (em->section_by_name) = _hash_free((em->section_by_name));
    for (i = 0; i < ((em->symbol_tables) ? (((vec_header_t *) (em->symbol_tables) - 1)->len) : 0); i++)
        elf_symbol_table_free(em->symbol_tables + i);
    for (i = 0; i < ((em->relocation_tables) ? (((vec_header_t *) (em->relocation_tables) - 1)->len) : 0); i++)
        elf_relocation_table_free(em->relocation_tables + i);
    do {
        if (em->dynamic_entries) {
            clib_mem_free(vec_header((em->dynamic_entries), (0)));
            em->dynamic_entries = 0;
        }
    } while (0);
    do {
        if (em->interpreter) {
            clib_mem_free(vec_header((em->interpreter), (0)));
            em->interpreter = 0;
        }
    } while (0);
}
static inline __attribute__((__always_inline__)) void
elf_get_segment_contents(elf_main_t *em, void *data, uword segment_index)
{
    elf_segment_t *g = ({
        do {
            if ((0 > 0) && !((segment_index) < ((em->segments) ? (((vec_header_t *) (em->segments) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/elf.h", (uword) 951,
                            ((char *) __FUNCTION__), "(segment_index) < vec_len (em->segments)");
            }
        } while (0);
        (em->segments) + (segment_index);
    });
    if (!g->contents)
        do {
            word _vec_n = (g->header.memory_size);
            word _vec_l = ((g->contents) ? (((vec_header_t *) (g->contents) - 1)->len) : 0);
            g->contents = _vec_resize_inline((g->contents), _vec_n, (_vec_l + _vec_n) * sizeof((g->contents)[0]), (0), ({
                                                 __typeof__((__alignof__(((g->contents))[0]))) _x =
                                                     ((__alignof__(((g->contents))[0])));
                                                 __typeof__(((0))) _y = (((0)));
                                                 _x > _y ? _x : _y;
                                             }));
            memcpy((g->contents) + _vec_l, (data + g->header.file_offset), _vec_n * sizeof((g->contents)[0]));
        } while (0);
}
static inline __attribute__((__always_inline__)) void *
elf_get_section_contents(elf_main_t *em, uword section_index, uword elt_size)
{
    elf_section_t *s;
    void *result;
    s      = ({
        do {
            if ((0 > 0) && !((section_index) < ((em->sections) ? (((vec_header_t *) (em->sections) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/elf.h", (uword) 964,
                            ((char *) __FUNCTION__), "(section_index) < vec_len (em->sections)");
            }
        } while (0);
        (em->sections) + (section_index);
    });
    result = 0;
    if (((s->contents) ? (((vec_header_t *) (s->contents) - 1)->len) : 0) > 0) {
        result = _vec_resize_inline(result, ((s->contents) ? (((vec_header_t *) (s->contents) - 1)->len) : 0) / elt_size,
                                    ((s->contents) ? (((vec_header_t *) (s->contents) - 1)->len) : 0), 0, ({
                                        __typeof__((__alignof__((result)[0]))) _x = ((__alignof__((result)[0])));
                                        __typeof__((0)) _y                        = ((0));
                                        _x > _y ? _x : _y;
                                    }));
        memcpy(result, s->contents, ((s->contents) ? (((vec_header_t *) (s->contents) - 1)->len) : 0));
    }
    return result;
}
static inline __attribute__((__always_inline__)) void
elf_set_section_contents(elf_main_t *em, uword section_index, void *new_contents, uword n_content_bytes)
{
    elf_section_t *s;
    s = ({
        do {
            if ((0 > 0) && !((section_index) < ((em->sections) ? (((vec_header_t *) (em->sections) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/elf.h", (uword) 988,
                            ((char *) __FUNCTION__), "(section_index) < vec_len (em->sections)");
            }
        } while (0);
        (em->sections) + (section_index);
    });
    do {
        if (s->contents) {
            clib_mem_free(vec_header((s->contents), (0)));
            s->contents = 0;
        }
    } while (0);
    do {
        word _vec_n = (n_content_bytes);
        word _vec_l = ((s->contents) ? (((vec_header_t *) (s->contents) - 1)->len) : 0);
        s->contents = _vec_resize_inline((s->contents), _vec_n, (_vec_l + _vec_n) * sizeof((s->contents)[0]), (0), ({
                                             __typeof__((__alignof__(((s->contents))[0]))) _x =
                                                 ((__alignof__(((s->contents))[0])));
                                             __typeof__(((0))) _y = (((0)));
                                             _x > _y ? _x : _y;
                                         }));
        memcpy((s->contents) + _vec_l, (new_contents), _vec_n * sizeof((s->contents)[0]));
    } while (0);
}
static inline __attribute__((__always_inline__)) u8 *
elf_section_name(elf_main_t *em, elf_section_t *s)
{
    elf_section_t *es = ({
        do {
            if ((0 > 0) && !((em->file_header.section_header_string_table_index) <
                             ((em->sections) ? (((vec_header_t *) (em->sections) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/elf.h", (uword) 998,
                            ((char *) __FUNCTION__),
                            "(em-> file_header.section_header_string_table_index) < vec_len (em->sections)");
            }
        } while (0);
        (em->sections) + (em->file_header.section_header_string_table_index);
    });
    return ({
        do {
            if ((0 > 0) && !((s->header.name) < ((es->contents) ? (((vec_header_t *) (es->contents) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/elf.h", (uword) 999,
                            ((char *) __FUNCTION__), "(s->header.name) < vec_len (es->contents)");
            }
        } while (0);
        (es->contents) + (s->header.name);
    });
}
static inline __attribute__((__always_inline__)) u8
elf_swap_u8(elf_main_t *em, u8 x)
{
    return x;
}
static inline __attribute__((__always_inline__)) u16
elf_swap_u16(elf_main_t *em, u16 x)
{
    return em->need_byte_swap ? clib_byte_swap_u16(x) : x;
}
static inline __attribute__((__always_inline__)) u32
elf_swap_u32(elf_main_t *em, u32 x)
{
    return em->need_byte_swap ? clib_byte_swap_u32(x) : x;
}
static inline __attribute__((__always_inline__)) u64
elf_swap_u64(elf_main_t *em, u64 x)
{
    return em->need_byte_swap ? clib_byte_swap_u64(x) : x;
}
format_function_t format_elf_main;
format_function_t format_elf_symbol;
clib_error_t *elf_read_file(elf_main_t *em, char *file_name);
clib_error_t *elf_write_file(elf_main_t *em, char *file_name);
clib_error_t *elf_delete_named_section(elf_main_t *em, char *section_name);
clib_error_t *elf_parse(elf_main_t *em, void *data, uword data_bytes);
void elf_parse_symbols(elf_main_t *em);
clib_error_t *elf_get_section_by_name(elf_main_t *em, char *section_name, elf_section_t **result);
clib_error_t *elf_get_section_by_start_address(elf_main_t *em, uword start_address, elf_section_t **result);
void elf_create_section_with_contents(elf_main_t *em, char *section_name, elf64_section_header_t *header,
                                      void *contents, uword n_content_bytes);
uword elf_delete_segment_with_type(elf_main_t *em, elf_segment_type_t segment_type);
void elf_set_dynamic_entries(elf_main_t *em);
typedef struct {
    void *lo, *hi;
} clib_elf_section_bounds_t;
typedef struct {
    clib_elf_section_bounds_t *bounds;
    u8 *name;
} clib_elf_section_t;
typedef struct {
    clib_elf_section_t *sections;
    uword *section_by_name;
    char *exec_path;
    elf_main_t *elf_mains;
} clib_elf_main_t;
static inline __attribute__((__always_inline__)) void
clib_elf_main_free(clib_elf_main_t *m)
{
    clib_elf_section_t *s;
    for (s = (m->sections); s < ((m->sections) + ((m->sections) ? (((vec_header_t *) (m->sections) - 1)->len) : 0)); s++) {
        do {
            if (s->bounds) {
                clib_mem_free(vec_header((s->bounds), (0)));
                s->bounds = 0;
            }
        } while (0);
        do {
            if (s->name) {
                clib_mem_free(vec_header((s->name), (0)));
                s->name = 0;
            }
        } while (0);
    }
    do {
        if (m->sections) {
            clib_mem_free(vec_header((m->sections), (0)));
            m->sections = 0;
        }
    } while (0);
    (m->section_by_name) = _hash_free((m->section_by_name));
    {
        elf_main_t *em;
        for (em = (m->elf_mains);
             em < ((m->elf_mains) + ((m->elf_mains) ? (((vec_header_t *) (m->elf_mains) - 1)->len) : 0)); em++) {
            elf_main_free(em);
        }
        do {
            if (m->elf_mains) {
                clib_mem_free(vec_header((m->elf_mains), (0)));
                m->elf_mains = 0;
            }
        } while (0);
    }
}
void clib_elf_main_init(char *exec_path);
clib_elf_section_bounds_t *clib_elf_get_section_bounds(char *name);
typedef struct {
    elf64_symbol_t symbol;
    u32 elf_main_index;
    u32 symbol_table_index;
} clib_elf_symbol_t;
uword clib_elf_symbol_by_name(char *name, clib_elf_symbol_t *result);
uword clib_elf_symbol_by_address(uword address, clib_elf_symbol_t *result);
format_function_t format_clib_elf_symbol, format_clib_elf_symbol_with_address;
typedef enum {
    VLIB_RX,
    VLIB_TX,
    VLIB_N_RX_TX = 2,
} vlib_rx_or_tx_t;
typedef enum {
    VLIB_READ,
    VLIB_WRITE,
} vlib_read_or_write_t;
typedef enum {
    VLIB_DOWN = 0,
    VLIB_UP   = 1,
} vlib_up_or_down_t;
typedef enum {
    VLIB_DISABLE = 0,
    VLIB_ENABLE  = 1,
} vlib_enable_or_disable_t;
struct vlib_main_t;
typedef u8 vlib_physmem_region_index_t;
typedef struct {
    vlib_physmem_region_index_t index;
    void *mem;
    uword size;
    int fd;
    u8 log2_page_size;
    u16 n_pages;
    u32 page_mask;
    void *heap;
    u32 flags;
    u8 numa_node;
    u64 *page_table;
    u8 *name;
} vlib_physmem_region_t;
typedef struct {
    u32 flags;
    vlib_physmem_region_t *regions;
} vlib_physmem_main_t;
extern vlib_physmem_main_t physmem_main;
typedef struct {
    uword regs[8];
} clib_longjmp_t __attribute__((aligned(16)));
void clib_longjmp(clib_longjmp_t *save, uword return_value);
uword clib_setjmp(clib_longjmp_t *save, uword return_value_not_taken);
uword clib_calljmp(uword (*func)(uword func_arg), uword func_arg, void *stack);
struct serialize_main_header_t;
struct serialize_stream_t;
typedef void(serialize_data_function_t)(struct serialize_main_header_t *h, struct serialize_stream_t *s);
typedef struct serialize_stream_t {
    u8 *buffer;
    u32 n_buffer_bytes;
    u32 current_buffer_index;
    u8 *overflow_buffer;
    u32 current_overflow_index;
    u32 flags;
    uword data_function_opaque;
    u32 opaque[64 - 4 * sizeof(u32) - 1 * sizeof(uword) - 2 * sizeof(void *)];
} serialize_stream_t;
static inline __attribute__((__always_inline__)) void
serialize_stream_set_end_of_stream(serialize_stream_t *s)
{
    s->flags |= (1 << 0);
}
static inline __attribute__((__always_inline__)) uword
serialize_stream_is_end_of_stream(serialize_stream_t *s)
{
    return (s->flags & (1 << 0)) != 0;
}
typedef struct serialize_main_header_t {
    u32 recursion_level;
    serialize_data_function_t *data_function;
    clib_error_t *error;
    clib_longjmp_t error_longjmp;
} serialize_main_header_t;
static inline __attribute__((__always_inline__)) void
serialize_error(serialize_main_header_t *m, clib_error_t *error)
{
    clib_longjmp(&m->error_longjmp, pointer_to_uword(error));
}
void *serialize_read_write_not_inline(serialize_main_header_t *m, serialize_stream_t *s, uword n_bytes, uword flags);
static inline __attribute__((__always_inline__)) void *
serialize_stream_read_write(serialize_main_header_t *header, serialize_stream_t *s, uword n_bytes, uword flags)
{
    uword i, j, l;
    l                       = ((s->overflow_buffer) ? (((vec_header_t *) (s->overflow_buffer) - 1)->len) : 0);
    i                       = s->current_buffer_index;
    j                       = i + n_bytes;
    s->current_buffer_index = j;
    if (l == 0 && j <= s->n_buffer_bytes) {
        return s->buffer + i;
    } else {
        s->current_buffer_index = i;
        return serialize_read_write_not_inline(header, s, n_bytes, flags);
    }
}
typedef struct {
    serialize_main_header_t header;
    serialize_stream_t stream;
} serialize_main_t;
static inline __attribute__((__always_inline__)) void
serialize_set_end_of_stream(serialize_main_t *m)
{
    serialize_stream_set_end_of_stream(&m->stream);
}
static inline __attribute__((__always_inline__)) uword
serialize_is_end_of_stream(serialize_main_t *m)
{
    return serialize_stream_is_end_of_stream(&m->stream);
}
typedef struct {
    serialize_main_header_t header;
    serialize_stream_t *streams;
} serialize_multiple_main_t;
typedef void(serialize_function_t)(serialize_main_t *m, va_list *va);
static inline __attribute__((__always_inline__)) void *
unserialize_get(serialize_main_t *m, uword n_bytes)
{
    return serialize_stream_read_write(&m->header, &m->stream, n_bytes, (1 << 0));
}
static inline __attribute__((__always_inline__)) void *
serialize_get(serialize_main_t *m, uword n_bytes)
{
    return serialize_stream_read_write(&m->header, &m->stream, n_bytes, (1 << 1));
}
static inline __attribute__((__always_inline__)) void
serialize_integer(serialize_main_t *m, u64 x, u32 n_bytes)
{
    u8 *p = serialize_get(m, n_bytes);
    if (n_bytes == 1)
        p[0] = x;
    else if (n_bytes == 2)
        (((struct { u16 _data __attribute__((packed)); } *) (p))->_data) = clib_host_to_net_u16(x);
    else if (n_bytes == 4)
        (((struct { u32 _data __attribute__((packed)); } *) (p))->_data) = clib_host_to_net_u32(x);
    else if (n_bytes == 8)
        (((struct { u64 _data __attribute__((packed)); } *) (p))->_data) = clib_host_to_net_u64(x);
    else
        do {
            if ((0 > 0) && !(0)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/serialize.h",
                            (uword) 197, ((char *) __FUNCTION__), "0");
            }
        } while (0);
}
static inline __attribute__((__always_inline__)) void
unserialize_integer(serialize_main_t *m, void *x, u32 n_bytes)
{
    u8 *p = unserialize_get(m, n_bytes);
    if (n_bytes == 1)
        *(u8 *) x = p[0];
    else if (n_bytes == 2)
        *(u16 *) x = clib_net_to_host_unaligned_mem_u16((u16 *) p);
    else if (n_bytes == 4)
        *(u32 *) x = clib_net_to_host_unaligned_mem_u32((u32 *) p);
    else if (n_bytes == 8)
        *(u64 *) x = clib_net_to_host_unaligned_mem_u64((u64 *) p);
    else
        do {
            if ((0 > 0) && !(0)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/serialize.h",
                            (uword) 213, ((char *) __FUNCTION__), "0");
            }
        } while (0);
}
static inline __attribute__((__always_inline__)) void
serialize_likely_small_unsigned_integer(serialize_main_t *m, u64 x)
{
    u64 r = x;
    u8 *p;
    if (r < (1 << 7)) {
        p    = serialize_get(m, 1);
        p[0] = 1 + 2 * r;
        return;
    }
    r -= (1 << 7);
    if (r < (1 << 14)) {
        p                                                                = serialize_get(m, 2);
        (((struct { u16 _data __attribute__((packed)); } *) (p))->_data) = clib_host_to_little_u16(4 * r + 2);
        return;
    }
    r -= (1 << 14);
    if (r < (1 << 29)) {
        p                                                                = serialize_get(m, 4);
        (((struct { u32 _data __attribute__((packed)); } *) (p))->_data) = clib_host_to_little_u32(8 * r + 4);
        return;
    }
    p                                                                    = serialize_get(m, 9);
    p[0]                                                                 = 0;
    (((struct { u64 _data __attribute__((packed)); } *) (p + 1))->_data) = clib_host_to_little_u64(x);
}
static inline __attribute__((__always_inline__)) u64
unserialize_likely_small_unsigned_integer(serialize_main_t *m)
{
    u8 *p = unserialize_get(m, 1);
    u64 r;
    u32 y = p[0];
    if (y & 1)
        return y / 2;
    r = 1 << 7;
    if (y & 2) {
        p = unserialize_get(m, 1);
        r += (y / 4) + (p[0] << 6);
        return r;
    }
    r += 1 << 14;
    if (y & 4) {
        p = unserialize_get(m, 3);
        r += ((y / 8) + (p[0] << (5 + 8 * 0)) + (p[1] << (5 + 8 * 1)) + (p[2] << (5 + 8 * 2)));
        return r;
    }
    p = unserialize_get(m, 8);
    r = (((struct { u64 _data __attribute__((packed)); } *) (p))->_data);
    r = clib_little_to_host_u64(r);
    return r;
}
static inline __attribute__((__always_inline__)) void
serialize_likely_small_signed_integer(serialize_main_t *m, i64 s)
{
    u64 u = s < 0 ? -(2 * s + 1) : 2 * s;
    serialize_likely_small_unsigned_integer(m, u);
}
static inline __attribute__((__always_inline__)) i64
unserialize_likely_small_signed_integer(serialize_main_t *m)
{
    u64 u = unserialize_likely_small_unsigned_integer(m);
    i64 s = u / 2;
    return (u & 1) ? -s : s;
}
void serialize_multiple_1(serialize_main_t *m, void *data, uword data_stride, uword n_data);
void serialize_multiple_2(serialize_main_t *m, void *data, uword data_stride, uword n_data);
void serialize_multiple_4(serialize_main_t *m, void *data, uword data_stride, uword n_data);
void unserialize_multiple_1(serialize_main_t *m, void *data, uword data_stride, uword n_data);
void unserialize_multiple_2(serialize_main_t *m, void *data, uword data_stride, uword n_data);
void unserialize_multiple_4(serialize_main_t *m, void *data, uword data_stride, uword n_data);
static inline __attribute__((__always_inline__)) void
serialize_multiple(serialize_main_t *m, void *data, uword n_data_bytes, uword data_stride, uword n_data)
{
    if (n_data_bytes == 1)
        serialize_multiple_1(m, data, data_stride, n_data);
    else if (n_data_bytes == 2)
        serialize_multiple_2(m, data, data_stride, n_data);
    else if (n_data_bytes == 4)
        serialize_multiple_4(m, data, data_stride, n_data);
    else
        do {
            if ((0 > 0) && !(0)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/serialize.h",
                            (uword) 335, ((char *) __FUNCTION__), "0");
            }
        } while (0);
}
static inline __attribute__((__always_inline__)) void
unserialize_multiple(serialize_main_t *m, void *data, uword n_data_bytes, uword data_stride, uword n_data)
{
    if (n_data_bytes == 1)
        unserialize_multiple_1(m, data, data_stride, n_data);
    else if (n_data_bytes == 2)
        unserialize_multiple_2(m, data, data_stride, n_data);
    else if (n_data_bytes == 4)
        unserialize_multiple_4(m, data, data_stride, n_data);
    else
        do {
            if ((0 > 0) && !(0)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/serialize.h",
                            (uword) 350, ((char *) __FUNCTION__), "0");
            }
        } while (0);
}
serialize_function_t serialize_64, unserialize_64;
serialize_function_t serialize_32, unserialize_32;
serialize_function_t serialize_16, unserialize_16;
serialize_function_t serialize_8, unserialize_8;
serialize_function_t serialize_f64, unserialize_f64;
serialize_function_t serialize_f32, unserialize_f32;
serialize_function_t serialize_vec_8, unserialize_vec_8;
serialize_function_t serialize_vec_16, unserialize_vec_16;
serialize_function_t serialize_vec_32, unserialize_vec_32;
serialize_function_t serialize_vec_64, unserialize_vec_64;
serialize_function_t serialize_vector, unserialize_vector, unserialize_aligned_vector;
serialize_function_t serialize_pool, unserialize_pool, unserialize_aligned_pool;
serialize_function_t serialize_heap, unserialize_heap;
void serialize_bitmap(serialize_main_t *m, uword *b);
uword *unserialize_bitmap(serialize_main_t *m);
void serialize_cstring(serialize_main_t *m, char *string);
void unserialize_cstring(serialize_main_t *m, char **string);
void serialize_close(serialize_main_t *m);
void unserialize_close(serialize_main_t *m);
void serialize_open_data(serialize_main_t *m, u8 *data, uword n_data_bytes);
void unserialize_open_data(serialize_main_t *m, u8 *data, uword n_data_bytes);
void serialize_open_vector(serialize_main_t *m, u8 *vector);
void *serialize_close_vector(serialize_main_t *m);
void unserialize_open_vector(serialize_main_t *m, u8 *vector);
clib_error_t *serialize_open_clib_file(serialize_main_t *m, char *file);
clib_error_t *unserialize_open_clib_file(serialize_main_t *m, char *file);
void serialize_open_clib_file_descriptor(serialize_main_t *m, int fd);
void unserialize_open_clib_file_descriptor(serialize_main_t *m, int fd);
clib_error_t *serialize(serialize_main_t *m, ...);
clib_error_t *unserialize(serialize_main_t *m, ...);
clib_error_t *va_serialize(serialize_main_t *m, va_list *va);
void serialize_magic(serialize_main_t *m, void *magic, u32 magic_bytes);
void unserialize_check_magic(serialize_main_t *m, void *magic, u32 magic_bytes);
typedef struct {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    u32 lock;
} * clib_spinlock_t;
static inline void
clib_spinlock_init(clib_spinlock_t *p)
{
    *p = clib_mem_alloc_aligned((1 << 6), (1 << 6));
    memset((void *) *p, 0, (1 << 6));
}
static inline void
clib_spinlock_free(clib_spinlock_t *p)
{
    if (*p) {
        clib_mem_free((void *) *p);
        *p = 0;
    }
}
static inline __attribute__((__always_inline__)) void
clib_spinlock_lock(clib_spinlock_t *p)
{
    while (__sync_lock_test_and_set(&(*p)->lock, 1))
        __builtin_ia32_pause();
    ;
}
static inline __attribute__((__always_inline__)) void
clib_spinlock_lock_if_init(clib_spinlock_t *p)
{
    if (__builtin_expect((*p != 0), 0))
        clib_spinlock_lock(p);
}
static inline __attribute__((__always_inline__)) void
clib_spinlock_unlock(clib_spinlock_t *p)
{
    ;
    __sync_synchronize();
    (*p)->lock = 0;
}
static inline __attribute__((__always_inline__)) void
clib_spinlock_unlock_if_init(clib_spinlock_t *p)
{
    if (__builtin_expect((*p != 0), 0))
        clib_spinlock_unlock(p);
}
typedef struct clib_rw_lock_ {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    volatile u32 n_readers;
    volatile u32 n_readers_lock;
    volatile u32 writer_lock;
} * clib_rwlock_t;
static inline __attribute__((__always_inline__)) void
clib_rwlock_init(clib_rwlock_t *p)
{
    *p = clib_mem_alloc_aligned((1 << 6), (1 << 6));
    memset((void *) *p, 0, (1 << 6));
}
static inline __attribute__((__always_inline__)) void
clib_rwlock_free(clib_rwlock_t *p)
{
    if (*p) {
        clib_mem_free((void *) *p);
        *p = 0;
    }
}
static inline __attribute__((__always_inline__)) void
clib_rwlock_reader_lock(clib_rwlock_t *p)
{
    while (__sync_lock_test_and_set(&(*p)->n_readers_lock, 1))
        __builtin_ia32_pause();
    (*p)->n_readers += 1;
    if ((*p)->n_readers == 1) {
        while (__sync_lock_test_and_set(&(*p)->writer_lock, 1))
            __builtin_ia32_pause();
    }
    __sync_synchronize();
    (*p)->n_readers_lock = 0;
    ;
}
static inline __attribute__((__always_inline__)) void
clib_rwlock_reader_unlock(clib_rwlock_t *p)
{
    do {
        if ((0 > 0) && !((*p)->n_readers > 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/lock.h", (uword) 159,
                        ((char *) __FUNCTION__), "(*p)->n_readers > 0");
        }
    } while (0);
    ;
    while (__sync_lock_test_and_set(&(*p)->n_readers_lock, 1))
        __builtin_ia32_pause();
    (*p)->n_readers -= 1;
    if ((*p)->n_readers == 0) {
        __sync_synchronize();
        (*p)->writer_lock = 0;
    }
    __sync_synchronize();
    (*p)->n_readers_lock = 0;
}
static inline __attribute__((__always_inline__)) void
clib_rwlock_writer_lock(clib_rwlock_t *p)
{
    while (__sync_lock_test_and_set(&(*p)->writer_lock, 1))
        __builtin_ia32_pause();
    ;
}
static inline __attribute__((__always_inline__)) void
clib_rwlock_writer_unlock(clib_rwlock_t *p)
{
    ;
    __sync_synchronize();
    (*p)->writer_lock = 0;
}
typedef u16 vlib_error_t;
static inline __attribute__((__always_inline__)) u32
vlib_error_get_node(vlib_error_t e)
{
    return e >> 6;
}
static inline __attribute__((__always_inline__)) u32
vlib_error_get_code(vlib_error_t e)
{
    return e & 0x3f;
}
static inline __attribute__((__always_inline__)) vlib_error_t
vlib_error_set(u32 node_index, u32 code)
{
    do {
        if ((0 > 0) && !(node_index < (1 << 10))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/error.h", (uword) 61,
                        ((char *) __FUNCTION__), "node_index < (1 << 10)");
        }
    } while (0);
    do {
        if ((0 > 0) && !(code < (1 << 6))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/error.h", (uword) 62,
                        ((char *) __FUNCTION__), "code < (1 << 6)");
        }
    } while (0);
    return (node_index << 6) | code;
}
static inline __attribute__((__always_inline__)) vlib_error_t
vlib_error_set_code(vlib_error_t e, u32 code)
{
    do {
        if ((0 > 0) && !(vlib_error_get_code(e) == 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/error.h", (uword) 69,
                        ((char *) __FUNCTION__), "vlib_error_get_code (e) == 0");
        }
    } while (0);
    do {
        if ((0 > 0) && !(code < (1 << 6))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/error.h", (uword) 70,
                        ((char *) __FUNCTION__), "code < (1 << 6)");
        }
    } while (0);
    e |= code;
    return e;
}
typedef struct {
    u64 *counters;
    u64 *counters_last_clear;
    char **error_strings_heap;
} vlib_error_main_t;
void vlib_register_errors(struct vlib_main_t *vm, u32 node_index, u32 n_errors, char *error_strings[]);
typedef u8 vlib_buffer_free_list_index_t;
enum {
    VLIB_BUFFER_NON_DEFAULT_FREELIST = (1 << (0)),
    VLIB_BUFFER_IS_TRACED            = (1 << (1)),
    VLIB_BUFFER_NEXT_PRESENT         = (1 << (2)),
    VLIB_BUFFER_TOTAL_LENGTH_VALID   = (1 << (3)),
    VLIB_BUFFER_EXT_HDR_VALID        = (1 << (4)),
};
enum {
    VLIB_BUFFER_LOG2_NON_DEFAULT_FREELIST = (0),
    VLIB_BUFFER_LOG2_IS_TRACED            = (1),
    VLIB_BUFFER_LOG2_NEXT_PRESENT         = (2),
    VLIB_BUFFER_LOG2_TOTAL_LENGTH_VALID   = (3),
    VLIB_BUFFER_LOG2_EXT_HDR_VALID        = (4),
};
typedef struct {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    u8 template_start[0];
    i16 current_data;
    u16 current_length;
    u32 flags;
    u32 flow_id;
    u32 next_buffer;
    u8 template_end[0];
    u32 current_config_index;
    vlib_error_t error;
    u8 n_add_refs;
    u8 buffer_pool_index;
    u32 opaque[10];
    u8 cacheline1[0] __attribute__((aligned((1 << 6))));
    u32 trace_index;
    u32 recycle_count;
    u32 total_length_not_including_first_buffer;
    vlib_buffer_free_list_index_t free_list_index;
    u8 align_pad[3];
    u32 opaque2[12];
    u8 cacheline2[0] __attribute__((aligned((1 << 6))));
    u8 pre_data[128];
    u8 data[0];
} vlib_buffer_t;
static inline __attribute__((__always_inline__)) void
vlib_buffer_struct_is_sane(vlib_buffer_t *b)
{
    do {
        if ((0 > 0) && !(sizeof(b[0]) % 64 == 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer.h", (uword) 192,
                        ((char *) __FUNCTION__), "sizeof (b[0]) % 64 == 0");
        }
    } while (0);
    do {
        if ((0 > 0) && !(b->pre_data + 128 == b->data)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer.h", (uword) 195,
                        ((char *) __FUNCTION__), "b->pre_data + VLIB_BUFFER_PRE_DATA_SIZE == b->data");
        }
    } while (0);
}
static inline __attribute__((__always_inline__)) void *
vlib_buffer_get_current(vlib_buffer_t *b)
{
    do {
        if ((0 > 0) && !((signed) b->current_data >= (signed) -128)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer.h", (uword) 208,
                        ((char *) __FUNCTION__), "(signed) b->current_data >= (signed) -VLIB_BUFFER_PRE_DATA_SIZE");
        }
    } while (0);
    return b->data + b->current_data;
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_advance(vlib_buffer_t *b, word l)
{
    do {
        if ((0 > 0) && !(b->current_length >= l)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer.h", (uword) 220,
                        ((char *) __FUNCTION__), "b->current_length >= l");
        }
    } while (0);
    b->current_data += l;
    b->current_length -= l;
    do {
        if ((0 > 0) && !((b->flags & VLIB_BUFFER_NEXT_PRESENT) == 0 || b->current_length >= (128))) {
            _clib_error(
                CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer.h", (uword) 225,
                ((char *) __FUNCTION__),
                "(b->flags & VLIB_BUFFER_NEXT_PRESENT) == 0 || b->current_length >= VLIB_BUFFER_MIN_CHAIN_SEG_SIZE");
        }
    } while (0);
}
static inline __attribute__((__always_inline__)) u8
vlib_buffer_has_space(vlib_buffer_t *b, word l)
{
    return b->current_length >= l;
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_reset(vlib_buffer_t *b)
{
    b->current_length += ({
        __typeof__(b->current_data) _x = (b->current_data);
        __typeof__(0) _y               = (0);
        _x > _y ? _x : _y;
    });
    b->current_data = 0;
}
static inline __attribute__((__always_inline__)) void *
vlib_get_buffer_opaque(vlib_buffer_t *b)
{
    return (void *) b->opaque;
}
static inline __attribute__((__always_inline__)) void *
vlib_get_buffer_opaque2(vlib_buffer_t *b)
{
    return (void *) b->opaque2;
}
static inline __attribute__((__always_inline__)) u8 *
vlib_buffer_get_tail(vlib_buffer_t *b)
{
    return b->data + b->current_data + b->current_length;
}
static inline __attribute__((__always_inline__)) void *
vlib_buffer_put_uninit(vlib_buffer_t *b, u8 size)
{
    void *p = vlib_buffer_get_tail(b);
    b->current_length += size;
    return p;
}
static inline __attribute__((__always_inline__)) void *
vlib_buffer_push_uninit(vlib_buffer_t *b, u8 size)
{
    do {
        if ((0 > 0) && !(b->current_data + 128 >= size)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer.h", (uword) 307,
                        ((char *) __FUNCTION__), "b->current_data + VLIB_BUFFER_PRE_DATA_SIZE >= size");
        }
    } while (0);
    b->current_data -= size;
    b->current_length += size;
    return vlib_buffer_get_current(b);
}
static inline __attribute__((__always_inline__)) void *
vlib_buffer_make_headroom(vlib_buffer_t *b, u8 size)
{
    do {
        if ((0 > 0) && !(b->current_data + 128 >= size)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer.h", (uword) 322,
                        ((char *) __FUNCTION__), "b->current_data + VLIB_BUFFER_PRE_DATA_SIZE >= size");
        }
    } while (0);
    b->current_data += size;
    return vlib_buffer_get_current(b);
}
static inline __attribute__((__always_inline__)) void *
vlib_buffer_pull(vlib_buffer_t *b, u8 size)
{
    if (b->current_length + 128 < size)
        return 0;
    void *data = vlib_buffer_get_current(b);
    vlib_buffer_advance(b, size);
    return data;
}
struct vlib_main_t;
typedef struct vlib_buffer_free_list_t {
    vlib_buffer_t buffer_init_template;
    vlib_buffer_free_list_index_t index;
    u32 n_data_bytes;
    u32 min_n_buffers_each_alloc;
    u32 n_alloc;
    u32 *buffers;
    u8 buffer_pool_index;
    u8 *name;
    void (*buffer_init_function)(struct vlib_main_t *vm, struct vlib_buffer_free_list_t *fl, u32 *buffers, u32 n_buffers);
    uword buffer_init_function_opaque;
} __attribute__((aligned(16))) vlib_buffer_free_list_t;
typedef uword(vlib_buffer_fill_free_list_cb_t)(struct vlib_main_t *vm, vlib_buffer_free_list_t *fl,
                                               uword min_free_buffers);
typedef void(vlib_buffer_free_cb_t)(struct vlib_main_t *vm, u32 *buffers, u32 n_buffers);
typedef void(vlib_buffer_free_no_next_cb_t)(struct vlib_main_t *vm, u32 *buffers, u32 n_buffers);
typedef struct {
    vlib_buffer_fill_free_list_cb_t *vlib_buffer_fill_free_list_cb;
    vlib_buffer_free_cb_t *vlib_buffer_free_cb;
    vlib_buffer_free_no_next_cb_t *vlib_buffer_free_no_next_cb;
    void (*vlib_packet_template_init_cb)(struct vlib_main_t *vm, void *t, void *packet_data, uword n_packet_data_bytes,
                                         uword min_n_buffers_each_physmem_alloc, u8 *name);
    void (*vlib_buffer_delete_free_list_cb)(struct vlib_main_t *vm, vlib_buffer_free_list_index_t free_list_index);
} vlib_buffer_callbacks_t;
extern vlib_buffer_callbacks_t *vlib_buffer_callbacks;
typedef struct {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    uword start;
    uword size;
    uword log2_page_size;
    vlib_physmem_region_index_t physmem_region;
    u32 *buffers;
    u16 buffer_size;
    uword buffers_per_page;
    uword n_elts;
    uword n_used;
    uword next_clear;
    uword *bitmap;
    clib_spinlock_t lock;
} vlib_buffer_pool_t;
typedef struct {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    uword buffer_mem_start;
    uword buffer_mem_size;
    vlib_buffer_pool_t *buffer_pools;
    u32 (*buffer_free_callback)(struct vlib_main_t *vm, u32 *buffers, u32 n_buffers, u32 follow_buffer_next);
    uword *free_list_by_size;
    uword *buffer_known_hash;
    clib_spinlock_t buffer_known_hash_lockp;
    vlib_buffer_callbacks_t cb;
    int callbacks_registered;
} vlib_buffer_main_t;
extern vlib_buffer_main_t buffer_main;
static inline __attribute__((__always_inline__)) vlib_buffer_pool_t *
vlib_buffer_pool_get(u8 buffer_pool_index)
{
    vlib_buffer_main_t *bm = &buffer_main;
    return ({
        do {
            if ((0 > 0) &&
                !((buffer_pool_index) < ((bm->buffer_pools) ? (((vec_header_t *) (bm->buffer_pools) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer.h", (uword) 465,
                            ((char *) __FUNCTION__), "(buffer_pool_index) < vec_len (bm->buffer_pools)");
            }
        } while (0);
        (bm->buffer_pools) + (buffer_pool_index);
    });
}
u8 vlib_buffer_pool_create(struct vlib_main_t *vm, vlib_physmem_region_index_t region, u16 buffer_size);
clib_error_t *vlib_buffer_main_init(struct vlib_main_t *vm);
typedef struct {
    struct vlib_main_t *vlib_main;
    u32 first_buffer, last_buffer;
    union {
        struct {
            u32 n_total_data_bytes;
            u32 max_n_data_bytes_per_chain;
            u32 next_index;
            vlib_buffer_free_list_index_t free_list_index;
        } tx;
        struct {
            u32 *buffer_fifo;
            uword ready_one_time_event;
        } rx;
    };
} vlib_serialize_buffer_main_t;
void serialize_open_vlib_buffer(serialize_main_t *m, struct vlib_main_t *vm, vlib_serialize_buffer_main_t *sm);
void unserialize_open_vlib_buffer(serialize_main_t *m, struct vlib_main_t *vm, vlib_serialize_buffer_main_t *sm);
u32 serialize_close_vlib_buffer(serialize_main_t *m);
void unserialize_close_vlib_buffer(serialize_main_t *m);
void *vlib_set_buffer_free_callback(struct vlib_main_t *vm, void *fp);
static inline __attribute__((__always_inline__)) u32
serialize_vlib_buffer_n_bytes(serialize_main_t *m)
{
    serialize_stream_t *s = &m->stream;
    vlib_serialize_buffer_main_t *sm =
        ((vlib_serialize_buffer_main_t *) (clib_address_t)(m->stream.data_function_opaque));
    return sm->tx.n_total_data_bytes + s->current_buffer_index +
           ((s->overflow_buffer) ? (((vec_header_t *) (s->overflow_buffer) - 1)->len) : 0);
}
struct vlib_cli_command_t;
typedef struct {
    u32 min_char;
    uword **bitmaps;
} vlib_cli_parse_position_t;
typedef struct {
    u8 *name;
    u32 index;
} vlib_cli_sub_command_t;
typedef struct {
    u8 *name;
    u32 rule_index;
    u32 command_index;
} vlib_cli_sub_rule_t;
typedef struct {
    char *name;
    char *short_help;
    char *long_help;
    uword data_size;
    unformat_function_t *unformat_function;
    uword unformat_function_arg[2];
} vlib_cli_parse_rule_t;
typedef clib_error_t *(vlib_cli_command_function_t)(struct vlib_main_t *vm, unformat_input_t *input,
                                                    struct vlib_cli_command_t *cmd);
typedef struct vlib_cli_command_t {
    char *path;
    char *short_help;
    char *long_help;
    vlib_cli_command_function_t *function;
    uword function_arg;
    uword is_mp_safe;
    vlib_cli_sub_command_t *sub_commands;
    uword *sub_command_index_by_name;
    vlib_cli_parse_position_t *sub_command_positions;
    uword *sub_rule_index_by_name;
    vlib_cli_sub_rule_t *sub_rules;
    struct vlib_cli_command_t *next_cli_command;
} vlib_cli_command_t;
typedef void(vlib_cli_output_function_t)(uword arg, u8 *buffer, uword buffer_bytes);
typedef struct {
    vlib_cli_command_t *commands;
    uword *command_index_by_path;
    vlib_cli_parse_rule_t *parse_rules;
    uword *parse_rule_index_by_name;
    void **parse_rule_data;
    vlib_cli_command_t *cli_command_registrations;
} vlib_cli_main_t;
void vlib_cli_output(struct vlib_main_t *vm, char *fmt, ...);
void vlib_cli_input(struct vlib_main_t *vm, unformat_input_t *input, vlib_cli_output_function_t *function,
                    uword function_arg);
clib_error_t *vlib_cli_register(struct vlib_main_t *vm, vlib_cli_command_t *c);
clib_error_t *vlib_cli_register_parse_rule(struct vlib_main_t *vm, vlib_cli_parse_rule_t *c);
uword unformat_vlib_cli_sub_input(unformat_input_t *i, va_list *args);
u8 **vlib_cli_get_possible_completions(u8 *input_str);
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
typedef uint64_t counter_t;
typedef struct {
    counter_t packets;
    counter_t bytes;
} vlib_counter_t;
typedef struct {
    counter_t **counters;
    counter_t *value_at_last_serialize;
    u32 last_incremental_serialize_index;
    char *name;
    char *stat_segment_name;
} vlib_simple_counter_main_t;
u32 vlib_simple_counter_n_counters(const vlib_simple_counter_main_t *cm);
static inline __attribute__((__always_inline__)) void
vlib_increment_simple_counter(vlib_simple_counter_main_t *cm, u32 thread_index, u32 index, u64 increment)
{
    counter_t *my_counters;
    my_counters = cm->counters[thread_index];
    my_counters[index] += increment;
}
static inline __attribute__((__always_inline__)) counter_t
vlib_get_simple_counter(vlib_simple_counter_main_t *cm, u32 index)
{
    counter_t *my_counters;
    counter_t v;
    int i;
    do {
        if ((0 > 0) && !(index < vlib_simple_counter_n_counters(cm))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/counter.h", (uword) 103,
                        ((char *) __FUNCTION__), "index < vlib_simple_counter_n_counters (cm)");
        }
    } while (0);
    v = 0;
    for (i = 0; i < ((cm->counters) ? (((vec_header_t *) (cm->counters) - 1)->len) : 0); i++) {
        my_counters = cm->counters[i];
        v += my_counters[index];
    }
    return v;
}
static inline __attribute__((__always_inline__)) void
vlib_zero_simple_counter(vlib_simple_counter_main_t *cm, u32 index)
{
    counter_t *my_counters;
    int i;
    do {
        if ((0 > 0) && !(index < vlib_simple_counter_n_counters(cm))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/counter.h", (uword) 128,
                        ((char *) __FUNCTION__), "index < vlib_simple_counter_n_counters (cm)");
        }
    } while (0);
    for (i = 0; i < ((cm->counters) ? (((vec_header_t *) (cm->counters) - 1)->len) : 0); i++) {
        my_counters        = cm->counters[i];
        my_counters[index] = 0;
    }
}
static inline __attribute__((__always_inline__)) void
vlib_counter_add(vlib_counter_t *a, vlib_counter_t *b)
{
    a->packets += b->packets;
    a->bytes += b->bytes;
}
static inline __attribute__((__always_inline__)) void
vlib_counter_sub(vlib_counter_t *a, vlib_counter_t *b)
{
    do {
        if ((0 > 0) && !(a->packets >= b->packets)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/counter.h", (uword) 156,
                        ((char *) __FUNCTION__), "a->packets >= b->packets");
        }
    } while (0);
    do {
        if ((0 > 0) && !(a->bytes >= b->bytes)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/counter.h", (uword) 157,
                        ((char *) __FUNCTION__), "a->bytes >= b->bytes");
        }
    } while (0);
    a->packets -= b->packets;
    a->bytes -= b->bytes;
}
static inline __attribute__((__always_inline__)) void
vlib_counter_zero(vlib_counter_t *a)
{
    a->packets = a->bytes = 0;
}
typedef struct {
    vlib_counter_t **counters;
    vlib_counter_t *value_at_last_serialize;
    u32 last_incremental_serialize_index;
    char *name;
    char *stat_segment_name;
} vlib_combined_counter_main_t;
u32 vlib_combined_counter_n_counters(const vlib_combined_counter_main_t *cm);
void vlib_clear_simple_counters(vlib_simple_counter_main_t *cm);
void vlib_clear_combined_counters(vlib_combined_counter_main_t *cm);
static inline __attribute__((__always_inline__)) void
vlib_increment_combined_counter(vlib_combined_counter_main_t *cm, u32 thread_index, u32 index, u64 n_packets, u64 n_bytes)
{
    vlib_counter_t *my_counters;
    my_counters = cm->counters[thread_index];
    my_counters[index].packets += n_packets;
    my_counters[index].bytes += n_bytes;
}
static inline __attribute__((__always_inline__)) void
vlib_prefetch_combined_counter(const vlib_combined_counter_main_t *cm, u32 thread_index, u32 index)
{
    vlib_counter_t *cpu_counters;
    cpu_counters = cm->counters[thread_index];
    do {
        void *_addr = (cpu_counters + index);
        do {
            if ((0 > 0) && !(((1 << 6)) <= 4 * (1 << 6))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/counter.h", (uword) 228,
                            ((char *) __FUNCTION__), "((1 << 6)) <= 4*CLIB_CACHE_LINE_BYTES");
            }
        } while (0);
        if (((1 << 6)) > (0) * (1 << 6))
            __builtin_prefetch(_addr + (0) * (1 << 6), 1, 3);
        ;
        if (((1 << 6)) > (1) * (1 << 6))
            __builtin_prefetch(_addr + (1) * (1 << 6), 1, 3);
        ;
        if (((1 << 6)) > (2) * (1 << 6))
            __builtin_prefetch(_addr + (2) * (1 << 6), 1, 3);
        ;
        if (((1 << 6)) > (3) * (1 << 6))
            __builtin_prefetch(_addr + (3) * (1 << 6), 1, 3);
        ;
    } while (0);
}
static inline void
vlib_get_combined_counter(const vlib_combined_counter_main_t *cm, u32 index, vlib_counter_t *result)
{
    vlib_counter_t *my_counters, *counter;
    int i;
    result->packets = 0;
    result->bytes   = 0;
    for (i = 0; i < ((cm->counters) ? (((vec_header_t *) (cm->counters) - 1)->len) : 0); i++) {
        my_counters = cm->counters[i];
        counter     = ({
            do {
                if ((0 > 0) && !((index) < ((my_counters) ? (((vec_header_t *) (my_counters) -1)->len) : 0))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/counter.h", (uword) 256,
                                ((char *) __FUNCTION__), "(index) < vec_len (my_counters)");
                }
            } while (0);
            (my_counters) + (index);
        });
        result->packets += counter->packets;
        result->bytes += counter->bytes;
    }
}
static inline __attribute__((__always_inline__)) void
vlib_zero_combined_counter(vlib_combined_counter_main_t *cm, u32 index)
{
    vlib_counter_t *my_counters, *counter;
    int i;
    for (i = 0; i < ((cm->counters) ? (((vec_header_t *) (cm->counters) - 1)->len) : 0); i++) {
        my_counters      = cm->counters[i];
        counter          = ({
            do {
                if ((0 > 0) && !((index) < ((my_counters) ? (((vec_header_t *) (my_counters) -1)->len) : 0))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/counter.h", (uword) 278,
                                ((char *) __FUNCTION__), "(index) < vec_len (my_counters)");
                }
            } while (0);
            (my_counters) + (index);
        });
        counter->packets = 0;
        counter->bytes   = 0;
    }
}
void vlib_validate_simple_counter(vlib_simple_counter_main_t *cm, u32 index);
void vlib_validate_combined_counter(vlib_combined_counter_main_t *cm, u32 index);
serialize_function_t serialize_vlib_simple_counter_main, unserialize_vlib_simple_counter_main;
serialize_function_t serialize_vlib_combined_counter_main, unserialize_vlib_combined_counter_main;
typedef clib_error_t *(vlib_init_function_t)(struct vlib_main_t *vm);
typedef struct _vlib_init_function_list_elt {
    struct _vlib_init_function_list_elt *next_init_function;
    vlib_init_function_t *f;
} _vlib_init_function_list_elt_t;
typedef clib_error_t *(vlib_config_function_t)(struct vlib_main_t *vm, unformat_input_t *input);
typedef struct vlib_config_function_runtime_t {
    vlib_config_function_t *function;
    unformat_input_t input;
    struct vlib_config_function_runtime_t *next_registration;
    u8 is_early;
    char name[32];
} vlib_config_function_runtime_t;
clib_error_t *vlib_call_all_init_functions(struct vlib_main_t *vm);
clib_error_t *vlib_call_all_config_functions(struct vlib_main_t *vm, unformat_input_t *input, int is_early);
clib_error_t *vlib_call_all_main_loop_enter_functions(struct vlib_main_t *vm);
clib_error_t *vlib_call_all_main_loop_exit_functions(struct vlib_main_t *vm);
clib_error_t *vlib_call_init_exit_functions(struct vlib_main_t *vm, _vlib_init_function_list_elt_t *head, int call_once);
void vlib_node_cli_reference(void);
void vlib_trace_cli_reference(void);
static __inline unsigned int
__get_cpuid_max(unsigned int __ext, unsigned int *__sig)
{
    unsigned int __eax, __ebx, __ecx, __edx;
    __asm__("cpuid\n\t" : "=a"(__eax), "=b"(__ebx), "=c"(__ecx), "=d"(__edx) : "0"(__ext));
    if (__sig)
        *__sig = __ebx;
    return __eax;
}
static __inline int
__get_cpuid(unsigned int __leaf, unsigned int *__eax, unsigned int *__ebx, unsigned int *__ecx, unsigned int *__edx)
{
    unsigned int __ext      = __leaf & 0x80000000;
    unsigned int __maxlevel = __get_cpuid_max(__ext, 0);
    if (__maxlevel == 0 || __maxlevel < __leaf)
        return 0;
    __asm__("cpuid\n\t" : "=a"(*__eax), "=b"(*__ebx), "=c"(*__ecx), "=d"(*__edx) : "0"(__leaf));
    return 1;
}
static __inline int
__get_cpuid_count(unsigned int __leaf, unsigned int __subleaf, unsigned int *__eax, unsigned int *__ebx,
                  unsigned int *__ecx, unsigned int *__edx)
{
    unsigned int __ext      = __leaf & 0x80000000;
    unsigned int __maxlevel = __get_cpuid_max(__ext, 0);
    if (__maxlevel == 0 || __maxlevel < __leaf)
        return 0;
    __asm__("cpuid\n\t" : "=a"(*__eax), "=b"(*__ebx), "=c"(*__ecx), "=d"(*__edx) : "0"(__leaf), "2"(__subleaf));
    return 1;
}
static inline int
clib_get_cpuid(const u32 lev, u32 *eax, u32 *ebx, u32 *ecx, u32 *edx)
{
    if ((u32) __get_cpuid_max(0x80000000 & lev, 0) < lev)
        return 0;
    if (lev == 7)

        __asm__("cpuid\n\t" : "=a"(*eax), "=b"(*ebx), "=c"(*ecx), "=d"(*edx) : "0"(lev), "2"(0));
    else

        __asm__("cpuid\n\t" : "=a"(*eax), "=b"(*ebx), "=c"(*ecx), "=d"(*edx) : "0"(lev));
    return 1;
}
static inline int
clib_cpu_supports_sse3()
{
    u32 __attribute__((unused)) eax, ebx = 0, ecx = 0, edx = 0;
    clib_get_cpuid(1, &eax, &ebx, &ecx, &edx);
    return ((ecx & (1 << 0)) != 0);
}
static inline int
clib_cpu_supports_ssse3()
{
    u32 __attribute__((unused)) eax, ebx = 0, ecx = 0, edx = 0;
    clib_get_cpuid(1, &eax, &ebx, &ecx, &edx);
    return ((ecx & (1 << 9)) != 0);
}
static inline int
clib_cpu_supports_sse41()
{
    u32 __attribute__((unused)) eax, ebx = 0, ecx = 0, edx = 0;
    clib_get_cpuid(1, &eax, &ebx, &ecx, &edx);
    return ((ecx & (1 << 19)) != 0);
}
static inline int
clib_cpu_supports_sse42()
{
    u32 __attribute__((unused)) eax, ebx = 0, ecx = 0, edx = 0;
    clib_get_cpuid(1, &eax, &ebx, &ecx, &edx);
    return ((ecx & (1 << 20)) != 0);
}
static inline int
clib_cpu_supports_avx()
{
    u32 __attribute__((unused)) eax, ebx = 0, ecx = 0, edx = 0;
    clib_get_cpuid(1, &eax, &ebx, &ecx, &edx);
    return ((ecx & (1 << 28)) != 0);
}
static inline int
clib_cpu_supports_avx2()
{
    u32 __attribute__((unused)) eax, ebx = 0, ecx = 0, edx = 0;
    clib_get_cpuid(7, &eax, &ebx, &ecx, &edx);
    return ((ebx & (1 << 5)) != 0);
}
static inline int
clib_cpu_supports_avx512f()
{
    u32 __attribute__((unused)) eax, ebx = 0, ecx = 0, edx = 0;
    clib_get_cpuid(7, &eax, &ebx, &ecx, &edx);
    return ((ebx & (1 << 16)) != 0);
}
static inline int
clib_cpu_supports_x86_aes()
{
    u32 __attribute__((unused)) eax, ebx = 0, ecx = 0, edx = 0;
    clib_get_cpuid(1, &eax, &ebx, &ecx, &edx);
    return ((ecx & (1 << 25)) != 0);
}
static inline int
clib_cpu_supports_sha()
{
    u32 __attribute__((unused)) eax, ebx = 0, ecx = 0, edx = 0;
    clib_get_cpuid(7, &eax, &ebx, &ecx, &edx);
    return ((ebx & (1 << 29)) != 0);
}
static inline int
clib_cpu_supports_invariant_tsc()
{
    u32 __attribute__((unused)) eax, ebx = 0, ecx = 0, edx = 0;
    clib_get_cpuid(0x80000007, &eax, &ebx, &ecx, &edx);
    return ((edx & (1 << 8)) != 0);
}
static inline int
clib_cpu_supports_fp()
{
    return 0;
}
static inline int
clib_cpu_supports_asimd()
{
    return 0;
}
static inline int
clib_cpu_supports_evtstrm()
{
    return 0;
}
static inline int
clib_cpu_supports_aarch64_aes()
{
    return 0;
}
static inline int
clib_cpu_supports_pmull()
{
    return 0;
}
static inline int
clib_cpu_supports_sha1()
{
    return 0;
}
static inline int
clib_cpu_supports_sha2()
{
    return 0;
}
static inline int
clib_cpu_supports_crc32()
{
    return 0;
}
static inline int
clib_cpu_supports_atomics()
{
    return 0;
}
static inline int
clib_cpu_supports_fphp()
{
    return 0;
}
static inline int
clib_cpu_supports_asimdhp()
{
    return 0;
}
static inline int
clib_cpu_supports_cpuid()
{
    return 0;
}
static inline int
clib_cpu_supports_asimdrdm()
{
    return 0;
}
static inline int
clib_cpu_supports_jscvt()
{
    return 0;
}
static inline int
clib_cpu_supports_fcma()
{
    return 0;
}
static inline int
clib_cpu_supports_lrcpc()
{
    return 0;
}
static inline int
clib_cpu_supports_dcpop()
{
    return 0;
}
static inline int
clib_cpu_supports_sha3()
{
    return 0;
}
static inline int
clib_cpu_supports_sm3()
{
    return 0;
}
static inline int
clib_cpu_supports_sm4()
{
    return 0;
}
static inline int
clib_cpu_supports_asimddp()
{
    return 0;
}
static inline int
clib_cpu_supports_sha512()
{
    return 0;
}
static inline int
clib_cpu_supports_sve()
{
    return 0;
}
static inline int
clib_cpu_supports_aes()
{
    return 0;
}
static inline int
clib_cpu_march_priority_avx512()
{
    if (clib_cpu_supports_avx512f())
        return 20;
    return -1;
}
static inline int
clib_cpu_march_priority_avx2()
{
    if (clib_cpu_supports_avx2())
        return 10;
    return -1;
}
static inline u32
clib_cpu_implementer()
{
    char buf[128];
    static u32 implementer = -1;
    if (-1 != implementer)
        return implementer;
    FILE *fp = fopen("/proc/cpuinfo", "r");
    if (!fp)
        return implementer;
    while (!feof(fp)) {
        if (!fgets(buf, sizeof(buf), fp))
            break;
        buf[127] = '\0';
        if (strstr(buf, "CPU implementer"))
            implementer = (u32) strtol(memchr(buf, ':', 128) + 2, ((void *) 0), 0);
        if (-1 != implementer)
            break;
    }
    fclose(fp);
    return implementer;
}
static inline u32
clib_cpu_part()
{
    char buf[128];
    static u32 part = -1;
    if (-1 != part)
        return part;
    FILE *fp = fopen("/proc/cpuinfo", "r");
    if (!fp)
        return part;
    while (!feof(fp)) {
        if (!fgets(buf, sizeof(buf), fp))
            break;
        buf[127] = '\0';
        if (strstr(buf, "CPU part"))
            part = (u32) strtol(memchr(buf, ':', 128) + 2, ((void *) 0), 0);
        if (-1 != part)
            break;
    }
    fclose(fp);
    return part;
}
static inline int
clib_cpu_march_priority_thunderx2t99()
{
    if ((0x43 == clib_cpu_implementer()) && (0x0af == clib_cpu_part()))
        return 20;
    return -1;
}
static inline int
clib_cpu_march_priority_qdf24xx()
{
    if ((0x51 == clib_cpu_implementer()) && (0xc00 == clib_cpu_part()))
        return 20;
    return -1;
}
static inline int
clib_cpu_march_priority_cortexa72()
{
    if ((0x41 == clib_cpu_implementer()) && (0xd08 == clib_cpu_part()))
        return 10;
    return -1;
}
format_function_t format_cpu_uarch;
format_function_t format_cpu_model_name;
format_function_t format_cpu_flags;
static inline __attribute__((__always_inline__)) u32
random_u32(u32 *seed)
{
    *seed = (1664525 * *seed) + 1013904223;
    return *seed;
}
int test_random_main(unformat_input_t *input);
static inline __attribute__((__always_inline__)) u32
random_u32_max(void)
{
    return 0xffffffff;
}
static inline __attribute__((__always_inline__)) uword
random_default_seed(void)
{
    return getpid();
}
static inline __attribute__((__always_inline__)) u64
random_u64(u64 *seed)
{
    *seed = 6364136223846793005ULL * *seed + 1442695040888963407ULL;
    return *seed;
}
static inline __attribute__((__always_inline__)) uword
random_uword(u32 *seed)
{
    if (sizeof(uword) == sizeof(u64))
        return random_u64((u64 *) seed);
    else
        return random_u32(seed);
}
static inline __attribute__((__always_inline__)) f64
random_f64(u32 *seed)
{
    return (f64) random_u32(seed) / (f64) random_u32_max();
}
static inline __attribute__((__always_inline__)) u8 *
random_string(u32 *seed, uword len)
{
    u8 *alphabet = (u8 *) "abcdefghijklmnopqrstuvwxyz";
    u8 *s        = 0;
    word i;
    do {
        word _vec_n = (len);
        word _vec_l = ((s) ? (((vec_header_t *) (s) -1)->len) : 0);
        s           = _vec_resize_inline((s), _vec_n, (_vec_l + _vec_n) * sizeof((s)[0]), (0), ({
                                   __typeof__((__alignof__(((s))[0]))) _x = ((__alignof__(((s))[0])));
                                   __typeof__(((0))) _y                   = (((0)));
                                   _x > _y ? _x : _y;
                               }));
    } while (0);
    for (i = 0; i < len; i++)
        s[i] = alphabet[random_u32(seed) % 26];
    return s;
}
f64 clib_chisquare(u64 *values);
static inline __attribute__((__always_inline__)) uword
count_set_bits(uword x)
{
    const uword c1 = 0x5555555555555555;
    const uword c2 = 0x3333333333333333;
    const uword c3 = 0x0f0f0f0f0f0f0f0f;
    x              = x - ((x >> (uword) 1) & c1);
    x              = (x & c2) + ((x >> (uword) 2) & c2);
    x              = (x + (x >> (uword) 4)) & c3;
    x              = x + (x >> (uword) 8);
    x              = x + (x >> (uword) 16);
    x              = x + (x >> (uword) 32);
    return x & (2 * (8 * sizeof(uword)) - 1);
}
typedef struct {
    uword masks[1 + 6];
} compress_main_t;
static inline __attribute__((__always_inline__)) void
compress_init(compress_main_t *cm, uword mask)
{
    uword q, m, zm, n, i;
    m            = ~mask;
    zm           = mask;
    cm->masks[0] = mask;
    for (i = 0; i < 6; i++) {
        q = m;
        m ^= m << 1;
        m ^= m << 2;
        m ^= m << 4;
        m ^= m << 8;
        m ^= m << 16;
        m ^= m << (uword) 32;
        cm->masks[1 + i] = n = (m << 1) & zm;
        m                    = q & ~m;
        q                    = zm & n;
        zm                   = zm ^ q ^ (q >> (1 << i));
    }
}
static inline __attribute__((__always_inline__)) uword
compress_bits(compress_main_t *cm, uword x)
{
    uword q, r;
    r = x & cm->masks[0];
    q = r & cm->masks[1];
    r ^= q ^ (q >> 1);
    q = r & cm->masks[2];
    r ^= q ^ (q >> 2);
    q = r & cm->masks[3];
    r ^= q ^ (q >> 4);
    q = r & cm->masks[4];
    r ^= q ^ (q >> 8);
    q = r & cm->masks[5];
    r ^= q ^ (q >> 16);
    q = r & cm->masks[6];
    r ^= q ^ (q >> (uword) 32);
    return r;
}
static inline __attribute__((__always_inline__)) uword
rotate_left(uword x, uword i)
{
    return (x << i) | (x >> ((8 * sizeof(i)) - i));
}
static inline __attribute__((__always_inline__)) uword
rotate_right(uword x, uword i)
{
    return (x >> i) | (x << ((8 * sizeof(i)) - i));
}
static inline __attribute__((__always_inline__)) uword
next_with_same_number_of_set_bits(uword x)
{
    uword smallest, ripple, ones;
    smallest = x & -x;
    ripple   = x + smallest;
    ones     = x ^ ripple;
    ones     = ones >> (2 + log2_first_set(x));
    return ripple | ones;
}
typedef uword clib_bitmap_t;
static inline __attribute__((__always_inline__)) uword
clib_bitmap_is_zero(uword *ai)
{
    uword i;
    for (i = 0; i < ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0); i++)
        if (ai[i] != 0)
            return 0;
    return 1;
}
static inline __attribute__((__always_inline__)) uword
clib_bitmap_is_equal(uword *a, uword *b)
{
    uword i;
    if (((a) ? (((vec_header_t *) (a) -1)->len) : 0) != ((b) ? (((vec_header_t *) (b) -1)->len) : 0))
        return 0;
    for (i = 0; i < ((a) ? (((vec_header_t *) (a) -1)->len) : 0); i++)
        if (a[i] != b[i])
            return 0;
    return 1;
}
static inline __attribute__((__always_inline__)) uword *
_clib_bitmap_remove_trailing_zeros(uword *a)
{
    word i;
    if (a) {
        for (i = (((vec_header_t *) (a) -1)->len) - 1; i >= 0; i--)
            if (a[i] != 0)
                break;
        (((vec_header_t *) (a) -1)->len) = i + 1;
    }
    return a;
}
static inline __attribute__((__always_inline__)) uword
clib_bitmap_set_no_check(uword *a, uword i, uword new_value)
{
    uword i0  = i / (8 * sizeof(a[0]));
    uword i1  = i % (8 * sizeof(a[0]));
    uword bit = (uword) 1 << i1;
    uword ai, old_value;
    ai        = a[i0];
    old_value = (ai & bit) != 0;
    ai &= ~bit;
    ai |= ((uword)(new_value != 0)) << i1;
    a[i0] = ai;
    return old_value;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_set(uword *ai, uword i, uword value)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    uword a;
    if (value == 0 && i0 >= ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0))
        return ai;
    do {
        _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                           ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = ((i0));
        word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n = (1 + (_vec_i - _vec_l));
                word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                ((ai))      = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                    ((__alignof__(((((ai))))[0])));
                                                __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
        }
    } while (0);
    a = ai[i0];
    a &= ~((uword) 1 << i1);
    a |= ((uword)(value != 0)) << i1;
    ai[i0] = a;
    if (a == 0)
        ai = _clib_bitmap_remove_trailing_zeros(ai);
    return ai;
}
static inline __attribute__((__always_inline__)) uword
clib_bitmap_get(uword *ai, uword i)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    return i0 < ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0) && 0 != ((ai[i0] >> i1) & 1);
}
static inline __attribute__((__always_inline__)) uword
clib_bitmap_get_no_check(uword *ai, uword i)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    return 0 != ((ai[i0] >> i1) & 1);
}
static inline __attribute__((__always_inline__)) uword
clib_bitmap_get_multiple_no_check(uword *ai, uword i, uword n_bits)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    do {
        if ((0 > 0) && !(i1 + n_bits <= (8 * sizeof(uword)))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/bitmap.h", (uword) 224,
                        ((char *) __FUNCTION__), "i1 + n_bits <= BITS (uword)");
        }
    } while (0);
    return 0 != ((ai[i0] >> i1) & pow2_mask(n_bits));
}
static inline __attribute__((__always_inline__)) uword
clib_bitmap_get_multiple(uword *bitmap, uword i, uword n_bits)
{
    uword i0, i1, result;
    uword l = ((bitmap) ? (((vec_header_t *) (bitmap) -1)->len) : 0);
    do {
        if ((0 > 0) && !(n_bits <= (8 * sizeof(result)))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/bitmap.h", (uword) 240,
                        ((char *) __FUNCTION__), "n_bits <= BITS (result)");
        }
    } while (0);
    i0     = i / (8 * sizeof(bitmap[0]));
    i1     = i % (8 * sizeof(bitmap[0]));
    result = 0;
    if (i0 < l) {
        result |= (bitmap[i0] >> i1);
        if (n_bits < (8 * sizeof(bitmap[0])))
            result &= (((uword) 1 << n_bits) - 1);
    }
    i0++;
    if (i1 + n_bits > (8 * sizeof(bitmap[0])) && i0 < l) {
        n_bits -= (8 * sizeof(bitmap[0])) - i1;
        result |= (bitmap[i0] & (((uword) 1 << n_bits) - 1)) << ((8 * sizeof(bitmap[0])) - i1);
    }
    return result;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_set_multiple(uword *bitmap, uword i, uword value, uword n_bits)
{
    uword i0, i1, l, t, m;
    do {
        if ((0 > 0) && !(n_bits <= (8 * sizeof(value)))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/bitmap.h", (uword) 279,
                        ((char *) __FUNCTION__), "n_bits <= BITS (value)");
        }
    } while (0);
    i0 = i / (8 * sizeof(bitmap[0]));
    i1 = i % (8 * sizeof(bitmap[0]));
    do {
        _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((bitmap)[0])) == 0) ||
                           ((sizeof((bitmap)[0]) % sizeof(uword)) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = (((i + n_bits) / (8 * sizeof(bitmap[0]))));
        word _vec_l = (((bitmap)) ? (((vec_header_t *) ((bitmap)) - 1)->len) : 0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n = (1 + (_vec_i - _vec_l));
                word _vec_l = ((((bitmap))) ? (((vec_header_t *) (((bitmap))) - 1)->len) : 0);
                ((bitmap)) =
                    _vec_resize_inline((((bitmap))), _vec_n, (_vec_l + _vec_n) * sizeof((((bitmap)))[0]), ((0)), ({
                                           __typeof__((__alignof__(((((bitmap))))[0]))) _x =
                                               ((__alignof__(((((bitmap))))[0])));
                                           __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                           _x > _y ? _x : _y;
                                       }));
            } while (0);
            memset(((bitmap)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((bitmap))[0]));
        }
    } while (0);
    l = ((bitmap) ? (((vec_header_t *) (bitmap) -1)->len) : 0);
    m = ~0;
    if (n_bits < (8 * sizeof(value)))
        m = (((uword) 1 << n_bits) - 1);
    value &= m;
    t = bitmap[i0];
    t &= ~(m << i1);
    t |= value << i1;
    bitmap[i0] = t;
    i0++;
    if (i1 + n_bits > (8 * sizeof(bitmap[0])) && i0 < l) {
        t = (8 * sizeof(bitmap[0])) - i1;
        value >>= t;
        n_bits -= t;
        t = bitmap[i0];
        m = ((uword) 1 << n_bits) - 1;
        t &= ~m;
        t |= value;
        bitmap[i0] = t;
    }
    return bitmap;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_set_region(uword *bitmap, uword i, uword value, uword n_bits)
{
    uword a0, a1, b0;
    uword i_end, mask;
    a0    = i / (8 * sizeof(bitmap[0]));
    a1    = i % (8 * sizeof(bitmap[0]));
    i_end = i + n_bits;
    b0    = i_end / (8 * sizeof(bitmap[0]));
    do {
        _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((bitmap)[0])) == 0) ||
                           ((sizeof((bitmap)[0]) % sizeof(uword)) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = ((b0));
        word _vec_l = (((bitmap)) ? (((vec_header_t *) ((bitmap)) - 1)->len) : 0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n = (1 + (_vec_i - _vec_l));
                word _vec_l = ((((bitmap))) ? (((vec_header_t *) (((bitmap))) - 1)->len) : 0);
                ((bitmap)) =
                    _vec_resize_inline((((bitmap))), _vec_n, (_vec_l + _vec_n) * sizeof((((bitmap)))[0]), ((0)), ({
                                           __typeof__((__alignof__(((((bitmap))))[0]))) _x =
                                               ((__alignof__(((((bitmap))))[0])));
                                           __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                           _x > _y ? _x : _y;
                                       }));
            } while (0);
            memset(((bitmap)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((bitmap))[0]));
        }
    } while (0);
    mask = n_bits < (8 * sizeof(bitmap[0])) ? pow2_mask(n_bits) : ~0;
    mask <<= a1;
    if (value)
        bitmap[a0] |= mask;
    else
        bitmap[a0] &= ~mask;
    for (a0++; a0 < b0; a0++)
        bitmap[a0] = value ? ~0 : 0;
    if (a0 == b0) {
        word n_bits_left = n_bits - ((8 * sizeof(bitmap[0])) - a1);
        mask             = pow2_mask(n_bits_left);
        if (value)
            bitmap[a0] |= mask;
        else
            bitmap[a0] &= ~mask;
    }
    return bitmap;
}
static inline __attribute__((__always_inline__)) uword
clib_bitmap_first_set(uword *ai)
{
    uword i = 0;
    for (; i < ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0); i++) {
        uword x = ai[i];
        if (x != 0)
            return i * (8 * sizeof(ai[0])) + log2_first_set(x);
    }
    return ~0;
}
static inline __attribute__((__always_inline__)) uword
clib_bitmap_last_set(uword *ai)
{
    uword i;
    for (i = ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0); i > 0; i--) {
        uword x = ai[i - 1];
        if (x != 0) {
            uword first_bit;
            first_bit = __builtin_clzll(x);
            return (i) * (8 * sizeof(ai[0])) - first_bit - 1;
        }
    }
    return ~0;
}
static inline __attribute__((__always_inline__)) uword
clib_bitmap_first_clear(uword *ai)
{
    uword i;
    for (i = 0; i < ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0); i++) {
        uword x = ~ai[i];
        if (x != 0)
            return i * (8 * sizeof(ai[0])) + log2_first_set(x);
    }
    return i * (8 * sizeof(ai[0]));
}
static inline __attribute__((__always_inline__)) uword
clib_bitmap_count_set_bits(uword *ai)
{
    uword i;
    uword n_set = 0;
    for (i = 0; i < ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0); i++)
        n_set += count_set_bits(ai[i]);
    return n_set;
}
static inline __attribute__((__always_inline__)) uword *clib_bitmap_and(uword *ai, uword *bi);
static inline __attribute__((__always_inline__)) uword *clib_bitmap_andnot(uword *ai, uword *bi);
static inline __attribute__((__always_inline__)) uword *clib_bitmap_or(uword *ai, uword *bi);
static inline __attribute__((__always_inline__)) uword *clib_bitmap_or(uword *ai, uword *bi);
static inline __attribute__((__always_inline__)) uword *clib_bitmap_xor(uword *ai, uword *bi);
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_and(uword *ai, uword *bi)
{
    uword i, a, b, bi_len, n_trailing_zeros;
    n_trailing_zeros = 0;
    bi_len           = ((bi) ? (((vec_header_t *) (bi) -1)->len) : 0);
    if (bi_len > 0)
        do {
            _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                               ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                           "vector validate aligned on incorrectly sized object");
            word _vec_i = ((bi_len - 1));
            word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
            if (_vec_i >= _vec_l) {
                do {
                    word _vec_n = (1 + (_vec_i - _vec_l));
                    word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                    ((ai)) = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                    __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                        ((__alignof__(((((ai))))[0])));
                                                    __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                    _x > _y ? _x : _y;
                                                }));
                } while (0);
                memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
            }
        } while (0);
    for (i = 0; i < ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0); i++) {
        a = ai[i];
        b = i < bi_len ? bi[i] : 0;
        do {
            a = a & b;
        } while (0);
        ai[i] = a;
        if (1)
            n_trailing_zeros = a ? 0 : (n_trailing_zeros + 1);
    }
    if (1)
        (((vec_header_t *) (ai) -1)->len) -= n_trailing_zeros;
    return ai;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_andnot(uword *ai, uword *bi)
{
    uword i, a, b, bi_len, n_trailing_zeros;
    n_trailing_zeros = 0;
    bi_len           = ((bi) ? (((vec_header_t *) (bi) -1)->len) : 0);
    if (bi_len > 0)
        do {
            _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                               ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                           "vector validate aligned on incorrectly sized object");
            word _vec_i = ((bi_len - 1));
            word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
            if (_vec_i >= _vec_l) {
                do {
                    word _vec_n = (1 + (_vec_i - _vec_l));
                    word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                    ((ai)) = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                    __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                        ((__alignof__(((((ai))))[0])));
                                                    __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                    _x > _y ? _x : _y;
                                                }));
                } while (0);
                memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
            }
        } while (0);
    for (i = 0; i < ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0); i++) {
        a = ai[i];
        b = i < bi_len ? bi[i] : 0;
        do {
            a = a & ~b;
        } while (0);
        ai[i] = a;
        if (1)
            n_trailing_zeros = a ? 0 : (n_trailing_zeros + 1);
    }
    if (1)
        (((vec_header_t *) (ai) -1)->len) -= n_trailing_zeros;
    return ai;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_or(uword *ai, uword *bi)
{
    uword i, a, b, bi_len, n_trailing_zeros;
    n_trailing_zeros = 0;
    bi_len           = ((bi) ? (((vec_header_t *) (bi) -1)->len) : 0);
    if (bi_len > 0)
        do {
            _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                               ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                           "vector validate aligned on incorrectly sized object");
            word _vec_i = ((bi_len - 1));
            word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
            if (_vec_i >= _vec_l) {
                do {
                    word _vec_n = (1 + (_vec_i - _vec_l));
                    word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                    ((ai)) = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                    __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                        ((__alignof__(((((ai))))[0])));
                                                    __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                    _x > _y ? _x : _y;
                                                }));
                } while (0);
                memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
            }
        } while (0);
    for (i = 0; i < ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0); i++) {
        a = ai[i];
        b = i < bi_len ? bi[i] : 0;
        do {
            a = a | b;
        } while (0);
        ai[i] = a;
        if (0)
            n_trailing_zeros = a ? 0 : (n_trailing_zeros + 1);
    }
    if (0)
        (((vec_header_t *) (ai) -1)->len) -= n_trailing_zeros;
    return ai;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_xor(uword *ai, uword *bi)
{
    uword i, a, b, bi_len, n_trailing_zeros;
    n_trailing_zeros = 0;
    bi_len           = ((bi) ? (((vec_header_t *) (bi) -1)->len) : 0);
    if (bi_len > 0)
        do {
            _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                               ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                           "vector validate aligned on incorrectly sized object");
            word _vec_i = ((bi_len - 1));
            word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
            if (_vec_i >= _vec_l) {
                do {
                    word _vec_n = (1 + (_vec_i - _vec_l));
                    word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                    ((ai)) = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                    __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                        ((__alignof__(((((ai))))[0])));
                                                    __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                    _x > _y ? _x : _y;
                                                }));
                } while (0);
                memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
            }
        } while (0);
    for (i = 0; i < ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0); i++) {
        a = ai[i];
        b = i < bi_len ? bi[i] : 0;
        do {
            a = a ^ b;
        } while (0);
        ai[i] = a;
        if (1)
            n_trailing_zeros = a ? 0 : (n_trailing_zeros + 1);
    }
    if (1)
        (((vec_header_t *) (ai) -1)->len) -= n_trailing_zeros;
    return ai;
}
static inline __attribute__((__always_inline__)) uword *clib_bitmap_dup_and(uword *ai, uword *bi);
static inline __attribute__((__always_inline__)) uword *clib_bitmap_dup_andnot(uword *ai, uword *bi);
static inline __attribute__((__always_inline__)) uword *clib_bitmap_dup_or(uword *ai, uword *bi);
static inline __attribute__((__always_inline__)) uword *clib_bitmap_dup_xor(uword *ai, uword *bi);
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_dup_and(uword *ai, uword *bi)
{
    return clib_bitmap_and(({
                               __typeof__((ai)[0]) *_vec_v = 0;
                               uword _vec_l                = ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0);
                               if (_vec_l > 0) {
                                   do {
                                       word _vec_n = (_vec_l);
                                       word _vec_l = ((_vec_v) ? (((vec_header_t *) (_vec_v) -1)->len) : 0);
                                       _vec_v      = _vec_resize_inline((_vec_v), _vec_n,
                                                                   (_vec_l + _vec_n) * sizeof((_vec_v)[0]), ((0)), ({
                                                                       __typeof__((__alignof__(((_vec_v))[0]))) _x =
                                                                           ((__alignof__(((_vec_v))[0])));
                                                                       __typeof__((((0)))) _y = ((((0))));
                                                                       _x > _y ? _x : _y;
                                                                   }));
                                   } while (0);
                                   memcpy(_vec_v, (ai), _vec_l * sizeof((ai)[0]));
                               }
                               _vec_v;
                           }),
                           bi);
};
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_dup_andnot(uword *ai, uword *bi)
{
    return clib_bitmap_andnot(({
                                  __typeof__((ai)[0]) *_vec_v = 0;
                                  uword _vec_l                = ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0);
                                  if (_vec_l > 0) {
                                      do {
                                          word _vec_n = (_vec_l);
                                          word _vec_l = ((_vec_v) ? (((vec_header_t *) (_vec_v) -1)->len) : 0);
                                          _vec_v      = _vec_resize_inline((_vec_v), _vec_n,
                                                                      (_vec_l + _vec_n) * sizeof((_vec_v)[0]), ((0)), ({
                                                                          __typeof__((__alignof__(((_vec_v))[0]))) _x =
                                                                              ((__alignof__(((_vec_v))[0])));
                                                                          __typeof__((((0)))) _y = ((((0))));
                                                                          _x > _y ? _x : _y;
                                                                      }));
                                      } while (0);
                                      memcpy(_vec_v, (ai), _vec_l * sizeof((ai)[0]));
                                  }
                                  _vec_v;
                              }),
                              bi);
};
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_dup_or(uword *ai, uword *bi)
{
    return clib_bitmap_or(({
                              __typeof__((ai)[0]) *_vec_v = 0;
                              uword _vec_l                = ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0);
                              if (_vec_l > 0) {
                                  do {
                                      word _vec_n = (_vec_l);
                                      word _vec_l = ((_vec_v) ? (((vec_header_t *) (_vec_v) -1)->len) : 0);
                                      _vec_v      = _vec_resize_inline((_vec_v), _vec_n,
                                                                  (_vec_l + _vec_n) * sizeof((_vec_v)[0]), ((0)), ({
                                                                      __typeof__((__alignof__(((_vec_v))[0]))) _x =
                                                                          ((__alignof__(((_vec_v))[0])));
                                                                      __typeof__((((0)))) _y = ((((0))));
                                                                      _x > _y ? _x : _y;
                                                                  }));
                                  } while (0);
                                  memcpy(_vec_v, (ai), _vec_l * sizeof((ai)[0]));
                              }
                              _vec_v;
                          }),
                          bi);
};
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_dup_xor(uword *ai, uword *bi)
{
    return clib_bitmap_xor(({
                               __typeof__((ai)[0]) *_vec_v = 0;
                               uword _vec_l                = ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0);
                               if (_vec_l > 0) {
                                   do {
                                       word _vec_n = (_vec_l);
                                       word _vec_l = ((_vec_v) ? (((vec_header_t *) (_vec_v) -1)->len) : 0);
                                       _vec_v      = _vec_resize_inline((_vec_v), _vec_n,
                                                                   (_vec_l + _vec_n) * sizeof((_vec_v)[0]), ((0)), ({
                                                                       __typeof__((__alignof__(((_vec_v))[0]))) _x =
                                                                           ((__alignof__(((_vec_v))[0])));
                                                                       __typeof__((((0)))) _y = ((((0))));
                                                                       _x > _y ? _x : _y;
                                                                   }));
                                   } while (0);
                                   memcpy(_vec_v, (ai), _vec_l * sizeof((ai)[0]));
                               }
                               _vec_v;
                           }),
                           bi);
};
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_andi(uword *ai, uword i)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    uword a, b;
    do {
        _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                           ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = ((i0));
        word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n = (1 + (_vec_i - _vec_l));
                word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                ((ai))      = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                    ((__alignof__(((((ai))))[0])));
                                                __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
        }
    } while (0);
    a = ai[i0];
    b = (uword) 1 << i1;
    do {
        a = a & b;
    } while (0);
    ai[i0] = a;
    if (1 && a == 0)
        ai = _clib_bitmap_remove_trailing_zeros(ai);
    return ai;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_andnoti(uword *ai, uword i)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    uword a, b;
    do {
        _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                           ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = ((i0));
        word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n = (1 + (_vec_i - _vec_l));
                word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                ((ai))      = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                    ((__alignof__(((((ai))))[0])));
                                                __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
        }
    } while (0);
    a = ai[i0];
    b = (uword) 1 << i1;
    do {
        a = a & ~b;
    } while (0);
    ai[i0] = a;
    if (1 && a == 0)
        ai = _clib_bitmap_remove_trailing_zeros(ai);
    return ai;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_ori(uword *ai, uword i)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    uword a, b;
    do {
        _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                           ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = ((i0));
        word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n = (1 + (_vec_i - _vec_l));
                word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                ((ai))      = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                    ((__alignof__(((((ai))))[0])));
                                                __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
        }
    } while (0);
    a = ai[i0];
    b = (uword) 1 << i1;
    do {
        a = a | b;
    } while (0);
    ai[i0] = a;
    if (0 && a == 0)
        ai = _clib_bitmap_remove_trailing_zeros(ai);
    return ai;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_xori(uword *ai, uword i)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    uword a, b;
    do {
        _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                           ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = ((i0));
        word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n = (1 + (_vec_i - _vec_l));
                word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                ((ai))      = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                    ((__alignof__(((((ai))))[0])));
                                                __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
        }
    } while (0);
    a = ai[i0];
    b = (uword) 1 << i1;
    do {
        a = a ^ b;
    } while (0);
    ai[i0] = a;
    if (1 && a == 0)
        ai = _clib_bitmap_remove_trailing_zeros(ai);
    return ai;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_andi_notrim(uword *ai, uword i)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    uword a, b;
    do {
        _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                           ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = ((i0));
        word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n = (1 + (_vec_i - _vec_l));
                word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                ((ai))      = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                    ((__alignof__(((((ai))))[0])));
                                                __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
        }
    } while (0);
    a = ai[i0];
    b = (uword) 1 << i1;
    do {
        a = a & b;
    } while (0);
    ai[i0] = a;
    return ai;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_andnoti_notrim(uword *ai, uword i)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    uword a, b;
    do {
        _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                           ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = ((i0));
        word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n = (1 + (_vec_i - _vec_l));
                word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                ((ai))      = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                    ((__alignof__(((((ai))))[0])));
                                                __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
        }
    } while (0);
    a = ai[i0];
    b = (uword) 1 << i1;
    do {
        a = a & ~b;
    } while (0);
    ai[i0] = a;
    return ai;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_ori_notrim(uword *ai, uword i)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    uword a, b;
    do {
        _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                           ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = ((i0));
        word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n = (1 + (_vec_i - _vec_l));
                word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                ((ai))      = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                    ((__alignof__(((((ai))))[0])));
                                                __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
        }
    } while (0);
    a = ai[i0];
    b = (uword) 1 << i1;
    do {
        a = a | b;
    } while (0);
    ai[i0] = a;
    return ai;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_xori_notrim(uword *ai, uword i)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    uword a, b;
    do {
        _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                           ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = ((i0));
        word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n = (1 + (_vec_i - _vec_l));
                word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                ((ai))      = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                    ((__alignof__(((((ai))))[0])));
                                                __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
        }
    } while (0);
    a = ai[i0];
    b = (uword) 1 << i1;
    do {
        a = a ^ b;
    } while (0);
    ai[i0] = a;
    return ai;
}
static inline __attribute__((__always_inline__)) uword *
clib_bitmap_random(uword *ai, uword n_bits, u32 *seed)
{
    do {
        if (ai)
            (((vec_header_t *) (ai) -1)->len) = 0;
    } while (0);
    if (n_bits > 0) {
        uword i = n_bits - 1;
        uword i0, i1;
        uword log2_rand_max;
        log2_rand_max = min_log2(random_u32_max());
        i0            = i / (8 * sizeof(ai[0]));
        i1            = i % (8 * sizeof(ai[0]));
        do {
            _Static_assert(sizeof(uword) == 0 || ((sizeof(uword) % sizeof((ai)[0])) == 0) ||
                               ((sizeof((ai)[0]) % sizeof(uword)) == 0),
                           "vector validate aligned on incorrectly sized object");
            word _vec_i = ((i0));
            word _vec_l = (((ai)) ? (((vec_header_t *) ((ai)) - 1)->len) : 0);
            if (_vec_i >= _vec_l) {
                do {
                    word _vec_n = (1 + (_vec_i - _vec_l));
                    word _vec_l = ((((ai))) ? (((vec_header_t *) (((ai))) - 1)->len) : 0);
                    ((ai)) = _vec_resize_inline((((ai))), _vec_n, (_vec_l + _vec_n) * sizeof((((ai)))[0]), ((0)), ({
                                                    __typeof__((__alignof__(((((ai))))[0]))) _x =
                                                        ((__alignof__(((((ai))))[0])));
                                                    __typeof__((((sizeof(uword))))) _y = ((((sizeof(uword)))));
                                                    _x > _y ? _x : _y;
                                                }));
                } while (0);
                memset(((ai)) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof(((ai))[0]));
            }
        } while (0);
        for (i = 0; i <= i0; i++) {
            uword n;
            for (n = 0; n < (8 * sizeof(ai[i])); n += log2_rand_max)
                ai[i] |= random_u32(seed) << n;
        }
        if (i1 + 1 < (8 * sizeof(ai[0])))
            ai[i0] &= (((uword) 1 << (i1 + 1)) - 1);
    }
    return ai;
}
static inline __attribute__((__always_inline__)) uword
clib_bitmap_next_set(uword *ai, uword i)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    uword t;
    if (i0 < ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0)) {
        t = (ai[i0] >> i1) << i1;
        if (t)
            return log2_first_set(t) + i0 * (8 * sizeof(ai[0]));
        for (i0++; i0 < ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0); i0++) {
            t = ai[i0];
            if (t)
                return log2_first_set(t) + i0 * (8 * sizeof(ai[0]));
        }
    }
    return ~0;
}
static inline __attribute__((__always_inline__)) uword
clib_bitmap_next_clear(uword *ai, uword i)
{
    uword i0 = i / (8 * sizeof(ai[0]));
    uword i1 = i % (8 * sizeof(ai[0]));
    uword t;
    if (i0 < ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0)) {
        t = (~ai[i0] >> i1) << i1;
        if (t)
            return log2_first_set(t) + i0 * (8 * sizeof(ai[0]));
        for (i0++; i0 < ((ai) ? (((vec_header_t *) (ai) -1)->len) : 0); i0++) {
            t = ~ai[i0];
            if (t)
                return log2_first_set(t) + i0 * (8 * sizeof(ai[0]));
        }
        return (i0 + 1) * (8 * sizeof(ai[0]));
    }
    return i;
}
static inline uword
unformat_bitmap_mask(unformat_input_t *input, va_list *va)
{
    u8 *v                 = 0;
    uword **bitmap_return = __builtin_va_arg(*va, uword **);
    uword *bitmap         = 0;
    if (unformat(input, "%U", unformat_hex_string, &v)) {
        int i, s = ((v) ? (((vec_header_t *) (v) -1)->len) : 0) - 1;
        for (i = 0; s >= 0; i++, s--)
            bitmap = clib_bitmap_set_multiple(bitmap, s * (8 * sizeof(v[i])), v[i], (8 * sizeof(v[i])));
        do {
            if (v) {
                clib_mem_free(vec_header((v), (0)));
                v = 0;
            }
        } while (0);
        *bitmap_return = bitmap;
        return 1;
    }
    return 0;
}
static inline uword
unformat_bitmap_list(unformat_input_t *input, va_list *va)
{
    uword **bitmap_return = __builtin_va_arg(*va, uword **);
    uword *bitmap         = 0;
    u32 a, b;
    while (unformat_check_input(input) != (~0)) {
        int i;
        if (unformat(input, "%u-%u,", &a, &b))
            ;
        else if (unformat(input, "%u,", &a))
            b = a;
        else if (unformat(input, "%u-%u", &a, &b))
            ;
        else if (unformat(input, "%u", &a))
            b = a;
        else if (bitmap) {
            unformat_put_input(input);
            break;
        } else
            goto error;
        if (b < a)
            goto error;
        for (i = a; i <= b; i++)
            bitmap = clib_bitmap_set(bitmap, i, 1);
    }
    *bitmap_return = bitmap;
    return 1;
error:
    do {
        if (bitmap) {
            clib_mem_free(vec_header((bitmap), (0)));
            bitmap = 0;
        }
    } while (0);
    return 0;
}
static inline u8 *
format_bitmap_hex(u8 *s, va_list *args)
{
    uword *bitmap = __builtin_va_arg(*args, uword *);
    int i, is_trailing_zero = 1;
    if (!bitmap)
        return format(s, "0");
    i = (((bitmap) ? (((vec_header_t *) (bitmap) -1)->len) : 0) * sizeof(bitmap[0])) * 2;
    while (i > 0) {
        u8 x = clib_bitmap_get_multiple(bitmap, --i * 4, 4);
        if (x && is_trailing_zero)
            is_trailing_zero = 0;
        if (x || !is_trailing_zero)
            s = format(s, "%x", x);
    }
    return s;
}
u8 *format_mheap(u8 *s, va_list *va);
void *mheap_alloc_with_lock(void *memory, uword size, int locked);
typedef struct {
    uword *free_bitmap;
    u32 *free_indices;
    u32 max_elts;
    u8 *mmap_base;
    u64 mmap_size;
} pool_header_t;
static inline __attribute__((__always_inline__)) pool_header_t *
pool_header(void *v)
{
    return vec_aligned_header(v, sizeof(pool_header_t), sizeof(void *));
}
extern void _pool_init_fixed(void **, u32, u32);
extern void fpool_free(void *);
static inline __attribute__((__always_inline__)) void
pool_validate(void *v)
{
    pool_header_t *p = pool_header(v);
    uword i, n_free_bitmap;
    if (!v)
        return;
    n_free_bitmap = clib_bitmap_count_set_bits(p->free_bitmap);
    do {
        if ((0 > 0) && !(n_free_bitmap == ((p->free_indices) ? (((vec_header_t *) (p->free_indices) - 1)->len) : 0))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/pool.h", (uword) 102,
                        ((char *) __FUNCTION__), "n_free_bitmap == vec_len (p->free_indices)");
        }
    } while (0);
    for (i = 0; i < ((p->free_indices) ? (((vec_header_t *) (p->free_indices) - 1)->len) : 0); i++)
        do {
            if ((0 > 0) && !(clib_bitmap_get(p->free_bitmap, p->free_indices[i]) == 1)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/pool.h", (uword) 104,
                            ((char *) __FUNCTION__), "clib_bitmap_get (p->free_bitmap, p->free_indices[i]) == 1");
            }
        } while (0);
}
static inline __attribute__((__always_inline__)) void
pool_header_validate_index(void *v, uword index)
{
    pool_header_t *p = pool_header(v);
    if (v)
        do {
            _Static_assert(0 == 0 || ((0 % sizeof(p->free_bitmap[0])) == 0) || ((sizeof(p->free_bitmap[0]) % 0) == 0),
                           "vector validate aligned on incorrectly sized object");
            word _vec_i = (index / (8 * sizeof(uword)));
            word _vec_l = ((p->free_bitmap) ? (((vec_header_t *) (p->free_bitmap) - 1)->len) : 0);
            if (_vec_i >= _vec_l) {
                do {
                    word _vec_n      = (1 + (_vec_i - _vec_l));
                    word _vec_l      = (((p->free_bitmap)) ? (((vec_header_t *) ((p->free_bitmap)) - 1)->len) : 0);
                    (p->free_bitmap) = _vec_resize_inline(((p->free_bitmap)), _vec_n,
                                                          (_vec_l + _vec_n) * sizeof(((p->free_bitmap))[0]), ((0)), ({
                                                              __typeof__((__alignof__((((p->free_bitmap)))[0]))) _x =
                                                                  ((__alignof__((((p->free_bitmap)))[0])));
                                                              __typeof__((((0)))) _y = ((((0))));
                                                              _x > _y ? _x : _y;
                                                          }));
                } while (0);
                memset((p->free_bitmap) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof((p->free_bitmap)[0]));
            }
        } while (0);
}
static inline __attribute__((__always_inline__)) uword
pool_elts(void *v)
{
    uword ret = ((v) ? (((vec_header_t *) (v) -1)->len) : 0);
    if (v)
        ret -= ((pool_header(v)->free_indices) ? (((vec_header_t *) (pool_header(v)->free_indices) - 1)->len) : 0);
    return ret;
}
static inline __attribute__((__always_inline__)) uword
pool_header_bytes(void *v)
{
    pool_header_t *p = pool_header(v);
    if (!v)
        return 0;
    return (((p->free_bitmap) ? (((vec_header_t *) (p->free_bitmap) - 1)->len) : 0) * sizeof(p->free_bitmap[0])) +
           (((p->free_indices) ? (((vec_header_t *) (p->free_indices) - 1)->len) : 0) * sizeof(p->free_indices[0]));
}
static inline __attribute__((__always_inline__)) uword
pool_free_elts(void *v)
{
    pool_header_t *p = pool_header(v);
    uword n_free     = 0;
    if (v) {
        n_free += ((p->free_indices) ? (((vec_header_t *) (p->free_indices) - 1)->len) : 0);
        n_free += ({
                      void *_vec_capacity_v = (void *) (v);
                      uword _vec_capacity_b = (sizeof(p[0]));
                      _vec_capacity_b =
                          sizeof(vec_header_t) + (((_vec_capacity_b) + sizeof(uword) - 1) & ~(sizeof(uword) - 1));
                      _vec_capacity_v ? clib_mem_size(_vec_capacity_v - _vec_capacity_b) : 0;
                  }) -
                  ((v) ? (((vec_header_t *) (v) -1)->len) : 0);
    }
    return n_free;
}
static inline __attribute__((__always_inline__)) void *
_pool_free(void *v)
{
    pool_header_t *p = pool_header(v);
    if (!v)
        return v;
    do {
        if (p->free_bitmap) {
            clib_mem_free(vec_header((p->free_bitmap), (0)));
            p->free_bitmap = 0;
        }
    } while (0);
    if (p->max_elts) {
        int rv;
        rv = munmap(p->mmap_base, p->mmap_size);
        if (rv)
            _clib_error(CLIB_ERROR_WARNING | CLIB_ERROR_ERRNO_VALID, ((char *) __FUNCTION__), 346, "munmap");
    } else {
        do {
            if (p->free_indices) {
                clib_mem_free(vec_header((p->free_indices), (0)));
                p->free_indices = 0;
            }
        } while (0);
        do {
            if (v) {
                clib_mem_free(vec_header((v), (vec_aligned_header_bytes(sizeof(pool_header_t), sizeof(void *)))));
                v = 0;
            }
        } while (0);
    }
    return 0;
}
typedef struct {
    u64 time;
    u32 node_index;
    u32 n_data;
    u8 data[0];
} vlib_trace_header_t;
typedef struct {
    u32 count;
    u32 limit;
} vlib_trace_node_t;
typedef struct {
    vlib_trace_header_t **trace_buffer_pool;
    u32 last_main_loop_count;
    u32 filter_node_index;
    u32 filter_flag;
    u32 filter_count;
    u32 trace_enable;
    vlib_trace_node_t *nodes;
    int verbose;
} vlib_trace_main_t;
struct vlib_node_runtime_t;
struct vlib_frame_t;
typedef uword(vlib_node_function_t)(struct vlib_main_t *vm, struct vlib_node_runtime_t *node, struct vlib_frame_t *frame);
typedef enum {
    VLIB_NODE_TYPE_INTERNAL,
    VLIB_NODE_TYPE_INPUT,
    VLIB_NODE_TYPE_PRE_INPUT,
    VLIB_NODE_TYPE_PROCESS,
    VLIB_N_NODE_TYPE,
} vlib_node_type_t;
typedef struct _vlib_node_fn_registration {
    vlib_node_function_t *function;
    int priority;
    struct _vlib_node_fn_registration *next_registration;
    char *name;
} vlib_node_fn_registration_t;
typedef struct _vlib_node_registration {
    vlib_node_function_t *function;
    vlib_node_fn_registration_t *node_fn_registrations;
    char *name;
    char *sibling_of;
    u32 index;
    vlib_node_type_t type;
    char **error_strings;
    format_function_t *format_buffer;
    unformat_function_t *unformat_buffer;
    format_function_t *format_trace;
    unformat_function_t *unformat_trace;
    u8 *(*validate_frame)(struct vlib_main_t *vm, struct vlib_node_runtime_t *, struct vlib_frame_t *f);
    void *runtime_data;
    u16 process_log2_n_stack_bytes;
    u8 runtime_data_bytes;
    u8 state;
    u16 flags;
    u16 scalar_size, vector_size;
    u16 n_errors;
    u16 n_next_nodes;
    struct _vlib_node_registration *next_registration;
    char *next_nodes[];
} vlib_node_registration_t;
static inline __attribute__((__always_inline__)) vlib_node_registration_t *
vlib_node_next_registered(vlib_node_registration_t *c)
{
    c = ((void *) (clib_address_t)(
        round_pow2(pointer_to_uword(c + 1) + (c->n_next_nodes * sizeof(c->next_nodes[0])), 32)));
    return c;
}
typedef struct {
    u64 calls, vectors, clocks, suspends;
    u64 max_clock;
    u64 max_clock_n;
} vlib_node_stats_t;
typedef enum {
    VLIB_NODE_STATE_POLLING,
    VLIB_NODE_STATE_INTERRUPT,
    VLIB_NODE_STATE_DISABLED,
    VLIB_N_NODE_STATE,
} vlib_node_state_t;
typedef struct vlib_node_t {
    vlib_node_function_t *function;
    u8 *name;
    u32 name_elog_string;
    vlib_node_stats_t stats_total;
    vlib_node_stats_t stats_last_clear;
    vlib_node_type_t type;
    u32 index;
    u32 runtime_index;
    void *runtime_data;
    u16 flags;
    u8 state;
    u8 runtime_data_bytes;
    u16 n_errors;
    u16 scalar_size, vector_size;
    u32 error_heap_handle;
    u32 error_heap_index;
    char **error_strings;
    char **next_node_names;
    u32 *next_nodes;
    char *sibling_of;
    uword *sibling_bitmap;
    u64 *n_vectors_by_next_node;
    uword *next_slot_by_node;
    uword *prev_node_bitmap;
    u32 owner_node_index, owner_next_index;
    format_function_t *format_buffer;
    unformat_function_t *unformat_buffer;
    format_function_t *format_trace;
    u8 *(*validate_frame)(struct vlib_main_t *vm, struct vlib_node_runtime_t *, struct vlib_frame_t *f);
    u8 *state_string;
    vlib_node_fn_registration_t *node_fn_registrations;
} vlib_node_t;
typedef struct vlib_frame_t {
    u16 frame_flags;
    u16 flags;
    u8 scalar_size;
    u8 vector_size;
    u16 n_vectors;
    u8 arguments[0];
} vlib_frame_t;
typedef struct {
    u32 frame_index;
    u32 node_runtime_index;
    u32 flags;
    u32 vectors_since_last_overflow;
} vlib_next_frame_t;
static inline __attribute__((__always_inline__)) void
vlib_next_frame_init(vlib_next_frame_t *nf)
{
    memset(nf, 0, sizeof(nf[0]));
    nf->frame_index        = ~0;
    nf->node_runtime_index = ~0;
}
typedef struct {
    u32 node_runtime_index;
    u32 frame_index;
    u32 next_frame_index;
} vlib_pending_frame_t;
typedef struct vlib_node_runtime_t {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    vlib_node_function_t *function;
    vlib_error_t *errors;
    u32 clocks_since_last_overflow;
    u32 max_clock;
    u32 max_clock_n;
    u32 calls_since_last_overflow;
    u32 vectors_since_last_overflow;
    u32 next_frame_index;
    u32 node_index;
    u32 input_main_loops_per_call;
    u32 main_loop_count_last_dispatch;
    u32 main_loop_vector_stats[2];
    u16 flags;
    u16 state;
    u16 n_next_nodes;
    u16 cached_next_index;
    u16 thread_index;
    u8 runtime_data[0];
} vlib_node_runtime_t;
typedef struct {
    u32 n_alloc_frames;
    u32 *free_frame_indices;
} vlib_frame_size_t;
typedef struct {
    uword opaque;
} vlib_process_event_type_t;
typedef struct {
    vlib_node_runtime_t node_runtime;
    clib_longjmp_t return_longjmp;
    clib_longjmp_t resume_longjmp;
    u16 flags;
    u16 log2_n_stack_bytes;
    u32 suspended_process_frame_index;
    u32 n_suspends;
    void **pending_event_data_by_type_index;
    uword *non_empty_event_type_bitmap;
    uword *one_time_event_type_bitmap;
    uword *event_type_index_by_type_opaque;
    vlib_process_event_type_t *event_type_pool;
    u64 resume_clock_interval;
    u32 stop_timer_handle;
    vlib_cli_output_function_t *output_function;
    uword output_function_arg;
    u32 stack[0] __attribute__((aligned(0x1000)));
} vlib_process_t __attribute__((aligned((1 << 6))));
typedef char
    assert_process_stack_must_be_aligned_exactly_to_page_size_multiple[(sizeof(vlib_process_t) - 0x1000) == 0 ? 0 : -1];
typedef struct {
    u32 node_index;
    u32 one_time_event;
} vlib_one_time_waiting_process_t;
typedef struct {
    u16 n_data_elts;
    u16 n_data_elt_bytes;
    u32 n_data_bytes;
    u32 process_node_index;
    u32 event_type_index;
    union {
        u8 inline_event_data[64 - 3 * sizeof(u32) - 2 * sizeof(u16)];
        u8 *event_data_as_vector;
    };
} vlib_signal_timed_event_data_t;
static inline __attribute__((__always_inline__)) uword
vlib_timing_wheel_data_is_timed_event(u32 d)
{
    return d & 1;
}
static inline __attribute__((__always_inline__)) u32
vlib_timing_wheel_data_set_suspended_process(u32 i)
{
    return 0 + 2 * i;
}
static inline __attribute__((__always_inline__)) u32
vlib_timing_wheel_data_set_timed_event(u32 i)
{
    return 1 + 2 * i;
}
static inline __attribute__((__always_inline__)) uword
vlib_timing_wheel_data_get_index(u32 d)
{
    return d / 2;
}
typedef struct {
    vlib_node_t **nodes;
    uword *node_by_name;
    u32 flags;
    vlib_node_runtime_t *nodes_by_type[VLIB_N_NODE_TYPE];
    u32 *pending_interrupt_node_runtime_indices;
    clib_spinlock_t pending_interrupt_lock;
    u32 polling_threshold_vector_length;
    u32 interrupt_threshold_vector_length;
    vlib_next_frame_t *next_frames;
    vlib_pending_frame_t *pending_frames;
    void *timing_wheel;
    vlib_signal_timed_event_data_t *signal_timed_event_data_pool;
    u32 *data_from_advancing_timing_wheel;
    f64 time_next_process_ready;
    vlib_process_t **processes;
    u32 current_process_index;
    vlib_pending_frame_t *suspended_process_frames;
    void **recycled_event_data_vectors;
    u32 input_node_counts_by_state[VLIB_N_NODE_STATE];
    uword *frame_size_hash;
    vlib_frame_size_t *frame_sizes;
    f64 time_last_runtime_stats_clear;
    vlib_node_registration_t *node_registrations;
} vlib_node_main_t;
typedef struct {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    u64 head;
    u64 head_hint;
    u64 tail;
    u32 n_in_use;
    u32 nelts;
    u32 written;
    u32 threshold;
    i32 n_vectors[32];
} frame_queue_trace_t;
typedef struct {
    u64 count[32];
} frame_queue_nelt_counter_t;
typedef u32 vlib_log_class_t;
typedef enum {
    VLIB_LOG_LEVEL_EMERG    = 0,
    VLIB_LOG_LEVEL_ALERT    = 1,
    VLIB_LOG_LEVEL_CRIT     = 2,
    VLIB_LOG_LEVEL_ERR      = 3,
    VLIB_LOG_LEVEL_WARNING  = 4,
    VLIB_LOG_LEVEL_NOTICE   = 5,
    VLIB_LOG_LEVEL_INFO     = 6,
    VLIB_LOG_LEVEL_DEBUG    = 7,
    VLIB_LOG_LEVEL_DISABLED = 8,
} vlib_log_level_t;
vlib_log_class_t vlib_log_register_class(char *vlass, char *subclass);
u32 vlib_log_get_indent();
void vlib_log(vlib_log_level_t level, vlib_log_class_t class, char *fmt, ...);
typedef struct {
    u64 total_cpu_time;
    u64 last_cpu_time;
    f64 clocks_per_second;
    f64 seconds_per_clock;
    u64 init_cpu_time;
    u64 last_verify_cpu_time;
    f64 last_verify_reference_time;
    u32 log2_clocks_per_second, log2_clocks_per_frequency_verify;
} clib_time_t;
static inline __attribute__((__always_inline__)) u64
clib_cpu_time_now(void)
{
    u32 a, d;
    asm volatile("rdtsc" : "=a"(a), "=d"(d));
    return (u64) a + ((u64) d << (u64) 32);
}
void clib_time_verify_frequency(clib_time_t *c);
static inline __attribute__((__always_inline__)) f64
clib_time_now_internal(clib_time_t *c, u64 n)
{
    u64 l = c->last_cpu_time;
    u64 t = c->total_cpu_time;
    t += n - l;
    c->total_cpu_time = t;
    c->last_cpu_time  = n;
    if (__builtin_expect(((c->last_cpu_time - c->last_verify_cpu_time) >> c->log2_clocks_per_frequency_verify), 0))
        clib_time_verify_frequency(c);
    return t * c->seconds_per_clock;
}
static inline __attribute__((__always_inline__)) f64
clib_time_now(clib_time_t *c)
{
    return clib_time_now_internal(c, clib_cpu_time_now());
}
static inline __attribute__((__always_inline__)) void
clib_cpu_time_wait(u64 dt)
{
    u64 t_end = clib_cpu_time_now() + dt;
    while (clib_cpu_time_now() < t_end)
        ;
}
void clib_time_init(clib_time_t *c);
struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
    long int tm_gmtoff;
    const char *tm_zone;
};
struct itimerspec {
    struct timespec it_interval;
    struct timespec it_value;
};
struct sigevent;
extern clock_t clock(void) __attribute__((__nothrow__, __leaf__));
extern time_t time(time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern double difftime(time_t __time1, time_t __time0) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern time_t mktime(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern size_t strftime(char *__restrict __s, size_t __maxsize, const char *__restrict __format,
                       const struct tm *__restrict __tp) __attribute__((__nothrow__, __leaf__));
extern size_t strftime_l(char *__restrict __s, size_t __maxsize, const char *__restrict __format,
                         const struct tm *__restrict __tp, locale_t __loc) __attribute__((__nothrow__, __leaf__));
extern struct tm *gmtime(const time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern struct tm *localtime(const time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern struct tm *gmtime_r(const time_t *__restrict __timer, struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern struct tm *localtime_r(const time_t *__restrict __timer, struct tm *__restrict __tp)
    __attribute__((__nothrow__, __leaf__));
extern char *asctime(const struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern char *ctime(const time_t *__timer) __attribute__((__nothrow__, __leaf__));
extern char *asctime_r(const struct tm *__restrict __tp, char *__restrict __buf) __attribute__((__nothrow__, __leaf__));
extern char *ctime_r(const time_t *__restrict __timer, char *__restrict __buf) __attribute__((__nothrow__, __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset(void) __attribute__((__nothrow__, __leaf__));
extern int daylight;
extern long int timezone;
extern int stime(const time_t *__when) __attribute__((__nothrow__, __leaf__));
extern time_t timegm(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern time_t timelocal(struct tm *__tp) __attribute__((__nothrow__, __leaf__));
extern int dysize(int __year) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int nanosleep(const struct timespec *__requested_time, struct timespec *__remaining);
extern int clock_getres(clockid_t __clock_id, struct timespec *__res) __attribute__((__nothrow__, __leaf__));
extern int clock_gettime(clockid_t __clock_id, struct timespec *__tp) __attribute__((__nothrow__, __leaf__));
extern int clock_settime(clockid_t __clock_id, const struct timespec *__tp) __attribute__((__nothrow__, __leaf__));
extern int clock_nanosleep(clockid_t __clock_id, int __flags, const struct timespec *__req, struct timespec *__rem);
extern int clock_getcpuclockid(pid_t __pid, clockid_t *__clock_id) __attribute__((__nothrow__, __leaf__));
extern int timer_create(clockid_t __clock_id, struct sigevent *__restrict __evp, timer_t *__restrict __timerid)
    __attribute__((__nothrow__, __leaf__));
extern int timer_delete(timer_t __timerid) __attribute__((__nothrow__, __leaf__));
extern int timer_settime(timer_t __timerid, int __flags, const struct itimerspec *__restrict __value,
                         struct itimerspec *__restrict __ovalue) __attribute__((__nothrow__, __leaf__));
extern int timer_gettime(timer_t __timerid, struct itimerspec *__value) __attribute__((__nothrow__, __leaf__));
extern int timer_getoverrun(timer_t __timerid) __attribute__((__nothrow__, __leaf__));
extern int timespec_get(struct timespec *__ts, int __base) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
struct timezone {
    int tz_minuteswest;
    int tz_dsttime;
};
typedef struct timezone *__restrict __timezone_ptr_t;
extern int gettimeofday(struct timeval *__restrict __tv, __timezone_ptr_t __tz) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int settimeofday(const struct timeval *__tv, const struct timezone *__tz) __attribute__((__nothrow__, __leaf__));
extern int adjtime(const struct timeval *__delta, struct timeval *__olddelta) __attribute__((__nothrow__, __leaf__));
enum __itimer_which { ITIMER_REAL = 0, ITIMER_VIRTUAL = 1, ITIMER_PROF = 2 };
struct itimerval {
    struct timeval it_interval;
    struct timeval it_value;
};
typedef int __itimer_which_t;
extern int getitimer(__itimer_which_t __which, struct itimerval *__value) __attribute__((__nothrow__, __leaf__));
extern int setitimer(__itimer_which_t __which, const struct itimerval *__restrict __new,
                     struct itimerval *__restrict __old) __attribute__((__nothrow__, __leaf__));
extern int utimes(const char *__file, const struct timeval __tvp[2]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int lutimes(const char *__file, const struct timeval __tvp[2]) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int futimes(int __fd, const struct timeval __tvp[2]) __attribute__((__nothrow__, __leaf__));
enum __rlimit_resource {
    RLIMIT_CPU          = 0,
    RLIMIT_FSIZE        = 1,
    RLIMIT_DATA         = 2,
    RLIMIT_STACK        = 3,
    RLIMIT_CORE         = 4,
    __RLIMIT_RSS        = 5,
    RLIMIT_NOFILE       = 7,
    __RLIMIT_OFILE      = RLIMIT_NOFILE,
    RLIMIT_AS           = 9,
    __RLIMIT_NPROC      = 6,
    __RLIMIT_MEMLOCK    = 8,
    __RLIMIT_LOCKS      = 10,
    __RLIMIT_SIGPENDING = 11,
    __RLIMIT_MSGQUEUE   = 12,
    __RLIMIT_NICE       = 13,
    __RLIMIT_RTPRIO     = 14,
    __RLIMIT_RTTIME     = 15,
    __RLIMIT_NLIMITS    = 16,
    __RLIM_NLIMITS      = __RLIMIT_NLIMITS
};
typedef __rlim_t rlim_t;
struct rlimit {
    rlim_t rlim_cur;
    rlim_t rlim_max;
};
enum __rusage_who { RUSAGE_SELF = 0, RUSAGE_CHILDREN = -1 };
struct rusage {
    struct timeval ru_utime;
    struct timeval ru_stime;
    __extension__ union {
        long int ru_maxrss;
        __syscall_slong_t __ru_maxrss_word;
    };
    __extension__ union {
        long int ru_ixrss;
        __syscall_slong_t __ru_ixrss_word;
    };
    __extension__ union {
        long int ru_idrss;
        __syscall_slong_t __ru_idrss_word;
    };
    __extension__ union {
        long int ru_isrss;
        __syscall_slong_t __ru_isrss_word;
    };
    __extension__ union {
        long int ru_minflt;
        __syscall_slong_t __ru_minflt_word;
    };
    __extension__ union {
        long int ru_majflt;
        __syscall_slong_t __ru_majflt_word;
    };
    __extension__ union {
        long int ru_nswap;
        __syscall_slong_t __ru_nswap_word;
    };
    __extension__ union {
        long int ru_inblock;
        __syscall_slong_t __ru_inblock_word;
    };
    __extension__ union {
        long int ru_oublock;
        __syscall_slong_t __ru_oublock_word;
    };
    __extension__ union {
        long int ru_msgsnd;
        __syscall_slong_t __ru_msgsnd_word;
    };
    __extension__ union {
        long int ru_msgrcv;
        __syscall_slong_t __ru_msgrcv_word;
    };
    __extension__ union {
        long int ru_nsignals;
        __syscall_slong_t __ru_nsignals_word;
    };
    __extension__ union {
        long int ru_nvcsw;
        __syscall_slong_t __ru_nvcsw_word;
    };
    __extension__ union {
        long int ru_nivcsw;
        __syscall_slong_t __ru_nivcsw_word;
    };
};
enum __priority_which { PRIO_PROCESS = 0, PRIO_PGRP = 1, PRIO_USER = 2 };
typedef int __rlimit_resource_t;
typedef int __rusage_who_t;
typedef int __priority_which_t;
extern int getrlimit(__rlimit_resource_t __resource, struct rlimit *__rlimits) __attribute__((__nothrow__, __leaf__));
extern int setrlimit(__rlimit_resource_t __resource, const struct rlimit *__rlimits)
    __attribute__((__nothrow__, __leaf__));
extern int getrusage(__rusage_who_t __who, struct rusage *__usage) __attribute__((__nothrow__, __leaf__));
extern int getpriority(__priority_which_t __which, id_t __who) __attribute__((__nothrow__, __leaf__));
extern int setpriority(__priority_which_t __which, id_t __who, int __prio) __attribute__((__nothrow__, __leaf__));
static inline __attribute__((__always_inline__)) f64
unix_time_now(void)
{
    struct timespec ts;
    syscall(228, 0, &ts);
    return ts.tv_sec + 1e-9 * ts.tv_nsec;
}
static inline __attribute__((__always_inline__)) u64
unix_time_now_nsec(void)
{
    struct timespec ts;
    syscall(228, 0, &ts);
    return 1e9 * ts.tv_sec + ts.tv_nsec;
}
static inline __attribute__((__always_inline__)) void
unix_time_now_nsec_fraction(u32 *sec, u32 *nsec)
{
    struct timespec ts;
    syscall(228, 0, &ts);
    *sec  = ts.tv_sec;
    *nsec = ts.tv_nsec;
}
static inline __attribute__((__always_inline__)) f64
unix_usage_now(void)
{
    struct rusage u;
    getrusage(RUSAGE_SELF, &u);
    return u.ru_utime.tv_sec + 1e-6 * u.ru_utime.tv_usec + u.ru_stime.tv_sec + 1e-6 * u.ru_stime.tv_usec;
}
static inline __attribute__((__always_inline__)) void
unix_sleep(f64 dt)
{
    struct timespec ts, tsrem;
    ts.tv_sec  = dt;
    ts.tv_nsec = 1e9 * (dt - (f64) ts.tv_sec);
    while (nanosleep(&ts, &tsrem) < 0)
        ts = tsrem;
}
typedef struct {
    u32 offset;
    i32 next, prev;
} heap_elt_t;
static inline __attribute__((__always_inline__)) uword
heap_is_free(heap_elt_t *e)
{
    return (e->offset & (1 << 31)) != 0;
}
static inline __attribute__((__always_inline__)) uword
heap_offset(heap_elt_t *e)
{
    return e->offset & ~(1 << 31);
}
static inline __attribute__((__always_inline__)) heap_elt_t *
heap_next(heap_elt_t *e)
{
    return e + e->next;
}
static inline __attribute__((__always_inline__)) heap_elt_t *
heap_prev(heap_elt_t *e)
{
    return e + e->prev;
}
static inline __attribute__((__always_inline__)) uword
heap_elt_size(void *v, heap_elt_t *e)
{
    heap_elt_t *n     = heap_next(e);
    uword next_offset = n != e ? heap_offset(n) : ((v) ? (((vec_header_t *) (v) -1)->len) : 0);
    return next_offset - heap_offset(e);
}
typedef struct {
    heap_elt_t *elts;
    u32 *small_free_elt_free_index;
    u32 *free_elts;
    u32 **free_lists;
    format_function_t *format_elt;
    uword *used_elt_bitmap;
    u32 head, tail;
    u32 used_count, max_len;
    u32 elt_bytes;
    u32 flags;
} heap_header_t;
static inline __attribute__((__always_inline__)) heap_header_t *
heap_header(void *v)
{
    return vec_header(v, sizeof(heap_header_t));
}
static inline __attribute__((__always_inline__)) uword
heap_header_bytes()
{
    return vec_header_bytes(sizeof(heap_header_t));
}
static inline __attribute__((__always_inline__)) void
heap_dup_header(heap_header_t *old, heap_header_t *new)
{
    uword i;
    new[0]          = old[0];
    new->elts       = ({
        __typeof__((new->elts)[0]) *_vec_v = 0;
        uword _vec_l                       = ((new->elts) ? (((vec_header_t *) (new->elts) - 1)->len) : 0);
        if (_vec_l > 0) {
            do {
                word _vec_n = (_vec_l);
                word _vec_l = ((_vec_v) ? (((vec_header_t *) (_vec_v) -1)->len) : 0);
                _vec_v      = _vec_resize_inline((_vec_v), _vec_n, (_vec_l + _vec_n) * sizeof((_vec_v)[0]), ((0)), ({
                                                __typeof__((__alignof__(((_vec_v))[0]))) _x =
                                                    ((__alignof__(((_vec_v))[0])));
                                                __typeof__((((0)))) _y = ((((0))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memcpy(_vec_v, (new->elts), _vec_l * sizeof((new->elts)[0]));
        }
        _vec_v;
    });
    new->free_elts  = ({
        __typeof__((new->free_elts)[0]) *_vec_v = 0;
        uword _vec_l = ((new->free_elts) ? (((vec_header_t *) (new->free_elts) - 1)->len) : 0);
        if (_vec_l > 0) {
            do {
                word _vec_n = (_vec_l);
                word _vec_l = ((_vec_v) ? (((vec_header_t *) (_vec_v) -1)->len) : 0);
                _vec_v      = _vec_resize_inline((_vec_v), _vec_n, (_vec_l + _vec_n) * sizeof((_vec_v)[0]), ((0)), ({
                                                __typeof__((__alignof__(((_vec_v))[0]))) _x =
                                                    ((__alignof__(((_vec_v))[0])));
                                                __typeof__((((0)))) _y = ((((0))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memcpy(_vec_v, (new->free_elts), _vec_l * sizeof((new->free_elts)[0]));
        }
        _vec_v;
    });
    new->free_lists = ({
        __typeof__((new->free_lists)[0]) *_vec_v = 0;
        uword _vec_l = ((new->free_lists) ? (((vec_header_t *) (new->free_lists) - 1)->len) : 0);
        if (_vec_l > 0) {
            do {
                word _vec_n = (_vec_l);
                word _vec_l = ((_vec_v) ? (((vec_header_t *) (_vec_v) -1)->len) : 0);
                _vec_v      = _vec_resize_inline((_vec_v), _vec_n, (_vec_l + _vec_n) * sizeof((_vec_v)[0]), ((0)), ({
                                                __typeof__((__alignof__(((_vec_v))[0]))) _x =
                                                    ((__alignof__(((_vec_v))[0])));
                                                __typeof__((((0)))) _y = ((((0))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memcpy(_vec_v, (new->free_lists), _vec_l * sizeof((new->free_lists)[0]));
        }
        _vec_v;
    });
    for (i = 0; i < ((new->free_lists) ? (((vec_header_t *) (new->free_lists) - 1)->len) : 0); i++)
        new->free_lists[i] = ({
            __typeof__((new->free_lists[i])[0]) *_vec_v = 0;
            uword _vec_l = ((new->free_lists[i]) ? (((vec_header_t *) (new->free_lists[i]) - 1)->len) : 0);
            if (_vec_l > 0) {
                do {
                    word _vec_n = (_vec_l);
                    word _vec_l = ((_vec_v) ? (((vec_header_t *) (_vec_v) -1)->len) : 0);
                    _vec_v = _vec_resize_inline((_vec_v), _vec_n, (_vec_l + _vec_n) * sizeof((_vec_v)[0]), ((0)), ({
                                                    __typeof__((__alignof__(((_vec_v))[0]))) _x =
                                                        ((__alignof__(((_vec_v))[0])));
                                                    __typeof__((((0)))) _y = ((((0))));
                                                    _x > _y ? _x : _y;
                                                }));
                } while (0);
                memcpy(_vec_v, (new->free_lists[i]), _vec_l * sizeof((new->free_lists[i])[0]));
            }
            _vec_v;
        });
    new->used_elt_bitmap           = ({
        __typeof__((new->used_elt_bitmap)[0]) *_vec_v = 0;
        uword _vec_l = ((new->used_elt_bitmap) ? (((vec_header_t *) (new->used_elt_bitmap) - 1)->len) : 0);
        if (_vec_l > 0) {
            do {
                word _vec_n = (_vec_l);
                word _vec_l = ((_vec_v) ? (((vec_header_t *) (_vec_v) -1)->len) : 0);
                _vec_v      = _vec_resize_inline((_vec_v), _vec_n, (_vec_l + _vec_n) * sizeof((_vec_v)[0]), ((0)), ({
                                                __typeof__((__alignof__(((_vec_v))[0]))) _x =
                                                    ((__alignof__(((_vec_v))[0])));
                                                __typeof__((((0)))) _y = ((((0))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memcpy(_vec_v, (new->used_elt_bitmap), _vec_l * sizeof((new->used_elt_bitmap)[0]));
        }
        _vec_v;
    });
    new->small_free_elt_free_index = ({
        __typeof__((new->small_free_elt_free_index)[0]) *_vec_v = 0;
        uword _vec_l =
            ((new->small_free_elt_free_index) ? (((vec_header_t *) (new->small_free_elt_free_index) - 1)->len) : 0);
        if (_vec_l > 0) {
            do {
                word _vec_n = (_vec_l);
                word _vec_l = ((_vec_v) ? (((vec_header_t *) (_vec_v) -1)->len) : 0);
                _vec_v      = _vec_resize_inline((_vec_v), _vec_n, (_vec_l + _vec_n) * sizeof((_vec_v)[0]), ((0)), ({
                                                __typeof__((__alignof__(((_vec_v))[0]))) _x =
                                                    ((__alignof__(((_vec_v))[0])));
                                                __typeof__((((0)))) _y = ((((0))));
                                                _x > _y ? _x : _y;
                                            }));
            } while (0);
            memcpy(_vec_v, (new->small_free_elt_free_index), _vec_l * sizeof((new->small_free_elt_free_index)[0]));
        }
        _vec_v;
    });
}
static inline __attribute__((__always_inline__)) void *
_heap_dup(void *v_old, uword v_bytes)
{
    heap_header_t *h_old, *h_new;
    void *v_new;
    h_old = heap_header(v_old);
    if (!v_old)
        return v_old;
    v_new = 0;
    v_new = _vec_resize_inline(v_new, (((vec_header_t *) (v_old) -1)->len), v_bytes, sizeof(heap_header_t), ({
                                   __typeof__((__alignof__((v_new)[0]))) _x = ((__alignof__((v_new)[0])));
                                   __typeof__((((1 << 6)))) _y              = ((((1 << 6))));
                                   _x > _y ? _x : _y;
                               }));
    h_new = heap_header(v_new);
    heap_dup_header(h_old, h_new);
    memcpy(v_new, v_old, v_bytes);
    return v_new;
}
static inline __attribute__((__always_inline__)) uword
heap_elts(void *v)
{
    heap_header_t *h = heap_header(v);
    return h->used_count;
}
uword heap_bytes(void *v);
static inline __attribute__((__always_inline__)) void *
_heap_new(u32 len, u32 n_elt_bytes)
{
    void *v                   = _vec_resize_inline((void *) 0, len, (uword) len * n_elt_bytes, sizeof(heap_header_t), ({
                                     __typeof__((__alignof__(((void *) 0)[0]))) _x = ((__alignof__(((void *) 0)[0])));
                                     __typeof__((((1 << 6)))) _y                   = ((((1 << 6))));
                                     _x > _y ? _x : _y;
                                 }));
    heap_header(v)->elt_bytes = n_elt_bytes;
    return v;
}
static inline __attribute__((__always_inline__)) void
heap_set_format(void *v, format_function_t *format_elt)
{
    do {
        if ((0 > 0) && !(v)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/heap.h", (uword) 235,
                        ((char *) __FUNCTION__), "v");
        }
    } while (0);
    heap_header(v)->format_elt = format_elt;
}
static inline __attribute__((__always_inline__)) void
heap_set_max_len(void *v, uword max_len)
{
    do {
        if ((0 > 0) && !(v)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/heap.h", (uword) 242,
                        ((char *) __FUNCTION__), "v");
        }
    } while (0);
    heap_header(v)->max_len = max_len;
}
static inline __attribute__((__always_inline__)) uword
heap_get_max_len(void *v)
{
    return v ? heap_header(v)->max_len : 0;
}
static inline __attribute__((__always_inline__)) void *
heap_create_from_memory(void *memory, uword max_len, uword elt_bytes)
{
    heap_header_t *h;
    void *v;
    if (max_len * elt_bytes < sizeof(h[0]))
        return 0;
    h = memory;
    memset(h, 0, sizeof(h[0]));
    h->max_len                       = max_len;
    h->elt_bytes                     = elt_bytes;
    h->flags                         = (1);
    v                                = (void *) (memory + heap_header_bytes());
    (((vec_header_t *) (v) -1)->len) = 0;
    return v;
}
static inline __attribute__((__always_inline__)) heap_elt_t *
heap_get_elt(void *v, uword handle)
{
    heap_header_t *h = heap_header(v);
    heap_elt_t *e    = ({
        do {
            if ((0 > 0) && !((handle) < ((h->elts) ? (((vec_header_t *) (h->elts) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/heap.h", (uword) 302,
                            ((char *) __FUNCTION__), "(handle) < vec_len (h->elts)");
            }
        } while (0);
        (h->elts) + (handle);
    });
    do {
        if ((0 > 0) && !(!heap_is_free(e))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/heap.h", (uword) 303,
                        ((char *) __FUNCTION__), "!heap_is_free (e)");
        }
    } while (0);
    return e;
}
static inline __attribute__((__always_inline__)) uword
heap_is_free_handle(void *v, uword heap_handle)
{
    heap_header_t *h = heap_header(v);
    heap_elt_t *e    = ({
        do {
            if ((0 > 0) && !((heap_handle) < ((h->elts) ? (((vec_header_t *) (h->elts) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/heap.h", (uword) 317,
                            ((char *) __FUNCTION__), "(heap_handle) < vec_len (h->elts)");
            }
        } while (0);
        (h->elts) + (heap_handle);
    });
    return heap_is_free(e);
}
extern uword heap_len(void *v, word handle);
extern void *_heap_alloc(void *v, uword size, uword alignment, uword elt_bytes, uword *offset, uword *handle);
extern void heap_dealloc(void *v, uword handle);
extern void heap_validate(void *v);
extern u8 *format_heap(u8 *s, va_list *va);
void *_heap_free(void *v);
typedef struct {
    u8 *key_vector_or_heap;
    u32 *key_vector_free_indices;
    u8 **key_tmps;
    u32 n_key_bytes;
    u32 hash_seed;
    uword *hash;
    format_function_t *format_key;
} mhash_t;
void mhash_init(mhash_t *h, uword n_value_bytes, uword n_key_bytes);
static inline __attribute__((__always_inline__)) void
mhash_init_c_string(mhash_t *h, uword n_value_bytes)
{
    mhash_init(h, n_value_bytes, 1);
}
static inline __attribute__((__always_inline__)) void
mhash_init_vec_string(mhash_t *h, uword n_value_bytes)
{
    mhash_init(h, n_value_bytes, 0);
}
static inline __attribute__((__always_inline__)) void *
mhash_key_to_mem(mhash_t *h, uword key)
{
    if (key == ~0) {
        u8 *key_tmp;
        int my_cpu = os_get_thread_index();
        do {
            _Static_assert(0 == 0 || ((0 % sizeof(h->key_tmps[0])) == 0) || ((sizeof(h->key_tmps[0]) % 0) == 0),
                           "vector validate aligned on incorrectly sized object");
            word _vec_i = (my_cpu);
            word _vec_l = ((h->key_tmps) ? (((vec_header_t *) (h->key_tmps) - 1)->len) : 0);
            if (_vec_i >= _vec_l) {
                do {
                    word _vec_n   = (1 + (_vec_i - _vec_l));
                    word _vec_l   = (((h->key_tmps)) ? (((vec_header_t *) ((h->key_tmps)) - 1)->len) : 0);
                    (h->key_tmps) = _vec_resize_inline(((h->key_tmps)), _vec_n,
                                                       (_vec_l + _vec_n) * sizeof(((h->key_tmps))[0]), ((0)), ({
                                                           __typeof__((__alignof__((((h->key_tmps)))[0]))) _x =
                                                               ((__alignof__((((h->key_tmps)))[0])));
                                                           __typeof__((((0)))) _y = ((((0))));
                                                           _x > _y ? _x : _y;
                                                       }));
                } while (0);
                memset((h->key_tmps) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof((h->key_tmps)[0]));
            }
        } while (0);
        key_tmp = h->key_tmps[my_cpu];
        return key_tmp;
    }
    return ({
        do {
            if ((0 > 0) &&
                !((key) < ((h->key_vector_or_heap) ? (((vec_header_t *) (h->key_vector_or_heap) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/mhash.h", (uword) 101,
                            ((char *) __FUNCTION__), "(key) < vec_len (h->key_vector_or_heap)");
            }
        } while (0);
        (h->key_vector_or_heap) + (key);
    });
}
hash_pair_t *mhash_get_pair(mhash_t *h, const void *key);
uword mhash_set_mem(mhash_t *h, void *key, uword *new_value, uword *old_value);
uword mhash_unset(mhash_t *h, void *key, uword *old_value);
static inline __attribute__((__always_inline__)) uword *
mhash_get(mhash_t *h, const void *key)
{
    hash_pair_t *p = mhash_get_pair(h, key);
    return p ? &p->value[0] : 0;
}
static inline __attribute__((__always_inline__)) uword
mhash_set(mhash_t *h, void *key, uword new_value, uword *old_value)
{
    return mhash_set_mem(h, key, &new_value, old_value);
}
static inline __attribute__((__always_inline__)) uword
mhash_unset_key(mhash_t *h, uword key, uword *old_value)
{
    void *k = mhash_key_to_mem(h, key);
    return mhash_unset(h, k, old_value);
}
static inline __attribute__((__always_inline__)) uword
mhash_value_bytes(mhash_t *m)
{
    hash_t *h = hash_header(m->hash);
    return hash_value_bytes(h);
}
static inline __attribute__((__always_inline__)) uword
mhash_elts(mhash_t *m)
{
    return hash_elts(m->hash);
}
static inline __attribute__((__always_inline__)) uword
mhash_key_vector_is_heap(mhash_t *h)
{
    return h->n_key_bytes <= 1;
}
static inline __attribute__((__always_inline__)) void
mhash_free(mhash_t *h)
{
    if (mhash_key_vector_is_heap(h))
        (h->key_vector_or_heap) = _heap_free(h->key_vector_or_heap);
    else
        do {
            if (h->key_vector_or_heap) {
                clib_mem_free(vec_header((h->key_vector_or_heap), (0)));
                h->key_vector_or_heap = 0;
            }
        } while (0);
    do {
        if (h->key_vector_free_indices) {
            clib_mem_free(vec_header((h->key_vector_free_indices), (0)));
            h->key_vector_free_indices = 0;
        }
    } while (0);
    (h->hash) = _hash_free((h->hash));
}
format_function_t format_mhash_key;
typedef struct {
    union {
        u64 time_cycles;
        f64 time;
    };
    u16 type;
    u16 track;
    u8 data[20];
} elog_event_t;
typedef struct {
    u32 type_index_plus_one;
    char **enum_strings_vector;
    char *format;
    char *format_args;
    char *function;
    u32 n_enum_strings;
    char *enum_strings[];
} elog_event_type_t;
typedef struct {
    char *name;
    u32 track_index_plus_one;
} elog_track_t;
typedef struct {
    u64 cpu;
    u64 os_nsec;
} elog_time_stamp_t;
typedef struct {
    u32 n_total_events;
    u32 n_total_events_disable_limit;
    elog_event_t dummy_event;
    uword event_ring_size;
    elog_event_t *event_ring;
    elog_event_type_t *event_types;
    uword *event_type_by_format;
    char *string_table;
    elog_track_t *tracks;
    elog_track_t default_track;
    clib_time_t cpu_timer;
    elog_time_stamp_t init_time, serialize_time;
    uword *lock;
    f64 nsec_per_cpu_clock;
    elog_event_t *events;
} elog_main_t;
static inline __attribute__((__always_inline__)) uword
elog_n_events_in_buffer(elog_main_t *em)
{
    return ({
        __typeof__(em->n_total_events) _x  = (em->n_total_events);
        __typeof__(em->event_ring_size) _y = (em->event_ring_size);
        _x < _y ? _x : _y;
    });
}
static inline __attribute__((__always_inline__)) uword
elog_buffer_capacity(elog_main_t *em)
{
    return em->event_ring_size;
}
static inline __attribute__((__always_inline__)) void
elog_reset_buffer(elog_main_t *em)
{
    em->n_total_events               = 0;
    em->n_total_events_disable_limit = ~0;
}
static inline __attribute__((__always_inline__)) void
elog_enable_disable(elog_main_t *em, int is_enabled)
{
    em->n_total_events               = 0;
    em->n_total_events_disable_limit = is_enabled ? ~0 : 0;
}
static inline __attribute__((__always_inline__)) void
elog_disable_after_events(elog_main_t *em, uword n)
{
    em->n_total_events_disable_limit = em->n_total_events + n;
}
static inline __attribute__((__always_inline__)) void
elog_disable_trigger(elog_main_t *em)
{
    em->n_total_events_disable_limit =
        em->n_total_events + ((em->event_ring) ? (((vec_header_t *) (em->event_ring) - 1)->len) : 0) / 2;
}
word elog_event_type_register(elog_main_t *em, elog_event_type_t *t);
word elog_track_register(elog_main_t *em, elog_track_t *t);
static inline __attribute__((__always_inline__)) uword
elog_is_enabled(elog_main_t *em)
{
    return em->n_total_events < em->n_total_events_disable_limit;
}
static inline __attribute__((__always_inline__)) void *
elog_event_data_inline(elog_main_t *em, elog_event_type_t *type, elog_track_t *track, u64 cpu_time)
{
    elog_event_t *e;
    uword ei;
    word type_index, track_index;
    if (__builtin_expect((!elog_is_enabled(em)), 0))
        return em->dummy_event.data;
    type_index  = (word) type->type_index_plus_one - 1;
    track_index = (word) track->track_index_plus_one - 1;
    if (__builtin_expect(((type_index | track_index) < 0), 0)) {
        if (type_index < 0)
            type_index = elog_event_type_register(em, type);
        if (track_index < 0)
            track_index = elog_track_register(em, track);
    }
    do {
        if ((0 > 0) && !(track_index < ((em->tracks) ? (((vec_header_t *) (em->tracks) - 1)->len) : 0))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/elog.h", (uword) 312,
                        ((char *) __FUNCTION__), "track_index < vec_len (em->tracks)");
        }
    } while (0);
    do {
        if ((0 > 0) && !(is_pow2(((em->event_ring) ? (((vec_header_t *) (em->event_ring) - 1)->len) : 0)))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/elog.h", (uword) 313,
                        ((char *) __FUNCTION__), "is_pow2 (vec_len (em->event_ring))");
        }
    } while (0);
    if (em->lock)
        ei = __sync_fetch_and_add(&em->n_total_events, 1);
    else
        ei = em->n_total_events++;
    ei &= em->event_ring_size - 1;
    e              = ({
        do {
            if ((0 > 0) && !((ei) < ((em->event_ring) ? (((vec_header_t *) (em->event_ring) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/elog.h", (uword) 321,
                            ((char *) __FUNCTION__), "(ei) < vec_len (em->event_ring)");
            }
        } while (0);
        (em->event_ring) + (ei);
    });
    e->time_cycles = cpu_time;
    e->type        = type_index;
    e->track       = track_index;
    return e->data;
}
void *elog_event_data(elog_main_t *em, elog_event_type_t *type, elog_track_t *track, u64 cpu_time);
static inline __attribute__((__always_inline__)) void *
elog_event_data_not_inline(elog_main_t *em, elog_event_type_t *type, elog_track_t *track, u64 cpu_time)
{
    if (__builtin_expect((!elog_is_enabled(em)), 0))
        return em->dummy_event.data;
    return elog_event_data(em, type, track, cpu_time);
}
static inline __attribute__((__always_inline__)) void
elog(elog_main_t *em, elog_event_type_t *type, u32 data)
{
    u32 *d = elog_event_data_not_inline(em, type, &em->default_track, clib_cpu_time_now());
    d[0]   = data;
}
static inline __attribute__((__always_inline__)) void
elog_inline(elog_main_t *em, elog_event_type_t *type, u32 data)
{
    u32 *d = elog_event_data_inline(em, type, &em->default_track, clib_cpu_time_now());
    d[0]   = data;
}
static inline __attribute__((__always_inline__)) void
elog_track(elog_main_t *em, elog_event_type_t *type, elog_track_t *track, u32 data)
{
    u32 *d = elog_event_data_not_inline(em, type, track, clib_cpu_time_now());
    d[0]   = data;
}
static inline __attribute__((__always_inline__)) void
elog_track_inline(elog_main_t *em, elog_event_type_t *type, elog_track_t *track, u32 data)
{
    u32 *d = elog_event_data_inline(em, type, track, clib_cpu_time_now());
    d[0]   = data;
}
static inline __attribute__((__always_inline__)) void *
elog_data(elog_main_t *em, elog_event_type_t *type, elog_track_t *track)
{
    return elog_event_data_not_inline(em, type, track, clib_cpu_time_now());
}
static inline __attribute__((__always_inline__)) void *
elog_data_inline(elog_main_t *em, elog_event_type_t *type, elog_track_t *track)
{
    return elog_event_data_inline(em, type, track, clib_cpu_time_now());
}
u32 elog_string(elog_main_t *em, char *format, ...);
void elog_time_now(elog_time_stamp_t *et);
elog_event_t *elog_get_events(elog_main_t *em);
elog_event_t *elog_peek_events(elog_main_t *em);
void elog_merge(elog_main_t *dst, u8 *dst_tag, elog_main_t *src, u8 *src_tag, f64 align_tweak);
u8 *format_elog_event(u8 *s, va_list *va);
u8 *format_elog_track(u8 *s, va_list *va);
void serialize_elog_main(serialize_main_t *m, va_list *va);
void unserialize_elog_main(serialize_main_t *m, va_list *va);
void elog_init(elog_main_t *em, u32 n_events);
void elog_alloc(elog_main_t *em, u32 n_events);
static inline __attribute__((__always_inline__)) clib_error_t *
elog_write_file(elog_main_t *em, char *clib_file, int flush_ring)
{
    serialize_main_t m;
    clib_error_t *error;
    error = serialize_open_clib_file(&m, clib_file);
    if (error)
        return error;
    error = serialize(&m, serialize_elog_main, em, flush_ring);
    if (!error)
        serialize_close(&m);
    return error;
}
static inline __attribute__((__always_inline__)) clib_error_t *
elog_read_file(elog_main_t *em, char *clib_file)
{
    serialize_main_t m;
    clib_error_t *error;
    error = unserialize_open_clib_file(&m, clib_file);
    if (error)
        return error;
    error = unserialize(&m, unserialize_elog_main, em);
    if (!error)
        unserialize_close(&m);
    return error;
}
typedef struct {
    uword memory[(1 << (4))];
    uword a, b, c;
} isaac_t;
void isaac(isaac_t *ctx, uword *results);
void isaac2(isaac_t *ctx, uword *results);
void isaac_init(isaac_t *ctx, uword *results);
int test_isaac_main(unformat_input_t *input);
typedef struct {
    isaac_t ctx[2];
    uword *buffer;
    uword n_cached_bytes;
    union {
        u8 cached_bytes[sizeof(uword)];
        uword cached_word;
    };
} clib_random_buffer_t;
static inline __attribute__((__always_inline__)) void
clib_random_buffer_free(clib_random_buffer_t *b)
{
    do {
        if (b->buffer) {
            clib_mem_free(vec_header((b->buffer), (0)));
            b->buffer = 0;
        }
    } while (0);
}
void clib_random_buffer_fill(clib_random_buffer_t *b, uword n_words);
void clib_random_buffer_init(clib_random_buffer_t *b, uword seed);
static inline __attribute__((__always_inline__)) void *
clib_random_buffer_get_data(clib_random_buffer_t *b, uword n_bytes)
{
    uword n_words, i, l;
    l = b->n_cached_bytes;
    if (n_bytes <= l) {
        b->n_cached_bytes = l - n_bytes;
        return &b->cached_bytes[l];
    }
    n_words = n_bytes / sizeof(uword);
    if (n_bytes % sizeof(uword))
        n_words++;
    if (__builtin_expect((n_words > ((b->buffer) ? (((vec_header_t *) (b->buffer) - 1)->len) : 0)), 0))
        clib_random_buffer_fill(b, n_words);
    i                                         = ((b->buffer) ? (((vec_header_t *) (b->buffer) - 1)->len) : 0) - n_words;
    (((vec_header_t *) (b->buffer) - 1)->len) = i;
    if (n_bytes < sizeof(uword)) {
        b->cached_word    = b->buffer[i];
        b->n_cached_bytes = sizeof(uword) - n_bytes;
        return b->cached_bytes;
    } else
        return b->buffer + i;
}
typedef long int __jmp_buf[8];
enum { PTHREAD_CREATE_JOINABLE, PTHREAD_CREATE_DETACHED };
enum {
    PTHREAD_MUTEX_TIMED_NP,
    PTHREAD_MUTEX_RECURSIVE_NP,
    PTHREAD_MUTEX_ERRORCHECK_NP,
    PTHREAD_MUTEX_ADAPTIVE_NP,
    PTHREAD_MUTEX_NORMAL     = PTHREAD_MUTEX_TIMED_NP,
    PTHREAD_MUTEX_RECURSIVE  = PTHREAD_MUTEX_RECURSIVE_NP,
    PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
    PTHREAD_MUTEX_DEFAULT    = PTHREAD_MUTEX_NORMAL
};
enum {
    PTHREAD_MUTEX_STALLED,
    PTHREAD_MUTEX_STALLED_NP = PTHREAD_MUTEX_STALLED,
    PTHREAD_MUTEX_ROBUST,
    PTHREAD_MUTEX_ROBUST_NP = PTHREAD_MUTEX_ROBUST
};
enum { PTHREAD_PRIO_NONE, PTHREAD_PRIO_INHERIT, PTHREAD_PRIO_PROTECT };
enum {
    PTHREAD_RWLOCK_PREFER_READER_NP,
    PTHREAD_RWLOCK_PREFER_WRITER_NP,
    PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
    PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_READER_NP
};
enum { PTHREAD_INHERIT_SCHED, PTHREAD_EXPLICIT_SCHED };
enum { PTHREAD_SCOPE_SYSTEM, PTHREAD_SCOPE_PROCESS };
enum { PTHREAD_PROCESS_PRIVATE, PTHREAD_PROCESS_SHARED };
struct _pthread_cleanup_buffer {
    void (*__routine)(void *);
    void *__arg;
    int __canceltype;
    struct _pthread_cleanup_buffer *__prev;
};
enum { PTHREAD_CANCEL_ENABLE, PTHREAD_CANCEL_DISABLE };
enum { PTHREAD_CANCEL_DEFERRED, PTHREAD_CANCEL_ASYNCHRONOUS };
extern int pthread_create(pthread_t *__restrict __newthread, const pthread_attr_t *__restrict __attr,
                          void *(*__start_routine)(void *), void *__restrict __arg) __attribute__((__nothrow__))
__attribute__((__nonnull__(1, 3)));
extern void pthread_exit(void *__retval) __attribute__((__noreturn__));
extern int pthread_join(pthread_t __th, void **__thread_return);
extern int pthread_detach(pthread_t __th) __attribute__((__nothrow__, __leaf__));
extern pthread_t pthread_self(void) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int pthread_equal(pthread_t __thread1, pthread_t __thread2) __attribute__((__nothrow__, __leaf__))
__attribute__((__const__));
extern int pthread_attr_init(pthread_attr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_destroy(pthread_attr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_getdetachstate(const pthread_attr_t *__attr, int *__detachstate)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setdetachstate(pthread_attr_t *__attr, int __detachstate) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_getguardsize(const pthread_attr_t *__attr, size_t *__guardsize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setguardsize(pthread_attr_t *__attr, size_t __guardsize) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_getschedparam(const pthread_attr_t *__restrict __attr, struct sched_param *__restrict __param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setschedparam(pthread_attr_t *__restrict __attr, const struct sched_param *__restrict __param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_getschedpolicy(const pthread_attr_t *__restrict __attr, int *__restrict __policy)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setschedpolicy(pthread_attr_t *__attr, int __policy) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_getinheritsched(const pthread_attr_t *__restrict __attr, int *__restrict __inherit)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setinheritsched(pthread_attr_t *__attr, int __inherit) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_getscope(const pthread_attr_t *__restrict __attr, int *__restrict __scope)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setscope(pthread_attr_t *__attr, int __scope) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_getstackaddr(const pthread_attr_t *__restrict __attr, void **__restrict __stackaddr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2))) __attribute__((__deprecated__));
extern int pthread_attr_setstackaddr(pthread_attr_t *__attr, void *__stackaddr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1))) __attribute__((__deprecated__));
extern int pthread_attr_getstacksize(const pthread_attr_t *__restrict __attr, size_t *__restrict __stacksize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_attr_setstacksize(pthread_attr_t *__attr, size_t __stacksize) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_attr_getstack(const pthread_attr_t *__restrict __attr, void **__restrict __stackaddr,
                                 size_t *__restrict __stacksize) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2, 3)));
extern int pthread_attr_setstack(pthread_attr_t *__attr, void *__stackaddr, size_t __stacksize)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_setschedparam(pthread_t __target_thread, int __policy, const struct sched_param *__param)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3)));
extern int pthread_getschedparam(pthread_t __target_thread, int *__restrict __policy,
                                 struct sched_param *__restrict __param) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 3)));
extern int pthread_setschedprio(pthread_t __target_thread, int __prio) __attribute__((__nothrow__, __leaf__));
extern int pthread_once(pthread_once_t *__once_control, void (*__init_routine)(void)) __attribute__((__nonnull__(1, 2)));
extern int pthread_setcancelstate(int __state, int *__oldstate);
extern int pthread_setcanceltype(int __type, int *__oldtype);
extern int pthread_cancel(pthread_t __th);
extern void pthread_testcancel(void);
typedef struct {
    struct {
        __jmp_buf __cancel_jmp_buf;
        int __mask_was_saved;
    } __cancel_jmp_buf[1];
    void *__pad[4];
} __pthread_unwind_buf_t __attribute__((__aligned__));
struct __pthread_cleanup_frame {
    void (*__cancel_routine)(void *);
    void *__cancel_arg;
    int __do_it;
    int __cancel_type;
};
extern void __pthread_register_cancel(__pthread_unwind_buf_t *__buf);
extern void __pthread_unregister_cancel(__pthread_unwind_buf_t *__buf);
extern void __pthread_unwind_next(__pthread_unwind_buf_t *__buf) __attribute__((__noreturn__)) __attribute__((__weak__));
struct __jmp_buf_tag;
extern int __sigsetjmp(struct __jmp_buf_tag *__env, int __savemask) __attribute__((__nothrow__));
extern int pthread_mutex_init(pthread_mutex_t *__mutex, const pthread_mutexattr_t *__mutexattr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutex_destroy(pthread_mutex_t *__mutex) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_mutex_trylock(pthread_mutex_t *__mutex) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_mutex_lock(pthread_mutex_t *__mutex) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_mutex_timedlock(pthread_mutex_t *__restrict __mutex, const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutex_unlock(pthread_mutex_t *__mutex) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_mutex_getprioceiling(const pthread_mutex_t *__restrict __mutex, int *__restrict __prioceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutex_setprioceiling(pthread_mutex_t *__restrict __mutex, int __prioceiling,
                                        int *__restrict __old_ceiling) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 3)));
extern int pthread_mutex_consistent(pthread_mutex_t *__mutex) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_mutexattr_init(pthread_mutexattr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_mutexattr_destroy(pthread_mutexattr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getpshared(const pthread_mutexattr_t *__restrict __attr, int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_setpshared(pthread_mutexattr_t *__attr, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_gettype(const pthread_mutexattr_t *__restrict __attr, int *__restrict __kind)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_settype(pthread_mutexattr_t *__attr, int __kind) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getprotocol(const pthread_mutexattr_t *__restrict __attr, int *__restrict __protocol)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_setprotocol(pthread_mutexattr_t *__attr, int __protocol)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *__restrict __attr, int *__restrict __prioceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *__attr, int __prioceiling)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_mutexattr_getrobust(const pthread_mutexattr_t *__attr, int *__robustness)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_mutexattr_setrobust(pthread_mutexattr_t *__attr, int __robustness)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlock_init(pthread_rwlock_t *__restrict __rwlock, const pthread_rwlockattr_t *__restrict __attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlock_destroy(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlock_rdlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlock_tryrdlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlock_timedrdlock(pthread_rwlock_t *__restrict __rwlock, const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlock_wrlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlock_trywrlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlock_timedwrlock(pthread_rwlock_t *__restrict __rwlock, const struct timespec *__restrict __abstime)
    __attribute__((__nothrow__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlock_unlock(pthread_rwlock_t *__rwlock) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_init(pthread_rwlockattr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_destroy(pthread_rwlockattr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *__restrict __attr, int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *__attr, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_rwlockattr_getkind_np(const pthread_rwlockattr_t *__restrict __attr, int *__restrict __pref)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_rwlockattr_setkind_np(pthread_rwlockattr_t *__attr, int __pref)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_cond_init(pthread_cond_t *__restrict __cond, const pthread_condattr_t *__restrict __cond_attr)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_cond_destroy(pthread_cond_t *__cond) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_cond_signal(pthread_cond_t *__cond) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_cond_broadcast(pthread_cond_t *__cond) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_cond_wait(pthread_cond_t *__restrict __cond, pthread_mutex_t *__restrict __mutex)
    __attribute__((__nonnull__(1, 2)));
extern int pthread_cond_timedwait(pthread_cond_t *__restrict __cond, pthread_mutex_t *__restrict __mutex,
                                  const struct timespec *__restrict __abstime) __attribute__((__nonnull__(1, 2, 3)));
extern int pthread_condattr_init(pthread_condattr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_condattr_destroy(pthread_condattr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_condattr_getpshared(const pthread_condattr_t *__restrict __attr, int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_condattr_setpshared(pthread_condattr_t *__attr, int __pshared) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_condattr_getclock(const pthread_condattr_t *__restrict __attr, __clockid_t *__restrict __clock_id)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_condattr_setclock(pthread_condattr_t *__attr, __clockid_t __clock_id)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_spin_init(pthread_spinlock_t *__lock, int __pshared) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_spin_destroy(pthread_spinlock_t *__lock) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_spin_lock(pthread_spinlock_t *__lock) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_spin_trylock(pthread_spinlock_t *__lock) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_spin_unlock(pthread_spinlock_t *__lock) __attribute__((__nothrow__)) __attribute__((__nonnull__(1)));
extern int pthread_barrier_init(pthread_barrier_t *__restrict __barrier, const pthread_barrierattr_t *__restrict __attr,
                                unsigned int __count) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_barrier_destroy(pthread_barrier_t *__barrier) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_barrier_wait(pthread_barrier_t *__barrier) __attribute__((__nothrow__))
__attribute__((__nonnull__(1)));
extern int pthread_barrierattr_init(pthread_barrierattr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_barrierattr_destroy(pthread_barrierattr_t *__attr) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int pthread_barrierattr_getpshared(const pthread_barrierattr_t *__restrict __attr, int *__restrict __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1, 2)));
extern int pthread_barrierattr_setpshared(pthread_barrierattr_t *__attr, int __pshared)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_key_create(pthread_key_t *__key, void (*__destr_function)(void *))
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int pthread_key_delete(pthread_key_t __key) __attribute__((__nothrow__, __leaf__));
extern void *pthread_getspecific(pthread_key_t __key) __attribute__((__nothrow__, __leaf__));
extern int pthread_setspecific(pthread_key_t __key, const void *__pointer) __attribute__((__nothrow__, __leaf__));
extern int pthread_getcpuclockid(pthread_t __thread_id, __clockid_t *__clock_id) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern int pthread_atfork(void (*__prepare)(void), void (*__parent)(void), void (*__child)(void))
    __attribute__((__nothrow__, __leaf__));
typedef struct vlib_main_t {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    clib_time_t clib_time;
    u64 cpu_time_last_node_dispatch;
    u64 cpu_time_main_loop_start;
    u32 main_loop_count;
    u32 main_loop_vectors_processed;
    u32 main_loop_nodes_processed;
    u32 vector_counts_per_main_loop[2];
    u32 node_counts_per_main_loop[2];
    u32 main_loop_exit_set;
    volatile u32 main_loop_exit_now;
    clib_longjmp_t main_loop_exit;
    clib_error_t *main_loop_error;
    char *name;
    void *heap_base;
    void *heap_aligned_base;
    uword heap_size;
    vlib_buffer_free_list_t *buffer_free_list_pool;
    clib_error_t *(*os_physmem_region_alloc)(struct vlib_main_t *vm, char *name, u32 size, u8 numa_node, u32 flags,
                                             vlib_physmem_region_index_t *idx);
    void (*os_physmem_region_free)(struct vlib_main_t *vm, vlib_physmem_region_index_t idx);
    void *(*os_physmem_alloc_aligned)(struct vlib_main_t *vm, vlib_physmem_region_index_t idx, uword n_bytes,
                                      uword alignment);
    void (*os_physmem_free)(struct vlib_main_t *vm, vlib_physmem_region_index_t idx, void *x);
    vlib_node_main_t node_main;
    vlib_cli_main_t cli_main;
    vlib_trace_main_t trace_main;
    vlib_error_main_t error_main;
    void (*os_punt_frame)(struct vlib_main_t *vm, struct vlib_node_runtime_t *node, vlib_frame_t *frame);
    u32 mc_stream_index;
    vlib_one_time_waiting_process_t *procs_waiting_for_mc_stream_join;
    elog_main_t elog_main;
    int elog_trace_api_messages;
    int elog_trace_cli_commands;
    elog_event_type_t *node_call_elog_event_types;
    elog_event_type_t *node_return_elog_event_types;
    elog_event_type_t *error_elog_event_types;
    uword random_seed;
    clib_random_buffer_t random_buffer;
    uword *init_functions_called;
    u32 thread_index;
    _vlib_init_function_list_elt_t *init_function_registrations;
    _vlib_init_function_list_elt_t *worker_init_function_registrations;
    _vlib_init_function_list_elt_t *main_loop_enter_function_registrations;
    _vlib_init_function_list_elt_t *main_loop_exit_function_registrations;
    _vlib_init_function_list_elt_t *api_init_function_registrations;
    vlib_config_function_runtime_t *config_function_registrations;
    volatile u32 queue_signal_pending;
    volatile u32 api_queue_nonempty;
    void (*queue_signal_callback)(struct vlib_main_t *);
    u8 **argv;
    volatile int parked_at_barrier;
    int elog_post_mortem_dump;
    int need_vlib_worker_thread_node_runtime_update;
    f64 barrier_epoch;
    f64 barrier_no_close_before;
    uword *pending_rpc_requests;
} vlib_main_t;
extern vlib_main_t vlib_global_main;
void vlib_worker_loop(vlib_main_t *vm);
static inline __attribute__((__always_inline__)) f64
vlib_time_now(vlib_main_t *vm)
{
    return clib_time_now(&vm->clib_time);
}
static inline __attribute__((__always_inline__)) f64
vlib_time_now_ticks(vlib_main_t *vm, u64 n)
{
    return clib_time_now_internal(&vm->clib_time, n);
}
static inline __attribute__((__always_inline__)) void
vlib_time_wait(vlib_main_t *vm, f64 wait)
{
    f64 t     = vlib_time_now(vm);
    f64 limit = t + wait;
    while (t < limit)
        t = vlib_time_now(vm);
}
static inline __attribute__((__always_inline__)) void
vlib_panic_with_error(vlib_main_t *vm, clib_error_t *error)
{
    vm->main_loop_error = error;
    clib_longjmp(&vm->main_loop_exit, 1);
}
static inline __attribute__((__always_inline__)) void
vlib_panic(vlib_main_t *vm)
{
    vlib_panic_with_error(vm, 0);
}
static inline __attribute__((__always_inline__)) u32
vlib_vector_input_stats_index(vlib_main_t *vm, word delta)
{
    u32 i;
    i = vm->main_loop_count >> 7;
    do {
        if ((0 > 0) &&
            !(is_pow2((sizeof(vm->vector_counts_per_main_loop) / sizeof(vm->vector_counts_per_main_loop[0]))))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/main.h", (uword) 292,
                        ((char *) __FUNCTION__), "is_pow2 (ARRAY_LEN (vm->vector_counts_per_main_loop))");
        }
    } while (0);
    return (i + delta) & ((sizeof(vm->vector_counts_per_main_loop) / sizeof(vm->vector_counts_per_main_loop[0])) - 1);
}
static inline __attribute__((__always_inline__)) u32
vlib_last_vectors_per_main_loop(vlib_main_t *vm)
{
    u32 i = vlib_vector_input_stats_index(vm, -1);
    u32 n = vm->vector_counts_per_main_loop[i];
    return n >> 7;
}
static inline __attribute__((__always_inline__)) f64
vlib_last_vectors_per_main_loop_as_f64(vlib_main_t *vm)
{
    u32 i = vlib_vector_input_stats_index(vm, -1);
    u32 v = vm->vector_counts_per_main_loop[i];
    return (f64) v / (f64)(1 << 7);
}
static inline __attribute__((__always_inline__)) f64
vlib_last_vector_length_per_node(vlib_main_t *vm)
{
    u32 i = vlib_vector_input_stats_index(vm, -1);
    u32 v = vm->vector_counts_per_main_loop[i];
    u32 n = vm->node_counts_per_main_loop[i];
    return n == 0 ? 0 : (f64) v / (f64) n;
}
extern u32 wraps;
static inline __attribute__((__always_inline__)) void
vlib_increment_main_loop_counter(vlib_main_t *vm)
{
    u32 i, c, n, v, is_wrap;
    c       = vm->main_loop_count++;
    is_wrap = (c & pow2_mask(7)) == 0;
    if (is_wrap)
        wraps++;
    i = vlib_vector_input_stats_index(vm, is_wrap);
    v = is_wrap ? 0 : vm->vector_counts_per_main_loop[i];
    n = is_wrap ? 0 : vm->node_counts_per_main_loop[i];
    v += vm->main_loop_vectors_processed;
    n += vm->main_loop_nodes_processed;
    vm->main_loop_vectors_processed    = 0;
    vm->main_loop_nodes_processed      = 0;
    vm->vector_counts_per_main_loop[i] = v;
    vm->node_counts_per_main_loop[i]   = n;
    if (__builtin_expect((vm->main_loop_exit_now), 0))
        clib_longjmp(&vm->main_loop_exit, 2);
}
static inline __attribute__((__always_inline__)) void
vlib_set_queue_signal_callback(vlib_main_t *vm, void (*fp)(vlib_main_t *))
{
    vm->queue_signal_callback = fp;
}
int vlib_main(vlib_main_t *vm, unformat_input_t *input);
extern u8 **vlib_thread_stacks;
u32 vlib_app_num_thread_stacks_needed(void) __attribute__((weak));
extern void vlib_node_sync_stats(vlib_main_t *vm, vlib_node_t *n);
extern vlib_main_t **vlib_mains;
void vlib_set_thread_name(char *name);
typedef void(vlib_thread_function_t)(void *arg);
typedef struct vlib_thread_registration_ {
    struct vlib_thread_registration_ *next;
    char *name;
    char *short_name;
    vlib_thread_function_t *function;
    uword mheap_size;
    int fixed_count;
    u32 count;
    int no_data_structure_clone;
    u32 frame_queue_nelts;
    int use_pthreads;
    u32 first_index;
    uword *coremask;
} vlib_thread_registration_t;
typedef enum {
    VLIB_FRAME_QUEUE_ELT_DISPATCH_FRAME,
} vlib_frame_queue_msg_type_t;
typedef struct {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    volatile u32 valid;
    u32 msg_type;
    u32 n_vectors;
    u32 last_n_vectors;
    u32 buffer_index[256];
} vlib_frame_queue_elt_t;
typedef struct {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    volatile u32 *wait_at_barrier;
    volatile u32 *workers_at_barrier;
    u8 cacheline1[0] __attribute__((aligned((1 << 6))));
    void *thread_mheap;
    u8 *thread_stack;
    void (*thread_function)(void *);
    void *thread_function_arg;
    i64 recursion_level;
    elog_track_t elog_track;
    u32 instance_id;
    vlib_thread_registration_t *registration;
    u8 *name;
    u64 barrier_sync_count;
    u8 barrier_elog_enabled;
    const char *barrier_caller;
    const char *barrier_context;
    volatile u32 *node_reforks_required;
    long lwp;
    int cpu_id;
    int core_id;
    int socket_id;
    pthread_t thread_id;
} vlib_worker_thread_t;
extern vlib_worker_thread_t *vlib_worker_threads;
typedef struct {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    volatile u64 tail;
    u64 enqueues;
    u64 enqueue_ticks;
    u64 enqueue_vectors;
    u32 enqueue_full_events;
    u8 cacheline1[0] __attribute__((aligned((1 << 6))));
    volatile u64 head;
    u64 dequeues;
    u64 dequeue_ticks;
    u64 dequeue_vectors;
    u64 trace;
    u64 vector_threshold;
    u8 cacheline2[0] __attribute__((aligned((1 << 6))));
    volatile u64 head_hint;
    u8 cacheline3[0] __attribute__((aligned((1 << 6))));
    vlib_frame_queue_elt_t *elts;
    u32 nelts;
} vlib_frame_queue_t;
typedef struct {
    vlib_frame_queue_elt_t **handoff_queue_elt_by_thread_index;
    vlib_frame_queue_t **congested_handoff_queue_by_thread_index;
} vlib_frame_queue_per_thread_data_t;
typedef struct {
    u32 node_index;
    u32 frame_queue_nelts;
    u32 queue_hi_thresh;
    vlib_frame_queue_t **vlib_frame_queues;
    vlib_frame_queue_per_thread_data_t *per_thread_data;
    frame_queue_trace_t *frame_queue_traces;
    frame_queue_nelt_counter_t *frame_queue_histogram;
} vlib_frame_queue_main_t;
typedef struct {
    uword node_index;
    uword type_opaque;
    uword data;
} vlib_process_signal_event_mt_args_t;
clib_error_t *vlib_thread_init(vlib_main_t *vm);
int vlib_frame_queue_enqueue(vlib_main_t *vm, u32 node_runtime_index, u32 frame_queue_index, vlib_frame_t *frame,
                             vlib_frame_queue_msg_type_t type);
int vlib_frame_queue_dequeue(vlib_main_t *vm, vlib_frame_queue_main_t *fqm);
void vlib_worker_thread_node_runtime_update(void);
void vlib_create_worker_threads(vlib_main_t *vm, int n, void (*thread_function)(void *));
void vlib_worker_thread_init(vlib_worker_thread_t *w);
u32 vlib_frame_queue_main_init(u32 node_index, u32 frame_queue_nelts);
void vlib_worker_thread_barrier_sync_int(vlib_main_t *vm);
void vlib_worker_thread_barrier_release(vlib_main_t *vm);
void vlib_worker_thread_node_refork(void);
static inline __attribute__((__always_inline__)) uword
vlib_get_thread_index(void)
{
    return __os_thread_index;
}
static inline __attribute__((__always_inline__)) void
vlib_smp_unsafe_warning(void)
{
    if (0 > 0) {
        if (vlib_get_thread_index())
            fformat(stderr, "%s: SMP unsafe warning...\n", __FUNCTION__);
    }
}
typedef enum {
    VLIB_WORKER_THREAD_FORK_FIXUP_ILLEGAL = 0,
    VLIB_WORKER_THREAD_FORK_FIXUP_NEW_SW_IF_INDEX,
} vlib_fork_fixup_t;
void vlib_worker_thread_fork_fixup(vlib_fork_fixup_t which);
typedef enum {
    SCHED_POLICY_OTHER = 0,
    SCHED_POLICY_BATCH = 3,
    SCHED_POLICY_IDLE  = 5,
    SCHED_POLICY_FIFO  = 1,
    SCHED_POLICY_RR    = 2,
    SCHED_POLICY_N,
} sched_policy_t;
typedef struct {
    clib_error_t *(*vlib_launch_thread_cb)(void *fp, vlib_worker_thread_t *w, unsigned cpu_id);
    clib_error_t *(*vlib_thread_set_lcore_cb)(u32 thread, u16 cpu);
} vlib_thread_callbacks_t;
typedef struct {
    vlib_thread_registration_t *next;
    vlib_thread_registration_t **registrations;
    uword *thread_registrations_by_name;
    vlib_worker_thread_t *worker_threads;
    int use_pthreads;
    u32 n_vlib_mains;
    u32 n_thread_stacks;
    u32 n_pthreads;
    u32 n_threads;
    u32 skip_cores;
    u8 *thread_prefix;
    u32 main_lcore;
    uword *cpu_core_bitmap;
    uword *cpu_socket_bitmap;
    vlib_frame_queue_main_t *frame_queue_mains;
    volatile u32 worker_thread_release;
    u32 sched_policy;
    u32 sched_priority;
    vlib_thread_callbacks_t cb;
    int extern_thread_mgmt;
} vlib_thread_main_t;
extern vlib_thread_main_t vlib_thread_main;
static inline __attribute__((__always_inline__)) vlib_main_t *
vlib_get_main(void)
{
    vlib_main_t *vm;
    vm = vlib_mains[vlib_get_thread_index()];
    do {
        if ((0 > 0) && !(vm)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/global_funcs.h", (uword) 27,
                        ((char *) __FUNCTION__), "vm");
        }
    } while (0);
    return vm;
}
static inline __attribute__((__always_inline__)) vlib_thread_main_t *
vlib_get_thread_main()
{
    return &vlib_thread_main;
}
static inline __attribute__((__always_inline__)) u32
vlib_num_workers()
{
    return vlib_thread_main.n_vlib_mains - 1;
}
static inline __attribute__((__always_inline__)) u32
vlib_get_worker_thread_index(u32 worker_index)
{
    return worker_index + 1;
}
static inline __attribute__((__always_inline__)) u32
vlib_get_worker_index(u32 thread_index)
{
    return thread_index - 1;
}
static inline __attribute__((__always_inline__)) u32
vlib_get_current_worker_index()
{
    return vlib_get_thread_index() - 1;
}
static inline void
vlib_worker_thread_barrier_check(void)
{
    if (__builtin_expect((*vlib_worker_threads->wait_at_barrier), 0)) {
        vlib_main_t *vm  = vlib_get_main();
        u32 thread_index = vm->thread_index;
        f64 t            = vlib_time_now(vm);
        if (__builtin_expect((vlib_worker_threads->barrier_elog_enabled), 0)) {
            vlib_worker_thread_t *w    = vlib_worker_threads + thread_index;
            static elog_event_type_t e = {
                .format      = "barrier-wait-thread-%d",
                .format_args = "i4",
            };
            struct {
                u32 thread_index;
            } __attribute__((packed)) * ed;
            ed               = elog_data((&vlib_global_main.elog_main), &e, &w->elog_track);
            ed->thread_index = thread_index;
        }
        __sync_fetch_and_add(vlib_worker_threads->workers_at_barrier, 1);
        if (0 > 0) {
            vm                    = vlib_get_main();
            vm->parked_at_barrier = 1;
        }
        while (*vlib_worker_threads->wait_at_barrier)
            ;
        if (0 > 0)
            vm->parked_at_barrier = 0;
        __sync_fetch_and_add(vlib_worker_threads->workers_at_barrier, -1);
        if (__builtin_expect((*vlib_worker_threads->node_reforks_required), 0)) {
            if (__builtin_expect((vlib_worker_threads->barrier_elog_enabled), 0)) {
                t                          = vlib_time_now(vm) - t;
                vlib_worker_thread_t *w    = vlib_worker_threads + thread_index;
                static elog_event_type_t e = {
                    .format      = "barrier-refork-thread-%d",
                    .format_args = "i4",
                };
                struct {
                    u32 thread_index;
                } __attribute__((packed)) * ed;
                ed               = elog_data((&vlib_global_main.elog_main), &e, &w->elog_track);
                ed->thread_index = thread_index;
            }
            vlib_worker_thread_node_refork();
            __sync_fetch_and_add(vlib_worker_threads->node_reforks_required, -1);
            while (*vlib_worker_threads->node_reforks_required)
                ;
        }
        if (__builtin_expect((vlib_worker_threads->barrier_elog_enabled), 0)) {
            t                          = vlib_time_now(vm) - t;
            vlib_worker_thread_t *w    = vlib_worker_threads + thread_index;
            static elog_event_type_t e = {
                .format      = "barrier-released-thread-%d: %dus",
                .format_args = "i4i4",
            };
            struct {
                u32 thread_index;
                u32 duration;
            } __attribute__((packed)) * ed;
            ed               = elog_data((&vlib_global_main.elog_main), &e, &w->elog_track);
            ed->thread_index = thread_index;
            ed->duration     = (int) (1000000.0 * t);
        }
    }
}
static inline __attribute__((__always_inline__)) vlib_main_t *
vlib_get_worker_vlib_main(u32 worker_index)
{
    vlib_main_t *vm;
    vlib_thread_main_t *tm = &vlib_thread_main;
    do {
        if ((0 > 0) && !(worker_index < tm->n_vlib_mains - 1)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/threads.h", (uword) 488,
                        ((char *) __FUNCTION__), "worker_index < tm->n_vlib_mains - 1");
        }
    } while (0);
    vm = vlib_mains[worker_index + 1];
    do {
        if ((0 > 0) && !(vm)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/threads.h", (uword) 490,
                        ((char *) __FUNCTION__), "vm");
        }
    } while (0);
    return vm;
}
static inline u8
vlib_thread_is_main_w_barrier(void)
{
    return (!vlib_num_workers() || ((vlib_get_thread_index() == 0 && vlib_worker_threads->wait_at_barrier[0])));
}
static inline void
vlib_put_frame_queue_elt(vlib_frame_queue_elt_t *hf)
{
    __sync_synchronize();
    hf->valid = 1;
}
static inline vlib_frame_queue_elt_t *
vlib_get_frame_queue_elt(u32 frame_queue_index, u32 index)
{
    vlib_frame_queue_t *fq;
    vlib_frame_queue_elt_t *elt;
    vlib_thread_main_t *tm       = &vlib_thread_main;
    vlib_frame_queue_main_t *fqm = ({
        do {
            if ((0 > 0) && !((frame_queue_index) <
                             ((tm->frame_queue_mains) ? (((vec_header_t *) (tm->frame_queue_mains) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/threads.h", (uword) 516,
                            ((char *) __FUNCTION__), "(frame_queue_index) < vec_len (tm->frame_queue_mains)");
            }
        } while (0);
        (tm->frame_queue_mains) + (frame_queue_index);
    });
    u64 new_tail;
    fq = fqm->vlib_frame_queues[index];
    do {
        if ((0 > 0) && !(fq)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/threads.h", (uword) 520,
                        ((char *) __FUNCTION__), "fq");
        }
    } while (0);
    new_tail = __sync_add_and_fetch(&fq->tail, 1);
    while (new_tail >= fq->head_hint + fq->nelts)
        vlib_worker_thread_barrier_check();
    elt = fq->elts + (new_tail & (fq->nelts - 1));
    while (elt->valid)
        ;
    elt->msg_type       = VLIB_FRAME_QUEUE_ELT_DISPATCH_FRAME;
    elt->last_n_vectors = elt->n_vectors = 0;
    return elt;
}
static inline vlib_frame_queue_t *
is_vlib_frame_queue_congested(u32 frame_queue_index, u32 index, u32 queue_hi_thresh,
                              vlib_frame_queue_t **handoff_queue_by_worker_index)
{
    vlib_frame_queue_t *fq;
    vlib_thread_main_t *tm       = &vlib_thread_main;
    vlib_frame_queue_main_t *fqm = ({
        do {
            if ((0 > 0) && !((frame_queue_index) <
                             ((tm->frame_queue_mains) ? (((vec_header_t *) (tm->frame_queue_mains) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/threads.h", (uword) 550,
                            ((char *) __FUNCTION__), "(frame_queue_index) < vec_len (tm->frame_queue_mains)");
            }
        } while (0);
        (tm->frame_queue_mains) + (frame_queue_index);
    });
    fq                           = handoff_queue_by_worker_index[index];
    if (fq != (vlib_frame_queue_t *) (~0))
        return fq;
    fq = fqm->vlib_frame_queues[index];
    do {
        if ((0 > 0) && !(fq)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/threads.h", (uword) 557,
                        ((char *) __FUNCTION__), "fq");
        }
    } while (0);
    if (__builtin_expect((fq->tail >= (fq->head_hint + queue_hi_thresh)), 0)) {
        handoff_queue_by_worker_index[index] = fq;
        fq->enqueue_full_events++;
        return fq;
    }
    return ((void *) 0);
}
static inline vlib_frame_queue_elt_t *
vlib_get_worker_handoff_queue_elt(u32 frame_queue_index, u32 vlib_worker_index,
                                  vlib_frame_queue_elt_t **handoff_queue_elt_by_worker_index)
{
    vlib_frame_queue_elt_t *elt;
    if (handoff_queue_elt_by_worker_index[vlib_worker_index])
        return handoff_queue_elt_by_worker_index[vlib_worker_index];
    elt = vlib_get_frame_queue_elt(frame_queue_index, vlib_worker_index);
    handoff_queue_elt_by_worker_index[vlib_worker_index] = elt;
    return elt;
}
u8 *vlib_thread_stack_init(uword thread_index);
int vlib_thread_cb_register(struct vlib_main_t *vm, vlib_thread_callbacks_t *cb);
extern void *rpc_call_main_thread_cb_fn;
void vlib_process_signal_event_mt_helper(vlib_process_signal_event_mt_args_t *args);
void vlib_rpc_call_main_thread(void *function, u8 *args, u32 size);
u32 elog_global_id_for_msg_name(const char *msg_name);
static inline __attribute__((__always_inline__)) vlib_physmem_region_t *
vlib_physmem_get_region(vlib_main_t *vm, u8 index)
{
    vlib_physmem_main_t *vpm = &physmem_main;
    return ({
        typeof(vpm->regions) _e = (vpm->regions) + (index);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(vpm->regions);
                    uword _pool_i          = (_e) - (vpm->regions);
                    (_pool_i < ((vpm->regions) ? (((vec_header_t *) (vpm->regions) - 1)->len) : 0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/physmem_funcs.h", (uword) 47,
                            ((char *) __FUNCTION__), "! pool_is_free (vpm->regions, _e)");
            }
        } while (0);
        _e;
    });
}
static inline __attribute__((__always_inline__)) u64
vlib_physmem_offset_to_physical(vlib_main_t *vm, vlib_physmem_region_index_t idx, uword o)
{
    vlib_physmem_region_t *pr = vlib_physmem_get_region(vm, idx);
    uword page_index          = o >> pr->log2_page_size;
    do {
        if ((0 > 0) && !(o < pr->size)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/physmem_funcs.h", (uword) 56,
                        ((char *) __FUNCTION__), "o < pr->size");
        }
    } while (0);
    do {
        if ((0 > 0) && !(pr->page_table[page_index] != 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/physmem_funcs.h", (uword) 57,
                        ((char *) __FUNCTION__), "pr->page_table[page_index] != 0");
        }
    } while (0);
    return ((({
                do {
                    if ((0 > 0) &&
                        !((page_index) < ((pr->page_table) ? (((vec_header_t *) (pr->page_table) - 1)->len) : 0))) {
                        _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                    "../../../build-root/install-vpp_debug-native/vpp/include/vlib/physmem_funcs.h",
                                    (uword) 58, ((char *) __FUNCTION__), "(page_index) < vec_len (pr->page_table)");
                    }
                } while (0);
                (pr->page_table) + (page_index);
            }))[0] +
            (o & pr->page_mask));
}
static inline __attribute__((__always_inline__)) int
vlib_physmem_is_virtual(vlib_main_t *vm, vlib_physmem_region_index_t idx, uword p)
{
    vlib_physmem_region_t *pr = vlib_physmem_get_region(vm, idx);
    return p >= pointer_to_uword(pr->mem) && p < (pointer_to_uword(pr->mem) + pr->size);
}
static inline __attribute__((__always_inline__)) uword
vlib_physmem_offset_of(vlib_main_t *vm, vlib_physmem_region_index_t idx, void *p)
{
    vlib_physmem_region_t *pr = vlib_physmem_get_region(vm, idx);
    uword a                   = pointer_to_uword(p);
    uword o;
    do {
        if ((0 > 0) && !(vlib_physmem_is_virtual(vm, idx, a))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/physmem_funcs.h", (uword) 78,
                        ((char *) __FUNCTION__), "vlib_physmem_is_virtual (vm, idx, a)");
        }
    } while (0);
    o = a - pointer_to_uword(pr->mem);
    do {
        if ((0 > 0) && !((uword) o == a - pointer_to_uword(pr->mem))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/physmem_funcs.h", (uword) 82,
                        ((char *) __FUNCTION__), "(uword) o == a - pointer_to_uword (pr->mem)");
        }
    } while (0);
    return o;
}
static inline __attribute__((__always_inline__)) void *
vlib_physmem_at_offset(vlib_main_t *vm, vlib_physmem_region_index_t idx, uword offset)
{
    vlib_physmem_region_t *pr = vlib_physmem_get_region(vm, idx);
    do {
        if ((0 > 0) && !(offset < pr->size)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/physmem_funcs.h", (uword) 92,
                        ((char *) __FUNCTION__), "offset < pr->size");
        }
    } while (0);
    return ((void *) (clib_address_t)(pointer_to_uword(pr->mem) + offset));
}
static inline __attribute__((__always_inline__)) void *
vlib_physmem_alloc_aligned(vlib_main_t *vm, vlib_physmem_region_index_t idx, clib_error_t **error, uword n_bytes,
                           uword alignment)
{
    void *r = vm->os_physmem_alloc_aligned(vm, idx, n_bytes, alignment);
    if (!r)
        *error = _clib_error_return((0), (0), (0), (char *) ((char *) __FUNCTION__),
                                    "failed to allocate %wd bytes of I/O memory", n_bytes);
    else
        *error = 0;
    return r;
}
static inline __attribute__((__always_inline__)) void *
vlib_physmem_alloc(vlib_main_t *vm, vlib_physmem_region_index_t idx, clib_error_t **error, uword n_bytes)
{
    return vlib_physmem_alloc_aligned(vm, idx, error, n_bytes, (1 << 6));
}
static inline __attribute__((__always_inline__)) void
vlib_physmem_free(vlib_main_t *vm, vlib_physmem_region_index_t idx, void *mem)
{
    if (mem)
        vm->os_physmem_free(vm, idx, mem);
}
static inline __attribute__((__always_inline__)) u64
vlib_physmem_virtual_to_physical(vlib_main_t *vm, vlib_physmem_region_index_t idx, void *mem)
{
    vlib_physmem_main_t *vpm  = &physmem_main;
    vlib_physmem_region_t *pr = ({
        typeof(vpm->regions) _e = (vpm->regions) + (idx);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(vpm->regions);
                    uword _pool_i          = (_e) - (vpm->regions);
                    (_pool_i < ((vpm->regions) ? (((vec_header_t *) (vpm->regions) - 1)->len) : 0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/physmem_funcs.h",
                            (uword) 133, ((char *) __FUNCTION__), "! pool_is_free (vpm->regions, _e)");
            }
        } while (0);
        _e;
    });
    uword o                   = mem - pr->mem;
    return vlib_physmem_offset_to_physical(vm, idx, o);
}
static inline __attribute__((__always_inline__)) clib_error_t *
vlib_physmem_region_alloc(vlib_main_t *vm, char *name, u32 size, u8 numa_node, u32 flags, vlib_physmem_region_index_t *idx)
{
    return vm->os_physmem_region_alloc(vm, name, size, numa_node, flags, idx);
}
static inline __attribute__((__always_inline__)) void
vlib_physmem_region_free(struct vlib_main_t *vm, vlib_physmem_region_index_t idx)
{
    vm->os_physmem_region_free(vm, idx);
}
typedef struct {
    u32 head_index;
    u32 tail_index;
} clib_fifo_header_t;
static inline __attribute__((__always_inline__)) clib_fifo_header_t *
clib_fifo_header(void *f)
{
    return vec_header(f, sizeof(clib_fifo_header_t));
}
static inline __attribute__((__always_inline__)) uword
clib_fifo_elts(void *v)
{
    word l, r;
    clib_fifo_header_t *f = clib_fifo_header(v);
    if (!v)
        return 0;
    l = (((vec_header_t *) (v) -1)->len);
    r = (word) f->tail_index - (word) f->head_index;
    r = r < 0 ? r + l : r;
    do {
        if ((0 > 0) && !(r >= 0 && r <= l)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/fifo.h", (uword) 77,
                        ((char *) __FUNCTION__), "r >= 0 && r <= l");
        }
    } while (0);
    return r;
}
static inline __attribute__((__always_inline__)) uword
clib_fifo_free_elts(void *v)
{
    return ((v) ? (((vec_header_t *) (v) -1)->len) : 0) - clib_fifo_elts(v);
}
static inline __attribute__((__always_inline__)) void
clib_fifo_reset(void *v)
{
    clib_fifo_header_t *f = clib_fifo_header(v);
    if (v) {
        f->head_index = f->tail_index    = 0;
        (((vec_header_t *) (v) -1)->len) = 0;
    }
}
void *_clib_fifo_resize(void *v, uword n_elts, uword elt_bytes);
static inline __attribute__((__always_inline__)) void *
_clib_fifo_validate(void *v, uword n_elts, uword elt_bytes)
{
    if (clib_fifo_free_elts(v) < n_elts)
        v = _clib_fifo_resize(v, n_elts, elt_bytes);
    return v;
}
static inline __attribute__((__always_inline__)) void *
_clib_fifo_advance_tail(void *v, word n_elts, uword elt_bytes, uword *tail_return)
{
    word i, l, n_free;
    clib_fifo_header_t *f;
    n_free = clib_fifo_free_elts(v);
    if (n_free < n_elts) {
        v      = _clib_fifo_resize(v, n_elts, elt_bytes);
        n_free = clib_fifo_free_elts(v);
    }
    do {
        if ((0 > 0) && !(n_free >= n_elts)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/fifo.h", (uword) 130,
                        ((char *) __FUNCTION__), "n_free >= n_elts");
        }
    } while (0);
    n_free -= n_elts;
    f = clib_fifo_header(v);
    l = (((vec_header_t *) (v) -1)->len);
    i = f->tail_index;
    if (n_free == 0) {
        f->tail_index = f->head_index + l;
    } else {
        word n = f->tail_index + n_elts;
        if (n >= l)
            n -= l;
        else if (n < 0)
            n += l;
        do {
            if ((0 > 0) && !(n >= 0 && n < l)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/fifo.h", (uword) 149,
                            ((char *) __FUNCTION__), "n >= 0 && n < l");
            }
        } while (0);
        f->tail_index = n;
    }
    do {
        if ((0 > 0) && !(clib_fifo_free_elts(v) == n_free)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/fifo.h", (uword) 153,
                        ((char *) __FUNCTION__), "clib_fifo_free_elts (v) == n_free");
        }
    } while (0);
    if (tail_return)
        *tail_return = n_elts > 0 ? i : f->tail_index;
    return v;
}
static inline __attribute__((__always_inline__)) uword
clib_fifo_advance_head(void *v, uword n_elts)
{
    clib_fifo_header_t *f;
    uword l, i, n;
    do {
        if ((0 > 0) && !(clib_fifo_elts(v) >= n_elts)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/fifo.h", (uword) 174,
                        ((char *) __FUNCTION__), "clib_fifo_elts (v) >= n_elts");
        }
    } while (0);
    f = clib_fifo_header(v);
    l = (((vec_header_t *) (v) -1)->len);
    if (f->tail_index == f->head_index + l)
        f->tail_index = f->head_index;
    n = i = f->head_index;
    n += n_elts;
    n = n >= l ? n - l : n;
    do {
        if ((0 > 0) && !(n < l)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/fifo.h", (uword) 185,
                        ((char *) __FUNCTION__), "n < l");
        }
    } while (0);
    f->head_index = n;
    return i;
}
static inline __attribute__((__always_inline__)) uword
clib_fifo_head_index(void *v)
{
    clib_fifo_header_t *f = clib_fifo_header(v);
    return v ? f->head_index : 0;
}
static inline __attribute__((__always_inline__)) uword
clib_fifo_tail_index(void *v)
{
    clib_fifo_header_t *f = clib_fifo_header(v);
    return v ? f->tail_index : 0;
}
static inline __attribute__((__always_inline__)) uword
clib_fifo_elt_index(void *v, uword i)
{
    clib_fifo_header_t *f = clib_fifo_header(v);
    uword result          = 0;
    do {
        if ((0 > 0) && !(i < clib_fifo_elts(v))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/fifo.h", (uword) 265,
                        ((char *) __FUNCTION__), "i < clib_fifo_elts (v)");
        }
    } while (0);
    if (v) {
        result = f->head_index + i;
        if (result >= (((vec_header_t *) (v) -1)->len))
            result -= (((vec_header_t *) (v) -1)->len);
    }
    return result;
}
static inline __attribute__((__always_inline__)) vlib_buffer_t *
vlib_get_buffer(vlib_main_t *vm, u32 buffer_index)
{
    vlib_buffer_main_t *bm = &buffer_main;
    uword offset           = ((uword) buffer_index) << 6;
    do {
        if ((0 > 0) && !(offset < bm->buffer_mem_size)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 62,
                        ((char *) __FUNCTION__), "offset < bm->buffer_mem_size");
        }
    } while (0);
    return ((void *) (clib_address_t)(bm->buffer_mem_start + offset));
}
static inline __attribute__((__always_inline__)) void
vlib_get_buffers_with_offset(vlib_main_t *vm, u32 *bi, void **b, int count, i32 offset)
{
    while (count >= 4) {
        b[0] = ((u8 *) vlib_get_buffer(vm, bi[0])) + offset;
        b[1] = ((u8 *) vlib_get_buffer(vm, bi[1])) + offset;
        b[2] = ((u8 *) vlib_get_buffer(vm, bi[2])) + offset;
        b[3] = ((u8 *) vlib_get_buffer(vm, bi[3])) + offset;
        b += 4;
        bi += 4;
        count -= 4;
    }
    while (count) {
        b[0] = ((u8 *) vlib_get_buffer(vm, bi[0])) + offset;
        b += 1;
        bi += 1;
        count -= 1;
    }
}
static inline __attribute__((__always_inline__)) void
vlib_get_buffers(vlib_main_t *vm, u32 *bi, vlib_buffer_t **b, int count)
{
    vlib_get_buffers_with_offset(vm, bi, (void **) b, count, 0);
}
static inline __attribute__((__always_inline__)) u32
vlib_get_buffer_index(vlib_main_t *vm, void *p)
{
    vlib_buffer_main_t *bm = &buffer_main;
    uword offset           = pointer_to_uword(p) - bm->buffer_mem_start;
    do {
        if ((0 > 0) && !(pointer_to_uword(p) >= bm->buffer_mem_start)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 158,
                        ((char *) __FUNCTION__), "pointer_to_uword (p) >= bm->buffer_mem_start");
        }
    } while (0);
    do {
        if ((0 > 0) && !(offset < bm->buffer_mem_size)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 159,
                        ((char *) __FUNCTION__), "offset < bm->buffer_mem_size");
        }
    } while (0);
    do {
        if ((0 > 0) && !((offset % (1 << 6)) == 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 160,
                        ((char *) __FUNCTION__), "(offset % (1 << CLIB_LOG2_CACHE_LINE_BYTES)) == 0");
        }
    } while (0);
    return offset >> 6;
}
static inline __attribute__((__always_inline__)) void
vlib_get_buffer_indices_with_offset(vlib_main_t *vm, void **b, u32 *bi, uword count, i32 offset)
{
    while (count >= 4) {
        bi[0] = vlib_get_buffer_index(vm, ((u8 *) b[0]) + offset);
        bi[1] = vlib_get_buffer_index(vm, ((u8 *) b[1]) + offset);
        bi[2] = vlib_get_buffer_index(vm, ((u8 *) b[2]) + offset);
        bi[3] = vlib_get_buffer_index(vm, ((u8 *) b[3]) + offset);
        bi += 4;
        b += 4;
        count -= 4;
    }
    while (count) {
        bi[0] = vlib_get_buffer_index(vm, ((u8 *) b[0]) + offset);
        bi += 1;
        b += 1;
        count -= 1;
    }
}
static inline __attribute__((__always_inline__)) void
vlib_get_buffer_indices(vlib_main_t *vm, vlib_buffer_t **b, u32 *bi, uword count)
{
    vlib_get_buffer_indices_with_offset(vm, (void **) b, bi, count, 0);
}
static inline __attribute__((__always_inline__)) vlib_buffer_t *
vlib_get_next_buffer(vlib_main_t *vm, vlib_buffer_t *b)
{
    return (b->flags & VLIB_BUFFER_NEXT_PRESENT ? vlib_get_buffer(vm, b->next_buffer) : 0);
}
uword vlib_buffer_length_in_chain_slow_path(vlib_main_t *vm, vlib_buffer_t *b_first);
static inline __attribute__((__always_inline__)) uword
vlib_buffer_length_in_chain(vlib_main_t *vm, vlib_buffer_t *b)
{
    uword len = b->current_length;
    if (__builtin_expect(((b->flags & VLIB_BUFFER_NEXT_PRESENT) == 0), 1))
        return len;
    if (__builtin_expect((b->flags & VLIB_BUFFER_TOTAL_LENGTH_VALID), 1))
        return len + b->total_length_not_including_first_buffer;
    return vlib_buffer_length_in_chain_slow_path(vm, b);
}
static inline __attribute__((__always_inline__)) uword
vlib_buffer_index_length_in_chain(vlib_main_t *vm, u32 bi)
{
    vlib_buffer_t *b = vlib_get_buffer(vm, bi);
    return vlib_buffer_length_in_chain(vm, b);
}
static inline __attribute__((__always_inline__)) uword
vlib_buffer_contents(vlib_main_t *vm, u32 buffer_index, u8 *contents)
{
    uword content_len = 0;
    uword l;
    vlib_buffer_t *b;
    while (1) {
        b = vlib_get_buffer(vm, buffer_index);
        l = b->current_length;
        memcpy(contents + content_len, b->data + b->current_data, l);
        content_len += l;
        if (!(b->flags & VLIB_BUFFER_NEXT_PRESENT))
            break;
        buffer_index = b->next_buffer;
    }
    return content_len;
}
static inline __attribute__((__always_inline__)) u64
vlib_get_buffer_data_physical_address(vlib_main_t *vm, u32 buffer_index)
{
    vlib_buffer_main_t *bm   = &buffer_main;
    vlib_buffer_t *b         = vlib_get_buffer(vm, buffer_index);
    vlib_buffer_pool_t *pool = ({
        do {
            if ((0 > 0) &&
                !((b->buffer_pool_index) < ((bm->buffer_pools) ? (((vec_header_t *) (bm->buffer_pools) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 324,
                            ((char *) __FUNCTION__), "(b->buffer_pool_index) < vec_len (bm->buffer_pools)");
            }
        } while (0);
        (bm->buffer_pools) + (b->buffer_pool_index);
    });
    return vlib_physmem_virtual_to_physical(vm, pool->physmem_region, b->data);
}
typedef enum {
    VLIB_BUFFER_UNKNOWN,
    VLIB_BUFFER_KNOWN_FREE,
    VLIB_BUFFER_KNOWN_ALLOCATED,
} vlib_buffer_known_state_t;
void vlib_buffer_validate_alloc_free(vlib_main_t *vm, u32 *buffers, uword n_buffers,
                                     vlib_buffer_known_state_t expected_state);
static inline __attribute__((__always_inline__)) vlib_buffer_known_state_t
vlib_buffer_is_known(u32 buffer_index)
{
    vlib_buffer_main_t *bm = &buffer_main;
    clib_spinlock_lock(&bm->buffer_known_hash_lockp);
    uword *p = _hash_get((bm->buffer_known_hash), (uword)(buffer_index));
    clib_spinlock_unlock(&bm->buffer_known_hash_lockp);
    return p ? p[0] : VLIB_BUFFER_UNKNOWN;
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_set_known_state(u32 buffer_index, vlib_buffer_known_state_t state)
{
    vlib_buffer_main_t *bm = &buffer_main;
    clib_spinlock_lock(&bm->buffer_known_hash_lockp);
    ({
        uword _v                = (uword)(state);
        (bm->buffer_known_hash) = _hash_set3((bm->buffer_known_hash), (uword)(buffer_index), (void *) &_v, (0));
    });
    clib_spinlock_unlock(&bm->buffer_known_hash_lockp);
}
u8 *vlib_validate_buffer(vlib_main_t *vm, u32 buffer_index, uword follow_chain);
static inline __attribute__((__always_inline__)) u32
vlib_buffer_round_size(u32 size)
{
    return round_pow2(size, sizeof(vlib_buffer_t));
}
static inline __attribute__((__always_inline__)) vlib_buffer_free_list_index_t
vlib_buffer_get_free_list_index(vlib_buffer_t *b)
{
    if (__builtin_expect((b->flags & VLIB_BUFFER_NON_DEFAULT_FREELIST), 0))
        return b->free_list_index;
    return 0;
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_set_free_list_index(vlib_buffer_t *b, vlib_buffer_free_list_index_t index)
{
    if (__builtin_expect((index), 0)) {
        b->flags |= VLIB_BUFFER_NON_DEFAULT_FREELIST;
        b->free_list_index = index;
    } else
        b->flags &= ~VLIB_BUFFER_NON_DEFAULT_FREELIST;
}
static inline __attribute__((__always_inline__)) u32
vlib_buffer_alloc_from_free_list(vlib_main_t *vm, u32 *buffers, u32 n_buffers, vlib_buffer_free_list_index_t index)
{
    vlib_buffer_main_t *bm = &buffer_main;
    vlib_buffer_free_list_t *fl;
    u32 *src;
    uword len;
    do {
        if ((0 > 0) && !(bm->cb.vlib_buffer_fill_free_list_cb)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 454,
                        ((char *) __FUNCTION__), "bm->cb.vlib_buffer_fill_free_list_cb");
        }
    } while (0);
    fl  = ({
        typeof(vm->buffer_free_list_pool) _e = (vm->buffer_free_list_pool) + (index);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(vm->buffer_free_list_pool);
                    uword _pool_i          = (_e) - (vm->buffer_free_list_pool);
                    (_pool_i <
                     ((vm->buffer_free_list_pool) ? (((vec_header_t *) (vm->buffer_free_list_pool) - 1)->len) : 0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 456,
                            ((char *) __FUNCTION__), "! pool_is_free (vm->buffer_free_list_pool, _e)");
            }
        } while (0);
        _e;
    });
    len = ((fl->buffers) ? (((vec_header_t *) (fl->buffers) - 1)->len) : 0);
    if (__builtin_expect((len < n_buffers), 0)) {
        bm->cb.vlib_buffer_fill_free_list_cb(vm, fl, n_buffers);
        if (__builtin_expect(((len = ((fl->buffers) ? (((vec_header_t *) (fl->buffers) - 1)->len) : 0)) == 0), 0))
            return 0;
        n_buffers = ({
            __typeof__(len) _x       = (len);
            __typeof__(n_buffers) _y = (n_buffers);
            _x < _y ? _x : _y;
        });
        src       = fl->buffers + len - n_buffers;
        memcpy(buffers, src, n_buffers * sizeof(u32));
        (((vec_header_t *) (fl->buffers) - 1)->len) -= n_buffers;
        vlib_buffer_validate_alloc_free(vm, buffers, n_buffers, VLIB_BUFFER_KNOWN_FREE);
        return n_buffers;
    }
    src = fl->buffers + len - n_buffers;
    memcpy(buffers, src, n_buffers * sizeof(u32));
    (((vec_header_t *) (fl->buffers) - 1)->len) -= n_buffers;
    vlib_buffer_validate_alloc_free(vm, buffers, n_buffers, VLIB_BUFFER_KNOWN_FREE);
    return n_buffers;
}
static inline __attribute__((__always_inline__)) u32
vlib_buffer_alloc(vlib_main_t *vm, u32 *buffers, u32 n_buffers)
{
    return vlib_buffer_alloc_from_free_list(vm, buffers, n_buffers, (0));
}
static inline __attribute__((__always_inline__)) u32
vlib_buffer_alloc_to_ring(vlib_main_t *vm, u32 *ring, u32 start, u32 ring_size, u32 n_buffers)
{
    u32 n_alloc;
    do {
        if ((0 > 0) && !(n_buffers <= ring_size)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 525,
                        ((char *) __FUNCTION__), "n_buffers <= ring_size");
        }
    } while (0);
    if (__builtin_expect((start + n_buffers <= ring_size), 1))
        return vlib_buffer_alloc(vm, ring + start, n_buffers);
    n_alloc = vlib_buffer_alloc(vm, ring + start, ring_size - start);
    if (__builtin_expect((n_alloc == ring_size - start), 1))
        n_alloc += vlib_buffer_alloc(vm, ring, n_buffers - n_alloc);
    return n_alloc;
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_free(vlib_main_t *vm, u32 *buffers, u32 n_buffers)
{
    vlib_buffer_main_t *bm = &buffer_main;
    do {
        if ((0 > 0) && !(bm->cb.vlib_buffer_free_cb)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 555,
                        ((char *) __FUNCTION__), "bm->cb.vlib_buffer_free_cb");
        }
    } while (0);
    return bm->cb.vlib_buffer_free_cb(vm, buffers, n_buffers);
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_free_no_next(vlib_main_t *vm, u32 *buffers, u32 n_buffers)
{
    vlib_buffer_main_t *bm = &buffer_main;
    do {
        if ((0 > 0) && !(bm->cb.vlib_buffer_free_no_next_cb)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 576,
                        ((char *) __FUNCTION__), "bm->cb.vlib_buffer_free_no_next_cb");
        }
    } while (0);
    return bm->cb.vlib_buffer_free_no_next_cb(vm, buffers, n_buffers);
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_free_one(vlib_main_t *vm, u32 buffer_index)
{
    vlib_buffer_free(vm, &buffer_index, 1);
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_free_from_ring(vlib_main_t *vm, u32 *ring, u32 start, u32 ring_size, u32 n_buffers)
{
    do {
        if ((0 > 0) && !(n_buffers <= ring_size)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 605,
                        ((char *) __FUNCTION__), "n_buffers <= ring_size");
        }
    } while (0);
    if (__builtin_expect((start + n_buffers <= ring_size), 1)) {
        vlib_buffer_free(vm, ring + start, n_buffers);
    } else {
        vlib_buffer_free(vm, ring + start, ring_size - start);
        vlib_buffer_free(vm, ring, n_buffers - (ring_size - start));
    }
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_free_from_ring_no_next(vlib_main_t *vm, u32 *ring, u32 start, u32 ring_size, u32 n_buffers)
{
    do {
        if ((0 > 0) && !(n_buffers <= ring_size)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 630,
                        ((char *) __FUNCTION__), "n_buffers <= ring_size");
        }
    } while (0);
    if (__builtin_expect((start + n_buffers <= ring_size), 1)) {
        vlib_buffer_free_no_next(vm, ring + start, n_buffers);
    } else {
        vlib_buffer_free_no_next(vm, ring + start, ring_size - start);
        vlib_buffer_free_no_next(vm, ring, n_buffers - (ring_size - start));
    }
}
vlib_buffer_free_list_index_t vlib_buffer_create_free_list(vlib_main_t *vm, u32 n_data_bytes, char *fmt, ...);
static inline __attribute__((__always_inline__)) void
vlib_buffer_delete_free_list(vlib_main_t *vm, vlib_buffer_free_list_index_t free_list_index)
{
    vlib_buffer_main_t *bm = &buffer_main;
    do {
        if ((0 > 0) && !(bm->cb.vlib_buffer_delete_free_list_cb)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 653,
                        ((char *) __FUNCTION__), "bm->cb.vlib_buffer_delete_free_list_cb");
        }
    } while (0);
    bm->cb.vlib_buffer_delete_free_list_cb(vm, free_list_index);
}
void vlib_buffer_free_list_fill_unaligned(vlib_main_t *vm, vlib_buffer_free_list_t *free_list, uword n_unaligned_buffers);
static inline __attribute__((__always_inline__)) vlib_buffer_free_list_t *
vlib_buffer_get_buffer_free_list(vlib_main_t *vm, vlib_buffer_t *b, vlib_buffer_free_list_index_t *index)
{
    vlib_buffer_free_list_index_t i;
    *index = i = vlib_buffer_get_free_list_index(b);
    return ({
        typeof(vm->buffer_free_list_pool) _e = (vm->buffer_free_list_pool) + (i);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(vm->buffer_free_list_pool);
                    uword _pool_i          = (_e) - (vm->buffer_free_list_pool);
                    (_pool_i <
                     ((vm->buffer_free_list_pool) ? (((vec_header_t *) (vm->buffer_free_list_pool) - 1)->len) : 0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 671,
                            ((char *) __FUNCTION__), "! pool_is_free (vm->buffer_free_list_pool, _e)");
            }
        } while (0);
        _e;
    });
}
static inline __attribute__((__always_inline__)) vlib_buffer_free_list_t *
vlib_buffer_get_free_list(vlib_main_t *vm, vlib_buffer_free_list_index_t free_list_index)
{
    vlib_buffer_free_list_t *f;
    f = ({
        typeof(vm->buffer_free_list_pool) _e = (vm->buffer_free_list_pool) + (free_list_index);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(vm->buffer_free_list_pool);
                    uword _pool_i          = (_e) - (vm->buffer_free_list_pool);
                    (_pool_i <
                     ((vm->buffer_free_list_pool) ? (((vec_header_t *) (vm->buffer_free_list_pool) - 1)->len) : 0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 680,
                            ((char *) __FUNCTION__), "! pool_is_free (vm->buffer_free_list_pool, _e)");
            }
        } while (0);
        _e;
    });
    do {
        if ((0 > 0) && !(f->index == free_list_index)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 683,
                        ((char *) __FUNCTION__), "f->index == free_list_index");
        }
    } while (0);
    return f;
}
static inline __attribute__((__always_inline__)) u32
vlib_buffer_free_list_buffer_size(vlib_main_t *vm, vlib_buffer_free_list_index_t index)
{
    vlib_buffer_free_list_t *f = vlib_buffer_get_free_list(vm, index);
    return f->n_data_bytes;
}
void vlib_aligned_memcpy(void *_dst, void *_src, int n_bytes);
static inline __attribute__((__always_inline__)) void
vlib_copy_buffers(u32 *dst, u32 *src, u32 n)
{
    while (n >= 4) {
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        dst += 4;
        src += 4;
        n -= 4;
    }
    while (n > 0) {
        dst[0] = src[0];
        dst += 1;
        src += 1;
        n -= 1;
    }
}
u32 vlib_buffer_add_data(vlib_main_t *vm, vlib_buffer_free_list_index_t free_list_index, u32 buffer_index, void *data,
                         u32 n_data_bytes);
static inline __attribute__((__always_inline__)) vlib_buffer_t *
vlib_buffer_copy(vlib_main_t *vm, vlib_buffer_t *b)
{
    vlib_buffer_t *s, *d, *fd;
    uword n_alloc, n_buffers = 1;
    u32 flag_mask = VLIB_BUFFER_NEXT_PRESENT | VLIB_BUFFER_TOTAL_LENGTH_VALID;
    int i;
    s = b;
    while (s->flags & VLIB_BUFFER_NEXT_PRESENT) {
        n_buffers++;
        s = vlib_get_buffer(vm, s->next_buffer);
    }
    u32 new_buffers[n_buffers];
    n_alloc = vlib_buffer_alloc(vm, new_buffers, n_buffers);
    if (__builtin_expect((n_alloc < n_buffers), 0)) {
        if (n_alloc > 0)
            vlib_buffer_free(vm, new_buffers, n_alloc);
        return 0;
    }
    s  = b;
    fd = d                                     = vlib_get_buffer(vm, new_buffers[0]);
    d->current_data                            = s->current_data;
    d->current_length                          = s->current_length;
    d->flags                                   = s->flags & flag_mask;
    d->total_length_not_including_first_buffer = s->total_length_not_including_first_buffer;
    memcpy(d->opaque, s->opaque, sizeof(s->opaque));
    memcpy(d->opaque2, s->opaque2, sizeof(s->opaque2));
    memcpy(vlib_buffer_get_current(d), vlib_buffer_get_current(s), s->current_length);
    for (i = 1; i < n_buffers; i++) {
        d->next_buffer    = new_buffers[i];
        s                 = vlib_get_buffer(vm, s->next_buffer);
        d                 = vlib_get_buffer(vm, new_buffers[i]);
        d->current_data   = s->current_data;
        d->current_length = s->current_length;
        memcpy(vlib_buffer_get_current(d), vlib_buffer_get_current(s), s->current_length);
        d->flags = s->flags & flag_mask;
    }
    return fd;
}
static inline __attribute__((__always_inline__)) u16
vlib_buffer_clone_256(vlib_main_t *vm, u32 src_buffer, u32 *buffers, u16 n_buffers, u16 head_end_offset)
{
    u16 i;
    vlib_buffer_t *s = vlib_get_buffer(vm, src_buffer);
    do {
        if ((0 > 0) && !(s->n_add_refs == 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 803,
                        ((char *) __FUNCTION__), "s->n_add_refs == 0");
        }
    } while (0);
    do {
        if ((0 > 0) && !(n_buffers)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 804,
                        ((char *) __FUNCTION__), "n_buffers");
        }
    } while (0);
    do {
        if ((0 > 0) && !(n_buffers <= 256)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 805,
                        ((char *) __FUNCTION__), "n_buffers <= 256");
        }
    } while (0);
    if (s->current_length <= head_end_offset + (1 << 6) * 2) {
        buffers[0] = src_buffer;
        for (i = 1; i < n_buffers; i++) {
            vlib_buffer_t *d;
            d = vlib_buffer_copy(vm, s);
            if (d == 0)
                return i;
            buffers[i] = vlib_get_buffer_index(vm, d);
        }
        return n_buffers;
    }
    if (__builtin_expect((n_buffers == 1), 0)) {
        buffers[0] = src_buffer;
        return 1;
    }
    n_buffers = vlib_buffer_alloc_from_free_list(vm, buffers, n_buffers, vlib_buffer_get_free_list_index(s));
    for (i = 0; i < n_buffers; i++) {
        vlib_buffer_t *d  = vlib_get_buffer(vm, buffers[i]);
        d->current_data   = s->current_data;
        d->current_length = head_end_offset;
        vlib_buffer_set_free_list_index(d, vlib_buffer_get_free_list_index(s));
        d->total_length_not_including_first_buffer = s->current_length - head_end_offset;
        if (__builtin_expect((s->flags & VLIB_BUFFER_NEXT_PRESENT), 0)) {
            d->total_length_not_including_first_buffer += s->total_length_not_including_first_buffer;
        }
        d->flags = s->flags | VLIB_BUFFER_NEXT_PRESENT;
        d->flags &= ~VLIB_BUFFER_EXT_HDR_VALID;
        memcpy(d->opaque, s->opaque, sizeof(s->opaque));
        memcpy(d->opaque2, s->opaque2, sizeof(s->opaque2));
        memcpy(vlib_buffer_get_current(d), vlib_buffer_get_current(s), head_end_offset);
        d->next_buffer = src_buffer;
    }
    vlib_buffer_advance(s, head_end_offset);
    s->n_add_refs = n_buffers - 1;
    while (s->flags & VLIB_BUFFER_NEXT_PRESENT) {
        s             = vlib_get_buffer(vm, s->next_buffer);
        s->n_add_refs = n_buffers - 1;
    }
    return n_buffers;
}
static inline __attribute__((__always_inline__)) u16
vlib_buffer_clone(vlib_main_t *vm, u32 src_buffer, u32 *buffers, u16 n_buffers, u16 head_end_offset)
{
    vlib_buffer_t *s = vlib_get_buffer(vm, src_buffer);
    u16 n_cloned     = 0;
    while (n_buffers > 256) {
        vlib_buffer_t *copy;
        copy = vlib_buffer_copy(vm, s);
        n_cloned +=
            vlib_buffer_clone_256(vm, vlib_get_buffer_index(vm, copy), (buffers + n_cloned), 256, head_end_offset);
        n_buffers -= 256;
    }
    n_cloned += vlib_buffer_clone_256(vm, src_buffer, buffers + n_cloned, n_buffers, head_end_offset);
    return n_cloned;
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_attach_clone(vlib_main_t *vm, vlib_buffer_t *head, vlib_buffer_t *tail)
{
    do {
        if ((0 > 0) && !((head->flags & VLIB_BUFFER_NEXT_PRESENT) == 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 913,
                        ((char *) __FUNCTION__), "(head->flags & VLIB_BUFFER_NEXT_PRESENT) == 0");
        }
    } while (0);
    do {
        if ((0 > 0) && !(vlib_buffer_get_free_list_index(head) == vlib_buffer_get_free_list_index(tail))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 915,
                        ((char *) __FUNCTION__),
                        "vlib_buffer_get_free_list_index (head) == vlib_buffer_get_free_list_index (tail)");
        }
    } while (0);
    head->flags |= VLIB_BUFFER_NEXT_PRESENT;
    head->flags &= ~VLIB_BUFFER_TOTAL_LENGTH_VALID;
    head->flags &= ~VLIB_BUFFER_EXT_HDR_VALID;
    head->flags |= (tail->flags & VLIB_BUFFER_TOTAL_LENGTH_VALID);
    head->next_buffer                             = vlib_get_buffer_index(vm, tail);
    head->total_length_not_including_first_buffer = tail->current_length + tail->total_length_not_including_first_buffer;
next_segment:
    __sync_add_and_fetch(&tail->n_add_refs, 1);
    if (tail->flags & VLIB_BUFFER_NEXT_PRESENT) {
        tail = vlib_get_buffer(vm, tail->next_buffer);
        goto next_segment;
    }
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_chain_init(vlib_buffer_t *first)
{
    first->total_length_not_including_first_buffer = 0;
    first->current_length                          = 0;
    first->flags &= ~VLIB_BUFFER_NEXT_PRESENT;
    first->flags |= VLIB_BUFFER_TOTAL_LENGTH_VALID;
}
static inline __attribute__((__always_inline__)) vlib_buffer_t *
vlib_buffer_chain_buffer(vlib_main_t *vm, vlib_buffer_t *first, vlib_buffer_t *last, u32 next_bi)
{
    vlib_buffer_t *next_buffer = vlib_get_buffer(vm, next_bi);
    last->next_buffer          = next_bi;
    last->flags |= VLIB_BUFFER_NEXT_PRESENT;
    next_buffer->current_length = 0;
    next_buffer->flags &= ~VLIB_BUFFER_NEXT_PRESENT;
    return next_buffer;
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_chain_increase_length(vlib_buffer_t *first, vlib_buffer_t *last, i32 len)
{
    last->current_length += len;
    if (first != last)
        first->total_length_not_including_first_buffer += len;
}
static inline __attribute__((__always_inline__)) u16
vlib_buffer_chain_append_data(vlib_main_t *vm, vlib_buffer_free_list_index_t free_list_index, vlib_buffer_t *first,
                              vlib_buffer_t *last, void *data, u16 data_len)
{
    u32 n_buffer_bytes = vlib_buffer_free_list_buffer_size(vm, free_list_index);
    do {
        if ((0 > 0) && !(n_buffer_bytes >= last->current_length + last->current_data)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 983,
                        ((char *) __FUNCTION__), "n_buffer_bytes >= last->current_length + last->current_data");
        }
    } while (0);
    u16 len = ({
        __typeof__(data_len) _x = (data_len);
        __typeof__(n_buffer_bytes - last->current_length - last->current_data) _y =
            (n_buffer_bytes - last->current_length - last->current_data);
        _x < _y ? _x : _y;
    });
    memcpy(vlib_buffer_get_current(last) + last->current_length, data, len);
    vlib_buffer_chain_increase_length(first, last, len);
    return len;
}
u16 vlib_buffer_chain_append_data_with_alloc(vlib_main_t *vm, vlib_buffer_free_list_index_t free_list_index,
                                             vlib_buffer_t *first, vlib_buffer_t **last, void *data, u16 data_len);
void vlib_buffer_chain_validate(vlib_main_t *vm, vlib_buffer_t *first);
format_function_t format_vlib_buffer, format_vlib_buffer_and_data, format_vlib_buffer_contents;
typedef struct {
    u8 *packet_data;
    u32 min_n_buffers_each_alloc;
    vlib_buffer_free_list_index_t free_list_index;
    u32 *free_buffers;
} vlib_packet_template_t;
void vlib_packet_template_get_packet_helper(vlib_main_t *vm, vlib_packet_template_t *t);
void vlib_packet_template_init(vlib_main_t *vm, vlib_packet_template_t *t, void *packet_data, uword n_packet_data_bytes,
                               uword min_n_buffers_each_alloc, char *fmt, ...);
void *vlib_packet_template_get_packet(vlib_main_t *vm, vlib_packet_template_t *t, u32 *bi_result);
static inline __attribute__((__always_inline__)) void
vlib_packet_template_free(vlib_main_t *vm, vlib_packet_template_t *t)
{
    do {
        if (t->packet_data) {
            clib_mem_free(vec_header((t->packet_data), (0)));
            t->packet_data = 0;
        }
    } while (0);
}
static inline __attribute__((__always_inline__)) u32
unserialize_vlib_buffer_n_bytes(serialize_main_t *m)
{
    serialize_stream_t *s = &m->stream;
    vlib_serialize_buffer_main_t *sm =
        ((vlib_serialize_buffer_main_t *) (clib_address_t)(m->stream.data_function_opaque));
    vlib_main_t *vm = sm->vlib_main;
    u32 n, *f;
    n = s->n_buffer_bytes - s->current_buffer_index;
    if (sm->last_buffer != ~0) {
        vlib_buffer_t *b = vlib_get_buffer(vm, sm->last_buffer);
        while (b->flags & VLIB_BUFFER_NEXT_PRESENT) {
            b = vlib_get_buffer(vm, b->next_buffer);
            n += b->current_length;
        }
    }
    do {
        uword _i, _l, _n;
        _i = clib_fifo_head_index(sm->rx.buffer_fifo);
        _l = ((sm->rx.buffer_fifo) ? (((vec_header_t *) (sm->rx.buffer_fifo) - 1)->len) : 0);
        _n = clib_fifo_elts(sm->rx.buffer_fifo);
        while (_n > 0) {
            (f) = (sm->rx.buffer_fifo) + _i;
            do {
                ({ n += vlib_buffer_index_length_in_chain(vm, f[0]); });
            } while (0);
            _n--;
            _i++;
            _i = _i >= _l ? 0 : _i;
        }
    } while (0);
    return n;
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_init_for_free_list(vlib_buffer_t *dst, vlib_buffer_free_list_t *fl)
{
    vlib_buffer_t *src = &fl->buffer_init_template;
    do {
        if ((0 > 0) && !(((uword) & (((vlib_buffer_t *) 0)->cacheline0)) == 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 1084,
                        ((char *) __FUNCTION__), "STRUCT_OFFSET_OF (vlib_buffer_t, cacheline0) == 0");
        }
    } while (0);
    do {
        if ((0 > 0) && !(((uword) & (((vlib_buffer_t *) 0)->cacheline1)) == (1 << 6))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 1086,
                        ((char *) __FUNCTION__), "STRUCT_OFFSET_OF (vlib_buffer_t, cacheline1) == CLIB_CACHE_LINE_BYTES");
        }
    } while (0);
    do {
        if ((0 > 0) && !(((uword) & (((vlib_buffer_t *) 0)->cacheline2)) == (1 << 6) * 2)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 1088,
                        ((char *) __FUNCTION__),
                        "STRUCT_OFFSET_OF (vlib_buffer_t, cacheline2) == CLIB_CACHE_LINE_BYTES * 2");
        }
    } while (0);
    do {
        if ((0 > 0) && !(fl->index == vlib_buffer_get_free_list_index(src))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 1091,
                        ((char *) __FUNCTION__), "fl->index == vlib_buffer_get_free_list_index (src)");
        }
    } while (0);
    memcpy(&(dst)->template_start, &(src)->template_start,
           ((uword) & (((vlib_buffer_t *) 0)->template_end)) - ((uword) & (((vlib_buffer_t *) 0)->template_start)));
    dst->n_add_refs = src->n_add_refs;
    vlib_buffer_set_free_list_index(dst, fl->index);
    do {
        if ((0 > 0) && !(dst->current_data == src->current_data)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 1104,
                        ((char *) __FUNCTION__), "dst->current_data == src->current_data");
        }
    } while (0);
    ;
    do {
        if ((0 > 0) && !(dst->current_length == src->current_length)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 1105,
                        ((char *) __FUNCTION__), "dst->current_length == src->current_length");
        }
    } while (0);
    ;
    do {
        if ((0 > 0) && !(dst->flags == src->flags)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 1106,
                        ((char *) __FUNCTION__), "dst->flags == src->flags");
        }
    } while (0);
    ;
    do {
        if ((0 > 0) && !(dst->n_add_refs == 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_funcs.h", (uword) 1114,
                        ((char *) __FUNCTION__), "dst->n_add_refs == 0");
        }
    } while (0);
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_add_to_free_list(vlib_main_t *vm, vlib_buffer_free_list_t *f, u32 buffer_index, u8 do_init)
{
    vlib_buffer_pool_t *bp = vlib_buffer_pool_get(f->buffer_pool_index);
    vlib_buffer_t *b;
    b = vlib_get_buffer(vm, buffer_index);
    if (__builtin_expect((do_init), 1))
        vlib_buffer_init_for_free_list(b, f);
    do {
        word _vec_l          = ((f->buffers) ? (((vec_header_t *) (f->buffers) - 1)->len) : 0);
        f->buffers           = _vec_resize_inline((f->buffers), 1, (_vec_l + 1) * sizeof((f->buffers)[0]), (0), ({
                                            __typeof__((__alignof__(((f->buffers))[0]))) _x =
                                                ((__alignof__(((f->buffers))[0])));
                                            __typeof__((((1 << 6)))) _y = ((((1 << 6))));
                                            _x > _y ? _x : _y;
                                        }));
        (f->buffers)[_vec_l] = (buffer_index);
    } while (0);
    if (((f->buffers) ? (((vec_header_t *) (f->buffers) - 1)->len) : 0) > 4 * 256) {
        clib_spinlock_lock(&bp->lock);
        do {
            word _vec_n = (256);
            word _vec_l = ((bp->buffers) ? (((vec_header_t *) (bp->buffers) - 1)->len) : 0);
            bp->buffers = _vec_resize_inline((bp->buffers), _vec_n, (_vec_l + _vec_n) * sizeof((bp->buffers)[0]), (0), ({
                                                 __typeof__((__alignof__(((bp->buffers))[0]))) _x =
                                                     ((__alignof__(((bp->buffers))[0])));
                                                 __typeof__((((1 << 6)))) _y = ((((1 << 6))));
                                                 _x > _y ? _x : _y;
                                             }));
            memcpy((bp->buffers) + _vec_l, (f->buffers), _vec_n * sizeof((bp->buffers)[0]));
        } while (0);
        do {
            word _vec_l = ((f->buffers) ? (((vec_header_t *) (f->buffers) - 1)->len) : 0);
            word _vec_n = (256);
            word _vec_m = (0);
            if (_vec_l - _vec_n - _vec_m > 0)
                memmove((f->buffers) + _vec_m, (f->buffers) + _vec_m + _vec_n,
                        (_vec_l - _vec_n - _vec_m) * sizeof((f->buffers)[0]));
            if (_vec_n > 0)
                memset((f->buffers) + _vec_l - _vec_n, 0, _vec_n * sizeof((f->buffers)[0]));
            (((vec_header_t *) (f->buffers) - 1)->len) -= _vec_n;
        } while (0);
        f->n_alloc -= 256;
        clib_spinlock_unlock(&bp->lock);
    }
}
static inline void
vlib_validate_buffer_in_use(vlib_buffer_t *b, u32 expected)
{
}
static inline void
vlib_validate_buffer_set_in_use(vlib_buffer_t *b, u32 expected)
{
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_chain_compress(vlib_main_t *vm, vlib_buffer_t *first, u32 **discard_vector)
{
    if (first->current_length >= (256) || !(first->flags & VLIB_BUFFER_NEXT_PRESENT)) {
        return;
    }
    vlib_buffer_free_list_index_t index;
    vlib_buffer_free_list_t *free_list = vlib_buffer_get_buffer_free_list(vm, first, &index);
    u32 want_first_size                = ({
        __typeof__((256)) _x                                         = ((256));
        __typeof__(free_list->n_data_bytes - first->current_data) _y = (free_list->n_data_bytes - first->current_data);
        _x < _y ? _x : _y;
    });
    do {
        vlib_buffer_t *second = vlib_get_buffer(vm, first->next_buffer);
        u32 need              = want_first_size - first->current_length;
        u32 amount_to_copy    = ({
            __typeof__(need) _x                   = (need);
            __typeof__(second->current_length) _y = (second->current_length);
            _x < _y ? _x : _y;
        });
        memcpy(((u8 *) vlib_buffer_get_current(first)) + first->current_length, vlib_buffer_get_current(second),
               amount_to_copy);
        first->current_length += amount_to_copy;
        vlib_buffer_advance(second, amount_to_copy);
        if (first->flags & VLIB_BUFFER_TOTAL_LENGTH_VALID) {
            first->total_length_not_including_first_buffer -= amount_to_copy;
        }
        if (!second->current_length) {
            do {
                word _vec_l = ((*discard_vector) ? (((vec_header_t *) (*discard_vector) - 1)->len) : 0);
                *discard_vector =
                    _vec_resize_inline((*discard_vector), 1, (_vec_l + 1) * sizeof((*discard_vector)[0]), (0), ({
                                           __typeof__((__alignof__(((*discard_vector))[0]))) _x =
                                               ((__alignof__(((*discard_vector))[0])));
                                           __typeof__(((0))) _y = (((0)));
                                           _x > _y ? _x : _y;
                                       }));
                (*discard_vector)[_vec_l] = (first->next_buffer);
            } while (0);
            if (second->flags & VLIB_BUFFER_NEXT_PRESENT) {
                first->next_buffer = second->next_buffer;
            } else {
                first->flags &= ~VLIB_BUFFER_NEXT_PRESENT;
            }
            second->flags &= ~VLIB_BUFFER_NEXT_PRESENT;
        }
    } while ((first->current_length < want_first_size) && (first->flags & VLIB_BUFFER_NEXT_PRESENT));
}
static inline __attribute__((__always_inline__)) void *
vlib_cli_get_parse_rule_result(vlib_main_t *vm, uword index)
{
    vlib_cli_main_t *cm = &vm->cli_main;
    return (({
        do {
            if ((0 > 0) &&
                !((index) < ((cm->parse_rule_data) ? (((vec_header_t *) (cm->parse_rule_data) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/cli_funcs.h", (uword) 47,
                            ((char *) __FUNCTION__), "(index) < vec_len (cm->parse_rule_data)");
            }
        } while (0);
        (cm->parse_rule_data) + (index);
    }))[0];
}
typedef struct {
    u32 next;
    u32 prev;
    union {
        struct {
            u16 fast_ring_offset;
            u16 slow_ring_offset;
        };
        u64 expiration_time;
    };
    u32 user_handle;
} tw_timer_1t_3w_1024sl_ov_t;
typedef struct {
    u32 head_index;
} tw_timer_wheel_slot_t;
typedef enum {
    TW_TIMER_RING_FAST,
    TW_TIMER_RING_SLOW,
    TW_TIMER_RING_GLACIER,
} tw_ring_index_t;
typedef struct {
    u8 timer_id;
    u32 pool_index;
    u32 handle;
} __attribute__((packed)) trace_1t_3w_1024sl_ov_t;
typedef struct {
    tw_timer_1t_3w_1024sl_ov_t *timers;
    f64 next_run_time;
    f64 last_run_time;
    f64 ticks_per_second;
    f64 timer_interval;
    u64 current_tick;
    u64 first_expires_tick;
    u32 current_index[3];
    tw_timer_wheel_slot_t w[3][1024];
    tw_timer_wheel_slot_t overflow;
    uword *fast_slot_bitmap;
    void (*expired_timer_callback)(u32 *expired_timer_handles);
    u32 *expired_timer_handles;
    u32 max_expirations;
} tw_timer_wheel_1t_3w_1024sl_ov_t;
u32 tw_timer_start_1t_3w_1024sl_ov(tw_timer_wheel_1t_3w_1024sl_ov_t *tw, u32 pool_index, u32 timer_id, u64 interval);
void tw_timer_stop_1t_3w_1024sl_ov(tw_timer_wheel_1t_3w_1024sl_ov_t *tw, u32 handle);
int tw_timer_handle_is_free_1t_3w_1024sl_ov(tw_timer_wheel_1t_3w_1024sl_ov_t *tw, u32 handle);
void tw_timer_update_1t_3w_1024sl_ov(tw_timer_wheel_1t_3w_1024sl_ov_t *tw, u32 handle, u64 interval);
void tw_timer_wheel_init_1t_3w_1024sl_ov(tw_timer_wheel_1t_3w_1024sl_ov_t *tw, void *expired_timer_callback,
                                         f64 timer_interval, u32 max_expirations);
void tw_timer_wheel_free_1t_3w_1024sl_ov(tw_timer_wheel_1t_3w_1024sl_ov_t *tw);
u32 *tw_timer_expire_timers_1t_3w_1024sl_ov(tw_timer_wheel_1t_3w_1024sl_ov_t *tw, f64 now);
u32 *tw_timer_expire_timers_vec_1t_3w_1024sl_ov(tw_timer_wheel_1t_3w_1024sl_ov_t *tw, f64 now, u32 *vec);
u32 tw_timer_first_expires_in_ticks_1t_3w_1024sl_ov(tw_timer_wheel_1t_3w_1024sl_ov_t *tw);
static inline __attribute__((__always_inline__)) vlib_node_t *
vlib_get_node(vlib_main_t *vm, u32 i)
{
    return (({
        do {
            if ((0 > 0) && !((i) < ((vm->node_main.nodes) ? (((vec_header_t *) (vm->node_main.nodes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 61,
                            ((char *) __FUNCTION__), "(i) < vec_len (vm->node_main.nodes)");
            }
        } while (0);
        (vm->node_main.nodes) + (i);
    }))[0];
}
static inline __attribute__((__always_inline__)) vlib_node_t *
vlib_get_next_node(vlib_main_t *vm, u32 node_index, u32 next_index)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_node_t *n;
    n = (({
        do {
            if ((0 > 0) && !((node_index) < ((nm->nodes) ? (((vec_header_t *) (nm->nodes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 77,
                            ((char *) __FUNCTION__), "(node_index) < vec_len (nm->nodes)");
            }
        } while (0);
        (nm->nodes) + (node_index);
    }))[0];
    do {
        if ((0 > 0) && !(next_index < ((n->next_nodes) ? (((vec_header_t *) (n->next_nodes) - 1)->len) : 0))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 78,
                        ((char *) __FUNCTION__), "next_index < vec_len (n->next_nodes)");
        }
    } while (0);
    return vlib_get_node(vm, n->next_nodes[next_index]);
}
static inline __attribute__((__always_inline__)) vlib_node_runtime_t *
vlib_node_get_runtime(vlib_main_t *vm, u32 node_index)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_node_t *n       = (({
        do {
            if ((0 > 0) && !((node_index) < ((nm->nodes) ? (((vec_header_t *) (nm->nodes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 92,
                            ((char *) __FUNCTION__), "(node_index) < vec_len (nm->nodes)");
            }
        } while (0);
        (nm->nodes) + (node_index);
    }))[0];
    vlib_process_t *p;
    if (n->type != VLIB_NODE_TYPE_PROCESS)
        return ({
            do {
                if ((0 > 0) &&
                    !((n->runtime_index) <
                      ((nm->nodes_by_type[n->type]) ? (((vec_header_t *) (nm->nodes_by_type[n->type]) - 1)->len) : 0))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 95,
                                ((char *) __FUNCTION__), "(n->runtime_index) < vec_len (nm->nodes_by_type[n->type])");
                }
            } while (0);
            (nm->nodes_by_type[n->type]) + (n->runtime_index);
        });
    else {
        p = (({
            do {
                if ((0 > 0) &&
                    !((n->runtime_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h",
                                (uword) 98, ((char *) __FUNCTION__), "(n->runtime_index) < vec_len (nm->processes)");
                }
            } while (0);
            (nm->processes) + (n->runtime_index);
        }))[0];
        return &p->node_runtime;
    }
}
static inline __attribute__((__always_inline__)) void *
vlib_node_get_runtime_data(vlib_main_t *vm, u32 node_index)
{
    vlib_node_runtime_t *r = vlib_node_get_runtime(vm, node_index);
    return r->runtime_data;
}
static inline __attribute__((__always_inline__)) void
vlib_node_set_runtime_data(vlib_main_t *vm, u32 node_index, void *runtime_data, u32 n_runtime_data_bytes)
{
    vlib_node_t *n         = vlib_get_node(vm, node_index);
    vlib_node_runtime_t *r = vlib_node_get_runtime(vm, node_index);
    n->runtime_data_bytes  = n_runtime_data_bytes;
    do {
        if (n->runtime_data) {
            clib_mem_free(vec_header((n->runtime_data), (0)));
            n->runtime_data = 0;
        }
    } while (0);
    do {
        word _vec_n = (n_runtime_data_bytes);
        word _vec_l = ((n->runtime_data) ? (((vec_header_t *) (n->runtime_data) - 1)->len) : 0);
        n->runtime_data =
            _vec_resize_inline((n->runtime_data), _vec_n, (_vec_l + _vec_n) * sizeof((n->runtime_data)[0]), (0), ({
                                   __typeof__((__alignof__(((n->runtime_data))[0]))) _x =
                                       ((__alignof__(((n->runtime_data))[0])));
                                   __typeof__(((0))) _y = (((0)));
                                   _x > _y ? _x : _y;
                               }));
        memcpy((n->runtime_data) + _vec_l, (runtime_data), _vec_n * sizeof((n->runtime_data)[0]));
    } while (0);
    do {
        if ((0 > 0) && !(((n->runtime_data) ? (((vec_header_t *) (n->runtime_data) - 1)->len) : 0) <=
                         sizeof(vlib_node_runtime_t) - ((uword) & (((vlib_node_runtime_t *) 0)->runtime_data)))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 135,
                        ((char *) __FUNCTION__),
                        "vec_len (n->runtime_data) <= sizeof (vlib_node_runtime_t) - STRUCT_OFFSET_OF "
                        "(vlib_node_runtime_t, runtime_data)");
        }
    } while (0);
    if (((n->runtime_data) ? (((vec_header_t *) (n->runtime_data) - 1)->len) : 0) > 0)
        memcpy(r->runtime_data, n->runtime_data,
               ((n->runtime_data) ? (((vec_header_t *) (n->runtime_data) - 1)->len) : 0));
}
static inline __attribute__((__always_inline__)) void
vlib_node_set_state(vlib_main_t *vm, u32 node_index, vlib_node_state_t new_state)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_node_t *n;
    vlib_node_runtime_t *r;
    n = (({
        do {
            if ((0 > 0) && !((node_index) < ((nm->nodes) ? (((vec_header_t *) (nm->nodes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 154,
                            ((char *) __FUNCTION__), "(node_index) < vec_len (nm->nodes)");
            }
        } while (0);
        (nm->nodes) + (node_index);
    }))[0];
    if (n->type == VLIB_NODE_TYPE_PROCESS) {
        vlib_process_t *p = (({
            do {
                if ((0 > 0) &&
                    !((n->runtime_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h",
                                (uword) 157, ((char *) __FUNCTION__), "(n->runtime_index) < vec_len (nm->processes)");
                }
            } while (0);
            (nm->processes) + (n->runtime_index);
        }))[0];
        r                 = &p->node_runtime;
        p->flags &= ~((1 << 2) | (1 << 0) | (1 << 1));
    } else
        r = ({
            do {
                if ((0 > 0) &&
                    !((n->runtime_index) <
                      ((nm->nodes_by_type[n->type]) ? (((vec_header_t *) (nm->nodes_by_type[n->type]) - 1)->len) : 0))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 166,
                                ((char *) __FUNCTION__), "(n->runtime_index) < vec_len (nm->nodes_by_type[n->type])");
                }
            } while (0);
            (nm->nodes_by_type[n->type]) + (n->runtime_index);
        });
    do {
        if ((0 > 0) && !(new_state < VLIB_N_NODE_STATE)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 168,
                        ((char *) __FUNCTION__), "new_state < VLIB_N_NODE_STATE");
        }
    } while (0);
    if (n->type == VLIB_NODE_TYPE_INPUT) {
        do {
            if ((0 > 0) && !(nm->input_node_counts_by_state[n->state] > 0)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 172,
                            ((char *) __FUNCTION__), "nm->input_node_counts_by_state[n->state] > 0");
            }
        } while (0);
        nm->input_node_counts_by_state[n->state] -= 1;
        nm->input_node_counts_by_state[new_state] += 1;
    }
    n->state = new_state;
    r->state = new_state;
}
static inline __attribute__((__always_inline__)) vlib_node_state_t
vlib_node_get_state(vlib_main_t *vm, u32 node_index)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_node_t *n;
    n = (({
        do {
            if ((0 > 0) && !((node_index) < ((nm->nodes) ? (((vec_header_t *) (nm->nodes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 191,
                            ((char *) __FUNCTION__), "(node_index) < vec_len (nm->nodes)");
            }
        } while (0);
        (nm->nodes) + (node_index);
    }))[0];
    return n->state;
}
static inline __attribute__((__always_inline__)) void
vlib_node_set_interrupt_pending(vlib_main_t *vm, u32 node_index)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_node_t *n       = (({
        do {
            if ((0 > 0) && !((node_index) < ((nm->nodes) ? (((vec_header_t *) (nm->nodes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 199,
                            ((char *) __FUNCTION__), "(node_index) < vec_len (nm->nodes)");
            }
        } while (0);
        (nm->nodes) + (node_index);
    }))[0];
    do {
        if ((0 > 0) && !(n->type == VLIB_NODE_TYPE_INPUT)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 200,
                        ((char *) __FUNCTION__), "n->type == VLIB_NODE_TYPE_INPUT");
        }
    } while (0);
    clib_spinlock_lock_if_init(&nm->pending_interrupt_lock);
    do {
        word _vec_l = ((nm->pending_interrupt_node_runtime_indices) ?
                           (((vec_header_t *) (nm->pending_interrupt_node_runtime_indices) - 1)->len) :
                           0);
        nm->pending_interrupt_node_runtime_indices =
            _vec_resize_inline((nm->pending_interrupt_node_runtime_indices), 1,
                               (_vec_l + 1) * sizeof((nm->pending_interrupt_node_runtime_indices)[0]), (0), ({
                                   __typeof__((__alignof__(((nm->pending_interrupt_node_runtime_indices))[0]))) _x =
                                       ((__alignof__(((nm->pending_interrupt_node_runtime_indices))[0])));
                                   __typeof__(((0))) _y = (((0)));
                                   _x > _y ? _x : _y;
                               }));
        (nm->pending_interrupt_node_runtime_indices)[_vec_l] = (n->runtime_index);
    } while (0);
    clib_spinlock_unlock_if_init(&nm->pending_interrupt_lock);
}
static inline __attribute__((__always_inline__)) vlib_process_t *
vlib_get_process_from_node(vlib_main_t *vm, vlib_node_t *node)
{
    vlib_node_main_t *nm = &vm->node_main;
    do {
        if ((0 > 0) && !(node->type == VLIB_NODE_TYPE_PROCESS)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 210,
                        ((char *) __FUNCTION__), "node->type == VLIB_NODE_TYPE_PROCESS");
        }
    } while (0);
    return (({
        do {
            if ((0 > 0) &&
                !((node->runtime_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 211,
                            ((char *) __FUNCTION__), "(node->runtime_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (node->runtime_index);
    }))[0];
}
static inline __attribute__((__always_inline__)) vlib_frame_t *
vlib_get_frame_no_check(vlib_main_t *vm, uword frame_index)
{
    vlib_frame_t *f;
    f = vm->heap_aligned_base + (frame_index * (1 << 6));
    return f;
}
static inline __attribute__((__always_inline__)) u32
vlib_frame_index_no_check(vlib_main_t *vm, vlib_frame_t *f)
{
    uword i;
    do {
        if ((0 > 0) && !(((uword) f & ((1 << 6) - 1)) == 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 228,
                        ((char *) __FUNCTION__), "((uword) f & (VLIB_FRAME_ALIGN - 1)) == 0");
        }
    } while (0);
    i = ((u8 *) f - (u8 *) vm->heap_aligned_base);
    do {
        if ((0 > 0) && !((i / (1 << 6)) <= 0xFFFFFFFFULL)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 231,
                        ((char *) __FUNCTION__), "(i / VLIB_FRAME_ALIGN) <= 0xFFFFFFFFULL");
        }
    } while (0);
    return i / (1 << 6);
}
static inline __attribute__((__always_inline__)) vlib_frame_t *
vlib_get_frame(vlib_main_t *vm, uword frame_index)
{
    vlib_frame_t *f = vlib_get_frame_no_check(vm, frame_index);
    do {
        if ((0 > 0) && !(f->frame_flags & (1 << 1))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 240,
                        ((char *) __FUNCTION__), "f->frame_flags & VLIB_FRAME_IS_ALLOCATED");
        }
    } while (0);
    return f;
}
static inline __attribute__((__always_inline__)) u32
vlib_frame_index(vlib_main_t *vm, vlib_frame_t *f)
{
    uword i = vlib_frame_index_no_check(vm, f);
    do {
        if ((0 > 0) && !(vlib_get_frame(vm, i) == f)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 248,
                        ((char *) __FUNCTION__), "vlib_get_frame (vm, i) == f");
        }
    } while (0);
    return i;
}
static inline __attribute__((__always_inline__)) u32
vlib_frame_vector_byte_offset(u32 scalar_size)
{
    return round_pow2(sizeof(vlib_frame_t) + scalar_size, (1 << 4));
}
static inline __attribute__((__always_inline__)) void *
vlib_frame_vector_args(vlib_frame_t *f)
{
    return (void *) f + vlib_frame_vector_byte_offset(f->scalar_size);
}
static inline __attribute__((__always_inline__)) void *
vlib_frame_args(vlib_frame_t *f)
{
    return vlib_frame_vector_args(f) - f->scalar_size;
}
static inline __attribute__((__always_inline__)) vlib_next_frame_t *
vlib_node_runtime_get_next_frame(vlib_main_t *vm, vlib_node_runtime_t *n, u32 next_index)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_next_frame_t *nf;
    do {
        if ((0 > 0) && !(next_index < n->n_next_nodes)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 296,
                        ((char *) __FUNCTION__), "next_index < n->n_next_nodes");
        }
    } while (0);
    nf = ({
        do {
            if ((0 > 0) && !((n->next_frame_index + next_index) <
                             ((nm->next_frames) ? (((vec_header_t *) (nm->next_frames) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 297,
                            ((char *) __FUNCTION__), "(n->next_frame_index + next_index) < vec_len (nm->next_frames)");
            }
        } while (0);
        (nm->next_frames) + (n->next_frame_index + next_index);
    });
    if (0 > 0) {
        vlib_node_t *node, *next;
        node = (({
            do {
                if ((0 > 0) && !((n->node_index) < ((nm->nodes) ? (((vec_header_t *) (nm->nodes) - 1)->len) : 0))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h",
                                (uword) 302, ((char *) __FUNCTION__), "(n->node_index) < vec_len (nm->nodes)");
                }
            } while (0);
            (nm->nodes) + (n->node_index);
        }))[0];
        next = (({
            do {
                if ((0 > 0) &&
                    !((node->next_nodes[next_index]) < ((nm->nodes) ? (((vec_header_t *) (nm->nodes) - 1)->len) : 0))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 303,
                                ((char *) __FUNCTION__), "(node->next_nodes[next_index]) < vec_len (nm->nodes)");
                }
            } while (0);
            (nm->nodes) + (node->next_nodes[next_index]);
        }))[0];
        do {
            if ((0 > 0) && !(nf->node_runtime_index == next->runtime_index)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 304,
                            ((char *) __FUNCTION__), "nf->node_runtime_index == next->runtime_index");
            }
        } while (0);
    }
    return nf;
}
static inline __attribute__((__always_inline__)) vlib_next_frame_t *
vlib_node_get_next_frame(vlib_main_t *vm, u32 node_index, u32 next_index)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_node_t *n;
    vlib_node_runtime_t *r;
    n = (({
        do {
            if ((0 > 0) && !((node_index) < ((nm->nodes) ? (((vec_header_t *) (nm->nodes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 331,
                            ((char *) __FUNCTION__), "(node_index) < vec_len (nm->nodes)");
            }
        } while (0);
        (nm->nodes) + (node_index);
    }))[0];
    r = ({
        do {
            if ((0 > 0) &&
                !((n->runtime_index) <
                  ((nm->nodes_by_type[n->type]) ? (((vec_header_t *) (nm->nodes_by_type[n->type]) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 332,
                            ((char *) __FUNCTION__), "(n->runtime_index) < vec_len (nm->nodes_by_type[n->type])");
            }
        } while (0);
        (nm->nodes_by_type[n->type]) + (n->runtime_index);
    });
    return vlib_node_runtime_get_next_frame(vm, r, next_index);
}
vlib_frame_t *vlib_get_next_frame_internal(vlib_main_t *vm, vlib_node_runtime_t *node, u32 next_index,
                                           u32 alloc_new_frame);
void vlib_put_next_frame(vlib_main_t *vm, vlib_node_runtime_t *r, u32 next_index, u32 n_packets_left);
static inline __attribute__((__always_inline__)) void
vlib_set_next_frame_buffer(vlib_main_t *vm, vlib_node_runtime_t *node, u32 next_index, u32 buffer_index)
{
    u32 *p;
    p    = ({
        uword _n_left;
        do {
            vlib_frame_t *_f = vlib_get_next_frame_internal(((vm)), ((node)), ((next_index)), (0));
            u32 _n           = _f->n_vectors;
            ((p))            = vlib_frame_vector_args(_f) + _n * sizeof(((p))[0]);
            (_n_left)        = 256 - _n;
        } while (0);
        do {
            if ((0 > 0) && !(_n_left > 0)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 402,
                            ((char *) __FUNCTION__), "_n_left > 0");
            }
        } while (0);
        vlib_put_next_frame((vm), (node), (next_index), _n_left - 1);
        (p);
    });
    p[0] = buffer_index;
}
vlib_frame_t *vlib_get_frame_to_node(vlib_main_t *vm, u32 to_node_index);
void vlib_put_frame_to_node(vlib_main_t *vm, u32 to_node_index, vlib_frame_t *f);
static inline __attribute__((__always_inline__)) uword
vlib_in_process_context(vlib_main_t *vm)
{
    return vm->node_main.current_process_index != ~0;
}
static inline __attribute__((__always_inline__)) vlib_process_t *
vlib_get_current_process(vlib_main_t *vm)
{
    vlib_node_main_t *nm = &vm->node_main;
    if (vlib_in_process_context(vm))
        return (({
            do {
                if ((0 > 0) && !((nm->current_process_index) <
                                 ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 421,
                                ((char *) __FUNCTION__), "(nm->current_process_index) < vec_len (nm->processes)");
                }
            } while (0);
            (nm->processes) + (nm->current_process_index);
        }))[0];
    return 0;
}
static inline __attribute__((__always_inline__)) uword
vlib_current_process(vlib_main_t *vm)
{
    return vlib_get_current_process(vm)->node_runtime.node_index;
}
static inline __attribute__((__always_inline__)) uword
vlib_process_suspend_time_is_zero(f64 dt)
{
    return dt < 10e-6;
}
static inline __attribute__((__always_inline__)) uword
vlib_process_suspend(vlib_main_t *vm, f64 dt)
{
    uword r;
    vlib_node_main_t *nm = &vm->node_main;
    vlib_process_t *p    = (({
        do {
            if ((0 > 0) &&
                !((nm->current_process_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 452,
                            ((char *) __FUNCTION__), "(nm->current_process_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (nm->current_process_index);
    }))[0];
    if (vlib_process_suspend_time_is_zero(dt))
        return 1;
    p->flags |= (1 << 0);
    r = clib_setjmp(&p->resume_longjmp, 0);
    if (r == 0) {
        p->resume_clock_interval = dt * 1e5;
        clib_longjmp(&p->return_longjmp, ((uword) ~0 - 1));
    }
    return r;
}
static inline __attribute__((__always_inline__)) void
vlib_process_free_event_type(vlib_process_t *p, uword t, uword is_one_time_event)
{
    do {
        if ((0 > 0) && !(!({
                pool_header_t *_pool_p = pool_header((p->event_type_pool));
                uword _pool_i          = ((p->event_type_pool) + (t)) - ((p->event_type_pool));
                (_pool_i < (((p->event_type_pool)) ? (((vec_header_t *) ((p->event_type_pool)) - 1)->len) : 0)) ?
                    clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                    1;
            }))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 473,
                        ((char *) __FUNCTION__), "!pool_is_free_index (p->event_type_pool, t)");
        }
    } while (0);
    do {
        typeof(p->event_type_pool) _e = (p->event_type_pool) + (t);
        do {
            pool_header_t *_pool_p = pool_header(p->event_type_pool);
            uword _pool_l          = (_e) - (p->event_type_pool);
            do {
                if ((0 > 0) &&
                    !(((_e) >= (p->event_type_pool) &&
                       (_e) < ((p->event_type_pool) +
                               ((p->event_type_pool) ? (((vec_header_t *) (p->event_type_pool) - 1)->len) : 0))))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h",
                                (uword) 474, ((char *) __FUNCTION__), "vec_is_member (p->event_type_pool, _e)");
                }
            } while (0);
            do {
                if ((0 > 0) && !(!({
                        pool_header_t *_pool_p = pool_header(p->event_type_pool);
                        uword _pool_i          = (_e) - (p->event_type_pool);
                        (_pool_i < ((p->event_type_pool) ? (((vec_header_t *) (p->event_type_pool) - 1)->len) : 0)) ?
                            clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                            1;
                    }))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h",
                                (uword) 474, ((char *) __FUNCTION__), "! pool_is_free (p->event_type_pool, _e)");
                }
            } while (0);
            _pool_p->free_bitmap = clib_bitmap_ori_notrim(_pool_p->free_bitmap, _pool_l);
            if (_pool_p->max_elts) {
                do {
                    if ((0 > 0) && !(_pool_l < _pool_p->max_elts)) {
                        _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                    "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h",
                                    (uword) 474, ((char *) __FUNCTION__), "_pool_var(l) < _pool_var (p)->max_elts");
                    }
                } while (0);
                _pool_p->free_indices[(((vec_header_t *) (_pool_p->free_indices) - 1)->len)] = _pool_l;
                (((vec_header_t *) (_pool_p->free_indices) - 1)->len) += 1;
            } else
                do {
                    word _vec_l = ((_pool_p->free_indices) ? (((vec_header_t *) (_pool_p->free_indices) - 1)->len) : 0);
                    _pool_p->free_indices =
                        _vec_resize_inline((_pool_p->free_indices), 1,
                                           (_vec_l + 1) * sizeof((_pool_p->free_indices)[0]), (0), ({
                                               __typeof__((__alignof__(((_pool_p->free_indices))[0]))) _x =
                                                   ((__alignof__(((_pool_p->free_indices))[0])));
                                               __typeof__(((0))) _y = (((0)));
                                               _x > _y ? _x : _y;
                                           }));
                    (_pool_p->free_indices)[_vec_l] = (_pool_l);
                } while (0);
        } while (0);
    } while (0);
    if (is_one_time_event)
        p->one_time_event_type_bitmap = clib_bitmap_andnoti(p->one_time_event_type_bitmap, t);
}
static inline __attribute__((__always_inline__)) void
vlib_process_maybe_free_event_type(vlib_process_t *p, uword t)
{
    do {
        if ((0 > 0) && !(!({
                pool_header_t *_pool_p = pool_header((p->event_type_pool));
                uword _pool_i          = ((p->event_type_pool) + (t)) - ((p->event_type_pool));
                (_pool_i < (((p->event_type_pool)) ? (((vec_header_t *) ((p->event_type_pool)) - 1)->len) : 0)) ?
                    clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                    1;
            }))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 483,
                        ((char *) __FUNCTION__), "!pool_is_free_index (p->event_type_pool, t)");
        }
    } while (0);
    if (clib_bitmap_get(p->one_time_event_type_bitmap, t))
        vlib_process_free_event_type(p, t, 1);
}
static inline __attribute__((__always_inline__)) void *
vlib_process_get_event_data(vlib_main_t *vm, uword *return_event_type_opaque)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_process_t *p;
    vlib_process_event_type_t *et;
    uword t;
    void *event_data_vector;
    p = (({
        do {
            if ((0 > 0) &&
                !((nm->current_process_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 498,
                            ((char *) __FUNCTION__), "(nm->current_process_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (nm->current_process_index);
    }))[0];
    t = clib_bitmap_first_set(p->non_empty_event_type_bitmap);
    if (t == ~0)
        return 0;
    p->non_empty_event_type_bitmap = clib_bitmap_andnoti(p->non_empty_event_type_bitmap, t);
    do {
        if ((0 > 0) && !((((vec_header_t *) (p->pending_event_data_by_type_index[t]) - 1)->len) > 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 509,
                        ((char *) __FUNCTION__), "_vec_len (p->pending_event_data_by_type_index[t]) > 0");
        }
    } while (0);
    event_data_vector                      = p->pending_event_data_by_type_index[t];
    p->pending_event_data_by_type_index[t] = 0;
    et                                     = ({
        typeof(p->event_type_pool) _e = (p->event_type_pool) + (t);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(p->event_type_pool);
                    uword _pool_i          = (_e) - (p->event_type_pool);
                    (_pool_i < ((p->event_type_pool) ? (((vec_header_t *) (p->event_type_pool) - 1)->len) : 0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 513,
                            ((char *) __FUNCTION__), "! pool_is_free (p->event_type_pool, _e)");
            }
        } while (0);
        _e;
    });
    *return_event_type_opaque              = et->opaque;
    vlib_process_maybe_free_event_type(p, t);
    return event_data_vector;
}
static inline __attribute__((__always_inline__)) void
vlib_process_put_event_data(vlib_main_t *vm, void *event_data)
{
    vlib_node_main_t *nm = &vm->node_main;
    do {
        word _vec_l =
            ((nm->recycled_event_data_vectors) ? (((vec_header_t *) (nm->recycled_event_data_vectors) - 1)->len) : 0);
        nm->recycled_event_data_vectors =
            _vec_resize_inline((nm->recycled_event_data_vectors), 1,
                               (_vec_l + 1) * sizeof((nm->recycled_event_data_vectors)[0]), (0), ({
                                   __typeof__((__alignof__(((nm->recycled_event_data_vectors))[0]))) _x =
                                       ((__alignof__(((nm->recycled_event_data_vectors))[0])));
                                   __typeof__(((0))) _y = (((0)));
                                   _x > _y ? _x : _y;
                               }));
        (nm->recycled_event_data_vectors)[_vec_l] = (event_data);
    } while (0);
}
static inline __attribute__((__always_inline__)) uword
vlib_process_get_events(vlib_main_t *vm, uword **data_vector)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_process_t *p;
    vlib_process_event_type_t *et;
    uword r, t, l;
    p = (({
        do {
            if ((0 > 0) &&
                !((nm->current_process_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 549,
                            ((char *) __FUNCTION__), "(nm->current_process_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (nm->current_process_index);
    }))[0];
    t = clib_bitmap_first_set(p->non_empty_event_type_bitmap);
    if (t == ~0)
        return t;
    p->non_empty_event_type_bitmap = clib_bitmap_andnoti(p->non_empty_event_type_bitmap, t);
    l                              = (((vec_header_t *) (p->pending_event_data_by_type_index[t]) - 1)->len);
    if (data_vector)
        do {
            word _vec_n = (l);
            word _vec_l = ((*data_vector) ? (((vec_header_t *) (*data_vector) - 1)->len) : 0);
            *data_vector =
                _vec_resize_inline((*data_vector), _vec_n, (_vec_l + _vec_n) * sizeof((*data_vector)[0]), (0), ({
                                       __typeof__((__alignof__(((*data_vector))[0]))) _x =
                                           ((__alignof__(((*data_vector))[0])));
                                       __typeof__(((0))) _y = (((0)));
                                       _x > _y ? _x : _y;
                                   }));
            memcpy((*data_vector) + _vec_l, (p->pending_event_data_by_type_index[t]), _vec_n * sizeof((*data_vector)[0]));
        } while (0);
    (((vec_header_t *) (p->pending_event_data_by_type_index[t]) - 1)->len) = 0;
    et                                                                     = ({
        typeof(p->event_type_pool) _e = (p->event_type_pool) + (t);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(p->event_type_pool);
                    uword _pool_i          = (_e) - (p->event_type_pool);
                    (_pool_i < ((p->event_type_pool) ? (((vec_header_t *) (p->event_type_pool) - 1)->len) : 0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 565,
                            ((char *) __FUNCTION__), "! pool_is_free (p->event_type_pool, _e)");
            }
        } while (0);
        _e;
    });
    r                                                                      = et->opaque;
    vlib_process_maybe_free_event_type(p, t);
    return r;
}
static inline __attribute__((__always_inline__)) uword
vlib_process_get_events_helper(vlib_process_t *p, uword t, uword **data_vector)
{
    uword l;
    p->non_empty_event_type_bitmap = clib_bitmap_andnoti(p->non_empty_event_type_bitmap, t);
    l                              = (((vec_header_t *) (p->pending_event_data_by_type_index[t]) - 1)->len);
    if (data_vector)
        do {
            word _vec_n = (l);
            word _vec_l = ((*data_vector) ? (((vec_header_t *) (*data_vector) - 1)->len) : 0);
            *data_vector =
                _vec_resize_inline((*data_vector), _vec_n, (_vec_l + _vec_n) * sizeof((*data_vector)[0]), (0), ({
                                       __typeof__((__alignof__(((*data_vector))[0]))) _x =
                                           ((__alignof__(((*data_vector))[0])));
                                       __typeof__(((0))) _y = (((0)));
                                       _x > _y ? _x : _y;
                                   }));
            memcpy((*data_vector) + _vec_l, (p->pending_event_data_by_type_index[t]), _vec_n * sizeof((*data_vector)[0]));
        } while (0);
    (((vec_header_t *) (p->pending_event_data_by_type_index[t]) - 1)->len) = 0;
    vlib_process_maybe_free_event_type(p, t);
    return l;
}
static inline __attribute__((__always_inline__)) uword
vlib_process_get_events_with_type(vlib_main_t *vm, uword **data_vector, uword with_type_opaque)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_process_t *p;
    uword t, *h;
    p = (({
        do {
            if ((0 > 0) &&
                !((nm->current_process_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 604,
                            ((char *) __FUNCTION__), "(nm->current_process_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (nm->current_process_index);
    }))[0];
    h = _hash_get((p->event_type_index_by_type_opaque), (uword)(with_type_opaque));
    if (!h)
        return 0;
    t = h[0];
    if (!clib_bitmap_get(p->non_empty_event_type_bitmap, t))
        return 0;
    return vlib_process_get_events_helper(p, t, data_vector);
}
static inline __attribute__((__always_inline__)) uword *
vlib_process_wait_for_event(vlib_main_t *vm)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_process_t *p;
    uword r;
    p = (({
        do {
            if ((0 > 0) &&
                !((nm->current_process_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 625,
                            ((char *) __FUNCTION__), "(nm->current_process_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (nm->current_process_index);
    }))[0];
    if (clib_bitmap_is_zero(p->non_empty_event_type_bitmap)) {
        p->flags |= (1 << 1);
        r = clib_setjmp(&p->resume_longjmp, 0);
        if (r == 0)
            clib_longjmp(&p->return_longjmp, ((uword) ~0 - 1));
    }
    return p->non_empty_event_type_bitmap;
}
static inline __attribute__((__always_inline__)) uword
vlib_process_wait_for_one_time_event(vlib_main_t *vm, uword **data_vector, uword with_type_index)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_process_t *p;
    uword r;
    p = (({
        do {
            if ((0 > 0) &&
                !((nm->current_process_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 648,
                            ((char *) __FUNCTION__), "(nm->current_process_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (nm->current_process_index);
    }))[0];
    do {
        if ((0 > 0) && !(!({
                pool_header_t *_pool_p = pool_header((p->event_type_pool));
                uword _pool_i          = ((p->event_type_pool) + (with_type_index)) - ((p->event_type_pool));
                (_pool_i < (((p->event_type_pool)) ? (((vec_header_t *) ((p->event_type_pool)) - 1)->len) : 0)) ?
                    clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                    1;
            }))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 649,
                        ((char *) __FUNCTION__), "!pool_is_free_index (p->event_type_pool, with_type_index)");
        }
    } while (0);
    while (!clib_bitmap_get(p->non_empty_event_type_bitmap, with_type_index)) {
        p->flags |= (1 << 1);
        r = clib_setjmp(&p->resume_longjmp, 0);
        if (r == 0)
            clib_longjmp(&p->return_longjmp, ((uword) ~0 - 1));
    }
    return vlib_process_get_events_helper(p, with_type_index, data_vector);
}
static inline __attribute__((__always_inline__)) uword
vlib_process_wait_for_event_with_type(vlib_main_t *vm, uword **data_vector, uword with_type_opaque)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_process_t *p;
    uword r, *h;
    p = (({
        do {
            if ((0 > 0) &&
                !((nm->current_process_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 672,
                            ((char *) __FUNCTION__), "(nm->current_process_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (nm->current_process_index);
    }))[0];
    h = _hash_get((p->event_type_index_by_type_opaque), (uword)(with_type_opaque));
    while (!h || !clib_bitmap_get(p->non_empty_event_type_bitmap, h[0])) {
        p->flags |= (1 << 1);
        r = clib_setjmp(&p->resume_longjmp, 0);
        if (r == 0)
            clib_longjmp(&p->return_longjmp, ((uword) ~0 - 1));
        if (!h)
            h = _hash_get((p->event_type_index_by_type_opaque), (uword)(with_type_opaque));
    }
    return vlib_process_get_events_helper(p, h[0], data_vector);
}
static inline __attribute__((__always_inline__)) f64
vlib_process_wait_for_event_or_clock(vlib_main_t *vm, f64 dt)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_process_t *p;
    f64 wakeup_time;
    uword r;
    p = (({
        do {
            if ((0 > 0) &&
                !((nm->current_process_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 706,
                            ((char *) __FUNCTION__), "(nm->current_process_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (nm->current_process_index);
    }))[0];
    if (vlib_process_suspend_time_is_zero(dt) || !clib_bitmap_is_zero(p->non_empty_event_type_bitmap))
        return dt;
    wakeup_time = vlib_time_now(vm) + dt;
    p->flags |= ((1 << 1) | (1 << 0));
    r = clib_setjmp(&p->resume_longjmp, 0);
    if (r == 0) {
        p->resume_clock_interval = dt * 1e5;
        clib_longjmp(&p->return_longjmp, ((uword) ~0 - 1));
    }
    return wakeup_time - vlib_time_now(vm);
}
static inline __attribute__((__always_inline__)) vlib_process_event_type_t *
vlib_process_new_event_type(vlib_process_t *p, uword with_type_opaque)
{
    vlib_process_event_type_t *et;
    do {
        pool_header_t *_pool_p = pool_header(p->event_type_pool);
        uword _pool_l;
        _Static_assert(0 == 0 || ((0 % sizeof(p->event_type_pool[0])) == 0) || ((sizeof(p->event_type_pool[0]) % 0) == 0),
                       "Pool aligned alloc of incorrectly sized object");
        _pool_l = 0;
        if (p->event_type_pool)
            _pool_l = ((_pool_p->free_indices) ? (((vec_header_t *) (_pool_p->free_indices) - 1)->len) : 0);
        if (_pool_l > 0) {
            uword _pool_i        = _pool_p->free_indices[_pool_l - 1];
            (et)                 = (p->event_type_pool) + _pool_i;
            _pool_p->free_bitmap = clib_bitmap_andnoti_notrim(_pool_p->free_bitmap, _pool_i);
            (((vec_header_t *) (_pool_p->free_indices) - 1)->len) = _pool_l - 1;
        } else {
            if ((p->event_type_pool) && _pool_p->max_elts) {
                _clib_error(CLIB_ERROR_WARNING, ((char *) __FUNCTION__), 734, "can't expand fixed-size pool");
                os_out_of_memory();
            }
            p->event_type_pool =
                _vec_resize_inline(p->event_type_pool, 1,
                                   (((p->event_type_pool) ? (((vec_header_t *) (p->event_type_pool) - 1)->len) : 0) + 1) *
                                       sizeof(p->event_type_pool[0]),
                                   vec_aligned_header_bytes(sizeof(pool_header_t), sizeof(void *)), ({
                                       __typeof__((__alignof__((p->event_type_pool)[0]))) _x =
                                           ((__alignof__((p->event_type_pool)[0])));
                                       __typeof__(((0))) _y = (((0)));
                                       _x > _y ? _x : _y;
                                   }));
            et = ((p->event_type_pool) + ((p->event_type_pool) ? (((vec_header_t *) (p->event_type_pool) - 1)->len) : 0)) -
                 1;
        }
    } while (0);
    et->opaque = with_type_opaque;
    return et;
}
static inline __attribute__((__always_inline__)) uword
vlib_process_create_one_time_event(vlib_main_t *vm, uword node_index, uword with_type_opaque)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_node_t *n       = vlib_get_node(vm, node_index);
    vlib_process_t *p    = (({
        do {
            if ((0 > 0) && !((n->runtime_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 745,
                            ((char *) __FUNCTION__), "(n->runtime_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (n->runtime_index);
    }))[0];
    vlib_process_event_type_t *et;
    uword t;
    et                            = vlib_process_new_event_type(p, with_type_opaque);
    t                             = et - p->event_type_pool;
    p->one_time_event_type_bitmap = clib_bitmap_ori(p->one_time_event_type_bitmap, t);
    return t;
}
static inline __attribute__((__always_inline__)) void
vlib_process_delete_one_time_event(vlib_main_t *vm, uword node_index, uword t)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_node_t *n       = vlib_get_node(vm, node_index);
    vlib_process_t *p    = (({
        do {
            if ((0 > 0) && !((n->runtime_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 762,
                            ((char *) __FUNCTION__), "(n->runtime_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (n->runtime_index);
    }))[0];
    do {
        if ((0 > 0) && !(clib_bitmap_get(p->one_time_event_type_bitmap, t))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 764,
                        ((char *) __FUNCTION__), "clib_bitmap_get (p->one_time_event_type_bitmap, t)");
        }
    } while (0);
    vlib_process_free_event_type(p, t, 1);
}
static inline __attribute__((__always_inline__)) void *
vlib_process_signal_event_helper(vlib_node_main_t *nm, vlib_node_t *n, vlib_process_t *p, uword t, uword n_data_elts,
                                 uword n_data_elt_bytes)
{
    uword p_flags, add_to_pending, delete_from_wheel;
    void *data_to_be_written_by_caller;
    do {
        if ((0 > 0) && !(n->type == VLIB_NODE_TYPE_PROCESS)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 778,
                        ((char *) __FUNCTION__), "n->type == VLIB_NODE_TYPE_PROCESS");
        }
    } while (0);
    do {
        if ((0 > 0) && !(!({
                pool_header_t *_pool_p = pool_header((p->event_type_pool));
                uword _pool_i          = ((p->event_type_pool) + (t)) - ((p->event_type_pool));
                (_pool_i < (((p->event_type_pool)) ? (((vec_header_t *) ((p->event_type_pool)) - 1)->len) : 0)) ?
                    clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                    1;
            }))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 780,
                        ((char *) __FUNCTION__), "!pool_is_free_index (p->event_type_pool, t)");
        }
    } while (0);
    do {
        _Static_assert(0 == 0 || ((0 % sizeof(p->pending_event_data_by_type_index[0])) == 0) ||
                           ((sizeof(p->pending_event_data_by_type_index[0]) % 0) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = (t);
        word _vec_l = ((p->pending_event_data_by_type_index) ?
                           (((vec_header_t *) (p->pending_event_data_by_type_index) - 1)->len) :
                           0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n = (1 + (_vec_i - _vec_l));
                word _vec_l = (((p->pending_event_data_by_type_index)) ?
                                   (((vec_header_t *) ((p->pending_event_data_by_type_index)) - 1)->len) :
                                   0);
                (p->pending_event_data_by_type_index) =
                    _vec_resize_inline(((p->pending_event_data_by_type_index)), _vec_n,
                                       (_vec_l + _vec_n) * sizeof(((p->pending_event_data_by_type_index))[0]), ((0)), ({
                                           __typeof__((__alignof__((((p->pending_event_data_by_type_index)))[0]))) _x =
                                               ((__alignof__((((p->pending_event_data_by_type_index)))[0])));
                                           __typeof__((((0)))) _y = ((((0))));
                                           _x > _y ? _x : _y;
                                       }));
            } while (0);
            memset((p->pending_event_data_by_type_index) + _vec_l, 0,
                   (1 + (_vec_i - _vec_l)) * sizeof((p->pending_event_data_by_type_index)[0]));
        }
    } while (0);
    {
        void *data_vec = p->pending_event_data_by_type_index[t];
        uword l;
        if (!data_vec &&
            ((nm->recycled_event_data_vectors) ? (((vec_header_t *) (nm->recycled_event_data_vectors) - 1)->len) : 0)) {
            data_vec                                = ({
                uword _vec_l = ((nm->recycled_event_data_vectors) ?
                                    (((vec_header_t *) (nm->recycled_event_data_vectors) - 1)->len) :
                                    0);
                do {
                    if ((0 > 0) && !(_vec_l > 0)) {
                        _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                    "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h",
                                    (uword) 791, ((char *) __FUNCTION__), "_v(l) > 0");
                    }
                } while (0);
                _vec_l -= 1;
                (((vec_header_t *) (nm->recycled_event_data_vectors) - 1)->len) = _vec_l;
                (nm->recycled_event_data_vectors)[_vec_l];
            });
            (((vec_header_t *) (data_vec) -1)->len) = 0;
        }
        l        = ((data_vec) ? (((vec_header_t *) (data_vec) -1)->len) : 0);
        data_vec = _vec_resize_inline(data_vec, n_data_elts, (l + n_data_elts) * n_data_elt_bytes, 0, ({
                                          __typeof__((__alignof__((data_vec)[0]))) _x = ((__alignof__((data_vec)[0])));
                                          __typeof__((0)) _y                          = ((0));
                                          _x > _y ? _x : _y;
                                      }));
        p->pending_event_data_by_type_index[t] = data_vec;
        data_to_be_written_by_caller           = data_vec + l * n_data_elt_bytes;
    }
    p->non_empty_event_type_bitmap = clib_bitmap_ori(p->non_empty_event_type_bitmap, t);
    p_flags                        = p->flags;
    add_to_pending                 = (p_flags & (1 << 2)) == 0;
    delete_from_wheel              = 0;
    if (p_flags & (1 << 0)) {
        if (p_flags & (1 << 1)) {
            if (!tw_timer_handle_is_free_1t_3w_1024sl_ov((tw_timer_wheel_1t_3w_1024sl_ov_t *) nm->timing_wheel,
                                                         p->stop_timer_handle))
                delete_from_wheel = 1;
            else
                add_to_pending = 0;
        } else
            add_to_pending = 0;
    }
    add_to_pending &= nm->current_process_index != n->runtime_index;
    if (add_to_pending) {
        u32 x    = vlib_timing_wheel_data_set_suspended_process(n->runtime_index);
        p->flags = p_flags | (1 << 2);
        do {
            word _vec_l = ((nm->data_from_advancing_timing_wheel) ?
                               (((vec_header_t *) (nm->data_from_advancing_timing_wheel) - 1)->len) :
                               0);
            nm->data_from_advancing_timing_wheel =
                _vec_resize_inline((nm->data_from_advancing_timing_wheel), 1,
                                   (_vec_l + 1) * sizeof((nm->data_from_advancing_timing_wheel)[0]), (0), ({
                                       __typeof__((__alignof__(((nm->data_from_advancing_timing_wheel))[0]))) _x =
                                           ((__alignof__(((nm->data_from_advancing_timing_wheel))[0])));
                                       __typeof__(((0))) _y = (((0)));
                                       _x > _y ? _x : _y;
                                   }));
            (nm->data_from_advancing_timing_wheel)[_vec_l] = (x);
        } while (0);
        if (delete_from_wheel)
            tw_timer_stop_1t_3w_1024sl_ov((tw_timer_wheel_1t_3w_1024sl_ov_t *) nm->timing_wheel, p->stop_timer_handle);
    }
    return data_to_be_written_by_caller;
}
static inline __attribute__((__always_inline__)) void *
vlib_process_signal_event_data(vlib_main_t *vm, uword node_index, uword type_opaque, uword n_data_elts,
                               uword n_data_elt_bytes)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_node_t *n       = vlib_get_node(vm, node_index);
    vlib_process_t *p    = (({
        do {
            if ((0 > 0) && !((n->runtime_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 861,
                            ((char *) __FUNCTION__), "(n->runtime_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (n->runtime_index);
    }))[0];
    uword *h, t;
    do {
        if ((0 > 0) && !(vlib_get_thread_index() == 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 865,
                        ((char *) __FUNCTION__), "vlib_get_thread_index () == 0");
        }
    } while (0);
    h = _hash_get((p->event_type_index_by_type_opaque), (uword)(type_opaque));
    if (!h) {
        vlib_process_event_type_t *et = vlib_process_new_event_type(p, type_opaque);
        t                             = et - p->event_type_pool;
        ({
            uword _v = (uword)(t);
            (p->event_type_index_by_type_opaque) =
                _hash_set3((p->event_type_index_by_type_opaque), (uword)(type_opaque), (void *) &_v, (0));
        });
    } else
        t = h[0];
    return vlib_process_signal_event_helper(nm, n, p, t, n_data_elts, n_data_elt_bytes);
}
static inline __attribute__((__always_inline__)) void *
vlib_process_signal_event_at_time(vlib_main_t *vm, f64 dt, uword node_index, uword type_opaque, uword n_data_elts,
                                  uword n_data_elt_bytes)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_node_t *n       = vlib_get_node(vm, node_index);
    vlib_process_t *p    = (({
        do {
            if ((0 > 0) && !((n->runtime_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 891,
                            ((char *) __FUNCTION__), "(n->runtime_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (n->runtime_index);
    }))[0];
    uword *h, t;
    h = _hash_get((p->event_type_index_by_type_opaque), (uword)(type_opaque));
    if (!h) {
        vlib_process_event_type_t *et = vlib_process_new_event_type(p, type_opaque);
        t                             = et - p->event_type_pool;
        ({
            uword _v = (uword)(t);
            (p->event_type_index_by_type_opaque) =
                _hash_set3((p->event_type_index_by_type_opaque), (uword)(type_opaque), (void *) &_v, (0));
        });
    } else
        t = h[0];
    if (vlib_process_suspend_time_is_zero(dt))
        return vlib_process_signal_event_helper(nm, n, p, t, n_data_elts, n_data_elt_bytes);
    else {
        vlib_signal_timed_event_data_t *te;
        do {
            pool_header_t *_pool_p = pool_header(nm->signal_timed_event_data_pool);
            uword _pool_l;
            _Static_assert(sizeof(te[0]) == 0 || ((sizeof(te[0]) % sizeof(nm->signal_timed_event_data_pool[0])) == 0) ||
                               ((sizeof(nm->signal_timed_event_data_pool[0]) % sizeof(te[0])) == 0),
                           "Pool aligned alloc of incorrectly sized object");
            _pool_l = 0;
            if (nm->signal_timed_event_data_pool)
                _pool_l = ((_pool_p->free_indices) ? (((vec_header_t *) (_pool_p->free_indices) - 1)->len) : 0);
            if (_pool_l > 0) {
                uword _pool_i        = _pool_p->free_indices[_pool_l - 1];
                (te)                 = (nm->signal_timed_event_data_pool) + _pool_i;
                _pool_p->free_bitmap = clib_bitmap_andnoti_notrim(_pool_p->free_bitmap, _pool_i);
                (((vec_header_t *) (_pool_p->free_indices) - 1)->len) = _pool_l - 1;
            } else {
                if ((nm->signal_timed_event_data_pool) && _pool_p->max_elts) {
                    _clib_error(CLIB_ERROR_WARNING, ((char *) __FUNCTION__), 912, "can't expand fixed-size pool");
                    os_out_of_memory();
                }
                nm->signal_timed_event_data_pool =
                    _vec_resize_inline(nm->signal_timed_event_data_pool, 1,
                                       (((nm->signal_timed_event_data_pool) ?
                                             (((vec_header_t *) (nm->signal_timed_event_data_pool) - 1)->len) :
                                             0) +
                                        1) *
                                           sizeof(nm->signal_timed_event_data_pool[0]),
                                       vec_aligned_header_bytes(sizeof(pool_header_t), sizeof(void *)), ({
                                           __typeof__((__alignof__((nm->signal_timed_event_data_pool)[0]))) _x =
                                               ((__alignof__((nm->signal_timed_event_data_pool)[0])));
                                           __typeof__(((sizeof(te[0])))) _y = (((sizeof(te[0]))));
                                           _x > _y ? _x : _y;
                                       }));
                te = ((nm->signal_timed_event_data_pool) +
                      ((nm->signal_timed_event_data_pool) ?
                           (((vec_header_t *) (nm->signal_timed_event_data_pool) - 1)->len) :
                           0)) -
                     1;
            }
        } while (0);
        te->n_data_elts      = n_data_elts;
        te->n_data_elt_bytes = n_data_elt_bytes;
        te->n_data_bytes     = n_data_elts * n_data_elt_bytes;
        do {
            if ((0 > 0) && !(te->n_data_elts == n_data_elts)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 919,
                            ((char *) __FUNCTION__), "te->n_data_elts == n_data_elts");
            }
        } while (0);
        do {
            if ((0 > 0) && !(te->n_data_elt_bytes == n_data_elt_bytes)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 920,
                            ((char *) __FUNCTION__), "te->n_data_elt_bytes == n_data_elt_bytes");
            }
        } while (0);
        do {
            if ((0 > 0) && !(te->n_data_bytes == n_data_elts * n_data_elt_bytes)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 921,
                            ((char *) __FUNCTION__), "te->n_data_bytes == n_data_elts * n_data_elt_bytes");
            }
        } while (0);
        te->process_node_index = n->runtime_index;
        te->event_type_index   = t;
        p->stop_timer_handle =
            tw_timer_start_1t_3w_1024sl_ov((tw_timer_wheel_1t_3w_1024sl_ov_t *) nm->timing_wheel,
                                           vlib_timing_wheel_data_set_timed_event(te - nm->signal_timed_event_data_pool),
                                           0, (vlib_time_now(vm) + dt) * 1e5);
        if (te->n_data_bytes < sizeof(te->inline_event_data))
            return te->inline_event_data;
        else {
            te->event_data_as_vector = 0;
            do {
                word _vec_n = (te->n_data_bytes);
                word _vec_l = ((te->event_data_as_vector) ? (((vec_header_t *) (te->event_data_as_vector) - 1)->len) : 0);
                te->event_data_as_vector =
                    _vec_resize_inline((te->event_data_as_vector), _vec_n,
                                       (_vec_l + _vec_n) * sizeof((te->event_data_as_vector)[0]), (0), ({
                                           __typeof__((__alignof__(((te->event_data_as_vector))[0]))) _x =
                                               ((__alignof__(((te->event_data_as_vector))[0])));
                                           __typeof__(((0))) _y = (((0)));
                                           _x > _y ? _x : _y;
                                       }));
            } while (0);
            return te->event_data_as_vector;
        }
    }
}
static inline __attribute__((__always_inline__)) void *
vlib_process_signal_one_time_event_data(vlib_main_t *vm, uword node_index, uword type_index, uword n_data_elts,
                                        uword n_data_elt_bytes)
{
    vlib_node_main_t *nm = &vm->node_main;
    vlib_node_t *n       = vlib_get_node(vm, node_index);
    vlib_process_t *p    = (({
        do {
            if ((0 > 0) && !((n->runtime_index) < ((nm->processes) ? (((vec_header_t *) (nm->processes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 954,
                            ((char *) __FUNCTION__), "(n->runtime_index) < vec_len (nm->processes)");
            }
        } while (0);
        (nm->processes) + (n->runtime_index);
    }))[0];
    return vlib_process_signal_event_helper(nm, n, p, type_index, n_data_elts, n_data_elt_bytes);
}
static inline __attribute__((__always_inline__)) void
vlib_process_signal_event(vlib_main_t *vm, uword node_index, uword type_opaque, uword data)
{
    uword *d = vlib_process_signal_event_data(vm, node_index, type_opaque, 1, sizeof(uword));
    d[0]     = data;
}
static inline __attribute__((__always_inline__)) void
vlib_process_signal_event_pointer(vlib_main_t *vm, uword node_index, uword type_opaque, void *data)
{
    void **d = vlib_process_signal_event_data(vm, node_index, type_opaque, 1, sizeof(data));
    d[0]     = data;
}
static inline __attribute__((__always_inline__)) void
vlib_process_signal_event_mt(vlib_main_t *vm, uword node_index, uword type_opaque, uword data)
{
    if (vlib_get_thread_index() != 0) {
        vlib_process_signal_event_mt_args_t args = {
            .node_index  = node_index,
            .type_opaque = type_opaque,
            .data        = data,
        };
        vlib_rpc_call_main_thread(vlib_process_signal_event_mt_helper, (u8 *) &args, sizeof(args));
    } else
        vlib_process_signal_event(vm, node_index, type_opaque, data);
}
static inline __attribute__((__always_inline__)) void
vlib_process_signal_one_time_event(vlib_main_t *vm, uword node_index, uword type_index, uword data)
{
    uword *d = vlib_process_signal_one_time_event_data(vm, node_index, type_index, 1, sizeof(uword));
    d[0]     = data;
}
static inline __attribute__((__always_inline__)) void
vlib_signal_one_time_waiting_process(vlib_main_t *vm, vlib_one_time_waiting_process_t *p)
{
    vlib_process_signal_one_time_event(vm, p->node_index, p->one_time_event, ~0);
    memset(p, ~0, sizeof(p[0]));
}
static inline __attribute__((__always_inline__)) void
vlib_signal_one_time_waiting_process_vector(vlib_main_t *vm, vlib_one_time_waiting_process_t **wps)
{
    vlib_one_time_waiting_process_t *wp;
    for (wp = (*wps); wp < ((*wps) + ((*wps) ? (((vec_header_t *) (*wps) - 1)->len) : 0)); wp++)
        vlib_signal_one_time_waiting_process(vm, wp);
    do {
        if (*wps) {
            clib_mem_free(vec_header((*wps), (0)));
            *wps = 0;
        }
    } while (0);
}
static inline __attribute__((__always_inline__)) void
vlib_current_process_wait_for_one_time_event(vlib_main_t *vm, vlib_one_time_waiting_process_t *p)
{
    p->node_index     = vlib_current_process(vm);
    p->one_time_event = vlib_process_create_one_time_event(vm, p->node_index, ~0);
    vlib_process_wait_for_one_time_event(vm, 0, p->one_time_event);
}
static inline __attribute__((__always_inline__)) void
vlib_current_process_wait_for_one_time_event_vector(vlib_main_t *vm, vlib_one_time_waiting_process_t **wps)
{
    vlib_one_time_waiting_process_t *wp;
    do {
        word _vec_n = (1);
        word _vec_l = ((*wps) ? (((vec_header_t *) (*wps) - 1)->len) : 0);
        *wps        = _vec_resize_inline((*wps), _vec_n, (_vec_l + _vec_n) * sizeof((*wps)[0]), (0), ({
                                      __typeof__((__alignof__(((*wps))[0]))) _x = ((__alignof__(((*wps))[0])));
                                      __typeof__(((0))) _y                      = (((0)));
                                      _x > _y ? _x : _y;
                                  }));
        wp          = (*wps) + _vec_l;
    } while (0);
    vlib_current_process_wait_for_one_time_event(vm, wp);
}
static inline __attribute__((__always_inline__)) u32
vlib_node_runtime_update_main_loop_vector_stats(vlib_main_t *vm, vlib_node_runtime_t *node, uword n_vectors)
{
    u32 i, d, vi0, vi1;
    u32 i0, i1;
    do {
        if ((0 > 0) && !(is_pow2((sizeof(node->main_loop_vector_stats) / sizeof(node->main_loop_vector_stats[0]))))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/node_funcs.h", (uword) 1062,
                        ((char *) __FUNCTION__), "is_pow2 (ARRAY_LEN (node->main_loop_vector_stats))");
        }
    } while (0);
    i   = ((vm->main_loop_count >> 7) &
         ((sizeof(node->main_loop_vector_stats) / sizeof(node->main_loop_vector_stats[0])) - 1));
    i0  = i ^ 0;
    i1  = i ^ 1;
    d   = ((vm->main_loop_count >> 7) - (node->main_loop_count_last_dispatch >> 7));
    vi0 = node->main_loop_vector_stats[i0];
    vi1 = node->main_loop_vector_stats[i1];
    vi0 = d == 0 ? vi0 : 0;
    vi1 = d <= 1 ? vi1 : 0;
    vi0 += n_vectors;
    node->main_loop_vector_stats[i0]    = vi0;
    node->main_loop_vector_stats[i1]    = vi1;
    node->main_loop_count_last_dispatch = vm->main_loop_count;
    return node->main_loop_vector_stats[i1];
}
static inline __attribute__((__always_inline__)) f64
vlib_node_vectors_per_main_loop_as_float(vlib_main_t *vm, u32 node_index)
{
    vlib_node_runtime_t *rt = vlib_node_get_runtime(vm, node_index);
    u32 v;
    v = vlib_node_runtime_update_main_loop_vector_stats(vm, rt, 0);
    return (f64) v / (1 << 7);
}
static inline __attribute__((__always_inline__)) u32
vlib_node_vectors_per_main_loop_as_integer(vlib_main_t *vm, u32 node_index)
{
    vlib_node_runtime_t *rt = vlib_node_get_runtime(vm, node_index);
    u32 v;
    v = vlib_node_runtime_update_main_loop_vector_stats(vm, rt, 0);
    return v >> 7;
}
void vlib_frame_free(vlib_main_t *vm, vlib_node_runtime_t *r, vlib_frame_t *f);
uword vlib_node_get_next(vlib_main_t *vm, uword node, uword next_node);
uword vlib_node_add_next_with_slot(vlib_main_t *vm, uword node, uword next_node, uword slot);
static inline __attribute__((__always_inline__)) uword
vlib_node_add_next(vlib_main_t *vm, uword node, uword next_node)
{
    return vlib_node_add_next_with_slot(vm, node, next_node, ~0);
}
uword vlib_node_add_named_next_with_slot(vlib_main_t *vm, uword node, char *next_name, uword slot);
static inline __attribute__((__always_inline__)) uword
vlib_node_add_named_next(vlib_main_t *vm, uword node, char *name)
{
    return vlib_node_add_named_next_with_slot(vm, node, name, ~0);
}
void vlib_node_get_nodes(vlib_main_t *vm, u32 max_threads, int include_stats, int barrier_sync,
                         vlib_node_t ****node_dupsp, vlib_main_t ***stat_vmsp);
vlib_node_t *vlib_get_node_by_name(vlib_main_t *vm, u8 *name);
void vlib_node_rename(vlib_main_t *vm, u32 node_index, char *fmt, ...);
u32 vlib_register_node(vlib_main_t *vm, vlib_node_registration_t *r);
void vlib_register_all_static_nodes(vlib_main_t *vm);
void vlib_start_process(vlib_main_t *vm, uword process_index);
void vlib_node_sync_stats(vlib_main_t *vm, vlib_node_t *n);
clib_error_t *vlib_node_main_init(vlib_main_t *vm);
format_function_t format_vlib_node_graph;
format_function_t format_vlib_node_name;
format_function_t format_vlib_next_node_name;
format_function_t format_vlib_node_and_next;
format_function_t format_vlib_cpu_time;
format_function_t format_vlib_time;
unformat_function_t unformat_vlib_node;
static inline __attribute__((__always_inline__)) void
vlib_node_increment_counter(vlib_main_t *vm, u32 node_index, u32 counter_index, u64 increment)
{
    vlib_node_t *n              = vlib_get_node(vm, node_index);
    vlib_error_main_t *em       = &vm->error_main;
    u32 node_counter_base_index = n->error_heap_index;
    em->counters[node_counter_base_index + counter_index] += increment;
}
static inline __attribute__((__always_inline__)) void
vlib_error_elog_count(vlib_main_t *vm, uword counter, uword increment)
{
    if (0 > 0 && increment > 0) {
        elog_main_t *em = &vm->elog_main;
        elog(em, ({
                 do {
                     if ((0 > 0) && !((counter) < ((vm->error_elog_event_types) ?
                                                       (((vec_header_t *) (vm->error_elog_event_types) - 1)->len) :
                                                       0))) {
                         _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                     "../../../build-root/install-vpp_debug-native/vpp/include/vlib/error_funcs.h",
                                     (uword) 51, ((char *) __FUNCTION__),
                                     "(counter) < vec_len (vm->error_elog_event_types)");
                     }
                 } while (0);
                 (vm->error_elog_event_types) + (counter);
             }),
             increment);
    }
}
static inline __attribute__((__always_inline__)) void
vlib_error_count(vlib_main_t *vm, uword node_index, uword counter, uword increment)
{
    vlib_node_t *n        = vlib_get_node(vm, node_index);
    vlib_error_main_t *em = &vm->error_main;
    do {
        if ((0 > 0) && !(counter < n->n_errors)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/error_funcs.h", (uword) 63,
                        ((char *) __FUNCTION__), "counter < n->n_errors");
        }
    } while (0);
    counter += n->error_heap_index;
    do {
        if ((0 > 0) && !(counter < ((em->counters) ? (((vec_header_t *) (em->counters) - 1)->len) : 0))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/error_funcs.h", (uword) 66,
                        ((char *) __FUNCTION__), "counter < vec_len (em->counters)");
        }
    } while (0);
    em->counters[counter] += increment;
    vlib_error_elog_count(vm, counter, increment);
}
uword vlib_error_drop_buffers(vlib_main_t *vm, vlib_node_runtime_t *node, u32 *buffers, u32 next_buffer_stride,
                              u32 n_buffers, u32 error_next_index, u32 error_node, u32 error_code);
u8 *format_vlib_rx_tx(u8 *s, va_list *args);
u8 *format_vlib_read_write(u8 *s, va_list *args);
u8 *format_vlib_buffer_data(u8 *s, va_list *args);
uword unformat_vlib_enable_disable(unformat_input_t *input, va_list *args);
uword unformat_vlib_rx_tx(unformat_input_t *input, va_list *args);
uword unformat_vlib_number_by_name(unformat_input_t *input, va_list *args);
uword unformat_vlib_number(unformat_input_t *input, va_list *args);
extern u8 *vnet_trace_dummy;
static inline __attribute__((__always_inline__)) void
vlib_validate_trace(vlib_trace_main_t *tm, vlib_buffer_t *b)
{
    do {
        if ((0 > 0) && !(1 || b->flags & VLIB_BUFFER_IS_TRACED)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/trace_funcs.h", (uword) 52,
                        ((char *) __FUNCTION__), "1 || b->flags & VLIB_BUFFER_IS_TRACED");
        }
    } while (0);
    do {
        if ((0 > 0) && !(!({
                pool_header_t *_pool_p = pool_header((tm->trace_buffer_pool));
                uword _pool_i          = ((tm->trace_buffer_pool) + (b->trace_index)) - ((tm->trace_buffer_pool));
                (_pool_i < (((tm->trace_buffer_pool)) ? (((vec_header_t *) ((tm->trace_buffer_pool)) - 1)->len) : 0)) ?
                    clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                    1;
            }))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/trace_funcs.h", (uword) 53,
                        ((char *) __FUNCTION__), "!pool_is_free_index (tm->trace_buffer_pool, b->trace_index)");
        }
    } while (0);
}
static inline __attribute__((__always_inline__)) void *
vlib_add_trace(vlib_main_t *vm, vlib_node_runtime_t *r, vlib_buffer_t *b, u32 n_data_bytes)
{
    vlib_trace_main_t *tm = &vm->trace_main;
    vlib_trace_header_t *h;
    u32 n_data_words;
    do {
        if ((0 > 0) && !(vnet_trace_dummy)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/trace_funcs.h", (uword) 64,
                        ((char *) __FUNCTION__), "vnet_trace_dummy");
        }
    } while (0);
    if (__builtin_expect((tm->trace_enable == 0), 0)) {
        do {
            if ((0 > 0) && !(((vnet_trace_dummy) ? (((vec_header_t *) (vnet_trace_dummy) -1)->len) : 0) >=
                             n_data_bytes + sizeof(*h))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/trace_funcs.h", (uword) 68,
                            ((char *) __FUNCTION__), "vec_len (vnet_trace_dummy) >= n_data_bytes + sizeof (*h)");
            }
        } while (0);
        return vnet_trace_dummy;
    }
    vlib_validate_trace(tm, b);
    n_data_bytes = round_pow2(n_data_bytes, sizeof(h[0]));
    n_data_words = n_data_bytes / sizeof(h[0]);
    do {
        word _vec_n = (1 + n_data_words);
        word _vec_l = ((tm->trace_buffer_pool[b->trace_index]) ?
                           (((vec_header_t *) (tm->trace_buffer_pool[b->trace_index]) - 1)->len) :
                           0);
        tm->trace_buffer_pool[b->trace_index] =
            _vec_resize_inline((tm->trace_buffer_pool[b->trace_index]), _vec_n,
                               (_vec_l + _vec_n) * sizeof((tm->trace_buffer_pool[b->trace_index])[0]), (0), ({
                                   __typeof__((__alignof__(((tm->trace_buffer_pool[b->trace_index]))[0]))) _x =
                                       ((__alignof__(((tm->trace_buffer_pool[b->trace_index]))[0])));
                                   __typeof__(((sizeof(h[0])))) _y = (((sizeof(h[0]))));
                                   _x > _y ? _x : _y;
                               }));
        h = (tm->trace_buffer_pool[b->trace_index]) + _vec_l;
    } while (0);
    h->time       = vm->cpu_time_last_node_dispatch;
    h->n_data     = n_data_words;
    h->node_index = r->node_index;
    return h->data;
}
static inline __attribute__((__always_inline__)) vlib_trace_header_t *
vlib_trace_header_next(vlib_trace_header_t *h)
{
    return h + 1 + h->n_data;
}
static inline __attribute__((__always_inline__)) void
vlib_free_trace(vlib_main_t *vm, vlib_buffer_t *b)
{
    vlib_trace_main_t *tm = &vm->trace_main;
    vlib_validate_trace(tm, b);
    (((vec_header_t *) (tm->trace_buffer_pool[b->trace_index]) - 1)->len) = 0;
    do {
        typeof(tm->trace_buffer_pool) _e = (tm->trace_buffer_pool) + (b->trace_index);
        do {
            pool_header_t *_pool_p = pool_header(tm->trace_buffer_pool);
            uword _pool_l          = (_e) - (tm->trace_buffer_pool);
            do {
                if ((0 > 0) &&
                    !(((_e) >= (tm->trace_buffer_pool) &&
                       (_e) < ((tm->trace_buffer_pool) +
                               ((tm->trace_buffer_pool) ? (((vec_header_t *) (tm->trace_buffer_pool) - 1)->len) : 0))))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/trace_funcs.h",
                                (uword) 98, ((char *) __FUNCTION__), "vec_is_member (tm->trace_buffer_pool, _e)");
                }
            } while (0);
            do {
                if ((0 > 0) && !(!({
                        pool_header_t *_pool_p = pool_header(tm->trace_buffer_pool);
                        uword _pool_i          = (_e) - (tm->trace_buffer_pool);
                        (_pool_i < ((tm->trace_buffer_pool) ? (((vec_header_t *) (tm->trace_buffer_pool) - 1)->len) : 0)) ?
                            clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                            1;
                    }))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vlib/trace_funcs.h",
                                (uword) 98, ((char *) __FUNCTION__), "! pool_is_free (tm->trace_buffer_pool, _e)");
                }
            } while (0);
            _pool_p->free_bitmap = clib_bitmap_ori_notrim(_pool_p->free_bitmap, _pool_l);
            if (_pool_p->max_elts) {
                do {
                    if ((0 > 0) && !(_pool_l < _pool_p->max_elts)) {
                        _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                    "../../../build-root/install-vpp_debug-native/vpp/include/vlib/trace_funcs.h",
                                    (uword) 98, ((char *) __FUNCTION__), "_pool_var(l) < _pool_var (p)->max_elts");
                    }
                } while (0);
                _pool_p->free_indices[(((vec_header_t *) (_pool_p->free_indices) - 1)->len)] = _pool_l;
                (((vec_header_t *) (_pool_p->free_indices) - 1)->len) += 1;
            } else
                do {
                    word _vec_l = ((_pool_p->free_indices) ? (((vec_header_t *) (_pool_p->free_indices) - 1)->len) : 0);
                    _pool_p->free_indices =
                        _vec_resize_inline((_pool_p->free_indices), 1,
                                           (_vec_l + 1) * sizeof((_pool_p->free_indices)[0]), (0), ({
                                               __typeof__((__alignof__(((_pool_p->free_indices))[0]))) _x =
                                                   ((__alignof__(((_pool_p->free_indices))[0])));
                                               __typeof__(((0))) _y = (((0)));
                                               _x > _y ? _x : _y;
                                           }));
                    (_pool_p->free_indices)[_vec_l] = (_pool_l);
                } while (0);
        } while (0);
    } while (0);
}
static inline __attribute__((__always_inline__)) void
vlib_trace_next_frame(vlib_main_t *vm, vlib_node_runtime_t *r, u32 next_index)
{
    vlib_next_frame_t *nf;
    nf = vlib_node_runtime_get_next_frame(vm, r, next_index);
    nf->flags |= (1 << 5);
}
void trace_apply_filter(vlib_main_t *vm);
static inline __attribute__((__always_inline__)) void
vlib_trace_buffer(vlib_main_t *vm, vlib_node_runtime_t *r, u32 next_index, vlib_buffer_t *b, int follow_chain)
{
    vlib_trace_main_t *tm = &vm->trace_main;
    vlib_trace_header_t **h;
    if (__builtin_expect((tm->trace_enable == 0), 0))
        return;
    if (tm->last_main_loop_count != vm->main_loop_count) {
        tm->last_main_loop_count = vm->main_loop_count;
        trace_apply_filter(vm);
    }
    vlib_trace_next_frame(vm, r, next_index);
    do {
        pool_header_t *_pool_p = pool_header(tm->trace_buffer_pool);
        uword _pool_l;
        _Static_assert(0 == 0 || ((0 % sizeof(tm->trace_buffer_pool[0])) == 0) ||
                           ((sizeof(tm->trace_buffer_pool[0]) % 0) == 0),
                       "Pool aligned alloc of incorrectly sized object");
        _pool_l = 0;
        if (tm->trace_buffer_pool)
            _pool_l = ((_pool_p->free_indices) ? (((vec_header_t *) (_pool_p->free_indices) - 1)->len) : 0);
        if (_pool_l > 0) {
            uword _pool_i        = _pool_p->free_indices[_pool_l - 1];
            (h)                  = (tm->trace_buffer_pool) + _pool_i;
            _pool_p->free_bitmap = clib_bitmap_andnoti_notrim(_pool_p->free_bitmap, _pool_i);
            (((vec_header_t *) (_pool_p->free_indices) - 1)->len) = _pool_l - 1;
        } else {
            if ((tm->trace_buffer_pool) && _pool_p->max_elts) {
                _clib_error(CLIB_ERROR_WARNING, ((char *) __FUNCTION__), 136, "can't expand fixed-size pool");
                os_out_of_memory();
            }
            tm->trace_buffer_pool =
                _vec_resize_inline(tm->trace_buffer_pool, 1,
                                   (((tm->trace_buffer_pool) ? (((vec_header_t *) (tm->trace_buffer_pool) - 1)->len) : 0) +
                                    1) *
                                       sizeof(tm->trace_buffer_pool[0]),
                                   vec_aligned_header_bytes(sizeof(pool_header_t), sizeof(void *)), ({
                                       __typeof__((__alignof__((tm->trace_buffer_pool)[0]))) _x =
                                           ((__alignof__((tm->trace_buffer_pool)[0])));
                                       __typeof__(((0))) _y = (((0)));
                                       _x > _y ? _x : _y;
                                   }));
            h = ((tm->trace_buffer_pool) +
                 ((tm->trace_buffer_pool) ? (((vec_header_t *) (tm->trace_buffer_pool) - 1)->len) : 0)) -
                1;
        }
    } while (0);
    do {
        b->flags |= VLIB_BUFFER_IS_TRACED;
        b->trace_index = h - tm->trace_buffer_pool;
    } while (follow_chain && (b = vlib_get_next_buffer(vm, b)));
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_copy_trace_flag(vlib_main_t *vm, vlib_buffer_t *b, u32 bi_target)
{
    vlib_buffer_t *b_target = vlib_get_buffer(vm, bi_target);
    b_target->flags |= b->flags & VLIB_BUFFER_IS_TRACED;
    b_target->trace_index = b->trace_index;
}
static inline __attribute__((__always_inline__)) u32
vlib_get_trace_count(vlib_main_t *vm, vlib_node_runtime_t *rt)
{
    vlib_trace_main_t *tm = &vm->trace_main;
    vlib_trace_node_t *tn;
    int n;
    if (rt->node_index >= ((tm->nodes) ? (((vec_header_t *) (tm->nodes) - 1)->len) : 0))
        return 0;
    tn = tm->nodes + rt->node_index;
    n  = tn->limit - tn->count;
    do {
        if ((0 > 0) && !(n >= 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/trace_funcs.h", (uword) 166,
                        ((char *) __FUNCTION__), "n >= 0");
        }
    } while (0);
    return n;
}
static inline __attribute__((__always_inline__)) void
vlib_set_trace_count(vlib_main_t *vm, vlib_node_runtime_t *rt, u32 count)
{
    vlib_trace_main_t *tm = &vm->trace_main;
    vlib_trace_node_t *tn = ({
        do {
            if ((0 > 0) && !((rt->node_index) < ((tm->nodes) ? (((vec_header_t *) (tm->nodes) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/trace_funcs.h", (uword) 175,
                            ((char *) __FUNCTION__), "(rt->node_index) < vec_len (tm->nodes)");
            }
        } while (0);
        (tm->nodes) + (rt->node_index);
    });
    do {
        if ((0 > 0) && !(count <= tn->limit)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/trace_funcs.h", (uword) 177,
                        ((char *) __FUNCTION__), "count <= tn->limit");
        }
    } while (0);
    tn->count = tn->limit - count;
}
void vlib_trace_frame_buffers_only(vlib_main_t *vm, vlib_node_runtime_t *node, u32 *buffers, uword n_buffers,
                                   uword next_buffer_stride, uword n_buffer_data_bytes_in_trace);
static inline __attribute__((__always_inline__)) uword
generic_buffer_node_inline(vlib_main_t *vm, vlib_node_runtime_t *node, vlib_frame_t *frame, uword sizeof_trace,
                           void *opaque1, uword opaque2,
                           void (*two_buffers)(vlib_main_t *vm, void *opaque1, uword opaque2, vlib_buffer_t *b0,
                                               vlib_buffer_t *b1, u32 *next0, u32 *next1),
                           void (*one_buffer)(vlib_main_t *vm, void *opaque1, uword opaque2, vlib_buffer_t *b0,
                                              u32 *next0))
{
    u32 n_left_from, *from, *to_next;
    u32 next_index;
    from        = vlib_frame_vector_args(frame);
    n_left_from = frame->n_vectors;
    next_index  = node->cached_next_index;
    if (node->flags & (1 << 5))
        vlib_trace_frame_buffers_only(vm, node, from, frame->n_vectors, 1, sizeof_trace);
    while (n_left_from > 0) {
        u32 n_left_to_next;
        do {
            vlib_frame_t *_f = vlib_get_next_frame_internal((vm), (node), (next_index), (0));
            u32 _n           = _f->n_vectors;
            (to_next)        = vlib_frame_vector_args(_f) + _n * sizeof((to_next)[0]);
            (n_left_to_next) = 256 - _n;
        } while (0);
        while (n_left_from >= 4 && n_left_to_next >= 2) {
            vlib_buffer_t *p0, *p1;
            u32 pi0, next0;
            u32 pi1, next1;
            {
                vlib_buffer_t *p2, *p3;
                p2 = vlib_get_buffer(vm, from[2]);
                p3 = vlib_get_buffer(vm, from[3]);
                do {
                    void *_addr = (p2);
                    do {
                        if ((0 > 0) && !((64) <= 4 * (1 << 6))) {
                            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_node.h",
                                        (uword) 280, ((char *) __FUNCTION__), "(64) <= 4*CLIB_CACHE_LINE_BYTES");
                        }
                    } while (0);
                    if ((64) > (0) * (1 << 6))
                        __builtin_prefetch(_addr + (0) * (1 << 6), 0, 3);
                    ;
                    if ((64) > (1) * (1 << 6))
                        __builtin_prefetch(_addr + (1) * (1 << 6), 0, 3);
                    ;
                    if ((64) > (2) * (1 << 6))
                        __builtin_prefetch(_addr + (2) * (1 << 6), 0, 3);
                    ;
                    if ((64) > (3) * (1 << 6))
                        __builtin_prefetch(_addr + (3) * (1 << 6), 0, 3);
                    ;
                } while (0);
                do {
                    void *_addr = (p3);
                    do {
                        if ((0 > 0) && !((64) <= 4 * (1 << 6))) {
                            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_node.h",
                                        (uword) 281, ((char *) __FUNCTION__), "(64) <= 4*CLIB_CACHE_LINE_BYTES");
                        }
                    } while (0);
                    if ((64) > (0) * (1 << 6))
                        __builtin_prefetch(_addr + (0) * (1 << 6), 0, 3);
                    ;
                    if ((64) > (1) * (1 << 6))
                        __builtin_prefetch(_addr + (1) * (1 << 6), 0, 3);
                    ;
                    if ((64) > (2) * (1 << 6))
                        __builtin_prefetch(_addr + (2) * (1 << 6), 0, 3);
                    ;
                    if ((64) > (3) * (1 << 6))
                        __builtin_prefetch(_addr + (3) * (1 << 6), 0, 3);
                    ;
                } while (0);
                do {
                    void *_addr = (p2->data);
                    do {
                        if ((0 > 0) && !((64) <= 4 * (1 << 6))) {
                            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_node.h",
                                        (uword) 283, ((char *) __FUNCTION__), "(64) <= 4*CLIB_CACHE_LINE_BYTES");
                        }
                    } while (0);
                    if ((64) > (0) * (1 << 6))
                        __builtin_prefetch(_addr + (0) * (1 << 6), 0, 3);
                    ;
                    if ((64) > (1) * (1 << 6))
                        __builtin_prefetch(_addr + (1) * (1 << 6), 0, 3);
                    ;
                    if ((64) > (2) * (1 << 6))
                        __builtin_prefetch(_addr + (2) * (1 << 6), 0, 3);
                    ;
                    if ((64) > (3) * (1 << 6))
                        __builtin_prefetch(_addr + (3) * (1 << 6), 0, 3);
                    ;
                } while (0);
                do {
                    void *_addr = (p3->data);
                    do {
                        if ((0 > 0) && !((64) <= 4 * (1 << 6))) {
                            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                        "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_node.h",
                                        (uword) 284, ((char *) __FUNCTION__), "(64) <= 4*CLIB_CACHE_LINE_BYTES");
                        }
                    } while (0);
                    if ((64) > (0) * (1 << 6))
                        __builtin_prefetch(_addr + (0) * (1 << 6), 0, 3);
                    ;
                    if ((64) > (1) * (1 << 6))
                        __builtin_prefetch(_addr + (1) * (1 << 6), 0, 3);
                    ;
                    if ((64) > (2) * (1 << 6))
                        __builtin_prefetch(_addr + (2) * (1 << 6), 0, 3);
                    ;
                    if ((64) > (3) * (1 << 6))
                        __builtin_prefetch(_addr + (3) * (1 << 6), 0, 3);
                    ;
                } while (0);
            }
            pi0 = to_next[0] = from[0];
            pi1 = to_next[1] = from[1];
            from += 2;
            to_next += 2;
            n_left_from -= 2;
            n_left_to_next -= 2;
            p0 = vlib_get_buffer(vm, pi0);
            p1 = vlib_get_buffer(vm, pi1);
            two_buffers(vm, opaque1, opaque2, p0, p1, &next0, &next1);
            do {
                int enqueue_code = (next0 != next_index) + 2 * (next1 != next_index);
                if (__builtin_expect((enqueue_code != 0), 0)) {
                    switch (enqueue_code) {
                    case 1:
                        to_next[-2] = pi1;
                        to_next -= 1;
                        n_left_to_next += 1;
                        vlib_set_next_frame_buffer(vm, node, next0, pi0);
                        break;
                    case 2:
                        to_next -= 1;
                        n_left_to_next += 1;
                        vlib_set_next_frame_buffer(vm, node, next1, pi1);
                        break;
                    case 3:
                        to_next -= 2;
                        n_left_to_next += 2;
                        vlib_set_next_frame_buffer(vm, node, next0, pi0);
                        vlib_set_next_frame_buffer(vm, node, next1, pi1);
                        if (next0 == next1) {
                            vlib_put_next_frame(vm, node, next_index, n_left_to_next);
                            next_index = next1;
                            do {
                                vlib_frame_t *_f = vlib_get_next_frame_internal((vm), (node), (next_index), (0));
                                u32 _n           = _f->n_vectors;
                                (to_next)        = vlib_frame_vector_args(_f) + _n * sizeof((to_next)[0]);
                                (n_left_to_next) = 256 - _n;
                            } while (0);
                        }
                    }
                }
            } while (0);
        }
        while (n_left_from > 0 && n_left_to_next > 0) {
            vlib_buffer_t *p0;
            u32 pi0, next0;
            pi0        = from[0];
            to_next[0] = pi0;
            from += 1;
            to_next += 1;
            n_left_from -= 1;
            n_left_to_next -= 1;
            p0 = vlib_get_buffer(vm, pi0);
            one_buffer(vm, opaque1, opaque2, p0, &next0);
            do {
                if (__builtin_expect((next0 != next_index), 0)) {
                    vlib_put_next_frame(vm, node, next_index, n_left_to_next + 1);
                    next_index = next0;
                    do {
                        vlib_frame_t *_f = vlib_get_next_frame_internal((vm), (node), (next_index), (0));
                        u32 _n           = _f->n_vectors;
                        (to_next)        = vlib_frame_vector_args(_f) + _n * sizeof((to_next)[0]);
                        (n_left_to_next) = 256 - _n;
                    } while (0);
                    to_next[0] = pi0;
                    to_next += 1;
                    n_left_to_next -= 1;
                }
            } while (0);
        }
        vlib_put_next_frame(vm, node, next_index, n_left_to_next);
    }
    return frame->n_vectors;
}
static inline __attribute__((__always_inline__)) void
vlib_buffer_enqueue_to_next(vlib_main_t *vm, vlib_node_runtime_t *node, u32 *buffers, u16 *nexts, uword count)
{
    u32 *to_next, n_left_to_next, max;
    u16 next_index;
    next_index = nexts[0];
    do {
        vlib_frame_t *_f = vlib_get_next_frame_internal((vm), (node), (next_index), (0));
        u32 _n           = _f->n_vectors;
        (to_next)        = vlib_frame_vector_args(_f) + _n * sizeof((to_next)[0]);
        (n_left_to_next) = 256 - _n;
    } while (0);
    max = ({
        __typeof__(n_left_to_next) _x = (n_left_to_next);
        __typeof__(count) _y          = (count);
        _x < _y ? _x : _y;
    });
    while (count) {
        u32 n_enqueued;
        if ((nexts[0] != next_index) || n_left_to_next == 0) {
            vlib_put_next_frame(vm, node, next_index, n_left_to_next);
            next_index = nexts[0];
            do {
                vlib_frame_t *_f = vlib_get_next_frame_internal((vm), (node), (next_index), (0));
                u32 _n           = _f->n_vectors;
                (to_next)        = vlib_frame_vector_args(_f) + _n * sizeof((to_next)[0]);
                (n_left_to_next) = 256 - _n;
            } while (0);
            max = ({
                __typeof__(n_left_to_next) _x = (n_left_to_next);
                __typeof__(count) _y          = (count);
                _x < _y ? _x : _y;
            });
        }
        u16 x = 0;
        if (count + 3 < max) {
            x |= next_index ^ nexts[1];
            x |= next_index ^ nexts[2];
            x |= next_index ^ nexts[3];
            n_enqueued = (x == 0) ? 4 : 1;
        } else
            n_enqueued = 1;
        if (__builtin_expect((n_enqueued > max), 0))
            n_enqueued = max;
        if (n_enqueued >= 4) {
            memcpy(to_next, buffers, 4 * sizeof(u32));
            nexts += 4;
            to_next += 4;
            buffers += 4;
            n_left_to_next -= 4;
            count -= 4;
            max -= 4;
            continue;
        }
        to_next[0] = buffers[0];
        nexts += 1;
        to_next += 1;
        buffers += 1;
        n_left_to_next -= 1;
        count -= 1;
        max -= 1;
    }
    vlib_put_next_frame(vm, node, next_index, n_left_to_next);
}
static inline __attribute__((__always_inline__)) u32
vlib_buffer_enqueue_to_thread(vlib_main_t *vm, u32 frame_queue_index, u32 *buffer_indices, u16 *thread_indices,
                              u32 n_packets, int drop_on_congestion)
{
    vlib_thread_main_t *tm = vlib_get_thread_main();
    vlib_frame_queue_main_t *fqm;
    vlib_frame_queue_per_thread_data_t *ptd;
    u32 n_left = n_packets;
    u32 drop_list[256], *dbi = drop_list, n_drop = 0;
    vlib_frame_queue_elt_t *hf = 0;
    u32 n_left_to_next_thread = 0, *to_next_thread = 0;
    u32 next_thread_index, current_thread_index    = ~0;
    int i;
    fqm = ({
        do {
            if ((0 > 0) && !((frame_queue_index) <
                             ((tm->frame_queue_mains) ? (((vec_header_t *) (tm->frame_queue_mains) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_node.h", (uword) 466,
                            ((char *) __FUNCTION__), "(frame_queue_index) < vec_len (tm->frame_queue_mains)");
            }
        } while (0);
        (tm->frame_queue_mains) + (frame_queue_index);
    });
    ptd = ({
        do {
            if ((0 > 0) && !((vm->thread_index) <
                             ((fqm->per_thread_data) ? (((vec_header_t *) (fqm->per_thread_data) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vlib/buffer_node.h", (uword) 467,
                            ((char *) __FUNCTION__), "(vm->thread_index) < vec_len (fqm->per_thread_data)");
            }
        } while (0);
        (fqm->per_thread_data) + (vm->thread_index);
    });
    while (n_left) {
        next_thread_index = thread_indices[0];
        if (next_thread_index != current_thread_index) {
            if (drop_on_congestion &&
                is_vlib_frame_queue_congested(frame_queue_index, next_thread_index, fqm->queue_hi_thresh,
                                              ptd->congested_handoff_queue_by_thread_index)) {
                dbi[0] = buffer_indices[0];
                dbi++;
                n_drop++;
                goto next;
            }
            if (hf)
                hf->n_vectors = 256 - n_left_to_next_thread;
            hf                    = vlib_get_worker_handoff_queue_elt(frame_queue_index, next_thread_index,
                                                   ptd->handoff_queue_elt_by_thread_index);
            n_left_to_next_thread = 256 - hf->n_vectors;
            to_next_thread        = &hf->buffer_index[hf->n_vectors];
            current_thread_index  = next_thread_index;
        }
        to_next_thread[0] = buffer_indices[0];
        to_next_thread++;
        n_left_to_next_thread--;
        if (n_left_to_next_thread == 0) {
            hf->n_vectors = 256;
            vlib_put_frame_queue_elt(hf);
            current_thread_index                                      = ~0;
            ptd->handoff_queue_elt_by_thread_index[next_thread_index] = 0;
            hf                                                        = 0;
        }
    next:
        thread_indices += 1;
        buffer_indices += 1;
        n_left -= 1;
    }
    if (hf)
        hf->n_vectors = 256 - n_left_to_next_thread;
    for (i = 0; i < ((ptd->handoff_queue_elt_by_thread_index) ?
                         (((vec_header_t *) (ptd->handoff_queue_elt_by_thread_index) - 1)->len) :
                         0);
         i++) {
        if (ptd->handoff_queue_elt_by_thread_index[i]) {
            hf = ptd->handoff_queue_elt_by_thread_index[i];
            if (1 || hf->n_vectors == hf->last_n_vectors) {
                vlib_put_frame_queue_elt(hf);
                ptd->handoff_queue_elt_by_thread_index[i] = 0;
            } else
                hf->last_n_vectors = hf->n_vectors;
        }
        ptd->congested_handoff_queue_by_thread_index[i] = (vlib_frame_queue_t *) (~0);
    }
    if (drop_on_congestion && n_drop)
        vlib_buffer_free(vm, drop_list, n_drop);
    return n_packets - n_drop;
}
typedef enum {
    PCAP_PACKET_TYPE_null     = (0),
    PCAP_PACKET_TYPE_ethernet = (1),
    PCAP_PACKET_TYPE_ppp      = (9),
    PCAP_PACKET_TYPE_ip       = (12),
    PCAP_PACKET_TYPE_hdlc     = (104),
} pcap_packet_type_t;
typedef struct {
    u32 magic;
    u16 major_version;
    u16 minor_version;
    u32 time_zone;
    u32 sigfigs;
    u32 max_packet_size_in_bytes;
    u32 packet_type;
} pcap_file_header_t;
typedef struct {
    u32 time_in_sec;
    u32 time_in_usec;
    u32 n_packet_bytes_stored_in_file;
    u32 n_bytes_in_packet;
    u8 data[0];
} pcap_packet_header_t;
typedef struct {
    clib_spinlock_t lock;
    char *file_name;
    u32 n_packets_to_capture;
    pcap_packet_type_t packet_type;
    u32 n_packets_captured;
    u32 flags;
    int file_descriptor;
    u32 n_pcap_data_written;
    u8 *pcap_data;
    u8 **packets_read;
    u64 *timestamps;
    u32 min_packet_bytes, max_packet_bytes;
} pcap_main_t;
clib_error_t *pcap_write(pcap_main_t *pm);
clib_error_t *pcap_read(pcap_main_t *pm);
static inline void *
pcap_add_packet(pcap_main_t *pm, f64 time_now, u32 n_bytes_in_trace, u32 n_bytes_in_packet)
{
    pcap_packet_header_t *h;
    u8 *d;
    do {
        word _vec_n = (sizeof(h[0]) + n_bytes_in_trace);
        word _vec_l = ((pm->pcap_data) ? (((vec_header_t *) (pm->pcap_data) - 1)->len) : 0);
        pm->pcap_data =
            _vec_resize_inline((pm->pcap_data), _vec_n, (_vec_l + _vec_n) * sizeof((pm->pcap_data)[0]), (0), ({
                                   __typeof__((__alignof__(((pm->pcap_data))[0]))) _x =
                                       ((__alignof__(((pm->pcap_data))[0])));
                                   __typeof__(((0))) _y = (((0)));
                                   _x > _y ? _x : _y;
                               }));
        d = (pm->pcap_data) + _vec_l;
    } while (0);
    h                                = (void *) (d);
    h->time_in_sec                   = time_now;
    h->time_in_usec                  = 1e6 * (time_now - h->time_in_sec);
    h->n_packet_bytes_stored_in_file = n_bytes_in_trace;
    h->n_bytes_in_packet             = n_bytes_in_packet;
    pm->n_packets_captured++;
    return h->data;
}
static inline void
pcap_add_buffer(pcap_main_t *pm, vlib_main_t *vm, u32 buffer_index, u32 n_bytes_in_trace)
{
    vlib_buffer_t *b = vlib_get_buffer(vm, buffer_index);
    u32 n            = vlib_buffer_length_in_chain(vm, b);
    i32 n_left       = ({
        __typeof__(n_bytes_in_trace) _x = (n_bytes_in_trace);
        __typeof__(n) _y                = (n);
        _x < _y ? _x : _y;
    });
    f64 time_now     = vlib_time_now(vm);
    void *d;
    if (__builtin_expect((pm->n_packets_captured < pm->n_packets_to_capture), 1)) {
        clib_spinlock_lock_if_init(&pm->lock);
        d = pcap_add_packet(pm, time_now, n_left, n);
        while (1) {
            u32 copy_length = ({
                __typeof__((u32) n_left) _x      = ((u32) n_left);
                __typeof__(b->current_length) _y = (b->current_length);
                _x < _y ? _x : _y;
            });
            memcpy(d, b->data + b->current_data, copy_length);
            n_left -= b->current_length;
            if (n_left <= 0)
                break;
            d += b->current_length;
            do {
                if ((0 > 0) && !(b->flags & VLIB_BUFFER_NEXT_PRESENT)) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vnet/unix/pcap.h",
                                (uword) 229, ((char *) __FUNCTION__), "b->flags & VLIB_BUFFER_NEXT_PRESENT");
                }
            } while (0);
            b = vlib_get_buffer(vm, b->next_buffer);
        }
        clib_spinlock_unlock_if_init(&pm->lock);
    }
}
enum {
    VNET_BUFFER_F_L4_CHECKSUM_COMPUTED = (1 << (32 - (1))),
    VNET_BUFFER_F_L4_CHECKSUM_CORRECT  = (1 << (32 - (2))),
    VNET_BUFFER_F_VLAN_2_DEEP          = (1 << (32 - (3))),
    VNET_BUFFER_F_VLAN_1_DEEP          = (1 << (32 - (4))),
    VNET_BUFFER_F_SPAN_CLONE           = (1 << (32 - (5))),
    VNET_BUFFER_F_LOOP_COUNTER_VALID   = (1 << (32 - (6))),
    VNET_BUFFER_F_LOCALLY_ORIGINATED   = (1 << (32 - (7))),
    VNET_BUFFER_F_IS_IP4               = (1 << (32 - (8))),
    VNET_BUFFER_F_IS_IP6               = (1 << (32 - (9))),
    VNET_BUFFER_F_OFFLOAD_IP_CKSUM     = (1 << (32 - (10))),
    VNET_BUFFER_F_OFFLOAD_TCP_CKSUM    = (1 << (32 - (11))),
    VNET_BUFFER_F_OFFLOAD_UDP_CKSUM    = (1 << (32 - (12))),
    VNET_BUFFER_F_IS_NATED             = (1 << (32 - (13))),
    VNET_BUFFER_F_L2_HDR_OFFSET_VALID  = (1 << (32 - (14))),
    VNET_BUFFER_F_L3_HDR_OFFSET_VALID  = (1 << (32 - (15))),
    VNET_BUFFER_F_L4_HDR_OFFSET_VALID  = (1 << (32 - (16))),
    VNET_BUFFER_F_FLOW_REPORT          = (1 << (32 - (17))),
    VNET_BUFFER_F_IS_DVR               = (1 << (32 - (18))),
    VNET_BUFFER_F_QOS_DATA_VALID       = (1 << (32 - (19))),
};
enum {
    VNET_BUFFER_F_LOG2_L4_CHECKSUM_COMPUTED = (32 - (1)),
    VNET_BUFFER_F_LOG2_L4_CHECKSUM_CORRECT  = (32 - (2)),
    VNET_BUFFER_F_LOG2_VLAN_2_DEEP          = (32 - (3)),
    VNET_BUFFER_F_LOG2_VLAN_1_DEEP          = (32 - (4)),
    VNET_BUFFER_F_LOG2_SPAN_CLONE           = (32 - (5)),
    VNET_BUFFER_F_LOG2_LOOP_COUNTER_VALID   = (32 - (6)),
    VNET_BUFFER_F_LOG2_LOCALLY_ORIGINATED   = (32 - (7)),
    VNET_BUFFER_F_LOG2_IS_IP4               = (32 - (8)),
    VNET_BUFFER_F_LOG2_IS_IP6               = (32 - (9)),
    VNET_BUFFER_F_LOG2_OFFLOAD_IP_CKSUM     = (32 - (10)),
    VNET_BUFFER_F_LOG2_OFFLOAD_TCP_CKSUM    = (32 - (11)),
    VNET_BUFFER_F_LOG2_OFFLOAD_UDP_CKSUM    = (32 - (12)),
    VNET_BUFFER_F_LOG2_IS_NATED             = (32 - (13)),
    VNET_BUFFER_F_LOG2_L2_HDR_OFFSET_VALID  = (32 - (14)),
    VNET_BUFFER_F_LOG2_L3_HDR_OFFSET_VALID  = (32 - (15)),
    VNET_BUFFER_F_LOG2_L4_HDR_OFFSET_VALID  = (32 - (16)),
    VNET_BUFFER_F_LOG2_FLOW_REPORT          = (32 - (17)),
    VNET_BUFFER_F_LOG2_IS_DVR               = (32 - (18)),
    VNET_BUFFER_F_LOG2_QOS_DATA_VALID       = (32 - (19)),
};
typedef struct {
    u32 sw_if_index[VLIB_N_RX_TX];
    i16 l2_hdr_offset;
    i16 l3_hdr_offset;
    i16 l4_hdr_offset;
    u8 feature_arc_index;
    u8 dont_waste_me;
    union {
        struct {
            u32 adj_index[VLIB_N_RX_TX];
            union {
                struct {
                    u32 flow_hash;
                    union {
                        u32 save_protocol;
                        u32 fib_index;
                    };
                    u32 save_rewrite_length;
                    u32 rpf_id;
                };
                struct {
                    u8 type;
                    u8 code;
                    u32 data;
                } icmp;
                union {
                    struct {
                        u32 next_index;
                        u16 estimated_mtu;
                    };
                    struct {
                        u16 fragment_first;
                        u16 fragment_last;
                        u16 range_first;
                        u16 range_last;
                        u32 next_range_bi;
                        u16 ip6_frag_hdr_offset;
                    };
                } reass;
            };
        } ip;
        struct {
            u32 pad[VLIB_N_RX_TX + 1];
            u8 ttl;
            u8 exp;
            u8 first;
            u32 save_rewrite_length;
            struct {
                u8 n_bytes;
            } bier;
        } mpls;
        struct opaque_l2 {
            u32 feature_bitmap;
            u16 bd_index;
            u8 l2_len;
            u8 shg;
            u16 l2fib_sn;
            u8 bd_age;
        } l2;
        struct {
            u32 pad[4];
            u8 next_index;
            u32 session_index;
        } l2t;
        struct {
            struct opaque_l2 pad;
            union {
                u32 table_index;
                u32 opaque_index;
            };
            u64 hash;
        } l2_classify;
        struct {
            u32 pad[8 - VLIB_N_RX_TX - 1];
            u32 index;
        } policer;
        struct {
            u32 flags;
            u32 sad_index;
        } ipsec;
        struct {
            u16 mtu;
        } map;
        struct {
            u32 map_domain_index;
            struct {
                u32 saddr, daddr;
                u16 frag_offset;
                u16 l4_offset;
                u8 l4_protocol;
            } v6;
            u16 checksum_offset;
            u16 mtu;
        } map_t;
        struct {
            u32 pad[2];
            u16 mtu;
            u8 next_index;
            u8 flags;
        } ip_frag;
        struct {
            u32 current_config_index;
        } cop;
        struct {
            u16 overlay_afi;
        } lisp;
        struct {
            u32 connection_index;
            u32 seq_number;
            u32 seq_end;
            u32 ack_number;
            u16 hdr_offset;
            u16 data_offset;
            u16 data_len;
            u8 flags;
        } tcp;
        struct {
            u32 connection_index;
            u16 sid;
            u16 ssn;
            u32 tsn;
            u16 hdr_offset;
            u16 data_offset;
            u16 data_len;
            u8 subconn_idx;
            u8 flags;
        } sctp;
        struct {
            u32 flags;
        } snat;
        u32 unused[6];
    };
} vnet_buffer_opaque_t;
_Static_assert(sizeof(vnet_buffer_opaque_t) <= (sizeof((((vlib_buffer_t *) 0)->opaque))),
               "VNET buffer meta-data too large for vlib_buffer");
typedef struct {
    struct {
        u8 bits;
        u8 source;
    } qos;
    u8 loop_counter;
    u8 __unused[1];
    struct {
        u8 __unused;
        u8 flags;
        u16 src_epg;
    } gbp;
    union {
        struct {
        };
        struct {
            u64 pad[1];
            u64 pg_replay_timestamp;
        };
        u32 unused[10];
    };
} vnet_buffer_opaque2_t;
_Static_assert(sizeof(vnet_buffer_opaque2_t) <= (sizeof((((vlib_buffer_t *) 0)->opaque2))),
               "VNET buffer opaque2 meta-data too large for vlib_buffer");
format_function_t format_vnet_buffer;
typedef struct {
    u32 feature_index;
    u32 node_index;
    u32 next_index;
    u32 *feature_config;
} vnet_config_feature_t;
static inline __attribute__((__always_inline__)) void
vnet_config_feature_free(vnet_config_feature_t *f)
{
    do {
        if (f->feature_config) {
            clib_mem_free(vec_header((f->feature_config), (0)));
            f->feature_config = 0;
        }
    } while (0);
}
typedef struct {
    vnet_config_feature_t *features;
    u32 *config_string_vector;
    u32 config_string_heap_index, config_string_heap_handle;
    u32 index;
    u32 reference_count;
} vnet_config_t;
typedef struct {
    vnet_config_t *config_pool;
    uword *config_string_hash;
    u32 *config_string_heap;
    u32 *start_node_indices, end_node_index;
    u32 *node_index_by_feature_index;
    u32 *config_pool_index_by_user_index;
    u32 *config_string_temp;
} vnet_config_main_t;
static inline __attribute__((__always_inline__)) void
vnet_config_free(vnet_config_main_t *cm, vnet_config_t *c)
{
    vnet_config_feature_t *f;
    for (f = (c->features); f < ((c->features) + ((c->features) ? (((vec_header_t *) (c->features) - 1)->len) : 0)); f++)
        vnet_config_feature_free(f);
    do {
        if (c->features) {
            clib_mem_free(vec_header((c->features), (0)));
            c->features = 0;
        }
    } while (0);
    heap_dealloc(cm->config_string_heap, c->config_string_heap_handle);
    do {
        if (c->config_string_vector) {
            clib_mem_free(vec_header((c->config_string_vector), (0)));
            c->config_string_vector = 0;
        }
    } while (0);
}
static inline __attribute__((__always_inline__)) void *
vnet_get_config_data(vnet_config_main_t *cm, u32 *config_index, u32 *next_index, u32 n_data_bytes)
{
    u32 i, n, *d;
    i             = *config_index;
    d             = ({
        do {
            if ((0 > 0) &&
                !((i) < ((cm->config_string_heap) ? (((vec_header_t *) (cm->config_string_heap) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/config.h", (uword) 129,
                            ((char *) __FUNCTION__), "(i) < vec_len (cm->config_string_heap)");
            }
        } while (0);
        (cm->config_string_heap) + (i);
    });
    n             = round_pow2(n_data_bytes, sizeof(d[0])) / sizeof(d[0]);
    *next_index   = d[n];
    *config_index = (i + n + 1);
    return (void *) d;
}
void vnet_config_init(vlib_main_t *vm, vnet_config_main_t *cm, char *start_node_names[], int n_start_node_names,
                      char *feature_node_names[], int n_feature_node_names);
u32 vnet_config_add_feature(vlib_main_t *vm, vnet_config_main_t *cm, u32 config_id, u32 feature_index,
                            void *feature_config, u32 n_feature_config_bytes);
u32 vnet_config_del_feature(vlib_main_t *vm, vnet_config_main_t *cm, u32 config_id, u32 feature_index,
                            void *feature_config, u32 n_feature_config_bytes);
u8 *vnet_config_format_features(vlib_main_t *vm, vnet_config_main_t *cm, u32 config_index, u8 *s);
typedef enum {
    VNET_L3_PACKET_TYPE_LLC_LENGTH,
    VNET_L3_PACKET_TYPE_XNS_IDP,
    VNET_L3_PACKET_TYPE_IP4,
    VNET_L3_PACKET_TYPE_ARP,
    VNET_L3_PACKET_TYPE_VINES_IP,
    VNET_L3_PACKET_TYPE_VINES_LOOPBACK,
    VNET_L3_PACKET_TYPE_VINES_ECHO,
    VNET_L3_PACKET_TYPE_TRAIN,
    VNET_L3_PACKET_TYPE_CDP,
    VNET_L3_PACKET_TYPE_CGMP,
    VNET_L3_PACKET_TYPE_SRP_CONTROL,
    VNET_L3_PACKET_TYPE_CENTRINO_PROMISC,
    VNET_L3_PACKET_TYPE_DECNET,
    VNET_L3_PACKET_TYPE_DECNET_DUMP_LOAD,
    VNET_L3_PACKET_TYPE_DECNET_REMOTE_CONSOLE,
    VNET_L3_PACKET_TYPE_DECNET_ROUTE,
    VNET_L3_PACKET_TYPE_DEC_LAT,
    VNET_L3_PACKET_TYPE_DEC_DIAGNOSTIC,
    VNET_L3_PACKET_TYPE_DEC_CUSTOMER,
    VNET_L3_PACKET_TYPE_DEC_SCA,
    VNET_L3_PACKET_TYPE_TRANSPARENT_BRIDGING,
    VNET_L3_PACKET_TYPE_RAW_FRAME_RELAY,
    VNET_L3_PACKET_TYPE_REVERSE_ARP,
    VNET_L3_PACKET_TYPE_DEC_LAN_BRIDGE,
    VNET_L3_PACKET_TYPE_DEC_ETHERNET_ENCRYPTION,
    VNET_L3_PACKET_TYPE_DEC_LAN_TRAFFIC_MONITOR,
    VNET_L3_PACKET_TYPE_DEC_LAST,
    VNET_L3_PACKET_TYPE_APPLETALK,
    VNET_L3_PACKET_TYPE_IBM_SNA,
    VNET_L3_PACKET_TYPE_APPLETALK_AARP,
    VNET_L3_PACKET_TYPE_WELLFLEET_COMPRESSION,
    VNET_L3_PACKET_TYPE_VLAN,
    VNET_L3_PACKET_TYPE_IPX,
    VNET_L3_PACKET_TYPE_SNMP,
    VNET_L3_PACKET_TYPE_CABLETRON_ISMP,
    VNET_L3_PACKET_TYPE_CABLETRON_ISMP_TBFLOOD,
    VNET_L3_PACKET_TYPE_IP6,
    VNET_L3_PACKET_TYPE_ATOMIC,
    VNET_L3_PACKET_TYPE_TCP_IP_COMPRESSION,
    VNET_L3_PACKET_TYPE_IP_AUTONOMOUS_SYSTEMS,
    VNET_L3_PACKET_TYPE_SECURE_DATA,
    VNET_L3_PACKET_TYPE_MAC_CONTROL,
    VNET_L3_PACKET_TYPE_SLOW_PROTOCOLS,
    VNET_L3_PACKET_TYPE_PPP,
    VNET_L3_PACKET_TYPE_MPLS,
    VNET_L3_PACKET_TYPE_MPLS_UPSTREAM_ASSIGNED,
    VNET_L3_PACKET_TYPE_PPPOE_DISCOVERY,
    VNET_L3_PACKET_TYPE_PPPOE_SESSION,
    VNET_L3_PACKET_TYPE_INTEL_ANS,
    VNET_L3_PACKET_TYPE_MICROSOFT_NLB_HEARTBEAT,
    VNET_L3_PACKET_TYPE_CDMA_2000,
    VNET_L3_PACKET_TYPE_802_1X_AUTHENTICATION,
    VNET_L3_PACKET_TYPE_PROFINET,
    VNET_L3_PACKET_TYPE_HYPERSCSI,
    VNET_L3_PACKET_TYPE_AOE,
    VNET_L3_PACKET_TYPE_DOT1AD,
    VNET_L3_PACKET_TYPE_BRDWALK,
    VNET_L3_PACKET_TYPE_802_OUI_EXTENDED,
    VNET_L3_PACKET_TYPE_802_11I_PRE_AUTHENTICATION,
    VNET_L3_PACKET_TYPE_802_1_LLDP,
    VNET_L3_PACKET_TYPE_DOT1AH,
    VNET_L3_PACKET_TYPE_NSH,
    VNET_L3_PACKET_TYPE_LOOPBACK,
    VNET_L3_PACKET_TYPE_RTNET_MAC,
    VNET_L3_PACKET_TYPE_RTNET_CONFIG,
    VNET_L3_PACKET_TYPE_VLAN_9100,
    VNET_L3_PACKET_TYPE_VLAN_9200,
    VNET_L3_PACKET_TYPE_PGLAN,
    VNET_L3_PACKET_TYPE_SRP_ISIS,
    VNET_L3_PACKET_TYPE_RESERVED,
} vnet_l3_packet_type_t;
struct vnet_main_t;
struct vnet_hw_interface_t;
struct vnet_sw_interface_t;
struct ip46_address_t;
typedef enum {
    VNET_HW_INTERFACE_RX_MODE_UNKNOWN,
    VNET_HW_INTERFACE_RX_MODE_POLLING,
    VNET_HW_INTERFACE_RX_MODE_INTERRUPT,
    VNET_HW_INTERFACE_RX_MODE_ADAPTIVE,
    VNET_HW_INTERFACE_RX_MODE_DEFAULT,
    VNET_HW_INTERFACE_NUM_RX_MODES,
} vnet_hw_interface_rx_mode;
typedef clib_error_t *(vnet_interface_function_t)(struct vnet_main_t *vnm, u32 if_index, u32 flags);
typedef clib_error_t *(vnet_subif_add_del_function_t)(struct vnet_main_t *vnm, u32 if_index,
                                                      struct vnet_sw_interface_t *template, int is_add);
typedef clib_error_t *(vnet_interface_set_mac_address_function_t)(struct vnet_hw_interface_t *hi, const u8 *old_address,
                                                                  const u8 *new_address);
typedef clib_error_t *(vnet_interface_set_rx_mode_function_t)(struct vnet_main_t *vnm, u32 if_index, u32 queue_id,
                                                              vnet_hw_interface_rx_mode mode);
typedef clib_error_t *(vnet_interface_set_l2_mode_function_t)(struct vnet_main_t *vnm, struct vnet_hw_interface_t *hi,
                                                              i32 l2_if_adjust);
typedef enum {
    VNET_FLOW_DEV_OP_ADD_FLOW,
    VNET_FLOW_DEV_OP_DEL_FLOW,
    VNET_FLOW_DEV_OP_GET_COUNTER,
    VNET_FLOW_DEV_OP_RESET_COUNTER,
} vnet_flow_dev_op_t;
typedef int(vnet_flow_dev_ops_function_t)(struct vnet_main_t *vnm, vnet_flow_dev_op_t op, u32 hw_if_index, u32 index,
                                          uword *private_data);
typedef enum vnet_interface_function_priority_t_ {
    VNET_ITF_FUNC_PRIORITY_LOW,
    VNET_ITF_FUNC_PRIORITY_HIGH,
} vnet_interface_function_priority_t;
typedef struct _vnet_interface_function_list_elt {
    struct _vnet_interface_function_list_elt *next_interface_function;
    clib_error_t *(*fp)(struct vnet_main_t *vnm, u32 if_index, u32 flags);
} _vnet_interface_function_list_elt_t;
typedef struct _vnet_device_class {
    u32 index;
    char *name;
    vnet_interface_function_t *interface_add_del_function;
    vnet_interface_function_t *admin_up_down_function;
    vnet_subif_add_del_function_t *subif_add_del_function;
    vnet_interface_set_rx_mode_function_t *rx_mode_change_function;
    vnet_interface_set_l2_mode_function_t *set_l2_mode_function;
    u32 redistribute;
    vlib_node_function_t *tx_function;
    vlib_node_fn_registration_t *tx_fn_registrations;
    char **tx_function_error_strings;
    u32 tx_function_n_errors;
    int (*name_renumber)(struct vnet_hw_interface_t *hi, u32 new_dev_instance);
    vnet_flow_dev_ops_function_t *flow_ops_function;
    format_function_t *format_device_name;
    unformat_function_t *unformat_device_name;
    format_function_t *format_device;
    format_function_t *format_tx_trace;
    format_function_t *format_flow;
    void (*clear_counters)(u32 dev_class_instance);
    uword (*is_valid_class_for_interface)(struct vnet_main_t *vnm, u32 hw_if_index, u32 hw_class_index);
    void (*hw_class_change)(struct vnet_main_t *vnm, u32 hw_if_index, u32 new_hw_class_index);
    void (*rx_redirect_to_node)(struct vnet_main_t *vnm, u32 hw_if_index, u32 node_index);
    struct _vnet_device_class *next_class_registration;
    vnet_interface_set_mac_address_function_t *mac_addr_change_function;
} vnet_device_class_t;
typedef enum vnet_link_t_ {
    VNET_LINK_IP4 = 0,
    VNET_LINK_IP6,
    VNET_LINK_MPLS,
    VNET_LINK_ETHERNET,
    VNET_LINK_ARP,
    VNET_LINK_NSH,
} __attribute__((packed)) vnet_link_t;
extern vnet_l3_packet_type_t vnet_link_to_l3_proto(vnet_link_t link);
typedef enum vnet_hw_interface_class_flags_t_ {
    VNET_HW_INTERFACE_CLASS_FLAG_P2P = (1 << 0),
} vnet_hw_interface_class_flags_t;
typedef struct _vnet_hw_interface_class {
    u32 index;
    char *name;
    vnet_hw_interface_class_flags_t flags;
    vnet_interface_function_t *interface_add_del_function;
    vnet_interface_function_t *admin_up_down_function;
    vnet_interface_function_t *link_up_down_function;
    vnet_interface_set_mac_address_function_t *mac_addr_change_function;
    format_function_t *format_interface_name;
    format_function_t *format_address;
    format_function_t *format_header;
    format_function_t *format_device;
    unformat_function_t *unformat_hw_address;
    unformat_function_t *unformat_header;
    u8 *(*build_rewrite)(struct vnet_main_t *vnm, u32 sw_if_index, vnet_link_t link_type, const void *dst_hw_address);
    void (*update_adjacency)(struct vnet_main_t *vnm, u32 sw_if_index, u32 adj_index);
    uword (*is_valid_class_for_interface)(struct vnet_main_t *vnm, u32 hw_if_index, u32 hw_class_index);
    void (*hw_class_change)(struct vnet_main_t *vnm, u32 hw_if_index, u32 old_class_index, u32 new_class_index);
    struct _vnet_hw_interface_class *next_class_registration;
} vnet_hw_interface_class_t;
extern u8 *default_build_rewrite(struct vnet_main_t *vnm, u32 sw_if_index, vnet_link_t link_type,
                                 const void *dst_hw_address);
extern void default_update_adjacency(struct vnet_main_t *vnm, u32 sw_if_index, u32 adj_index);
typedef struct vnet_hw_interface_t {
    u8 *name;
    u32 flags;
    u8 *hw_address;
    u32 output_node_index, tx_node_index;
    u32 dev_class_index;
    u32 dev_instance;
    u32 hw_class_index;
    u32 hw_instance;
    u32 hw_if_index;
    u32 sw_if_index;
    u32 output_node_next_index;
    f64 max_rate_bits_per_sec;
    u32 min_supported_packet_bytes;
    u32 max_supported_packet_bytes;
    u32 min_packet_bytes;
    u32 max_packet_bytes;
    uword *sub_interface_sw_if_index_by_id;
    u32 l2_if_count;
    uword *bond_info;
    u32 input_node_index;
    u32 *input_node_thread_index_by_queue;
    u8 *rx_mode_by_queue;
    vnet_hw_interface_rx_mode default_rx_mode;
    uword *dq_runtime_index_by_queue;
} vnet_hw_interface_t;
extern vnet_device_class_t vnet_local_interface_device_class;
typedef enum {
    VNET_SW_INTERFACE_TYPE_HARDWARE,
    VNET_SW_INTERFACE_TYPE_SUB,
    VNET_SW_INTERFACE_TYPE_P2P,
    VNET_SW_INTERFACE_TYPE_PIPE,
} vnet_sw_interface_type_t;
typedef struct {
    u32 id;
    struct {
        u16 outer_vlan_id;
        u16 inner_vlan_id;
        union {
            u16 raw_flags;
            struct {
                u16 no_tags : 1;
                u16 one_tag : 1;
                u16 two_tags : 1;
                u16 dot1ad : 1;
                u16 exact_match : 1;
                u16 default_sub : 1;
                u16 outer_vlan_id_any : 1;
                u16 inner_vlan_id_any : 1;
            } flags;
        };
    } eth;
} vnet_sub_interface_t;
typedef struct {
    u32 id;
    u32 pool_index;
    u8 client_mac[6];
} vnet_p2p_sub_interface_t;
typedef enum {
    VNET_FLOOD_CLASS_BVI,
    VNET_FLOOD_CLASS_NORMAL,
    VNET_FLOOD_CLASS_TUNNEL_MASTER,
    VNET_FLOOD_CLASS_TUNNEL_NORMAL,
    VNET_FLOOD_CLASS_NO_FLOOD,
} vnet_flood_class_t;
typedef enum { VNET_MTU_L3, VNET_MTU_IP4, VNET_MTU_IP6, VNET_MTU_MPLS, VNET_N_MTU } vnet_mtu_t;
extern vnet_mtu_t vnet_link_to_mtu(vnet_link_t link);
typedef enum vnet_sw_interface_flags_t_ {
    VNET_SW_INTERFACE_FLAG_ADMIN_UP       = (1 << 0),
    VNET_SW_INTERFACE_FLAG_PUNT           = (1 << 1),
    VNET_SW_INTERFACE_FLAG_PROXY_ARP      = (1 << 2),
    VNET_SW_INTERFACE_FLAG_UNNUMBERED     = (1 << 3),
    VNET_SW_INTERFACE_FLAG_BOND_SLAVE     = (1 << 4),
    VNET_SW_INTERFACE_FLAG_HIDDEN         = (1 << 5),
    VNET_SW_INTERFACE_FLAG_ERROR          = (1 << 6),
    VNET_SW_INTERFACE_FLAG_DIRECTED_BCAST = (1 << 7),
} __attribute__((packed)) vnet_sw_interface_flags_t;
typedef struct {
    vnet_sw_interface_type_t type : 16;
    vnet_sw_interface_flags_t flags;
    u32 sw_if_index;
    u32 sup_sw_if_index;
    u32 unnumbered_sw_if_index;
    u32 link_speed;
    u32 hw_if_index;
    u32 mtu[VNET_N_MTU];
    vnet_sub_interface_t sub;
    vnet_p2p_sub_interface_t p2p;
    vnet_flood_class_t flood_class;
} vnet_sw_interface_t;
typedef enum {
    VNET_INTERFACE_COUNTER_DROP         = 0,
    VNET_INTERFACE_COUNTER_PUNT         = 1,
    VNET_INTERFACE_COUNTER_IP4          = 2,
    VNET_INTERFACE_COUNTER_IP6          = 3,
    VNET_INTERFACE_COUNTER_RX_NO_BUF    = 4,
    VNET_INTERFACE_COUNTER_RX_MISS      = 5,
    VNET_INTERFACE_COUNTER_RX_ERROR     = 6,
    VNET_INTERFACE_COUNTER_TX_ERROR     = 7,
    VNET_INTERFACE_COUNTER_MPLS         = 8,
    VNET_N_SIMPLE_INTERFACE_COUNTER     = 9,
    VNET_INTERFACE_COUNTER_RX           = 0,
    VNET_INTERFACE_COUNTER_RX_UNICAST   = 1,
    VNET_INTERFACE_COUNTER_RX_MULTICAST = 2,
    VNET_INTERFACE_COUNTER_RX_BROADCAST = 3,
    VNET_INTERFACE_COUNTER_TX           = 4,
    VNET_INTERFACE_COUNTER_TX_UNICAST   = 5,
    VNET_INTERFACE_COUNTER_TX_MULTICAST = 6,
    VNET_INTERFACE_COUNTER_TX_BROADCAST = 7,
    VNET_N_COMBINED_INTERFACE_COUNTER   = 8,
} vnet_interface_counter_type_t;
typedef enum {
    COLLECT_SIMPLE_STATS   = 0,
    COLLECT_DETAILED_STATS = 1,
} vnet_interface_stats_collection_mode_e;
extern int collect_detailed_interface_stats_flag;
static inline int
collect_detailed_interface_stats(void)
{
    return collect_detailed_interface_stats_flag;
}
void collect_detailed_interface_stats_flag_set(void);
void collect_detailed_interface_stats_flag_clear(void);
typedef struct {
    u32 output_node_index;
    u32 tx_node_index;
} vnet_hw_interface_nodes_t;
typedef struct {
    vnet_hw_interface_t *hw_interfaces;
    uword *hw_interface_by_name;
    vnet_hw_interface_class_t *hw_interface_classes;
    vnet_device_class_t *device_classes;
    uword *hw_interface_class_by_name;
    uword *device_class_by_name;
    vnet_sw_interface_t *sw_interfaces;
    uword *sw_if_index_by_sup_and_sub;
    volatile u32 *sw_if_counter_lock;
    vlib_simple_counter_main_t *sw_if_counters;
    vlib_combined_counter_main_t *combined_sw_if_counters;
    vnet_hw_interface_nodes_t *deleted_hw_interface_nodes;
    int drop_pcap_enable;
    pcap_main_t pcap_main;
    u8 *pcap_filename;
    u32 pcap_sw_if_index;
    u32 pcap_pkts_to_capture;
    uword *pcap_drop_filter_hash;
    u8 output_feature_arc_index;
} vnet_interface_main_t;
static inline void
vnet_interface_counter_lock(vnet_interface_main_t *im)
{
    if (im->sw_if_counter_lock)
        while (__sync_lock_test_and_set(im->sw_if_counter_lock, 1))
            ;
}
static inline void
vnet_interface_counter_unlock(vnet_interface_main_t *im)
{
    if (im->sw_if_counter_lock)
        *im->sw_if_counter_lock = 0;
}
void vnet_pcap_drop_trace_filter_add_del(u32 error_index, int is_add);
int vnet_interface_name_renumber(u32 sw_if_index, u32 new_show_dev_instance);
typedef enum {
    VNET_API_ERROR_UNSPECIFIED                        = (-1),
    VNET_API_ERROR_INVALID_SW_IF_INDEX                = (-2),
    VNET_API_ERROR_NO_SUCH_FIB                        = (-3),
    VNET_API_ERROR_NO_SUCH_INNER_FIB                  = (-4),
    VNET_API_ERROR_NO_SUCH_LABEL                      = (-5),
    VNET_API_ERROR_NO_SUCH_ENTRY                      = (-6),
    VNET_API_ERROR_INVALID_VALUE                      = (-7),
    VNET_API_ERROR_INVALID_VALUE_2                    = (-8),
    VNET_API_ERROR_UNIMPLEMENTED                      = (-9),
    VNET_API_ERROR_INVALID_SW_IF_INDEX_2              = (-10),
    VNET_API_ERROR_SYSCALL_ERROR_1                    = (-11),
    VNET_API_ERROR_SYSCALL_ERROR_2                    = (-12),
    VNET_API_ERROR_SYSCALL_ERROR_3                    = (-13),
    VNET_API_ERROR_SYSCALL_ERROR_4                    = (-14),
    VNET_API_ERROR_SYSCALL_ERROR_5                    = (-15),
    VNET_API_ERROR_SYSCALL_ERROR_6                    = (-16),
    VNET_API_ERROR_SYSCALL_ERROR_7                    = (-17),
    VNET_API_ERROR_SYSCALL_ERROR_8                    = (-18),
    VNET_API_ERROR_SYSCALL_ERROR_9                    = (-19),
    VNET_API_ERROR_SYSCALL_ERROR_10                   = (-20),
    VNET_API_ERROR_FEATURE_DISABLED                   = (-30),
    VNET_API_ERROR_INVALID_REGISTRATION               = (-31),
    VNET_API_ERROR_NEXT_HOP_NOT_IN_FIB                = (-50),
    VNET_API_ERROR_UNKNOWN_DESTINATION                = (-51),
    VNET_API_ERROR_PREFIX_MATCHES_NEXT_HOP            = (-52),
    VNET_API_ERROR_NEXT_HOP_NOT_FOUND_MP              = (-53),
    VNET_API_ERROR_NO_MATCHING_INTERFACE              = (-54),
    VNET_API_ERROR_INVALID_VLAN                       = (-55),
    VNET_API_ERROR_VLAN_ALREADY_EXISTS                = (-56),
    VNET_API_ERROR_INVALID_SRC_ADDRESS                = (-57),
    VNET_API_ERROR_INVALID_DST_ADDRESS                = (-58),
    VNET_API_ERROR_ADDRESS_LENGTH_MISMATCH            = (-59),
    VNET_API_ERROR_ADDRESS_NOT_FOUND_FOR_INTERFACE    = (-60),
    VNET_API_ERROR_ADDRESS_NOT_LINK_LOCAL             = (-61),
    VNET_API_ERROR_IP6_NOT_ENABLED                    = (-62),
    VNET_API_ERROR_IN_PROGRESS                        = (10),
    VNET_API_ERROR_NO_SUCH_NODE                       = (-63),
    VNET_API_ERROR_NO_SUCH_NODE2                      = (-64),
    VNET_API_ERROR_NO_SUCH_TABLE                      = (-65),
    VNET_API_ERROR_NO_SUCH_TABLE2                     = (-66),
    VNET_API_ERROR_NO_SUCH_TABLE3                     = (-67),
    VNET_API_ERROR_SUBIF_ALREADY_EXISTS               = (-68),
    VNET_API_ERROR_SUBIF_CREATE_FAILED                = (-69),
    VNET_API_ERROR_INVALID_MEMORY_SIZE                = (-70),
    VNET_API_ERROR_INVALID_INTERFACE                  = (-71),
    VNET_API_ERROR_INVALID_VLAN_TAG_COUNT             = (-72),
    VNET_API_ERROR_INVALID_ARGUMENT                   = (-73),
    VNET_API_ERROR_UNEXPECTED_INTF_STATE              = (-74),
    VNET_API_ERROR_TUNNEL_EXIST                       = (-75),
    VNET_API_ERROR_INVALID_DECAP_NEXT                 = (-76),
    VNET_API_ERROR_RESPONSE_NOT_READY                 = (-77),
    VNET_API_ERROR_NOT_CONNECTED                      = (-78),
    VNET_API_ERROR_IF_ALREADY_EXISTS                  = (-79),
    VNET_API_ERROR_BOND_SLAVE_NOT_ALLOWED             = (-80),
    VNET_API_ERROR_VALUE_EXIST                        = (-81),
    VNET_API_ERROR_SAME_SRC_DST                       = (-82),
    VNET_API_ERROR_IP6_MULTICAST_ADDRESS_NOT_PRESENT  = (-83),
    VNET_API_ERROR_SR_POLICY_NAME_NOT_PRESENT         = (-84),
    VNET_API_ERROR_NOT_RUNNING_AS_ROOT                = (-85),
    VNET_API_ERROR_ALREADY_CONNECTED                  = (-86),
    VNET_API_ERROR_UNSUPPORTED_JNI_VERSION            = (-87),
    VNET_API_ERROR_FAILED_TO_ATTACH_TO_JAVA_THREAD    = (-88),
    VNET_API_ERROR_INVALID_WORKER                     = (-89),
    VNET_API_ERROR_LISP_DISABLED                      = (-90),
    VNET_API_ERROR_CLASSIFY_TABLE_NOT_FOUND           = (-91),
    VNET_API_ERROR_INVALID_EID_TYPE                   = (-92),
    VNET_API_ERROR_CANNOT_CREATE_PCAP_FILE            = (-93),
    VNET_API_ERROR_INCORRECT_ADJACENCY_TYPE           = (-94),
    VNET_API_ERROR_EXCEEDED_NUMBER_OF_RANGES_CAPACITY = (-95),
    VNET_API_ERROR_EXCEEDED_NUMBER_OF_PORTS_CAPACITY  = (-96),
    VNET_API_ERROR_INVALID_ADDRESS_FAMILY             = (-97),
    VNET_API_ERROR_INVALID_SUB_SW_IF_INDEX            = (-98),
    VNET_API_ERROR_TABLE_TOO_BIG                      = (-99),
    VNET_API_ERROR_CANNOT_ENABLE_DISABLE_FEATURE      = (-100),
    VNET_API_ERROR_BFD_EEXIST                         = (-101),
    VNET_API_ERROR_BFD_ENOENT                         = (-102),
    VNET_API_ERROR_BFD_EINUSE                         = (-103),
    VNET_API_ERROR_BFD_NOTSUPP                        = (-104),
    VNET_API_ERROR_ADDRESS_IN_USE                     = (-105),
    VNET_API_ERROR_ADDRESS_NOT_IN_USE                 = (-106),
    VNET_API_ERROR_QUEUE_FULL                         = (-107),
    VNET_API_ERROR_APP_UNSUPPORTED_CFG                = (-108),
    VNET_API_ERROR_URI_FIFO_CREATE_FAILED             = (-109),
    VNET_API_ERROR_LISP_RLOC_LOCAL                    = (-110),
    VNET_API_ERROR_BFD_EAGAIN                         = (-111),
    VNET_API_ERROR_INVALID_GPE_MODE                   = (-112),
    VNET_API_ERROR_LISP_GPE_ENTRIES_PRESENT           = (-113),
    VNET_API_ERROR_ADDRESS_FOUND_FOR_INTERFACE        = (-114),
    VNET_API_ERROR_SESSION_CONNECT                    = (-115),
    VNET_API_ERROR_ENTRY_ALREADY_EXISTS               = (-116),
    VNET_API_ERROR_SVM_SEGMENT_CREATE_FAIL            = (-117),
    VNET_API_ERROR_APPLICATION_NOT_ATTACHED           = (-118),
    VNET_API_ERROR_BD_ALREADY_EXISTS                  = (-119),
    VNET_API_ERROR_BD_IN_USE                          = (-120),
    VNET_API_ERROR_BD_NOT_MODIFIABLE                  = (-121),
    VNET_API_ERROR_BD_ID_EXCEED_MAX                   = (-122),
    VNET_API_ERROR_SUBIF_DOESNT_EXIST                 = (-123),
    VNET_API_ERROR_L2_MACS_EVENT_CLINET_PRESENT       = (-124),
    VNET_API_ERROR_INVALID_QUEUE                      = (-125),
    VNET_API_ERROR_UNSUPPORTED                        = (-126),
    VNET_API_ERROR_DUPLICATE_IF_ADDRESS               = (-127),
    VNET_API_ERROR_APP_INVALID_NS                     = (-128),
    VNET_API_ERROR_APP_WRONG_NS_SECRET                = (-129),
    VNET_API_ERROR_APP_CONNECT_SCOPE                  = (-130),
    VNET_API_ERROR_APP_ALREADY_ATTACHED               = (-131),
    VNET_API_ERROR_SESSION_REDIRECT                   = (-132),
    VNET_API_ERROR_ILLEGAL_NAME                       = (-133),
    VNET_API_ERROR_NO_NAME_SERVERS                    = (-134),
    VNET_API_ERROR_NAME_SERVER_NOT_FOUND              = (-135),
    VNET_API_ERROR_NAME_RESOLUTION_NOT_ENABLED        = (-136),
    VNET_API_ERROR_NAME_SERVER_FORMAT_ERROR           = (-137),
    VNET_API_ERROR_NAME_SERVER_NO_SUCH_NAME           = (-138),
    VNET_API_ERROR_NAME_SERVER_NO_ADDRESSES           = (-139),
    VNET_API_ERROR_NAME_SERVER_NEXT_SERVER            = (-140),
    VNET_API_ERROR_APP_CONNECT_FILTERED               = (-141),
    VNET_API_ERROR_ACL_IN_USE_INBOUND                 = (-142),
    VNET_API_ERROR_ACL_IN_USE_OUTBOUND                = (-143),
    VNET_API_ERROR_INIT_FAILED                        = (-144),
    VNET_API_ERROR_NETLINK_ERROR                      = (-145),
    VNET_API_ERROR_BIER_BSL_UNSUP                     = (-146),
    VNET_API_ERROR_INSTANCE_IN_USE                    = (-147),
    VNET_API_ERROR_INVALID_SESSION_ID                 = (-148),
    VNET_API_ERROR_ACL_IN_USE_BY_LOOKUP_CONTEXT       = (-149),
    VNET_API_ERROR_INVALID_VALUE_3                    = (-150),
    VNET_API_ERROR_NON_ETHERNET                       = (-151),
    VNET_API_ERROR_BD_ALREADY_HAS_BVI                 = (-152),
    VNET_API_N_ERROR,
} vnet_api_error_t;
static inline u8 *
format_vnet_api_errno(u8 *s, va_list *args)
{
    vnet_api_error_t api_error = __builtin_va_arg(*args, vnet_api_error_t);
    switch (api_error) {
    case -1:
        s = format(s, "%s", "Unspecified Error");
        break;
    case -2:
        s = format(s, "%s", "Invalid sw_if_index");
        break;
    case -3:
        s = format(s, "%s", "No such FIB / VRF");
        break;
    case -4:
        s = format(s, "%s", "No such inner FIB / VRF");
        break;
    case -5:
        s = format(s, "%s", "No such label");
        break;
    case -6:
        s = format(s, "%s", "No such entry");
        break;
    case -7:
        s = format(s, "%s", "Invalid value");
        break;
    case -8:
        s = format(s, "%s", "Invalid value #2");
        break;
    case -9:
        s = format(s, "%s", "Unimplemented");
        break;
    case -10:
        s = format(s, "%s", "Invalid sw_if_index #2");
        break;
    case -11:
        s = format(s, "%s", "System call error #1");
        break;
    case -12:
        s = format(s, "%s", "System call error #2");
        break;
    case -13:
        s = format(s, "%s", "System call error #3");
        break;
    case -14:
        s = format(s, "%s", "System call error #4");
        break;
    case -15:
        s = format(s, "%s", "System call error #5");
        break;
    case -16:
        s = format(s, "%s", "System call error #6");
        break;
    case -17:
        s = format(s, "%s", "System call error #7");
        break;
    case -18:
        s = format(s, "%s", "System call error #8");
        break;
    case -19:
        s = format(s, "%s", "System call error #9");
        break;
    case -20:
        s = format(s, "%s", "System call error #10");
        break;
    case -30:
        s = format(s, "%s", "Feature disabled by configuration");
        break;
    case -31:
        s = format(s, "%s", "Invalid registration");
        break;
    case -50:
        s = format(s, "%s", "Next hop not in FIB");
        break;
    case -51:
        s = format(s, "%s", "Unknown destination");
        break;
    case -52:
        s = format(s, "%s", "Prefix matches next hop");
        break;
    case -53:
        s = format(s, "%s", "Next hop not found (multipath)");
        break;
    case -54:
        s = format(s, "%s", "No matching interface for probe");
        break;
    case -55:
        s = format(s, "%s", "Invalid VLAN");
        break;
    case -56:
        s = format(s, "%s", "VLAN subif already exists");
        break;
    case -57:
        s = format(s, "%s", "Invalid src address");
        break;
    case -58:
        s = format(s, "%s", "Invalid dst address");
        break;
    case -59:
        s = format(s, "%s", "Address length mismatch");
        break;
    case -60:
        s = format(s, "%s", "Address not found for interface");
        break;
    case -61:
        s = format(s, "%s", "Address not link-local");
        break;
    case -62:
        s = format(s, "%s", "ip6 not enabled");
        break;
    case 10:
        s = format(s, "%s", "Operation in progress");
        break;
    case -63:
        s = format(s, "%s", "No such graph node");
        break;
    case -64:
        s = format(s, "%s", "No such graph node #2");
        break;
    case -65:
        s = format(s, "%s", "No such table");
        break;
    case -66:
        s = format(s, "%s", "No such table #2");
        break;
    case -67:
        s = format(s, "%s", "No such table #3");
        break;
    case -68:
        s = format(s, "%s", "Subinterface already exists");
        break;
    case -69:
        s = format(s, "%s", "Subinterface creation failed");
        break;
    case -70:
        s = format(s, "%s", "Invalid memory size requested");
        break;
    case -71:
        s = format(s, "%s", "Invalid interface");
        break;
    case -72:
        s = format(s, "%s", "Invalid number of tags for requested operation");
        break;
    case -73:
        s = format(s, "%s", "Invalid argument");
        break;
    case -74:
        s = format(s, "%s", "Unexpected interface state");
        break;
    case -75:
        s = format(s, "%s", "Tunnel already exists");
        break;
    case -76:
        s = format(s, "%s", "Invalid decap-next");
        break;
    case -77:
        s = format(s, "%s", "Response not ready");
        break;
    case -78:
        s = format(s, "%s", "Not connected to the data plane");
        break;
    case -79:
        s = format(s, "%s", "Interface already exists");
        break;
    case -80:
        s = format(s, "%s", "Operation not allowed on slave of BondEthernet");
        break;
    case -81:
        s = format(s, "%s", "Value already exists");
        break;
    case -82:
        s = format(s, "%s", "Source and destination are the same");
        break;
    case -83:
        s = format(s, "%s", "IP6 multicast address required");
        break;
    case -84:
        s = format(s, "%s", "Segement routing policy name required");
        break;
    case -85:
        s = format(s, "%s", "Not running as root");
        break;
    case -86:
        s = format(s, "%s", "Connection to the data plane already exists");
        break;
    case -87:
        s = format(s, "%s", "Unsupported JNI version");
        break;
    case -88:
        s = format(s, "%s", "Failed to attach to Java thread");
        break;
    case -89:
        s = format(s, "%s", "Invalid worker thread");
        break;
    case -90:
        s = format(s, "%s", "LISP is disabled");
        break;
    case -91:
        s = format(s, "%s", "Classify table not found");
        break;
    case -92:
        s = format(s, "%s", "Unsupported LSIP EID type");
        break;
    case -93:
        s = format(s, "%s", "Cannot create pcap file");
        break;
    case -94:
        s = format(s, "%s", "Invalid adjacency type for this operation");
        break;
    case -95:
        s = format(s, "%s", "Operation would exceed configured capacity of ranges");
        break;
    case -96:
        s = format(s, "%s", "Operation would exceed capacity of number of ports");
        break;
    case -97:
        s = format(s, "%s", "Invalid address family");
        break;
    case -98:
        s = format(s, "%s", "Invalid sub-interface sw_if_index");
        break;
    case -99:
        s = format(s, "%s", "Table too big");
        break;
    case -100:
        s = format(s, "%s", "Cannot enable/disable feature");
        break;
    case -101:
        s = format(s, "%s", "Duplicate BFD object");
        break;
    case -102:
        s = format(s, "%s", "No such BFD object");
        break;
    case -103:
        s = format(s, "%s", "BFD object in use");
        break;
    case -104:
        s = format(s, "%s", "BFD feature not supported");
        break;
    case -105:
        s = format(s, "%s", "Address in use");
        break;
    case -106:
        s = format(s, "%s", "Address not in use");
        break;
    case -107:
        s = format(s, "%s", "Queue full");
        break;
    case -108:
        s = format(s, "%s", "Unsupported application config");
        break;
    case -109:
        s = format(s, "%s", "URI FIFO segment create failed");
        break;
    case -110:
        s = format(s, "%s", "RLOC address is local");
        break;
    case -111:
        s = format(s, "%s", "BFD object cannot be manipulated at this time");
        break;
    case -112:
        s = format(s, "%s", "Invalid GPE mode");
        break;
    case -113:
        s = format(s, "%s", "LISP GPE entries are present");
        break;
    case -114:
        s = format(s, "%s", "Address found for interface");
        break;
    case -115:
        s = format(s, "%s", "Session failed to connect");
        break;
    case -116:
        s = format(s, "%s", "Entry already exists");
        break;
    case -117:
        s = format(s, "%s", "svm segment create fail");
        break;
    case -118:
        s = format(s, "%s", "application not attached");
        break;
    case -119:
        s = format(s, "%s", "Bridge domain already exists");
        break;
    case -120:
        s = format(s, "%s", "Bridge domain has member interfaces");
        break;
    case -121:
        s = format(s, "%s", "Bridge domain 0 can't be deleted/modified");
        break;
    case -122:
        s = format(s, "%s", "Bridge domain ID exceed 16M limit");
        break;
    case -123:
        s = format(s, "%s", "Subinterface doesn't exist");
        break;
    case -124:
        s = format(s, "%s", "Client already exist for L2 MACs events");
        break;
    case -125:
        s = format(s, "%s", "Invalid queue");
        break;
    case -126:
        s = format(s, "%s", "Unsupported");
        break;
    case -127:
        s = format(s, "%s", "Address already present on another interface");
        break;
    case -128:
        s = format(s, "%s", "Invalid application namespace");
        break;
    case -129:
        s = format(s, "%s", "Wrong app namespace secret");
        break;
    case -130:
        s = format(s, "%s", "Connect scope");
        break;
    case -131:
        s = format(s, "%s", "App already attached");
        break;
    case -132:
        s = format(s, "%s", "Redirect failed");
        break;
    case -133:
        s = format(s, "%s", "Illegal name");
        break;
    case -134:
        s = format(s, "%s", "No name servers configured");
        break;
    case -135:
        s = format(s, "%s", "Name server not found");
        break;
    case -136:
        s = format(s, "%s", "Name resolution not enabled");
        break;
    case -137:
        s = format(s, "%s", "Server format error (bug!)");
        break;
    case -138:
        s = format(s, "%s", "No such name");
        break;
    case -139:
        s = format(s, "%s", "No addresses available");
        break;
    case -140:
        s = format(s, "%s", "Retry with new server");
        break;
    case -141:
        s = format(s, "%s", "Connect was filtered");
        break;
    case -142:
        s = format(s, "%s", "Inbound ACL in use");
        break;
    case -143:
        s = format(s, "%s", "Outbound ACL in use");
        break;
    case -144:
        s = format(s, "%s", "Initialization Failed");
        break;
    case -145:
        s = format(s, "%s", "netlink error");
        break;
    case -146:
        s = format(s, "%s", "BIER bit-string-length unsupported");
        break;
    case -147:
        s = format(s, "%s", "Instance in use");
        break;
    case -148:
        s = format(s, "%s", "session ID out of range");
        break;
    case -149:
        s = format(s, "%s", "ACL in use by a lookup context");
        break;
    case -150:
        s = format(s, "%s", "Invalid value #3");
        break;
    case -151:
        s = format(s, "%s", "Interface is not an Ethernet interface");
        break;
    case -152:
        s = format(s, "%s", "Bridge domain already has a BVI interface");
        break;
    default:
        s = format(s, "UNKNOWN");
        break;
    }
    return s;
}
typedef struct vnet_main_t {
    u32 local_interface_hw_if_index;
    u32 local_interface_sw_if_index;
    vnet_interface_main_t interface_main;
    vnet_device_class_t *device_class_registrations;
    vnet_hw_interface_class_t *hw_interface_class_registrations;
    _vnet_interface_function_list_elt_t
        *hw_interface_add_del_functions[((vnet_interface_function_priority_t) VNET_ITF_FUNC_PRIORITY_HIGH + 1)];
    _vnet_interface_function_list_elt_t
        *hw_interface_link_up_down_functions[((vnet_interface_function_priority_t) VNET_ITF_FUNC_PRIORITY_HIGH + 1)];
    _vnet_interface_function_list_elt_t
        *sw_interface_add_del_functions[((vnet_interface_function_priority_t) VNET_ITF_FUNC_PRIORITY_HIGH + 1)];
    _vnet_interface_function_list_elt_t
        *sw_interface_admin_up_down_functions[((vnet_interface_function_priority_t) VNET_ITF_FUNC_PRIORITY_HIGH + 1)];
    _vnet_interface_function_list_elt_t
        *sw_interface_mtu_change_functions[((vnet_interface_function_priority_t) VNET_ITF_FUNC_PRIORITY_HIGH + 1)];
    uword *interface_tag_by_sw_if_index;
    vnet_api_error_t api_errno;
    vlib_main_t *vlib_main;
} vnet_main_t;
extern vnet_main_t vnet_main;
extern vnet_main_t **vnet_mains;
static inline __attribute__((__always_inline__)) vnet_hw_interface_t *
vnet_get_hw_interface(vnet_main_t *vnm, u32 hw_if_index)
{
    return ({
        typeof(vnm->interface_main.hw_interfaces) _e = (vnm->interface_main.hw_interfaces) + (hw_if_index);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(vnm->interface_main.hw_interfaces);
                    uword _pool_i          = (_e) - (vnm->interface_main.hw_interfaces);
                    (_pool_i < ((vnm->interface_main.hw_interfaces) ?
                                    (((vec_header_t *) (vnm->interface_main.hw_interfaces) - 1)->len) :
                                    0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/interface_funcs.h", (uword) 46,
                            ((char *) __FUNCTION__), "! pool_is_free (vnm->interface_main.hw_interfaces, _e)");
            }
        } while (0);
        _e;
    });
}
static inline __attribute__((__always_inline__)) vnet_hw_interface_t *
vnet_get_hw_interface_safe(vnet_main_t *vnm, u32 hw_if_index)
{
    if (!({
            pool_header_t *_pool_p = pool_header((vnm->interface_main.hw_interfaces));
            uword _pool_i = ((vnm->interface_main.hw_interfaces) + (hw_if_index)) - ((vnm->interface_main.hw_interfaces));
            (_pool_i < (((vnm->interface_main.hw_interfaces)) ?
                            (((vec_header_t *) ((vnm->interface_main.hw_interfaces)) - 1)->len) :
                            0)) ?
                clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                1;
        }))
        return ({
            typeof(vnm->interface_main.hw_interfaces) _e = (vnm->interface_main.hw_interfaces) + (hw_if_index);
            do {
                if ((0 > 0) && !(!({
                        pool_header_t *_pool_p = pool_header(vnm->interface_main.hw_interfaces);
                        uword _pool_i          = (_e) - (vnm->interface_main.hw_interfaces);
                        (_pool_i < ((vnm->interface_main.hw_interfaces) ?
                                        (((vec_header_t *) (vnm->interface_main.hw_interfaces) - 1)->len) :
                                        0)) ?
                            clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                            1;
                    }))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vnet/interface_funcs.h",
                                (uword) 53, ((char *) __FUNCTION__),
                                "! pool_is_free (vnm->interface_main.hw_interfaces, _e)");
                }
            } while (0);
            _e;
        });
    return (((void *) 0));
}
static inline __attribute__((__always_inline__)) vnet_sw_interface_t *
vnet_get_sw_interface(vnet_main_t *vnm, u32 sw_if_index)
{
    return ({
        typeof(vnm->interface_main.sw_interfaces) _e = (vnm->interface_main.sw_interfaces) + (sw_if_index);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(vnm->interface_main.sw_interfaces);
                    uword _pool_i          = (_e) - (vnm->interface_main.sw_interfaces);
                    (_pool_i < ((vnm->interface_main.sw_interfaces) ?
                                    (((vec_header_t *) (vnm->interface_main.sw_interfaces) - 1)->len) :
                                    0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/interface_funcs.h", (uword) 60,
                            ((char *) __FUNCTION__), "! pool_is_free (vnm->interface_main.sw_interfaces, _e)");
            }
        } while (0);
        _e;
    });
}
static inline __attribute__((__always_inline__)) vnet_sw_interface_t *
vnet_get_sw_interface_safe(vnet_main_t *vnm, u32 sw_if_index)
{
    if (!({
            pool_header_t *_pool_p = pool_header((vnm->interface_main.sw_interfaces));
            uword _pool_i = ((vnm->interface_main.sw_interfaces) + (sw_if_index)) - ((vnm->interface_main.sw_interfaces));
            (_pool_i < (((vnm->interface_main.sw_interfaces)) ?
                            (((vec_header_t *) ((vnm->interface_main.sw_interfaces)) - 1)->len) :
                            0)) ?
                clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                1;
        }))
        return ({
            typeof(vnm->interface_main.sw_interfaces) _e = (vnm->interface_main.sw_interfaces) + (sw_if_index);
            do {
                if ((0 > 0) && !(!({
                        pool_header_t *_pool_p = pool_header(vnm->interface_main.sw_interfaces);
                        uword _pool_i          = (_e) - (vnm->interface_main.sw_interfaces);
                        (_pool_i < ((vnm->interface_main.sw_interfaces) ?
                                        (((vec_header_t *) (vnm->interface_main.sw_interfaces) - 1)->len) :
                                        0)) ?
                            clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                            1;
                    }))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vnet/interface_funcs.h",
                                (uword) 67, ((char *) __FUNCTION__),
                                "! pool_is_free (vnm->interface_main.sw_interfaces, _e)");
                }
            } while (0);
            _e;
        });
    return (((void *) 0));
}
static inline __attribute__((__always_inline__)) vnet_sw_interface_t *
vnet_get_hw_sw_interface(vnet_main_t *vnm, u32 hw_if_index)
{
    vnet_hw_interface_t *hw = vnet_get_hw_interface(vnm, hw_if_index);
    vnet_sw_interface_t *sw = vnet_get_sw_interface(vnm, hw->sw_if_index);
    do {
        if ((0 > 0) && !(sw->type == VNET_SW_INTERFACE_TYPE_HARDWARE)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/interface_funcs.h", (uword) 76,
                        ((char *) __FUNCTION__), "sw->type == VNET_SW_INTERFACE_TYPE_HARDWARE");
        }
    } while (0);
    return sw;
}
static inline __attribute__((__always_inline__)) vnet_sw_interface_t *
vnet_get_sup_sw_interface(vnet_main_t *vnm, u32 sw_if_index)
{
    vnet_sw_interface_t *sw = vnet_get_sw_interface(vnm, sw_if_index);
    if (sw->type == VNET_SW_INTERFACE_TYPE_SUB || sw->type == VNET_SW_INTERFACE_TYPE_PIPE ||
        sw->type == VNET_SW_INTERFACE_TYPE_P2P)
        sw = vnet_get_sw_interface(vnm, sw->sup_sw_if_index);
    return sw;
}
static inline __attribute__((__always_inline__)) vnet_hw_interface_t *
vnet_get_sup_hw_interface(vnet_main_t *vnm, u32 sw_if_index)
{
    vnet_sw_interface_t *sw = vnet_get_sup_sw_interface(vnm, sw_if_index);
    do {
        if ((0 > 0) && !((sw->type == VNET_SW_INTERFACE_TYPE_HARDWARE) || (sw->type == VNET_SW_INTERFACE_TYPE_PIPE))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/interface_funcs.h", (uword) 96,
                        ((char *) __FUNCTION__),
                        "(sw->type == VNET_SW_INTERFACE_TYPE_HARDWARE) || (sw->type == VNET_SW_INTERFACE_TYPE_PIPE)");
        }
    } while (0);
    return vnet_get_hw_interface(vnm, sw->hw_if_index);
}
static inline __attribute__((__always_inline__)) vnet_hw_interface_class_t *
vnet_get_hw_interface_class(vnet_main_t *vnm, u32 hw_class_index)
{
    return ({
        do {
            if ((0 > 0) &&
                !((hw_class_index) < ((vnm->interface_main.hw_interface_classes) ?
                                          (((vec_header_t *) (vnm->interface_main.hw_interface_classes) - 1)->len) :
                                          0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/interface_funcs.h",
                            (uword) 104, ((char *) __FUNCTION__),
                            "(hw_class_index) < vec_len (vnm->interface_main.hw_interface_classes)");
            }
        } while (0);
        (vnm->interface_main.hw_interface_classes) + (hw_class_index);
    });
}
static inline __attribute__((__always_inline__)) vnet_device_class_t *
vnet_get_device_class(vnet_main_t *vnm, u32 dev_class_index)
{
    return ({
        do {
            if ((0 > 0) && !((dev_class_index) < ((vnm->interface_main.device_classes) ?
                                                      (((vec_header_t *) (vnm->interface_main.device_classes) - 1)->len) :
                                                      0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/interface_funcs.h",
                            (uword) 111, ((char *) __FUNCTION__),
                            "(dev_class_index) < vec_len (vnm->interface_main.device_classes)");
            }
        } while (0);
        (vnm->interface_main.device_classes) + (dev_class_index);
    });
}
static inline u8 *
vnet_get_sw_interface_tag(vnet_main_t *vnm, u32 sw_if_index)
{
    uword *p;
    p = _hash_get((vnm->interface_tag_by_sw_if_index), (uword)(sw_if_index));
    if (p)
        return ((u8 *) p[0]);
    return 0;
}
static inline void
vnet_set_sw_interface_tag(vnet_main_t *vnm, u8 *tag, u32 sw_if_index)
{
    uword *p;
    p = _hash_get((vnm->interface_tag_by_sw_if_index), (uword)(sw_if_index));
    if (p) {
        u8 *oldtag = (u8 *) p[0];
        ((vnm->interface_tag_by_sw_if_index) = _hash_unset((vnm->interface_tag_by_sw_if_index), (uword)(sw_if_index), 0));
        do {
            if (oldtag) {
                clib_mem_free(vec_header((oldtag), (0)));
                oldtag = 0;
            }
        } while (0);
    }
    ({
        uword _v = (uword)(tag);
        (vnm->interface_tag_by_sw_if_index) =
            _hash_set3((vnm->interface_tag_by_sw_if_index), (uword)(sw_if_index), (void *) &_v, (0));
    });
}
static inline void
vnet_clear_sw_interface_tag(vnet_main_t *vnm, u32 sw_if_index)
{
    uword *p;
    p = _hash_get((vnm->interface_tag_by_sw_if_index), (uword)(sw_if_index));
    if (p) {
        u8 *oldtag = (u8 *) p[0];
        ((vnm->interface_tag_by_sw_if_index) = _hash_unset((vnm->interface_tag_by_sw_if_index), (uword)(sw_if_index), 0));
        do {
            if (oldtag) {
                clib_mem_free(vec_header((oldtag), (0)));
                oldtag = 0;
            }
        } while (0);
    }
}
typedef enum walk_rc_t_ {
    WALK_STOP,
    WALK_CONTINUE,
} walk_rc_t;
typedef walk_rc_t (*vnet_hw_sw_interface_walk_t)(vnet_main_t *vnm, u32 sw_if_index, void *ctx);
void vnet_hw_interface_walk_sw(vnet_main_t *vnm, u32 hw_if_index, vnet_hw_sw_interface_walk_t fn, void *ctx);
typedef walk_rc_t (*vnet_sw_interface_walk_t)(vnet_main_t *vnm, vnet_sw_interface_t *si, void *ctx);
void vnet_sw_interface_walk(vnet_main_t *vnm, vnet_sw_interface_walk_t fn, void *ctx);
typedef walk_rc_t (*vnet_hw_interface_walk_t)(vnet_main_t *vnm, u32 hw_if_index, void *ctx);
void vnet_hw_interface_walk(vnet_main_t *vnm, vnet_hw_interface_walk_t fn, void *ctx);
u32 vnet_register_interface(vnet_main_t *vnm, u32 dev_class_index, u32 dev_instance, u32 hw_class_index, u32 hw_instance);
void vnet_set_interface_output_node(vnet_main_t *vnm, u32 hw_if_index, u32 node_index);
clib_error_t *vnet_create_sw_interface(vnet_main_t *vnm, vnet_sw_interface_t *template, u32 *sw_if_index);
void vnet_delete_hw_interface(vnet_main_t *vnm, u32 hw_if_index);
void vnet_delete_sw_interface(vnet_main_t *vnm, u32 sw_if_index);
int vnet_sw_interface_is_p2p(vnet_main_t *vnm, u32 sw_if_index);
static inline __attribute__((__always_inline__)) vnet_sw_interface_flags_t
vnet_sw_interface_get_flags(vnet_main_t *vnm, u32 sw_if_index)
{
    vnet_sw_interface_t *sw = vnet_get_sw_interface(vnm, sw_if_index);
    return sw->flags;
}
static inline __attribute__((__always_inline__)) uword
vnet_sw_interface_is_valid(vnet_main_t *vnm, u32 sw_if_index)
{
    return !({
        pool_header_t *_pool_p = pool_header((vnm->interface_main.sw_interfaces));
        uword _pool_i = ((vnm->interface_main.sw_interfaces) + (sw_if_index)) - ((vnm->interface_main.sw_interfaces));
        (_pool_i < (((vnm->interface_main.sw_interfaces)) ?
                        (((vec_header_t *) ((vnm->interface_main.sw_interfaces)) - 1)->len) :
                        0)) ?
            clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
            1;
    });
}
static inline __attribute__((__always_inline__)) uword
vnet_hw_interface_is_valid(vnet_main_t *vnm, u32 hw_if_index)
{
    return !({
        pool_header_t *_pool_p = pool_header((vnm->interface_main.hw_interfaces));
        uword _pool_i = ((vnm->interface_main.hw_interfaces) + (hw_if_index)) - ((vnm->interface_main.hw_interfaces));
        (_pool_i < (((vnm->interface_main.hw_interfaces)) ?
                        (((vec_header_t *) ((vnm->interface_main.hw_interfaces)) - 1)->len) :
                        0)) ?
            clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
            1;
    });
}
static inline __attribute__((__always_inline__)) uword
vnet_sw_interface_is_admin_up(vnet_main_t *vnm, u32 sw_if_index)
{
    return (vnet_sw_interface_get_flags(vnm, sw_if_index) & VNET_SW_INTERFACE_FLAG_ADMIN_UP) != 0;
}
static inline __attribute__((__always_inline__)) uword
vnet_swif_is_api_visible(vnet_sw_interface_t *si)
{
    return !(si->flags & VNET_SW_INTERFACE_FLAG_HIDDEN);
}
static inline __attribute__((__always_inline__)) uword
vnet_sw_interface_is_api_visible(vnet_main_t *vnm, u32 sw_if_index)
{
    vnet_sw_interface_t *si = vnet_get_sw_interface(vnm, sw_if_index);
    return vnet_swif_is_api_visible(si);
}
static inline __attribute__((__always_inline__)) uword
vnet_sw_interface_is_api_valid(vnet_main_t *vnm, u32 sw_if_index)
{
    return !({
        pool_header_t *_pool_p = pool_header((vnm->interface_main.sw_interfaces));
        uword _pool_i = ((vnm->interface_main.sw_interfaces) + (sw_if_index)) - ((vnm->interface_main.sw_interfaces));
        (_pool_i < (((vnm->interface_main.sw_interfaces)) ?
                        (((vec_header_t *) ((vnm->interface_main.sw_interfaces)) - 1)->len) :
                        0)) ?
            clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
            1;
    }) && vnet_sw_interface_is_api_visible(vnm, sw_if_index);
}
static inline __attribute__((__always_inline__)) uword
vnet_hw_interface_get_flags(vnet_main_t *vnm, u32 hw_if_index)
{
    vnet_hw_interface_t *hw = vnet_get_hw_interface(vnm, hw_if_index);
    return hw->flags;
}
static inline __attribute__((__always_inline__)) u32
vnet_hw_interface_get_mtu(vnet_main_t *vnm, u32 hw_if_index)
{
    vnet_hw_interface_t *hw = vnet_get_hw_interface(vnm, hw_if_index);
    return hw->max_packet_bytes;
}
static inline __attribute__((__always_inline__)) u32
vnet_sw_interface_get_mtu(vnet_main_t *vnm, u32 sw_if_index, vnet_mtu_t af)
{
    vnet_sw_interface_t *sw = vnet_get_sw_interface(vnm, sw_if_index);
    u32 mtu;
    mtu = sw->mtu[af] > 0 ? sw->mtu[af] : sw->mtu[VNET_MTU_L3];
    if (mtu == 0)
        return 9000;
    return mtu;
}
static inline __attribute__((__always_inline__)) uword
vnet_hw_interface_is_link_up(vnet_main_t *vnm, u32 hw_if_index)
{
    return (vnet_hw_interface_get_flags(vnm, hw_if_index) & (1 << 0)) != 0;
}
static inline __attribute__((__always_inline__)) vlib_frame_t *
vnet_get_frame_to_sw_interface(vnet_main_t *vnm, u32 sw_if_index)
{
    vnet_hw_interface_t *hw = vnet_get_sup_hw_interface(vnm, sw_if_index);
    return vlib_get_frame_to_node(vlib_get_main(), hw->output_node_index);
}
static inline __attribute__((__always_inline__)) void
vnet_put_frame_to_sw_interface(vnet_main_t *vnm, u32 sw_if_index, vlib_frame_t *f)
{
    vnet_hw_interface_t *hw = vnet_get_sup_hw_interface(vnm, sw_if_index);
    return vlib_put_frame_to_node(vlib_get_main(), hw->output_node_index, f);
}
clib_error_t *vnet_hw_interface_set_flags(vnet_main_t *vnm, u32 hw_if_index, u32 flags);
clib_error_t *vnet_sw_interface_set_flags(vnet_main_t *vnm, u32 sw_if_index, u32 flags);
clib_error_t *vnet_hw_interface_set_class(vnet_main_t *vnm, u32 hw_if_index, u32 new_hw_class_index);
int vnet_hw_interface_rx_redirect_to_node(vnet_main_t *vnm, u32 hw_if_index, u32 node_index);
void vnet_hw_interface_init_for_class(vnet_main_t *vnm, u32 hw_if_index, u32 hw_class_index, u32 hw_instance);
clib_error_t *vnet_rename_interface(vnet_main_t *vnm, u32 hw_if_index, char *new_name);
clib_error_t *vnet_hw_interface_change_mac_address(vnet_main_t *vnm, u32 hw_if_index, u8 *mac_address);
clib_error_t *set_hw_interface_change_rx_mode(vnet_main_t *vnm, u32 hw_if_index, u8 queue_id_valid, u32 queue_id,
                                              vnet_hw_interface_rx_mode mode);
clib_error_t *set_hw_interface_rx_placement(u32 hw_if_index, u32 queue_id, u32 thread_index, u8 is_main);
void vnet_hw_interface_set_mtu(vnet_main_t *vnm, u32 hw_if_index, u32 mtu);
void vnet_sw_interface_set_mtu(vnet_main_t *vnm, u32 sw_if_index, u32 mtu);
void vnet_sw_interface_set_protocol_mtu(vnet_main_t *vnm, u32 sw_if_index, u32 mtu[]);
void vnet_sw_interface_update_unnumbered(u32 sw_if_index, u32 ip_sw_if_index, u8 enable);
int vnet_sw_interface_stats_collect_enable_disable(u32 sw_if_index, u8 enable);
void vnet_sw_interface_ip_directed_broadcast(vnet_main_t *vnm, u32 sw_if_index, u8 enable);
format_function_t format_vnet_hw_interface;
format_function_t format_vnet_hw_interface_rx_mode;
format_function_t format_vnet_hw_if_index_name;
format_function_t format_vnet_sw_interface;
format_function_t format_vnet_sw_interface_name;
format_function_t format_vnet_sw_interface_name_override;
format_function_t format_vnet_sw_if_index_name;
format_function_t format_vnet_sw_interface_flags;
unformat_function_t unformat_vnet_sw_interface;
unformat_function_t unformat_vnet_hw_interface;
unformat_function_t unformat_vnet_hw_interface_flags;
unformat_function_t unformat_vnet_sw_interface_flags;
typedef struct {
    u32 hw_if_index;
    u32 sw_if_index;
    u32 dev_instance;
    u32 is_deleted;
} vnet_interface_output_runtime_t;
void *vnet_interface_output_node_multiarch_select(void);
word vnet_sw_interface_compare(vnet_main_t *vnm, uword sw_if_index0, uword sw_if_index1);
word vnet_hw_interface_compare(vnet_main_t *vnm, uword hw_if_index0, uword hw_if_index1);
typedef enum {
    VNET_INTERFACE_OUTPUT_NEXT_DROP,
    VNET_INTERFACE_OUTPUT_NEXT_TX,
} vnet_interface_output_next_t;
typedef enum {
    VNET_INTERFACE_TX_NEXT_DROP,
    VNET_INTERFACE_TX_N_NEXT,
} vnet_interface_tx_next_t;
typedef enum {
    VNET_INTERFACE_OUTPUT_ERROR_INTERFACE_DOWN,
    VNET_INTERFACE_OUTPUT_ERROR_INTERFACE_DELETED,
} vnet_interface_output_error_t;
u8 *format_vnet_interface_output_trace(u8 *s, va_list *va);
serialize_function_t serialize_vnet_interface_state, unserialize_vnet_interface_state;
vnet_main_t *vnet_get_main(void);
typedef enum {
    PG_EDIT_INVALID_TYPE,
    PG_EDIT_FIXED,
    PG_EDIT_INCREMENT,
    PG_EDIT_RANDOM,
    PG_EDIT_UNSPECIFIED,
} pg_edit_type_t;
typedef struct {
    pg_edit_type_t type;
    i32 lsb_bit_offset;
    u32 n_bits;
    u8 *values[2];
    u64 last_increment_value;
} pg_edit_t;
static inline __attribute__((__always_inline__)) void
pg_edit_free(pg_edit_t *e)
{
    int i;
    for (i = 0; i < (sizeof(e->values) / sizeof(e->values[0])); i++)
        do {
            if (e->values[i]) {
                clib_mem_free(vec_header((e->values[i]), (0)));
                e->values[i] = 0;
            }
        } while (0);
}
static inline uword
pg_edit_n_alloc_bytes(pg_edit_t *e)
{
    int i0, i1, n_bytes, n_bits_left;
    i0          = e->lsb_bit_offset;
    i1          = i0 % (8 * sizeof(u8));
    n_bytes     = 0;
    n_bits_left = e->n_bits;
    if (n_bits_left > 0 && i1 != 0) {
        n_bytes++;
        n_bits_left -= i1;
        if (n_bits_left < 0)
            n_bits_left = 0;
    }
    n_bytes += (n_bits_left / (8 * sizeof(u8)));
    n_bytes += (n_bits_left % (8 * sizeof(u8))) != 0;
    return n_bytes;
}
static inline void
pg_edit_alloc_value(pg_edit_t *e, int i)
{
    do {
        _Static_assert(0 == 0 || ((0 % sizeof(e->values[i][0])) == 0) || ((sizeof(e->values[i][0]) % 0) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = (e->lsb_bit_offset / (8 * sizeof(u8)));
        word _vec_l = ((e->values[i]) ? (((vec_header_t *) (e->values[i]) - 1)->len) : 0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n    = (1 + (_vec_i - _vec_l));
                word _vec_l    = (((e->values[i])) ? (((vec_header_t *) ((e->values[i])) - 1)->len) : 0);
                (e->values[i]) = _vec_resize_inline(((e->values[i])), _vec_n,
                                                    (_vec_l + _vec_n) * sizeof(((e->values[i]))[0]), ((0)), ({
                                                        __typeof__((__alignof__((((e->values[i])))[0]))) _x =
                                                            ((__alignof__((((e->values[i])))[0])));
                                                        __typeof__((((0)))) _y = ((((0))));
                                                        _x > _y ? _x : _y;
                                                    }));
            } while (0);
            memset((e->values[i]) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof((e->values[i])[0]));
        }
    } while (0);
}
extern void pg_edit_set_value(pg_edit_t *e, int hi_or_lo, u64 value);
static inline void
pg_edit_set_fixed(pg_edit_t *e, u64 value)
{
    e->type = PG_EDIT_FIXED;
    pg_edit_set_value(e, 0, value);
}
static inline void
pg_edit_copy_type_and_values(pg_edit_t *dst, pg_edit_t *src)
{
    int i;
    dst->type = src->type;
    src->type = PG_EDIT_INVALID_TYPE;
    for (i = 0; i < (sizeof(dst->values) / sizeof(dst->values[0])); i++) {
        dst->values[i] = src->values[i];
        src->values[i] = 0;
    }
}
static inline u64
pg_edit_get_value(pg_edit_t *e, int hi_or_lo)
{
    u64 r = 0;
    int i, n;
    u8 *v = e->values[hi_or_lo];
    n     = round_pow2(e->n_bits, (8 * sizeof(u8))) / (8 * sizeof(u8));
    do {
        if ((0 > 0) && !(n <= ((v) ? (((vec_header_t *) (v) -1)->len) : 0))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/pg/edit.h", (uword) 181,
                        ((char *) __FUNCTION__), "n <= vec_len (v)");
        }
    } while (0);
    do {
        if ((0 > 0) && !(n <= sizeof(r))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/pg/edit.h", (uword) 182,
                        ((char *) __FUNCTION__), "n <= sizeof (r)");
        }
    } while (0);
    for (i = 0; i < n; i++)
        r = (r << (8 * sizeof(v[i]))) + v[i];
    return r;
}
static inline uword
pg_edit_is_fixed_with_value(pg_edit_t *e, u64 value)
{
    return (e->type == PG_EDIT_FIXED && value == pg_edit_get_value(e, 0));
}
uword unformat_pg_edit(unformat_input_t *input, va_list *args);
uword unformat_pg_payload(unformat_input_t *input, va_list *args);
uword unformat_pg_number(unformat_input_t *input, va_list *args);
uword unformat_pg_interface(unformat_input_t *input, va_list *args);
extern vnet_device_class_t pg_dev_class;
struct pg_main_t;
struct pg_stream_t;
typedef struct pg_edit_group_t {
    pg_edit_t *edits;
    pg_edit_t *non_fixed_edits;
    u8 *fixed_packet_data;
    u8 *fixed_packet_data_mask;
    u32 start_byte_offset;
    u32 n_packet_bytes;
    void (*edit_function)(struct pg_main_t *pg, struct pg_stream_t *s, struct pg_edit_group_t *g, u32 *buffers,
                          u32 n_buffers);
    uword edit_function_opaque;
} pg_edit_group_t;
typedef struct {
    pg_edit_t *edits;
    u32 *buffer_fifo;
    vlib_buffer_free_list_index_t free_list_index;
} pg_buffer_index_t;
typedef struct pg_stream_t {
    u8 *name;
    u32 flags;
    pg_edit_group_t *edit_groups;
    pg_edit_type_t packet_size_edit_type;
    u32 min_packet_bytes, max_packet_bytes;
    pg_edit_t *non_fixed_edits;
    u8 *fixed_packet_data, *fixed_packet_data_mask;
    u32 buffer_bytes;
    u32 last_increment_packet_size;
    u32 pg_if_index;
    u32 sw_if_index[VLIB_N_RX_TX];
    u32 node_index;
    u32 worker_index;
    u32 next_index;
    u32 if_id;
    u64 n_packets_generated;
    u64 n_packets_limit;
    f64 rate_packets_per_second;
    f64 time_last_generate;
    f64 packet_accumulator;
    pg_buffer_index_t *buffer_indices;
    u8 **replay_packet_templates;
    u64 *replay_packet_timestamps;
    u32 current_replay_packet_index;
} pg_stream_t;
static inline __attribute__((__always_inline__)) void
pg_buffer_index_free(pg_buffer_index_t *bi)
{
    do {
        if (bi->edits) {
            clib_mem_free(vec_header((bi->edits), (0)));
            bi->edits = 0;
        }
    } while (0);
    do {
        if ((bi->buffer_fifo)) {
            clib_mem_free(vec_header(((bi->buffer_fifo)), (sizeof(clib_fifo_header_t))));
            (bi->buffer_fifo) = 0;
        }
    } while (0);
}
static inline __attribute__((__always_inline__)) void
pg_edit_group_free(pg_edit_group_t *g)
{
    pg_edit_t *e;
    for (e = (g->edits); e < ((g->edits) + ((g->edits) ? (((vec_header_t *) (g->edits) - 1)->len) : 0)); e++)
        pg_edit_free(e);
    do {
        if (g->edits) {
            clib_mem_free(vec_header((g->edits), (0)));
            g->edits = 0;
        }
    } while (0);
    do {
        if (g->fixed_packet_data) {
            clib_mem_free(vec_header((g->fixed_packet_data), (0)));
            g->fixed_packet_data = 0;
        }
    } while (0);
    do {
        if (g->fixed_packet_data_mask) {
            clib_mem_free(vec_header((g->fixed_packet_data_mask), (0)));
            g->fixed_packet_data_mask = 0;
        }
    } while (0);
}
static inline __attribute__((__always_inline__)) void
pg_stream_free(pg_stream_t *s)
{
    int i;
    pg_edit_group_t *g;
    pg_edit_t *e;
    for (e = (s->non_fixed_edits);
         e < ((s->non_fixed_edits) + ((s->non_fixed_edits) ? (((vec_header_t *) (s->non_fixed_edits) - 1)->len) : 0));
         e++)
        pg_edit_free(e);
    do {
        if (s->non_fixed_edits) {
            clib_mem_free(vec_header((s->non_fixed_edits), (0)));
            s->non_fixed_edits = 0;
        }
    } while (0);
    for (g = (s->edit_groups);
         g < ((s->edit_groups) + ((s->edit_groups) ? (((vec_header_t *) (s->edit_groups) - 1)->len) : 0)); g++)
        pg_edit_group_free(g);
    do {
        if (s->edit_groups) {
            clib_mem_free(vec_header((s->edit_groups), (0)));
            s->edit_groups = 0;
        }
    } while (0);
    do {
        if (s->fixed_packet_data) {
            clib_mem_free(vec_header((s->fixed_packet_data), (0)));
            s->fixed_packet_data = 0;
        }
    } while (0);
    do {
        if (s->fixed_packet_data_mask) {
            clib_mem_free(vec_header((s->fixed_packet_data_mask), (0)));
            s->fixed_packet_data_mask = 0;
        }
    } while (0);
    do {
        if (s->name) {
            clib_mem_free(vec_header((s->name), (0)));
            s->name = 0;
        }
    } while (0);
    for (i = 0; i < ((s->replay_packet_templates) ? (((vec_header_t *) (s->replay_packet_templates) - 1)->len) : 0); i++)
        do {
            if (s->replay_packet_templates[i]) {
                clib_mem_free(vec_header((s->replay_packet_templates[i]), (0)));
                s->replay_packet_templates[i] = 0;
            }
        } while (0);
    do {
        if (s->replay_packet_templates) {
            clib_mem_free(vec_header((s->replay_packet_templates), (0)));
            s->replay_packet_templates = 0;
        }
    } while (0);
    do {
        if (s->replay_packet_timestamps) {
            clib_mem_free(vec_header((s->replay_packet_timestamps), (0)));
            s->replay_packet_timestamps = 0;
        }
    } while (0);
    {
        pg_buffer_index_t *bi;
        for (bi = (s->buffer_indices);
             bi < ((s->buffer_indices) + ((s->buffer_indices) ? (((vec_header_t *) (s->buffer_indices) - 1)->len) : 0));
             bi++)
            pg_buffer_index_free(bi);
        do {
            if (s->buffer_indices) {
                clib_mem_free(vec_header((s->buffer_indices), (0)));
                s->buffer_indices = 0;
            }
        } while (0);
    }
}
static inline __attribute__((__always_inline__)) int
pg_stream_is_enabled(pg_stream_t *s)
{
    return (s->flags & (1 << 0)) != 0;
}
static inline __attribute__((__always_inline__)) pg_edit_group_t *
pg_stream_get_group(pg_stream_t *s, u32 group_index)
{
    return ({
        do {
            if ((0 > 0) && !((group_index) < ((s->edit_groups) ? (((vec_header_t *) (s->edit_groups) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/pg/pg.h", (uword) 227,
                            ((char *) __FUNCTION__), "(group_index) < vec_len (s->edit_groups)");
            }
        } while (0);
        (s->edit_groups) + (group_index);
    });
}
static inline __attribute__((__always_inline__)) void *
pg_create_edit_group(pg_stream_t *s, int n_edit_bytes, int n_packet_bytes, u32 *group_index)
{
    pg_edit_group_t *g;
    int n_edits;
    do {
        word _vec_n = (1);
        word _vec_l = ((s->edit_groups) ? (((vec_header_t *) (s->edit_groups) - 1)->len) : 0);
        s->edit_groups =
            _vec_resize_inline((s->edit_groups), _vec_n, (_vec_l + _vec_n) * sizeof((s->edit_groups)[0]), (0), ({
                                   __typeof__((__alignof__(((s->edit_groups))[0]))) _x =
                                       ((__alignof__(((s->edit_groups))[0])));
                                   __typeof__(((0))) _y = (((0)));
                                   _x > _y ? _x : _y;
                               }));
        g = (s->edit_groups) + _vec_l;
    } while (0);
    if (group_index)
        *group_index = g - s->edit_groups;
    do {
        if ((0 > 0) && !(n_edit_bytes % sizeof(pg_edit_t) == 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/pg/pg.h", (uword) 241,
                        ((char *) __FUNCTION__), "n_edit_bytes % sizeof (pg_edit_t) == 0");
        }
    } while (0);
    n_edits = n_edit_bytes / sizeof(pg_edit_t);
    do {
        word _vec_n = (n_edits);
        word _vec_l = ((g->edits) ? (((vec_header_t *) (g->edits) - 1)->len) : 0);
        g->edits    = _vec_resize_inline((g->edits), _vec_n, (_vec_l + _vec_n) * sizeof((g->edits)[0]), (0), ({
                                          __typeof__((__alignof__(((g->edits))[0]))) _x =
                                              ((__alignof__(((g->edits))[0])));
                                          __typeof__(((0))) _y = (((0)));
                                          _x > _y ? _x : _y;
                                      }));
    } while (0);
    g->n_packet_bytes = n_packet_bytes;
    return g->edits;
}
static inline __attribute__((__always_inline__)) void *
pg_add_edits(pg_stream_t *s, int n_edit_bytes, int n_packet_bytes, u32 group_index)
{
    pg_edit_group_t *g = pg_stream_get_group(s, group_index);
    pg_edit_t *e;
    int n_edits;
    do {
        if ((0 > 0) && !(n_edit_bytes % sizeof(pg_edit_t) == 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/pg/pg.h", (uword) 257,
                        ((char *) __FUNCTION__), "n_edit_bytes % sizeof (pg_edit_t) == 0");
        }
    } while (0);
    n_edits = n_edit_bytes / sizeof(pg_edit_t);
    do {
        word _vec_n = (n_edits);
        word _vec_l = ((g->edits) ? (((vec_header_t *) (g->edits) - 1)->len) : 0);
        g->edits    = _vec_resize_inline((g->edits), _vec_n, (_vec_l + _vec_n) * sizeof((g->edits)[0]), (0), ({
                                          __typeof__((__alignof__(((g->edits))[0]))) _x =
                                              ((__alignof__(((g->edits))[0])));
                                          __typeof__(((0))) _y = (((0)));
                                          _x > _y ? _x : _y;
                                      }));
        e           = (g->edits) + _vec_l;
    } while (0);
    g->n_packet_bytes += n_packet_bytes;
    return e;
}
static inline __attribute__((__always_inline__)) void *
pg_get_edit_group(pg_stream_t *s, u32 group_index)
{
    pg_edit_group_t *g = pg_stream_get_group(s, group_index);
    return g->edits;
}
static inline __attribute__((__always_inline__)) uword
pg_edit_group_n_bytes(pg_stream_t *s, u32 group_index)
{
    pg_edit_group_t *g;
    uword n_bytes = 0;
    for (g = s->edit_groups + group_index;
         g < ((s->edit_groups) + ((s->edit_groups) ? (((vec_header_t *) (s->edit_groups) - 1)->len) : 0)); g++)
        n_bytes += g->n_packet_bytes;
    return n_bytes;
}
static inline __attribute__((__always_inline__)) void
pg_free_edit_group(pg_stream_t *s)
{
    uword i            = ((s->edit_groups) ? (((vec_header_t *) (s->edit_groups) - 1)->len) : 0) - 1;
    pg_edit_group_t *g = pg_stream_get_group(s, i);
    pg_edit_group_free(g);
    memset(g, 0, sizeof(g[0]));
    (((vec_header_t *) (s->edit_groups) - 1)->len) = i;
}
typedef struct {
    volatile u32 *lockp;
    u32 hw_if_index, sw_if_index;
    u32 id;
    pcap_main_t pcap_main;
    u8 *pcap_file_name;
} pg_interface_t;
typedef struct {
    unformat_function_t *unformat_edit;
} pg_node_t;
typedef struct pg_main_t {
    pg_stream_t *streams;
    uword **enabled_streams;
    uword *stream_index_by_name;
    pg_interface_t *interfaces;
    uword *if_index_by_if_id;
    pg_node_t *nodes;
} pg_main_t;
extern pg_main_t pg_main;
extern vlib_node_registration_t pg_input_node;
vlib_node_function_t pg_input, pg_output;
void pg_stream_del(pg_main_t *pg, uword index);
void pg_stream_add(pg_main_t *pg, pg_stream_t *s_init);
void pg_stream_enable_disable(pg_main_t *pg, pg_stream_t *s, int is_enable);
u32 pg_interface_add_or_get(pg_main_t *pg, uword stream_index);
static inline __attribute__((__always_inline__)) pg_node_t *
pg_get_node(uword node_index)
{
    pg_main_t *pg = &pg_main;
    do {
        _Static_assert(0 == 0 || ((0 % sizeof(pg->nodes[0])) == 0) || ((sizeof(pg->nodes[0]) % 0) == 0),
                       "vector validate aligned on incorrectly sized object");
        word _vec_i = (node_index);
        word _vec_l = ((pg->nodes) ? (((vec_header_t *) (pg->nodes) - 1)->len) : 0);
        if (_vec_i >= _vec_l) {
            do {
                word _vec_n = (1 + (_vec_i - _vec_l));
                word _vec_l = (((pg->nodes)) ? (((vec_header_t *) ((pg->nodes)) - 1)->len) : 0);
                (pg->nodes) =
                    _vec_resize_inline(((pg->nodes)), _vec_n, (_vec_l + _vec_n) * sizeof(((pg->nodes))[0]), ((0)), ({
                                           __typeof__((__alignof__((((pg->nodes)))[0]))) _x =
                                               ((__alignof__((((pg->nodes)))[0])));
                                           __typeof__((((0)))) _y = ((((0))));
                                           _x > _y ? _x : _y;
                                       }));
            } while (0);
            memset((pg->nodes) + _vec_l, 0, (1 + (_vec_i - _vec_l)) * sizeof((pg->nodes)[0]));
        }
    } while (0);
    return pg->nodes + node_index;
}
void pg_edit_group_get_fixed_packet_data(pg_stream_t *s, u32 group_index, void *fixed_packet_data,
                                         void *fixed_packet_data_mask);
void pg_enable_disable(u32 stream_index, int is_enable);
typedef struct {
    u32 hw_if_index;
    u32 dev_instance;
    u8 is_enabled;
    u8 *pcap_file_name;
    u32 count;
} pg_capture_args_t;
clib_error_t *pg_capture(pg_capture_args_t *a);
typedef struct {
    vlib_buffer_t buffer;
    u32 buffer_index;
} pg_output_trace_t;
typedef enum {
    ETHERNET_TYPE_LLC_LENGTH                 = 0x600,
    ETHERNET_TYPE_XNS_IDP                    = 0x600,
    ETHERNET_TYPE_IP4                        = 0x800,
    ETHERNET_TYPE_ARP                        = 0x806,
    ETHERNET_TYPE_VINES_IP                   = 0x0BAD,
    ETHERNET_TYPE_VINES_LOOPBACK             = 0x0BAE,
    ETHERNET_TYPE_VINES_ECHO                 = 0x0BAF,
    ETHERNET_TYPE_TRAIN                      = 0x1984,
    ETHERNET_TYPE_CDP                        = 0x2000,
    ETHERNET_TYPE_CGMP                       = 0x2001,
    ETHERNET_TYPE_SRP_CONTROL                = 0x2007,
    ETHERNET_TYPE_CENTRINO_PROMISC           = 0x2452,
    ETHERNET_TYPE_DECNET                     = 0x6000,
    ETHERNET_TYPE_DECNET_DUMP_LOAD           = 0x6001,
    ETHERNET_TYPE_DECNET_REMOTE_CONSOLE      = 0x6002,
    ETHERNET_TYPE_DECNET_ROUTE               = 0x6003,
    ETHERNET_TYPE_DEC_LAT                    = 0x6004,
    ETHERNET_TYPE_DEC_DIAGNOSTIC             = 0x6005,
    ETHERNET_TYPE_DEC_CUSTOMER               = 0x6006,
    ETHERNET_TYPE_DEC_SCA                    = 0x6007,
    ETHERNET_TYPE_TRANSPARENT_BRIDGING       = 0x6558,
    ETHERNET_TYPE_RAW_FRAME_RELAY            = 0x6559,
    ETHERNET_TYPE_REVERSE_ARP                = 0x8035,
    ETHERNET_TYPE_DEC_LAN_BRIDGE             = 0x8038,
    ETHERNET_TYPE_DEC_ETHERNET_ENCRYPTION    = 0x803D,
    ETHERNET_TYPE_DEC_LAN_TRAFFIC_MONITOR    = 0x803F,
    ETHERNET_TYPE_DEC_LAST                   = 0x8041,
    ETHERNET_TYPE_APPLETALK                  = 0x809B,
    ETHERNET_TYPE_IBM_SNA                    = 0x80D5,
    ETHERNET_TYPE_APPLETALK_AARP             = 0x80F3,
    ETHERNET_TYPE_WELLFLEET_COMPRESSION      = 0x80FF,
    ETHERNET_TYPE_VLAN                       = 0x8100,
    ETHERNET_TYPE_IPX                        = 0x8137,
    ETHERNET_TYPE_SNMP                       = 0x814C,
    ETHERNET_TYPE_CABLETRON_ISMP             = 0x81FD,
    ETHERNET_TYPE_CABLETRON_ISMP_TBFLOOD     = 0x81FF,
    ETHERNET_TYPE_IP6                        = 0x86DD,
    ETHERNET_TYPE_ATOMIC                     = 0x86DF,
    ETHERNET_TYPE_TCP_IP_COMPRESSION         = 0x876B,
    ETHERNET_TYPE_IP_AUTONOMOUS_SYSTEMS      = 0x876C,
    ETHERNET_TYPE_SECURE_DATA                = 0x876D,
    ETHERNET_TYPE_MAC_CONTROL                = 0x8808,
    ETHERNET_TYPE_SLOW_PROTOCOLS             = 0x8809,
    ETHERNET_TYPE_PPP                        = 0x880B,
    ETHERNET_TYPE_MPLS                       = 0x8847,
    ETHERNET_TYPE_MPLS_UPSTREAM_ASSIGNED     = 0x8848,
    ETHERNET_TYPE_PPPOE_DISCOVERY            = 0x8863,
    ETHERNET_TYPE_PPPOE_SESSION              = 0x8864,
    ETHERNET_TYPE_INTEL_ANS                  = 0x886D,
    ETHERNET_TYPE_MICROSOFT_NLB_HEARTBEAT    = 0x886F,
    ETHERNET_TYPE_CDMA_2000                  = 0x8881,
    ETHERNET_TYPE_802_1X_AUTHENTICATION      = 0x888e,
    ETHERNET_TYPE_PROFINET                   = 0x8892,
    ETHERNET_TYPE_HYPERSCSI                  = 0x889a,
    ETHERNET_TYPE_AOE                        = 0x88a2,
    ETHERNET_TYPE_DOT1AD                     = 0x88a8,
    ETHERNET_TYPE_BRDWALK                    = 0x88AE,
    ETHERNET_TYPE_802_OUI_EXTENDED           = 0x88B7,
    ETHERNET_TYPE_802_11I_PRE_AUTHENTICATION = 0x88c7,
    ETHERNET_TYPE_802_1_LLDP                 = 0x88cc,
    ETHERNET_TYPE_DOT1AH                     = 0x88e7,
    ETHERNET_TYPE_NSH                        = 0x894f,
    ETHERNET_TYPE_LOOPBACK                   = 0x9000,
    ETHERNET_TYPE_RTNET_MAC                  = 0x9021,
    ETHERNET_TYPE_RTNET_CONFIG               = 0x9022,
    ETHERNET_TYPE_VLAN_9100                  = 0x9100,
    ETHERNET_TYPE_VLAN_9200                  = 0x9200,
    ETHERNET_TYPE_PGLAN                      = 0x9999,
    ETHERNET_TYPE_SRP_ISIS                   = 0xFEFE,
    ETHERNET_TYPE_RESERVED                   = 0xFFFF,
} ethernet_type_t;
typedef struct {
    u8 dst_address[6];
    u8 src_address[6];
    u16 type;
} ethernet_header_t;
static inline __attribute__((__always_inline__)) uword
ethernet_address_cast(u8 *a)
{
    return (a[0] >> 0) & 1;
}
static inline __attribute__((__always_inline__)) int
ethernet_address_is_broadcast(u8 *a)
{
    return (((struct { u32 _data __attribute__((packed)); } *) (a))->_data) == 0xffffffff &&
           (((struct { u16 _data __attribute__((packed)); } *) (a + 4))->_data) == 0xffff;
}
static inline __attribute__((__always_inline__)) uword
ethernet_address_is_locally_administered(u8 *a)
{
    return (a[0] >> 1) & 1;
}
static inline __attribute__((__always_inline__)) void
ethernet_address_set_locally_administered(u8 *a)
{
    a[0] |= 1 << 1;
}
static inline __attribute__((__always_inline__)) int
eh_dst_addr_to_rx_ctype(ethernet_header_t *eh)
{
    if (__builtin_expect((ethernet_address_cast(eh->dst_address) == 0), 1)) {
        return VNET_INTERFACE_COUNTER_RX_UNICAST;
    } else if (ethernet_address_is_broadcast(eh->dst_address)) {
        return VNET_INTERFACE_COUNTER_RX_BROADCAST;
    } else {
        return VNET_INTERFACE_COUNTER_RX_MULTICAST;
    }
}
static inline __attribute__((__always_inline__)) int
eh_dst_addr_to_tx_ctype(ethernet_header_t *eh)
{
    if (__builtin_expect((ethernet_address_cast(eh->dst_address) == 0), 1)) {
        return VNET_INTERFACE_COUNTER_TX_UNICAST;
    } else if (ethernet_address_is_broadcast(eh->dst_address)) {
        return VNET_INTERFACE_COUNTER_TX_BROADCAST;
    } else {
        return VNET_INTERFACE_COUNTER_TX_MULTICAST;
    }
}
typedef struct {
    u16 priority_cfi_and_id;
    u16 type;
} ethernet_vlan_header_t;
static inline __attribute__((__always_inline__)) void
ethernet_vlan_header_set_priority_net_order(ethernet_vlan_header_t *h, u8 prio)
{
    u8 *bytes = (u8 *) (&h->priority_cfi_and_id);
    bytes[0] &= 0x1f;
    bytes[0] |= (prio & 0x7) << 5;
}
static inline __attribute__((__always_inline__)) u8
ethernet_vlan_header_get_priority_net_order(ethernet_vlan_header_t *h)
{
    u8 *bytes = (u8 *) (&h->priority_cfi_and_id);
    return (bytes[0] >> 5);
}
typedef struct {
    u16 type;
    u16 priority_cfi_and_id;
} ethernet_vlan_header_tv_t;
typedef struct {
    u8 b_dst_address[6];
    u8 b_src_address[6];
    u16 b_type;
    u16 priority_dei_id;
    u16 i_type;
    u32 priority_dei_uca_res_sid;
} ethernet_pbb_header_t;
typedef struct {
    u8 b_dst_address[6];
    u8 b_src_address[6];
    u16 b_type;
    u16 priority_dei_id;
    u16 i_type;
    u32 priority_dei_uca_res_sid;
} __attribute__((packed)) ethernet_pbb_header_packed_t;
typedef enum {
    VNET_DEVICE_INPUT_NEXT_IP4_NCS_INPUT,
    VNET_DEVICE_INPUT_NEXT_IP4_INPUT,
    VNET_DEVICE_INPUT_NEXT_IP6_INPUT,
    VNET_DEVICE_INPUT_NEXT_MPLS_INPUT,
    VNET_DEVICE_INPUT_NEXT_ETHERNET_INPUT,
    VNET_DEVICE_INPUT_NEXT_DROP,
    VNET_DEVICE_INPUT_N_NEXT_NODES,
} vnet_device_input_next_t;
typedef struct {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    u64 aggregate_rx_packets;
} vnet_device_per_worker_data_t;
typedef struct {
    vnet_device_per_worker_data_t *workers;
    uword first_worker_thread_index;
    uword last_worker_thread_index;
    uword next_worker_thread_index;
} vnet_device_main_t;
typedef struct {
    u32 hw_if_index;
    u32 dev_instance;
    u16 queue_id;
    vnet_hw_interface_rx_mode mode;
    u32 interrupt_pending;
} vnet_device_and_queue_t;
typedef struct {
    vnet_device_and_queue_t *devices_and_queues;
    vlib_node_state_t enabled_node_state;
} vnet_device_input_runtime_t;
extern vnet_device_main_t vnet_device_main;
extern vlib_node_registration_t device_input_node;
extern const u32 device_input_next_node_advance[];
extern const u32 device_input_next_node_flags[];
static inline void
vnet_hw_interface_set_input_node(vnet_main_t *vnm, u32 hw_if_index, u32 node_index)
{
    vnet_hw_interface_t *hw = vnet_get_hw_interface(vnm, hw_if_index);
    hw->input_node_index    = node_index;
}
void vnet_hw_interface_assign_rx_thread(vnet_main_t *vnm, u32 hw_if_index, u16 queue_id, uword thread_index);
int vnet_hw_interface_unassign_rx_thread(vnet_main_t *vnm, u32 hw_if_index, u16 queue_id);
int vnet_hw_interface_set_rx_mode(vnet_main_t *vnm, u32 hw_if_index, u16 queue_id, vnet_hw_interface_rx_mode mode);
int vnet_hw_interface_get_rx_mode(vnet_main_t *vnm, u32 hw_if_index, u16 queue_id, vnet_hw_interface_rx_mode *mode);
static inline u64
vnet_get_aggregate_rx_packets(void)
{
    vnet_device_main_t *vdm = &vnet_device_main;
    u64 sum                 = 0;
    vnet_device_per_worker_data_t *pwd;
    for (pwd = (vdm->workers);
         pwd < ((vdm->workers) + ((vdm->workers) ? (((vec_header_t *) (vdm->workers) - 1)->len) : 0)); pwd++)
        sum += pwd->aggregate_rx_packets;
    return sum;
}
static inline void
vnet_device_increment_rx_packets(u32 thread_index, u64 count)
{
    vnet_device_main_t *vdm = &vnet_device_main;
    vnet_device_per_worker_data_t *pwd;
    pwd = ({
        do {
            if ((0 > 0) && !((thread_index) < ((vdm->workers) ? (((vec_header_t *) (vdm->workers) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/devices/devices.h",
                            (uword) 115, ((char *) __FUNCTION__), "(thread_index) < vec_len (vdm->workers)");
            }
        } while (0);
        (vdm->workers) + (thread_index);
    });
    pwd->aggregate_rx_packets += count;
}
static inline __attribute__((__always_inline__)) vnet_device_and_queue_t *
vnet_get_device_and_queue(vlib_main_t *vm, vlib_node_runtime_t *node)
{
    vnet_device_input_runtime_t *rt = (void *) node->runtime_data;
    return rt->devices_and_queues;
}
static inline __attribute__((__always_inline__)) uword
vnet_get_device_input_thread_index(vnet_main_t *vnm, u32 hw_if_index, u16 queue_id)
{
    vnet_hw_interface_t *hw = vnet_get_hw_interface(vnm, hw_if_index);
    do {
        if ((0 > 0) && !(queue_id < ((hw->input_node_thread_index_by_queue) ?
                                         (((vec_header_t *) (hw->input_node_thread_index_by_queue) - 1)->len) :
                                         0))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/devices/devices.h", (uword) 131,
                        ((char *) __FUNCTION__), "queue_id < vec_len (hw->input_node_thread_index_by_queue)");
        }
    } while (0);
    return hw->input_node_thread_index_by_queue[queue_id];
}
static inline __attribute__((__always_inline__)) void
vnet_device_input_set_interrupt_pending(vnet_main_t *vnm, u32 hw_if_index, u16 queue_id)
{
    vlib_main_t *vm;
    vnet_hw_interface_t *hw;
    vnet_device_input_runtime_t *rt;
    vnet_device_and_queue_t *dq;
    uword idx;
    hw                    = vnet_get_hw_interface(vnm, hw_if_index);
    idx                   = vnet_get_device_input_thread_index(vnm, hw_if_index, queue_id);
    vm                    = vlib_mains[idx];
    rt                    = vlib_node_get_runtime_data(vm, hw->input_node_index);
    idx                   = hw->dq_runtime_index_by_queue[queue_id];
    dq                    = ({
        do {
            if ((0 > 0) &&
                !((idx) < ((rt->devices_and_queues) ? (((vec_header_t *) (rt->devices_and_queues) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/devices/devices.h",
                            (uword) 150, ((char *) __FUNCTION__), "(idx) < vec_len (rt->devices_and_queues)");
            }
        } while (0);
        (rt->devices_and_queues) + (idx);
    });
    dq->interrupt_pending = 1;
    vlib_node_set_interrupt_pending(vm, hw->input_node_index);
}
typedef struct _vnet_feature_arc_registration {
    struct _vnet_feature_arc_registration *next;
    char *arc_name;
    char **start_nodes;
    int n_start_nodes;
    u8 feature_arc_index;
    u8 *arc_index_ptr;
} vnet_feature_arc_registration_t;
typedef clib_error_t *(vnet_feature_enable_disable_function_t)(u32 sw_if_index, int enable_disable);
typedef struct _vnet_feature_registration {
    struct _vnet_feature_registration *next, *next_in_arc;
    char *arc_name;
    char *node_name;
    u32 *feature_index_ptr;
    u32 feature_index;
    char **runs_before;
    char **runs_after;
    vnet_feature_enable_disable_function_t *enable_disable_cb;
} vnet_feature_registration_t;
typedef struct vnet_feature_config_main_t_ {
    vnet_config_main_t config_main;
    u32 *config_index_by_sw_if_index;
} vnet_feature_config_main_t;
typedef struct {
    vnet_feature_arc_registration_t *next_arc;
    uword **arc_index_by_name;
    vnet_feature_registration_t *next_feature;
    vnet_feature_registration_t **next_feature_by_arc;
    uword **next_feature_by_name;
    vnet_feature_config_main_t *feature_config_mains;
    char ***feature_nodes;
    uword **sw_if_index_has_features;
    i16 **feature_count_by_sw_if_index;
    u8 device_input_feature_arc_index;
    vlib_main_t *vlib_main;
    vnet_main_t *vnet_main;
} vnet_feature_main_t;
extern vnet_feature_main_t feature_main;
void vnet_config_update_feature_count(vnet_feature_main_t *fm, u8 arc, u32 sw_if_index, int is_add);
u32 vnet_get_feature_index(u8 arc, const char *s);
u8 vnet_get_feature_arc_index(const char *s);
vnet_feature_registration_t *vnet_get_feature_reg(const char *arc_name, const char *node_name);
int vnet_feature_enable_disable_with_index(u8 arc_index, u32 feature_index, u32 sw_if_index, int enable_disable,
                                           void *feature_config, u32 n_feature_config_bytes);
int vnet_feature_enable_disable(const char *arc_name, const char *node_name, u32 sw_if_index, int enable_disable,
                                void *feature_config, u32 n_feature_config_bytes);
static inline vnet_feature_config_main_t *
vnet_get_feature_arc_config_main(u8 arc_index)
{
    vnet_feature_main_t *fm = &feature_main;
    if (arc_index == (u8) ~0)
        return 0;
    return &fm->feature_config_mains[arc_index];
}
static inline __attribute__((__always_inline__)) vnet_feature_config_main_t *
vnet_feature_get_config_main(u16 arc)
{
    vnet_feature_main_t *fm = &feature_main;
    return &fm->feature_config_mains[arc];
}
static inline __attribute__((__always_inline__)) int
vnet_have_features(u8 arc, u32 sw_if_index)
{
    vnet_feature_main_t *fm = &feature_main;
    return clib_bitmap_get(fm->sw_if_index_has_features[arc], sw_if_index);
}
static inline __attribute__((__always_inline__)) u32
vnet_get_feature_config_index(u8 arc, u32 sw_if_index)
{
    vnet_feature_main_t *fm        = &feature_main;
    vnet_feature_config_main_t *cm = &fm->feature_config_mains[arc];
    return (({
        do {
            if ((0 > 0) && !((sw_if_index) < ((cm->config_index_by_sw_if_index) ?
                                                  (((vec_header_t *) (cm->config_index_by_sw_if_index) - 1)->len) :
                                                  0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/feature/feature.h",
                            (uword) 203, ((char *) __FUNCTION__),
                            "(sw_if_index) < vec_len (cm->config_index_by_sw_if_index)");
            }
        } while (0);
        (cm->config_index_by_sw_if_index) + (sw_if_index);
    }))[0];
}
static inline __attribute__((__always_inline__)) void *
vnet_feature_arc_start_with_data(u8 arc, u32 sw_if_index, u32 *next, vlib_buffer_t *b, u32 n_data_bytes)
{
    vnet_feature_main_t *fm = &feature_main;
    vnet_feature_config_main_t *cm;
    cm = &fm->feature_config_mains[arc];
    if (__builtin_expect((vnet_have_features(arc, sw_if_index)), 0)) {
        ((vnet_buffer_opaque_t *) (b)->opaque)->feature_arc_index = arc;
        b->current_config_index                                   = (({
            do {
                if ((0 > 0) && !((sw_if_index) < ((cm->config_index_by_sw_if_index) ?
                                                      (((vec_header_t *) (cm->config_index_by_sw_if_index) - 1)->len) :
                                                      0))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vnet/feature/feature.h",
                                (uword) 218, ((char *) __FUNCTION__),
                                "(sw_if_index) < vec_len (cm->config_index_by_sw_if_index)");
                }
            } while (0);
            (cm->config_index_by_sw_if_index) + (sw_if_index);
        }))[0];
        return vnet_get_config_data(&cm->config_main, &b->current_config_index, next, n_data_bytes);
    }
    return 0;
}
static inline __attribute__((__always_inline__)) void
vnet_feature_arc_start(u8 arc, u32 sw_if_index, u32 *next0, vlib_buffer_t *b0)
{
    vnet_feature_arc_start_with_data(arc, sw_if_index, next0, b0, 0);
}
static inline __attribute__((__always_inline__)) void *
vnet_feature_next_with_data(u32 *next0, vlib_buffer_t *b0, u32 n_data_bytes)
{
    vnet_feature_main_t *fm        = &feature_main;
    u8 arc                         = ((vnet_buffer_opaque_t *) (b0)->opaque)->feature_arc_index;
    vnet_feature_config_main_t *cm = &fm->feature_config_mains[arc];
    return vnet_get_config_data(&cm->config_main, &b0->current_config_index, next0, n_data_bytes);
}
static inline __attribute__((__always_inline__)) void
vnet_feature_next(u32 *next0, vlib_buffer_t *b0)
{
    vnet_feature_next_with_data(next0, b0, 0);
}
static inline __attribute__((__always_inline__)) int
vnet_device_input_have_features(u32 sw_if_index)
{
    vnet_feature_main_t *fm = &feature_main;
    return vnet_have_features(fm->device_input_feature_arc_index, sw_if_index);
}
static inline __attribute__((__always_inline__)) void
vnet_feature_start_device_input_x1(u32 sw_if_index, u32 *next0, vlib_buffer_t *b0)
{
    vnet_feature_main_t *fm = &feature_main;
    vnet_feature_config_main_t *cm;
    u8 feature_arc_index = fm->device_input_feature_arc_index;
    cm                   = &fm->feature_config_mains[feature_arc_index];
    if (__builtin_expect((clib_bitmap_get(fm->sw_if_index_has_features[feature_arc_index], sw_if_index)), 0)) {
        u16 adv;
        adv = device_input_next_node_advance[*next0];
        vlib_buffer_advance(b0, -adv);
        ((vnet_buffer_opaque_t *) (b0)->opaque)->feature_arc_index = feature_arc_index;
        b0->current_config_index                                   = (({
            do {
                if ((0 > 0) && !((sw_if_index) < ((cm->config_index_by_sw_if_index) ?
                                                      (((vec_header_t *) (cm->config_index_by_sw_if_index) - 1)->len) :
                                                      0))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vnet/feature/feature.h",
                                (uword) 282, ((char *) __FUNCTION__),
                                "(sw_if_index) < vec_len (cm->config_index_by_sw_if_index)");
                }
            } while (0);
            (cm->config_index_by_sw_if_index) + (sw_if_index);
        }))[0];
        vnet_get_config_data(&cm->config_main, &b0->current_config_index, next0, 0);
    }
}
static inline __attribute__((__always_inline__)) void
vnet_feature_start_device_input_x2(u32 sw_if_index, u32 *next0, u32 *next1, vlib_buffer_t *b0, vlib_buffer_t *b1)
{
    vnet_feature_main_t *fm = &feature_main;
    vnet_feature_config_main_t *cm;
    u8 feature_arc_index = fm->device_input_feature_arc_index;
    cm                   = &fm->feature_config_mains[feature_arc_index];
    if (__builtin_expect((clib_bitmap_get(fm->sw_if_index_has_features[feature_arc_index], sw_if_index)), 0)) {
        u16 adv;
        adv = device_input_next_node_advance[*next0];
        vlib_buffer_advance(b0, -adv);
        adv = device_input_next_node_advance[*next1];
        vlib_buffer_advance(b1, -adv);
        ((vnet_buffer_opaque_t *) (b0)->opaque)->feature_arc_index = feature_arc_index;
        ((vnet_buffer_opaque_t *) (b1)->opaque)->feature_arc_index = feature_arc_index;
        b0->current_config_index                                   = (({
            do {
                if ((0 > 0) && !((sw_if_index) < ((cm->config_index_by_sw_if_index) ?
                                                      (((vec_header_t *) (cm->config_index_by_sw_if_index) - 1)->len) :
                                                      0))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vnet/feature/feature.h",
                                (uword) 318, ((char *) __FUNCTION__),
                                "(sw_if_index) < vec_len (cm->config_index_by_sw_if_index)");
                }
            } while (0);
            (cm->config_index_by_sw_if_index) + (sw_if_index);
        }))[0];
        b1->current_config_index                                   = b0->current_config_index;
        vnet_get_config_data(&cm->config_main, &b0->current_config_index, next0, 0);
        vnet_get_config_data(&cm->config_main, &b1->current_config_index, next1, 0);
    }
}
static inline __attribute__((__always_inline__)) void
vnet_feature_start_device_input_x4(u32 sw_if_index, u32 *next0, u32 *next1, u32 *next2, u32 *next3, vlib_buffer_t *b0,
                                   vlib_buffer_t *b1, vlib_buffer_t *b2, vlib_buffer_t *b3)
{
    vnet_feature_main_t *fm = &feature_main;
    vnet_feature_config_main_t *cm;
    u8 feature_arc_index = fm->device_input_feature_arc_index;
    cm                   = &fm->feature_config_mains[feature_arc_index];
    if (__builtin_expect((clib_bitmap_get(fm->sw_if_index_has_features[feature_arc_index], sw_if_index)), 0)) {
        u16 adv;
        adv = device_input_next_node_advance[*next0];
        vlib_buffer_advance(b0, -adv);
        adv = device_input_next_node_advance[*next1];
        vlib_buffer_advance(b1, -adv);
        adv = device_input_next_node_advance[*next2];
        vlib_buffer_advance(b2, -adv);
        adv = device_input_next_node_advance[*next3];
        vlib_buffer_advance(b3, -adv);
        ((vnet_buffer_opaque_t *) (b0)->opaque)->feature_arc_index = feature_arc_index;
        ((vnet_buffer_opaque_t *) (b1)->opaque)->feature_arc_index = feature_arc_index;
        ((vnet_buffer_opaque_t *) (b2)->opaque)->feature_arc_index = feature_arc_index;
        ((vnet_buffer_opaque_t *) (b3)->opaque)->feature_arc_index = feature_arc_index;
        b0->current_config_index                                   = (({
            do {
                if ((0 > 0) && !((sw_if_index) < ((cm->config_index_by_sw_if_index) ?
                                                      (((vec_header_t *) (cm->config_index_by_sw_if_index) - 1)->len) :
                                                      0))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vnet/feature/feature.h",
                                (uword) 370, ((char *) __FUNCTION__),
                                "(sw_if_index) < vec_len (cm->config_index_by_sw_if_index)");
                }
            } while (0);
            (cm->config_index_by_sw_if_index) + (sw_if_index);
        }))[0];
        b1->current_config_index                                   = b0->current_config_index;
        b2->current_config_index                                   = b0->current_config_index;
        b3->current_config_index                                   = b0->current_config_index;
        vnet_get_config_data(&cm->config_main, &b0->current_config_index, next0, 0);
        vnet_get_config_data(&cm->config_main, &b1->current_config_index, next1, 0);
        vnet_get_config_data(&cm->config_main, &b2->current_config_index, next2, 0);
        vnet_get_config_data(&cm->config_main, &b3->current_config_index, next3, 0);
    }
}
clib_error_t *vnet_feature_arc_init(vlib_main_t *vm, vnet_config_main_t *vcm, char **feature_start_nodes,
                                    int num_feature_start_nodes, vnet_feature_registration_t *first_reg,
                                    char ***feature_nodes);
void vnet_interface_features_show(vlib_main_t *vm, u32 sw_if_index, int verbose);
static inline __attribute__((__always_inline__)) u64
ethernet_mac_address_u64(const u8 *a)
{
    return (((u64) a[0] << (u64)(5 * 8)) | ((u64) a[1] << (u64)(4 * 8)) | ((u64) a[2] << (u64)(3 * 8)) |
            ((u64) a[3] << (u64)(2 * 8)) | ((u64) a[4] << (u64)(1 * 8)) | ((u64) a[5] << (u64)(0 * 8)));
}
static inline __attribute__((__always_inline__)) void
ethernet_mac_address_from_u64(u64 u, u8 *a)
{
    i8 ii;
    for (ii = 5; ii >= 0; ii--) {
        a[ii] = u & 0xFF;
        u     = u >> 8;
    }
}
static inline int
ethernet_mac_address_is_multicast_u64(u64 a)
{
    return (a & (1ULL << (5 * 8))) != 0;
}
static inline int
ethernet_mac_address_is_zero(const u8 *mac)
{
    return ((*((u32 *) mac) == 0) && (*((u16 *) (mac + 4)) == 0));
}
static inline __attribute__((__always_inline__)) int
ethernet_frame_is_tagged(u16 type)
{
    if ((type == ETHERNET_TYPE_VLAN) || (type == ETHERNET_TYPE_DOT1AD) || (type == ETHERNET_TYPE_VLAN_9100) ||
        (type == ETHERNET_TYPE_VLAN_9200))
        return 1;
    return 0;
}
static inline __attribute__((__always_inline__)) int
ethernet_frame_is_any_tagged_x2(u16 type0, u16 type1)
{
    return ethernet_frame_is_tagged(type0) || ethernet_frame_is_tagged(type1);
}
static inline __attribute__((__always_inline__)) int
ethernet_frame_is_any_tagged_x4(u16 type0, u16 type1, u16 type2, u16 type3)
{
    return ethernet_frame_is_tagged(type0) || ethernet_frame_is_tagged(type1) || ethernet_frame_is_tagged(type2) ||
           ethernet_frame_is_tagged(type3);
}
typedef struct {
    ethernet_header_t ethernet;
    ethernet_vlan_header_t vlan[2];
} ethernet_max_header_t;
struct vnet_hw_interface_t;
typedef u32(ethernet_flag_change_function_t)(vnet_main_t *vnm, struct vnet_hw_interface_t *hi, u32 flags);
typedef struct ethernet_interface {
    ethernet_flag_change_function_t *flag_change;
    u32 driver_instance;
    u8 address[6];
} ethernet_interface_t;
extern vnet_hw_interface_class_t ethernet_hw_interface_class;
typedef struct {
    char *name;
    ethernet_type_t type;
    u32 node_index;
    u32 next_index;
} ethernet_type_info_t;
typedef enum {
    ETHERNET_ERROR_NONE,
    ETHERNET_ERROR_BAD_LLC_LENGTH,
    ETHERNET_ERROR_UNKNOWN_TYPE,
    ETHERNET_ERROR_UNKNOWN_VLAN,
    ETHERNET_ERROR_L3_MAC_MISMATCH,
    ETHERNET_ERROR_DOWN,
    ETHERNET_N_ERROR,
} ethernet_error_t;
typedef struct {
    u32 sw_if_index;
    u32 flags;
} subint_config_t;
static inline __attribute__((__always_inline__)) u32
eth_create_valid_subint_match_flags(u32 num_tags)
{
    return (1 << 4) | (1 << num_tags);
}
typedef struct {
    subint_config_t untagged_subint;
    subint_config_t default_subint;
    u16 dot1q_vlans;
    u16 dot1ad_vlans;
} main_intf_t;
typedef struct {
    subint_config_t single_tag_subint;
    subint_config_t inner_any_subint;
    u32 qinqs;
} vlan_intf_t;
typedef struct {
    vlan_intf_t vlans[(1 << 12)];
} vlan_table_t;
typedef struct {
    subint_config_t subint;
} qinq_intf_t;
typedef struct {
    qinq_intf_t vlans[(1 << 12)];
} qinq_table_t;
typedef struct {
    u16 *input_next_by_type;
    u32 *sparse_index_by_input_next_index;
    u32 input_next_ip4;
    u32 input_next_ip6;
    u32 input_next_mpls;
} next_by_ethertype_t;
typedef struct {
    vlib_main_t *vlib_main;
    next_by_ethertype_t l3_next;
    u32 l2_next;
    u32 redirect_l3;
    u32 redirect_l3_next;
    ethernet_interface_t *interfaces;
    ethernet_type_info_t *type_infos;
    uword *type_info_by_name, *type_info_by_type;
    main_intf_t *main_intfs;
    vlan_table_t *vlan_pool;
    qinq_table_t *qinq_pool;
    int format_ethernet_address_16bit;
    u8 next_by_ethertype_register_called;
    u8 output_feature_arc_index;
    uword *bm_loopback_instances;
} ethernet_main_t;
extern ethernet_main_t ethernet_main;
static inline __attribute__((__always_inline__)) ethernet_type_info_t *
ethernet_get_type_info(ethernet_main_t *em, ethernet_type_t type)
{
    uword *p = _hash_get((em->type_info_by_type), (uword)(type));
    return p ? ({
        do {
            if ((0 > 0) && !((p[0]) < ((em->type_infos) ? (((vec_header_t *) (em->type_infos) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ethernet/ethernet.h",
                            (uword) 326, ((char *) __FUNCTION__), "(p[0]) < vec_len (em->type_infos)");
            }
        } while (0);
        (em->type_infos) + (p[0]);
    }) :
               0;
}
ethernet_interface_t *ethernet_get_interface(ethernet_main_t *em, u32 hw_if_index);
clib_error_t *ethernet_register_interface(vnet_main_t *vnm, u32 dev_class_index, u32 dev_instance, u8 *address,
                                          u32 *hw_if_index_return, ethernet_flag_change_function_t flag_change);
void ethernet_delete_interface(vnet_main_t *vnm, u32 hw_if_index);
void ethernet_register_input_type(vlib_main_t *vm, ethernet_type_t type, u32 node_index);
void ethernet_register_l2_input(vlib_main_t *vm, u32 node_index);
void ethernet_register_l3_redirect(vlib_main_t *vm, u32 node_index);
u8 *format_mac_address(u8 *s, va_list *args);
u8 *format_ethernet_address(u8 *s, va_list *args);
u8 *format_ethernet_type(u8 *s, va_list *args);
u8 *format_ethernet_vlan_tci(u8 *s, va_list *va);
u8 *format_ethernet_header(u8 *s, va_list *args);
u8 *format_ethernet_header_with_length(u8 *s, va_list *args);
uword unformat_ethernet_address(unformat_input_t *input, va_list *args);
uword unformat_mac_address(unformat_input_t *input, va_list *args);
uword unformat_ethernet_type_host_byte_order(unformat_input_t *input, va_list *args);
uword unformat_ethernet_type_net_byte_order(unformat_input_t *input, va_list *args);
uword unformat_ethernet_header(unformat_input_t *input, va_list *args);
uword unformat_ethernet_interface(unformat_input_t *input, va_list *args);
uword unformat_pg_ethernet_header(unformat_input_t *input, va_list *args);
static inline __attribute__((__always_inline__)) void
ethernet_setup_node(vlib_main_t *vm, u32 node_index)
{
    vlib_node_t *n     = vlib_get_node(vm, node_index);
    pg_node_t *pn      = pg_get_node(node_index);
    n->format_buffer   = format_ethernet_header_with_length;
    n->unformat_buffer = unformat_ethernet_header;
    pn->unformat_edit  = unformat_pg_ethernet_header;
}
static inline __attribute__((__always_inline__)) ethernet_header_t *
ethernet_buffer_get_header(vlib_buffer_t *b)
{
    return (void *) (b->data + ((vnet_buffer_opaque_t *) (b)->opaque)->l2_hdr_offset);
}
ethernet_main_t *ethernet_get_main(vlib_main_t *vm);
u32 ethernet_set_flags(vnet_main_t *vnm, u32 hw_if_index, u32 flags);
void ethernet_sw_interface_set_l2_mode(vnet_main_t *vnm, u32 sw_if_index, u32 l2);
void ethernet_sw_interface_set_l2_mode_noport(vnet_main_t *vnm, u32 sw_if_index, u32 l2);
void ethernet_set_rx_redirect(vnet_main_t *vnm, vnet_hw_interface_t *hi, u32 enable);
clib_error_t *next_by_ethertype_init(next_by_ethertype_t *l3_next);
clib_error_t *next_by_ethertype_register(next_by_ethertype_t *l3_next, u32 ethertype, u32 next_index);
int vnet_create_loopback_interface(u32 *sw_if_indexp, u8 *mac_address, u8 is_specified, u32 user_instance);
int vnet_delete_loopback_interface(u32 sw_if_index);
int vnet_delete_sub_interface(u32 sw_if_index);
static inline __attribute__((__always_inline__)) void
eth_vlan_table_lookups(ethernet_main_t *em, vnet_main_t *vnm, u32 port_sw_if_index0, u16 first_ethertype, u16 outer_id,
                       u16 inner_id, vnet_hw_interface_t **hi, main_intf_t **main_intf, vlan_intf_t **vlan_intf,
                       qinq_intf_t **qinq_intf)
{
    vlan_table_t *vlan_table;
    qinq_table_t *qinq_table;
    u32 vlan_table_id;
    *hi           = vnet_get_sup_hw_interface(vnm, port_sw_if_index0);
    *main_intf    = ({
        do {
            if ((0 > 0) &&
                !(((*hi)->hw_if_index) < ((em->main_intfs) ? (((vec_header_t *) (em->main_intfs) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ethernet/ethernet.h",
                            (uword) 484, ((char *) __FUNCTION__), "((*hi)->hw_if_index) < vec_len (em->main_intfs)");
            }
        } while (0);
        (em->main_intfs) + ((*hi)->hw_if_index);
    });
    vlan_table_id = (first_ethertype == ETHERNET_TYPE_DOT1AD) ? (*main_intf)->dot1ad_vlans : (*main_intf)->dot1q_vlans;
    vlan_table    = ({
        do {
            if ((0 > 0) && !((vlan_table_id) < ((em->vlan_pool) ? (((vec_header_t *) (em->vlan_pool) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ethernet/ethernet.h",
                            (uword) 491, ((char *) __FUNCTION__), "(vlan_table_id) < vec_len (em->vlan_pool)");
            }
        } while (0);
        (em->vlan_pool) + (vlan_table_id);
    });
    *vlan_intf    = &vlan_table->vlans[outer_id];
    qinq_table    = ({
        do {
            if ((0 > 0) &&
                !(((*vlan_intf)->qinqs) < ((em->qinq_pool) ? (((vec_header_t *) (em->qinq_pool) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ethernet/ethernet.h",
                            (uword) 494, ((char *) __FUNCTION__), "((*vlan_intf)->qinqs) < vec_len (em->qinq_pool)");
            }
        } while (0);
        (em->qinq_pool) + ((*vlan_intf)->qinqs);
    });
    *qinq_intf    = &qinq_table->vlans[inner_id];
}
static inline __attribute__((__always_inline__)) u32
eth_identify_subint(vnet_hw_interface_t *hi, vlib_buffer_t *b0, u32 match_flags, main_intf_t *main_intf,
                    vlan_intf_t *vlan_intf, qinq_intf_t *qinq_intf, u32 *new_sw_if_index, u8 *error0, u32 *is_l2)
{
    subint_config_t *subint;
    subint = &qinq_intf->subint;
    if ((subint->flags & match_flags) == match_flags)
        goto matched;
    subint = &vlan_intf->inner_any_subint;
    if ((subint->flags & match_flags) == match_flags)
        goto matched;
    subint = &vlan_intf->single_tag_subint;
    if ((subint->flags & match_flags) == match_flags)
        goto matched;
    subint = &main_intf->default_subint;
    if ((subint->flags & match_flags) == match_flags)
        goto matched;
    subint = &main_intf->untagged_subint;
    if ((subint->flags & match_flags) == match_flags)
        goto matched;
    *new_sw_if_index = ~0;
    *error0          = ETHERNET_ERROR_UNKNOWN_VLAN;
    *is_l2           = 0;
    return 0;
matched:
    *new_sw_if_index = subint->sw_if_index;
    *is_l2           = subint->flags & (1 << 5);
    return 1;
}
static inline __attribute__((__always_inline__)) u32
eth_mac_equal(const u8 *mac1, const u8 *mac2)
{
    return (*((u32 *) (mac1 + 0)) == *((u32 *) (mac2 + 0)) && *((u32 *) (mac1 + 2)) == *((u32 *) (mac2 + 2)));
}
static inline __attribute__((__always_inline__)) ethernet_main_t *
vnet_get_ethernet_main(void)
{
    return &ethernet_main;
}
void vnet_register_ip4_arp_resolution_event(vnet_main_t *vnm, void *address_arg, uword node_index, uword type_opaque,
                                            uword data);
int vnet_add_del_ip4_arp_change_event(vnet_main_t *vnm, void *data_callback, u32 pid, void *address_arg,
                                      uword node_index, uword type_opaque, uword data, int is_add);
void wc_arp_set_publisher_node(uword inode_index, uword event_type);
void ethernet_arp_change_mac(u32 sw_if_index);
void ethernet_ndp_change_mac(u32 sw_if_index);
void arp_update_adjacency(vnet_main_t *vnm, u32 sw_if_index, u32 ai);
void ethernet_update_adjacency(vnet_main_t *vnm, u32 sw_if_index, u32 ai);
u8 *ethernet_build_rewrite(vnet_main_t *vnm, u32 sw_if_index, vnet_link_t link_type, const void *dst_address);
const u8 *ethernet_ip4_mcast_dst_addr(void);
const u8 *ethernet_ip6_mcast_dst_addr(void);
extern vlib_node_registration_t ethernet_input_node;
typedef struct {
    u32 sw_if_index;
    u32 ip4;
    u8 mac[6];
} wc_arp_report_t;
struct iovec {
    void *iov_base;
    size_t iov_len;
};
enum __socket_type {
    SOCK_STREAM    = 1,
    SOCK_DGRAM     = 2,
    SOCK_RAW       = 3,
    SOCK_RDM       = 4,
    SOCK_SEQPACKET = 5,
    SOCK_DCCP      = 6,
    SOCK_PACKET    = 10,
    SOCK_CLOEXEC   = 02000000,
    SOCK_NONBLOCK  = 00004000
};
typedef unsigned short int sa_family_t;
struct sockaddr {
    sa_family_t sa_family;
    char sa_data[14];
};
struct sockaddr_storage {
    sa_family_t ss_family;
    char __ss_padding[(128 - (sizeof(unsigned short int)) - sizeof(unsigned long int))];
    unsigned long int __ss_align;
};
enum {
    MSG_OOB          = 0x01,
    MSG_PEEK         = 0x02,
    MSG_DONTROUTE    = 0x04,
    MSG_CTRUNC       = 0x08,
    MSG_PROXY        = 0x10,
    MSG_TRUNC        = 0x20,
    MSG_DONTWAIT     = 0x40,
    MSG_EOR          = 0x80,
    MSG_WAITALL      = 0x100,
    MSG_FIN          = 0x200,
    MSG_SYN          = 0x400,
    MSG_CONFIRM      = 0x800,
    MSG_RST          = 0x1000,
    MSG_ERRQUEUE     = 0x2000,
    MSG_NOSIGNAL     = 0x4000,
    MSG_MORE         = 0x8000,
    MSG_WAITFORONE   = 0x10000,
    MSG_BATCH        = 0x40000,
    MSG_ZEROCOPY     = 0x4000000,
    MSG_FASTOPEN     = 0x20000000,
    MSG_CMSG_CLOEXEC = 0x40000000
};
struct msghdr {
    void *msg_name;
    socklen_t msg_namelen;
    struct iovec *msg_iov;
    size_t msg_iovlen;
    void *msg_control;
    size_t msg_controllen;
    int msg_flags;
};
struct cmsghdr {
    size_t cmsg_len;
    int cmsg_level;
    int cmsg_type;
    __extension__ unsigned char __cmsg_data[];
};
extern struct cmsghdr *__cmsg_nxthdr(struct msghdr *__mhdr, struct cmsghdr *__cmsg)
    __attribute__((__nothrow__, __leaf__));
enum { SCM_RIGHTS = 0x01 };
struct linger {
    int l_onoff;
    int l_linger;
};
struct osockaddr {
    unsigned short int sa_family;
    unsigned char sa_data[14];
};
enum { SHUT_RD = 0, SHUT_WR, SHUT_RDWR };
extern int socket(int __domain, int __type, int __protocol) __attribute__((__nothrow__, __leaf__));
extern int socketpair(int __domain, int __type, int __protocol, int __fds[2]) __attribute__((__nothrow__, __leaf__));
extern int bind(int __fd, const struct sockaddr *__addr, socklen_t __len) __attribute__((__nothrow__, __leaf__));
extern int getsockname(int __fd, struct sockaddr *__restrict __addr, socklen_t *__restrict __len)
    __attribute__((__nothrow__, __leaf__));
extern int connect(int __fd, const struct sockaddr *__addr, socklen_t __len);
extern int getpeername(int __fd, struct sockaddr *__restrict __addr, socklen_t *__restrict __len)
    __attribute__((__nothrow__, __leaf__));
extern ssize_t send(int __fd, const void *__buf, size_t __n, int __flags);
extern ssize_t recv(int __fd, void *__buf, size_t __n, int __flags);
extern ssize_t sendto(int __fd, const void *__buf, size_t __n, int __flags, const struct sockaddr *__addr,
                      socklen_t __addr_len);
extern ssize_t recvfrom(int __fd, void *__restrict __buf, size_t __n, int __flags, struct sockaddr *__restrict __addr,
                        socklen_t *__restrict __addr_len);
extern ssize_t sendmsg(int __fd, const struct msghdr *__message, int __flags);
extern ssize_t recvmsg(int __fd, struct msghdr *__message, int __flags);
extern int getsockopt(int __fd, int __level, int __optname, void *__restrict __optval, socklen_t *__restrict __optlen)
    __attribute__((__nothrow__, __leaf__));
extern int setsockopt(int __fd, int __level, int __optname, const void *__optval, socklen_t __optlen)
    __attribute__((__nothrow__, __leaf__));
extern int listen(int __fd, int __n) __attribute__((__nothrow__, __leaf__));
extern int accept(int __fd, struct sockaddr *__restrict __addr, socklen_t *__restrict __addr_len);
extern int shutdown(int __fd, int __how) __attribute__((__nothrow__, __leaf__));
extern int sockatmark(int __fd) __attribute__((__nothrow__, __leaf__));
extern int isfdtype(int __fd, int __fdtype) __attribute__((__nothrow__, __leaf__));
typedef uint32_t in_addr_t;
struct in_addr {
    in_addr_t s_addr;
};
struct ip_opts {
    struct in_addr ip_dst;
    char ip_opts[40];
};
struct ip_mreqn {
    struct in_addr imr_multiaddr;
    struct in_addr imr_address;
    int imr_ifindex;
};
struct in_pktinfo {
    int ipi_ifindex;
    struct in_addr ipi_spec_dst;
    struct in_addr ipi_addr;
};
enum {
    IPPROTO_IP      = 0,
    IPPROTO_ICMP    = 1,
    IPPROTO_IGMP    = 2,
    IPPROTO_IPIP    = 4,
    IPPROTO_TCP     = 6,
    IPPROTO_EGP     = 8,
    IPPROTO_PUP     = 12,
    IPPROTO_UDP     = 17,
    IPPROTO_IDP     = 22,
    IPPROTO_TP      = 29,
    IPPROTO_DCCP    = 33,
    IPPROTO_IPV6    = 41,
    IPPROTO_RSVP    = 46,
    IPPROTO_GRE     = 47,
    IPPROTO_ESP     = 50,
    IPPROTO_AH      = 51,
    IPPROTO_MTP     = 92,
    IPPROTO_BEETPH  = 94,
    IPPROTO_ENCAP   = 98,
    IPPROTO_PIM     = 103,
    IPPROTO_COMP    = 108,
    IPPROTO_SCTP    = 132,
    IPPROTO_UDPLITE = 136,
    IPPROTO_MPLS    = 137,
    IPPROTO_RAW     = 255,
    IPPROTO_MAX
};
enum {
    IPPROTO_HOPOPTS  = 0,
    IPPROTO_ROUTING  = 43,
    IPPROTO_FRAGMENT = 44,
    IPPROTO_ICMPV6   = 58,
    IPPROTO_NONE     = 59,
    IPPROTO_DSTOPTS  = 60,
    IPPROTO_MH       = 135
};
typedef uint16_t in_port_t;
enum {
    IPPORT_ECHO         = 7,
    IPPORT_DISCARD      = 9,
    IPPORT_SYSTAT       = 11,
    IPPORT_DAYTIME      = 13,
    IPPORT_NETSTAT      = 15,
    IPPORT_FTP          = 21,
    IPPORT_TELNET       = 23,
    IPPORT_SMTP         = 25,
    IPPORT_TIMESERVER   = 37,
    IPPORT_NAMESERVER   = 42,
    IPPORT_WHOIS        = 43,
    IPPORT_MTP          = 57,
    IPPORT_TFTP         = 69,
    IPPORT_RJE          = 77,
    IPPORT_FINGER       = 79,
    IPPORT_TTYLINK      = 87,
    IPPORT_SUPDUP       = 95,
    IPPORT_EXECSERVER   = 512,
    IPPORT_LOGINSERVER  = 513,
    IPPORT_CMDSERVER    = 514,
    IPPORT_EFSSERVER    = 520,
    IPPORT_BIFFUDP      = 512,
    IPPORT_WHOSERVER    = 513,
    IPPORT_ROUTESERVER  = 520,
    IPPORT_RESERVED     = 1024,
    IPPORT_USERRESERVED = 5000
};
struct in6_addr {
    union {
        uint8_t __u6_addr8[16];
        uint16_t __u6_addr16[8];
        uint32_t __u6_addr32[4];
    } __in6_u;
};
extern const struct in6_addr in6addr_any;
extern const struct in6_addr in6addr_loopback;
struct sockaddr_in {
    sa_family_t sin_family;
    in_port_t sin_port;
    struct in_addr sin_addr;
    unsigned char
        sin_zero[sizeof(struct sockaddr) - (sizeof(unsigned short int)) - sizeof(in_port_t) - sizeof(struct in_addr)];
};
struct sockaddr_in6 {
    sa_family_t sin6_family;
    in_port_t sin6_port;
    uint32_t sin6_flowinfo;
    struct in6_addr sin6_addr;
    uint32_t sin6_scope_id;
};
struct ip_mreq {
    struct in_addr imr_multiaddr;
    struct in_addr imr_interface;
};
struct ip_mreq_source {
    struct in_addr imr_multiaddr;
    struct in_addr imr_interface;
    struct in_addr imr_sourceaddr;
};
struct ipv6_mreq {
    struct in6_addr ipv6mr_multiaddr;
    unsigned int ipv6mr_interface;
};
struct group_req {
    uint32_t gr_interface;
    struct sockaddr_storage gr_group;
};
struct group_source_req {
    uint32_t gsr_interface;
    struct sockaddr_storage gsr_group;
    struct sockaddr_storage gsr_source;
};
struct ip_msfilter {
    struct in_addr imsf_multiaddr;
    struct in_addr imsf_interface;
    uint32_t imsf_fmode;
    uint32_t imsf_numsrc;
    struct in_addr imsf_slist[1];
};
struct group_filter {
    uint32_t gf_interface;
    struct sockaddr_storage gf_group;
    uint32_t gf_fmode;
    uint32_t gf_numsrc;
    struct sockaddr_storage gf_slist[1];
};
extern uint32_t ntohl(uint32_t __netlong) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern uint16_t ntohs(uint16_t __netshort) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern uint32_t htonl(uint32_t __hostlong) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern uint16_t htons(uint16_t __hostshort) __attribute__((__nothrow__, __leaf__)) __attribute__((__const__));
extern int bindresvport(int __sockfd, struct sockaddr_in *__sock_in) __attribute__((__nothrow__, __leaf__));
extern int bindresvport6(int __sockfd, struct sockaddr_in6 *__sock_in) __attribute__((__nothrow__, __leaf__));
typedef struct _socket_t {
    i32 fd;
    char *config;
    u32 flags;
    u8 *tx_buffer;
    u8 *rx_buffer;
    struct sockaddr_in peer;
    pid_t pid;
    uid_t uid;
    gid_t gid;
    clib_error_t *(*write_func)(struct _socket_t *sock);
    clib_error_t *(*read_func)(struct _socket_t *sock, int min_bytes);
    clib_error_t *(*close_func)(struct _socket_t *sock);
    clib_error_t *(*recvmsg_func)(struct _socket_t *s, void *msg, int msglen, int fds[], int num_fds);
    clib_error_t *(*sendmsg_func)(struct _socket_t *s, void *msg, int msglen, int fds[], int num_fds);
    uword private_data;
} clib_socket_t;
clib_error_t *clib_socket_init(clib_socket_t *socket);
clib_error_t *clib_socket_accept(clib_socket_t *server, clib_socket_t *client);
static inline __attribute__((__always_inline__)) uword
clib_socket_is_server(clib_socket_t *sock)
{
    return (sock->flags & (1 << 0)) != 0;
}
static inline __attribute__((__always_inline__)) uword
clib_socket_is_client(clib_socket_t *s)
{
    return !clib_socket_is_server(s);
}
static inline __attribute__((__always_inline__)) uword
clib_socket_is_connected(clib_socket_t *sock)
{
    return sock->fd > 0;
}
static inline __attribute__((__always_inline__)) int
clib_socket_rx_end_of_file(clib_socket_t *s)
{
    return s->flags & (1 << 2);
}
static inline __attribute__((__always_inline__)) void *
clib_socket_tx_add(clib_socket_t *s, int n_bytes)
{
    u8 *result;
    do {
        word _vec_n  = (n_bytes);
        word _vec_l  = ((s->tx_buffer) ? (((vec_header_t *) (s->tx_buffer) - 1)->len) : 0);
        s->tx_buffer = _vec_resize_inline((s->tx_buffer), _vec_n, (_vec_l + _vec_n) * sizeof((s->tx_buffer)[0]), (0), ({
                                              __typeof__((__alignof__(((s->tx_buffer))[0]))) _x =
                                                  ((__alignof__(((s->tx_buffer))[0])));
                                              __typeof__(((0))) _y = (((0)));
                                              _x > _y ? _x : _y;
                                          }));
        result       = (s->tx_buffer) + _vec_l;
    } while (0);
    return result;
}
static inline __attribute__((__always_inline__)) void
clib_socket_tx_add_va_formatted(clib_socket_t *s, char *fmt, va_list *va)
{
    s->tx_buffer = va_format(s->tx_buffer, fmt, va);
}
static inline __attribute__((__always_inline__)) clib_error_t *
clib_socket_tx(clib_socket_t *s)
{
    return s->write_func(s);
}
static inline __attribute__((__always_inline__)) clib_error_t *
clib_socket_rx(clib_socket_t *s, int n_bytes)
{
    return s->read_func(s, n_bytes);
}
static inline __attribute__((__always_inline__)) clib_error_t *
clib_socket_sendmsg(clib_socket_t *s, void *msg, int msglen, int fds[], int num_fds)
{
    return s->sendmsg_func(s, msg, msglen, fds, num_fds);
}
static inline __attribute__((__always_inline__)) clib_error_t *
clib_socket_recvmsg(clib_socket_t *s, void *msg, int msglen, int fds[], int num_fds)
{
    return s->recvmsg_func(s, msg, msglen, fds, num_fds);
}
static inline __attribute__((__always_inline__)) void
clib_socket_free(clib_socket_t *s)
{
    do {
        if (s->tx_buffer) {
            clib_mem_free(vec_header((s->tx_buffer), (0)));
            s->tx_buffer = 0;
        }
    } while (0);
    do {
        if (s->rx_buffer) {
            clib_mem_free(vec_header((s->rx_buffer), (0)));
            s->rx_buffer = 0;
        }
    } while (0);
    if (clib_mem_is_heap_object(s->config))
        do {
            if (s->config) {
                clib_mem_free(vec_header((s->config), (0)));
                s->config = 0;
            }
        } while (0);
    memset(s, 0, sizeof(s[0]));
}
static inline __attribute__((__always_inline__)) clib_error_t *
clib_socket_close(clib_socket_t *sock)
{
    clib_error_t *err;
    err = (*sock->close_func)(sock);
    return err;
}
void clib_socket_tx_add_formatted(clib_socket_t *s, char *fmt, ...);
typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;
struct termios {
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_line;
    cc_t c_cc[32];
    speed_t c_ispeed;
    speed_t c_ospeed;
};
extern speed_t cfgetospeed(const struct termios *__termios_p) __attribute__((__nothrow__, __leaf__));
extern speed_t cfgetispeed(const struct termios *__termios_p) __attribute__((__nothrow__, __leaf__));
extern int cfsetospeed(struct termios *__termios_p, speed_t __speed) __attribute__((__nothrow__, __leaf__));
extern int cfsetispeed(struct termios *__termios_p, speed_t __speed) __attribute__((__nothrow__, __leaf__));
extern int cfsetspeed(struct termios *__termios_p, speed_t __speed) __attribute__((__nothrow__, __leaf__));
extern int tcgetattr(int __fd, struct termios *__termios_p) __attribute__((__nothrow__, __leaf__));
extern int tcsetattr(int __fd, int __optional_actions, const struct termios *__termios_p)
    __attribute__((__nothrow__, __leaf__));
extern void cfmakeraw(struct termios *__termios_p) __attribute__((__nothrow__, __leaf__));
extern int tcsendbreak(int __fd, int __duration) __attribute__((__nothrow__, __leaf__));
extern int tcdrain(int __fd);
extern int tcflush(int __fd, int __queue_selector) __attribute__((__nothrow__, __leaf__));
extern int tcflow(int __fd, int __action) __attribute__((__nothrow__, __leaf__));
extern __pid_t tcgetsid(int __fd) __attribute__((__nothrow__, __leaf__));
struct clib_file;
typedef clib_error_t *(clib_file_function_t)(struct clib_file *f);
typedef struct clib_file {
    u32 file_descriptor;
    u32 flags;
    u32 polling_thread_index;
    uword private_data;
    clib_file_function_t *read_function, *write_function, *error_function;
    u8 *description;
    u64 read_events;
    u64 write_events;
    u64 error_events;
} clib_file_t;
typedef enum {
    UNIX_FILE_UPDATE_ADD,
    UNIX_FILE_UPDATE_MODIFY,
    UNIX_FILE_UPDATE_DELETE,
} clib_file_update_type_t;
typedef struct {
    clib_file_t *file_pool;
    void (*file_update)(clib_file_t *file, clib_file_update_type_t update_type);
} clib_file_main_t;
static inline __attribute__((__always_inline__)) uword
clib_file_add(clib_file_main_t *um, clib_file_t *template)
{
    clib_file_t *f;
    do {
        pool_header_t *_pool_p = pool_header(um->file_pool);
        uword _pool_l;
        _Static_assert(0 == 0 || ((0 % sizeof(um->file_pool[0])) == 0) || ((sizeof(um->file_pool[0]) % 0) == 0),
                       "Pool aligned alloc of incorrectly sized object");
        _pool_l = 0;
        if (um->file_pool)
            _pool_l = ((_pool_p->free_indices) ? (((vec_header_t *) (_pool_p->free_indices) - 1)->len) : 0);
        if (_pool_l > 0) {
            uword _pool_i        = _pool_p->free_indices[_pool_l - 1];
            (f)                  = (um->file_pool) + _pool_i;
            _pool_p->free_bitmap = clib_bitmap_andnoti_notrim(_pool_p->free_bitmap, _pool_i);
            (((vec_header_t *) (_pool_p->free_indices) - 1)->len) = _pool_l - 1;
        } else {
            if ((um->file_pool) && _pool_p->max_elts) {
                _clib_error(CLIB_ERROR_WARNING, ((char *) __FUNCTION__), 99, "can't expand fixed-size pool");
                os_out_of_memory();
            }
            um->file_pool =
                _vec_resize_inline(um->file_pool, 1,
                                   (((um->file_pool) ? (((vec_header_t *) (um->file_pool) - 1)->len) : 0) + 1) *
                                       sizeof(um->file_pool[0]),
                                   vec_aligned_header_bytes(sizeof(pool_header_t), sizeof(void *)), ({
                                       __typeof__((__alignof__((um->file_pool)[0]))) _x =
                                           ((__alignof__((um->file_pool)[0])));
                                       __typeof__(((0))) _y = (((0)));
                                       _x > _y ? _x : _y;
                                   }));
            f = ((um->file_pool) + ((um->file_pool) ? (((vec_header_t *) (um->file_pool) - 1)->len) : 0)) - 1;
        }
    } while (0);
    f[0]            = template[0];
    f->read_events  = 0;
    f->write_events = 0;
    f->error_events = 0;
    um->file_update(f, UNIX_FILE_UPDATE_ADD);
    return f - um->file_pool;
}
static inline __attribute__((__always_inline__)) void
clib_file_del(clib_file_main_t *um, clib_file_t *f)
{
    um->file_update(f, UNIX_FILE_UPDATE_DELETE);
    close(f->file_descriptor);
    f->file_descriptor = ~0;
    do {
        if (f->description) {
            clib_mem_free(vec_header((f->description), (0)));
            f->description = 0;
        }
    } while (0);
    do {
        pool_header_t *_pool_p = pool_header(um->file_pool);
        uword _pool_l          = (f) - (um->file_pool);
        do {
            if ((0 > 0) &&
                !(((f) >= (um->file_pool) &&
                   (f) < ((um->file_pool) + ((um->file_pool) ? (((vec_header_t *) (um->file_pool) - 1)->len) : 0))))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/file.h", (uword) 115,
                            ((char *) __FUNCTION__), "vec_is_member (um->file_pool, f)");
            }
        } while (0);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(um->file_pool);
                    uword _pool_i          = (f) - (um->file_pool);
                    (_pool_i < ((um->file_pool) ? (((vec_header_t *) (um->file_pool) - 1)->len) : 0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/file.h", (uword) 115,
                            ((char *) __FUNCTION__), "! pool_is_free (um->file_pool, f)");
            }
        } while (0);
        _pool_p->free_bitmap = clib_bitmap_ori_notrim(_pool_p->free_bitmap, _pool_l);
        if (_pool_p->max_elts) {
            do {
                if ((0 > 0) && !(_pool_l < _pool_p->max_elts)) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/file.h", (uword) 115,
                                ((char *) __FUNCTION__), "_pool_var(l) < _pool_var (p)->max_elts");
                }
            } while (0);
            _pool_p->free_indices[(((vec_header_t *) (_pool_p->free_indices) - 1)->len)] = _pool_l;
            (((vec_header_t *) (_pool_p->free_indices) - 1)->len) += 1;
        } else
            do {
                word _vec_l = ((_pool_p->free_indices) ? (((vec_header_t *) (_pool_p->free_indices) - 1)->len) : 0);
                _pool_p->free_indices           = _vec_resize_inline((_pool_p->free_indices), 1,
                                                           (_vec_l + 1) * sizeof((_pool_p->free_indices)[0]), (0), ({
                                                               __typeof__((__alignof__(((_pool_p->free_indices))[0])))
                                                                   _x = ((__alignof__(((_pool_p->free_indices))[0])));
                                                               __typeof__(((0))) _y = (((0)));
                                                               _x > _y ? _x : _y;
                                                           }));
                (_pool_p->free_indices)[_vec_l] = (_pool_l);
            } while (0);
    } while (0);
}
static inline __attribute__((__always_inline__)) void
clib_file_del_by_index(clib_file_main_t *um, uword index)
{
    clib_file_t *uf;
    uf = ({
        typeof(um->file_pool) _e = (um->file_pool) + (index);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(um->file_pool);
                    uword _pool_i          = (_e) - (um->file_pool);
                    (_pool_i < ((um->file_pool) ? (((vec_header_t *) (um->file_pool) - 1)->len) : 0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/file.h", (uword) 122,
                            ((char *) __FUNCTION__), "! pool_is_free (um->file_pool, _e)");
            }
        } while (0);
        _e;
    });
    clib_file_del(um, uf);
}
static inline __attribute__((__always_inline__)) void
clib_file_set_polling_thread(clib_file_main_t *um, uword index, u32 thread_index)
{
    clib_file_t *f = ({
        typeof(um->file_pool) _e = (um->file_pool) + (index);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(um->file_pool);
                    uword _pool_i          = (_e) - (um->file_pool);
                    (_pool_i < ((um->file_pool) ? (((vec_header_t *) (um->file_pool) - 1)->len) : 0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/file.h", (uword) 130,
                            ((char *) __FUNCTION__), "! pool_is_free (um->file_pool, _e)");
            }
        } while (0);
        _e;
    });
    um->file_update(f, UNIX_FILE_UPDATE_DELETE);
    f->polling_thread_index = thread_index;
    um->file_update(f, UNIX_FILE_UPDATE_ADD);
}
static inline __attribute__((__always_inline__)) uword
clib_file_set_data_available_to_write(clib_file_main_t *um, u32 clib_file_index, uword is_available)
{
    clib_file_t *uf     = ({
        typeof(um->file_pool) _e = (um->file_pool) + (clib_file_index);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(um->file_pool);
                    uword _pool_i          = (_e) - (um->file_pool);
                    (_pool_i < ((um->file_pool) ? (((vec_header_t *) (um->file_pool) - 1)->len) : 0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/file.h", (uword) 141,
                            ((char *) __FUNCTION__), "! pool_is_free (um->file_pool, _e)");
            }
        } while (0);
        _e;
    });
    uword was_available = (uf->flags & (1 << 0));
    if ((was_available != 0) != (is_available != 0)) {
        uf->flags ^= (1 << 0);
        um->file_update(uf, UNIX_FILE_UPDATE_MODIFY);
    }
    return was_available != 0;
}
static inline __attribute__((__always_inline__)) clib_file_t *
clib_file_get(clib_file_main_t *fm, u32 file_index)
{
    if (({
            pool_header_t *_pool_p = pool_header((fm->file_pool));
            uword _pool_i          = ((fm->file_pool) + (file_index)) - ((fm->file_pool));
            (_pool_i < (((fm->file_pool)) ? (((vec_header_t *) ((fm->file_pool)) - 1)->len) : 0)) ?
                clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                1;
        }))
        return 0;
    return ({
        typeof(fm->file_pool) _e = (fm->file_pool) + (file_index);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(fm->file_pool);
                    uword _pool_i          = (_e) - (fm->file_pool);
                    (_pool_i < ((fm->file_pool) ? (((vec_header_t *) (fm->file_pool) - 1)->len) : 0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/file.h", (uword) 156,
                            ((char *) __FUNCTION__), "! pool_is_free (fm->file_pool, _e)");
            }
        } while (0);
        _e;
    });
}
static inline __attribute__((__always_inline__)) clib_error_t *
clib_file_write(clib_file_t *f)
{
    f->write_events++;
    return f->write_function(f);
}
typedef struct {
    f64 time;
    clib_error_t *error;
} unix_error_history_t;
typedef struct {
    vlib_main_t *vlib_main;
    u32 flags;
    clib_socket_t cli_listen_socket;
    unix_error_history_t error_history[128];
    u32 error_history_index;
    u64 n_total_errors;
    u8 *startup_config_filename;
    u8 *runtime_dir;
    u8 *pidfile;
    volatile int unix_config_complete;
    u8 *log_filename;
    int log_fd;
    int cli_line_mode;
    u32 cli_history_limit;
    int cli_no_banner;
    u32 cli_pager_buffer_limit;
    int cli_no_pager;
    struct termios tio_stdin;
    int tio_isset;
    u32 poll_sleep_usec;
} unix_main_t;
extern unix_main_t unix_main;
extern clib_file_main_t file_main;
static inline __attribute__((__always_inline__)) void
unix_save_error(unix_main_t *um, clib_error_t *error)
{
    unix_error_history_t *eh = um->error_history + um->error_history_index;
    clib_error_free_vector(eh->error);
    eh->error = error;
    eh->time  = vlib_time_now(um->vlib_main);
    um->n_total_errors += 1;
    if (++um->error_history_index >= (sizeof(um->error_history) / sizeof(um->error_history[0])))
        um->error_history_index = 0;
}
int vlib_unix_main(int argc, char *argv[]);
clib_error_t *unix_physmem_init(vlib_main_t *vm);
void vlib_unix_cli_set_prompt(char *prompt);
static inline unix_main_t *
vlib_unix_get_main(void)
{
    return &unix_main;
}
static inline char *
vlib_unix_get_runtime_dir(void)
{
    return (char *) unix_main.runtime_dir;
}
extern u8 **vlib_thread_stacks;
clib_error_t *foreach_directory_file(char *dir_name, clib_error_t *(*f)(void *arg, u8 *path_name, u8 *file_name),
                                     void *arg, int scan_dirs);
clib_error_t *vlib_unix_recursive_mkdir(char *path);
clib_error_t *vlib_unix_validate_runtime_file(unix_main_t *um, const char *path, u8 **full_path);
struct stat {
    __dev_t st_dev;
    __ino_t st_ino;
    __nlink_t st_nlink;
    __mode_t st_mode;
    __uid_t st_uid;
    __gid_t st_gid;
    int __pad0;
    __dev_t st_rdev;
    __off_t st_size;
    __blksize_t st_blksize;
    __blkcnt_t st_blocks;
    struct timespec st_atim;
    struct timespec st_mtim;
    struct timespec st_ctim;
    __syscall_slong_t __glibc_reserved[3];
};
extern int stat(const char *__restrict __file, struct stat *__restrict __buf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int fstat(int __fd, struct stat *__buf) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int fstatat(int __fd, const char *__restrict __file, struct stat *__restrict __buf, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 3)));
extern int lstat(const char *__restrict __file, struct stat *__restrict __buf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1, 2)));
extern int chmod(const char *__file, __mode_t __mode) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int lchmod(const char *__file, __mode_t __mode) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int fchmod(int __fd, __mode_t __mode) __attribute__((__nothrow__, __leaf__));
extern int fchmodat(int __fd, const char *__file, __mode_t __mode, int __flag) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern __mode_t umask(__mode_t __mask) __attribute__((__nothrow__, __leaf__));
extern int mkdir(const char *__path, __mode_t __mode) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int mkdirat(int __fd, const char *__path, __mode_t __mode) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern int mknod(const char *__path, __mode_t __mode, __dev_t __dev) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int mknodat(int __fd, const char *__path, __mode_t __mode, __dev_t __dev) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern int mkfifo(const char *__path, __mode_t __mode) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
extern int mkfifoat(int __fd, const char *__path, __mode_t __mode) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2)));
extern int utimensat(int __fd, const char *__path, const struct timespec __times[2], int __flags)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2)));
extern int futimens(int __fd, const struct timespec __times[2]) __attribute__((__nothrow__, __leaf__));
extern int __fxstat(int __ver, int __fildes, struct stat *__stat_buf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(3)));
extern int __xstat(int __ver, const char *__filename, struct stat *__stat_buf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 3)));
extern int __lxstat(int __ver, const char *__filename, struct stat *__stat_buf) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(2, 3)));
extern int __fxstatat(int __ver, int __fildes, const char *__filename, struct stat *__stat_buf, int __flag)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 4)));
extern int __xmknod(int __ver, const char *__path, __mode_t __mode, __dev_t *__dev)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(2, 4)));
extern int __xmknodat(int __ver, int __fd, const char *__path, __mode_t __mode, __dev_t *__dev)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(3, 5)));
typedef struct {
    u8 default_disabled;
    const char version[32];
    const char version_required[32];
    const char *early_init;
    const char *description;
} __attribute__((packed)) vlib_plugin_registration_t;
typedef struct {
    u8 *name;
    u8 *filename;
    struct stat file_info;
    void *handle;
    vlib_plugin_registration_t *reg;
    char *version;
} plugin_info_t;
typedef struct {
    char *name;
    u8 is_disabled;
    u8 is_enabled;
    u8 skip_version_check;
} plugin_config_t;
typedef struct {
    plugin_info_t *plugin_info;
    uword *plugin_by_name_hash;
    u8 *plugin_path;
    u8 *plugin_name_filter;
    u8 *vat_plugin_path;
    u8 *vat_plugin_name_filter;
    u8 plugins_default_disable;
    plugin_config_t *configs;
    uword *config_index_by_name;
    vlib_main_t *vlib_main;
} plugin_main_t;
extern plugin_main_t vlib_plugin_main;
clib_error_t *vlib_plugin_config(vlib_main_t *vm, unformat_input_t *input);
int vlib_plugin_early_init(vlib_main_t *vm);
int vlib_load_new_plugins(plugin_main_t *pm, int from_early_init);
void *vlib_get_plugin_symbol(char *plugin_name, char *symbol_name);
u8 *vlib_get_vat_plugin_path(void);
u8 **clib_ptclosure_alloc(int n);
void clib_ptclosure_free(u8 **ptc);
void clib_ptclosure_copy(u8 **dst, u8 **src);
u8 **clib_ptclosure(u8 **orig);
format_function_t format_ip_protocol;
unformat_function_t unformat_ip_protocol;
format_function_t format_tcp_udp_port;
unformat_function_t unformat_tcp_udp_port;
typedef enum format_ip_adjacency_flags_t_ {
    FORMAT_IP_ADJACENCY_NONE,
    FORMAT_IP_ADJACENCY_BRIEF  = FORMAT_IP_ADJACENCY_NONE,
    FORMAT_IP_ADJACENCY_DETAIL = (1 << 0),
} format_ip_adjacency_flags_t;
format_function_t format_ip_adjacency;
format_function_t format_ip_adjacency_packet_data;
format_function_t format_ip46_address;
unformat_function_t unformat_ip46_address;
unformat_function_t unformat_ip4_address;
unformat_function_t unformat_ip4_address_and_mask;
format_function_t format_ip4_address;
format_function_t format_ip4_address_and_length;
format_function_t format_ip4_address_and_mask;
unformat_function_t unformat_ip4_header;
format_function_t format_ip4_header;
unformat_function_t unformat_ip4_match;
unformat_function_t unformat_pg_ip4_header;
unformat_function_t unformat_ip6_address;
unformat_function_t unformat_ip6_address_and_mask;
format_function_t format_ip6_address;
format_function_t format_ip6_address_and_length;
format_function_t format_ip6_address_and_mask;
unformat_function_t unformat_ip6_header;
format_function_t format_ip6_header;
unformat_function_t unformat_pg_ip6_header;
format_function_t format_tcp_header, format_udp_header, format_sctp_header;
unformat_function_t unformat_pg_tcp_header, unformat_pg_udp_header, unformat_pg_sctp_header;
typedef enum ip_protocol {
    IP_PROTOCOL_IP6_HOP_BY_HOP_OPTIONS  = 0,
    IP_PROTOCOL_ICMP                    = 1,
    IP_PROTOCOL_IGMP                    = 2,
    IP_PROTOCOL_GGP                     = 3,
    IP_PROTOCOL_IP_IN_IP                = 4,
    IP_PROTOCOL_ST                      = 5,
    IP_PROTOCOL_TCP                     = 6,
    IP_PROTOCOL_CBT                     = 7,
    IP_PROTOCOL_EGP                     = 8,
    IP_PROTOCOL_IGP                     = 9,
    IP_PROTOCOL_BBN_RCC_MON             = 10,
    IP_PROTOCOL_NVP_II                  = 11,
    IP_PROTOCOL_PUP                     = 12,
    IP_PROTOCOL_ARGUS                   = 13,
    IP_PROTOCOL_EMCON                   = 14,
    IP_PROTOCOL_XNET                    = 15,
    IP_PROTOCOL_CHAOS                   = 16,
    IP_PROTOCOL_UDP                     = 17,
    IP_PROTOCOL_MUX                     = 18,
    IP_PROTOCOL_DCN_MEAS                = 19,
    IP_PROTOCOL_HMP                     = 20,
    IP_PROTOCOL_PRM                     = 21,
    IP_PROTOCOL_XNS_IDP                 = 22,
    IP_PROTOCOL_TRUNK_1                 = 23,
    IP_PROTOCOL_TRUNK_2                 = 24,
    IP_PROTOCOL_LEAF_1                  = 25,
    IP_PROTOCOL_LEAF_2                  = 26,
    IP_PROTOCOL_RDP                     = 27,
    IP_PROTOCOL_IRTP                    = 28,
    IP_PROTOCOL_ISO_TP4                 = 29,
    IP_PROTOCOL_NETBLT                  = 30,
    IP_PROTOCOL_MFE_NSP                 = 31,
    IP_PROTOCOL_MERIT_INP               = 32,
    IP_PROTOCOL_SEP                     = 33,
    IP_PROTOCOL_3PC                     = 34,
    IP_PROTOCOL_IDPR                    = 35,
    IP_PROTOCOL_XTP                     = 36,
    IP_PROTOCOL_DDP                     = 37,
    IP_PROTOCOL_IDPR_CMTP               = 38,
    IP_PROTOCOL_TP                      = 39,
    IP_PROTOCOL_IL                      = 40,
    IP_PROTOCOL_IPV6                    = 41,
    IP_PROTOCOL_SDRP                    = 42,
    IP_PROTOCOL_IPV6_ROUTE              = 43,
    IP_PROTOCOL_IPV6_FRAGMENTATION      = 44,
    IP_PROTOCOL_IDRP                    = 45,
    IP_PROTOCOL_RSVP                    = 46,
    IP_PROTOCOL_GRE                     = 47,
    IP_PROTOCOL_MHRP                    = 48,
    IP_PROTOCOL_BNA                     = 49,
    IP_PROTOCOL_IPSEC_ESP               = 50,
    IP_PROTOCOL_IPSEC_AH                = 51,
    IP_PROTOCOL_I_NLSP                  = 52,
    IP_PROTOCOL_SWIPE                   = 53,
    IP_PROTOCOL_NARP                    = 54,
    IP_PROTOCOL_MOBILE                  = 55,
    IP_PROTOCOL_TLSP                    = 56,
    IP_PROTOCOL_SKIP                    = 57,
    IP_PROTOCOL_ICMP6                   = 58,
    IP_PROTOCOL_IP6_NONXT               = 59,
    IP_PROTOCOL_IP6_DESTINATION_OPTIONS = 60,
    IP_PROTOCOL_CFTP                    = 62,
    IP_PROTOCOL_SAT_EXPAK               = 64,
    IP_PROTOCOL_KRYPTOLAN               = 65,
    IP_PROTOCOL_RVD                     = 66,
    IP_PROTOCOL_IPPC                    = 67,
    IP_PROTOCOL_SAT_MON                 = 69,
    IP_PROTOCOL_VISA                    = 70,
    IP_PROTOCOL_IPCV                    = 71,
    IP_PROTOCOL_CPNX                    = 72,
    IP_PROTOCOL_CPHB                    = 73,
    IP_PROTOCOL_WSN                     = 74,
    IP_PROTOCOL_PVP                     = 75,
    IP_PROTOCOL_BR_SAT_MON              = 76,
    IP_PROTOCOL_SUN_ND                  = 77,
    IP_PROTOCOL_WB_MON                  = 78,
    IP_PROTOCOL_WB_EXPAK                = 79,
    IP_PROTOCOL_ISO_IP                  = 80,
    IP_PROTOCOL_VMTP                    = 81,
    IP_PROTOCOL_SECURE_VMTP             = 82,
    IP_PROTOCOL_VINES                   = 83,
    IP_PROTOCOL_TTP                     = 84,
    IP_PROTOCOL_NSFNET_IGP              = 85,
    IP_PROTOCOL_DGP                     = 86,
    IP_PROTOCOL_TCF                     = 87,
    IP_PROTOCOL_EIGRP                   = 88,
    IP_PROTOCOL_OSPF                    = 89,
    IP_PROTOCOL_SPRITE_RPC              = 90,
    IP_PROTOCOL_LARP                    = 91,
    IP_PROTOCOL_MTP                     = 92,
    IP_PROTOCOL_AX                      = 93,
    IP_PROTOCOL_IPIP                    = 94,
    IP_PROTOCOL_MICP                    = 95,
    IP_PROTOCOL_SCC_SP                  = 96,
    IP_PROTOCOL_ETHERIP                 = 97,
    IP_PROTOCOL_ENCAP                   = 98,
    IP_PROTOCOL_GMTP                    = 100,
    IP_PROTOCOL_IFMP                    = 101,
    IP_PROTOCOL_PNNI                    = 102,
    IP_PROTOCOL_PIM                     = 103,
    IP_PROTOCOL_ARIS                    = 104,
    IP_PROTOCOL_SCPS                    = 105,
    IP_PROTOCOL_QNX                     = 106,
    IP_PROTOCOL_A                       = 107,
    IP_PROTOCOL_IPCOMP                  = 108,
    IP_PROTOCOL_SNP                     = 109,
    IP_PROTOCOL_COMPAQ_PEER             = 110,
    IP_PROTOCOL_IPX_IN_IP               = 111,
    IP_PROTOCOL_VRRP                    = 112,
    IP_PROTOCOL_PGM                     = 113,
    IP_PROTOCOL_L2TP                    = 115,
    IP_PROTOCOL_DDX                     = 116,
    IP_PROTOCOL_IATP                    = 117,
    IP_PROTOCOL_STP                     = 118,
    IP_PROTOCOL_SRP                     = 119,
    IP_PROTOCOL_UTI                     = 120,
    IP_PROTOCOL_SMP                     = 121,
    IP_PROTOCOL_SM                      = 122,
    IP_PROTOCOL_PTP                     = 123,
    IP_PROTOCOL_ISIS                    = 124,
    IP_PROTOCOL_FIRE                    = 125,
    IP_PROTOCOL_CRTP                    = 126,
    IP_PROTOCOL_CRUDP                   = 127,
    IP_PROTOCOL_SSCOPMCE                = 128,
    IP_PROTOCOL_IPLT                    = 129,
    IP_PROTOCOL_SPS                     = 130,
    IP_PROTOCOL_PIPE                    = 131,
    IP_PROTOCOL_SCTP                    = 132,
    IP_PROTOCOL_FC                      = 133,
    IP_PROTOCOL_RSVP_E2E_IGNORE         = 134,
    IP_PROTOCOL_MOBILITY                = 135,
    IP_PROTOCOL_UDP_LITE                = 136,
    IP_PROTOCOL_MPLS_IN_IP              = 137,
    IP_PROTOCOL_VPP_FRAGMENTATION       = 0xfe,
    IP_PROTOCOL_RESERVED                = 255,
} ip_protocol_t;
typedef enum {
    IP_PORT_TCPMUX                  = 1,
    IP_PORT_COMPRESS_NET_MANAGEMENT = 2,
    IP_PORT_COMPRESS_NET            = 3,
    IP_PORT_RJE                     = 5,
    IP_PORT_ECHO                    = 7,
    IP_PORT_DISCARD                 = 9,
    IP_PORT_SYSTAT                  = 11,
    IP_PORT_DAYTIME                 = 13,
    IP_PORT_QOTD                    = 17,
    IP_PORT_MSP                     = 18,
    IP_PORT_CHARGEN                 = 19,
    IP_PORT_FTP_DATA                = 20,
    IP_PORT_FTP                     = 21,
    IP_PORT_SSH                     = 22,
    IP_PORT_TELNET                  = 23,
    IP_PORT_SMTP                    = 25,
    IP_PORT_NSW_FE                  = 27,
    IP_PORT_MSG_ICP                 = 29,
    IP_PORT_MSG_AUTH                = 31,
    IP_PORT_DSP                     = 33,
    IP_PORT_TIME                    = 37,
    IP_PORT_RAP                     = 38,
    IP_PORT_RLP                     = 39,
    IP_PORT_GRAPHICS                = 41,
    IP_PORT_NAME                    = 42,
    IP_PORT_NAMESERVER              = 42,
    IP_PORT_NICNAME                 = 43,
    IP_PORT_MPM_FLAGS               = 44,
    IP_PORT_MPM                     = 45,
    IP_PORT_MPM_SND                 = 46,
    IP_PORT_NI_FTP                  = 47,
    IP_PORT_AUDITD                  = 48,
    IP_PORT_TACACS                  = 49,
    IP_PORT_RE_MAIL_CK              = 50,
    IP_PORT_LA_MAINT                = 51,
    IP_PORT_XNS_TIME                = 52,
    IP_PORT_DNS                     = 53,
    IP_PORT_XNS_CH                  = 54,
    IP_PORT_ISI_GL                  = 55,
    IP_PORT_XNS_AUTH                = 56,
    IP_PORT_XNS_MAIL                = 58,
    IP_PORT_NI_MAIL                 = 61,
    IP_PORT_ACAS                    = 62,
    IP_PORT_WHOIS_PLUS_PLUS         = 63,
    IP_PORT_COVIA                   = 64,
    IP_PORT_TACACS_DS               = 65,
    IP_PORT_ORACLE_SQL_NET          = 66,
    IP_PORT_BOOTPS                  = 67,
    IP_PORT_BOOTPC                  = 68,
    IP_PORT_TFTP                    = 69,
    IP_PORT_GOPHER                  = 70,
    IP_PORT_NETRJS_1                = 71,
    IP_PORT_NETRJS_2                = 72,
    IP_PORT_NETRJS_3                = 73,
    IP_PORT_NETRJS_4                = 74,
    IP_PORT_DEOS                    = 76,
    IP_PORT_VETTCP                  = 78,
    IP_PORT_FINGER                  = 79,
    IP_PORT_WWW                     = 80,
    IP_PORT_HOSTS2_NS               = 81,
    IP_PORT_XFER                    = 82,
    IP_PORT_MIT_ML_DEV              = 83,
    IP_PORT_CTF                     = 84,
    IP_PORT_MIT_ML_DEV1             = 85,
    IP_PORT_MFCOBOL                 = 86,
    IP_PORT_KERBEROS                = 88,
    IP_PORT_SU_MIT_TG               = 89,
    IP_PORT_DNSIX                   = 90,
    IP_PORT_MIT_DOV                 = 91,
    IP_PORT_NPP                     = 92,
    IP_PORT_DCP                     = 93,
    IP_PORT_OBJCALL                 = 94,
    IP_PORT_SUPDUP                  = 95,
    IP_PORT_DIXIE                   = 96,
    IP_PORT_SWIFT_RVF               = 97,
    IP_PORT_TACNEWS                 = 98,
    IP_PORT_METAGRAM                = 99,
    IP_PORT_NEWACCT                 = 100,
    IP_PORT_HOSTNAME                = 101,
    IP_PORT_ISO_TSAP                = 102,
    IP_PORT_GPPITNP                 = 103,
    IP_PORT_ACR_NEMA                = 104,
    IP_PORT_CSO                     = 105,
    IP_PORT_CSNET_NS                = 105,
    IP_PORT_3COM_TSMUX              = 106,
    IP_PORT_RTELNET                 = 107,
    IP_PORT_SNAGAS                  = 108,
    IP_PORT_POP2                    = 109,
    IP_PORT_POP3                    = 110,
    IP_PORT_SUNRPC                  = 111,
    IP_PORT_MCIDAS                  = 112,
    IP_PORT_IDENT                   = 113,
    IP_PORT_SFTP                    = 115,
    IP_PORT_ANSANOTIFY              = 116,
    IP_PORT_UUCP_PATH               = 117,
    IP_PORT_SQLSERV                 = 118,
    IP_PORT_NNTP                    = 119,
    IP_PORT_CFDPTKT                 = 120,
    IP_PORT_ERPC                    = 121,
    IP_PORT_SMAKYNET                = 122,
    IP_PORT_NTP                     = 123,
    IP_PORT_ANSATRADER              = 124,
    IP_PORT_LOCUS_MAP               = 125,
    IP_PORT_NXEDIT                  = 126,
    IP_PORT_LOCUS_CON               = 127,
    IP_PORT_GSS_XLICEN              = 128,
    IP_PORT_PWDGEN                  = 129,
    IP_PORT_CISCO_FNA               = 130,
    IP_PORT_CISCO_TNA               = 131,
    IP_PORT_CISCO_SYS               = 132,
    IP_PORT_STATSRV                 = 133,
    IP_PORT_INGRES_NET              = 134,
    IP_PORT_EPMAP                   = 135,
    IP_PORT_PROFILE                 = 136,
    IP_PORT_NETBIOS_NS              = 137,
    IP_PORT_NETBIOS_DGM             = 138,
    IP_PORT_NETBIOS_SSN             = 139,
    IP_PORT_EMFIS_DATA              = 140,
    IP_PORT_EMFIS_CNTL              = 141,
    IP_PORT_BL_IDM                  = 142,
    IP_PORT_IMAP                    = 143,
    IP_PORT_UMA                     = 144,
    IP_PORT_UAAC                    = 145,
    IP_PORT_ISO_TP0                 = 146,
    IP_PORT_ISO_IP                  = 147,
    IP_PORT_JARGON                  = 148,
    IP_PORT_AED_512                 = 149,
    IP_PORT_SQL_NET                 = 150,
    IP_PORT_HEMS                    = 151,
    IP_PORT_BFTP                    = 152,
    IP_PORT_SGMP                    = 153,
    IP_PORT_NETSC_PROD              = 154,
    IP_PORT_NETSC_DEV               = 155,
    IP_PORT_SQLSRV                  = 156,
    IP_PORT_KNET_CMP                = 157,
    IP_PORT_PCMAIL_SRV              = 158,
    IP_PORT_NSS_ROUTING             = 159,
    IP_PORT_SGMP_TRAPS              = 160,
    IP_PORT_SNMP                    = 161,
    IP_PORT_SNMPTRAP                = 162,
    IP_PORT_CMIP_MAN                = 163,
    IP_PORT_CMIP_AGENT              = 164,
    IP_PORT_XNS_COURIER             = 165,
    IP_PORT_S_NET                   = 166,
    IP_PORT_NAMP                    = 167,
    IP_PORT_RSVD                    = 168,
    IP_PORT_SEND                    = 169,
    IP_PORT_PRINT_SRV               = 170,
    IP_PORT_MULTIPLEX               = 171,
    IP_PORT_CL1                     = 172,
    IP_PORT_XYPLEX_MUX              = 173,
    IP_PORT_MAILQ                   = 174,
    IP_PORT_VMNET                   = 175,
    IP_PORT_GENRAD_MUX              = 176,
    IP_PORT_XDMCP                   = 177,
    IP_PORT_NEXTSTEP                = 178,
    IP_PORT_BGP                     = 179,
    IP_PORT_RIS                     = 180,
    IP_PORT_UNIFY                   = 181,
    IP_PORT_AUDIT                   = 182,
    IP_PORT_OCBINDER                = 183,
    IP_PORT_OCSERVER                = 184,
    IP_PORT_REMOTE_KIS              = 185,
    IP_PORT_KIS                     = 186,
    IP_PORT_ACI                     = 187,
    IP_PORT_MUMPS                   = 188,
    IP_PORT_QFT                     = 189,
    IP_PORT_GACP                    = 190,
    IP_PORT_PROSPERO                = 191,
    IP_PORT_OSU_NMS                 = 192,
    IP_PORT_SRMP                    = 193,
    IP_PORT_IRC                     = 194,
    IP_PORT_DN6_NLM_AUD             = 195,
    IP_PORT_DN6_SMM_RED             = 196,
    IP_PORT_DLS                     = 197,
    IP_PORT_DLS_MON                 = 198,
    IP_PORT_SMUX                    = 199,
    IP_PORT_SRC                     = 200,
    IP_PORT_AT_RTMP                 = 201,
    IP_PORT_AT_NBP                  = 202,
    IP_PORT_AT_3                    = 203,
    IP_PORT_AT_ECHO                 = 204,
    IP_PORT_AT_5                    = 205,
    IP_PORT_AT_ZIS                  = 206,
    IP_PORT_AT_7                    = 207,
    IP_PORT_AT_8                    = 208,
    IP_PORT_QMTP                    = 209,
    IP_PORT_Z39_50                  = 210,
    IP_PORT_TI914CG                 = 211,
    IP_PORT_ANET                    = 212,
    IP_PORT_IPX                     = 213,
    IP_PORT_VMPWSCS                 = 214,
    IP_PORT_SOFTPC                  = 215,
    IP_PORT_CAILIC                  = 216,
    IP_PORT_DBASE                   = 217,
    IP_PORT_MPP                     = 218,
    IP_PORT_UARPS                   = 219,
    IP_PORT_IMAP3                   = 220,
    IP_PORT_FLN_SPX                 = 221,
    IP_PORT_RSH_SPX                 = 222,
    IP_PORT_CDC                     = 223,
    IP_PORT_MASQDIALER              = 224,
    IP_PORT_DIRECT                  = 242,
    IP_PORT_SUR_MEAS                = 243,
    IP_PORT_INBUSINESS              = 244,
    IP_PORT_LINK                    = 245,
    IP_PORT_DSP3270                 = 246,
    IP_PORT_SUBNTBCST_TFTP          = 247,
    IP_PORT_BHFHS                   = 248,
    IP_PORT_RAP1                    = 256,
    IP_PORT_SET                     = 257,
    IP_PORT_YAK_CHAT                = 258,
    IP_PORT_ESRO_GEN                = 259,
    IP_PORT_OPENPORT                = 260,
    IP_PORT_NSIIOPS                 = 261,
    IP_PORT_ARCISDMS                = 262,
    IP_PORT_HDAP                    = 263,
    IP_PORT_BGMP                    = 264,
    IP_PORT_X_BONE_CTL              = 265,
    IP_PORT_SST                     = 266,
    IP_PORT_TD_SERVICE              = 267,
    IP_PORT_TD_REPLICA              = 268,
    IP_PORT_HTTP_MGMT               = 280,
    IP_PORT_PERSONAL_LINK           = 281,
    IP_PORT_CABLEPORT_AX            = 282,
    IP_PORT_RESCAP                  = 283,
    IP_PORT_CORERJD                 = 284,
    IP_PORT_FXP                     = 286,
    IP_PORT_K_BLOCK                 = 287,
    IP_PORT_NOVASTORBAKCUP          = 308,
    IP_PORT_ENTRUSTTIME             = 309,
    IP_PORT_BHMDS                   = 310,
    IP_PORT_ASIP_WEBADMIN           = 311,
    IP_PORT_VSLMP                   = 312,
    IP_PORT_MAGENTA_LOGIC           = 313,
    IP_PORT_OPALIS_ROBOT            = 314,
    IP_PORT_DPSI                    = 315,
    IP_PORT_DECAUTH                 = 316,
    IP_PORT_ZANNET                  = 317,
    IP_PORT_PKIX_TIMESTAMP          = 318,
    IP_PORT_PTP_EVENT               = 319,
    IP_PORT_PTP_GENERAL             = 320,
    IP_PORT_PIP                     = 321,
    IP_PORT_RTSPS                   = 322,
    IP_PORT_TEXAR                   = 333,
    IP_PORT_PDAP                    = 344,
    IP_PORT_PAWSERV                 = 345,
    IP_PORT_ZSERV                   = 346,
    IP_PORT_FATSERV                 = 347,
    IP_PORT_CSI_SGWP                = 348,
    IP_PORT_MFTP                    = 349,
    IP_PORT_MATIP_TYPE_A            = 350,
    IP_PORT_MATIP_TYPE_B            = 351,
    IP_PORT_BHOETTY                 = 351,
    IP_PORT_DTAG_STE_SB             = 352,
    IP_PORT_BHOEDAP4                = 352,
    IP_PORT_NDSAUTH                 = 353,
    IP_PORT_BH611                   = 354,
    IP_PORT_DATEX_ASN               = 355,
    IP_PORT_CLOANTO_NET_1           = 356,
    IP_PORT_BHEVENT                 = 357,
    IP_PORT_SHRINKWRAP              = 358,
    IP_PORT_NSRMP                   = 359,
    IP_PORT_SCOI2ODIALOG            = 360,
    IP_PORT_SEMANTIX                = 361,
    IP_PORT_SRSSEND                 = 362,
    IP_PORT_RSVP_TUNNEL             = 363,
    IP_PORT_AURORA_CMGR             = 364,
    IP_PORT_DTK                     = 365,
    IP_PORT_ODMR                    = 366,
    IP_PORT_MORTGAGEWARE            = 367,
    IP_PORT_QBIKGDP                 = 368,
    IP_PORT_RPC2PORTMAP             = 369,
    IP_PORT_CODAAUTH2               = 370,
    IP_PORT_CLEARCASE               = 371,
    IP_PORT_ULISTPROC               = 372,
    IP_PORT_LEGENT_1                = 373,
    IP_PORT_LEGENT_2                = 374,
    IP_PORT_HASSLE                  = 375,
    IP_PORT_NIP                     = 376,
    IP_PORT_TNETOS                  = 377,
    IP_PORT_DSETOS                  = 378,
    IP_PORT_IS99C                   = 379,
    IP_PORT_IS99S                   = 380,
    IP_PORT_HP_COLLECTOR            = 381,
    IP_PORT_HP_MANAGED_NODE         = 382,
    IP_PORT_HP_ALARM_MGR            = 383,
    IP_PORT_ARNS                    = 384,
    IP_PORT_IBM_APP                 = 385,
    IP_PORT_ASA                     = 386,
    IP_PORT_AURP                    = 387,
    IP_PORT_UNIDATA_LDM             = 388,
    IP_PORT_LDAP                    = 389,
    IP_PORT_UIS                     = 390,
    IP_PORT_SYNOTICS_RELAY          = 391,
    IP_PORT_SYNOTICS_BROKER         = 392,
    IP_PORT_META5                   = 393,
    IP_PORT_EMBL_NDT                = 394,
    IP_PORT_NETCP                   = 395,
    IP_PORT_NETWARE_IP              = 396,
    IP_PORT_MPTN                    = 397,
    IP_PORT_KRYPTOLAN               = 398,
    IP_PORT_ISO_TSAP_C2             = 399,
    IP_PORT_WORK_SOL                = 400,
    IP_PORT_UPS                     = 401,
    IP_PORT_GENIE                   = 402,
    IP_PORT_DECAP                   = 403,
    IP_PORT_NCED                    = 404,
    IP_PORT_NCLD                    = 405,
    IP_PORT_IMSP                    = 406,
    IP_PORT_TIMBUKTU                = 407,
    IP_PORT_PRM_SM                  = 408,
    IP_PORT_PRM_NM                  = 409,
    IP_PORT_DECLADEBUG              = 410,
    IP_PORT_RMT                     = 411,
    IP_PORT_SYNOPTICS_TRAP          = 412,
    IP_PORT_SMSP                    = 413,
    IP_PORT_INFOSEEK                = 414,
    IP_PORT_BNET                    = 415,
    IP_PORT_SILVERPLATTER           = 416,
    IP_PORT_ONMUX                   = 417,
    IP_PORT_HYPER_G                 = 418,
    IP_PORT_ARIEL1                  = 419,
    IP_PORT_SMPTE                   = 420,
    IP_PORT_ARIEL2                  = 421,
    IP_PORT_ARIEL3                  = 422,
    IP_PORT_OPC_JOB_START           = 423,
    IP_PORT_OPC_JOB_TRACK           = 424,
    IP_PORT_ICAD_EL                 = 425,
    IP_PORT_SMARTSDP                = 426,
    IP_PORT_SVRLOC                  = 427,
    IP_PORT_OCS_CMU                 = 428,
    IP_PORT_OCS_AMU                 = 429,
    IP_PORT_UTMPSD                  = 430,
    IP_PORT_UTMPCD                  = 431,
    IP_PORT_IASD                    = 432,
    IP_PORT_NNSP                    = 433,
    IP_PORT_MOBILEIP_AGENT          = 434,
    IP_PORT_MOBILIP_MN              = 435,
    IP_PORT_DNA_CML                 = 436,
    IP_PORT_COMSCM                  = 437,
    IP_PORT_DSFGW                   = 438,
    IP_PORT_DASP                    = 439,
    IP_PORT_SGCP                    = 440,
    IP_PORT_DECVMS_SYSMGT           = 441,
    IP_PORT_CVC_HOSTD               = 442,
    IP_PORT_HTTPS                   = 443,
    IP_PORT_SNPP                    = 444,
    IP_PORT_MICROSOFT_DS            = 445,
    IP_PORT_DDM_RDB                 = 446,
    IP_PORT_DDM_DFM                 = 447,
    IP_PORT_DDM_SSL                 = 448,
    IP_PORT_AS_SERVERMAP            = 449,
    IP_PORT_TSERVER                 = 450,
    IP_PORT_SFS_SMP_NET             = 451,
    IP_PORT_SFS_CONFIG              = 452,
    IP_PORT_CREATIVESERVER          = 453,
    IP_PORT_CONTENTSERVER           = 454,
    IP_PORT_CREATIVEPARTNR          = 455,
    IP_PORT_MACON_TCP               = 456,
    IP_PORT_SCOHELP                 = 457,
    IP_PORT_APPLEQTC                = 458,
    IP_PORT_AMPR_RCMD               = 459,
    IP_PORT_SKRONK                  = 460,
    IP_PORT_DATASURFSRV             = 461,
    IP_PORT_DATASURFSRVSEC          = 462,
    IP_PORT_ALPES                   = 463,
    IP_PORT_KPASSWD                 = 464,
    IP_PORT_URD                     = 465,
    IP_PORT_DIGITAL_VRC             = 466,
    IP_PORT_MYLEX_MAPD              = 467,
    IP_PORT_PHOTURIS                = 468,
    IP_PORT_RCP                     = 469,
    IP_PORT_SCX_PROXY               = 470,
    IP_PORT_MONDEX                  = 471,
    IP_PORT_LJK_LOGIN               = 472,
    IP_PORT_HYBRID_POP              = 473,
    IP_PORT_TN_TL_W1                = 474,
    IP_PORT_TCPNETHASPSRV           = 475,
    IP_PORT_TN_TL_FD1               = 476,
    IP_PORT_SS7NS                   = 477,
    IP_PORT_SPSC                    = 478,
    IP_PORT_IAFSERVER               = 479,
    IP_PORT_IAFDBASE                = 480,
    IP_PORT_PH                      = 481,
    IP_PORT_BGS_NSI                 = 482,
    IP_PORT_ULPNET                  = 483,
    IP_PORT_INTEGRA_SME             = 484,
    IP_PORT_POWERBURST              = 485,
    IP_PORT_AVIAN                   = 486,
    IP_PORT_SAFT                    = 487,
    IP_PORT_GSS_HTTP                = 488,
    IP_PORT_NEST_PROTOCOL           = 489,
    IP_PORT_MICOM_PFS               = 490,
    IP_PORT_GO_LOGIN                = 491,
    IP_PORT_TICF_1                  = 492,
    IP_PORT_TICF_2                  = 493,
    IP_PORT_POV_RAY                 = 494,
    IP_PORT_INTECOURIER             = 495,
    IP_PORT_PIM_RP_DISC             = 496,
    IP_PORT_DANTZ                   = 497,
    IP_PORT_SIAM                    = 498,
    IP_PORT_ISO_ILL                 = 499,
    IP_PORT_ISAKMP                  = 500,
    IP_PORT_STMF                    = 501,
    IP_PORT_ASA_APPL_PROTO          = 502,
    IP_PORT_INTRINSA                = 503,
    IP_PORT_CITADEL                 = 504,
    IP_PORT_MAILBOX_LM              = 505,
    IP_PORT_OHIMSRV                 = 506,
    IP_PORT_CRS                     = 507,
    IP_PORT_XVTTP                   = 508,
    IP_PORT_SNARE                   = 509,
    IP_PORT_FCP                     = 510,
    IP_PORT_PASSGO                  = 511,
    IP_PORT_EXEC                    = 512,
    IP_PORT_LOGIN                   = 513,
    IP_PORT_SHELL                   = 514,
    IP_PORT_PRINTER                 = 515,
    IP_PORT_VIDEOTEX                = 516,
    IP_PORT_TALK                    = 517,
    IP_PORT_NTALK                   = 518,
    IP_PORT_UTIME                   = 519,
    IP_PORT_EFS                     = 520,
    IP_PORT_RIPNG                   = 521,
    IP_PORT_ULP                     = 522,
    IP_PORT_IBM_DB2                 = 523,
    IP_PORT_NCP                     = 524,
    IP_PORT_TIMED                   = 525,
    IP_PORT_TEMPO                   = 526,
    IP_PORT_STX                     = 527,
    IP_PORT_CUSTIX                  = 528,
    IP_PORT_IRC_SERV                = 529,
    IP_PORT_COURIER                 = 530,
    IP_PORT_CONFERENCE              = 531,
    IP_PORT_NETNEWS                 = 532,
    IP_PORT_NETWALL                 = 533,
    IP_PORT_MM_ADMIN                = 534,
    IP_PORT_IIOP                    = 535,
    IP_PORT_OPALIS_RDV              = 536,
    IP_PORT_NMSP                    = 537,
    IP_PORT_GDOMAP                  = 538,
    IP_PORT_APERTUS_LDP             = 539,
    IP_PORT_UUCP                    = 540,
    IP_PORT_UUCP_RLOGIN             = 541,
    IP_PORT_COMMERCE                = 542,
    IP_PORT_KLOGIN                  = 543,
    IP_PORT_KSHELL                  = 544,
    IP_PORT_APPLEQTCSRVR            = 545,
    IP_PORT_DHCPV6_CLIENT           = 546,
    IP_PORT_DHCPV6_SERVER           = 547,
    IP_PORT_AFPOVERTCP              = 548,
    IP_PORT_IDFP                    = 549,
    IP_PORT_NEW_RWHO                = 550,
    IP_PORT_CYBERCASH               = 551,
    IP_PORT_DEVSHR_NTS              = 552,
    IP_PORT_PIRP                    = 553,
    IP_PORT_RTSP                    = 554,
    IP_PORT_DSF                     = 555,
    IP_PORT_REMOTEFS                = 556,
    IP_PORT_OPENVMS_SYSIPC          = 557,
    IP_PORT_SDNSKMP                 = 558,
    IP_PORT_TEEDTAP                 = 559,
    IP_PORT_RMONITOR                = 560,
    IP_PORT_MONITOR                 = 561,
    IP_PORT_CHSHELL                 = 562,
    IP_PORT_NNTPS                   = 563,
    IP_PORT_9PFS                    = 564,
    IP_PORT_WHOAMI                  = 565,
    IP_PORT_STREETTALK              = 566,
    IP_PORT_BANYAN_RPC              = 567,
    IP_PORT_MS_SHUTTLE              = 568,
    IP_PORT_MS_ROME                 = 569,
    IP_PORT_METER                   = 570,
    IP_PORT_METER1                  = 571,
    IP_PORT_SONAR                   = 572,
    IP_PORT_BANYAN_VIP              = 573,
    IP_PORT_FTP_AGENT               = 574,
    IP_PORT_VEMMI                   = 575,
    IP_PORT_IPCD                    = 576,
    IP_PORT_VNAS                    = 577,
    IP_PORT_IPDD                    = 578,
    IP_PORT_DECBSRV                 = 579,
    IP_PORT_SNTP_HEARTBEAT          = 580,
    IP_PORT_BDP                     = 581,
    IP_PORT_SCC_SECURITY            = 582,
    IP_PORT_PHILIPS_VC              = 583,
    IP_PORT_KEYSERVER               = 584,
    IP_PORT_IMAP4_SSL               = 585,
    IP_PORT_PASSWORD_CHG            = 586,
    IP_PORT_SUBMISSION              = 587,
    IP_PORT_CAL                     = 588,
    IP_PORT_EYELINK                 = 589,
    IP_PORT_TNS_CML                 = 590,
    IP_PORT_HTTP_ALT                = 591,
    IP_PORT_EUDORA_SET              = 592,
    IP_PORT_HTTP_RPC_EPMAP          = 593,
    IP_PORT_TPIP                    = 594,
    IP_PORT_CAB_PROTOCOL            = 595,
    IP_PORT_SMSD                    = 596,
    IP_PORT_PTCNAMESERVICE          = 597,
    IP_PORT_SCO_WEBSRVRMG3          = 598,
    IP_PORT_ACP                     = 599,
    IP_PORT_IPCSERVER               = 600,
    IP_PORT_SYSLOG_CONN             = 601,
    IP_PORT_XMLRPC_BEEP             = 602,
    IP_PORT_IDXP                    = 603,
    IP_PORT_TUNNEL                  = 604,
    IP_PORT_SOAP_BEEP               = 605,
    IP_PORT_URM                     = 606,
    IP_PORT_NQS                     = 607,
    IP_PORT_SIFT_UFT                = 608,
    IP_PORT_NPMP_TRAP               = 609,
    IP_PORT_NPMP_LOCAL              = 610,
    IP_PORT_NPMP_GUI                = 611,
    IP_PORT_HMMP_IND                = 612,
    IP_PORT_HMMP_OP                 = 613,
    IP_PORT_SSHELL                  = 614,
    IP_PORT_SCO_INETMGR             = 615,
    IP_PORT_SCO_SYSMGR              = 616,
    IP_PORT_SCO_DTMGR               = 617,
    IP_PORT_DEI_ICDA                = 618,
    IP_PORT_COMPAQ_EVM              = 619,
    IP_PORT_SCO_WEBSRVRMGR          = 620,
    IP_PORT_ESCP_IP                 = 621,
    IP_PORT_COLLABORATOR            = 622,
    IP_PORT_ASF_RMCP                = 623,
    IP_PORT_CRYPTOADMIN             = 624,
    IP_PORT_DEC_DLM                 = 625,
    IP_PORT_ASIA                    = 626,
    IP_PORT_PASSGO_TIVOLI           = 627,
    IP_PORT_QMQP                    = 628,
    IP_PORT_3COM_AMP3               = 629,
    IP_PORT_RDA                     = 630,
    IP_PORT_IPP                     = 631,
    IP_PORT_BMPP                    = 632,
    IP_PORT_SERVSTAT                = 633,
    IP_PORT_GINAD                   = 634,
    IP_PORT_RLZDBASE                = 635,
    IP_PORT_LDAPS                   = 636,
    IP_PORT_LANSERVER               = 637,
    IP_PORT_MCNS_SEC                = 638,
    IP_PORT_MSDP                    = 639,
    IP_PORT_ENTRUST_SPS             = 640,
    IP_PORT_REPCMD                  = 641,
    IP_PORT_ESRO_EMSDP              = 642,
    IP_PORT_SANITY                  = 643,
    IP_PORT_DWR                     = 644,
    IP_PORT_PSSC                    = 645,
    IP_PORT_LDP                     = 646,
    IP_PORT_DHCP_FAILOVER           = 647,
    IP_PORT_RRP                     = 648,
    IP_PORT_CADVIEW_3D              = 649,
    IP_PORT_OBEX                    = 650,
    IP_PORT_IEEE_MMS                = 651,
    IP_PORT_HELLO_PORT              = 652,
    IP_PORT_REPSCMD                 = 653,
    IP_PORT_AODV                    = 654,
    IP_PORT_TINC                    = 655,
    IP_PORT_SPMP                    = 656,
    IP_PORT_RMC                     = 657,
    IP_PORT_TENFOLD                 = 658,
    IP_PORT_MAC_SRVR_ADMIN          = 660,
    IP_PORT_HAP                     = 661,
    IP_PORT_PFTP                    = 662,
    IP_PORT_PURENOISE               = 663,
    IP_PORT_ASF_SECURE_RMCP         = 664,
    IP_PORT_SUN_DR                  = 665,
    IP_PORT_MDQS                    = 666,
    IP_PORT_DOOM                    = 666,
    IP_PORT_DISCLOSE                = 667,
    IP_PORT_MECOMM                  = 668,
    IP_PORT_MEREGISTER              = 669,
    IP_PORT_VACDSM_SWS              = 670,
    IP_PORT_VACDSM_APP              = 671,
    IP_PORT_VPPS_QUA                = 672,
    IP_PORT_CIMPLEX                 = 673,
    IP_PORT_ACAP                    = 674,
    IP_PORT_DCTP                    = 675,
    IP_PORT_VPPS_VIA                = 676,
    IP_PORT_VPP                     = 677,
    IP_PORT_GGF_NCP                 = 678,
    IP_PORT_MRM                     = 679,
    IP_PORT_ENTRUST_AAAS            = 680,
    IP_PORT_ENTRUST_AAMS            = 681,
    IP_PORT_XFR                     = 682,
    IP_PORT_CORBA_IIOP              = 683,
    IP_PORT_CORBA_IIOP_SSL          = 684,
    IP_PORT_MDC_PORTMAPPER          = 685,
    IP_PORT_HCP_WISMAR              = 686,
    IP_PORT_ASIPREGISTRY            = 687,
    IP_PORT_REALM_RUSD              = 688,
    IP_PORT_NMAP                    = 689,
    IP_PORT_VATP                    = 690,
    IP_PORT_MSEXCH_ROUTING          = 691,
    IP_PORT_HYPERWAVE_ISP           = 692,
    IP_PORT_CONNENDP                = 693,
    IP_PORT_HA_CLUSTER              = 694,
    IP_PORT_IEEE_MMS_SSL            = 695,
    IP_PORT_RUSHD                   = 696,
    IP_PORT_UUIDGEN                 = 697,
    IP_PORT_OLSR                    = 698,
    IP_PORT_ACCESSNETWORK           = 699,
    IP_PORT_EPP                     = 700,
    IP_PORT_LMP                     = 701,
    IP_PORT_IRIS_BEEP               = 702,
    IP_PORT_ELCSD                   = 704,
    IP_PORT_AGENTX                  = 705,
    IP_PORT_SILC                    = 706,
    IP_PORT_BORLAND_DSJ             = 707,
    IP_PORT_ENTRUST_KMSH            = 709,
    IP_PORT_ENTRUST_ASH             = 710,
    IP_PORT_CISCO_TDP               = 711,
    IP_PORT_TBRPF                   = 712,
    IP_PORT_NETVIEWDM1              = 729,
    IP_PORT_NETVIEWDM2              = 730,
    IP_PORT_NETVIEWDM3              = 731,
    IP_PORT_NETGW                   = 741,
    IP_PORT_NETRCS                  = 742,
    IP_PORT_FLEXLM                  = 744,
    IP_PORT_FUJITSU_DEV             = 747,
    IP_PORT_RIS_CM                  = 748,
    IP_PORT_KERBEROS_ADM            = 749,
    IP_PORT_RFILE                   = 750,
    IP_PORT_PUMP                    = 751,
    IP_PORT_QRH                     = 752,
    IP_PORT_RRH                     = 753,
    IP_PORT_TELL                    = 754,
    IP_PORT_NLOGIN                  = 758,
    IP_PORT_CON                     = 759,
    IP_PORT_NS                      = 760,
    IP_PORT_RXE                     = 761,
    IP_PORT_QUOTAD                  = 762,
    IP_PORT_CYCLESERV               = 763,
    IP_PORT_OMSERV                  = 764,
    IP_PORT_WEBSTER                 = 765,
    IP_PORT_PHONEBOOK               = 767,
    IP_PORT_VID                     = 769,
    IP_PORT_CADLOCK                 = 770,
    IP_PORT_RTIP                    = 771,
    IP_PORT_CYCLESERV2              = 772,
    IP_PORT_SUBMIT                  = 773,
    IP_PORT_RPASSWD                 = 774,
    IP_PORT_ENTOMB                  = 775,
    IP_PORT_WPAGES                  = 776,
    IP_PORT_MULTILING_HTTP          = 777,
    IP_PORT_WPGS                    = 780,
    IP_PORT_MDBS_DAEMON             = 800,
    IP_PORT_DEVICE                  = 801,
    IP_PORT_FCP_UDP                 = 810,
    IP_PORT_ITM_MCELL_S             = 828,
    IP_PORT_PKIX_3_CA_RA            = 829,
    IP_PORT_DHCP_FAILOVER2          = 847,
    IP_PORT_GDOI                    = 848,
    IP_PORT_ISCSI                   = 860,
    IP_PORT_RSYNC                   = 873,
    IP_PORT_ICLCNET_LOCATE          = 886,
    IP_PORT_ICLCNET_SVINFO          = 887,
    IP_PORT_ACCESSBUILDER           = 888,
    IP_PORT_CDDBP                   = 888,
    IP_PORT_OMGINITIALREFS          = 900,
    IP_PORT_SMPNAMERES              = 901,
    IP_PORT_IDEAFARM_CHAT           = 902,
    IP_PORT_IDEAFARM_CATCH          = 903,
    IP_PORT_XACT_BACKUP             = 911,
    IP_PORT_APEX_MESH               = 912,
    IP_PORT_APEX_EDGE               = 913,
    IP_PORT_FTPS_DATA               = 989,
    IP_PORT_FTPS                    = 990,
    IP_PORT_NAS                     = 991,
    IP_PORT_TELNETS                 = 992,
    IP_PORT_IMAPS                   = 993,
    IP_PORT_IRCS                    = 994,
    IP_PORT_POP3S                   = 995,
    IP_PORT_VSINET                  = 996,
    IP_PORT_MAITRD                  = 997,
    IP_PORT_BUSBOY                  = 998,
    IP_PORT_GARCON                  = 999,
    IP_PORT_PUPROUTER               = 999,
    IP_PORT_CADLOCK2                = 1000,
    IP_PORT_SURF                    = 1010,
} ip_port_t;
typedef enum {
    IP_BUILTIN_PROTOCOL_UDP,
    IP_BUILTIN_PROTOCOL_ICMP,
    IP_BUILTIN_PROTOCOL_UNKNOWN,
} ip_builtin_protocol_t;
typedef enum {
    IP_MULTICAST_GROUP_all_hosts_on_subnet     = 1,
    IP_MULTICAST_GROUP_all_routers_on_subnet   = 2,
    IP_MULTICAST_GROUP_dvmrp                   = 4,
    IP_MULTICAST_GROUP_ospf_all_routers        = 5,
    IP_MULTICAST_GROUP_ospf_designated_routers = 6,
    IP_MULTICAST_GROUP_pim                     = 13,
    IP_MULTICAST_GROUP_vrrp                    = 18,
    IP_MULTICAST_GROUP_hsrp                    = 102,
    IP_MULTICAST_GROUP_igmp_v3                 = 22,
} ip_multicast_group_t;
static inline __attribute__((__always_inline__)) u16
ip_csum(void *data, u16 n_left)
{
    u32 sum;
    sum = (n_left & 1) ? ((u8 *) data)[n_left - 1] << 8 : 0;
    n_left >>= 1;
    while (n_left >= 8) {
        sum += clib_net_to_host_u16(*((u16 *) data + 0));
        sum += clib_net_to_host_u16(*((u16 *) data + 1));
        sum += clib_net_to_host_u16(*((u16 *) data + 2));
        sum += clib_net_to_host_u16(*((u16 *) data + 3));
        sum += clib_net_to_host_u16(*((u16 *) data + 4));
        sum += clib_net_to_host_u16(*((u16 *) data + 5));
        sum += clib_net_to_host_u16(*((u16 *) data + 6));
        sum += clib_net_to_host_u16(*((u16 *) data + 7));
        n_left -= 8;
        data += 16;
    }
    while (n_left) {
        sum += clib_net_to_host_u16(*(u16 *) data);
        n_left -= 1;
        data += 2;
    }
    sum = (sum & 0xffff) + (sum >> 16);
    sum = (sum & 0xffff) + (sum >> 16);
    return ~((u16) sum);
}
typedef uword ip_csum_t;
static inline __attribute__((__always_inline__)) ip_csum_t
ip_csum_with_carry(ip_csum_t sum, ip_csum_t x)
{
    ip_csum_t t = sum + x;
    return t + (t < x);
}
static inline __attribute__((__always_inline__)) ip_csum_t
ip_csum_add_even(ip_csum_t c, ip_csum_t x)
{
    ip_csum_t d;
    d = c - x;
    d -= d > c;
    ip_csum_t t = ip_csum_with_carry(d, x);
    do {
        if ((0 > 0) && !((t - c == 0) || (t - c == ~0))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/ip_packet.h", (uword) 202,
                        ((char *) __FUNCTION__), "(t - c == 0) || (t - c == ~0)");
        }
    } while (0);
    return d;
}
static inline __attribute__((__always_inline__)) ip_csum_t
ip_csum_sub_even(ip_csum_t c, ip_csum_t x)
{
    return ip_csum_with_carry(c, x);
}
static inline __attribute__((__always_inline__)) ip_csum_t
ip_csum_update_inline(ip_csum_t sum, ip_csum_t old, ip_csum_t new, u32 field_byte_offset, u32 field_n_bytes)
{
    if ((field_n_bytes % 2) && (field_byte_offset % 2) == (1)) {
        old = old << 8;
        new = new << 8;
    }
    sum = ip_csum_sub_even(sum, old);
    sum = ip_csum_add_even(sum, new);
    return sum;
}
static inline __attribute__((__always_inline__)) u16
ip_csum_fold(ip_csum_t c)
{
    c = (c & (ip_csum_t) 0xffffffff) + (c >> (ip_csum_t) 32);
    c = (c & 0xffff) + (c >> 16);
    c = (c & 0xffff) + (c >> 16);
    c = (c & 0xffff) + (c >> 16);
    return c;
}
extern ip_csum_t (*vnet_incremental_checksum_fp)(ip_csum_t, void *, uword);
static inline __attribute__((__always_inline__)) ip_csum_t
ip_incremental_checksum(ip_csum_t sum, void *_data, uword n_bytes)
{
    return (*vnet_incremental_checksum_fp)(sum, _data, n_bytes);
}
static inline __attribute__((__always_inline__)) u16
ip_csum_and_memcpy_fold(ip_csum_t sum, void *dst)
{
    return ip_csum_fold(sum);
}
ip_csum_t ip_incremental_checksum(ip_csum_t sum, void *data, uword n_bytes);
enum {
    TCP_FLAG_BIT_FIN,
    TCP_FLAG_BIT_SYN,
    TCP_FLAG_BIT_RST,
    TCP_FLAG_BIT_PSH,
    TCP_FLAG_BIT_ACK,
    TCP_FLAG_BIT_URG,
    TCP_FLAG_BIT_ECE,
    TCP_FLAG_BIT_CWR,
    TCP_N_FLAG_BITS,
};
enum {
    TCP_FLAG_FIN = 1 << TCP_FLAG_BIT_FIN,
    TCP_FLAG_SYN = 1 << TCP_FLAG_BIT_SYN,
    TCP_FLAG_RST = 1 << TCP_FLAG_BIT_RST,
    TCP_FLAG_PSH = 1 << TCP_FLAG_BIT_PSH,
    TCP_FLAG_ACK = 1 << TCP_FLAG_BIT_ACK,
    TCP_FLAG_URG = 1 << TCP_FLAG_BIT_URG,
    TCP_FLAG_ECE = 1 << TCP_FLAG_BIT_ECE,
    TCP_FLAG_CWR = 1 << TCP_FLAG_BIT_CWR,
};
typedef struct _tcp_header {
    union {
        struct {
            u16 src_port;
            u16 dst_port;
        };
        struct {
            u16 src, dst;
        };
    };
    u32 seq_number;
    u32 ack_number;
    u8 data_offset_and_reserved;
    u8 flags;
    u16 window;
    u16 checksum;
    u16 urgent_pointer;
} __attribute__((packed)) tcp_header_t;
static inline __attribute__((__always_inline__)) int
tcp_header_bytes(tcp_header_t *t)
{
    return ((t)->data_offset_and_reserved >> 4) * sizeof(u32);
}
typedef enum tcp_option_type {
    TCP_OPTION_EOL            = 0,
    TCP_OPTION_NOOP           = 1,
    TCP_OPTION_MSS            = 2,
    TCP_OPTION_WINDOW_SCALE   = 3,
    TCP_OPTION_SACK_PERMITTED = 4,
    TCP_OPTION_SACK_BLOCK     = 5,
    TCP_OPTION_TIMESTAMP      = 8,
    TCP_OPTION_UTO            = 28,
    TCP_OPTION_AO             = 29,
} tcp_option_type_t;
enum {
    TCP_OPTS_FLAG_BIT_MSS,
    TCP_OPTS_FLAG_BIT_TSTAMP,
    TCP_OPTS_FLAG_BIT_WSCALE,
    TCP_OPTS_FLAG_BIT_SACK_PERMITTED,
    TCP_OPTS_FLAG_BIT_SACK,
    TCP_OPTIONS_N_FLAG_BITS,
};
enum {
    TCP_OPTS_FLAG_MSS            = 1 << TCP_OPTS_FLAG_BIT_MSS,
    TCP_OPTS_FLAG_TSTAMP         = 1 << TCP_OPTS_FLAG_BIT_TSTAMP,
    TCP_OPTS_FLAG_WSCALE         = 1 << TCP_OPTS_FLAG_BIT_WSCALE,
    TCP_OPTS_FLAG_SACK_PERMITTED = 1 << TCP_OPTS_FLAG_BIT_SACK_PERMITTED,
    TCP_OPTS_FLAG_SACK           = 1 << TCP_OPTS_FLAG_BIT_SACK,
};
typedef struct _sack_block {
    u32 start;
    u32 end;
} sack_block_t;
typedef struct {
    u8 flags;
    u16 mss;
    u8 wscale;
    u32 tsval;
    u32 tsecr;
    sack_block_t *sacks;
    u8 n_sack_blocks;
} tcp_options_t;
typedef union {
    u8 data[4];
    u32 data_u32;
    u8 as_u8[4];
    u16 as_u16[2];
    u32 as_u32;
} ip4_address_t;
typedef struct {
    ip4_address_t ip4_addr;
    u32 fib_index;
} ip4_address_fib_t;
static inline __attribute__((__always_inline__)) void
ip4_addr_fib_init(ip4_address_fib_t *addr_fib, const ip4_address_t *address, u32 fib_index)
{
    memcpy(&addr_fib->ip4_addr, address, sizeof(addr_fib->ip4_addr));
    addr_fib->fib_index = fib_index;
}
typedef struct {
    ip4_address_t src, dst;
} ip4_address_pair_t;
typedef struct {
    ip4_address_t addr, mask;
} ip4_address_and_mask_t;
static inline __attribute__((__always_inline__)) uword
ip4_address_netmask_length(const ip4_address_t *a)
{
    uword result = 0;
    uword i;
    for (i = 0; i < (sizeof(a->as_u8) / sizeof(a->as_u8[0])); i++) {
        switch (a->as_u8[i]) {
        case 0xff:
            result += 8;
            break;
        case 0xfe:
            result += 7;
            goto done;
        case 0xfc:
            result += 6;
            goto done;
        case 0xf8:
            result += 5;
            goto done;
        case 0xf0:
            result += 4;
            goto done;
        case 0xe0:
            result += 3;
            goto done;
        case 0xc0:
            result += 2;
            goto done;
        case 0x80:
            result += 1;
            goto done;
        case 0x00:
            result += 0;
            goto done;
        default:
            return ~0;
        }
    }
done:
    return result;
}
typedef union {
    struct {
        u8 ip_version_and_header_length;
        u8 tos;
        u16 length;
        u16 fragment_id;
        u16 flags_and_fragment_offset;
        u8 ttl;
        u8 protocol;
        u16 checksum;
        union {
            struct {
                ip4_address_t src_address, dst_address;
            };
            ip4_address_pair_t address_pair;
        };
    };
    struct {
        u64 checksum_data_64[2];
        u32 checksum_data_64_32[1];
    } __attribute__((packed));
    struct {
        u32 checksum_data_32[5];
    } __attribute__((packed));
} ip4_header_t;
static inline __attribute__((__always_inline__)) int
ip4_get_fragment_offset(const ip4_header_t *i)
{
    return clib_net_to_host_u16(i->flags_and_fragment_offset) & 0x1fff;
}
static inline __attribute__((__always_inline__)) int
ip4_get_fragment_more(const ip4_header_t *i)
{
    return clib_net_to_host_u16(i->flags_and_fragment_offset) & (1 << 13);
}
static inline __attribute__((__always_inline__)) int
ip4_is_fragment(const ip4_header_t *i)
{
    return (i->flags_and_fragment_offset & clib_net_to_host_u16(0x1fff | (1 << 13)));
}
static inline __attribute__((__always_inline__)) int
ip4_is_first_fragment(const ip4_header_t *i)
{
    return (i->flags_and_fragment_offset & clib_net_to_host_u16(0x1fff | (1 << 13))) == clib_net_to_host_u16((1 << 13));
}
static inline __attribute__((__always_inline__)) int
ip4_get_fragment_offset_bytes(const ip4_header_t *i)
{
    return 8 * ip4_get_fragment_offset(i);
}
static inline __attribute__((__always_inline__)) int
ip4_header_bytes(const ip4_header_t *i)
{
    return sizeof(u32) * (i->ip_version_and_header_length & 0xf);
}
static inline __attribute__((__always_inline__)) void *
ip4_next_header(ip4_header_t *i)
{
    return (void *) i + ip4_header_bytes(i);
}
static inline __attribute__((__always_inline__)) u16
ip4_header_checksum(ip4_header_t *i)
{
    u16 save, csum;
    ip_csum_t sum;
    save        = i->checksum;
    i->checksum = 0;
    sum         = ip_incremental_checksum(0, i, ip4_header_bytes(i));
    csum        = ~ip_csum_fold(sum);
    i->checksum = save;
    if (csum == 0 && save == 0xffff)
        csum = save;
    return csum;
}
static inline uword
ip4_header_checksum_is_valid(ip4_header_t *i)
{
    return i->checksum == ip4_header_checksum(i);
}
static inline __attribute__((__always_inline__)) uword
ip4_address_is_multicast(const ip4_address_t *a)
{
    return (a->data[0] & 0xf0) == 0xe0;
}
static inline __attribute__((__always_inline__)) void
ip4_multicast_address_set_for_group(ip4_address_t *a, ip_multicast_group_t g)
{
    do {
        if ((0 > 0) && !((u32) g < (1 << 28))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/ip4_packet.h", (uword) 326,
                        ((char *) __FUNCTION__), "(u32) g < (1 << 28)");
        }
    } while (0);
    a->as_u32 = clib_host_to_net_u32((0xe << 28) + g);
}
static inline __attribute__((__always_inline__)) void
ip4_multicast_ethernet_address(u8 *ethernet_address, const ip4_address_t *a)
{
    const u8 *d         = a->as_u8;
    ethernet_address[0] = 0x01;
    ethernet_address[1] = 0x00;
    ethernet_address[2] = 0x5e;
    ethernet_address[3] = d[1] & 0x7f;
    ethernet_address[4] = d[2];
    ethernet_address[5] = d[3];
}
static inline __attribute__((__always_inline__)) void
ip4_tcp_reply_x1(ip4_header_t *ip0, tcp_header_t *tcp0)
{
    u32 src0, dst0;
    src0                      = ip0->src_address.data_u32;
    dst0                      = ip0->dst_address.data_u32;
    ip0->src_address.data_u32 = dst0;
    ip0->dst_address.data_u32 = src0;
    src0                      = tcp0->src;
    dst0                      = tcp0->dst;
    tcp0->src                 = dst0;
    tcp0->dst                 = src0;
}
static inline __attribute__((__always_inline__)) void
ip4_tcp_reply_x2(ip4_header_t *ip0, ip4_header_t *ip1, tcp_header_t *tcp0, tcp_header_t *tcp1)
{
    u32 src0, dst0, src1, dst1;
    src0                      = ip0->src_address.data_u32;
    src1                      = ip1->src_address.data_u32;
    dst0                      = ip0->dst_address.data_u32;
    dst1                      = ip1->dst_address.data_u32;
    ip0->src_address.data_u32 = dst0;
    ip1->src_address.data_u32 = dst1;
    ip0->dst_address.data_u32 = src0;
    ip1->dst_address.data_u32 = src1;
    src0                      = tcp0->src;
    src1                      = tcp1->src;
    dst0                      = tcp0->dst;
    dst1                      = tcp1->dst;
    tcp0->src                 = dst0;
    tcp1->src                 = dst1;
    tcp0->dst                 = src0;
    tcp1->dst                 = src1;
}
typedef union {
    u8 as_u8[16];
    u16 as_u16[8];
    u32 as_u32[4];
    u64 as_u64[2];
    uword as_uword[16 / sizeof(uword)];
} ip6_address_t;
typedef struct {
    ip6_address_t addr, mask;
} ip6_address_and_mask_t;
typedef struct {
    ip6_address_t ip6_addr;
    u32 fib_index;
} __attribute__((packed)) ip6_address_fib_t;
typedef enum { IP46_TYPE_ANY, IP46_TYPE_IP4, IP46_TYPE_IP6 } ip46_type_t;
typedef union {
    struct {
        u32 pad[3];
        ip4_address_t ip4;
    };
    ip6_address_t ip6;
    u8 as_u8[16];
    u64 as_u64[2];
} __attribute__((packed)) ip46_address_t;
static inline __attribute__((__always_inline__)) void
ip46_address_copy(ip46_address_t *dst, const ip46_address_t *src)
{
    dst->as_u64[0] = src->as_u64[0];
    dst->as_u64[1] = src->as_u64[1];
}
static inline __attribute__((__always_inline__)) void
ip46_address_set_ip6(ip46_address_t *dst, const ip6_address_t *src)
{
    dst->as_u64[0] = src->as_u64[0];
    dst->as_u64[1] = src->as_u64[1];
}
static inline __attribute__((__always_inline__)) ip46_address_t
to_ip46(u32 is_ipv6, u8 *buf)
{
    ip46_address_t ip;
    if (is_ipv6)
        ip.ip6 = *((ip6_address_t *) buf);
    else
        (((&ip)->pad[0] = (&ip)->pad[1] = (&ip)->pad[2] = 0), (&ip)->ip4 = ((ip4_address_t *) buf)[0]);
    return ip;
}
static inline __attribute__((__always_inline__)) void
ip6_addr_fib_init(ip6_address_fib_t *addr_fib, const ip6_address_t *address, u32 fib_index)
{
    addr_fib->ip6_addr  = *address;
    addr_fib->fib_index = fib_index;
}
typedef enum {
    IP6_MULTICAST_SCOPE_loopback           = 0x1,
    IP6_MULTICAST_SCOPE_link_local         = 0x2,
    IP6_MULTICAST_SCOPE_admin_local        = 0x4,
    IP6_MULTICAST_SCOPE_site_local         = 0x5,
    IP6_MULTICAST_SCOPE_organization_local = 0x8,
    IP6_MULTICAST_SCOPE_global             = 0xe,
} ip6_multicast_address_scope_t;
typedef enum {
    IP6_MULTICAST_GROUP_ID_all_hosts     = 0x1,
    IP6_MULTICAST_GROUP_ID_all_routers   = 0x2,
    IP6_MULTICAST_GROUP_ID_rip_routers   = 0x9,
    IP6_MULTICAST_GROUP_ID_eigrp_routers = 0xa,
    IP6_MULTICAST_GROUP_ID_pim_routers   = 0xd,
    IP6_MULTICAST_GROUP_ID_mldv2_routers = 0x16,
} ip6_multicast_link_local_group_id_t;
static inline __attribute__((__always_inline__)) uword
ip6_address_is_multicast(const ip6_address_t *a)
{
    return a->as_u8[0] == 0xff;
}
static inline __attribute__((__always_inline__)) uword
ip46_address_is_multicast(const ip46_address_t *a)
{
    return (((a)->pad[0] | (a)->pad[1] | (a)->pad[2]) == 0) ? ip4_address_is_multicast(&a->ip4) :
                                                              ip6_address_is_multicast(&a->ip6);
}
static inline __attribute__((__always_inline__)) void
ip6_set_reserved_multicast_address(ip6_address_t *a, ip6_multicast_address_scope_t scope, u16 id)
{
    a->as_u64[0] = a->as_u64[1] = 0;
    a->as_u16[0]                = clib_host_to_net_u16(0xff00 | scope);
    a->as_u16[7]                = clib_host_to_net_u16(id);
}
static inline __attribute__((__always_inline__)) void
ip6_set_solicited_node_multicast_address(ip6_address_t *a, u32 id)
{
    a->as_u64[0] = a->as_u64[1] = 0;
    a->as_u16[0]                = clib_host_to_net_u16(0xff02);
    a->as_u8[11]                = 1;
    do {
        if ((0 > 0) && !((id >> 24) == 0)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/ip6_packet.h", (uword) 201,
                        ((char *) __FUNCTION__), "(id >> 24) == 0");
        }
    } while (0);
    id |= 0xff << 24;
    a->as_u32[3] = clib_host_to_net_u32(id);
}
static inline __attribute__((__always_inline__)) void
ip6_link_local_address_from_ethernet_address(ip6_address_t *a, const u8 *ethernet_address)
{
    a->as_u64[0] = a->as_u64[1] = 0;
    a->as_u16[0]                = clib_host_to_net_u16(0xfe80);
    a->as_u8[0x8]               = ethernet_address[0] | (1 << 6);
    a->as_u8[0x9]               = ethernet_address[1];
    a->as_u8[0xa]               = ethernet_address[2];
    a->as_u8[0xb]               = 0xff;
    a->as_u8[0xc]               = 0xfe;
    a->as_u8[0xd]               = ethernet_address[3];
    a->as_u8[0xe]               = ethernet_address[4];
    a->as_u8[0xf]               = ethernet_address[5];
}
static inline __attribute__((__always_inline__)) void
ip6_multicast_ethernet_address(u8 *ethernet_address, u32 group_id)
{
    ethernet_address[0] = 0x33;
    ethernet_address[1] = 0x33;
    ethernet_address[2] = ((group_id >> 24) & 0xff);
    ethernet_address[3] = ((group_id >> 16) & 0xff);
    ethernet_address[4] = ((group_id >> 8) & 0xff);
    ethernet_address[5] = ((group_id >> 0) & 0xff);
}
static inline __attribute__((__always_inline__)) uword
ip6_address_is_equal(const ip6_address_t *a, const ip6_address_t *b)
{
    int i;
    for (i = 0; i < (sizeof(a->as_uword) / sizeof(a->as_uword[0])); i++)
        if (a->as_uword[i] != b->as_uword[i])
            return 0;
    return 1;
}
static inline __attribute__((__always_inline__)) uword
ip6_address_is_equal_masked(const ip6_address_t *a, const ip6_address_t *b, const ip6_address_t *mask)
{
    int i;
    for (i = 0; i < (sizeof(a->as_uword) / sizeof(a->as_uword[0])); i++) {
        uword a_masked, b_masked;
        a_masked = a->as_uword[i] & mask->as_uword[i];
        b_masked = b->as_uword[i] & mask->as_uword[i];
        if (a_masked != b_masked)
            return 0;
    }
    return 1;
}
static inline __attribute__((__always_inline__)) void
ip6_address_mask(ip6_address_t *a, const ip6_address_t *mask)
{
    int i;
    for (i = 0; i < (sizeof(a->as_uword) / sizeof(a->as_uword[0])); i++)
        a->as_uword[i] &= mask->as_uword[i];
}
static inline __attribute__((__always_inline__)) void
ip6_address_set_zero(ip6_address_t *a)
{
    int i;
    for (i = 0; i < (sizeof(a->as_uword) / sizeof(a->as_uword[0])); i++)
        a->as_uword[i] = 0;
}
static inline __attribute__((__always_inline__)) void
ip6_address_mask_from_width(ip6_address_t *a, u32 width)
{
    int i, byte, bit, bitnum;
    do {
        if ((0 > 0) && !(width <= 128)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/ip6_packet.h", (uword) 282,
                        ((char *) __FUNCTION__), "width <= 128");
        }
    } while (0);
    memset(a, 0, sizeof(a[0]));
    for (i = 0; i < width; i++) {
        bitnum = (7 - (i & 7));
        byte   = i / 8;
        bit    = 1 << bitnum;
        a->as_u8[byte] |= bit;
    }
}
static inline __attribute__((__always_inline__)) uword
ip6_address_is_zero(const ip6_address_t *a)
{
    int i;
    for (i = 0; i < (sizeof(a->as_uword) / sizeof(a->as_uword[0])); i++)
        if (a->as_uword[i] != 0)
            return 0;
    return 1;
}
static inline __attribute__((__always_inline__)) uword
ip6_address_is_unspecified(const ip6_address_t *a)
{
    return ip6_address_is_zero(a);
}
static inline __attribute__((__always_inline__)) uword
ip6_address_is_loopback(const ip6_address_t *a)
{
    return (a->as_u64[0] == 0 && a->as_u32[2] == 0 && a->as_u16[6] == 0 && a->as_u8[14] == 0 && a->as_u8[15] == 1);
}
static inline __attribute__((__always_inline__)) uword
ip6_address_is_link_local_unicast(const ip6_address_t *a)
{
    return a->as_u8[0] == 0xfe && (a->as_u8[1] & 0xc0) == 0x80;
}
static inline __attribute__((__always_inline__)) uword
ip6_address_is_local_unicast(const ip6_address_t *a)
{
    return (a->as_u8[0] & 0xfe) == 0xfc;
}
static inline __attribute__((__always_inline__)) uword
ip6_address_is_global_unicast(const ip6_address_t *a)
{
    return (a->as_u8[0] & 0xe0) == 0x20;
}
static inline __attribute__((__always_inline__)) uword
ip6_is_solicited_node_multicast_address(const ip6_address_t *a)
{
    return (a->as_u32[0] == clib_host_to_net_u32(0xff020000) && a->as_u32[1] == 0 &&
            a->as_u32[2] == clib_host_to_net_u32(1) && a->as_u8[12] == 0xff);
}
static inline __attribute__((__always_inline__)) u32
ip6_address_hash_to_u32(const ip6_address_t *a)
{
    return (a->as_u32[0] ^ a->as_u32[1] ^ a->as_u32[2] ^ a->as_u32[3]);
}
static inline __attribute__((__always_inline__)) u64
ip6_address_hash_to_u64(const ip6_address_t *a)
{
    return (a->as_u64[0] ^ a->as_u64[1]);
}
typedef struct {
    u32 ip_version_traffic_class_and_flow_label;
    u16 payload_length;
    u8 protocol;
    u8 hop_limit;
    ip6_address_t src_address, dst_address;
} ip6_header_t;
static inline __attribute__((__always_inline__)) u8
ip6_traffic_class(const ip6_header_t *i)
{
    return (i->ip_version_traffic_class_and_flow_label & 0x0FF00000) >> 20;
}
static inline __attribute__((__always_inline__)) u8
ip6_traffic_class_network_order(const ip6_header_t *ip6)
{
    return (clib_net_to_host_u32(ip6->ip_version_traffic_class_and_flow_label) & 0x0ff00000) >> 20;
}
static inline __attribute__((__always_inline__)) void
ip6_set_traffic_class_network_order(ip6_header_t *ip6, u8 dscp)
{
    u32 tmp = clib_net_to_host_u32(ip6->ip_version_traffic_class_and_flow_label);
    tmp &= 0xf00fffff;
    tmp |= (dscp << 20);
    ip6->ip_version_traffic_class_and_flow_label = clib_host_to_net_u32(tmp);
}
static inline __attribute__((__always_inline__)) void *
ip6_next_header(ip6_header_t *i)
{
    return (void *) (i + 1);
}
static inline __attribute__((__always_inline__)) void
ip6_copy_header(ip6_header_t *dst, const ip6_header_t *src)
{
    dst->ip_version_traffic_class_and_flow_label = src->ip_version_traffic_class_and_flow_label;
    dst->payload_length                          = src->payload_length;
    dst->protocol                                = src->protocol;
    dst->hop_limit                               = src->hop_limit;
    dst->src_address.as_uword[0]                 = src->src_address.as_uword[0];
    dst->src_address.as_uword[1]                 = src->src_address.as_uword[1];
    dst->dst_address.as_uword[0]                 = src->dst_address.as_uword[0];
    dst->dst_address.as_uword[1]                 = src->dst_address.as_uword[1];
}
static inline __attribute__((__always_inline__)) void
ip6_tcp_reply_x1(ip6_header_t *ip0, tcp_header_t *tcp0)
{
    {
        ip6_address_t src0, dst0;
        src0             = ip0->src_address;
        dst0             = ip0->dst_address;
        ip0->src_address = dst0;
        ip0->dst_address = src0;
    }
    {
        u16 src0, dst0;
        src0      = tcp0->src;
        dst0      = tcp0->dst;
        tcp0->src = dst0;
        tcp0->dst = src0;
    }
}
static inline __attribute__((__always_inline__)) void
ip6_tcp_reply_x2(ip6_header_t *ip0, ip6_header_t *ip1, tcp_header_t *tcp0, tcp_header_t *tcp1)
{
    {
        ip6_address_t src0, dst0, src1, dst1;
        src0             = ip0->src_address;
        src1             = ip1->src_address;
        dst0             = ip0->dst_address;
        dst1             = ip1->dst_address;
        ip0->src_address = dst0;
        ip1->src_address = dst1;
        ip0->dst_address = src0;
        ip1->dst_address = src1;
    }
    {
        u16 src0, dst0, src1, dst1;
        src0      = tcp0->src;
        src1      = tcp1->src;
        dst0      = tcp0->dst;
        dst1      = tcp1->dst;
        tcp0->src = dst0;
        tcp1->src = dst1;
        tcp0->dst = src0;
        tcp1->dst = src1;
    }
}
typedef struct {
    u8 data;
} __attribute__((packed)) ip6_pad1_option_t;
typedef struct {
    u8 type;
    u8 len;
    u8 data[0];
} __attribute__((packed)) ip6_padN_option_t;
typedef struct {
    u8 type;
    u8 len;
    u16 value;
} __attribute__((packed)) ip6_router_alert_option_t;
typedef struct {
    u8 next_hdr;
    u8 n_data_u64s;
} __attribute__((packed)) ip6_ext_header_t;
static inline __attribute__((__always_inline__)) u8
ip6_ext_hdr(u8 nexthdr)
{
    return (nexthdr == IP_PROTOCOL_IP6_HOP_BY_HOP_OPTIONS) || (nexthdr == IP_PROTOCOL_IPV6_FRAGMENTATION) ||
           (nexthdr == IP_PROTOCOL_IPSEC_AH) || (nexthdr == IP_PROTOCOL_IPV6_ROUTE) ||
           (nexthdr == IP_PROTOCOL_IP6_DESTINATION_OPTIONS);
}
static inline __attribute__((__always_inline__)) void *
ip6_ext_next_header(ip6_ext_header_t *ext_hdr)
{
    return (void *) ((u8 *) ext_hdr + ((((ip6_ext_header_t *) (ext_hdr))->n_data_u64s + 1) << 3));
}
typedef struct {
    u8 next_hdr;
    u8 n_data_u64s;
    u8 data[0];
} __attribute__((packed)) ip6_hop_by_hop_ext_t;
typedef struct {
    u8 next_hdr;
    u8 rsv;
    u16 fragment_offset_and_more;
    u32 identification;
} __attribute__((packed)) ip6_frag_hdr_t;
typedef u32 mpls_label_t;
typedef struct {
    mpls_label_t label_exp_s_ttl;
} mpls_unicast_header_t;
typedef enum mpls_eos_bit_t_ {
    MPLS_NON_EOS = 0,
    MPLS_EOS     = 1,
} mpls_eos_bit_t;
static inline u8
ip_dscp_to_mpls_exp(u8 tos)
{
    return (tos >> 5);
}
static inline u8
mpls_exp_to_ip_dscp(u8 exp)
{
    return (exp << 5);
}
static inline u32
vnet_mpls_uc_get_label(mpls_label_t label_exp_s_ttl)
{
    return (label_exp_s_ttl >> 12);
}
static inline u32
vnet_mpls_uc_get_exp(mpls_label_t label_exp_s_ttl)
{
    return ((((label_exp_s_ttl) >> 9) & 0x07));
}
static inline u32
vnet_mpls_uc_get_s(mpls_label_t label_exp_s_ttl)
{
    return ((((label_exp_s_ttl) >> 8) & 0x01));
}
static inline u32
vnet_mpls_uc_get_ttl(mpls_label_t label_exp_s_ttl)
{
    return ((((label_exp_s_ttl) >> 0) & 0xff));
}
static inline void
vnet_mpls_uc_set_label(mpls_label_t *label_exp_s_ttl, u32 value)
{
    *label_exp_s_ttl = (((*label_exp_s_ttl) & ~((0x000fffff << 12))) | ((value & 0x000fffff) << 12));
}
static inline void
vnet_mpls_uc_set_exp(mpls_label_t *label_exp_s_ttl, u32 exp)
{
    *label_exp_s_ttl = (((*label_exp_s_ttl) & ~((0x07 << 9))) | ((exp & 0x07) << 9));
}
static inline void
vnet_mpls_uc_set_s(mpls_label_t *label_exp_s_ttl, u32 eos)
{
    *label_exp_s_ttl = (((*label_exp_s_ttl) & ~((0x01 << 8))) | ((eos & 0x01) << 8));
}
static inline void
vnet_mpls_uc_set_ttl(mpls_label_t *label_exp_s_ttl, u32 ttl)
{
    *label_exp_s_ttl = (((*label_exp_s_ttl) & ~((0xff << 0))) | ((ttl & 0xff)));
}
typedef u32 index_t;
typedef enum dpo_proto_t_ {
    DPO_PROTO_IP4 = 0,
    DPO_PROTO_IP6,
    DPO_PROTO_MPLS,
    DPO_PROTO_ETHERNET,
    DPO_PROTO_BIER,
    DPO_PROTO_NSH,
} __attribute__((packed)) dpo_proto_t;
typedef enum dpo_type_t_ {
    DPO_FIRST,
    DPO_DROP,
    DPO_IP_NULL,
    DPO_PUNT,
    DPO_LOAD_BALANCE,
    DPO_REPLICATE,
    DPO_ADJACENCY,
    DPO_ADJACENCY_INCOMPLETE,
    DPO_ADJACENCY_MIDCHAIN,
    DPO_ADJACENCY_GLEAN,
    DPO_ADJACENCY_MCAST,
    DPO_ADJACENCY_MCAST_MIDCHAIN,
    DPO_RECEIVE,
    DPO_LOOKUP,
    DPO_LISP_CP,
    DPO_CLASSIFY,
    DPO_MPLS_DISPOSITION_PIPE,
    DPO_MPLS_DISPOSITION_UNIFORM,
    DPO_MFIB_ENTRY,
    DPO_INTERFACE_RX,
    DPO_INTERFACE_TX,
    DPO_DVR,
    DPO_L3_PROXY,
    DPO_BIER_TABLE,
    DPO_BIER_FMASK,
    DPO_BIER_IMP,
    DPO_BIER_DISP_TABLE,
    DPO_BIER_DISP_ENTRY,
    DPO_IP6_LL,
    DPO_LAST,
} __attribute__((packed)) dpo_type_t;
typedef struct dpo_id_t_ {
    dpo_type_t dpoi_type;
    dpo_proto_t dpoi_proto;
    u16 dpoi_next_node;
    index_t dpoi_index;
} __attribute__((aligned(sizeof(u64)))) dpo_id_t;
_Static_assert(sizeof(dpo_id_t) <= sizeof(u64), "DPO ID is greater than sizeof u64 "
                                                "atomic updates need to be revisited");
static inline int
dpo_id_is_valid(const dpo_id_t *dpoi)
{
    return (dpoi->dpoi_type != DPO_FIRST && dpoi->dpoi_index != ((index_t)(~0)));
}
extern dpo_proto_t vnet_link_to_dpo_proto(vnet_link_t linkt);
extern void dpo_lock(dpo_id_t *dpo);
extern void dpo_unlock(dpo_id_t *dpo);
extern void dpo_mk_interpose(const dpo_id_t *original, const dpo_id_t *parent, dpo_id_t *clone);
extern void dpo_set(dpo_id_t *dpo, dpo_type_t type, dpo_proto_t proto, index_t index);
extern void dpo_reset(dpo_id_t *dpo);
extern int dpo_cmp(const dpo_id_t *dpo1, const dpo_id_t *dpo2);
extern void dpo_copy(dpo_id_t *dst, const dpo_id_t *src);
extern int dpo_is_adj(const dpo_id_t *dpo);
extern u8 *format_dpo_id(u8 *s, va_list *args);
extern u8 *format_dpo_type(u8 *s, va_list *args);
extern u8 *format_dpo_proto(u8 *s, va_list *args);
extern vnet_link_t dpo_proto_to_link(dpo_proto_t dp);
extern void dpo_stack(dpo_type_t child_type, dpo_proto_t child_proto, dpo_id_t *dpo, const dpo_id_t *parent_dpo);
extern void dpo_stack_from_node(u32 child_node, dpo_id_t *dpo, const dpo_id_t *parent);
extern u32 dpo_get_urpf(const dpo_id_t *dpo);
typedef void (*dpo_lock_fn_t)(dpo_id_t *dpo);
typedef void (*dpo_unlock_fn_t)(dpo_id_t *dpo);
typedef void (*dpo_mem_show_t)(void);
typedef u32 *(*dpo_get_next_node_t)(const dpo_id_t *dpo);
typedef u32 (*dpo_get_urpf_t)(const dpo_id_t *dpo);
typedef void (*dpo_mk_interpose_t)(const dpo_id_t *original, const dpo_id_t *parent, dpo_id_t *clone);
typedef struct dpo_vft_t_ {
    dpo_lock_fn_t dv_lock;
    dpo_lock_fn_t dv_unlock;
    format_function_t *dv_format;
    dpo_mem_show_t dv_mem_show;
    dpo_get_next_node_t dv_get_next_node;
    dpo_get_urpf_t dv_get_urpf;
    dpo_mk_interpose_t dv_mk_interpose;
} dpo_vft_t;
extern void dpo_register(dpo_type_t type, const dpo_vft_t *vft, const char *const *const *nodes);
extern dpo_type_t dpo_register_new_type(const dpo_vft_t *vft, const char *const *const *nodes);
extern u32 dpo_get_next_node_by_type_and_proto(dpo_type_t child_type, dpo_proto_t child_proto, dpo_type_t parent_type,
                                               dpo_proto_t parent_proto);
typedef enum bier_show_flags_t_ {
    BIER_SHOW_BRIEF,
    BIER_SHOW_DETAIL = (1 << 0),
} bier_show_flags_t;
typedef enum bier_table_type_t_ {
    BIER_TABLE_MPLS_SPF,
    BIER_TABLE_MPLS_TE,
} __attribute__((packed)) bier_table_type_t;
typedef enum bier_hdr_len_id_t_ {
    BIER_HDR_LEN_64 = 0,
    BIER_HDR_LEN_128,
    BIER_HDR_LEN_256,
    BIER_HDR_LEN_512,
    BIER_HDR_LEN_1024,
    BIER_HDR_LEN_2048,
    BIER_HDR_LEN_4096,
    BIER_HDR_LEN_INVALID,
} __attribute__((packed)) bier_hdr_len_id_t;
extern u8 *format_bier_hdr_len_id(u8 *s, va_list *ap);
static inline bier_hdr_len_id_t
bier_prefix_len_to_hdr_id(u16 prfx_len)
{
    switch (prfx_len) {
    case 7:
        return (BIER_HDR_LEN_64);
    case 8:
        return (BIER_HDR_LEN_128);
    case 9:
        return (BIER_HDR_LEN_256);
    case 10:
        return (BIER_HDR_LEN_512);
    case 11:
        return (BIER_HDR_LEN_1024);
    case 12:
        return (BIER_HDR_LEN_2048);
    case 13:
        return (BIER_HDR_LEN_4096);
    default:
        break;
    }
    return (BIER_HDR_LEN_INVALID);
}
static inline bier_hdr_len_id_t
bier_hdr_byte_len_to_id(u32 bytes)
{
    switch (bytes) {
    case 8:
        return (BIER_HDR_LEN_64);
    case 16:
        return (BIER_HDR_LEN_128);
    case 32:
        return (BIER_HDR_LEN_256);
    case 64:
        return (BIER_HDR_LEN_512);
    case 128:
        return (BIER_HDR_LEN_1024);
    case 256:
        return (BIER_HDR_LEN_2048);
    case 512:
        return (BIER_HDR_LEN_4096);
    }
    return (BIER_HDR_LEN_INVALID);
}
static inline bier_hdr_len_id_t
bier_hdr_bit_len_to_id(u32 bytes)
{
    switch (bytes) {
    case 64:
        return (BIER_HDR_LEN_64);
    case 128:
        return (BIER_HDR_LEN_128);
    case 256:
        return (BIER_HDR_LEN_256);
    case 512:
        return (BIER_HDR_LEN_512);
    case 1024:
        return (BIER_HDR_LEN_1024);
    case 2048:
        return (BIER_HDR_LEN_2048);
    case 4096:
        return (BIER_HDR_LEN_4096);
    }
    return (BIER_HDR_LEN_INVALID);
}
typedef enum bier_hdr_len_num_buckets_t_ {
    BIER_HDR_BUCKETS_64   = 8,
    BIER_HDR_BUCKETS_128  = 16,
    BIER_HDR_BUCKETS_256  = 32,
    BIER_HDR_BUCKETS_512  = 64,
    BIER_HDR_BUCKETS_1024 = 128,
    BIER_HDR_BUCKETS_2048 = 256,
    BIER_HDR_BUCKETS_4096 = 512,
} bier_hdr_len_num_buckets_t;
typedef enum bier_hdr_proto_id_t_ {
    BIER_HDR_PROTO_INVALID = 0,
    BIER_HDR_PROTO_MPLS_DOWN_STREAM,
    BIER_HDR_PROTO_MPLS_UP_STREAM,
    BIER_HDR_PROTO_ETHERNET,
    BIER_HDR_PROTO_IPV4,
    BIER_HDR_PROTO_IPV6,
    BIER_HDR_PROTO_VXLAN,
    BIER_HDR_PROTO_CTRL,
    BIER_HDR_PROTO_OAM,
} __attribute__((packed)) bier_hdr_proto_id_t;
extern u8 *format_bier_hdr_proto(u8 *s, va_list *ap);
extern dpo_proto_t bier_hdr_proto_to_dpo(bier_hdr_proto_id_t bproto);
typedef enum bier_hdr_version_t_ {
    BIER_HDR_VERSION_1 = 0,
} __attribute__((packed)) bier_hdr_version_t;
typedef enum bier_hdr_code_t_ {
    BIER_HDR_CODE_OAM_IPV4  = 0,
    BIER_HDR_CODE_OAM_IPV6  = 1,
    BIER_HDR_CODE_CTRL_IPV4 = 2,
    BIER_HDR_CODE_CTRL_IPV6 = 3,
} __attribute__((packed)) bier_hdr_code_t;
typedef enum bier_hdr_oam_sub_code_t_ {
    BIER_HDR_SUB_CODE_OAM_PING_REQ  = 0,
    BIER_HDR_SUB_CODE_OAM_PING_RESP = 1,
} __attribute__((packed)) bier_hdr_oam_sub_code_t;
typedef enum bier_hdr_ctrl_sub_code_t_ {
    BIER_HDR_SUB_CODE_CTRL_MEMBER_REQ   = 0,
    BIER_HDR_SUB_CODE_CTRL_ATTACHED_NET = 1,
} __attribute__((packed)) bier_hdr_ctrl_sub_code_t;
typedef u8 bier_bit_mask_bucket_t;
typedef struct bier_bit_string_t_ {
    u16 bbs_len;
    bier_bit_mask_bucket_t *bbs_buckets;
} bier_bit_string_t;
typedef u32 bier_bp_t;
typedef u16 bier_hdr_src_id_t;
typedef u32 bier_hdr_entropy_t;
typedef struct bier_hdr_t_ {
    u32 bh_first_word;
    u16 bh_oam_dscp_proto;
    u16 bh_bfr_id;
    bier_bit_mask_bucket_t bh_bit_string[0];
} bier_hdr_t;
extern u8 *format_bier_hdr(u8 *s, va_list *ap);
typedef u32 bier_table_set_id_t;
typedef u32 bier_table_sub_domain_id_t;
typedef u32 bier_table_ecmp_id_t;
typedef struct bier_table_id_t_ {
    bier_table_set_id_t bti_set;
    bier_table_sub_domain_id_t bti_sub_domain;
    bier_table_ecmp_id_t bti_ecmp;
    bier_hdr_len_id_t bti_hdr_len;
    bier_table_type_t bti_type;
} bier_table_id_t;
extern u8 *format_bier_table_id(u8 *s, va_list *ap);
extern int bier_table_id_cmp(const bier_table_id_t *btid1, const bier_table_id_t *btid2);
extern u32 bier_hdr_len_id_to_num_buckets(bier_hdr_len_id_t id);
extern u32 bier_hdr_len_id_to_num_bytes(bier_hdr_len_id_t id);
extern u32 bier_hdr_len_id_to_max_bucket(bier_hdr_len_id_t id);
extern u32 bier_hdr_len_id_to_num_bits(bier_hdr_len_id_t id);
extern u32 bier_hdr_len_id_to_max_bit(bier_hdr_len_id_t id);
extern u32 bier_hdr_len_id_to_prefix_len(bier_hdr_len_id_t id);
typedef int bier_rc;
typedef u32 bier_bift_id_t;
extern u16 bier_bfit_id_get_sub_domain(bier_bift_id_t bift_id);
extern u16 bier_bfit_id_get_set(bier_bift_id_t bift_id);
extern bier_hdr_proto_id_t bier_bift_id_get_bit_string_length(bier_bift_id_t bift_id);
extern bier_bift_id_t bier_bift_id_encode(bier_table_set_id_t set, bier_table_sub_domain_id_t sd, bier_hdr_len_id_t bsl);
extern void bier_bift_id_decode(bier_bift_id_t id, bier_table_set_id_t *set, bier_table_sub_domain_id_t *sd,
                                bier_hdr_len_id_t *bsl);
extern u8 *format_bier_bift_id(u8 *s, va_list *ap);
typedef u32 fib_node_index_t;
typedef enum fib_protocol_t_ {
    FIB_PROTOCOL_IP4  = DPO_PROTO_IP4,
    FIB_PROTOCOL_IP6  = DPO_PROTO_IP6,
    FIB_PROTOCOL_MPLS = DPO_PROTO_MPLS,
} __attribute__((packed)) fib_protocol_t;
static inline fib_protocol_t
fib_ip_proto(_Bool is_ip6)
{
    return (is_ip6) ? FIB_PROTOCOL_IP6 : FIB_PROTOCOL_IP4;
}
extern ip46_type_t fib_proto_to_ip46(fib_protocol_t fproto);
extern fib_protocol_t fib_proto_from_ip46(ip46_type_t iproto);
vnet_link_t fib_proto_to_link(fib_protocol_t proto);
typedef enum fib_forward_chain_type_t_ {
    FIB_FORW_CHAIN_TYPE_UNICAST_IP4,
    FIB_FORW_CHAIN_TYPE_UNICAST_IP6,
    FIB_FORW_CHAIN_TYPE_MPLS_NON_EOS,
    FIB_FORW_CHAIN_TYPE_BIER,
    FIB_FORW_CHAIN_TYPE_MPLS_EOS,
    FIB_FORW_CHAIN_TYPE_MCAST_IP4,
    FIB_FORW_CHAIN_TYPE_MCAST_IP6,
    FIB_FORW_CHAIN_TYPE_ETHERNET,
    FIB_FORW_CHAIN_TYPE_NSH,
} __attribute__((packed)) fib_forward_chain_type_t;
extern vnet_link_t fib_forw_chain_type_to_link_type(fib_forward_chain_type_t fct);
extern fib_forward_chain_type_t fib_forw_chain_type_from_link_type(vnet_link_t lt);
extern fib_forward_chain_type_t fib_forw_chain_type_from_dpo_proto(dpo_proto_t proto);
extern fib_forward_chain_type_t fib_forw_chain_type_from_fib_proto(fib_protocol_t proto);
extern dpo_proto_t fib_forw_chain_type_to_dpo_proto(fib_forward_chain_type_t fct);
typedef struct fib_prefix_t_ {
    u16 fp_len;
    fib_protocol_t fp_proto;
    u8 ___fp___pad;
    union {
        ip46_address_t fp_addr;
        struct {
            mpls_label_t fp_label;
            mpls_eos_bit_t fp_eos;
            dpo_proto_t fp_payload_proto;
        };
    };
} fib_prefix_t;
_Static_assert(((uword) & (((fib_prefix_t *) 0)->fp_addr)) == 4, "FIB Prefix's address is 4 byte aligned.");
extern int fib_prefix_cmp(const fib_prefix_t *p1, const fib_prefix_t *p2);
extern int fib_prefix_is_cover(const fib_prefix_t *p1, const fib_prefix_t *p2);
extern int fib_prefix_is_host(const fib_prefix_t *p);
extern void fib_prefix_from_ip46_addr(const ip46_address_t *addr, fib_prefix_t *pfx);
extern u8 *format_fib_prefix(u8 *s, va_list *args);
extern u8 *format_fib_forw_chain_type(u8 *s, va_list *args);
extern dpo_proto_t fib_proto_to_dpo(fib_protocol_t fib_proto);
extern fib_protocol_t dpo_proto_to_fib(dpo_proto_t dpo_proto);
extern fib_protocol_t bier_hdr_proto_to_fib(bier_hdr_proto_id_t bproto);
typedef enum fib_special_type_t_ {
    FIB_SPECIAL_TYPE_FIRST = 0,
    FIB_SPECIAL_TYPE_LOCAL = FIB_SPECIAL_TYPE_FIRST,
    FIB_SPECIAL_TYPE_DROP,
    FIB_SPECIAL_TYPE_LAST = FIB_SPECIAL_TYPE_DROP,
} __attribute__((packed)) fib_special_type_t;
extern u8 *format_fib_protocol(u8 *s, va_list *ap);
extern u8 *format_vnet_link(u8 *s, va_list *ap);
typedef enum fib_route_path_flags_t_ {
    FIB_ROUTE_PATH_FLAG_NONE            = 0,
    FIB_ROUTE_PATH_RESOLVE_VIA_HOST     = (1 << 0),
    FIB_ROUTE_PATH_RESOLVE_VIA_ATTACHED = (1 << 1),
    FIB_ROUTE_PATH_LOCAL                = (1 << 2),
    FIB_ROUTE_PATH_ATTACHED             = (1 << 3),
    FIB_ROUTE_PATH_DROP                 = (1 << 4),
    FIB_ROUTE_PATH_EXCLUSIVE            = (1 << 5),
    FIB_ROUTE_PATH_INTF_RX              = (1 << 6),
    FIB_ROUTE_PATH_RPF_ID               = (1 << 7),
    FIB_ROUTE_PATH_SOURCE_LOOKUP        = (1 << 8),
    FIB_ROUTE_PATH_UDP_ENCAP            = (1 << 9),
    FIB_ROUTE_PATH_BIER_FMASK           = (1 << 10),
    FIB_ROUTE_PATH_BIER_TABLE           = (1 << 11),
    FIB_ROUTE_PATH_BIER_IMP             = (1 << 12),
    FIB_ROUTE_PATH_DEAG                 = (1 << 13),
    FIB_ROUTE_PATH_DVR                  = (1 << 14),
} fib_route_path_flags_t;
typedef u32 fib_rpf_id_t;
typedef enum fib_mpls_lsp_mode_t_ {
    FIB_MPLS_LSP_MODE_PIPE,
    FIB_MPLS_LSP_MODE_UNIFORM,
} __attribute__((packed)) fib_mpls_lsp_mode_t;
extern u8 *format_fib_mpls_lsp_mode(u8 *s, va_list *ap);
typedef struct fib_mpls_label_t_ {
    mpls_label_t fml_value;
    fib_mpls_lsp_mode_t fml_mode;
    u8 fml_ttl;
    u8 fml_exp;
} fib_mpls_label_t;
extern u8 *format_fib_mpls_label(u8 *s, va_list *ap);
typedef struct fib_route_path_t_ {
    dpo_proto_t frp_proto;
    union {
        struct {
            union {
                ip46_address_t frp_addr;
                struct {
                    mpls_label_t frp_local_label;
                    mpls_eos_bit_t frp_eos;
                };
            };
            union {
                u32 frp_sw_if_index;
                fib_rpf_id_t frp_rpf_id;
            };
            union {
                u32 frp_fib_index;
                u32 frp_bier_fib_index;
            };
            fib_mpls_label_t *frp_label_stack;
            dpo_id_t dpo;
        };
        bier_table_id_t frp_bier_tbl;
        index_t frp_bier_imp;
        u32 frp_udp_encap_id;
        index_t frp_bier_fmask;
    };
    u8 frp_weight;
    u8 frp_preference;
    fib_route_path_flags_t frp_flags;
} fib_route_path_t;
extern uword unformat_fib_route_path(unformat_input_t *input, va_list *args);
typedef struct fib_route_path_encode_t_ {
    fib_route_path_t rpath;
    dpo_id_t dpo;
} fib_route_path_encode_t;
typedef enum fib_path_list_walk_rc_t_ {
    FIB_PATH_LIST_WALK_STOP,
    FIB_PATH_LIST_WALK_CONTINUE,
} fib_path_list_walk_rc_t;
typedef struct fib_path_ext_list_t_ {
    struct fib_path_ext_t_ *fpel_exts;
} fib_path_ext_list_t;
typedef enum fib_node_type_t_ {
    FIB_NODE_TYPE_FIRST = 0,
    FIB_NODE_TYPE_WALK,
    FIB_NODE_TYPE_ENTRY,
    FIB_NODE_TYPE_MFIB_ENTRY,
    FIB_NODE_TYPE_PATH_LIST,
    FIB_NODE_TYPE_PATH,
    FIB_NODE_TYPE_ADJ,
    FIB_NODE_TYPE_MPLS_ENTRY,
    FIB_NODE_TYPE_MPLS_TUNNEL,
    FIB_NODE_TYPE_LISP_GPE_FWD_ENTRY,
    FIB_NODE_TYPE_LISP_ADJ,
    FIB_NODE_TYPE_GRE_TUNNEL,
    FIB_NODE_TYPE_VXLAN_TUNNEL,
    FIB_NODE_TYPE_MAP_E,
    FIB_NODE_TYPE_VXLAN_GPE_TUNNEL,
    FIB_NODE_TYPE_GENEVE_TUNNEL,
    FIB_NODE_TYPE_UDP_ENCAP,
    FIB_NODE_TYPE_BIER_FMASK,
    FIB_NODE_TYPE_BIER_ENTRY,
    FIB_NODE_TYPE_VXLAN_GBP_TUNNEL,
    FIB_NODE_TYPE_TEST,
    FIB_NODE_TYPE_LAST = FIB_NODE_TYPE_TEST,
} __attribute__((packed)) fib_node_type_t;
typedef enum fib_node_back_walk_reason_t_ {
    FIB_NODE_BW_REASON_FIRST   = 0,
    FIB_NODE_BW_REASON_RESOLVE = FIB_NODE_BW_REASON_FIRST,
    FIB_NODE_BW_REASON_EVALUATE,
    FIB_NODE_BW_REASON_INTERFACE_UP,
    FIB_NODE_BW_REASON_INTERFACE_DOWN,
    FIB_NODE_BW_REASON_INTERFACE_DELETE,
    FIB_NODE_BW_REASON_ADJ_UPDATE,
    FIB_NODE_BW_REASON_ADJ_DOWN,
    FIB_NODE_BW_REASON_LAST = FIB_NODE_BW_REASON_ADJ_DOWN,
} fib_node_back_walk_reason_t;
typedef enum fib_node_bw_reason_flag_t_ {
    FIB_NODE_BW_REASON_FLAG_NONE             = 0,
    FIB_NODE_BW_REASON_FLAG_RESOLVE          = (1 << FIB_NODE_BW_REASON_RESOLVE),
    FIB_NODE_BW_REASON_FLAG_EVALUATE         = (1 << FIB_NODE_BW_REASON_EVALUATE),
    FIB_NODE_BW_REASON_FLAG_INTERFACE_UP     = (1 << FIB_NODE_BW_REASON_INTERFACE_UP),
    FIB_NODE_BW_REASON_FLAG_INTERFACE_DOWN   = (1 << FIB_NODE_BW_REASON_INTERFACE_DOWN),
    FIB_NODE_BW_REASON_FLAG_INTERFACE_DELETE = (1 << FIB_NODE_BW_REASON_INTERFACE_DELETE),
    FIB_NODE_BW_REASON_FLAG_ADJ_UPDATE       = (1 << FIB_NODE_BW_REASON_ADJ_UPDATE),
    FIB_NODE_BW_REASON_FLAG_ADJ_DOWN         = (1 << FIB_NODE_BW_REASON_ADJ_DOWN),
} __attribute__((packed)) fib_node_bw_reason_flag_t;
_Static_assert(sizeof(fib_node_bw_reason_flag_t) < 2, "BW Reason enum < 2 byte. Consequences for cover_upd_res_t");
typedef enum fib_node_bw_flags_t_ {
    FIB_NODE_BW_FLAG_NONE       = 0,
    FIB_NODE_BW_FLAG_FORCE_SYNC = (1 << 0),
} fib_node_bw_flags_t;
struct fib_node_t_;
typedef struct fib_node_ptr_t_ {
    fib_node_type_t fnp_type;
    fib_node_index_t fnp_index;
} fib_node_ptr_t;
typedef u32 fib_node_list_t;
typedef struct fib_node_back_walk_ctx_t_ {
    fib_node_bw_reason_flag_t fnbw_reason;
    fib_node_bw_flags_t fnbw_flags;
    u32 fnbw_depth;
} fib_node_back_walk_ctx_t;
typedef int (*fib_node_ptr_walk_t)(fib_node_ptr_t *depend, void *ctx);
typedef fib_node_ptr_t fib_node_ptr_list_t;
typedef enum fib_node_back_walk_rc_t_ {
    FIB_NODE_BACK_WALK_MERGE,
    FIB_NODE_BACK_WALK_CONTINUE,
} fib_node_back_walk_rc_t;
typedef fib_node_back_walk_rc_t (*fib_node_back_walk_t)(struct fib_node_t_ *node, fib_node_back_walk_ctx_t *ctx);
typedef struct fib_node_t_ *(*fib_node_get_t)(fib_node_index_t index);
typedef void (*fib_node_last_lock_gone_t)(struct fib_node_t_ *node);
typedef void (*fib_node_memory_show_t)(void);
typedef struct fib_node_vft_t_ {
    fib_node_get_t fnv_get;
    fib_node_last_lock_gone_t fnv_last_lock;
    fib_node_back_walk_t fnv_back_walk;
    format_function_t *fnv_format;
    fib_node_memory_show_t fnv_mem_show;
} fib_node_vft_t;
typedef struct fib_node_t_ {
    fib_node_type_t fn_type;
    u16 fn_pad;
    fib_node_list_t fn_children;
    u32 fn_locks;
} fib_node_t;
_Static_assert(sizeof(fib_node_t) == 12, "FIB node type is growing");
extern void fib_node_register_type(fib_node_type_t ft, const fib_node_vft_t *vft);
extern fib_node_type_t fib_node_register_new_type(const fib_node_vft_t *vft);
extern void fib_show_memory_usage(const char *name, u32 in_use_elts, u32 allocd_elts, size_t size_elt);
extern void fib_node_init(fib_node_t *node, fib_node_type_t ft);
extern void fib_node_deinit(fib_node_t *node);
extern void fib_node_lock(fib_node_t *node);
extern void fib_node_unlock(fib_node_t *node);
extern u32 fib_node_get_n_children(fib_node_type_t parent_type, fib_node_index_t parent_index);
extern u32 fib_node_child_add(fib_node_type_t parent_type, fib_node_index_t parent_index, fib_node_type_t child_type,
                              fib_node_index_t child_index);
extern void fib_node_child_remove(fib_node_type_t parent_type, fib_node_index_t parent_index,
                                  fib_node_index_t sibling_index);
extern fib_node_back_walk_rc_t fib_node_back_walk_one(fib_node_ptr_t *ptr, fib_node_back_walk_ctx_t *ctx);
extern u8 *fib_node_children_format(fib_node_list_t list, u8 *s);
extern const char *fib_node_type_get_name(fib_node_type_t type);
static inline int
fib_node_index_is_valid(fib_node_index_t ni)
{
    return (((fib_node_index_t)(~0)) != ni);
}
typedef u32 adj_index_t;
typedef enum adj_walk_rc_t_ {
    ADJ_WALK_RC_STOP,
    ADJ_WALK_RC_CONTINUE,
} adj_walk_rc_t;
typedef adj_walk_rc_t (*adj_walk_cb_t)(adj_index_t ai, void *ctx);
extern adj_index_t adj_nbr_add_or_lock(fib_protocol_t nh_proto, vnet_link_t link_type, const ip46_address_t *nh_addr,
                                       u32 sw_if_index);
extern adj_index_t adj_nbr_add_or_lock_w_rewrite(fib_protocol_t nh_proto, vnet_link_t link_type,
                                                 const ip46_address_t *nh_addr, u32 sw_if_index, u8 *rewrite);
typedef enum adj_nbr_rewrite_flag_t_ {
    ADJ_NBR_REWRITE_FLAG_NONE,
    ADJ_NBR_REWRITE_FLAG_INCOMPLETE = ADJ_NBR_REWRITE_FLAG_NONE,
    ADJ_NBR_REWRITE_FLAG_COMPLETE   = (1 << 0),
} adj_nbr_rewrite_flag_t;
extern void adj_nbr_update_rewrite(adj_index_t adj_index, adj_nbr_rewrite_flag_t flags, u8 *rewrite);
extern u8 *format_adj_nbr_incomplete(u8 *s, va_list *ap);
extern u8 *format_adj_nbr(u8 *s, va_list *ap);
extern void adj_nbr_walk(u32 sw_if_index, fib_protocol_t adj_nh_proto, adj_walk_cb_t cb, void *ctx);
void adj_nbr_walk_nh(u32 sw_if_index, fib_protocol_t adj_nh_proto, const ip46_address_t *nh, adj_walk_cb_t cb, void *ctx);
void adj_nbr_walk_nh4(u32 sw_if_index, const ip4_address_t *addr, adj_walk_cb_t cb, void *ctx);
void adj_nbr_walk_nh6(u32 sw_if_index, const ip6_address_t *addr, adj_walk_cb_t cb, void *ctx);
adj_index_t adj_nbr_find(fib_protocol_t nh_proto, vnet_link_t link_type, const ip46_address_t *nh_addr, u32 sw_if_index);
extern void adj_nbr_module_init(void);
extern u32 adj_nbr_db_size(void);
extern adj_index_t adj_glean_add_or_lock(fib_protocol_t proto, vnet_link_t linkt, u32 sw_if_index,
                                         const ip46_address_t *nh_addr);
extern adj_index_t adj_glean_get(fib_protocol_t proto, u32 sw_if_index);
extern void adj_glean_update_rewrite(adj_index_t adj_index);
extern u8 *format_adj_glean(u8 *s, va_list *ap);
extern void adj_glean_module_init(void);
typedef uword vnet_rewrite_data_t;
typedef enum vnet_rewrite_flags_t_ {
    VNET_REWRITE_HAS_FEATURES = (1 << 0),
} __attribute__((packed)) vnet_rewrite_flags_t;
typedef struct {
    u32 sw_if_index;
    u16 next_index;
    u16 data_bytes;
    u16 max_l3_packet_bytes;
    vnet_rewrite_flags_t flags;
    u8 dst_mcast_offset;
    u8 data[0];
} __attribute__((packed)) vnet_rewrite_header_t;
_Static_assert(sizeof(vnet_rewrite_header_t) <= 16, "Rewrite header too big");
static inline __attribute__((__always_inline__)) void
vnet_rewrite_clear_data_internal(vnet_rewrite_header_t *rw, int max_size)
{
    do {
        if ((0 > 0) && !((max_size > 0) && (max_size < 128))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/adj/rewrite.h", (uword) 119,
                        ((char *) __FUNCTION__), "(max_size > 0) && (max_size < VLIB_BUFFER_PRE_DATA_SIZE)");
        }
    } while (0);
    rw->data_bytes = 0;
    memset(rw->data, 0xfe, max_size);
}
static inline __attribute__((__always_inline__)) void
vnet_rewrite_set_data_internal(vnet_rewrite_header_t *rw, int max_size, void *data, int data_bytes)
{
    do {
        if ((0 > 0) && !((max_size > 0) && (max_size < 128))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/adj/rewrite.h", (uword) 130,
                        ((char *) __FUNCTION__), "(max_size > 0) && (max_size < VLIB_BUFFER_PRE_DATA_SIZE)");
        }
    } while (0);
    do {
        if ((0 > 0) && !((data_bytes >= 0) && (data_bytes < max_size))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/adj/rewrite.h", (uword) 131,
                        ((char *) __FUNCTION__), "(data_bytes >= 0) && (data_bytes < max_size)");
        }
    } while (0);
    rw->data_bytes = data_bytes;
    memcpy(rw->data + max_size - data_bytes, data, data_bytes);
    memset(rw->data, 0xfe, max_size - data_bytes);
}
static inline __attribute__((__always_inline__)) void *
vnet_rewrite_get_data_internal(vnet_rewrite_header_t *rw, int max_size)
{
    do {
        if ((0 > 0) && !(rw->data_bytes <= max_size)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/adj/rewrite.h", (uword) 147,
                        ((char *) __FUNCTION__), "rw->data_bytes <= max_size");
        }
    } while (0);
    return rw->data + max_size - rw->data_bytes;
}
static inline __attribute__((__always_inline__)) void
vnet_rewrite_copy_one(vnet_rewrite_data_t *p0, vnet_rewrite_data_t *rw0, int i)
{
    p0[-i] = rw0[-i];
}
void vnet_rewrite_copy_slow_path(vnet_rewrite_data_t *p0, vnet_rewrite_data_t *rw0, word n_left, uword most_likely_size);
typedef struct {
    u64 a;
    u32 b;
    u16 c;
} __attribute__((packed)) eh_copy_t;
static inline __attribute__((__always_inline__)) void
_vnet_rewrite_one_header(vnet_rewrite_header_t *h0, void *packet0, int max_size, int most_likely_size)
{
    vnet_rewrite_data_t *p0  = packet0;
    vnet_rewrite_data_t *rw0 = (vnet_rewrite_data_t *) (h0->data + max_size);
    word n_left0;
    do {
        if ((0 > 0) && !(h0->data_bytes != 0xfefe)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/adj/rewrite.h", (uword) 182,
                        ((char *) __FUNCTION__), "h0->data_bytes != 0xfefe");
        }
    } while (0);
    if (__builtin_expect((h0->data_bytes == sizeof(eh_copy_t)), 1)) {
        eh_copy_t *s, *d;
        s = (eh_copy_t *) (h0->data + max_size - sizeof(eh_copy_t));
        d = (eh_copy_t *) (((u8 *) packet0) - sizeof(eh_copy_t));
        memcpy(d, s, sizeof(eh_copy_t));
        return;
    }
    do {
        if (most_likely_size > ((4) - 1) * sizeof(vnet_rewrite_data_t))
            vnet_rewrite_copy_one(p0, rw0, (4));
    } while (0);
    do {
        if (most_likely_size > ((3) - 1) * sizeof(vnet_rewrite_data_t))
            vnet_rewrite_copy_one(p0, rw0, (3));
    } while (0);
    do {
        if (most_likely_size > ((2) - 1) * sizeof(vnet_rewrite_data_t))
            vnet_rewrite_copy_one(p0, rw0, (2));
    } while (0);
    do {
        if (most_likely_size > ((1) - 1) * sizeof(vnet_rewrite_data_t))
            vnet_rewrite_copy_one(p0, rw0, (1));
    } while (0);
    n_left0 = (int) (((int) h0->data_bytes - most_likely_size) + (sizeof(rw0[0]) - 1)) / (int) sizeof(rw0[0]);
    if (__builtin_expect((n_left0 > 0), 0))
        vnet_rewrite_copy_slow_path(p0, rw0, n_left0, most_likely_size);
}
static inline __attribute__((__always_inline__)) void
_vnet_rewrite_two_headers(vnet_rewrite_header_t *h0, vnet_rewrite_header_t *h1, void *packet0, void *packet1,
                          int max_size, int most_likely_size)
{
    vnet_rewrite_data_t *p0  = packet0;
    vnet_rewrite_data_t *p1  = packet1;
    vnet_rewrite_data_t *rw0 = (vnet_rewrite_data_t *) (h0->data + max_size);
    vnet_rewrite_data_t *rw1 = (vnet_rewrite_data_t *) (h1->data + max_size);
    word n_left0, n_left1;
    int slow_path;
    do {
        if ((0 > 0) && !(h0->data_bytes != 0xfefe)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/adj/rewrite.h", (uword) 228,
                        ((char *) __FUNCTION__), "h0->data_bytes != 0xfefe");
        }
    } while (0);
    do {
        if ((0 > 0) && !(h1->data_bytes != 0xfefe)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/adj/rewrite.h", (uword) 229,
                        ((char *) __FUNCTION__), "h1->data_bytes != 0xfefe");
        }
    } while (0);
    slow_path = h0->data_bytes ^ h1->data_bytes;
    slow_path += h0->data_bytes ^ sizeof(eh_copy_t);
    if (__builtin_expect((slow_path == 0), 1)) {
        eh_copy_t *s0, *d0, *s1, *d1;
        s0 = (eh_copy_t *) (h0->data + max_size - sizeof(eh_copy_t));
        d0 = (eh_copy_t *) (((u8 *) packet0) - sizeof(eh_copy_t));
        memcpy(d0, s0, sizeof(eh_copy_t));
        s1 = (eh_copy_t *) (h1->data + max_size - sizeof(eh_copy_t));
        d1 = (eh_copy_t *) (((u8 *) packet1) - sizeof(eh_copy_t));
        memcpy(d1, s1, sizeof(eh_copy_t));
        return;
    }
    do {
        if (most_likely_size > ((4) - 1) * sizeof(vnet_rewrite_data_t)) {
            vnet_rewrite_copy_one(p0, rw0, (4));
            vnet_rewrite_copy_one(p1, rw1, (4));
        }
    } while (0);
    do {
        if (most_likely_size > ((3) - 1) * sizeof(vnet_rewrite_data_t)) {
            vnet_rewrite_copy_one(p0, rw0, (3));
            vnet_rewrite_copy_one(p1, rw1, (3));
        }
    } while (0);
    do {
        if (most_likely_size > ((2) - 1) * sizeof(vnet_rewrite_data_t)) {
            vnet_rewrite_copy_one(p0, rw0, (2));
            vnet_rewrite_copy_one(p1, rw1, (2));
        }
    } while (0);
    do {
        if (most_likely_size > ((1) - 1) * sizeof(vnet_rewrite_data_t)) {
            vnet_rewrite_copy_one(p0, rw0, (1));
            vnet_rewrite_copy_one(p1, rw1, (1));
        }
    } while (0);
    n_left0 = (int) (((int) h0->data_bytes - most_likely_size) + (sizeof(rw0[0]) - 1)) / (int) sizeof(rw0[0]);
    n_left1 = (int) (((int) h1->data_bytes - most_likely_size) + (sizeof(rw1[0]) - 1)) / (int) sizeof(rw1[0]);
    if (__builtin_expect((n_left0 > 0 || n_left1 > 0), 0)) {
        vnet_rewrite_copy_slow_path(p0, rw0, n_left0, most_likely_size);
        vnet_rewrite_copy_slow_path(p1, rw1, n_left1, most_likely_size);
    }
}
static inline __attribute__((__always_inline__)) void
vnet_ip_mcast_fixup_header(u32 dst_mcast_mask, u32 dst_mcast_offset, u32 *addr, u8 *packet0)
{
    if (__builtin_expect((0 != dst_mcast_offset), 1)) {
        u8 *p0  = packet0 - dst_mcast_offset;
        u32 *p1 = (u32 *) p0;
        *p1 |= (*addr & dst_mcast_mask);
    }
}
void vnet_rewrite_for_sw_interface(struct vnet_main_t *vnm, vnet_link_t packet_type, u32 sw_if_index, u32 node_index,
                                   void *dst_address, vnet_rewrite_header_t *rw, u32 max_rewrite_bytes);
u32 vnet_tx_node_index_for_sw_interface(struct vnet_main_t *vnm, u32 sw_if_index);
void vnet_rewrite_init(struct vnet_main_t *vnm, u32 sw_if_index, vnet_link_t linkt, u32 this_node, u32 next_node,
                       vnet_rewrite_header_t *rw);
void vnet_rewrite_update_mtu(struct vnet_main_t *vnm, vnet_link_t linkt, vnet_rewrite_header_t *rw);
u8 *vnet_build_rewrite_for_sw_interface(struct vnet_main_t *vnm, u32 sw_if_index, vnet_link_t packet_type,
                                        const void *dst_address);
void vnet_update_adjacency_for_sw_interface(struct vnet_main_t *vnm, u32 sw_if_index, u32 ai);
format_function_t format_vnet_rewrite;
serialize_function_t serialize_vnet_rewrite, unserialize_vnet_rewrite;
typedef enum {
    IP_LOOKUP_NEXT_DROP,
    IP_LOOKUP_NEXT_PUNT,
    IP_LOOKUP_NEXT_LOCAL,
    IP_LOOKUP_NEXT_ARP,
    IP_LOOKUP_NEXT_GLEAN,
    IP_LOOKUP_NEXT_REWRITE,
    IP_LOOKUP_NEXT_MIDCHAIN,
    IP_LOOKUP_NEXT_ICMP_ERROR,
    IP_LOOKUP_NEXT_MCAST,
    IP_LOOKUP_NEXT_BCAST,
    IP_LOOKUP_NEXT_MCAST_MIDCHAIN,
    IP_LOOKUP_N_NEXT,
} __attribute__((packed)) ip_lookup_next_t;
typedef enum {
    IP4_LOOKUP_N_NEXT = IP_LOOKUP_N_NEXT,
} ip4_lookup_next_t;
typedef enum {
    IP6_LOOKUP_NEXT_HOP_BY_HOP = IP_LOOKUP_N_NEXT,
    IP6_LOOKUP_NEXT_ADD_HOP_BY_HOP,
    IP6_LOOKUP_NEXT_POP_HOP_BY_HOP,
    IP6_LOOKUP_N_NEXT,
} ip6_lookup_next_t;
extern const ip46_address_t ADJ_BCAST_ADDR;
struct ip_adjacency_t_;
typedef void (*adj_midchain_fixup_t)(vlib_main_t *vm, struct ip_adjacency_t_ *adj, vlib_buffer_t *b0, const void *data);
typedef enum ip_adjacency_flags_t_ {
    ADJ_FLAG_NONE              = 0,
    ADJ_FLAG_SYNC_WALK_ACTIVE  = (1 << 0),
    ADJ_FLAG_MIDCHAIN_NO_COUNT = (1 << 1),
} __attribute__((packed)) adj_flags_t;
typedef struct ip_adjacency_t_ {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    fib_node_t ia_node;
    ip_lookup_next_t lookup_next_index;
    vnet_link_t ia_link;
    fib_protocol_t ia_nh_proto;
    adj_flags_t ia_flags;
    union {
        struct {
            ip46_address_t next_hop;
        } nbr;
        struct {
            ip46_address_t next_hop;
            dpo_id_t next_dpo;
            adj_midchain_fixup_t fixup_func;
            const void *fixup_data;
        } midchain;
        struct {
            ip46_address_t receive_addr;
        } glean;
    } sub_type;
    u8 cacheline1[0] __attribute__((aligned((1 << 6))));
    struct {
        vnet_rewrite_header_t rewrite_header;
        u8 rewrite_data[(128) - sizeof(vnet_rewrite_header_t)];
    };
    struct adj_delegate_t_ *ia_delegates;
} ip_adjacency_t;
_Static_assert((((uword) & (((ip_adjacency_t *) 0)->cacheline0)) == 0), "IP adjacency cachline 0 is not offset");
_Static_assert((((uword) & (((ip_adjacency_t *) 0)->cacheline1)) == (1 << 6)),
               "IP adjacency cachline 1 is more than one cachline size offset");
extern void adj_lock(adj_index_t adj_index);
extern void adj_unlock(adj_index_t adj_index);
extern u32 adj_child_add(adj_index_t adj_index, fib_node_type_t type, fib_node_index_t child_index);
extern void adj_child_remove(adj_index_t adj_index, u32 sibling_index);
extern void adj_walk(u32 sw_if_index, adj_walk_cb_t cb, void *ctx);
extern vnet_link_t adj_get_link_type(adj_index_t ai);
extern u32 adj_get_sw_if_index(adj_index_t ai);
extern int adj_is_up(adj_index_t ai);
extern const u8 *adj_get_rewrite(adj_index_t ai);
extern void adj_feature_update(u32 sw_if_index, u8 arc_index, u8 is_enable);
extern ip_adjacency_t *adj_pool;
extern vlib_combined_counter_main_t adjacency_counters;
extern int adj_per_adj_counters;
static inline ip_adjacency_t *
adj_get(adj_index_t adj_index)
{
    return (({
        do {
            if ((0 > 0) && !((adj_index) < ((adj_pool) ? (((vec_header_t *) (adj_pool) -1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/adj/adj.h", (uword) 382,
                            ((char *) __FUNCTION__), "(adj_index) < vec_len (adj_pool)");
            }
        } while (0);
        (adj_pool) + (adj_index);
    }));
}
static inline int
adj_are_counters_enabled(void)
{
    return (adj_per_adj_counters);
}
typedef u32 flow_hash_config_t;
extern const ip46_address_t zero_addr;
typedef struct {
    u32 address_key;
    u32 sw_if_index;
    u16 address_length;
    u16 flags;
    u32 next_this_sw_interface;
    u32 prev_this_sw_interface;
} ip_interface_address_t;
typedef enum {
    IP_LOCAL_NEXT_DROP,
    IP_LOCAL_NEXT_PUNT,
    IP_LOCAL_NEXT_UDP_LOOKUP,
    IP_LOCAL_NEXT_ICMP,
    IP_LOCAL_NEXT_REASSEMBLY,
    IP_LOCAL_N_NEXT,
} ip_local_next_t;
struct ip_lookup_main_t;
typedef struct ip_lookup_main_t {
    ip_interface_address_t *if_address_pool;
    mhash_t address_to_if_address_index;
    u32 *if_address_pool_index_by_sw_if_index;
    u32 *classify_table_index_by_sw_if_index;
    u8 mcast_feature_arc_index;
    u8 ucast_feature_arc_index;
    u8 output_feature_arc_index;
    u32 fib_result_n_bytes, fib_result_n_words;
    u32 is_ip6;
    format_function_t *format_address_and_length;
    u8 local_next_by_ip_protocol[256];
    u8 builtin_protocol_by_ip_protocol[256];
} ip_lookup_main_t;
clib_error_t *ip_interface_address_add_del(ip_lookup_main_t *lm, u32 sw_if_index, void *address, u32 address_length,
                                           u32 is_del, u32 *result_index);
u8 *format_ip_flow_hash_config(u8 *s, va_list *args);
static inline __attribute__((__always_inline__)) ip_interface_address_t *
ip_get_interface_address(ip_lookup_main_t *lm, void *addr_fib)
{
    uword *p = mhash_get(&lm->address_to_if_address_index, addr_fib);
    return p ? ({
        typeof(lm->if_address_pool) _e = (lm->if_address_pool) + (p[0]);
        do {
            if ((0 > 0) && !(!({
                    pool_header_t *_pool_p = pool_header(lm->if_address_pool);
                    uword _pool_i          = (_e) - (lm->if_address_pool);
                    (_pool_i < ((lm->if_address_pool) ? (((vec_header_t *) (lm->if_address_pool) - 1)->len) : 0)) ?
                        clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                        1;
                }))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/lookup.h", (uword) 169,
                            ((char *) __FUNCTION__), "! pool_is_free (lm->if_address_pool, _e)");
            }
        } while (0);
        _e;
    }) :
               0;
}
static inline __attribute__((__always_inline__)) void *
ip_interface_address_get_address(ip_lookup_main_t *lm, ip_interface_address_t *a)
{
    return mhash_key_to_mem(&lm->address_to_if_address_index, a->address_key);
}
static inline __attribute__((__always_inline__)) void
ip_lookup_set_buffer_fib_index(u32 *fib_index_by_sw_if_index, vlib_buffer_t *b)
{
    ((vnet_buffer_opaque_t *) (b)->opaque)->ip.fib_index = (({
        do {
            if ((0 > 0) && !((((vnet_buffer_opaque_t *) (b)->opaque)->sw_if_index[VLIB_RX]) <
                             ((fib_index_by_sw_if_index) ? (((vec_header_t *) (fib_index_by_sw_if_index) -1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/lookup.h", (uword) 221,
                            ((char *) __FUNCTION__),
                            "(((vnet_buffer_opaque_t *) (b)->opaque)->sw_if_index[VLIB_RX]) < vec_len "
                            "(fib_index_by_sw_if_index)");
            }
        } while (0);
        (fib_index_by_sw_if_index) + (((vnet_buffer_opaque_t *) (b)->opaque)->sw_if_index[VLIB_RX]);
    }))[0];
    ((vnet_buffer_opaque_t *) (b)->opaque)->ip.fib_index =
        ((((vnet_buffer_opaque_t *) (b)->opaque)->sw_if_index[VLIB_TX] == (u32) ~0) ?
             ((vnet_buffer_opaque_t *) (b)->opaque)->ip.fib_index :
             ((vnet_buffer_opaque_t *) (b)->opaque)->sw_if_index[VLIB_TX]);
}
typedef struct _vnet_ip_container_proxy_args {
    fib_prefix_t prefix;
    u32 sw_if_index;
    u8 is_add;
} vnet_ip_container_proxy_args_t;
clib_error_t *vnet_ip_container_proxy_add_del(vnet_ip_container_proxy_args_t *args);
void ip_lookup_init(ip_lookup_main_t *lm, u32 ip_lookup_node_index);
typedef struct {
    u16 src_port, dst_port;
    u16 length;
    u16 checksum;
} udp_header_t;
typedef enum {
    ICMP4_echo_reply                  = 0,
    ICMP4_destination_unreachable     = 3,
    ICMP4_source_quench               = 4,
    ICMP4_redirect                    = 5,
    ICMP4_alternate_host_address      = 6,
    ICMP4_echo_request                = 8,
    ICMP4_router_advertisement        = 9,
    ICMP4_router_solicitation         = 10,
    ICMP4_time_exceeded               = 11,
    ICMP4_parameter_problem           = 12,
    ICMP4_timestamp_request           = 13,
    ICMP4_timestamp_reply             = 14,
    ICMP4_information_request         = 15,
    ICMP4_information_reply           = 16,
    ICMP4_address_mask_request        = 17,
    ICMP4_address_mask_reply          = 18,
    ICMP4_traceroute                  = 30,
    ICMP4_datagram_conversion_error   = 31,
    ICMP4_mobile_host_redirect        = 32,
    ICMP4_ip6_where_are_you           = 33,
    ICMP4_ip6_i_am_here               = 34,
    ICMP4_mobile_registration_request = 35,
    ICMP4_mobile_registration_reply   = 36,
    ICMP4_domain_name_request         = 37,
    ICMP4_domain_name_reply           = 38,
    ICMP4_skip                        = 39,
    ICMP4_photuris                    = 40,
} icmp4_type_t;
typedef enum {
    ICMP4_destination_unreachable_destination_unreachable_net                = 0,
    ICMP4_destination_unreachable_destination_unreachable_host               = 1,
    ICMP4_destination_unreachable_protocol_unreachable                       = 2,
    ICMP4_destination_unreachable_port_unreachable                           = 3,
    ICMP4_destination_unreachable_fragmentation_needed_and_dont_fragment_set = 4,
    ICMP4_destination_unreachable_source_route_failed                        = 5,
    ICMP4_destination_unreachable_destination_network_unknown                = 6,
    ICMP4_destination_unreachable_destination_host_unknown                   = 7,
    ICMP4_destination_unreachable_source_host_isolated                       = 8,
    ICMP4_destination_unreachable_network_administratively_prohibited        = 9,
    ICMP4_destination_unreachable_host_administratively_prohibited           = 10,
    ICMP4_destination_unreachable_network_unreachable_for_type_of_service    = 11,
    ICMP4_destination_unreachable_host_unreachable_for_type_of_service       = 12,
    ICMP4_destination_unreachable_communication_administratively_prohibited  = 13,
    ICMP4_destination_unreachable_host_precedence_violation                  = 14,
    ICMP4_destination_unreachable_precedence_cutoff_in_effect                = 15,
    ICMP4_redirect_network_redirect                                          = 0,
    ICMP4_redirect_host_redirect                                             = 1,
    ICMP4_redirect_type_of_service_and_network_redirect                      = 2,
    ICMP4_redirect_type_of_service_and_host_redirect                         = 3,
    ICMP4_router_advertisement_normal_router_advertisement                   = 0,
    ICMP4_router_advertisement_does_not_route_common_traffic                 = 16,
    ICMP4_time_exceeded_ttl_exceeded_in_transit                              = 0,
    ICMP4_time_exceeded_fragment_reassembly_time_exceeded                    = 1,
    ICMP4_parameter_problem_pointer_indicates_error                          = 0,
    ICMP4_parameter_problem_missing_required_option                          = 1,
    ICMP4_parameter_problem_bad_length                                       = 2,
} icmp4_code_t;
typedef enum {
    ICMP6_destination_unreachable              = 1,
    ICMP6_packet_too_big                       = 2,
    ICMP6_time_exceeded                        = 3,
    ICMP6_parameter_problem                    = 4,
    ICMP6_echo_request                         = 128,
    ICMP6_echo_reply                           = 129,
    ICMP6_multicast_listener_request           = 130,
    ICMP6_multicast_listener_report            = 131,
    ICMP6_multicast_listener_done              = 132,
    ICMP6_router_solicitation                  = 133,
    ICMP6_router_advertisement                 = 134,
    ICMP6_neighbor_solicitation                = 135,
    ICMP6_neighbor_advertisement               = 136,
    ICMP6_redirect                             = 137,
    ICMP6_router_renumbering                   = 138,
    ICMP6_node_information_request             = 139,
    ICMP6_node_information_response            = 140,
    ICMP6_inverse_neighbor_solicitation        = 141,
    ICMP6_inverse_neighbor_advertisement       = 142,
    ICMP6_multicast_listener_report_v2         = 143,
    ICMP6_home_agent_address_discovery_request = 144,
    ICMP6_home_agent_address_discovery_reply   = 145,
    ICMP6_mobile_prefix_solicitation           = 146,
    ICMP6_mobile_prefix_advertisement          = 147,
    ICMP6_certification_path_solicitation      = 148,
    ICMP6_certification_path_advertisement     = 149,
    ICMP6_multicast_router_advertisement       = 151,
    ICMP6_multicast_router_solicitation        = 152,
    ICMP6_multicast_router_termination         = 153,
    ICMP6_fmipv6_messages                      = 154,
} icmp6_type_t;
typedef enum {
    ICMP6_destination_unreachable_no_route_to_destination                 = 0,
    ICMP6_destination_unreachable_destination_administratively_prohibited = 1,
    ICMP6_destination_unreachable_beyond_scope_of_source_address          = 2,
    ICMP6_destination_unreachable_address_unreachable                     = 3,
    ICMP6_destination_unreachable_port_unreachable                        = 4,
    ICMP6_destination_unreachable_source_address_failed_policy            = 5,
    ICMP6_destination_unreachable_reject_route_to_destination             = 6,
    ICMP6_time_exceeded_ttl_exceeded_in_transit                           = 0,
    ICMP6_time_exceeded_fragment_reassembly_time_exceeded                 = 1,
    ICMP6_parameter_problem_erroneous_header_field                        = 0,
    ICMP6_parameter_problem_unrecognized_next_header                      = 1,
    ICMP6_parameter_problem_unrecognized_option                           = 2,
    ICMP6_parameter_problem_first_fragment_has_incomplete_header_chain    = 3,
    ICMP6_router_renumbering_command                                      = 0,
    ICMP6_router_renumbering_result                                       = 1,
    ICMP6_node_information_request_data_contains_ip6_address              = 0,
    ICMP6_node_information_request_data_contains_name                     = 1,
    ICMP6_node_information_request_data_contains_ip4_address              = 2,
    ICMP6_node_information_response_success                               = 0,
    ICMP6_node_information_response_failed                                = 1,
    ICMP6_node_information_response_unknown_request                       = 2,
} icmp6_code_t;
typedef struct {
    u8 type;
    u8 code;
    u16 checksum;
} __attribute__((packed)) icmp46_header_t;
typedef enum icmp6_neighbor_discovery_option_type {
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_source_link_layer_address             = 1,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_target_link_layer_address             = 2,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_prefix_information                    = 3,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_redirected_header                     = 4,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_mtu                                   = 5,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_nbma_shortcut_limit                   = 6,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_advertisement_interval                = 7,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_home_agent_information                = 8,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_source_address_list                   = 9,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_target_address_list                   = 10,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_cryptographically_generated_address   = 11,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_rsa_signature                         = 12,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_timestamp                             = 13,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_nonce                                 = 14,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_trust_anchor                          = 15,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_certificate                           = 16,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_ip_address_and_prefix                 = 17,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_new_router_prefix_information         = 18,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_mobile_link_layer_address             = 19,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_neighbor_advertisement_acknowledgment = 20,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_map                                   = 23,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_route_information                     = 24,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_recursive_dns_server                  = 25,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_ra_flags_extension                    = 26,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_handover_key_request                  = 27,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_handover_key_reply                    = 28,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_handover_assist_information           = 29,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_mobile_node_identifier                = 30,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_dns_search_list                       = 31,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_card_request                          = 138,
    ICMP6_NEIGHBOR_DISCOVERY_OPTION_card_reply                            = 139,
} icmp6_neighbor_discovery_option_type_t;
typedef struct {
    u8 type;
    u8 n_data_u64s;
    u8 data[0];
} __attribute__((packed)) icmp6_neighbor_discovery_option_header_t;
typedef struct {
    icmp6_neighbor_discovery_option_header_t header;
    u8 dst_address_length;
    u8 flags;
    u32 valid_time;
    u32 preferred_time;
    u32 unused;
    ip6_address_t dst_address;
} __attribute__((packed)) icmp6_neighbor_discovery_prefix_information_option_t;
typedef struct {
    u8 type;
    u8 aux_data_len_u32s;
    u16 num_sources;
    ip6_address_t mcast_addr;
    ip6_address_t source_addr[0];
} __attribute__((packed)) icmp6_multicast_address_record_t;
typedef struct {
    ip6_hop_by_hop_ext_t ext_hdr;
    ip6_router_alert_option_t alert;
    ip6_padN_option_t pad;
    icmp46_header_t icmp;
    u16 rsvd;
    u16 num_addr_records;
    icmp6_multicast_address_record_t records[0];
} __attribute__((packed)) icmp6_multicast_listener_report_header_t;
typedef struct {
    icmp6_neighbor_discovery_option_header_t header;
    u8 reserved[6];
    u8 data[0];
} __attribute__((packed)) icmp6_neighbor_discovery_redirected_header_option_t;
typedef struct {
    icmp6_neighbor_discovery_option_header_t header;
    u16 unused;
    u32 mtu;
} __attribute__((packed)) icmp6_neighbor_discovery_mtu_option_t;
typedef struct {
    icmp6_neighbor_discovery_option_header_t header;
    u8 ethernet_address[6];
} __attribute__((packed)) icmp6_neighbor_discovery_ethernet_link_layer_address_option_t;
typedef struct {
    icmp6_neighbor_discovery_option_header_t header;
    u8 max_l2_address[6 + 8];
} __attribute__((packed)) icmp6_neighbor_discovery_max_link_layer_address_option_t;
typedef struct {
    icmp46_header_t icmp;
    u32 reserved_must_be_zero;
} __attribute__((packed)) icmp6_neighbor_discovery_header_t;
typedef struct {
    icmp46_header_t icmp;
    u8 current_hop_limit;
    u8 flags;
    u16 router_lifetime_in_sec;
    u32 neighbor_reachable_time_in_msec;
    u32 time_in_msec_between_retransmitted_neighbor_solicitations;
} __attribute__((packed)) icmp6_router_advertisement_header_t;
typedef struct {
    icmp46_header_t icmp;
    u32 advertisement_flags;
    ip6_address_t target_address;
} __attribute__((packed)) icmp6_neighbor_solicitation_or_advertisement_header_t;
typedef struct {
    icmp46_header_t icmp;
    u32 reserved_must_be_zero;
    ip6_address_t better_next_hop_address;
    ip6_address_t dst_address;
} __attribute__((packed)) icmp6_redirect_header_t;
typedef struct {
    ip6_header_t ip;
    icmp6_neighbor_solicitation_or_advertisement_header_t neighbor;
    icmp6_neighbor_discovery_ethernet_link_layer_address_option_t link_layer_option;
} __attribute__((packed)) icmp6_neighbor_solicitation_header_t;
typedef struct {
    ip6_header_t ip;
    icmp6_neighbor_discovery_header_t neighbor;
    icmp6_neighbor_discovery_ethernet_link_layer_address_option_t link_layer_option;
} __attribute__((packed)) icmp6_router_solicitation_header_t;
typedef struct {
    ip6_header_t ip;
    icmp6_router_advertisement_header_t router;
    icmp6_neighbor_discovery_ethernet_link_layer_address_option_t link_layer_option;
    icmp6_neighbor_discovery_mtu_option_t mtu_option;
    icmp6_neighbor_discovery_prefix_information_option_t prefix[0];
} __attribute__((packed)) icmp6_router_advertisement_packet_t;
typedef struct {
    ip6_header_t ip;
    icmp6_multicast_listener_report_header_t report_hdr;
} __attribute__((packed)) icmp6_multicast_listener_report_packet_t;
static inline u64
clib_xxhash(u64 key)
{
    u64 k1, h64;
    k1  = key;
    h64 = 0x9e3779b97f4a7c13LL + 2870177450012600261ULL + 8;
    k1 *= 14029467366897019727ULL;
    k1 = ((k1 << 31) | (k1 >> (64 - 31)));
    k1 *= 11400714785074694791ULL;
    h64 ^= k1;
    h64 = ((h64 << 27) | (h64 >> (64 - 27))) * 11400714785074694791ULL + 9650029242287828579ULL;
    h64 ^= h64 >> 33;
    h64 *= 14029467366897019727ULL;
    h64 ^= h64 >> 29;
    h64 *= 1609587929392839161ULL;
    h64 ^= h64 >> 32;
    return h64;
}
typedef struct throttle_t_ {
    f64 time;
    uword **bitmaps;
    u64 *seeds;
    f64 *last_seed_change_time;
} throttle_t;
extern void throttle_init(throttle_t *t, u32 n_threads, f64 time);
static inline __attribute__((__always_inline__)) u64
throttle_seed(throttle_t *t, u32 thread_index, f64 time_now)
{
    if (time_now - t->last_seed_change_time[thread_index] > t->time) {
        (void) random_u64(&t->seeds[thread_index]);
        memset(t->bitmaps[thread_index], 0, (512) / (8 * sizeof(u8)));
        t->last_seed_change_time[thread_index] = time_now;
    }
    return t->seeds[thread_index];
}
static inline __attribute__((__always_inline__)) int
throttle_check(throttle_t *t, u32 thread_index, u64 hash, u64 seed)
{
    int drop;
    uword m;
    u32 w;
    hash = clib_xxhash(hash ^ seed);
    hash &= (512) - 1;
    w    = hash / (8 * sizeof(uword));
    m    = (uword) 1 << (hash % (8 * sizeof(uword)));
    drop = (t->bitmaps[thread_index][w] & m) != 0;
    t->bitmaps[thread_index][w] |= m;
    return (drop);
}
typedef struct ip4_mfib_t {
    uword *fib_entry_by_dst_address[65];
    u32 table_id;
    u32 index;
} ip4_mfib_t;
struct ip4_main_t;
typedef void(ip4_add_del_interface_address_function_t)(struct ip4_main_t *im, uword opaque, u32 sw_if_index,
                                                       ip4_address_t *address, u32 address_length, u32 if_address_index,
                                                       u32 is_del);
typedef struct {
    ip4_add_del_interface_address_function_t *function;
    uword function_opaque;
} ip4_add_del_interface_address_callback_t;
typedef void(ip4_table_bind_function_t)(struct ip4_main_t *im, uword opaque, u32 sw_if_index, u32 new_fib_index,
                                        u32 old_fib_index);
typedef struct {
    ip4_table_bind_function_t *function;
    uword function_opaque;
} ip4_table_bind_callback_t;
typedef struct ip4_main_t {
    ip_lookup_main_t lookup_main;
    struct fib_table_t_ *fibs;
    struct ip4_fib_t_ *v4_fibs;
    struct mfib_table_t_ *mfibs;
    u32 fib_masks[33];
    u32 *fib_index_by_sw_if_index;
    u32 *mfib_index_by_sw_if_index;
    u8 *ip_enabled_by_sw_if_index;
    uword *fib_index_by_table_id;
    uword *mfib_index_by_table_id;
    ip4_add_del_interface_address_callback_t *add_del_interface_address_callbacks;
    ip4_table_bind_callback_t *table_bind_callbacks;
    vlib_packet_template_t ip4_arp_request_packet_template;
    u32 flow_hash_seed;
    struct {
        u8 ttl;
        u8 tos;
        u8 pad[2];
    } host_config;
    uword mtrie_heap_size;
    void *mtrie_mheap;
    throttle_t arp_throttle;
} ip4_main_t;
extern ip4_main_t ip4_main;
extern vlib_node_registration_t ip4_input_node;
extern vlib_node_registration_t ip4_lookup_node;
extern vlib_node_registration_t ip4_local_node;
extern vlib_node_registration_t ip4_rewrite_node;
extern vlib_node_registration_t ip4_rewrite_mcast_node;
extern vlib_node_registration_t ip4_rewrite_local_node;
extern vlib_node_registration_t ip4_arp_node;
extern vlib_node_registration_t ip4_glean_node;
extern vlib_node_registration_t ip4_midchain_node;
static inline __attribute__((__always_inline__)) uword
ip4_destination_matches_route(const ip4_main_t *im, const ip4_address_t *key, const ip4_address_t *dest, uword dest_length)
{
    return 0 == ((key->data_u32 ^ dest->data_u32) & im->fib_masks[dest_length]);
}
static inline __attribute__((__always_inline__)) uword
ip4_destination_matches_interface(ip4_main_t *im, ip4_address_t *key, ip_interface_address_t *ia)
{
    ip4_address_t *a = ip_interface_address_get_address(&im->lookup_main, ia);
    return ip4_destination_matches_route(im, key, a, ia->address_length);
}
static inline __attribute__((__always_inline__)) int
ip4_src_address_for_packet(ip_lookup_main_t *lm, u32 sw_if_index, ip4_address_t *src)
{
    u32 if_add_index = lm->if_address_pool_index_by_sw_if_index[sw_if_index];
    if (__builtin_expect((if_add_index != ~0), 1)) {
        ip_interface_address_t *if_add = ({
            typeof(lm->if_address_pool) _e = (lm->if_address_pool) + (if_add_index);
            do {
                if ((0 > 0) && !(!({
                        pool_header_t *_pool_p = pool_header(lm->if_address_pool);
                        uword _pool_i          = (_e) - (lm->if_address_pool);
                        (_pool_i < ((lm->if_address_pool) ? (((vec_header_t *) (lm->if_address_pool) - 1)->len) : 0)) ?
                            clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                            1;
                    }))) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/ip4.h", (uword) 205,
                                ((char *) __FUNCTION__), "! pool_is_free (lm->if_address_pool, _e)");
                }
            } while (0);
            _e;
        });
        ip4_address_t *if_ip           = ip_interface_address_get_address(lm, if_add);
        *src                           = *if_ip;
        return 0;
    } else {
        src->as_u32 = 0;
    }
    return (!0);
}
static inline __attribute__((__always_inline__)) ip4_address_t *
ip4_interface_address_matching_destination(ip4_main_t *im, ip4_address_t *dst, u32 sw_if_index,
                                           ip_interface_address_t **result_ia)
{
    ip_lookup_main_t *lm = &im->lookup_main;
    ip_interface_address_t *ia;
    ip4_address_t *result = 0;
    do {
        vnet_main_t *_vnm = vnet_get_main();
        u32 _sw_if_index  = sw_if_index;
        vnet_sw_interface_t *_swif;
        _swif = vnet_get_sw_interface(_vnm, _sw_if_index);
        if (_swif->flags & VNET_SW_INTERFACE_FLAG_UNNUMBERED) {
            if (1)
                _sw_if_index = _swif->unnumbered_sw_if_index;
            else
                break;
        }
        u32 _ia =
            (((((lm)->if_address_pool_index_by_sw_if_index) ?
                   (((vec_header_t *) ((lm)->if_address_pool_index_by_sw_if_index) - 1)->len) :
                   0) > (_sw_if_index)) ?
                 (({
                     do {
                         if ((0 > 0) && !(((_sw_if_index)) <
                                          (((lm)->if_address_pool_index_by_sw_if_index) ?
                                               (((vec_header_t *) ((lm)->if_address_pool_index_by_sw_if_index) - 1)->len) :
                                               0))) {
                             _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                         "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/ip4.h",
                                         (uword) 239, ((char *) __FUNCTION__),
                                         "((_sw_if_index)) < vec_len ((lm)->if_address_pool_index_by_sw_if_index)");
                         }
                     } while (0);
                     ((lm)->if_address_pool_index_by_sw_if_index) + ((_sw_if_index));
                 }))[0] :
                 (u32) ~0);
        ip_interface_address_t *_a;
        while (_ia != ~0) {
            _a   = ({
                typeof((lm)->if_address_pool) _e = ((lm)->if_address_pool) + (_ia);
                do {
                    if ((0 > 0) && !(!({
                            pool_header_t *_pool_p = pool_header((lm)->if_address_pool);
                            uword _pool_i          = (_e) - ((lm)->if_address_pool);
                            (_pool_i <
                             (((lm)->if_address_pool) ? (((vec_header_t *) ((lm)->if_address_pool) - 1)->len) : 0)) ?
                                clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                                1;
                        }))) {
                        _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                    "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/ip4.h",
                                    (uword) 239, ((char *) __FUNCTION__), "! pool_is_free ((lm)->if_address_pool, _e)");
                    }
                } while (0);
                _e;
            });
            _ia  = _a->next_this_sw_interface;
            (ia) = _a;
            ({
                ip4_address_t *a = ip_interface_address_get_address(lm, ia);
                if (ip4_destination_matches_route(im, dst, a, ia->address_length)) {
                    result = a;
                    break;
                }
            });
        }
    } while (0);
    if (result_ia)
        *result_ia = result ? ia : 0;
    return result;
}
ip4_address_t *ip4_interface_first_address(ip4_main_t *im, u32 sw_if_index, ip_interface_address_t **result_ia);
clib_error_t *ip4_add_del_interface_address(vlib_main_t *vm, u32 sw_if_index, ip4_address_t *address,
                                            u32 address_length, u32 is_del);
void ip4_directed_broadcast(u32 sw_if_index, u8 enable);
void ip4_sw_interface_enable_disable(u32 sw_if_index, u32 is_enable);
int ip4_address_compare(ip4_address_t *a1, ip4_address_t *a2);
clib_error_t *ip4_probe_neighbor(vlib_main_t *vm, ip4_address_t *dst, u32 sw_if_index, u8 refresh);
clib_error_t *ip4_set_arp_limit(u32 arp_limit);
uword ip4_udp_register_listener(vlib_main_t *vm, u16 dst_port, u32 next_node_index);
void ip4_icmp_register_type(vlib_main_t *vm, icmp4_type_t type, u32 node_index);
u16 ip4_tcp_udp_compute_checksum(vlib_main_t *vm, vlib_buffer_t *p0, ip4_header_t *ip0);
void ip4_register_protocol(u32 protocol, u32 node_index);
serialize_function_t serialize_vnet_ip4_main, unserialize_vnet_ip4_main;
int vnet_set_ip4_flow_hash(u32 table_id, flow_hash_config_t flow_hash_config);
int vnet_set_ip4_classify_intfc(vlib_main_t *vm, u32 sw_if_index, u32 table_index);
void ip4_punt_policer_add_del(u8 is_add, u32 policer_index);
void ip4_punt_redirect_add(u32 rx_sw_if_index, u32 tx_sw_if_index, ip46_address_t *nh);
void ip4_punt_redirect_del(u32 rx_sw_if_index);
static inline __attribute__((__always_inline__)) u32
ip4_compute_flow_hash(const ip4_header_t *ip, flow_hash_config_t flow_hash_config)
{
    tcp_header_t *tcp = (void *) (ip + 1);
    u32 a, b, c, t1, t2;
    uword is_tcp_udp = (ip->protocol == IP_PROTOCOL_TCP || ip->protocol == IP_PROTOCOL_UDP);
    t1               = (flow_hash_config & (1 << 0)) ? ip->src_address.data_u32 : 0;
    t2               = (flow_hash_config & (1 << 1)) ? ip->dst_address.data_u32 : 0;
    a                = (flow_hash_config & (1 << 5)) ? t2 : t1;
    b                = (flow_hash_config & (1 << 5)) ? t1 : t2;
    b ^= (flow_hash_config & (1 << 2)) ? ip->protocol : 0;
    t1 = is_tcp_udp ? tcp->src : 0;
    t2 = is_tcp_udp ? tcp->dst : 0;
    t1 = (flow_hash_config & (1 << 3)) ? t1 : 0;
    t2 = (flow_hash_config & (1 << 4)) ? t2 : 0;
    c  = (flow_hash_config & (1 << 5)) ? (t1 << 16) | t2 : (t2 << 16) | t1;
    do {
        (a) -= (c);
        (a) ^= hash32_rotate_left((c), 4);
        (c) += (b);
        (b) -= (a);
        (b) ^= hash32_rotate_left((a), 6);
        (a) += (c);
        (c) -= (b);
        (c) ^= hash32_rotate_left((b), 8);
        (b) += (a);
        (a) -= (c);
        (a) ^= hash32_rotate_left((c), 16);
        (c) += (b);
        (b) -= (a);
        (b) ^= hash32_rotate_left((a), 19);
        (a) += (c);
        (c) -= (b);
        (c) ^= hash32_rotate_left((b), 4);
        (b) += (a);
    } while (0);
    do {
        (c) ^= (b);
        (c) -= hash32_rotate_left((b), 14);
        (a) ^= (c);
        (a) -= hash32_rotate_left((c), 11);
        (b) ^= (a);
        (b) -= hash32_rotate_left((a), 25);
        (c) ^= (b);
        (c) -= hash32_rotate_left((b), 16);
        (a) ^= (c);
        (a) -= hash32_rotate_left((c), 4);
        (b) ^= (a);
        (b) -= hash32_rotate_left((a), 14);
        (c) ^= (b);
        (c) -= hash32_rotate_left((b), 24);
    } while (0);
    return c;
}
void ip4_forward_next_trace(vlib_main_t *vm, vlib_node_runtime_t *node, vlib_frame_t *frame,
                            vlib_rx_or_tx_t which_adj_index);
u8 *format_ip4_forward_next_trace(u8 *s, va_list *args);
u32 ip4_tcp_udp_validate_checksum(vlib_main_t *vm, vlib_buffer_t *p0);
static inline __attribute__((__always_inline__)) void *
vlib_buffer_push_ip4(vlib_main_t *vm, vlib_buffer_t *b, ip4_address_t *src, ip4_address_t *dst, int proto, u8 csum_offload)
{
    ip4_header_t *ih;
    ih                               = vlib_buffer_push_uninit(b, sizeof(ip4_header_t));
    ih->ip_version_and_header_length = 0x45;
    ih->tos                          = 0;
    ih->length                       = clib_host_to_net_u16(vlib_buffer_length_in_chain(vm, b));
    ih->flags_and_fragment_offset    = clib_host_to_net_u16(0x4000);
    ih->ttl                          = 255;
    ih->protocol                     = proto;
    ih->src_address.as_u32           = src->as_u32;
    ih->dst_address.as_u32           = dst->as_u32;
    if (csum_offload) {
        ih->checksum = 0;
        b->flags |= VNET_BUFFER_F_OFFLOAD_IP_CKSUM | VNET_BUFFER_F_IS_IP4;
        ((vnet_buffer_opaque_t *) (b)->opaque)->l3_hdr_offset = (u8 *) ih - b->data;
        ((vnet_buffer_opaque_t *) (b)->opaque)->l4_hdr_offset =
            ((vnet_buffer_opaque_t *) (b)->opaque)->l3_hdr_offset + sizeof(*ih);
    } else
        ih->checksum = ip4_header_checksum(ih);
    return ih;
}
typedef enum {
    IP4_ERROR_NONE,
    IP4_ERROR_TOO_SHORT,
    IP4_ERROR_BAD_LENGTH,
    IP4_ERROR_BAD_CHECKSUM,
    IP4_ERROR_VERSION,
    IP4_ERROR_OPTIONS,
    IP4_ERROR_FRAGMENT_OFFSET_ONE,
    IP4_ERROR_TIME_EXPIRED,
    IP4_ERROR_MTU_EXCEEDED,
    IP4_ERROR_DST_LOOKUP_MISS,
    IP4_ERROR_SRC_LOOKUP_MISS,
    IP4_ERROR_DROP,
    IP4_ERROR_PUNT,
    IP4_ERROR_SAME_INTERFACE,
    IP4_ERROR_UNKNOWN_PROTOCOL,
    IP4_ERROR_TCP_CHECKSUM,
    IP4_ERROR_UDP_CHECKSUM,
    IP4_ERROR_UDP_LENGTH,
    IP4_ERROR_UNICAST_SOURCE_CHECK_FAILS,
    IP4_ERROR_SPOOFED_LOCAL_PACKETS,
    IP4_ERROR_INACL_TABLE_MISS,
    IP4_ERROR_INACL_SESSION_DENY,
    IP4_ERROR_OUTACL_TABLE_MISS,
    IP4_ERROR_OUTACL_SESSION_DENY,
    IP4_ERROR_RPF_FAILURE,
    IP4_ERROR_REASS_DUPLICATE_FRAGMENT,
    IP4_ERROR_REASS_LIMIT_REACHED,
    IP4_ERROR_REASS_TIMEOUT,
    IP4_N_ERROR,
} ip4_error_t;
typedef enum {
    ICMP4_ERROR_NONE,
    ICMP4_ERROR_UNKNOWN_TYPE,
    ICMP4_ERROR_INVALID_CODE_FOR_TYPE,
    ICMP4_ERROR_INVALID_HOP_LIMIT_FOR_TYPE,
    ICMP4_ERROR_LENGTH_TOO_SMALL_FOR_TYPE,
    ICMP4_ERROR_OPTIONS_WITH_ODD_LENGTH,
    ICMP4_ERROR_OPTION_WITH_ZERO_LENGTH,
    ICMP4_ERROR_ECHO_REPLIES_SENT,
    ICMP4_ERROR_DST_LOOKUP_MISS,
    ICMP4_ERROR_DEST_UNREACH_SENT,
    ICMP4_ERROR_TTL_EXPIRE_SENT,
    ICMP4_ERROR_PARAM_PROBLEM_SENT,
    ICMP4_ERROR_DROP,
} icmp4_error_t;
typedef struct {
    u8 packet_data[64];
} icmp_input_trace_t;
format_function_t format_icmp4_input_trace;
void ip4_icmp_register_type(vlib_main_t *vm, icmp4_type_t type, u32 node_index);
void icmp4_error_set_vnet_buffer(vlib_buffer_t *b, u8 type, u8 code, u32 data);
typedef struct {
    u8 protocol;
    u8 length;
} ip6_hop_by_hop_header_t;
typedef struct {
    u8 type;
    u8 length;
} ip6_hop_by_hop_option_t;
typedef struct {
    u64 key[3];
    u64 value;
} clib_bihash_kv_24_8_t;
static inline int
clib_bihash_is_free_24_8(const clib_bihash_kv_24_8_t *v)
{
    if (v->key[0] == ~0ULL && v->value == ~0ULL)
        return 1;
    return 0;
}
static inline u64
clib_bihash_hash_24_8(const clib_bihash_kv_24_8_t *v)
{
    u64 tmp = v->key[0] ^ v->key[1] ^ v->key[2];
    return clib_xxhash(tmp);
}
static inline u8 *
format_bihash_kvp_24_8(u8 *s, va_list *args)
{
    clib_bihash_kv_24_8_t *v = __builtin_va_arg(*args, clib_bihash_kv_24_8_t *);
    s                        = format(s, "key %llu %llu %llu value %llu", v->key[0], v->key[1], v->key[2], v->value);
    return s;
}
static inline int
clib_bihash_key_compare_24_8(u64 *a, u64 *b)
{
    return ((a[0] ^ b[0]) | (a[1] ^ b[1]) | (a[2] ^ b[2])) == 0;
}
typedef struct clib_bihash_value_24_8 {
    union {
        clib_bihash_kv_24_8_t kvp[4];
        u64 next_free_as_u64;
    };
} clib_bihash_value_24_8_t;
typedef struct {
    union {
        struct {
            u64 offset : 36;
            u64 lock : 1;
            u64 linear_search : 1;
            u64 log2_pages : 8;
            u64 refcnt : 16;
        };
        u64 as_u64;
    };
} clib_bihash_bucket_24_8_t;
_Static_assert(sizeof(clib_bihash_bucket_24_8_t) == sizeof(u64), "Size of "
                                                                 "BVT (clib_bihash_bucket)"
                                                                 " must be "
                                                                 "sizeof (u64)"
                                                                 " bytes");
typedef struct {
    u64 alloc_arena_next;
    u64 alloc_arena_size;
    u64 alloc_lock_as_u64;
    u64 buckets_as_u64;
    u64 freelists_as_u64;
    u32 nbuckets;
    volatile u32 ready;
    u64 pad[2];
} __attribute__((packed)) clib_bihash_shared_header_24_8_t;
_Static_assert(sizeof(clib_bihash_shared_header_24_8_t) == 8 * sizeof(u64), "Size of "
                                                                            "BVT (clib_bihash_shared_header)"
                                                                            " must be "
                                                                            "8 * sizeof (u64)"
                                                                            " bytes");
typedef struct {
    clib_bihash_bucket_24_8_t *buckets;
    volatile u32 *alloc_lock;
    clib_bihash_value_24_8_t **working_copies;
    int *working_copy_lengths;
    clib_bihash_bucket_24_8_t saved_bucket;
    u32 nbuckets;
    u32 log2_nbuckets;
    u8 *name;
    u64 *freelists;
    clib_bihash_shared_header_24_8_t sh;
    u64 alloc_arena;
    format_function_t *fmt_fn;
} clib_bihash_24_8_t;
static inline void
clib_bihash_alloc_lock_24_8(clib_bihash_24_8_t *h)
{
    while (__atomic_test_and_set(h->alloc_lock, 2))
        __builtin_ia32_pause();
}
static inline void
clib_bihash_alloc_unlock_24_8(clib_bihash_24_8_t *h)
{
    __atomic_clear(h->alloc_lock, 3);
}
static inline void
clib_bihash_lock_bucket_24_8(clib_bihash_bucket_24_8_t *b)
{
    clib_bihash_bucket_24_8_t unlocked_bucket, locked_bucket;
    do {
        locked_bucket.as_u64 = unlocked_bucket.as_u64 = b->as_u64;
        unlocked_bucket.lock                          = 0;
        locked_bucket.lock                            = 1;
        __builtin_ia32_pause();
    } while (__atomic_compare_exchange_n(&b->as_u64, &unlocked_bucket.as_u64, locked_bucket.as_u64, 1, 2, 2) == 0);
}
static inline void
clib_bihash_unlock_bucket_24_8(clib_bihash_bucket_24_8_t *b)
{
    __sync_synchronize();
    b->lock = 0;
}
static inline void *
clib_bihash_get_value_24_8(clib_bihash_24_8_t *h, uword offset)
{
    u8 *hp = (u8 *) (uword)((h)->alloc_arena);
    u8 *vp = hp + offset;
    return (void *) vp;
}
static inline int
clib_bihash_bucket_is_empty_24_8(clib_bihash_bucket_24_8_t *b)
{
    return b->offset == 0;
}
static inline uword
clib_bihash_get_offset_24_8(clib_bihash_24_8_t *h, void *v)
{
    u8 *hp, *vp;
    hp = (u8 *) (uword)((h)->alloc_arena);
    vp = (u8 *) v;
    return vp - hp;
}
void clib_bihash_init_24_8(clib_bihash_24_8_t *h, char *name, u32 nbuckets, uword memory_size);
void clib_bihash_set_kvp_format_fn_24_8(clib_bihash_24_8_t *h, format_function_t *fmt_fn);
void clib_bihash_free_24_8(clib_bihash_24_8_t *h);
int clib_bihash_add_del_24_8(clib_bihash_24_8_t *h, clib_bihash_kv_24_8_t *add_v, int is_add);
int clib_bihash_add_or_overwrite_stale_24_8(clib_bihash_24_8_t *h, clib_bihash_kv_24_8_t *add_v,
                                            int (*is_stale_cb)(clib_bihash_kv_24_8_t *, void *), void *arg);
int clib_bihash_search_24_8(clib_bihash_24_8_t *h, clib_bihash_kv_24_8_t *search_v, clib_bihash_kv_24_8_t *return_v);
void clib_bihash_foreach_key_value_pair_24_8(clib_bihash_24_8_t *h, void *callback, void *arg);
format_function_t format_bihash_24_8;
format_function_t format_bihash_kvp_24_8;
format_function_t format_bihash_lru_24_8;
static inline int
clib_bihash_search_inline_with_hash_24_8(clib_bihash_24_8_t *h, u64 hash, clib_bihash_kv_24_8_t *key_result)
{
    u32 bucket_index;
    clib_bihash_value_24_8_t *v;
    clib_bihash_bucket_24_8_t *b;
    int i, limit;
    bucket_index = hash & (h->nbuckets - 1);
    b            = &h->buckets[bucket_index];
    if (__builtin_expect((clib_bihash_bucket_is_empty_24_8(b)), 0))
        return -1;
    if (__builtin_expect((b->lock), 0)) {
        volatile clib_bihash_bucket_24_8_t *bv = b;
        while (bv->lock)
            __builtin_ia32_pause();
    }
    hash >>= h->log2_nbuckets;
    v     = clib_bihash_get_value_24_8(h, b->offset);
    limit = 4;
    v += (b->linear_search == 0) ? hash & ((1 << b->log2_pages) - 1) : 0;
    if (__builtin_expect((b->linear_search), 0))
        limit <<= b->log2_pages;
    for (i = 0; i < limit; i++) {
        if (clib_bihash_key_compare_24_8(v->kvp[i].key, key_result->key)) {
            *key_result = v->kvp[i];
            return 0;
        }
    }
    return -1;
}
static inline int
clib_bihash_search_inline_24_8(clib_bihash_24_8_t *h, clib_bihash_kv_24_8_t *key_result)
{
    u64 hash;
    hash = clib_bihash_hash_24_8(key_result);
    return clib_bihash_search_inline_with_hash_24_8(h, hash, key_result);
}
static inline void
clib_bihash_prefetch_bucket_24_8(clib_bihash_24_8_t *h, u64 hash)
{
    u32 bucket_index;
    clib_bihash_bucket_24_8_t *b;
    bucket_index = hash & (h->nbuckets - 1);
    b            = &h->buckets[bucket_index];
    do {
        void *_addr = (b);
        do {
            if ((0 > 0) && !(((1 << 6)) <= 4 * (1 << 6))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/bihash_template.h",
                            (uword) 324, ((char *) __FUNCTION__), "((1 << 6)) <= 4*CLIB_CACHE_LINE_BYTES");
            }
        } while (0);
        if (((1 << 6)) > (0) * (1 << 6))
            __builtin_prefetch(_addr + (0) * (1 << 6), 0, 3);
        ;
        if (((1 << 6)) > (1) * (1 << 6))
            __builtin_prefetch(_addr + (1) * (1 << 6), 0, 3);
        ;
        if (((1 << 6)) > (2) * (1 << 6))
            __builtin_prefetch(_addr + (2) * (1 << 6), 0, 3);
        ;
        if (((1 << 6)) > (3) * (1 << 6))
            __builtin_prefetch(_addr + (3) * (1 << 6), 0, 3);
        ;
    } while (0);
}
static inline void
clib_bihash_prefetch_data_24_8(clib_bihash_24_8_t *h, u64 hash)
{
    u32 bucket_index;
    clib_bihash_value_24_8_t *v;
    clib_bihash_bucket_24_8_t *b;
    bucket_index = hash & (h->nbuckets - 1);
    b            = &h->buckets[bucket_index];
    if (__builtin_expect((clib_bihash_bucket_is_empty_24_8(b)), 0))
        return;
    hash >>= h->log2_nbuckets;
    v = clib_bihash_get_value_24_8(h, b->offset);
    v += (b->linear_search == 0) ? hash & ((1 << b->log2_pages) - 1) : 0;
    do {
        void *_addr = (v);
        do {
            if ((0 > 0) && !(((1 << 6)) <= 4 * (1 << 6))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/bihash_template.h",
                            (uword) 345, ((char *) __FUNCTION__), "((1 << 6)) <= 4*CLIB_CACHE_LINE_BYTES");
            }
        } while (0);
        if (((1 << 6)) > (0) * (1 << 6))
            __builtin_prefetch(_addr + (0) * (1 << 6), 0, 3);
        ;
        if (((1 << 6)) > (1) * (1 << 6))
            __builtin_prefetch(_addr + (1) * (1 << 6), 0, 3);
        ;
        if (((1 << 6)) > (2) * (1 << 6))
            __builtin_prefetch(_addr + (2) * (1 << 6), 0, 3);
        ;
        if (((1 << 6)) > (3) * (1 << 6))
            __builtin_prefetch(_addr + (3) * (1 << 6), 0, 3);
        ;
    } while (0);
}
static inline int
clib_bihash_search_inline_2_with_hash_24_8(clib_bihash_24_8_t *h, u64 hash, clib_bihash_kv_24_8_t *search_key,
                                           clib_bihash_kv_24_8_t *valuep)
{
    u32 bucket_index;
    clib_bihash_value_24_8_t *v;
    clib_bihash_bucket_24_8_t *b;
    int i, limit;
    do {
        if ((0 > 0) && !(valuep)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vppinfra/bihash_template.h",
                        (uword) 357, ((char *) __FUNCTION__), "valuep");
        }
    } while (0);
    bucket_index = hash & (h->nbuckets - 1);
    b            = &h->buckets[bucket_index];
    if (__builtin_expect((clib_bihash_bucket_is_empty_24_8(b)), 0))
        return -1;
    if (__builtin_expect((b->lock), 0)) {
        volatile clib_bihash_bucket_24_8_t *bv = b;
        while (bv->lock)
            __builtin_ia32_pause();
    }
    hash >>= h->log2_nbuckets;
    v     = clib_bihash_get_value_24_8(h, b->offset);
    limit = 4;
    v += (b->linear_search == 0) ? hash & ((1 << b->log2_pages) - 1) : 0;
    if (__builtin_expect((b->linear_search), 0))
        limit <<= b->log2_pages;
    for (i = 0; i < limit; i++) {
        if (clib_bihash_key_compare_24_8(v->kvp[i].key, search_key->key)) {
            *valuep = v->kvp[i];
            return 0;
        }
    }
    return -1;
}
static inline int
clib_bihash_search_inline_2_24_8(clib_bihash_24_8_t *h, clib_bihash_kv_24_8_t *search_key, clib_bihash_kv_24_8_t *valuep)
{
    u64 hash;
    hash = clib_bihash_hash_24_8(search_key);
    return clib_bihash_search_inline_2_with_hash_24_8(h, hash, search_key, valuep);
}
struct radix_node {
    struct radix_mask *rn_mklist;
    struct radix_node *rn_p;
    i16 rn_b;
    u8 rn_bmask;
    u8 rn_flags;
    union {
        struct {
            const char *rn_Key;
            const char *rn_Mask;
            struct radix_node *rn_Dupedkey;
        } rn_leaf;
        struct {
            int rn_Off;
            struct radix_node *rn_L;
            struct radix_node *rn_R;
        } rn_node;
    } rn_u;
};
struct radix_mask {
    i16 rm_b;
    i8 rm_unused;
    u8 rm_flags;
    struct radix_mask *rm_mklist;
    union {
        const char *rmu_mask;
        struct radix_node *rmu_leaf;
    } rm_rmu;
    i32 rm_refs;
};
struct radix_node_head {
    struct radix_node *rnh_treetop;
    i32 rnh_addrsize;
    i32 rnh_pktsize;
    struct radix_node *(*rnh_addaddr)(const void *v, const void *mask, struct radix_node_head *head,
                                      struct radix_node nodes[]);
    struct radix_node *(*rnh_addpkt)(const void *v, const void *mask, struct radix_node_head *head,
                                     struct radix_node nodes[]);
    struct radix_node *(*rnh_deladdr)(const void *v, const void *mask, struct radix_node_head *head);
    struct radix_node *(*rnh_delpkt)(const void *v, const void *mask, struct radix_node_head *head);
    struct radix_node *(*rnh_matchaddr)(const void *v, struct radix_node_head *head);
    struct radix_node *(*rnh_lookup)(const void *v, const void *mask, struct radix_node_head *head);
    struct radix_node *(*rnh_matchpkt)(const void *v, struct radix_node_head *head);
    struct radix_node rnh_nodes[3];
};
void rn_init(void);
int rn_inithead(void **, int);
void rn_delayedinit(void **, int);
int rn_inithead0(struct radix_node_head *, int);
int rn_refines(const void *, const void *);
int rn_walktree(struct radix_node_head *, int (*)(struct radix_node *, void *), void *);
struct radix_node *rn_search_matched(struct radix_node_head *, int (*)(struct radix_node *, void *), void *);
struct radix_node *rn_addmask(const void *, int, int),
    *rn_addroute(const void *, const void *, struct radix_node_head *, struct radix_node[2]),
    *rn_delete1(const void *, const void *, struct radix_node_head *, struct radix_node *),
    *rn_delete(const void *, const void *, struct radix_node_head *),
    *rn_insert(const void *, struct radix_node_head *, int *, struct radix_node[2]),
    *rn_lookup(const void *, const void *, struct radix_node_head *), *rn_match(const void *, struct radix_node_head *),
    *rn_newpair(const void *, int, struct radix_node[2]), *rn_search(const void *, struct radix_node *),
    *rn_search_m(const void *, struct radix_node *, const void *);
typedef struct {
    ip6_address_t addr;
    u32 dst_address_length;
    u32 vrf_index;
} ip6_fib_key_t;
typedef struct {
    u8 cacheline0[0] __attribute__((aligned((1 << 6))));
    u32 table_id;
    u32 index;
} ip6_fib_t;
typedef struct ip6_mfib_t {
    u32 table_id;
    u32 index;
    struct radix_node_head *rhead;
} ip6_mfib_t;
struct ip6_main_t;
typedef void(ip6_add_del_interface_address_function_t)(struct ip6_main_t *im, uword opaque, u32 sw_if_index,
                                                       ip6_address_t *address, u32 address_length, u32 if_address_index,
                                                       u32 is_del);
typedef struct {
    ip6_add_del_interface_address_function_t *function;
    uword function_opaque;
} ip6_add_del_interface_address_callback_t;
typedef void(ip6_table_bind_function_t)(struct ip6_main_t *im, uword opaque, u32 sw_if_index, u32 new_fib_index,
                                        u32 old_fib_index);
typedef struct {
    ip6_table_bind_function_t *function;
    uword function_opaque;
} ip6_table_bind_callback_t;
typedef enum ip6_fib_table_instance_type_t_ {
    IP6_FIB_TABLE_FWDING,
    IP6_FIB_TABLE_NON_FWDING,
} ip6_fib_table_instance_type_t;
typedef struct ip6_fib_table_instance_t_ {
    clib_bihash_24_8_t ip6_hash;
    uword *non_empty_dst_address_length_bitmap;
    u8 *prefix_lengths_in_search_order;
    i32 dst_address_length_refcounts[129];
} ip6_fib_table_instance_t;
typedef struct ip6_main_t {
    ip6_fib_table_instance_t ip6_table[(IP6_FIB_TABLE_NON_FWDING + 1)];
    ip_lookup_main_t lookup_main;
    struct fib_table_t_ *fibs;
    ip6_fib_t *v6_fibs;
    struct mfib_table_t_ *mfibs;
    ip6_address_t fib_masks[129];
    u32 *fib_index_by_sw_if_index;
    u32 *mfib_index_by_sw_if_index;
    u8 *ip_enabled_by_sw_if_index;
    uword *fib_index_by_table_id;
    uword *mfib_index_by_table_id;
    uword *interface_route_adj_index_by_sw_if_index;
    ip6_add_del_interface_address_callback_t *add_del_interface_address_callbacks;
    ip6_table_bind_callback_t *table_bind_callbacks;
    vlib_packet_template_t discover_neighbor_packet_template;
    u32 lookup_table_nbuckets;
    uword lookup_table_size;
    u32 flow_hash_seed;
    struct {
        u8 ttl;
        u8 pad[3];
    } host_config;
    u8 hbh_enabled;
    throttle_t nd_throttle;
} ip6_main_t;
extern ip6_main_t ip6_main;
extern vlib_node_registration_t ip6_input_node;
extern vlib_node_registration_t ip6_rewrite_node;
extern vlib_node_registration_t ip6_rewrite_mcast_node;
extern vlib_node_registration_t ip6_rewrite_local_node;
extern vlib_node_registration_t ip6_discover_neighbor_node;
extern vlib_node_registration_t ip6_glean_node;
extern vlib_node_registration_t ip6_midchain_node;
extern void ip6_forward_next_trace(vlib_main_t *vm, vlib_node_runtime_t *node, vlib_frame_t *frame,
                                   vlib_rx_or_tx_t which_adj_index);
static inline __attribute__((__always_inline__)) uword
ip6_destination_matches_route(const ip6_main_t *im, const ip6_address_t *key, const ip6_address_t *dest, uword dest_length)
{
    int i;
    for (i = 0; i < (sizeof(key->as_uword) / sizeof(key->as_uword[0])); i++) {
        if ((key->as_uword[i] ^ dest->as_uword[i]) & im->fib_masks[dest_length].as_uword[i])
            return 0;
    }
    return 1;
}
static inline __attribute__((__always_inline__)) uword
ip6_destination_matches_interface(ip6_main_t *im, ip6_address_t *key, ip_interface_address_t *ia)
{
    ip6_address_t *a = ip_interface_address_get_address(&im->lookup_main, ia);
    return ip6_destination_matches_route(im, key, a, ia->address_length);
}
static inline __attribute__((__always_inline__)) uword
ip6_unaligned_destination_matches_route(ip6_main_t *im, ip6_address_t *key, ip6_address_t *dest, uword dest_length)
{
    int i;
    for (i = 0; i < (sizeof(key->as_uword) / sizeof(key->as_uword[0])); i++) {
        if (((((struct { uword _data __attribute__((packed)); } *) (&key->as_uword[i]))->_data) ^ dest->as_uword[i]) &
            im->fib_masks[dest_length].as_uword[i])
            return 0;
    }
    return 1;
}
extern int ip6_get_ll_address(u32 sw_if_index, ip6_address_t *addr);
static inline __attribute__((__always_inline__)) int
ip6_src_address_for_packet(ip_lookup_main_t *lm, u32 sw_if_index, const ip6_address_t *dst, ip6_address_t *src)
{
    if (ip6_address_is_link_local_unicast(dst)) {
        return ip6_get_ll_address(sw_if_index, src);
    } else {
        u32 if_add_index = lm->if_address_pool_index_by_sw_if_index[sw_if_index];
        if (__builtin_expect((if_add_index != ~0), 1)) {
            ip_interface_address_t *if_add = ({
                typeof(lm->if_address_pool) _e = (lm->if_address_pool) + (if_add_index);
                do {
                    if ((0 > 0) && !(!({
                            pool_header_t *_pool_p = pool_header(lm->if_address_pool);
                            uword _pool_i          = (_e) - (lm->if_address_pool);
                            (_pool_i < ((lm->if_address_pool) ? (((vec_header_t *) (lm->if_address_pool) - 1)->len) : 0)) ?
                                clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                                1;
                        }))) {
                        _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                    "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/ip6.h",
                                    (uword) 305, ((char *) __FUNCTION__), "! pool_is_free (lm->if_address_pool, _e)");
                    }
                } while (0);
                _e;
            });
            ip6_address_t *if_ip           = ip_interface_address_get_address(lm, if_add);
            *src                           = *if_ip;
            return (!0);
        }
    }
    src->as_u64[0] = 0;
    src->as_u64[1] = 0;
    return (0);
}
static inline __attribute__((__always_inline__)) ip6_address_t *
ip6_interface_address_matching_destination(ip6_main_t *im, ip6_address_t *dst, u32 sw_if_index,
                                           ip_interface_address_t **result_ia)
{
    ip_lookup_main_t *lm = &im->lookup_main;
    ip_interface_address_t *ia;
    ip6_address_t *result = 0;
    do {
        vnet_main_t *_vnm = vnet_get_main();
        u32 _sw_if_index  = sw_if_index;
        vnet_sw_interface_t *_swif;
        _swif = vnet_get_sw_interface(_vnm, _sw_if_index);
        if (_swif->flags & VNET_SW_INTERFACE_FLAG_UNNUMBERED) {
            if (1)
                _sw_if_index = _swif->unnumbered_sw_if_index;
            else
                break;
        }
        u32 _ia =
            (((((lm)->if_address_pool_index_by_sw_if_index) ?
                   (((vec_header_t *) ((lm)->if_address_pool_index_by_sw_if_index) - 1)->len) :
                   0) > (_sw_if_index)) ?
                 (({
                     do {
                         if ((0 > 0) && !(((_sw_if_index)) <
                                          (((lm)->if_address_pool_index_by_sw_if_index) ?
                                               (((vec_header_t *) ((lm)->if_address_pool_index_by_sw_if_index) - 1)->len) :
                                               0))) {
                             _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                         "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/ip6.h",
                                         (uword) 341, ((char *) __FUNCTION__),
                                         "((_sw_if_index)) < vec_len ((lm)->if_address_pool_index_by_sw_if_index)");
                         }
                     } while (0);
                     ((lm)->if_address_pool_index_by_sw_if_index) + ((_sw_if_index));
                 }))[0] :
                 (u32) ~0);
        ip_interface_address_t *_a;
        while (_ia != ~0) {
            _a   = ({
                typeof((lm)->if_address_pool) _e = ((lm)->if_address_pool) + (_ia);
                do {
                    if ((0 > 0) && !(!({
                            pool_header_t *_pool_p = pool_header((lm)->if_address_pool);
                            uword _pool_i          = (_e) - ((lm)->if_address_pool);
                            (_pool_i <
                             (((lm)->if_address_pool) ? (((vec_header_t *) ((lm)->if_address_pool) - 1)->len) : 0)) ?
                                clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                                1;
                        }))) {
                        _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                                    "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/ip6.h",
                                    (uword) 341, ((char *) __FUNCTION__), "! pool_is_free ((lm)->if_address_pool, _e)");
                    }
                } while (0);
                _e;
            });
            _ia  = _a->next_this_sw_interface;
            (ia) = _a;
            ({
                ip6_address_t *a = ip_interface_address_get_address(lm, ia);
                if (ip6_destination_matches_route(im, dst, a, ia->address_length)) {
                    result = a;
                    break;
                }
            });
        }
    } while (0);
    if (result_ia)
        *result_ia = result ? ia : 0;
    return result;
}
clib_error_t *ip6_add_del_interface_address(vlib_main_t *vm, u32 sw_if_index, ip6_address_t *address,
                                            u32 address_length, u32 is_del);
void ip6_sw_interface_enable_disable(u32 sw_if_index, u32 is_enable);
ip6_address_t *ip6_interface_first_address(ip6_main_t *im, u32 sw_if_index);
int ip6_address_compare(ip6_address_t *a1, ip6_address_t *a2);
clib_error_t *ip6_probe_neighbor(vlib_main_t *vm, ip6_address_t *dst, u32 sw_if_index, u8 refresh);
uword ip6_udp_register_listener(vlib_main_t *vm, u16 dst_port, u32 next_node_index);
u16 ip6_tcp_udp_icmp_compute_checksum(vlib_main_t *vm, vlib_buffer_t *p0, ip6_header_t *ip0, int *bogus_lengthp);
void ip6_register_protocol(u32 protocol, u32 node_index);
serialize_function_t serialize_vnet_ip6_main, unserialize_vnet_ip6_main;
void ip6_ethernet_update_adjacency(vnet_main_t *vnm, u32 sw_if_index, u32 ai);
void ip6_link_local_address_from_ethernet_mac_address(ip6_address_t *ip, u8 *mac);
void ip6_ethernet_mac_address_from_link_local_address(u8 *mac, ip6_address_t *ip);
int vnet_set_ip6_flow_hash(u32 table_id, flow_hash_config_t flow_hash_config);
clib_error_t *enable_ip6_interface(vlib_main_t *vm, u32 sw_if_index);
clib_error_t *disable_ip6_interface(vlib_main_t *vm, u32 sw_if_index);
int ip6_interface_enabled(vlib_main_t *vm, u32 sw_if_index);
clib_error_t *set_ip6_link_local_address(vlib_main_t *vm, u32 sw_if_index, ip6_address_t *address);
int vnet_add_del_ip6_nd_change_event(vnet_main_t *vnm, void *data_callback, u32 pid, void *address_arg,
                                     uword node_index, uword type_opaque, uword data, int is_add);
int vnet_ip6_nd_term(vlib_main_t *vm, vlib_node_runtime_t *node, vlib_buffer_t *p0, ethernet_header_t *eth,
                     ip6_header_t *ip, u32 sw_if_index, u16 bd_index);
void send_ip6_na(vlib_main_t *vm, u32 sw_if_index);
void send_ip6_na_w_addr(vlib_main_t *vm, const ip6_address_t *addr, u32 sw_if_index);
u8 *format_ip6_forward_next_trace(u8 *s, va_list *args);
u32 ip6_tcp_udp_icmp_validate_checksum(vlib_main_t *vm, vlib_buffer_t *p0);
void ip6_punt_policer_add_del(u8 is_add, u32 policer_index);
void ip6_punt_redirect_add(u32 rx_sw_if_index, u32 tx_sw_if_index, ip46_address_t *nh);
void ip6_punt_redirect_del(u32 rx_sw_if_index);
int vnet_set_ip6_classify_intfc(vlib_main_t *vm, u32 sw_if_index, u32 table_index);
extern vlib_node_registration_t ip6_lookup_node;
static inline __attribute__((__always_inline__)) u32
ip6_compute_flow_hash(const ip6_header_t *ip, flow_hash_config_t flow_hash_config)
{
    tcp_header_t *tcp;
    u64 a, b, c;
    u64 t1, t2;
    uword is_tcp_udp = 0;
    u8 protocol      = ip->protocol;
    if (__builtin_expect(((ip->protocol == IP_PROTOCOL_TCP) || (ip->protocol == IP_PROTOCOL_UDP)), 1)) {
        is_tcp_udp = 1;
        tcp        = (void *) (ip + 1);
    } else if (ip->protocol == IP_PROTOCOL_IP6_HOP_BY_HOP_OPTIONS) {
        ip6_hop_by_hop_header_t *hbh = (ip6_hop_by_hop_header_t *) (ip + 1);
        if ((hbh->protocol == IP_PROTOCOL_TCP) || (hbh->protocol == IP_PROTOCOL_UDP)) {
            is_tcp_udp = 1;
            tcp        = (tcp_header_t *) ((u8 *) hbh + ((hbh->length + 1) << 3));
        }
        protocol = hbh->protocol;
    }
    t1 = (ip->src_address.as_u64[0] ^ ip->src_address.as_u64[1]);
    t1 = (flow_hash_config & (1 << 0)) ? t1 : 0;
    t2 = (ip->dst_address.as_u64[0] ^ ip->dst_address.as_u64[1]);
    t2 = (flow_hash_config & (1 << 1)) ? t2 : 0;
    a  = (flow_hash_config & (1 << 5)) ? t2 : t1;
    b  = (flow_hash_config & (1 << 5)) ? t1 : t2;
    b ^= (flow_hash_config & (1 << 2)) ? protocol : 0;
    t1 = is_tcp_udp ? tcp->src : 0;
    t2 = is_tcp_udp ? tcp->dst : 0;
    t1 = (flow_hash_config & (1 << 3)) ? t1 : 0;
    t2 = (flow_hash_config & (1 << 4)) ? t2 : 0;
    c  = (flow_hash_config & (1 << 5)) ? ((t1 << 16) | t2) : ((t2 << 16) | t1);
    do {
        do {
            (a) -= (b) + (c);
            (a) ^= (c) >> (43);
            (b) -= (c) + (a);
            (b) ^= (a) << (9);
            (c) -= (a) + (b);
            (c) ^= (b) >> (8);
        } while (0);
        do {
            (a) -= (b) + (c);
            (a) ^= (c) >> (38);
            (b) -= (c) + (a);
            (b) ^= (a) << (23);
            (c) -= (a) + (b);
            (c) ^= (b) >> (5);
        } while (0);
        do {
            (a) -= (b) + (c);
            (a) ^= (c) >> (35);
            (b) -= (c) + (a);
            (b) ^= (a) << (49);
            (c) -= (a) + (b);
            (c) ^= (b) >> (11);
        } while (0);
        do {
            (a) -= (b) + (c);
            (a) ^= (c) >> (12);
            (b) -= (c) + (a);
            (b) ^= (a) << (18);
            (c) -= (a) + (b);
            (c) ^= (b) >> (22);
        } while (0);
    } while (0);
    return (u32) c;
}
static inline __attribute__((__always_inline__)) int
ip6_locate_header(vlib_buffer_t *p0, ip6_header_t *ip0, int find_hdr_type, u32 *offset)
{
    u8 next_proto = ip0->protocol;
    u8 *next_header;
    u8 done = 0;
    u32 cur_offset;
    u8 *temp_nxthdr = 0;
    u32 exthdr_len  = 0;
    next_header     = ip6_next_header(ip0);
    cur_offset      = sizeof(ip6_header_t);
    while (1) {
        done = (next_proto == find_hdr_type);
        if (__builtin_expect((next_header >= (u8 *) vlib_buffer_get_current(p0) + p0->current_length), 0)) {
            return (-1);
        }
        if (done)
            break;
        if ((!ip6_ext_hdr(next_proto)) || next_proto == IP_PROTOCOL_IP6_NONXT) {
            if (find_hdr_type < 0)
                break;
            return -1;
        }
        if (next_proto == IP_PROTOCOL_IPV6_FRAGMENTATION) {
            ip6_frag_hdr_t *frag_hdr = (ip6_frag_hdr_t *) next_header;
            u16 frag_off             = (clib_net_to_host_u16((frag_hdr)->fragment_offset_and_more) >> 3);
            if (frag_off)
                return (-1);
            exthdr_len  = sizeof(ip6_frag_hdr_t);
            temp_nxthdr = next_header + exthdr_len;
        } else if (next_proto == IP_PROTOCOL_IPSEC_AH) {
            exthdr_len  = ((((ip6_ext_header_t *) (((ip6_ext_header_t *) next_header)))->n_data_u64s + 2) << 2);
            temp_nxthdr = next_header + exthdr_len;
        } else {
            exthdr_len  = ((((ip6_ext_header_t *) (((ip6_ext_header_t *) next_header)))->n_data_u64s + 1) << 3);
            temp_nxthdr = next_header + exthdr_len;
        }
        next_proto  = ((ip6_ext_header_t *) next_header)->next_hdr;
        next_header = temp_nxthdr;
        cur_offset += exthdr_len;
    }
    *offset = cur_offset;
    return (next_proto);
}
u8 *format_ip6_hop_by_hop_ext_hdr(u8 *s, va_list *args);
typedef struct {
    int (*options[256])(vlib_buffer_t *b, ip6_header_t *ip, ip6_hop_by_hop_option_t *opt);
    u8 *(*trace[256])(u8 *s, ip6_hop_by_hop_option_t *opt);
    uword next_override;
} ip6_hop_by_hop_main_t;
extern ip6_hop_by_hop_main_t ip6_hop_by_hop_main;
int ip6_hbh_register_option(u8 option, int options(vlib_buffer_t *b, ip6_header_t *ip, ip6_hop_by_hop_option_t *opt),
                            u8 *trace(u8 *s, ip6_hop_by_hop_option_t *opt));
int ip6_hbh_unregister_option(u8 option);
void ip6_hbh_set_next_override(uword next);
static inline __attribute__((__always_inline__)) void *
vlib_buffer_push_ip6(vlib_main_t *vm, vlib_buffer_t *b, ip6_address_t *src, ip6_address_t *dst, int proto)
{
    ip6_header_t *ip6h;
    u16 payload_length;
    ip6h                                          = vlib_buffer_push_uninit(b, sizeof(ip6_header_t));
    ip6h->ip_version_traffic_class_and_flow_label = clib_host_to_net_u32(0x6 << 28);
    payload_length                                = vlib_buffer_length_in_chain(vm, b);
    payload_length -= sizeof(*ip6h);
    ip6h->payload_length = clib_host_to_net_u16(payload_length);
    ip6h->hop_limit      = 0xff;
    ip6h->protocol       = proto;
    memcpy(ip6h->src_address.as_u8, src->as_u8, sizeof(ip6h->src_address));
    memcpy(ip6h->dst_address.as_u8, dst->as_u8, sizeof(ip6h->src_address));
    b->flags |= VNET_BUFFER_F_IS_IP6;
    return ip6h;
}
typedef enum {
    IP6_ERROR_NONE,
    IP6_ERROR_TOO_SHORT,
    IP6_ERROR_BAD_LENGTH,
    IP6_ERROR_VERSION,
    IP6_ERROR_TIME_EXPIRED,
    IP6_ERROR_MTU_EXCEEDED,
    IP6_ERROR_DST_LOOKUP_MISS,
    IP6_ERROR_SRC_LOOKUP_MISS,
    IP6_ERROR_DROP,
    IP6_ERROR_PUNT,
    IP6_ERROR_UNKNOWN_PROTOCOL,
    IP6_ERROR_UDP_CHECKSUM,
    IP6_ERROR_ICMP_CHECKSUM,
    IP6_ERROR_UDP_LENGTH,
    IP6_ERROR_UNKNOWN_UDP_PORT,
    IP6_ERROR_SPOOFED_LOCAL_PACKETS,
    IP6_ERROR_INACL_TABLE_MISS,
    IP6_ERROR_INACL_SESSION_DENY,
    IP6_ERROR_OUTACL_TABLE_MISS,
    IP6_ERROR_OUTACL_SESSION_DENY,
    IP6_ERROR_REASS_MISSING_UPPER,
    IP6_ERROR_REASS_DUPLICATE_FRAGMENT,
    IP6_ERROR_REASS_OVERLAPPING_FRAGMENT,
    IP6_ERROR_REASS_LIMIT_REACHED,
    IP6_ERROR_REASS_TIMEOUT,
    IP6_N_ERROR,
} ip6_error_t;
typedef enum {
    ICMP6_ERROR_NONE,
    ICMP6_ERROR_UNKNOWN_TYPE,
    ICMP6_ERROR_INVALID_CODE_FOR_TYPE,
    ICMP6_ERROR_INVALID_HOP_LIMIT_FOR_TYPE,
    ICMP6_ERROR_LENGTH_TOO_SMALL_FOR_TYPE,
    ICMP6_ERROR_OPTIONS_WITH_ODD_LENGTH,
    ICMP6_ERROR_OPTION_WITH_ZERO_LENGTH,
    ICMP6_ERROR_ECHO_REPLIES_SENT,
    ICMP6_ERROR_NEIGHBOR_SOLICITATION_SOURCE_NOT_ON_LINK,
    ICMP6_ERROR_NEIGHBOR_SOLICITATION_SOURCE_UNKNOWN,
    ICMP6_ERROR_NEIGHBOR_ADVERTISEMENTS_TX,
    ICMP6_ERROR_NEIGHBOR_ADVERTISEMENTS_RX,
    ICMP6_ERROR_ROUTER_SOLICITATION_SOURCE_NOT_ON_LINK,
    ICMP6_ERROR_ROUTER_SOLICITATION_UNSUPPORTED_INTF,
    ICMP6_ERROR_ROUTER_SOLICITATION_RADV_NOT_CONFIG,
    ICMP6_ERROR_ROUTER_ADVERTISEMENT_SOURCE_NOT_LINK_LOCAL,
    ICMP6_ERROR_ROUTER_ADVERTISEMENTS_TX,
    ICMP6_ERROR_ROUTER_ADVERTISEMENTS_RX,
    ICMP6_ERROR_DST_LOOKUP_MISS,
    ICMP6_ERROR_DEST_UNREACH_SENT,
    ICMP6_ERROR_PACKET_TOO_BIG_SENT,
    ICMP6_ERROR_TTL_EXPIRE_SENT,
    ICMP6_ERROR_PARAM_PROBLEM_SENT,
    ICMP6_ERROR_DROP,
} icmp6_error_t;
typedef struct {
    u8 packet_data[64];
} icmp6_input_trace_t;
format_function_t format_icmp6_input_trace;
void icmp6_register_type(vlib_main_t *vm, icmp6_type_t type, u32 node_index);
void icmp6_error_set_vnet_buffer(vlib_buffer_t *b, u8 type, u8 code, u32 data);
extern vlib_node_registration_t ip6_icmp_input_node;
extern vlib_node_registration_t ip4_classify_node;
extern vlib_node_registration_t ip6_classify_node;
typedef enum vnet_classify_action_t_ {
    CLASSIFY_ACTION_SET_IP4_FIB_INDEX = 1,
    CLASSIFY_ACTION_SET_IP6_FIB_INDEX = 2,
    CLASSIFY_ACTION_SET_METADATA      = 3,
} __attribute__((packed)) vnet_classify_action_t;
struct _vnet_classify_main;
typedef struct _vnet_classify_main vnet_classify_main_t;
typedef struct _vnet_classify_entry {
    u32 next_index;
    union {
        struct {
            u32 opaque_index;
            i32 advance;
        };
        u64 opaque_count;
    };
    u8 flags;
    vnet_classify_action_t action;
    u16 metadata;
    union {
        u64 hits;
        struct _vnet_classify_entry *next_free;
    };
    f64 last_heard;
    u32x4 key[0];
} __attribute__((packed)) vnet_classify_entry_t;
static inline int
vnet_classify_entry_is_free(vnet_classify_entry_t *e)
{
    return e->flags & (1 << 0);
}
static inline int
vnet_classify_entry_is_busy(vnet_classify_entry_t *e)
{
    return ((e->flags & (1 << 0)) == 0);
}
typedef struct {
    u32 pad0[4];
    u64 pad1[2];
    u32x4 key[1];
} __attribute__((packed)) vnet_classify_entry_1_t;
typedef struct {
    u32 pad0[4];
    u64 pad1[2];
    u32x4 key[2];
} __attribute__((packed)) vnet_classify_entry_2_t;
typedef struct {
    u32 pad0[4];
    u64 pad1[2];
    u32x4 key[3];
} __attribute__((packed)) vnet_classify_entry_3_t;
typedef struct {
    u32 pad0[4];
    u64 pad1[2];
    u32x4 key[4];
} __attribute__((packed)) vnet_classify_entry_4_t;
typedef struct {
    u32 pad0[4];
    u64 pad1[2];
    u32x4 key[5];
} __attribute__((packed)) vnet_classify_entry_5_t;
;
typedef struct {
    union {
        struct {
            u32 offset;
            u8 linear_search;
            u8 pad[2];
            u8 log2_pages;
        };
        u64 as_u64;
    };
} vnet_classify_bucket_t;
typedef struct {
    u32x4 *mask;
    vnet_classify_bucket_t *buckets;
    vnet_classify_entry_t *entries;
    u32 match_n_vectors;
    u32 skip_n_vectors;
    u32 nbuckets;
    u32 log2_nbuckets;
    u32 linear_buckets;
    int entries_per_page;
    u32 active_elements;
    u32 current_data_flag;
    int current_data_offset;
    u32 data_offset;
    u32 next_table_index;
    u32 miss_next_index;
    vnet_classify_entry_t **working_copies;
    int *working_copy_lengths;
    vnet_classify_bucket_t saved_bucket;
    vnet_classify_entry_t **freelists;
    u8 *name;
    void *mheap;
    volatile u32 *writer_lock;
} vnet_classify_table_t;
struct _vnet_classify_main {
    vnet_classify_table_t *tables;
    unformat_function_t **unformat_l2_next_index_fns;
    unformat_function_t **unformat_ip_next_index_fns;
    unformat_function_t **unformat_acl_next_index_fns;
    unformat_function_t **unformat_policer_next_index_fns;
    unformat_function_t **unformat_opaque_index_fns;
    vlib_main_t *vlib_main;
    vnet_main_t *vnet_main;
};
extern vnet_classify_main_t vnet_classify_main;
u8 *format_classify_table(u8 *s, va_list *args);
u64 vnet_classify_hash_packet(vnet_classify_table_t *t, u8 *h);
static inline u64
vnet_classify_hash_packet_inline(vnet_classify_table_t *t, u8 *h)
{
    u32x4 *mask;
    union {
        u32x4 as_u32x4;
        u64 as_u64[2];
    } xor_sum __attribute__((aligned(sizeof(u32x4))));
    do {
        if ((0 > 0) && !(t)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/classify/vnet_classify.h",
                        (uword) 227, ((char *) __FUNCTION__), "t");
        }
    } while (0);
    mask = t->mask;
    {
        u32 skip_u64      = t->skip_n_vectors * 2;
        u64 *data64       = (u64 *) h;
        xor_sum.as_u64[0] = data64[0 + skip_u64] & ((u64 *) mask)[0];
        xor_sum.as_u64[1] = data64[1 + skip_u64] & ((u64 *) mask)[1];
        switch (t->match_n_vectors) {
        case 5:
            xor_sum.as_u64[0] ^= data64[8 + skip_u64] & ((u64 *) mask)[8];
            xor_sum.as_u64[1] ^= data64[9 + skip_u64] & ((u64 *) mask)[9];
        case 4:
            xor_sum.as_u64[0] ^= data64[6 + skip_u64] & ((u64 *) mask)[6];
            xor_sum.as_u64[1] ^= data64[7 + skip_u64] & ((u64 *) mask)[7];
        case 3:
            xor_sum.as_u64[0] ^= data64[4 + skip_u64] & ((u64 *) mask)[4];
            xor_sum.as_u64[1] ^= data64[5 + skip_u64] & ((u64 *) mask)[5];
        case 2:
            xor_sum.as_u64[0] ^= data64[2 + skip_u64] & ((u64 *) mask)[2];
            xor_sum.as_u64[1] ^= data64[3 + skip_u64] & ((u64 *) mask)[3];
        case 1:
            break;
        default:
            abort();
        }
    }
    return clib_xxhash(xor_sum.as_u64[0] ^ xor_sum.as_u64[1]);
}
static inline void
vnet_classify_prefetch_bucket(vnet_classify_table_t *t, u64 hash)
{
    u32 bucket_index;
    do {
        if ((0 > 0) && !(is_pow2(t->nbuckets))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/classify/vnet_classify.h",
                        (uword) 295, ((char *) __FUNCTION__), "is_pow2 (t->nbuckets)");
        }
    } while (0);
    bucket_index = hash & (t->nbuckets - 1);
    do {
        void *_addr = (&t->buckets[bucket_index]);
        do {
            if ((0 > 0) && !(((1 << 6)) <= 4 * (1 << 6))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/classify/vnet_classify.h",
                            (uword) 299, ((char *) __FUNCTION__), "((1 << 6)) <= 4*CLIB_CACHE_LINE_BYTES");
            }
        } while (0);
        if (((1 << 6)) > (0) * (1 << 6))
            __builtin_prefetch(_addr + (0) * (1 << 6), 0, 3);
        ;
        if (((1 << 6)) > (1) * (1 << 6))
            __builtin_prefetch(_addr + (1) * (1 << 6), 0, 3);
        ;
        if (((1 << 6)) > (2) * (1 << 6))
            __builtin_prefetch(_addr + (2) * (1 << 6), 0, 3);
        ;
        if (((1 << 6)) > (3) * (1 << 6))
            __builtin_prefetch(_addr + (3) * (1 << 6), 0, 3);
        ;
    } while (0);
}
static inline vnet_classify_entry_t *
vnet_classify_get_entry(vnet_classify_table_t *t, uword offset)
{
    u8 *hp = t->mheap;
    u8 *vp = hp + offset;
    return (void *) vp;
}
static inline uword
vnet_classify_get_offset(vnet_classify_table_t *t, vnet_classify_entry_t *v)
{
    u8 *hp, *vp;
    hp = (u8 *) t->mheap;
    vp = (u8 *) v;
    do {
        if ((0 > 0) && !((vp - hp) < 0x100000000ULL)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/classify/vnet_classify.h",
                        (uword) 320, ((char *) __FUNCTION__), "(vp - hp) < 0x100000000ULL");
        }
    } while (0);
    return vp - hp;
}
static inline vnet_classify_entry_t *
vnet_classify_entry_at_index(vnet_classify_table_t *t, vnet_classify_entry_t *e, u32 index)
{
    u8 *eu8;
    eu8 = (u8 *) e;
    eu8 += index * (sizeof(vnet_classify_entry_t) + (t->match_n_vectors * sizeof(u32x4)));
    return (vnet_classify_entry_t *) eu8;
}
static inline void
vnet_classify_prefetch_entry(vnet_classify_table_t *t, u64 hash)
{
    u32 bucket_index;
    u32 value_index;
    vnet_classify_bucket_t *b;
    vnet_classify_entry_t *e;
    bucket_index = hash & (t->nbuckets - 1);
    b            = &t->buckets[bucket_index];
    if (b->offset == 0)
        return;
    hash >>= t->log2_nbuckets;
    e           = vnet_classify_get_entry(t, b->offset);
    value_index = hash & ((1 << b->log2_pages) - 1);
    e           = vnet_classify_entry_at_index(t, e, value_index);
    do {
        void *_addr = (e);
        do {
            if ((0 > 0) && !(((1 << 6)) <= 4 * (1 << 6))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/classify/vnet_classify.h",
                            (uword) 360, ((char *) __FUNCTION__), "((1 << 6)) <= 4*CLIB_CACHE_LINE_BYTES");
            }
        } while (0);
        if (((1 << 6)) > (0) * (1 << 6))
            __builtin_prefetch(_addr + (0) * (1 << 6), 0, 3);
        ;
        if (((1 << 6)) > (1) * (1 << 6))
            __builtin_prefetch(_addr + (1) * (1 << 6), 0, 3);
        ;
        if (((1 << 6)) > (2) * (1 << 6))
            __builtin_prefetch(_addr + (2) * (1 << 6), 0, 3);
        ;
        if (((1 << 6)) > (3) * (1 << 6))
            __builtin_prefetch(_addr + (3) * (1 << 6), 0, 3);
        ;
    } while (0);
}
vnet_classify_entry_t *vnet_classify_find_entry(vnet_classify_table_t *t, u8 *h, u64 hash, f64 now);
static inline vnet_classify_entry_t *
vnet_classify_find_entry_inline(vnet_classify_table_t *t, u8 *h, u64 hash, f64 now)
{
    vnet_classify_entry_t *v;
    u32x4 *mask, *key;
    union {
        u32x4 as_u32x4;
        u64 as_u64[2];
    } result __attribute__((aligned(sizeof(u32x4))));
    vnet_classify_bucket_t *b;
    u32 value_index;
    u32 bucket_index;
    u32 limit;
    int i;
    bucket_index = hash & (t->nbuckets - 1);
    b            = &t->buckets[bucket_index];
    mask         = t->mask;
    if (b->offset == 0)
        return 0;
    hash >>= t->log2_nbuckets;
    v           = vnet_classify_get_entry(t, b->offset);
    value_index = hash & ((1 << b->log2_pages) - 1);
    limit       = t->entries_per_page;
    if (__builtin_expect((b->linear_search), 0)) {
        value_index = 0;
        limit *= (1 << b->log2_pages);
    }
    v = vnet_classify_entry_at_index(t, v, value_index);
    {
        u32 skip_u64 = t->skip_n_vectors * 2;
        u64 *data64  = (u64 *) h;
        for (i = 0; i < limit; i++) {
            key              = v->key;
            result.as_u64[0] = (data64[0 + skip_u64] & ((u64 *) mask)[0]) ^ ((u64 *) key)[0];
            result.as_u64[1] = (data64[1 + skip_u64] & ((u64 *) mask)[1]) ^ ((u64 *) key)[1];
            switch (t->match_n_vectors) {
            case 5:
                result.as_u64[0] |= (data64[8 + skip_u64] & ((u64 *) mask)[8]) ^ ((u64 *) key)[8];
                result.as_u64[1] |= (data64[9 + skip_u64] & ((u64 *) mask)[9]) ^ ((u64 *) key)[9];
            case 4:
                result.as_u64[0] |= (data64[6 + skip_u64] & ((u64 *) mask)[6]) ^ ((u64 *) key)[6];
                result.as_u64[1] |= (data64[7 + skip_u64] & ((u64 *) mask)[7]) ^ ((u64 *) key)[7];
            case 3:
                result.as_u64[0] |= (data64[4 + skip_u64] & ((u64 *) mask)[4]) ^ ((u64 *) key)[4];
                result.as_u64[1] |= (data64[5 + skip_u64] & ((u64 *) mask)[5]) ^ ((u64 *) key)[5];
            case 2:
                result.as_u64[0] |= (data64[2 + skip_u64] & ((u64 *) mask)[2]) ^ ((u64 *) key)[2];
                result.as_u64[1] |= (data64[3 + skip_u64] & ((u64 *) mask)[3]) ^ ((u64 *) key)[3];
            case 1:
                break;
            default:
                abort();
            }
            if (result.as_u64[0] == 0 && result.as_u64[1] == 0) {
                if (__builtin_expect((now), 1)) {
                    v->hits++;
                    v->last_heard = now;
                }
                return (v);
            }
            v = vnet_classify_entry_at_index(t, v, 1);
        }
    }
    return 0;
}
vnet_classify_table_t *vnet_classify_new_table(vnet_classify_main_t *cm, u8 *mask, u32 nbuckets, u32 memory_size,
                                               u32 skip_n_vectors, u32 match_n_vectors);
int vnet_classify_add_del_session(vnet_classify_main_t *cm, u32 table_index, u8 *match, u32 hit_next_index,
                                  u32 opaque_index, i32 advance, u8 action, u32 metadata, int is_add);
int vnet_classify_add_del_table(vnet_classify_main_t *cm, u8 *mask, u32 nbuckets, u32 memory_size, u32 skip, u32 match,
                                u32 next_table_index, u32 miss_next_index, u32 *table_index, u8 current_data_flag,
                                i16 current_data_offset, int is_add, int del_chain);
unformat_function_t unformat_ip4_mask;
unformat_function_t unformat_ip6_mask;
unformat_function_t unformat_l3_mask;
unformat_function_t unformat_l2_mask;
unformat_function_t unformat_classify_mask;
unformat_function_t unformat_l2_next_index;
unformat_function_t unformat_ip_next_index;
unformat_function_t unformat_ip4_match;
unformat_function_t unformat_ip6_match;
unformat_function_t unformat_l3_match;
unformat_function_t unformat_l4_match;
unformat_function_t unformat_vlan_tag;
unformat_function_t unformat_l2_match;
unformat_function_t unformat_classify_match;
void vnet_classify_register_unformat_ip_next_index_fn(unformat_function_t *fn);
void vnet_classify_register_unformat_l2_next_index_fn(unformat_function_t *fn);
void vnet_classify_register_unformat_acl_next_index_fn(unformat_function_t *fn);
void vnet_classify_register_unformat_policer_next_index_fn(unformat_function_t *fn);
void vnet_classify_register_unformat_opaque_index_fn(unformat_function_t *fn);
typedef struct {
    u8 *name;
    ip_protocol_t protocol;
    format_function_t *format_header;
    unformat_function_t *unformat_header;
    unformat_function_t *unformat_match;
    unformat_function_t *unformat_pg_edit;
} ip_protocol_info_t;
typedef struct {
    u8 *name;
    u16 port;
    format_function_t *format_header;
    unformat_function_t *unformat_pg_edit;
} tcp_udp_port_info_t;
typedef struct {
    ip_protocol_info_t *protocol_infos;
    uword *protocol_info_by_protocol;
    uword *protocol_info_by_name;
    tcp_udp_port_info_t *port_infos;
    uword *port_info_by_port;
    uword *port_info_by_name;
} ip_main_t;
extern ip_main_t ip_main;
clib_error_t *ip_main_init(vlib_main_t *vm);
static inline ip_protocol_info_t *
ip_get_protocol_info(ip_main_t *im, u32 protocol)
{
    uword *p;
    p = _hash_get((im->protocol_info_by_protocol), (uword)(protocol));
    return p ? ({
        do {
            if ((0 > 0) && !((p[0]) < ((im->protocol_infos) ? (((vec_header_t *) (im->protocol_infos) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/ip.h", (uword) 141,
                            ((char *) __FUNCTION__), "(p[0]) < vec_len (im->protocol_infos)");
            }
        } while (0);
        (im->protocol_infos) + (p[0]);
    }) :
               0;
}
static inline tcp_udp_port_info_t *
ip_get_tcp_udp_port_info(ip_main_t *im, u32 port)
{
    uword *p;
    p = _hash_get((im->port_info_by_port), (uword)(port));
    return p ? ({
        do {
            if ((0 > 0) && !((p[0]) < ((im->port_infos) ? (((vec_header_t *) (im->port_infos) - 1)->len) : 0))) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                            "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/ip.h", (uword) 150,
                            ((char *) __FUNCTION__), "(p[0]) < vec_len (im->port_infos)");
            }
        } while (0);
        (im->port_infos) + (p[0]);
    }) :
               0;
}
static inline __attribute__((__always_inline__)) ip_csum_t
ip_incremental_checksum_buffer(vlib_main_t *vm, vlib_buffer_t *first_buffer, u32 first_buffer_offset,
                               u32 n_bytes_to_checksum, ip_csum_t sum)
{
    vlib_buffer_t *b = first_buffer;
    u32 n_bytes_left = n_bytes_to_checksum;
    do {
        if ((0 > 0) && !(b->current_length >= first_buffer_offset)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vnet/ip/ip.h", (uword) 161,
                        ((char *) __FUNCTION__), "b->current_length >= first_buffer_offset");
        }
    } while (0);
    void *h;
    u32 n;
    n   = ({
        __typeof__(n_bytes_left) _x                            = (n_bytes_left);
        __typeof__(b->current_length - first_buffer_offset) _y = (b->current_length - first_buffer_offset);
        _x < _y ? _x : _y;
    });
    h   = vlib_buffer_get_current(b) + first_buffer_offset;
    sum = ip_incremental_checksum(sum, h, n);
    if (__builtin_expect((b->flags & VLIB_BUFFER_NEXT_PRESENT), 0)) {
        while (1) {
            n_bytes_left -= n;
            if (n_bytes_left == 0)
                break;
            b   = vlib_get_buffer(vm, b->next_buffer);
            n   = ({
                __typeof__(n_bytes_left) _x      = (n_bytes_left);
                __typeof__(b->current_length) _y = (b->current_length);
                _x < _y ? _x : _y;
            });
            h   = vlib_buffer_get_current(b);
            sum = ip_incremental_checksum(sum, h, n);
        }
    }
    return sum;
}
void ip_del_all_interface_addresses(vlib_main_t *vm, u32 sw_if_index);
extern vlib_node_registration_t ip4_inacl_node;
extern vlib_node_registration_t ip6_inacl_node;
void ip_table_create(fib_protocol_t fproto, u32 table_id, u8 is_api, const u8 *name);
void ip_table_delete(fib_protocol_t fproto, u32 table_id, u8 is_api);
int ip_table_bind(fib_protocol_t fproto, u32 sw_if_index, u32 table_id, u8 is_api);
u8 ip_is_zero(ip46_address_t *ip46_address, u8 is_ip4);
u8 ip_is_local_host(ip46_address_t *ip46_address, u8 is_ip4);
u8 ip4_is_local_host(ip4_address_t *ip4_address);
u8 ip6_is_local_host(ip6_address_t *ip6_address);
u8 ip_is_local(u32 fib_index, ip46_address_t *ip46_address, u8 is_ip4);
u8 ip_interface_has_address(u32 sw_if_index, ip46_address_t *ip, u8 is_ip4);
void ip_copy(ip46_address_t *dst, ip46_address_t *src, u8 is_ip4);
void ip_set(ip46_address_t *dst, void *src, u8 is_ip4);
void *ip_interface_get_first_ip(u32 sw_if_index, u8 is_ip4);
void ip4_address_normalize(ip4_address_t *ip4, u8 preflen);
void ip6_address_normalize(ip6_address_t *ip6, u8 preflen);
void ip4_preflen_to_mask(u8 pref_len, ip4_address_t *ip);
u32 ip4_mask_to_preflen(ip4_address_t *mask);
void ip4_prefix_max_address_host_order(ip4_address_t *ip, u8 plen, ip4_address_t *res);
void ip6_prefix_max_address_host_order(ip6_address_t *ip, u8 plen, ip6_address_t *res);
void ip6_preflen_to_mask(u8 pref_len, ip6_address_t *mask);
u32 ip6_mask_to_preflen(ip6_address_t *mask);
typedef struct {
    u16 msg_id_base;
    u8 periodic_timer_enabled;
    vlib_main_t *vlib_main;
    vnet_main_t *vnet_main;
    ethernet_main_t *ethernet_main;
} xfilter_main_t;
extern xfilter_main_t xfilter_main;
extern vlib_node_registration_t xfilter_node;
extern vlib_node_registration_t xfilter_periodic_node;
typedef long int ptrdiff_t;
typedef struct {
    long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
    long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
typedef struct svm_region_ {
    volatile uword version;
    pthread_mutex_t mutex;
    pthread_cond_t condvar;
    int mutex_owner_pid;
    int mutex_owner_tag;
    uword flags;
    uword virtual_base;
    uword virtual_size;
    void *region_heap;
    void *data_base;
    void *data_heap;
    volatile void *user_ctx;
    uword bitmap_size;
    uword *bitmap;
    char *region_name;
    char *backing_file;
    char **filenames;
    uword *client_pids;
} svm_region_t;
typedef struct svm_map_region_args_ {
    const char *root_path;
    const char *name;
    u64 baseva;
    u64 size;
    u64 pvt_heap_size;
    uword flags;
    char *backing_file;
    uword backing_mmap_size;
    int uid;
    int gid;
} svm_map_region_args_t;
u64 svm_get_global_region_base_va();
typedef struct {
    u8 *subregion_name;
} svm_subregion_t;
typedef struct {
    svm_subregion_t *subregions;
    uword *name_hash;
    u8 *root_path;
    int uid;
    int gid;
} svm_main_region_t;
void *svm_region_find_or_create(svm_map_region_args_t *a);
void svm_region_init(void);
void svm_region_init_mapped_region(svm_map_region_args_t *a, svm_region_t *rp);
int svm_region_init_chroot(const char *root_path);
void svm_region_init_chroot_uid_gid(const char *root_path, int uid, int gid);
void svm_region_init_args(svm_map_region_args_t *a);
void svm_region_exit(void);
void svm_region_exit_client(void);
void svm_region_unmap(void *rp_arg);
void svm_region_unmap_client(void *rp_arg);
void svm_client_scan(const char *root_path);
void svm_client_scan_this_region_nolock(svm_region_t *rp);
u8 *shm_name_from_svm_map_region_args(svm_map_region_args_t *a);
u8 *format_svm_region(u8 *s, va_list *args);
svm_region_t *svm_get_root_rp(void);
static inline void *
svm_mem_alloc(svm_region_t *rp, uword size)
{
    u8 *oldheap;
    do {
        if ((0 > 0) && !(rp->flags & (1 << 0))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/svm/svm.h", (uword) 35,
                        ((char *) __FUNCTION__), "rp->flags & SVM_FLAGS_MHEAP");
        }
    } while (0);
    u8 *rv;
    pthread_mutex_lock(&rp->mutex);
    oldheap = clib_mem_set_heap(rp->data_heap);
    rv      = clib_mem_alloc(size);
    clib_mem_set_heap(oldheap);
    pthread_mutex_unlock(&rp->mutex);
    return (rv);
}
static inline void *
svm_mem_alloc_aligned_at_offset(svm_region_t *rp, uword size, uword align, uword offset)
{
    u8 *oldheap;
    do {
        if ((0 > 0) && !(rp->flags & (1 << 0))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/svm/svm.h", (uword) 51,
                        ((char *) __FUNCTION__), "rp->flags & SVM_FLAGS_MHEAP");
        }
    } while (0);
    u8 *rv;
    pthread_mutex_lock(&rp->mutex);
    oldheap = clib_mem_set_heap(rp->data_heap);
    rv      = clib_mem_alloc_aligned_at_offset(size, align, offset, 1);
    clib_mem_set_heap(oldheap);
    pthread_mutex_unlock(&rp->mutex);
    return (rv);
}
static inline void
svm_mem_free(svm_region_t *rp, void *ptr)
{
    u8 *oldheap;
    do {
        if ((0 > 0) && !(rp->flags & (1 << 0))) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/svm/svm.h", (uword) 67,
                        ((char *) __FUNCTION__), "rp->flags & SVM_FLAGS_MHEAP");
        }
    } while (0);
    pthread_mutex_lock(&rp->mutex);
    oldheap = clib_mem_set_heap(rp->data_heap);
    clib_mem_free(ptr);
    clib_mem_set_heap(oldheap);
    pthread_mutex_unlock(&rp->mutex);
}
static inline void *
svm_push_pvt_heap(svm_region_t *rp)
{
    u8 *oldheap;
    oldheap = clib_mem_set_heap(rp->region_heap);
    return ((void *) oldheap);
}
static inline void *
svm_push_data_heap(svm_region_t *rp)
{
    u8 *oldheap;
    oldheap = clib_mem_set_heap(rp->data_heap);
    return ((void *) oldheap);
}
static inline void
svm_pop_heap(void *oldheap)
{
    clib_mem_set_heap(oldheap);
}
typedef struct _svm_queue {
    pthread_mutex_t mutex;
    pthread_cond_t condvar;
    int head;
    int tail;
    volatile int cursize;
    int maxsize;
    int elsize;
    int consumer_pid;
    int producer_evtfd;
    int consumer_evtfd;
    char data[0];
} svm_queue_t;
typedef enum {
    SVM_Q_WAIT = 0,
    SVM_Q_NOWAIT,
    SVM_Q_TIMEDWAIT,
} svm_q_conditional_wait_t;
svm_queue_t *svm_queue_alloc_and_init(int nels, int elsize, int consumer_pid);
svm_queue_t *svm_queue_init(void *base, int nels, int elsize);
void svm_queue_free(svm_queue_t *q);
int svm_queue_add(svm_queue_t *q, u8 *elem, int nowait);
int svm_queue_add2(svm_queue_t *q, u8 *elem, u8 *elem2, int nowait);
int svm_queue_sub(svm_queue_t *q, u8 *elem, svm_q_conditional_wait_t cond, u32 time);
int svm_queue_sub2(svm_queue_t *q, u8 *elem);
void svm_queue_lock(svm_queue_t *q);
void svm_queue_unlock(svm_queue_t *q);
int svm_queue_is_full(svm_queue_t *q);
int svm_queue_add_nolock(svm_queue_t *q, u8 *elem);
int svm_queue_sub_raw(svm_queue_t *q, u8 *elem);
void svm_queue_wait(svm_queue_t *q);
int svm_queue_timedwait(svm_queue_t *q, double timeout);
void svm_queue_add_raw(svm_queue_t *q, u8 *elem);
void svm_queue_set_producer_event_fd(svm_queue_t *q, int fd);
void svm_queue_set_consumer_event_fd(svm_queue_t *q, int fd);
typedef svm_queue_t unix_shared_memory_queue_t;
typedef enum {
    REGISTRATION_TYPE_FREE = 0,
    REGISTRATION_TYPE_SHMEM,
    REGISTRATION_TYPE_SOCKET_LISTEN,
    REGISTRATION_TYPE_SOCKET_SERVER,
    REGISTRATION_TYPE_SOCKET_CLIENT,
} vl_registration_type_t;
typedef struct vl_api_registration_ {
    vl_registration_type_t registration_type;
    u32 vl_api_registration_pool_index;
    u8 *name;
    f64 last_heard;
    int last_queue_head;
    int unanswered_pings;
    svm_queue_t *vl_input_queue;
    svm_region_t *vlib_rp;
    void *shmem_hdr;
    u32 clib_file_index;
    i8 *unprocessed_input;
    u32 unprocessed_msg_length;
    u8 *output_vector;
    int *additional_fds_to_close;
    u32 server_handle;
    u32 server_index;
} vl_api_registration_t;
typedef struct {
    int size;
    int trace_enable;
    int replay_enable;
} trace_cfg_t;
typedef struct {
    u8 endian;
    u8 enabled;
    u8 wrapped;
    u8 pad;
    u32 nitems;
    u32 curindex;
    u8 **traces;
} vl_api_trace_t;
typedef enum {
    VL_API_TRACE_TX,
    VL_API_TRACE_RX,
} vl_api_trace_which_t;
typedef struct {
    u8 *name;
    u16 first_msg_id;
    u16 last_msg_id;
} vl_api_msg_range_t;
typedef struct {
    int id;
    char *name;
    u32 crc;
    void *handler;
    void *cleanup;
    void *endian;
    void *print;
    int size;
    int traced;
    int replay;
    int message_bounce;
    int is_mp_safe;
} vl_msg_api_msg_config_t;
typedef struct msgbuf_ {
    svm_queue_t *q;
    u32 data_len;
    u32 gc_mark_timestamp;
    u8 data[0];
} msgbuf_t;
void vl_msg_api_handler(void *the_msg);
void vl_msg_api_handler_no_free(void *the_msg);
void vl_msg_api_handler_no_trace_no_free(void *the_msg);
void vl_msg_api_trace_only(void *the_msg);
void vl_msg_api_cleanup_handler(void *the_msg);
void vl_msg_api_replay_handler(void *the_msg);
void vl_msg_api_socket_handler(void *the_msg);
void vl_msg_api_set_handlers(int msg_id, char *msg_name, void *handler, void *cleanup, void *endian, void *print,
                             int msg_size, int traced);
void vl_msg_api_clean_handlers(int msg_id);
void vl_msg_api_config(vl_msg_api_msg_config_t *);
void vl_msg_api_set_cleanup_handler(int msg_id, void *fp);
void vl_msg_api_queue_handler(svm_queue_t *q);
void vl_msg_api_barrier_sync(void) __attribute__((weak));
void vl_msg_api_barrier_release(void) __attribute__((weak));
void vl_msg_api_free(void *);
void vl_noop_handler(void *mp);
void vl_msg_api_increment_missing_client_counter(void);
void vl_msg_api_post_mortem_dump(void);
void vl_msg_api_post_mortem_dump_enable_disable(int enable);
void vl_msg_api_register_pd_handler(void *handler, u16 msg_id_host_byte_order);
int vl_msg_api_pd_handler(void *mp, int rv);
void vl_msg_api_set_first_available_msg_id(u16 first_avail);
u16 vl_msg_api_get_msg_ids(const char *name, int n);
u32 vl_msg_api_get_msg_index(u8 *name_and_crc);
void *vl_msg_push_heap(void);
void vl_msg_pop_heap(void *oldheap);
typedef clib_error_t *(vl_msg_api_init_function_t)(u32 client_index);
typedef struct _vl_msg_api_init_function_list_elt {
    struct _vl_msg_api_init_function_list_elt *next_init_function;
    vl_msg_api_init_function_t *f;
} _vl_msg_api_function_list_elt_t;
typedef struct {
    u32 major;
    u32 minor;
    u32 patch;
    char name[64];
} api_version_t;
typedef struct {
    void (**msg_handlers)(void *);
    int (**pd_msg_handlers)(void *, int);
    void (**msg_cleanup_handlers)(void *);
    void (**msg_endian_handlers)(void *);
    void (**msg_print_handlers)(void *, void *);
    const char **msg_names;
    u8 *message_bounce;
    u8 *is_mp_safe;
    struct ring_alloc_ *arings;
    u32 ring_misses;
    u32 garbage_collects;
    u32 missing_clients;
    vl_api_trace_t *rx_trace;
    vl_api_trace_t *tx_trace;
    int msg_print_flag;
    trace_cfg_t *api_trace_cfg;
    int our_pid;
    svm_region_t *vlib_rp;
    svm_region_t *vlib_primary_rp;
    svm_region_t **vlib_private_rps;
    svm_region_t **mapped_shmem_regions;
    struct vl_shmem_hdr_ *shmem_hdr;
    vl_api_registration_t **vl_clients;
    u8 *serialized_message_table_in_shmem;
    u16 first_available_msg_id;
    uword *msg_range_by_name;
    vl_api_msg_range_t *msg_ranges;
    int api_uid;
    int api_gid;
    u64 global_baseva;
    u64 global_size;
    u64 api_size;
    u64 global_pvt_heap_size;
    u64 api_pvt_heap_size;
    svm_queue_t *vl_input_queue;
    int my_client_index;
    vl_api_registration_t *my_registration;
    u32 vlib_input_queue_length;
    uword *msg_index_by_name_and_crc;
    api_version_t *api_version_list;
    const char *region_name;
    const char *root_path;
    int replay_in_progress;
    u8 *save_msg_table_filename;
    _vl_msg_api_function_list_elt_t *reaper_function_registrations;
} api_main_t;
extern api_main_t api_main;
typedef struct {
    u8 endian;
    u8 wrapped;
    u32 nitems;
} __attribute__((packed)) vl_api_trace_file_header_t;
int vl_msg_api_trace_save(api_main_t *am, vl_api_trace_which_t which, FILE *fp);
static inline u32
vl_msg_api_get_msg_length_inline(void *msg_arg)
{
    u8 *msg          = (u8 *) msg_arg;
    msgbuf_t *header = (msgbuf_t *) (msg - __builtin_offsetof(msgbuf_t, data));
    return clib_net_to_host_u32(header->data_len);
}
int vl_msg_api_rx_trace_enabled(api_main_t *am);
int vl_msg_api_tx_trace_enabled(api_main_t *am);
void vl_msg_api_trace(api_main_t *am, vl_api_trace_t *tp, void *msg);
int vl_msg_api_trace_onoff(api_main_t *am, vl_api_trace_which_t which, int onoff);
int vl_msg_api_trace_free(api_main_t *am, vl_api_trace_which_t which);
int vl_msg_api_trace_configure(api_main_t *am, vl_api_trace_which_t which, u32 nitems);
void vl_msg_api_handler_with_vm_node(api_main_t *am, void *the_msg, vlib_main_t *vm, vlib_node_runtime_t *node);
vl_api_trace_t *vl_msg_api_trace_get(api_main_t *am, vl_api_trace_which_t which);
void vl_msg_api_add_msg_name_crc(api_main_t *am, const char *string, u32 id);
void vl_msg_api_add_version(api_main_t *am, const char *string, u32 major, u32 minor, u32 patch);
u8 *vlib_node_serialize(vlib_main_t *vm, vlib_node_t ***node_dups, u8 *vector, int include_nexts, int include_stats);
vlib_node_t ***vlib_node_unserialize(u8 *vector);
u32 vl_msg_api_get_msg_length(void *msg_arg);
typedef __sig_atomic_t sig_atomic_t;
union sigval {
    int sival_int;
    void *sival_ptr;
};
typedef union sigval __sigval_t;
typedef struct {
    int si_signo;
    int si_errno;
    int si_code;
    int __pad0;
    union {
        int _pad[((128 / sizeof(int)) - 4)];
        struct {
            __pid_t si_pid;
            __uid_t si_uid;
        } _kill;
        struct {
            int si_tid;
            int si_overrun;
            __sigval_t si_sigval;
        } _timer;
        struct {
            __pid_t si_pid;
            __uid_t si_uid;
            __sigval_t si_sigval;
        } _rt;
        struct {
            __pid_t si_pid;
            __uid_t si_uid;
            int si_status;
            __clock_t si_utime;
            __clock_t si_stime;
        } _sigchld;
        struct {
            void *si_addr;

            short int si_addr_lsb;
            union {
                struct {
                    void *_lower;
                    void *_upper;
                } _addr_bnd;
                __uint32_t _pkey;
            } _bounds;
        } _sigfault;
        struct {
            long int si_band;
            int si_fd;
        } _sigpoll;
        struct {
            void *_call_addr;
            int _syscall;
            unsigned int _arch;
        } _sigsys;
    } _sifields;
} siginfo_t;
enum { SI_ASYNCNL = -60, SI_TKILL = -6, SI_SIGIO, SI_ASYNCIO, SI_MESGQ, SI_TIMER, SI_QUEUE, SI_USER, SI_KERNEL = 0x80 };
enum { ILL_ILLOPC = 1, ILL_ILLOPN, ILL_ILLADR, ILL_ILLTRP, ILL_PRVOPC, ILL_PRVREG, ILL_COPROC, ILL_BADSTK };
enum { FPE_INTDIV = 1, FPE_INTOVF, FPE_FLTDIV, FPE_FLTOVF, FPE_FLTUND, FPE_FLTRES, FPE_FLTINV, FPE_FLTSUB };
enum { SEGV_MAPERR = 1, SEGV_ACCERR, SEGV_BNDERR, SEGV_PKUERR };
enum { BUS_ADRALN = 1, BUS_ADRERR, BUS_OBJERR, BUS_MCEERR_AR, BUS_MCEERR_AO };
enum { CLD_EXITED = 1, CLD_KILLED, CLD_DUMPED, CLD_TRAPPED, CLD_STOPPED, CLD_CONTINUED };
enum { POLL_IN = 1, POLL_OUT, POLL_MSG, POLL_ERR, POLL_PRI, POLL_HUP };
typedef __sigval_t sigval_t;
typedef struct sigevent {
    __sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;
    union {
        int _pad[((64 / sizeof(int)) - 4)];
        __pid_t _tid;
        struct {
            void (*_function)(__sigval_t);
            pthread_attr_t *_attribute;
        } _sigev_thread;
    } _sigev_un;
} sigevent_t;
enum { SIGEV_SIGNAL = 0, SIGEV_NONE, SIGEV_THREAD, SIGEV_THREAD_ID = 4 };
typedef void (*__sighandler_t)(int);
extern __sighandler_t __sysv_signal(int __sig, __sighandler_t __handler) __attribute__((__nothrow__, __leaf__));
extern __sighandler_t signal(int __sig, __sighandler_t __handler) __attribute__((__nothrow__, __leaf__));
extern int kill(__pid_t __pid, int __sig) __attribute__((__nothrow__, __leaf__));
extern int killpg(__pid_t __pgrp, int __sig) __attribute__((__nothrow__, __leaf__));
extern int raise(int __sig) __attribute__((__nothrow__, __leaf__));
extern __sighandler_t ssignal(int __sig, __sighandler_t __handler) __attribute__((__nothrow__, __leaf__));
extern int gsignal(int __sig) __attribute__((__nothrow__, __leaf__));
extern void psignal(int __sig, const char *__s);
extern void psiginfo(const siginfo_t *__pinfo, const char *__s);
extern int sigblock(int __mask) __attribute__((__nothrow__, __leaf__)) __attribute__((__deprecated__));
extern int sigsetmask(int __mask) __attribute__((__nothrow__, __leaf__)) __attribute__((__deprecated__));
extern int siggetmask(void) __attribute__((__nothrow__, __leaf__)) __attribute__((__deprecated__));
typedef __sighandler_t sig_t;
extern int sigemptyset(sigset_t *__set) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int sigfillset(sigset_t *__set) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int sigaddset(sigset_t *__set, int __signo) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int sigdelset(sigset_t *__set, int __signo) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int sigismember(const sigset_t *__set, int __signo) __attribute__((__nothrow__, __leaf__))
__attribute__((__nonnull__(1)));
struct sigaction {
    union {
        __sighandler_t sa_handler;
        void (*sa_sigaction)(int, siginfo_t *, void *);
    } __sigaction_handler;
    __sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer)(void);
};
extern int sigprocmask(int __how, const sigset_t *__restrict __set, sigset_t *__restrict __oset)
    __attribute__((__nothrow__, __leaf__));
extern int sigsuspend(const sigset_t *__set) __attribute__((__nonnull__(1)));
extern int sigaction(int __sig, const struct sigaction *__restrict __act, struct sigaction *__restrict __oact)
    __attribute__((__nothrow__, __leaf__));
extern int sigpending(sigset_t *__set) __attribute__((__nothrow__, __leaf__)) __attribute__((__nonnull__(1)));
extern int sigwait(const sigset_t *__restrict __set, int *__restrict __sig) __attribute__((__nonnull__(1, 2)));
extern int sigwaitinfo(const sigset_t *__restrict __set, siginfo_t *__restrict __info) __attribute__((__nonnull__(1)));
extern int sigtimedwait(const sigset_t *__restrict __set, siginfo_t *__restrict __info,
                        const struct timespec *__restrict __timeout) __attribute__((__nonnull__(1)));
extern int sigqueue(__pid_t __pid, int __sig, const union sigval __val) __attribute__((__nothrow__, __leaf__));
extern const char *const _sys_siglist[(64 + 1)];
extern const char *const sys_siglist[(64 + 1)];
struct _fpx_sw_bytes {
    __uint32_t magic1;
    __uint32_t extended_size;
    __uint64_t xstate_bv;
    __uint32_t xstate_size;
    __uint32_t __glibc_reserved1[7];
};
struct _fpreg {
    unsigned short significand[4];
    unsigned short exponent;
};
struct _fpxreg {
    unsigned short significand[4];
    unsigned short exponent;
    unsigned short __glibc_reserved1[3];
};
struct _xmmreg {
    __uint32_t element[4];
};
struct _fpstate {
    __uint16_t cwd;
    __uint16_t swd;
    __uint16_t ftw;
    __uint16_t fop;
    __uint64_t rip;
    __uint64_t rdp;
    __uint32_t mxcsr;
    __uint32_t mxcr_mask;
    struct _fpxreg _st[8];
    struct _xmmreg _xmm[16];
    __uint32_t __glibc_reserved1[24];
};
struct sigcontext {
    __uint64_t r8;
    __uint64_t r9;
    __uint64_t r10;
    __uint64_t r11;
    __uint64_t r12;
    __uint64_t r13;
    __uint64_t r14;
    __uint64_t r15;
    __uint64_t rdi;
    __uint64_t rsi;
    __uint64_t rbp;
    __uint64_t rbx;
    __uint64_t rdx;
    __uint64_t rax;
    __uint64_t rcx;
    __uint64_t rsp;
    __uint64_t rip;
    __uint64_t eflags;
    unsigned short cs;
    unsigned short gs;
    unsigned short fs;
    unsigned short __pad0;
    __uint64_t err;
    __uint64_t trapno;
    __uint64_t oldmask;
    __uint64_t cr2;
    __extension__ union {
        struct _fpstate *fpstate;
        __uint64_t __fpstate_word;
    };
    __uint64_t __reserved1[8];
};
struct _xsave_hdr {
    __uint64_t xstate_bv;
    __uint64_t __glibc_reserved1[2];
    __uint64_t __glibc_reserved2[5];
};
struct _ymmh_state {
    __uint32_t ymmh_space[64];
};
struct _xstate {
    struct _fpstate fpstate;
    struct _xsave_hdr xstate_hdr;
    struct _ymmh_state ymmh;
};
extern int sigreturn(struct sigcontext *__scp) __attribute__((__nothrow__, __leaf__));
typedef struct {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
} stack_t;
__extension__ typedef long long int greg_t;
typedef greg_t gregset_t[23];
struct _libc_fpxreg {
    unsigned short int significand[4];
    unsigned short int exponent;
    unsigned short int __glibc_reserved1[3];
};
struct _libc_xmmreg {
    __uint32_t element[4];
};
struct _libc_fpstate {
    __uint16_t cwd;
    __uint16_t swd;
    __uint16_t ftw;
    __uint16_t fop;
    __uint64_t rip;
    __uint64_t rdp;
    __uint32_t mxcsr;
    __uint32_t mxcr_mask;
    struct _libc_fpxreg _st[8];
    struct _libc_xmmreg _xmm[16];
    __uint32_t __glibc_reserved1[24];
};
typedef struct _libc_fpstate *fpregset_t;
typedef struct {
    gregset_t gregs;
    fpregset_t fpregs;
    __extension__ unsigned long long __reserved1[8];
} mcontext_t;
typedef struct ucontext_t {
    unsigned long int uc_flags;
    struct ucontext_t *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    sigset_t uc_sigmask;
    struct _libc_fpstate __fpregs_mem;
} ucontext_t;
extern int siginterrupt(int __sig, int __interrupt) __attribute__((__nothrow__, __leaf__));
enum { SS_ONSTACK = 1, SS_DISABLE };
extern int sigaltstack(const stack_t *__restrict __ss, stack_t *__restrict __oss) __attribute__((__nothrow__, __leaf__));
struct sigstack {
    void *ss_sp;
    int ss_onstack;
};
extern int sigstack(struct sigstack *__ss, struct sigstack *__oss) __attribute__((__nothrow__, __leaf__))
__attribute__((__deprecated__));
extern int pthread_sigmask(int __how, const __sigset_t *__restrict __newmask, __sigset_t *__restrict __oldmask)
    __attribute__((__nothrow__, __leaf__));
extern int pthread_kill(pthread_t __threadid, int __signo) __attribute__((__nothrow__, __leaf__));
extern int __libc_current_sigrtmin(void) __attribute__((__nothrow__, __leaf__));
extern int __libc_current_sigrtmax(void) __attribute__((__nothrow__, __leaf__));
struct flock {
    short int l_type;
    short int l_whence;
    __off_t l_start;
    __off_t l_len;
    __pid_t l_pid;
};
extern int fcntl(int __fd, int __cmd, ...);
extern int open(const char *__file, int __oflag, ...) __attribute__((__nonnull__(1)));
extern int openat(int __fd, const char *__file, int __oflag, ...) __attribute__((__nonnull__(2)));
extern int creat(const char *__file, mode_t __mode) __attribute__((__nonnull__(1)));
extern int posix_fadvise(int __fd, off_t __offset, off_t __len, int __advise) __attribute__((__nothrow__, __leaf__));
extern int posix_fallocate(int __fd, off_t __offset, off_t __len);
typedef enum ssvm_segment_type_ {
    SSVM_SEGMENT_SHM = 0,
    SSVM_SEGMENT_MEMFD,
    SSVM_SEGMENT_PRIVATE,
    SSVM_N_SEGMENT_TYPES
} ssvm_segment_type_t;
typedef struct {
    volatile u32 lock;
    volatile u32 owner_pid;
    int recursion_count;
    u32 tag;
    void *heap;
    u64 ssvm_va;
    u64 ssvm_size;
    u32 master_pid;
    u32 slave_pid;
    u8 *name;
    void *opaque[7];
    volatile u32 ready;
    ssvm_segment_type_t type;
} ssvm_shared_header_t;
typedef struct {
    ssvm_shared_header_t *sh;
    u64 ssvm_size;
    u32 my_pid;
    u8 *name;
    uword requested_va;
    int i_am_master;
    union {
        int fd;
        int attach_timeout;
    };
} ssvm_private_t;
static inline __attribute__((__always_inline__)) void
ssvm_lock(ssvm_shared_header_t *h, u32 my_pid, u32 tag)
{
    if (h->owner_pid == my_pid) {
        h->recursion_count++;
        return;
    }
    while (__sync_lock_test_and_set(&h->lock, 1))
        ;
    h->owner_pid       = my_pid;
    h->recursion_count = 1;
    h->tag             = tag;
}
static inline __attribute__((__always_inline__)) void
ssvm_lock_non_recursive(ssvm_shared_header_t *h, u32 tag)
{
    while (__sync_lock_test_and_set(&h->lock, 1))
        ;
    h->tag = tag;
}
static inline __attribute__((__always_inline__)) void
ssvm_unlock(ssvm_shared_header_t *h)
{
    if (--h->recursion_count == 0) {
        h->owner_pid = 0;
        h->tag       = 0;
        __sync_synchronize();
        h->lock = 0;
    }
}
static inline __attribute__((__always_inline__)) void
ssvm_unlock_non_recursive(ssvm_shared_header_t *h)
{
    h->tag = 0;
    __sync_synchronize();
    h->lock = 0;
}
static inline void *
ssvm_push_heap(ssvm_shared_header_t *sh)
{
    u8 *oldheap;
    oldheap = clib_mem_set_heap(sh->heap);
    return ((void *) oldheap);
}
static inline void
ssvm_pop_heap(void *oldheap)
{
    clib_mem_set_heap(oldheap);
}
static inline void *
ssvm_mem_alloc(ssvm_private_t *ssvm, uword size)
{
    u8 *oldheap;
    void *rv;
    oldheap = clib_mem_set_heap(ssvm->sh->heap);
    rv      = clib_mem_alloc(size);
    clib_mem_set_heap(oldheap);
    return (rv);
}
typedef enum {
    SSVM_API_ERROR_NO_NAME        = -100,
    SSVM_API_ERROR_NO_SIZE        = -101,
    SSVM_API_ERROR_CREATE_FAILURE = -102,
    SSVM_API_ERROR_SET_SIZE       = -103,
    SSVM_API_ERROR_MMAP           = -104,
    SSVM_API_ERROR_SLAVE_TIMEOUT  = -105,
} ssvm_api_error_enum_t;
int ssvm_master_init(ssvm_private_t *ssvm, ssvm_segment_type_t type);
int ssvm_slave_init(ssvm_private_t *ssvm, ssvm_segment_type_t type);
void ssvm_delete(ssvm_private_t *ssvm);
int ssvm_master_init_shm(ssvm_private_t *ssvm);
int ssvm_slave_init_shm(ssvm_private_t *ssvm);
void ssvm_delete_shm(ssvm_private_t *ssvm);
int ssvm_master_init_memfd(ssvm_private_t *memfd);
int ssvm_slave_init_memfd(ssvm_private_t *memfd);
void ssvm_delete_memfd(ssvm_private_t *memfd);
int ssvm_master_init_private(ssvm_private_t *ssvm);
int ssvm_slave_init_private(ssvm_private_t *ssvm);
void ssvm_delete_private(ssvm_private_t *ssvm);
ssvm_segment_type_t ssvm_type(const ssvm_private_t *ssvm);
u8 *ssvm_name(const ssvm_private_t *ssvm);
typedef struct ring_alloc_ {
    svm_queue_t *rp;
    u16 size;
    u16 nitems;
    u32 hits;
    u32 misses;
} ring_alloc_t;
typedef enum { VL_API_VLIB_RING, VL_API_CLIENT_RING, VL_API_QUEUE } vl_api_shm_config_type_t;
typedef struct vl_api_shm_elem_config_ {
    u8 type;
    u8 _pad;
    u16 count;
    u32 size;
} vl_api_shm_elem_config_t;
_Static_assert(sizeof(vl_api_shm_elem_config_t) == 8, "Size must be exactly 8 bytes");
typedef struct vl_shmem_hdr_ {
    int version;
    volatile int vl_pid;
    svm_queue_t *vl_input_queue;
    ring_alloc_t *vl_rings;
    ring_alloc_t *client_rings;
    u32 application_restarts;
    u32 restart_reclaims;
    u32 garbage_collects;
    u32 clib_file_index;
} vl_shmem_hdr_t;
void *vl_msg_api_alloc(int nbytes);
void *vl_msg_api_alloc_or_null(int nbytes);
void *vl_msg_api_alloc_as_if_client(int nbytes);
void *vl_msg_api_alloc_as_if_client_or_null(int nbytes);
void *vl_mem_api_alloc_as_if_client_w_reg(vl_api_registration_t *reg, int nbytes);
void vl_msg_api_free(void *a);
int vl_map_shmem(const char *region_name, int is_vlib);
void vl_unmap_shmem(void);
void vl_unmap_shmem_client(void);
void vl_register_mapped_shmem_region(svm_region_t *rp);
void vl_msg_api_send_shmem(svm_queue_t *q, u8 *elem);
void vl_msg_api_send_shmem_nolock(svm_queue_t *q, u8 *elem);
int vl_mem_api_can_send(svm_queue_t *q);
void vl_set_memory_region_name(const char *name);
void vl_set_memory_root_path(const char *root_path);
void vl_set_memory_uid(int uid);
void vl_set_memory_gid(int gid);
void vl_set_global_memory_baseva(u64 baseva);
void vl_set_global_memory_size(u64 size);
void vl_set_api_memory_size(u64 size);
void vl_set_global_pvt_heap_size(u64 size);
void vl_set_api_pvt_heap_size(u64 size);
void vl_init_shmem(svm_region_t *vlib_rp, vl_api_shm_elem_config_t *config, int is_vlib, int is_private_region);
svm_queue_t *vl_api_client_index_to_input_queue(u32 index);
int vl_mem_api_init(const char *region_name);
void vl_mem_api_dead_client_scan(api_main_t *am, vl_shmem_hdr_t *shm, f64 now);
int vl_mem_api_handle_msg_main(vlib_main_t *vm, vlib_node_runtime_t *node);
int vl_mem_api_handle_msg_private(vlib_main_t *vm, vlib_node_runtime_t *node, u32 reg_index);
vl_api_registration_t *vl_mem_api_client_index_to_registration(u32 handle);
void vl_mem_api_enable_disable(vlib_main_t *vm, int yesno);
u32 vl_api_memclnt_create_internal(char *, svm_queue_t *);
static inline u32
vl_msg_api_handle_get_epoch(u32 index)
{
    return (index & 0xFF);
}
static inline u32
vl_msg_api_handle_get_index(u32 index)
{
    return (index >> 8);
}
static inline u32
vl_msg_api_handle_from_index_and_epoch(u32 index, u32 epoch)
{
    u32 handle;
    do {
        if ((0 > 0) && !(index < 0x00FFFFFF)) {
            _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails",
                        "../../../build-root/install-vpp_debug-native/vpp/include/vlibmemory/memory_api.h", (uword) 55,
                        ((char *) __FUNCTION__), "index < 0x00FFFFFF");
        }
    } while (0);
    handle = (index << 8) | (epoch & 0xFF);
    return handle;
}
static inline u8
vl_msg_api_handle_is_valid(u32 handle, u32 restarts)
{
    u32 epoch = vl_msg_api_handle_get_epoch(handle);
    return ((restarts & 0xFF) == epoch);
}
int vl_client_connect(const char *name, int ctx_quota, int input_queue_size);
int vl_client_disconnect(void);
int vl_client_api_map(const char *region_name);
void vl_client_api_unmap(void);
void vl_client_disconnect_from_vlib(void);
void vl_client_disconnect_from_vlib_no_unmap(void);
int vl_client_connect_to_vlib(const char *svm_name, const char *client_name, int rx_queue_size);
int vl_client_connect_to_vlib_no_rx_pthread(const char *svm_name, const char *client_name, int rx_queue_size);
int vl_client_connect_to_vlib_no_map(const char *svm_name, const char *client_name, int rx_queue_size);
void vl_client_install_client_message_handlers(void);
u8 vl_mem_client_is_connected(void);
typedef struct {
    clib_file_t *clib_file;
    vl_api_registration_t *regp;
    u8 *data;
} vl_socket_args_for_process_t;
typedef struct {
    u8 *socket_name;
    u32 bind_address;
    vl_api_registration_t *registration_pool;
    vl_api_registration_t *current_rp;
    clib_file_t *current_uf;
    i8 *input_buffer;
    vl_socket_args_for_process_t *process_args;
    clib_socket_t socksvr_listen_socket;
} socket_main_t;
extern socket_main_t socket_main;
void vl_socket_free_registration_index(u32 pool_index);
clib_error_t *vl_socket_read_ready(struct clib_file *uf);
clib_error_t *vl_socket_write_ready(struct clib_file *uf);
void vl_socket_api_send(vl_api_registration_t *rp, u8 *elem);
void vl_socket_process_api_msg(clib_file_t *uf, vl_api_registration_t *rp, i8 *input_v);
void vl_sock_api_dump_clients(vlib_main_t *vm, api_main_t *am);
clib_error_t *vl_sock_api_init(vlib_main_t *vm);
clib_error_t *vl_sock_api_send_fd_msg(int socket_fd, int fds[], int n_fds);
clib_error_t *vl_sock_api_recv_fd_msg(int socket_fd, int fds[], int n_fds, u32 wait);
vl_api_registration_t *vl_socket_api_client_handle_to_registration(u32 idx);
u8 vl_socket_api_registration_handle_is_valid(u32 reg_index);
typedef struct {
    int socket_fd;
    int socket_enable;
    u32 client_index;
    clib_socket_t client_socket;
    u32 socket_buffer_size;
    u8 *socket_tx_buffer;
    u8 *socket_rx_buffer;
    u32 socket_tx_nbytes;
    int control_pings_outstanding;
    u8 *name;
    clib_time_t clib_time;
    ssvm_private_t memfd_segment;
} socket_client_main_t;
extern socket_client_main_t socket_client_main;
int vl_socket_client_connect(char *socket_path, char *client_name, u32 socket_buffer_size);
void vl_socket_client_disconnect(void);
int vl_socket_client_read(int wait);
int vl_socket_client_write(void);
void vl_socket_client_enable_disable(int enable);
void *vl_socket_client_msg_alloc(int nbytes);
int vl_socket_client_init_shm(vl_api_shm_elem_config_t *config);
clib_error_t *vl_socket_client_recv_fd_msg(int fds[], int n_fds, u32 wait);
void vl_api_rpc_call_main_thread(void *fp, u8 *data, u32 data_length);
u16 vl_client_get_first_plugin_msg_id(const char *plugin_name);
void vl_api_send_pending_rpc_requests(vlib_main_t *vm);
u8 *vl_api_serialize_message_table(api_main_t *am, u8 *vector);
static inline __attribute__((__always_inline__)) void
vl_api_send_msg(vl_api_registration_t *rp, u8 *elem)
{
    if (__builtin_expect((rp->registration_type > REGISTRATION_TYPE_SHMEM), 0)) {
        vl_socket_api_send(rp, elem);
    } else {
        vl_msg_api_send_shmem(rp->vl_input_queue, (u8 *) &elem);
    }
}
static inline __attribute__((__always_inline__)) int
vl_api_can_send_msg(vl_api_registration_t *rp)
{
    if (__builtin_expect((rp->registration_type > REGISTRATION_TYPE_SHMEM), 0))
        return 1;
    else
        return vl_mem_api_can_send(rp->vl_input_queue);
}
static inline __attribute__((__always_inline__)) vl_api_registration_t *
vl_api_client_index_to_registration(u32 index)
{
    if (vl_socket_api_registration_handle_is_valid(ntohl(index)))
        return vl_socket_api_client_handle_to_registration(ntohl(index));
    return vl_mem_api_client_index_to_registration(index);
}
static inline __attribute__((__always_inline__)) u32
vl_api_registration_file_index(vl_api_registration_t *reg)
{
    return reg->clib_file_index;
}
static inline __attribute__((__always_inline__)) clib_file_t *
vl_api_registration_file(vl_api_registration_t *reg)
{
    return clib_file_get(&file_main, vl_api_registration_file_index(reg));
}
static inline __attribute__((__always_inline__)) void
vl_api_registration_del_file(vl_api_registration_t *reg)
{
    clib_file_t *cf = vl_api_registration_file(reg);
    if (cf)
        clib_file_del(&file_main, cf);
}
static inline __attribute__((__always_inline__)) clib_error_t *
vl_api_send_fd_msg(vl_api_registration_t *reg, int fds[], int n_fds)
{
    clib_file_t *cf = vl_api_registration_file(reg);
    if (cf)
        return vl_sock_api_send_fd_msg(cf->file_descriptor, fds, n_fds);
    return 0;
}
static inline __attribute__((__always_inline__)) clib_error_t *
vl_api_recv_fd_msg(vl_api_registration_t *reg, int fds[], int n_fds, u32 wait)
{
    clib_file_t *cf = vl_api_registration_file(reg);
    if (cf)
        return vl_sock_api_recv_fd_msg(cf->file_descriptor, fds, n_fds, wait);
    return 0;
}
extern vlib_node_registration_t vl_api_clnt_node;
extern volatile int **vl_api_queue_cursizes;
typedef enum vl_api_clnt_process_events { QUEUE_SIGNAL_EVENT = 1, SOCKET_READ_EVENT } vl_api_clnt_process_events_t;
typedef enum {
    SLEEP_400_US,
    SLEEP_200_US,
    SLEEP_100_US,
    SLEEP_10_US,
    SLEEP_N_BUCKETS,
} histogram_index_t;
extern u64 vector_rate_histogram[];
vl_api_registration_t *sockclnt_get_registration(u32 index);
void socksvr_add_pending_output(struct clib_file *uf, struct vl_api_registration_ *cf, u8 *buffer, uword buffer_bytes);
void vl_socket_process_msg(struct clib_file *uf, struct vl_api_registration_ *rp, i8 *input_v);
u32 sockclnt_open_index(char *client_name, char *hostname, int port);
void sockclnt_close_index(u32 index);
void vl_client_msg_api_send(vl_api_registration_t *cm, u8 *elem);
typedef enum {
    VL_API_XFILTER_ENABLE_DISABLE,
    VL_API_XFILTER_ENABLE_DISABLE_REPLY,
    VL_MSG_FIRST_AVAILABLE,
} vl_msg_id_t;
typedef struct _vl_api_xfilter_enable_disable {
    u16 _vl_msg_id;
    u32 client_index;
    u32 context;
    u8 enable_disable;
    u32 sw_if_index;
} __attribute__((packed)) vl_api_xfilter_enable_disable_t;
typedef struct _vl_api_xfilter_enable_disable_reply {
    u16 _vl_msg_id;
    u32 context;
    i32 retval;
} __attribute__((packed)) vl_api_xfilter_enable_disable_reply_t;
static inline void
vl_api_xfilter_enable_disable_t_endian(vl_api_xfilter_enable_disable_t *a)
{
    a->_vl_msg_id   = clib_net_to_host_u16(a->_vl_msg_id);
    a->client_index = clib_net_to_host_u32(a->client_index);
    a->context      = clib_net_to_host_u32(a->context);
    a->sw_if_index  = clib_net_to_host_u32(a->sw_if_index);
}
static inline void
vl_api_xfilter_enable_disable_reply_t_endian(vl_api_xfilter_enable_disable_reply_t *a)
{
    a->_vl_msg_id = clib_net_to_host_u16(a->_vl_msg_id);
    a->context    = clib_net_to_host_u32(a->context);
    a->retval     = clib_net_to_host_u32(a->retval);
}
static inline void *
vl_api_xfilter_enable_disable_t_print(vl_api_xfilter_enable_disable_t *a, void *handle)
{
    vlib_cli_output(handle, "vl_api_xfilter_enable_disable_t:\n");
    vlib_cli_output(handle, "_vl_msg_id: %u\n", a->_vl_msg_id);
    vlib_cli_output(handle, "client_index: %u\n", a->client_index);
    vlib_cli_output(handle, "context: %u\n", a->context);
    vlib_cli_output(handle, "enable_disable: %u\n", a->enable_disable);
    vlib_cli_output(handle, "sw_if_index: %u\n", a->sw_if_index);
    return handle;
}
static inline void *
vl_api_xfilter_enable_disable_reply_t_print(vl_api_xfilter_enable_disable_reply_t *a, void *handle)
{
    vlib_cli_output(handle, "vl_api_xfilter_enable_disable_reply_t:\n");
    vlib_cli_output(handle, "_vl_msg_id: %u\n", a->_vl_msg_id);
    vlib_cli_output(handle, "context: %u\n", a->context);
    vlib_cli_output(handle, "retval: %ld\n", a->retval);
    return handle;
}
static u32 api_version = (0xe1f054ea);
static inline uword
vnet_sw_if_index_is_api_valid(u32 sw_if_index)
{
    return vnet_sw_interface_is_api_valid(vnet_get_main(), sw_if_index);
}
typedef struct {
    u32 client_index;
    u32 client_pid;
} vpe_client_registration_t;
struct _vl_api_ip4_arp_event;
struct _vl_api_ip6_nd_event;
typedef struct {
    uword *interface_events_registration_hash;
    vpe_client_registration_t *interface_events_registrations;
    uword *to_netconf_server_registration_hash;
    vpe_client_registration_t *to_netconf_server_registrations;
    uword *from_netconf_server_registration_hash;
    vpe_client_registration_t *from_netconf_server_registrations;
    uword *to_netconf_client_registration_hash;
    vpe_client_registration_t *to_netconf_client_registrations;
    uword *from_netconf_client_registration_hash;
    vpe_client_registration_t *from_netconf_client_registrations;
    uword *oam_events_registration_hash;
    vpe_client_registration_t *oam_events_registrations;
    uword *bfd_events_registration_hash;
    vpe_client_registration_t *bfd_events_registrations;
    uword *wc_ip6_nd_events_registration_hash;
    vpe_client_registration_t *wc_ip6_nd_events_registrations;
    uword *wc_ip4_arp_events_registration_hash;
    vpe_client_registration_t *wc_ip4_arp_events_registrations;
    uword *ip6_ra_events_registration_hash;
    vpe_client_registration_t *ip6_ra_events_registrations;
    uword *dhcp6_pd_reply_events_registration_hash;
    vpe_client_registration_t *dhcp6_pd_reply_events_registrations;
    uword *dhcp6_reply_events_registration_hash;
    vpe_client_registration_t *dhcp6_reply_events_registrations;
    u8 link_state_process_up;
    struct _vl_api_ip4_arp_event *arp_events;
    struct _vl_api_ip6_nd_event *nd_events;
    vlib_main_t *vlib_main;
    vnet_main_t *vnet_main;
} vpe_api_main_t;
extern vpe_api_main_t vpe_api_main;
xfilter_main_t xfilter_main;
int
xfilter_enable_disable(xfilter_main_t *sm, u32 sw_if_index, int enable_disable)
{
    vnet_sw_interface_t *sw;
    int rv = 0;
    if (({
            pool_header_t *_pool_p = pool_header((sm->vnet_main->interface_main.sw_interfaces));
            uword _pool_i          = ((sm->vnet_main->interface_main.sw_interfaces) + (sw_if_index)) -
                            ((sm->vnet_main->interface_main.sw_interfaces));
            (_pool_i < (((sm->vnet_main->interface_main.sw_interfaces)) ?
                            (((vec_header_t *) ((sm->vnet_main->interface_main.sw_interfaces)) - 1)->len) :
                            0)) ?
                clib_bitmap_get(_pool_p->free_bitmap, _pool_i) :
                1;
        })) {
        return VNET_API_ERROR_INVALID_SW_IF_INDEX;
    }
    sw = vnet_get_sw_interface(sm->vnet_main, sw_if_index);
    if (sw->type != VNET_SW_INTERFACE_TYPE_HARDWARE) {
        return VNET_API_ERROR_INVALID_SW_IF_INDEX;
    }
    vnet_feature_enable_disable("device-input", "xfilter", sw_if_index, enable_disable, 0, 0);
    vlib_process_signal_event(sm->vlib_main, xfilter_periodic_node.index, 3, (uword) enable_disable);
    return rv;
}
static clib_error_t *
xfilter_enable_disable_command_fn(vlib_main_t *vm, unformat_input_t *input, vlib_cli_command_t *cmd)
{
    xfilter_main_t *sm = &xfilter_main;
    u32 sw_if_index    = ~0;
    int enable_disable = 1;
    int rv;
    while (unformat_check_input(input) != (~0)) {
        if (unformat(input, "disable")) {
            enable_disable = 0;
        } else if (unformat(input, "%U", unformat_vnet_sw_interface, sm->vnet_main, &sw_if_index)) {
        } else {
            break;
        }
    }
    if (sw_if_index == ~0) {
        return _clib_error_return((0), (0), (0), (char *) ((char *) __FUNCTION__), "Please specify an interface...");
    }
    rv = xfilter_enable_disable(sm, sw_if_index, enable_disable);
    switch (rv) {
    case 0: {
        break;
    }
    case VNET_API_ERROR_INVALID_SW_IF_INDEX: {
        return _clib_error_return((0), (0), (0), (char *) ((char *) __FUNCTION__),
                                  "Invalid interface, only works on physical ports");
        break;
    }
    case VNET_API_ERROR_UNIMPLEMENTED: {
        return _clib_error_return((0), (0), (0), (char *) ((char *) __FUNCTION__),
                                  "Device driver doesn't support redirection");
        break;
    }
    default:
        return _clib_error_return((0), (0), (0), (char *) ((char *) __FUNCTION__), "xfilter_enable_disable returned %d",
                                  rv);
    }
    return 0;
}
static vlib_cli_command_t xfilter_enable_disable_command;
static void __vlib_cli_command_registration_xfilter_enable_disable_command(void) __attribute__((__constructor__));
static void
__vlib_cli_command_registration_xfilter_enable_disable_command(void)
{
    vlib_main_t *vm                                 = vlib_get_main();
    vlib_cli_main_t *cm                             = &vm->cli_main;
    xfilter_enable_disable_command.next_cli_command = cm->cli_command_registrations;
    cm->cli_command_registrations                   = &xfilter_enable_disable_command;
}
static void __vlib_cli_command_unregistration_xfilter_enable_disable_command(void) __attribute__((__destructor__));
static void
__vlib_cli_command_unregistration_xfilter_enable_disable_command(void)
{
    vlib_main_t *vm     = vlib_get_main();
    vlib_cli_main_t *cm = &vm->cli_main;
    {
        do {
            if ((0 > 0) && !(cm->cli_command_registrations)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails", "xfilter.c", (uword) 147,
                            ((char *) __FUNCTION__), "cm->cli_command_registrations");
            }
        } while (0);
        if (cm->cli_command_registrations == &xfilter_enable_disable_command)
            cm->cli_command_registrations = (&xfilter_enable_disable_command)->next_cli_command;
        else {
            __typeof__(&xfilter_enable_disable_command) current = cm->cli_command_registrations;
            while (current->next_cli_command) {
                if (current->next_cli_command == &xfilter_enable_disable_command) {
                    current->next_cli_command = current->next_cli_command->next_cli_command;
                    break;
                }
                current = current->next_cli_command;
            }
            do {
                if ((0 > 0) && !(current)) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails", "xfilter.c", (uword) 147,
                                ((char *) __FUNCTION__), "current");
                }
            } while (0);
        }
    };
}
static vlib_cli_command_t xfilter_enable_disable_command = {
    .path       = "xfilter enable-disable",
    .short_help = "xfilter enable-disable <interface-name> [disable]",
    .function   = xfilter_enable_disable_command_fn,
};
static void
vl_api_xfilter_enable_disable_t_handler(vl_api_xfilter_enable_disable_t *mp)
{
    vl_api_xfilter_enable_disable_reply_t *rmp;
    xfilter_main_t *sm = &xfilter_main;
    int rv;
    rv = xfilter_enable_disable(sm, ntohl(mp->sw_if_index), (int) (mp->enable_disable));
    do {
        vl_api_registration_t *rp;
        rv = vl_msg_api_pd_handler(mp, rv);
        rp = vl_api_client_index_to_registration(mp->client_index);
        if (rp == 0)
            return;
        rmp             = vl_msg_api_alloc(sizeof(*rmp));
        rmp->_vl_msg_id = htons((VL_API_XFILTER_ENABLE_DISABLE_REPLY) + (sm->msg_id_base));
        rmp->context    = mp->context;
        rmp->retval     = ntohl(rv);
        vl_api_send_msg(rp, (u8 *) rmp);
    } while (0);
    ;
}
static clib_error_t *
xfilter_plugin_api_hookup(vlib_main_t *vm)
{
    xfilter_main_t *sm = &xfilter_main;
    vl_msg_api_set_handlers((VL_API_XFILTER_ENABLE_DISABLE + sm->msg_id_base), "xfilter_enable_disable",
                            vl_api_xfilter_enable_disable_t_handler, vl_noop_handler,
                            vl_api_xfilter_enable_disable_t_endian, vl_api_xfilter_enable_disable_t_print,
                            sizeof(vl_api_xfilter_enable_disable_t), 1);
    ;
    return 0;
}
static void
setup_message_id_table(xfilter_main_t *sm, api_main_t *am)
{
    vl_msg_api_add_msg_name_crc(am,
                                "xfilter_enable_disable"
                                "57298519",
                                VL_API_XFILTER_ENABLE_DISABLE + sm->msg_id_base);
    vl_msg_api_add_msg_name_crc(am,
                                "xfilter_enable_disable_reply"
                                "e8d4e804",
                                VL_API_XFILTER_ENABLE_DISABLE_REPLY + sm->msg_id_base);
    ;
}
static clib_error_t *
xfilter_init(vlib_main_t *vm)
{
    xfilter_main_t *sm  = &xfilter_main;
    clib_error_t *error = 0;
    u8 *name;
    sm->vlib_main   = vm;
    sm->vnet_main   = vnet_get_main();
    name            = format(0, "xfilter_%08x%c", api_version, 0);
    sm->msg_id_base = vl_msg_api_get_msg_ids((char *) name, VL_MSG_FIRST_AVAILABLE);
    error           = xfilter_plugin_api_hookup(vm);
    setup_message_id_table(sm, &api_main);
    do {
        if (name) {
            clib_mem_free(vec_header((name), (0)));
            name = 0;
        }
    } while (0);
    return error;
}
clib_error_t *
xfilter_early_init(vlib_main_t *vm)
{
    printf("in xfilter early init\n");
    return ((void *) 0);
}
static clib_error_t *
xfilter_config(vlib_main_t *vm, unformat_input_t *input)
{
    printf("in xfilter config func\n");
    return ((void *) 0);
}
vlib_config_function_runtime_t _vlib_config_function_xfilter_config;
static void __vlib_add_config_function_xfilter_config(void) __attribute__((__constructor__));
static void
__vlib_add_config_function_xfilter_config(void)
{
    vlib_main_t *vm                                        = vlib_get_main();
    _vlib_config_function_xfilter_config.next_registration = vm->config_function_registrations;
    vm->config_function_registrations                      = &_vlib_config_function_xfilter_config;
}
static void __vlib_rm_config_function_xfilter_config(void) __attribute__((__destructor__));
static void
__vlib_rm_config_function_xfilter_config(void)
{
    vlib_main_t *vm                   = vlib_get_main();
    vlib_config_function_runtime_t *p = &_vlib_config_function_xfilter_config;
    {
        do {
            if ((0 > 0) && !(vm->config_function_registrations)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails", "xfilter.c", (uword) 243,
                            ((char *) __FUNCTION__), "vm->config_function_registrations");
            }
        } while (0);
        if (vm->config_function_registrations == p)
            vm->config_function_registrations = (p)->next_registration;
        else {
            __typeof__(p) current = vm->config_function_registrations;
            while (current->next_registration) {
                if (current->next_registration == p) {
                    current->next_registration = current->next_registration->next_registration;
                    break;
                }
                current = current->next_registration;
            }
            do {
                if ((0 > 0) && !(current)) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails", "xfilter.c", (uword) 243,
                                ((char *) __FUNCTION__), "current");
                }
            } while (0);
        }
    };
}
vlib_config_function_runtime_t _vlib_config_function_xfilter_config = {
    .name     = "xfilter",
    .function = xfilter_config,
    .is_early = 0,
};
vlib_init_function_t *_vlib_init_function_xfilter_init = xfilter_init;
static void __vlib_add_init_function_xfilter_init(void) __attribute__((__constructor__));
static void
__vlib_add_init_function_xfilter_init(void)
{
    vlib_main_t *vm = vlib_get_main();
    static _vlib_init_function_list_elt_t _vlib_init_function;
    _vlib_init_function.next_init_function = vm->init_function_registrations;
    vm->init_function_registrations        = &_vlib_init_function;
    _vlib_init_function.f                  = &xfilter_init;
}
static void __vlib_rm_init_function_xfilter_init(void) __attribute__((__destructor__));
static void
__vlib_rm_init_function_xfilter_init(void)
{
    vlib_main_t *vm = vlib_get_main();
    _vlib_init_function_list_elt_t *next;
    if (vm->init_function_registrations->f == &xfilter_init) {
        vm->init_function_registrations = vm->init_function_registrations->next_init_function;
        return;
    }
    next = vm->init_function_registrations;
    while (next->next_init_function) {
        if (next->next_init_function->f == &xfilter_init) {
            next->next_init_function = next->next_init_function->next_init_function;
            return;
        }
        next = next->next_init_function;
    }
};
static vnet_feature_registration_t vnet_feat_xfilter;
static void __vnet_add_feature_registration_xfilter(void) __attribute__((__constructor__));
static void
__vnet_add_feature_registration_xfilter(void)
{
    vnet_feature_main_t *fm = &feature_main;
    vnet_feat_xfilter.next  = fm->next_feature;
    fm->next_feature        = &vnet_feat_xfilter;
}
static void __vnet_rm_feature_registration_xfilter(void) __attribute__((__destructor__));
static void
__vnet_rm_feature_registration_xfilter(void)
{
    vnet_feature_main_t *fm        = &feature_main;
    vnet_feature_registration_t *r = &vnet_feat_xfilter;
    {
        do {
            if ((0 > 0) && !(fm->next_feature)) {
                _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails", "xfilter.c", (uword) 247,
                            ((char *) __FUNCTION__), "fm->next_feature");
            }
        } while (0);
        if (fm->next_feature == r)
            fm->next_feature = (r)->next;
        else {
            __typeof__(r) current = fm->next_feature;
            while (current->next) {
                if (current->next == r) {
                    current->next = current->next->next;
                    break;
                }
                current = current->next;
            }
            do {
                if ((0 > 0) && !(current)) {
                    _clib_error(CLIB_ERROR_ABORT, 0, 0, "%s:%d (%s) assertion `%s' fails", "xfilter.c", (uword) 247,
                                ((char *) __FUNCTION__), "current");
                }
            } while (0);
        }
    };
}
static vnet_feature_registration_t vnet_feat_xfilter = {
    .arc_name    = "device-input",
    .node_name   = "xfilter",
    .runs_before = (char *[]){"ethernet-input", 0},
};
vlib_plugin_registration_t vlib_plugin_registration __attribute__((__section__(".vlib_plugin_registration"))) = {
    .version     = "18.10-15~g16012e75-dirty",
    .description = "xfilter plugin description goes here",
    .early_init  = "xfilter_early_init",
};
