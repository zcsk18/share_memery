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
    char *c_addr;  
    if(argc!=2){  
        fprintf(stderr,"Usage：%s need start arg!\n\a",argv[0]);  
        exit(1);  
    }  
 
    shmid = atoi(argv[1]); 
    c_addr=shmat(shmid,0,0);  
    printf("Client get %s\n",c_addr); 
 
 
    shmctl(shmid,IPC_RMID,NULL);
    printf("client rm share memery: %d\n",shmid);
}  
