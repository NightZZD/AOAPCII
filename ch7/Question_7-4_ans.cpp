#include<bits/stdc++.h>
using namespace std;

int is_prime(int x) {
  for(int i = 2; i*i <= x; i++)
    if(x % i == 0) return 0;
  return 1;
}

int n, A[16], isprime[32], vis[16];
void dfs(int cur) {
  if(cur == n && isprime[A[0]+A[n-1]]) {
    for(int i = 0; i < n; i++) {
      if(i != 0) printf(" ");
      printf("%d", A[i]);
    }
    printf("\n");
  }
  else for(int i = 2; i <= n; i++){
    int current = i;
    if(!vis[i] && isprime[A[cur-1]+current]) {
      A[cur] = i;
      vis[i] = 1;
      dfs(cur+1);
      vis[i] = 0;
    }
  }
    
}

int main() {
  int caseNum = 0;
  for(int i = 2; i <= 31; i++) isprime[i] = is_prime(i);
  while(scanf("%d", &n) == 1 && n > 0) {
    if(caseNum > 0) printf("\n");
    printf("Case %d:\n", ++caseNum);
    memset(vis, 0, sizeof(vis));
    A[0] = 1;
    dfs(1);
  }
  return 0;
}