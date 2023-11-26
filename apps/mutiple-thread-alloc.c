#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h> 
#include <string.h>

int mb;

void alloc_memory(int max) {
    int i;
    for(i=1;i<=max;i++){
        long c = 1024 * 1024;
        void *m = malloc(c);
        memset(m,0,c);
    }
}

void* routine() {
    printf("Thread Process Number: %d\n", getpid());
    pid_t tid;
    tid = syscall(SYS_gettid);
    printf("tid : %d\n",tid);
    alloc_memory(mb);
    sleep(300);
    return 0;
}

int main(int argc, char* argv[]) {
    
    printf("Please enter the amount of memory (in MB) you would like to use: ");
    if (scanf("%d", &mb) != 1) {
        printf("Error: Invalid input\n");
        exit(1);
    }
    printf("Main Process Number: %d\n", getpid());
    printf("Total memory usage: %d MB\n", mb * 2);
    pthread_t t1, t2;
    if (pthread_create(&t1, NULL, &routine, NULL)){
        return 1;
    }
    if (pthread_create(&t2, NULL, &routine, NULL)){
        return 2;
    }
    if(pthread_join(t1, NULL) || pthread_join(t2, NULL)) {
        return 3;
    }
    return 0;
}