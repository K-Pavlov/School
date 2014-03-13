#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t wait_for_worker;
//worker with his total gold collected
struct mine
{
	int gold_in_mine;
	bool used = 0;
	
}mines

mines* allmines;

void* sum(void* mine_count)
{	
	if(allmines[mine_count]->used == 0)
	{
		while(gold_in_mine > 0)
		{
			pthread_mutex_lock(&sum_mutex);
			//Behaviour of the workers
			if(gold_in_mine > 0)
			{
				printf("Worker %d entered the mine\n",);
				current_worker -> gold_collected += 10;
				printf("Worker %d exited the mine\n", );
			}
			pthread_mutex_unlock(&sum_mutex);
		}
	}		
	pthread_exit(NULL);
}

int main(int argc, char** argv)
{
	int worker_number;
	int gold_in_mine = (int) argv[1];
	int worker_count = (int) argv[2];
	int mine_count = (int) argv[3];
	
	allmines = malloc(sizeof(totalomines) * mine_count));
	
	pthread_t worker[worker_count];	
	pthread_mutex_init(&wait_for_worker, NULL);
	
	for(worker_number = 0; worker_number < worker_count; worker_number++)
	{
		current_worker = workers[worker_number];
		pthread_create(worker[worker_number], NULL, sum, (void*)worker_number;}
	}

	for(worker_number = 0; worker_number < worker_count; worker_number++)
	{	
		pthread_join(worker[worker_number], NULL);
	}
		
	
	
	pthread_mutex_destroy(&wait_for_worker);
	
	return 0;
}
