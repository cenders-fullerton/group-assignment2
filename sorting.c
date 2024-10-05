#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE (sizeof(list)/sizeof(*list))
int list[] = {7,12,19,3,18,4,2,6,15,8};
int result[SIZE] = {0};

int compare(const void* a, const void* b) {
  return(*(int*)a - *(int*)b);
}
void* Sorting(int x[],int size){
   int n = size/sizeof(x[0]);
 
   qsort(list, SIZE, sizeof(int), compare);
   
   for (int i = 0; i < n; i++){
    printf("%d ",x[i]);
   }
   return NULL;
	}
int main() {
	pthread_t thread_id;
	printf("Start of thread");
	pthread_create(&thread_id,NULL,Sorting(list,45),NULL);
	pthread_join(thread_id,NULL);
	printf("End of thread");
	exit(0);
  return 0;
}
