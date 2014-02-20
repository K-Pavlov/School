#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
///qsort(
#define SIZE 10000	
#define THREAD_COUNT 2
int compare(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
void* calc(void* array)
{
	qsort(array,SIZE/2,sizeof(int),compare);
	return 0;
}
int main()
{		
	int i;
	int k;
	// Array init
	int array[SIZE];
	for(i = SIZE - 1, k =0; i >= 0; i--, k++)
	{
		array[k] = i;
	}
	//Thread count
	pthread_t threads[THREAD_COUNT];
	//Creating, calculating
	for(i = 0; i < THREAD_COUNT; i ++)
	{		
		if( pthread_create(&threads[i], NULL, calc,(void*)&array[SIZE/2*i] ) != 0)
		{
			perror("Error creating thread");
		}
	}
	//waiting
	void* return_value;
	for(i = 0; i < THREAD_COUNT; i++)
	{
        	if(pthread_join(threads[i], &return_value) != 0)
        	{
        		perror("Error when joining");
        	}
	}
	int sorted[SIZE];
	int place_in_sorted = 0;
	int first_part = 0;
	int second_part = SIZE/2;
	while(place_in_sorted != SIZE)
	{
		if(second_part == SIZE )
		{
			sorted[place_in_sorted++] = array[first_part++];
			continue;
		}
		
		if(first_part == SIZE/2)
		{
			sorted[place_in_sorted++] = array[second_part++];
			continue;
		}
		
		if(array[first_part] > array[second_part])
		{
			sorted[place_in_sorted++] = array[second_part++];
		}
		else
		{
			sorted[place_in_sorted++] = array[first_part++];
		}
	}	
	
	for(i = 0; i < SIZE; i++)
	{
		printf("%d\n", sorted[i]);
	}		
	pthread_exit(NULL);								
	return 0;
}
