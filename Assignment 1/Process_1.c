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
        printf("\nMini Shell END\n");
    }
    else
    {
        //child class
        execlp(argv[1],argv[1],argv[2],NULL);
        sleep(2);

    }
}
