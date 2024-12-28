//library for file control operations
#include<fcntl.h>
//library to close file using file descriptors
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
// stat.h will be used to check the file access permissions.
#include<sys/stat.h>
// to check if a system call has failed.
#include<errno.h>
/*
Concept 1: Kernel
A computer has hardware and software components. There are an unlimited number of options for the hardware components. Thus there must be an interface between the
software and the hardware. This is the kernel. (its an abstraction layer between the hardware and the software)

for us it is important as kernel maintains a list of preprocess open files. Each entry in the kernel in the form of an integer.

stdin: 0
stdout: 1
stderr: 2
this is called the file descripter.
*/

/*
Concept 2: open();
we already know fopen but fopen is the higher level call. infact fopen uses open.
instead of returning a file pointer like fopen it returns an int called the file descripter. (OS way of keeping track of files.)

fopen uses bufferingIO. this makes fopen faster than open in many cases!
fopen is also easy to port as even windows can use it.

then why use open instead of fopen: in Unix based operating systems there are many things which are stored as files but are not really files. Things like pipes and
serial ports on other devices. For some of these while interacting timing matters. So buffering is not desireable. Because its not a file I am writing into its a device
connecting through serial port where data needs to be transferred immediately. So not needed to use open.

open also takes in flags:
    //      O_RDONLY
    //      O_WRONLY
    //      O_RDWR
*/

int main(){
    int fd;
    fd = open("./test.txt", O_WRONLY);
    // Print out the flag and fd
    printf("Flag: 0x%X\n", O_WRONLY );
    printf("File descriptor fd = %d\n", fd);
    // close the file using close()
    close(fd);

    fd =open("./test2.txt",O_WRONLY | O_TRUNC);
    // we can bitwise or different flags:
    // for example this flag O_WRONLY|O_TRUNC means we are opening the file in write only mode and truncating the file making the test2.txt empty.
    // Print out the flag and fd
    printf("Flag: 0x%X\n", O_WRONLY | O_TRUNC);
    printf("File descriptor fd = %d\n", fd);
    close(fd);

    // file creation
    // first we need to decide the file permissions of the file. for this we create a variable mode. 
    mode_t mode = S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IROTH;
    // the above line gave read + write + execute perimission to user, read perimission to group and read permission to others.
    // or we can use hexadecimal
    mode = 0744;
    const char* name = "createfile.txt";

    int fd2 = creat(name,mode);
    if(fd2==-1){
        printf("Error in file creation");
        assert(0);
    }

    //reading:
    /*
    we create a 100 size biffer using calloc.
    signed size_t is the type for the read return.
    we need to read all the bytes from file. we also need to ensure we dont after EOF
    when we get ret = 0 then we have reached EOF
    */
    int fd3 = open("./test.txt",O_RDONLY);
    int len = 100;
    int position =0;
    char *buffer = (char*) calloc(len,sizeof(char));
    ssize_t ret;

    while(len!=0 && (ret = read(fd3,buffer+position,len)!=0)){
        if(ret==-1){
            // a signal was recieved before any bytes were read so can reissue
            if(errno == EINTR){
                continue;
            }
            // non-recoverable error
            printf("ERROR: read unsuccesfully");
            assert(0);
        }
        // update len
        len -= ret;
        position+=ret;
        printf("finished reading %ld bytes, updates len to %d, updated position to %d",ret,len,position);  
    }
    if(close(fd3)==-1){
        printf("Error in closing file");
        assert(0);
    }
    printf("Message:%s",buffer);
    /*
    Writing:

    open flag should be O_WRONLY | O_APPEND so prev stuff doesnot disappear
    O_WRONLY | O_TRUNC to remove previous content.
    
    in write():
    it almost rever returns 0 so in most cases we can ignore it.
    it returns -1 in error or number of bytes written.
    */
    mode = 0744;
    const char* name2 = "createfile_write.txt";
    int fd4 = creat(name2,mode);
    int position2 = 0;
    ssize_t ret2;
    fd4 = open("createfile_write.txt",O_WRONLY | O_APPEND);
    if(fd4==-1){
        printf("Error in opening the file");
        assert(0);
    }
    const char* messsage = "This is a test writing message";
    int len2 = strlen(messsage);
    // write entire message ensure we keep writing on partial writes brea on retuens of 0
    while(len2!=0 && (ret2= write(fd4,messsage+position,len2) !=0)){
        if(ret2==-1){
            if(errno==EINTR){
                continue;
            }
            printf("Unrecoverable error read unsuccessful");
            assert(0);
        }
        len2 -=ret2;
        position2+=ret2;
        printf("Written %ld bytes, len updated to %d and position updated to %d",ret2,len2,position2);
    }
    if(close(fd4)==-1){
        printf("Error in closing the file");
        assert(0);
    }
    printf("write completed");
    return(0);
}
