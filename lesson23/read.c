#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

//打开管道
int main(){
int fd=open("test",O_RDONLY);
if(fd==-1){
    perror("open");
    exit(0);
}
while(1){
    char buf[1024]={0};
    int len=read(fd,buf,sizeof(buf));
    if(len==0){
        printf("连接失败\n");
        break;
    }   
    printf("recv buf: %s\n", buf);
}
close(fd);
return 0;
}
