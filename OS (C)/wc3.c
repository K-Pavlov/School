#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>


//Mines as struct
typedef struct
{
	int gold_in_mine;
	short used;
}mine; 

pthread_mutex_t wait_worker;
int* workers_gold;
int worker_count;
mine* mines;
int mine_count;

short check_mines()
{
	//pthread_mutex_lock(&wait_worker);
	int i;
	for (i = 0; i <  mine_count; ++i)
	{
		if (mines[i].gold_in_mine > 0)
		{
			return 1;
		}
	}
	return 0;
	//pthread_mutex_unlock(&wait_worker);
}


//Worker digging
void* dig(void* current_worker)
{
	int workers_number = *(int*)&current_worker;
	int current_mine = 0;
	while(check_mines())
	{
		printf("%d",mines[current_mine].used);
		if(mines[current_mine].used == 0)
		{
			//pthread_mutex_lock(&wait_worker);
			printf("HI\n");
			mines[current_mine].used = 1;
			printf("Worker %d entered mine %d\n",workers_number, current_mine);
			workers_gold[workers_number] += 10;
			mines[current_mine].gold_in_mine -= 10;
			printf("Current gold in worker %d, current gold in mine %d\n", workers_gold[workers_number], mines[current_mine].gold_in_mine);
			sleep(3);
			printf("Worker %d exited mine %d\n",workers_number, current_mine);
			mines[current_mine].used = 0;
			//pthread_mutex_unlock(&wait_worker);
		}
	}
	printf("exit");
	pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{	
	mine_count = atoi(argv[3]);
	int gold = atoi(argv[1]);
	worker_count = atoi(argv[2]);
	
	
	pthread_t workers[worker_count];
	pthread_mutex_init(&wait_worker, NULL);
	//Dynamically alloc space for the mines
	mines = malloc(sizeof(mines) * mine_count);
	workers_gold = malloc(sizeof(workers_gold)*worker_count);
	//Give default values for mines
	int mines_count;
	for(mines_count = 0; mines_count < mine_count; mines_count++)
	{
		mines[mines_count].gold_in_mine = gold;
		mines[mines_count].used = 0;
	}
	//Create threads
	int workers_number;
	for (workers_number = 0; workers_number < worker_count; ++workers_number)
	{
		pthread_create(&workers[workers_number], NULL, dig, NULL);
	}



	//Join threads
	for (workers_number = 0; workers_number < worker_count; ++workers_number)
	{
			pthread_join(workers[workers_number], NULL);
	}
	return 0;
	
}