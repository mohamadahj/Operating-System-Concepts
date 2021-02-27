# Operating System Concepts

# Modified XV6

xv6 is a reimplementation of the Unix sixth edition in order to use as a learning tool. xv6 was developed by MIT as a teaching operating system for their “6.828” course. A vital fact about xv6 is that it contains all the core Unix concepts and has a similar structure to Unix even though it lacks some functionality that you would expect from a modern operating system. This is a lightweight operating system where the time to compile is very low and it also allows remote debugging.

### Adding a custom system call in XV6

In order to define your own system call in xv6, we need to make changes to 6 files. Namely, these files are as follows.
1. syscall.h
2. syscall.c
3. sysproc.c
4. usys.S
5. user.h
6. defs.h

### Changing XV6 Scheduler

XV6's default scheduler is Round-Robin. In order to change or customize it, we need to change the codes in scheduler() in proc.c.

### Run XV6

To run XV6, we need to install qemu. After that, type "make clean" in terminal, then type "make", and then, "make qemu".
