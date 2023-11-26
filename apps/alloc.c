#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
        int mb, i;
        printf("Please enter the amount of memory (in MB) you would like to use: ");
        if (scanf("%d", &mb) != 1) {
            printf("Error: Invalid input\n");
            exit(1);
        }
        for(i=1;i<=mb;i++){
            long c = 1024 * 1024;
            void *m = malloc(c);
            memset(m,0,c);
        }
        printf("Process Number: %d\n", getpid());
        printf("Total memory usage: %d MB\n", mb);
        sleep(300);
        return 0;
}