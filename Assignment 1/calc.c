#include<stdio.h>
#include<stdlib.h>
#include"calc.h"
int main()
{
    int choice;
    while(1)
    {
        printf("Choose Operation :\n1:Add\n2:Subtraction\n3:Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: add();
                    break;

            case 2: sub();
                    break;

            case 3: exit(0);

            default: printf("\nInvalid Choice\n");
                     break;

        }
    }
}
