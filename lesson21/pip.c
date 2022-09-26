/*
#include <unistd.h>
int pipe(int pipefd[2]);
    功能-创建匿名管道，用来进程间通信
    参数：int pipefd[2]
    pipefd[0]-读端
    pipefd[1]-写端
    返回值：
    成功 0
    失败 -1
注意：匿名管道只能用于具有关系的进程之间的通信（父子进程，兄弟进程）
*/
//子进程发送数据给父进程，父进程读取数据输出


//write()
//函数定义：ssize_t write (int fd, const void * buf, size_t count); 
//read()
//函数定义：ssize_t read(int fd, void * buf, size_t count);
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
    //创建子进程前开辟管道
    int pipefd[2];
    int ret = pipe(pipefd);
    if(ret == -1){
        perror("pipe");
        exit(0);
    }
    //创建子进程
    pid_t pid=fork();
    if(pid>0){
        //父进程
        char buf[1024]={0};
        int len =read(pipefd[0],buf,sizeof(buf));
        printf("parent recv: %s,pid: %d\n",buf,getpid());

    }
    else if(pid==0){
        //子进程
        char *str="hello, i am child process";
        write(pipefd[1],str,strlen(str));
    }
    return 0;
}