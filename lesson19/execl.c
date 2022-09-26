/*
#include <unistd.h>
extern char **environ;
int execl(const char *pathname, const char *arg, ...);
    -参数：
        -path：需要指定的执行的文件的路径或者名称
            a.out /home/chris/a.out 
        -arg: 是可执行文件所需要的参数列表
            第一个参数一般没什么作用，为了方便，一般写的是执行的程序的名称
            从第二个参数开始往后，就是程序执行所需要的参数列表
*/

#include <unistd.h>
#include <stdio.h>
int main(){
    pid_t pid=fork();

    if(pid>0){
        //父进程
        printf("i am parent process,pid: %d,ppid: %d\n",getpid(),getppid());

    }
    else if(pid == 0){ 
        //子进程
       
        execl("/home/chris/Linux/lesson19/hello","hello",NULL);
        printf("i am child process\n");
        

    }
    for(int i=0;i<3;i++){
        printf("i=%d,pid=%d\n",i,getpid());
    }

    return 0;
}