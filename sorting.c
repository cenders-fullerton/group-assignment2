#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE (sizeof(list)/sizeof(*list))
int list[] = {7, 12, 19, 3, 18, 4, 2, -5, 6, 15, 8};
int result[SIZE] = {0};
int counter = 0;

int compare(const void* a, const void* b) {
  return(*(int*)a - *(int*)b);
}
void* Sorting(int x[],int size){
 
   qsort(x, size, sizeof(int), compare);
   

   return NULL;
	}

void* merge(int sorted[], int final[]){
	for (int i = 0; i < 5; i++){
		result[counter] = sorted[i];
		counter++;
		}
	}
	
	
int main(){
  int left[5];
  int right[5];
  for (int i = 0; i < SIZE/2; i++){
	  left[i] = list[i];
	  }
  for (int i = 0; i < SIZE/2; i++){
	  right[i] = list[i+5];
	  }
	 pthread_t tid;
     pthread_create(&tid, NULL, Sorting(left,5),NULL);
     pthread_create(&tid, NULL, Sorting(right,5),NULL);
     pthread_create(&tid, NULL, merge(left,result),NULL);
     pthread_create(&tid, NULL, merge(right,result),NULL);
     pthread_exit(NULL);	  
	printf("\n");
	for (int i = 0; i < 10; i++){
	printf("%d ",result[i]);
}
return 0;
}
