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
   //int n = size;
 
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
	pthread_t thread_id;
	printf("Start of thread");
	pthread_create(&thread_id,NULL,Sorting(list,10),NULL);
	pthread_join(thread_id,NULL);
	printf("End of thread");
	exit(0);
  return 0;
}
