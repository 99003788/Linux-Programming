#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void handler_for_alarm(int signo)
{
    time_t now;
    time(&now);
    printf("current time is %s\n",ctime(&now));
    alarm(1);
}
int main()
{
    printf("Current Time is : \n");
    signal(SIGALRM,handler_for_alarm);
    alarm(5);
    while(1)
        pause();

    return 0;
}
