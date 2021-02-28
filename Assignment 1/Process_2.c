#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char *argv[])
{
    pid_t ret;
    int status,i;

    ret = fork();
    if(ret>0)
    {
        //parent class
        ret = waitpid(-1,&status,0);
        printf("\nYour File Compiled and Linked\n");
    }
    else
    {
        //child class
        execlp("gcc","gcc",argv[1],NULL);
        sleep(2);

    }
}
