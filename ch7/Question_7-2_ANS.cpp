#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,caseNum=1;
    while(scanf("%d",&n)==1){
        vector<int> seq(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &seq[i]);  // 用 scanf 读取每个数
        }
        long long maxProduct = 0;
        // 枚举所有子数组
        for (int i = 0; i < n; i++) {
            long long product = 1;
            for (int j = i; j < n; j++) {
                product *= seq[j];
                if (product > 0) {
                    maxProduct = max(maxProduct, product);
                }
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", caseNum, maxProduct);
        caseNum++;
    }
    return 0;
}