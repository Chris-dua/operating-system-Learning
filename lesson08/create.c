/*
#include <sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

   //创建一个新的文件
    int open(const char *pathname, int flags, mode_t mode);
        参数：
        - pathname: 要打开的路径
        - flags：对文件的操作权限设置以及其他的设置
                -必选项：O_RDPNLY, O_WORNLY, O_RDWR 这三个设置是互斥的
                -可选项: O_APPEND, O_SYNC, O_CREAT
        -mode: 八进制的数，表示创建出的新的文件的操作权限，比如0775
        最终的权限是： mode& ~umask(取反)
        0777 & 0775
        1111111111 & 111111101
        ---------------------------
        ->111111101
        按位与：0与任何数都为0
        umask的作用是抹去某些权限。
        
        返回值：返回一个新的文件描述符，如果调用失败，返回-1
        
    erron：属于Linux系统函数库，库里面的一个全局变量，记录的是错误号

    #include <stdio.h>
    void perror(const char *s);
    */


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(){
    //创建文件夹
    int fd = open("creat.txt",O_RDWR |O_CREAT,0777);
        if(fd == -1){
            perror("open");
        }
    
    close(fd);
    return 0;
}