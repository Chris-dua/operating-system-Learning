 /*
#include <unistd.h>
ssize_t read(int fd, void *buf, size_t count);
       参数：
        -fd: 文件描述符，open得到的，通过这个文件描述符操作某个文件
        -buf：需要读取数据存放的地方，数组的地址（传出参数）
        -count：指定的数组的大小
        返回值：
        -success：
            >0:返回实际的读取到的字节数
            =0：文件已经读取完了
        -filed：-1，并且设置errno

#include <unistd.h>
ssize_t write(int fd, const void *buf, size_t count);
    参数：
        -fd：文件描述符，open得到的
        -buf：往磁盘中写数据，数据
        -count：要写的数据的实际大小
    返回值：
        success：实际写入的字节数
        failed：返回-1，并设置errno

*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
//ssize_t read(int fd, void *buf, size_t count);
int main(){
    //通过open打开文件
    int srcfd= open("english.txt",O_RDONLY);
    if(srcfd==-1){
        perror("open");
        return -1;
    }
    //创建一个新的文件（拷贝文件）
    int destfd=open("cpy.txt",O_WRONLY|O_CREAT,0664);
     if(destfd==-1){
        perror("open");
        return -1;
    }
    //频繁的读写操作
    char buf[1024]={0};
    int len=read(srcfd,buf,sizeof(buf));
    
    while(len>0){
        write(destfd,buf,len);
        len=read(srcfd,buf,sizeof(buf));
    }
    //关闭文件
    close(destfd);
    close(srcfd);
    return 0;
}