#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE (sizeof(list)/sizeof(*list))
int list[] = {7,12,19,3,18,4,2,6,15,8};
int result[SIZE] = {0};

typedef struct{
	int * subArray;
	unsigned int size;
	} SortingThreadParameters;
	typedef struct
	{
		SortingThreadParameters left;
		SortingThreadParameters right;
	} MergingThreadParameters;
	
	
	
int compare(const void* a, const void* b) {
  return(*(int*)a - *(int*)b);
}
void* Sorting(int x[],int size){
 
   qsort(list, SIZE, sizeof(int), compare);
   
	for(int j = 0; j < SIZE/2; j++){
    printf("%d ",x[j]);
   }
  	for(int i = 5; i < SIZE; i++){
    printf("%d ",x[i]);
   }
   return NULL;
	}
int main() {
	Sorting(list,10);
	pthread_t threads[2];
	pthread_create(&threads[0],NULL,Sorting(list,5),(void*)NULL);
	pthread_create(&threads[1],NULL,Sorting(list,10),(void*)NULL);
	pthread_join(threads[0],NULL);
	pthread_join(threads[1],NULL);

	printf("the sorted array: ");
	for (int i = 0; i < SIZE; i++){
	printf("%d",list[i]);
}
  return 0;
}
