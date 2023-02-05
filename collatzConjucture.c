#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

void collatzConjucture(int n, int child){
    char buffer[50];
    sprintf(buffer, "From Child %d init n = %d, ", child, n);
    printf("%s", buffer);
    while(n > 1){
        if(n % 2 == 0){
            n = n / 2;
            sprintf(buffer, "From child %d n = %d, ", child, n);
            printf("%s", buffer);
        }
        else{
            n = (n * 3) + 1;
            sprintf(buffer, "From child %d n = %d, ", child, n);
            printf("%s", buffer);
        }
    }
    printf("\n");
}

int main(int argc, char* argv[])
{
    int pid, pid1;
    int a = atoi(argv[1]);
    pid = fork();
    if(a > 1 || a < 40){
        if(pid == 0){
            collatzConjucture(a, 1);
        }
        else{
            wait(0);
            pid1 = fork();
            if(pid1 == 0){
                collatzConjucture(a+3, 2);
            }
            else{
                sleep(1);
                wait(0);
                printf("children complete \n");
            }
        }
    }
    

    return 0;
}
