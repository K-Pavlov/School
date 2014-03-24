#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
pthread_mutex_t wait_worker;
typedef struct
{
	int gold_in_mine;
	short used;
}mine; 

mine* mines;

short check_mine()
{
	int i;
	for (int i = 0; i < sizeof(mines)/sizeof(mines[0]); ++i)
	{
		if(mines[i].gold_in_mine == 0)
		{
			return 0;
		}
	}
	return 1;
}

void* dig_mine(void* arg)
{
	int count_mine = 0;
	while(check_mine())
	{
		if(mines[count_mine].used == 0)
		{
			//TODO kopai
		}
		else
		{
			count_mine++;
		}
	}
	pthread_exit(NULL);
}

void init_mines(int mine_count, int gold)
{
	mines = malloc(sizeof(mines)*mine_count);
	int count;
	for(count = 0; count < mine_count; count++)
	{
		mines[count]->gold_in_mine = gold;
		mines[count]->used = 0;
	}
}

void init_workers(pthread_t* threads, int worker_count)
{
	int i;
	for(i = 0; i < worker_count; i++)
	{
		pthread_create(threads[worker_count], NULL, func, (void*) argv)
	}
}

void init(int mine_count, int gold, pthread_t* threads, int worker_count)
{
	init_mines(mine_count, gold);
	pthread_mutex_init(wait_worker);
}



int main(int argc, char const *argv[])
{
	int mine_count = atoi(argv[1]);
	int gold = atoi(argv[2]);
	int worker_count = atoi(argv[3]);
	init_mines(mine_count, gold);
	return 0;
}