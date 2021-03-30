#include "apue.h"

/*
打印当前用户的id，与组id
*/
int
main(void)
{
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    exit(0);
}