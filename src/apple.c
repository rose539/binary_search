#include <stdio.h>

int n;
int k;
int A[100000];

//各成分を推定値で割ったときの切り上げの値を足す
int p(int m){
  int sum = 0;
  for(int j = 0; j < n; j++){
    sum += (A[j] + m - 1) / m;
  }
  return (long long int) sum <= k;
}

//ubの値に代入するために配列の最大値を求める
int m(int B[]){
  int max = 0;
  for(int j = 0; j < n; j++){
    if(max <= B[j]) max = B[j];
  }
  return max;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = m(A);
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", ub);
  return 0;
}
