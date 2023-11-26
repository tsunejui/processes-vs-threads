#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
        int allocMem;
        printf("Please enter the amount of memory (in MB) you would like to use: ");
        if (scanf("%d", &allocMem) != 1) {
            printf("Error: Invalid input\n");
            exit(1);
        }

        long total = allocMem * 1024 * 1024;
        void *m = malloc(total);
        memset(m,0,total);
        printf("Process Number: %d\n", getpid());
        printf("Total memory usage: %d MB\n", allocMem);
        sleep(300);
        return 0;
}