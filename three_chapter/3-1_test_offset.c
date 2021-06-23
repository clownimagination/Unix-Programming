/*测试标准输入能否被设置偏移量*/

#include "../apue.h"
int
main(void)
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        printf("cannot seek\n");
    else
        printf("seek OK\n");
    exit(0);
}

/*测试命令与结果
# ./a.out < /etc/passwd
seek OK

# cat < /etc/passwd | ./a.out
cannot seek

# ./a.out < /var/spool/cron/FIFO
cannot seek
*/