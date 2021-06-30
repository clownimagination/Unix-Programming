# 文件和目录

## 函数 stat、fstat、fstatat和lstat

```c
#include <sys/stat.h>

int stat(const char *restrict pathname, struct stat *restrict buf);

int fstat(int fd, struct stat *buf);

int lstat(const char *restrict pathname, struct stat *restrict buf);

int fstatat(int fd, const char *restrict pathname, struct stat *restrict buf, int flag);

/* 所有 4 个函数的返回值：若成功；返回 0； 若失败，返回 -1 */
```