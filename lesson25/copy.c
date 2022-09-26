/* 1、对原始文件进行内存映射
2、创建新文件
3、把新文件的数据映射到内存中
4、通过内存拷贝把第一个文件的内存数据拷贝到新的文件内存中
5、释放资源 */

#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int main(){

    //对原始文件进行内存映射
    int fd = open("english.txt",O_RDWR);
    if(fd==-1){
        perror("open");
        exit(0);
    }

    //获取原始文件的长度
    int len =lseek(fd,0,SEEK_END);
    //创建一个新文件
    int fd1 =open("cpy.txt",O_RDWR|O_CREAT,0664);
    if(fd1==-1){
        perror("open");
        exit(0);
    }
    //对新文件进行拓展
    truncate("cpy.txt",len);
    write(fd1," ",1);
    //分别做内存映射
    void*ptr1=mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    void *ptr2=mmap(NULL,len,PROT_READ|PROT_WRITE,MAP_SHARED,fd1,0);
    if(ptr1==MAP_FAILED||ptr2==MAP_FAILED){
        perror("mmap");
        exit(0);
    }

    //内存拷贝
    memcpy(ptr2,ptr1,len);
    munmap(ptr2,len);
    munmap(ptr1,len);
    close(fd1);
    close(fd);
    return 0;


}