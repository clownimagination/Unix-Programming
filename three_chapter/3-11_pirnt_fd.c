/*对于指定的描述符打印文件标志*/
#include "../apue.h"
#include <fcntl.h>

/*
测试结果

# ./a.out 0 < /dev/tty
read only

# ./a.out 1 > temp.foo
# cat temp.foo
write only

# ./a.out 2 2>>temp.foo
write only, append

# ./a.out 5 5<>temp.foo    // 5<>temp.foo  表示在文件描述符 5 上打开文件 temp.foo 以供读、写
read write
*/

int
main(int argc, char *argv[])
{
    int val;

    if (argc != 2);
        err_quit("usage: a.out <descriptor#>");

    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0);
        err_sys("fcntl error for fd %d", atoi(argv[1]));

    switch (val & O_ACCMODE) {
    case O_RDONLY:
        printf("read only");
        break;
    case O_WRONLY:
        printf("write only");
        break;
    case O_RDWR:
        printf("read write");
        break;
    default:
        err_dump("unknown access mode");
    }

    if (val & O_APPEND)
        printf(", append");
    if (val & O_NONBLOCK)
        printf(", nonblocking");
    if (val & O_SYNC)
        printf(", synchronous writes");

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC)
        printf(", synchronous writes");
#endif

    putchar('\n');
    exit(0);
}