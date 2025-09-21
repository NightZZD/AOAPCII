#include<bits/stdc++.h>
using namespace std;

int main() {
    int k;
    while (scanf("%d", &k) == 1) {
        int kk = k * k;
        vector<pair<int, int>> ans;

        for (int i = 1; i <= k; i++) {
            if (kk % i == 0) {
                int y = k + i; //k<=y<=2k
                int x = k + kk / i; // x>=2k
                ans.push_back({x, y});
            }
        }

        printf("%d\n", (int)ans.size());
        for (auto &p : ans) {
            printf("1/%d = 1/%d + 1/%d\n", k, p.first, p.second);
        }
    }
    return 0;
}
