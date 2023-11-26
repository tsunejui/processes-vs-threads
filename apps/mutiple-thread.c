#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/syscall.h> 

void* routine() {
    printf("Thread Process Number: %d\n", getpid());
    pid_t tid;
    tid = syscall(SYS_gettid);
    printf("tid : %d\n",tid);
    sleep(300);
    return 0;
}

int main(int argc, char* argv[]) {

    printf("Main Process Number: %d\n", getpid());

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