#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE (sizeof(list)/sizeof(*list))
int list[10] = {7,12,19,3,18,4,2,6,15,8};
int result[SIZE] = {0};

int compare(const void* a, const void* b) {
  return(*(int*)a - *(int*)b);
}

int main() {
  int n = sizeof(list)/sizeof(list[0]);
 
  qsort(list, n, sizeof(int), compare);
 
  for (int i = 0; i < n; i++){
    printf("%d",list[i]);
  }
  return 0;
}
