#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <errno.h>  
#include <unistd.h>  
#include <sys/stat.h>  
#include <sys/types.h>  
#include <sys/ipc.h>  
#include <sys/shm.h>  
#define PERM S_IRUSR|S_IWUSR  
  
int main(int argc,char **argv){  
    int shmid;  
    char *p_addr,*c_addr;  
    if(argc!=2){  
        fprintf(stderr,"Usage：%s need start arg! \n\a",argv[0]);  
        exit(1);  
    }  
  
    if((shmid=shmget(IPC_PRIVATE,1024,PERM))==-1){  
        fprintf(stderr,"Create Share Memory Error：%s\n\a",strerror(errno));  
        exit(1);  
    }  
  
    p_addr=shmat(shmid,0,0);  
    memset(p_addr,'\0',1024);  
    strncpy(p_addr,argv[1],1024); 

    printf("shmid:%d\n",shmid);
}  
