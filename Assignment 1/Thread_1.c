#include <stdio.h>
#include <pthread.h>
//#include <stdlib.h>

#define MAX 20

#define MAX_THREAD 5


int a[] = { 1, 5, 7, 10, 12, 14, 15, 18, 267, 22, 25, 27, 30, 64, 110, 220 ,100,23, 40, 67,69};
int sum[5] = { 0 };
int part = 0;

void* sum_array(void* arg)
{

	int thread_part = part++;

	for (int i = thread_part * (MAX / 5); i < (thread_part + 1) * (MAX / 5); i++)
		sum[thread_part] += a[i];
}

int main()
{

	pthread_t threads[MAX_THREAD];


	for (int i = 0; i < MAX_THREAD; i++)
		pthread_create(&threads[i], NULL, sum_array, (void*)NULL);

	for (int i = 0; i < MAX_THREAD; i++)
		pthread_join(threads[i], NULL);

	int total_sum = 0;
	for (int i = 0; i < MAX_THREAD; i++)
		total_sum += sum[i];

    printf("Sum is : %d\n",total_sum);
	return 0;
}
