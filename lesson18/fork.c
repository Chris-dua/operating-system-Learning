/*

#include <sys/types.h>
#include <unistd.h>
pid_t fork(void);
        函数的作用：用于创建子进程
        返回值：
            fork()的返回值会返回两次。一次是在父进程中，一次是在子进程中。
            在父进程中返回创建的子进程的ID
            在子进程中返回0
            如何区分父进程和子进程：通过fork的返回值
            在父进程中返回-1，表示创建子进程失败，并且设置errno

*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    //创建子进程
    pid_t pid =fork();

    //进行判断，区分父进程和子进程
    if(pid>0){
        printf("pid:%d\n",pid);
        //如果大于0，返回的是创建的子进程的进程号
        printf("i am parent process,pid : %d,ppid : %d\n",getpid(),getppid());
    }
    else if(pid==0){
        //当前是子进程
        printf("i am child process,pid : %d,ppid : %d\n",getpid(),getppid());
    }
    for(int i=0;i<3;i++ ){
        printf("i : %d\n",i);
        sleep(1);
    }
}

//getpid()得到本身进程id，getppid()得到父进程进程id，如果已经是父进程，得到系统进程id，如bash环境运行得到bash的id