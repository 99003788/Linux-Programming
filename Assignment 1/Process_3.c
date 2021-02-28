#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(int argc, char *argv[])
{
    pid_t ret;
    int status;

    ret = fork();
    if(ret>0)
    {
        //parent class
        ret = waitpid(-1,&status,0);
        //printf("\ntotal count is %d\n",argc);
    }
    else
    {
        //child class
        //Compiling
        for(int i=1;i<argc;i++)
        {
            ret = fork();
            if(ret>0)
                ret = waitpid(-1,&status,0);
            else
                execlp("gcc","gcc",argv[i],"-c",NULL);
        }

        //Linking
        for(int i=1;i<argc;i++)
        {
            for(int j=0;argv[i][j]!='\0';j++)
                if(argv[i][j]=='.')
                {
                    argv[i][j+1]='o';
                    break;
                }
        }
        ret=fork();
        if(ret>0)
            ret = waitpid(-1,&status,0);
        else
            execlp("gcc","gcc",argv[1],argv[2],argv[3],"-o","test",NULL);

         //Execution
        execlp("./test","./test",NULL);
    }
}
