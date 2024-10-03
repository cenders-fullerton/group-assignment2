#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int list[] = {7,12,19,3,18,4,2,6,15,8};

int Compare(const void* a, const void* b) {
  return(*(int*)a - *(int*)b);
}

int* Sorting(int x[10]){
  //sleep(1);
  int n = 5 / sizeof(x[0]);
  
  qsort(x,n,sizeof(int),Compare);
  
  return x;
}

int main() {

  Sorting(list);
  int z = sizeof(list);
  for (int i = 0; i < z; i++){
    printf("%d",list[i]);
  }
  return 0;
}
