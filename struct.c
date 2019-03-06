#include <stdio.h>
#include <math.h>
#include "stdlib.h"
#define N 4

struct circle {
   float x, y, r;
};


int touch(struct circle a, struct circle b){
  int k = 0;
  float dis = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
  if(dis <= a.r + b.r)
    k+=1;

  return k;
}

struct circle arr[N];


int main(){

int k = 0;
struct circle *arr;
arr=(struct circle*)malloc(N*sizeof(struct circle));

for(size_t i = 0; i < N ;i++)
    scanf("%f%f%f",&arr[i].x,&arr[i].y,&arr[i].r);

for(size_t i = 0; i < N-1 ;i++){
    for(size_t j = i + 1; j < N ;j++){
      int temp = touch(arr[i], arr[j]);
      k+=temp;
    }
}

  printf("Count of touching circles is %d\n",k );

  return 0;
}
