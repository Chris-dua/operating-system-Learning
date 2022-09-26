/*
实现 ps aux|grep xxx
子进程:ps aux,子进程结束后，将数据发给父进程
父进程：获取到数据并且过滤

pipe()
execlp()

子进程将标准输出重定向到管道的写端。  dup2
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wait.h>


int main(){
    int fd[2];
    int ret=pipe(fd);
    if(ret==-1){
        perror("pipe");
        exit(0);
    }
    //创建子进程
    pid_t pid=fork();
    if(pid>0){
        close(fd[1]);
        char buf[1024]={0};
        int len =-1;
        while(len=read(fd[0],buf,sizeof(buf)-1)>0){
            printf("%s",buf);
            memset(buf,0,1024);
        }
        wait(NULL);

    }
    else if(pid==0){
        close(fd[0]);
        //文件描述符重定向
        dup2(fd[1],1);
        execlp("ps","ps","aux",NULL);
        perror("execlp");
    }
    else{
        perror("fork");
        exit(0);
    }
}