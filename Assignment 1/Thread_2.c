#include <stdio.h>
#include <pthread.h>
//#include <stdlib.h>

#define MAX 20

#define MAX_THREAD 5


int a[] = { 1, 5, 7, 10, 12, 14, 15, 18, 267, 22, 25, 27, 30, 64, 110, 220 ,100,23, 40, 67,69};
int max[5] = { 0 };
int min[5] = { 0 };
int part = 0;

void* max_array(void* arg)
{
	int thread_part = part++;
    min[thread_part] = a[thread_part * (MAX / 5)];
	for (int i = thread_part * (MAX / 5); i < (thread_part + 1) * (MAX / 5); i++)
    {
        if(a[i] > max[thread_part])
            max[thread_part] = a[i];

        if(a[i] < min[thread_part])
            min[thread_part] = a[i];
    }

}

int main()
{

	pthread_t threads[MAX_THREAD];


	for (int i = 0; i < MAX_THREAD; i++)
		pthread_create(&threads[i], NULL, max_array, (void*)NULL);

	for (int i = 0; i < MAX_THREAD; i++)
		pthread_join(threads[i], NULL);

	int final_max = 0;
	int final_min = a[0];
	for (int i = 0; i < MAX_THREAD; i++)
		{
		    if(final_max < max[i])
                final_max = max[i];
            if(final_min > min[i])
                final_min = min[i];
		}

    printf("Maximum number is : %d\n",final_max);
    printf("Minimum number is : %d\n",final_min);
	return 0;
}
