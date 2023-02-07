//declaring or importing required libraries.
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

//Declaring function collatzConjucture
void collatzConjucture(int n, int child){
    //declare char type variable to store a string
    char buffer[50];
    //using sprintf to store the string into buffer instead of printing on stdout.
    sprintf(buffer, "From Child %d init n = %d, ", child, n);
    //displaying the buffer using printf
    printf("%s", buffer);
    //iterating loop while the condition is true for collatz conjucture
    while(n > 1){
        if(n % 2 == 0){ //collatz conjucture logic for even numbers 
            n = n / 2;
            //using sprintf to store the string into buffer instead of printing on stdout.
            sprintf(buffer, "From child %d n = %d, ", child, n);
            //displaying the buffer using printf
            printf("%s", buffer);
        }
        else{
            //collatz conjucture logic for odd numbers 
            n = (n * 3) + 1;
            //using sprintf to store the string into buffer instead of printing on stdout.
            sprintf(buffer, "From child %d n = %d, ", child, n);
            //displaying the buffer using printf
            printf("%s", buffer);
        }
    }
    //displaying in new line
    printf("\n");
}

//declaring main function with argc and argv as command line arguments for command line input
int main(int argc, char* argv[])
{
    //declaring variables
    int pid, pid1;
    //converting char type variable to int type
    int a = atoi(argv[1]);
    //fork() is called to create new child process
    pid = fork();
    //checking if the input is in given limit
    if(a > 1 || a < 40){
        //if fork() returns 0, it means child process is created.
        if(pid == 0){
            //child 1 calling the collatzConjucture function
            collatzConjucture(a, 1);
            exit(0);
        }
        else{
            //calling fork() to create another child process
            pid1 = fork();
            //if fork() returns 0, it means another child process is created
            if(pid1 == 0){
                //child 2 calling the collatzConjucture function
                collatzConjucture(a+3, 2);
                exit(0);
            }
            else{
                //using wait() for children to complete its process
                wait(0);
                wait(0);
                printf("children complete\n");
            }
        }
    }
    

    return 0;
}
