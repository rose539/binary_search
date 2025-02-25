#include <stdio.h>

int n;
int k;
int A[100000];

//各成分を推定値で割ったときの切り捨ての値を足す
int p(int m){
  int sum = 0;
  for(int j = 0; j < n; j++){
    if(m != 0) sum += A[j] / m;
    else sum = k + 1;
  }
  return (long long int) sum < k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 100000001;
  while(ub - lb > 1){
    int mid = (ub + lb) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", lb);
  return 0;
}
