# 概述

## 引言

- 本章先会说明 文件 I/O 函数 -- 打开文件、读文件、写文件等，Unix 系统中的大多数文件 I/O 只需用到 5 个函数： open  read  write lseek 以及 close

- 然后说明不同缓冲长度对 read 和 write 函数的影响

> 术语 `不带缓冲` 指的是每个 read 和 write 都调用内核中的一个系统调用。这些不带缓冲的 I/O 函数不是 ISO C 的组成部分，但是，它们是 POSIX.1 和 Single UNIX Specification 的组成部分

只要有涉及多个进程间共享资源，原子操作的概念就变得非常重要

本章会讨论多个进程如何共享文件，以及所涉及的内核相关数据结构，也会说明 dup fcntl  sync  fsync ioctl 函数

### 文件描述符

##### open 函数

