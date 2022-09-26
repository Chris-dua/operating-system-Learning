/*
#include <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

    //打开一个以及存在的文件
    int open(const char *pathname, int flags);
        参数：
        - pathname: 要打开的路径
        - flag：对文件的操作权限设置以及其他的设置
            O_RDPNLY, O_WORNLY, O_RDWR 这三个设置是互斥的
        返回值：返回一个新的文件描述符，如果调用失败，返回-1
        
    erron：属于Linux系统函数库，库里面的一个全局变量，记录的是错误号

    #include <stdio.h>
    void perror(const char *s);


    //创建一个新的文件
    int open(const char *pathname, int flags, mode_t mode);

    */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(){
   int fd = open("a.txt",O_RDONLY);
   if(fd ==-1){
        perror("open");
   }
   //关闭
   close(fd);
}