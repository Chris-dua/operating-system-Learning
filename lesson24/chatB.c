#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
    int ret=access("fifo1",F_OK);
    if(ret == -1){
        printf("创建管道\n");
        mkfifo("fifo1",0664);
        if(ret == -1){
            perror("mkfifo");
            exit(0);
        }

    }
     ret=access("fifo2",F_OK);
    if(ret == -1){
        printf("创建管道\n");
        mkfifo("fifo2",0664);
        if(ret == -1){
            perror("mkfifo");
            exit(0);
        }
    }
    //B中只读管道
    int fdr=open("fifo1",O_RDONLY);
    if(fdr==-1){
        perror("open");
        exit(0);
    }
        printf("等待写入\n");
    //B中只写管道
    int fdw=open("fifo2",O_WRONLY);
    if(fdw==-1){
        perror("open");
        exit(0);
    }
        printf("等待键入\n");
    char buf[128];
    //循环写数据
    while(1){
        memset(buf,0,128);
        int len=read(fdr,buf,128);
        if(len<=0){
            perror("read");
            break;
        }
        printf("bufA:%s\n",buf);
    

    //循环收数据
        memset(buf,0,128);
        
        fgets(buf,128,stdin);
        ret =write(fdw,buf,strlen(buf));
        if(ret==-1){
            perror("write");
            break;
        } 
    }
    return 0;
    close(fdr);
    close(fdw);
}