#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t wait;
short mother_finished = 0;

short check_if_full_plates(short* table_plates)
{
	short full_plate = 0;
	int i;
	pthread_mutex_lock(&wait);
	for(i = 0; i < 4; i++)
	{
		if(table_plates[i] == 1)
		{
			return 1;
		}
	}
	pthread_mutex_unlock(&wait);
	return 0;
}

void* maika_mu_gotvi(void* table_plates)
{ 
	short* plates = (short*) table_plates;
	int flour_weight = 1000;
	int plate = 0;
	while(flour_weight > 0)
	{
		if(plate == 4)
		{
			plate = 0;
		}
		int random_flour = rand() % 100 + 1;
		//printf("%d ---- %d\n", random_flour, plates[plate] );
		if(flour_weight >= random_flour && plates[plate] == 0)
		{
			pthread_mutex_lock(&wait);
			//printf("GOTVA BE");
			flour_weight -= random_flour;
			printf("%d", flour_weight);
			usleep(random_flour*10000);
			plates[plate] = 1;
			pthread_mutex_unlock(&wait);
		} 
		plate++;
	}
	mother_finished = 1;
	pthread_exit(NULL);
}

void* toi_qde(void* table_plates)
{
	short* plates = (short*) table_plates;
	int plate = 0;
	int i_am_eating = rand() % 100 + 1;
	printf("%d ------------- %d\n", mother_finished, check_if_full_plates(plates));
	while(mother_finished == 0 && check_if_full_plates(plates) == 1)
	{	
		if(plate == 4)
		{
			plate = 0;
		}
		if(plates[plate] == 1)
		{
			pthread_mutex_lock(&wait);
			printf("QM MA");
			usleep(i_am_eating * 10000);	
			plates[plate] = 0;
			pthread_mutex_unlock(&wait);
		}
		plate++;
	}
	
}

int main()
{
	pthread_mutex_init(&wait, NULL);
	pthread_t ivancho, maika_mu;
	short table_plates[4];	
	pthread_create(&maika_mu, NULL, maika_mu_gotvi, (void*) table_plates);		
	pthread_create(&ivancho, NULL, toi_qde, (void*) table_plates);
	
	pthread_join(maika_mu, NULL);
	pthread_join(ivancho, NULL);
	
	pthread_mutex_destroy(&wait);
	
	return 0;
}
