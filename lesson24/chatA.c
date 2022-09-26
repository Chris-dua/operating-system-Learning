#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


/*
access("file",F_OK)----#include <unistd.h>
open("file",O_RDONLY)------#include <sys/types.h>,#include <sys/stat.h>,#include <fcntl.h>
mkfifo("file",0664)----#include<sys/types.h>,#include<sys/stat.h>
perror("")------#include<stdio.h>,#include<stdlib.h>
memset(buf,0,128)----#include<stdio.h>,#include<stdlib.h>
fgets(buf,128,stdin)---#include<stdio.h>
*/
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
    //A中只写管道
    int fdw=open("fifo1",O_WRONLY);
    if(fdw==-1){
        perror("open");
        exit(0);
    }
        printf("等待键入\n");
    //A中只读管道
    int fdr=open("fifo2",O_RDONLY);
    if(fdr==-1){
        perror("open");
        exit(0);
    }
        printf("等待写入\n");
    char buf[128];
    //循环写数据
    while(1){
        memset(buf,0,128);
        fgets(buf,128,stdin);
        ret =write(fdw,buf,strlen(buf));
        if(ret==-1){
            perror("write");
            break;
        } 
    

    //循环收数据
        memset(buf,0,128);
        int len=read(fdr,buf,128);
        if(len<=0){
            perror("read");
            break;
        }
        printf("bufB:%s\n",buf);
    }
    
    close(fdr);
    close(fdw);
    return 0;
}