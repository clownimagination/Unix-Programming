/* umask 函数示例 */
/* umask 就是赋权的取反(相当于关闭什么什么权限) */
#include "../apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int
main (void)
{
    umask(0);
    if (creat("foo", RWRWRW)<0)
        err_sys("creat error for foo");
    umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if (creat("bar", RWRWRW) < 0)
       err_sys("creat error for bar");
    exit(0);
}