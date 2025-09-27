#include <bits/stdc++.h>
using namespace std;

int n, L, cnt;
string ans;

bool isHard(const string &s) {
    int len = s.size();
    for (int k = 1; k * 2 <= len; k++) { // 检查长度从1到len//2的所有尾串，都不能有相同的两个串。
        string left = s.substr(len-2*k,k); // 倒数第一字符是len-1，倒数第二个字符是len-2，..., 从倒数第 2k 个字符开始，取长度 k。
        string right = s.substr(len-k,k);
        if (left == right) return false;
    }
    return true;
}

bool isHard_enumerate(const string &s) {
    int len = s.size();
    for (int k = 1; k <= len / 2; k++) {
        bool same = true;
        for (int j = 0; j < k; j++) { // j为比较的偏移量
            if (s[len - 2*k + j] != s[len - k + j]) { // s[len - 2*k ... len - k - 1]  ==  s[len - k ... len - 1]
                same = false;
                break;
            }
        }
        if (same) return false; // 出现连续重复子串
    }
    return true;
}

bool dfs(string &cur) {
    if (cnt++ == n) {
        ans = cur;
        return true;
    }
    for (int i = 0; i < L; i++) {
        cur.push_back('A' + i);
        if (isHard(cur)) {
            if (dfs(cur)) return true;
        }
        cur.pop_back();
    }
    return false;
}

bool dfs(string& cur){
    cnt += 1; // 空串第一次进入就算 1 个（所以通常从空串外层调用）。适合把根节点（空串）也计入计数的场景。
    if(cnt == n){
        ans = cur;
        return true;
    }
    for(int i=0;i<L;i++){
        cur.push_back('A'+i);
        if(isHard(cur)){
            if (dfs(cur)) return true;
        }
        cur.pop_back();
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> L) {
        if (n == 0 && L == 0) break;
        cnt = 0;
        ans.clear(); //多组用例，清空答案字符串
        string cur = ""; // 当前构造的字符串
        dfs(cur);

        // 输出格式化
        int len = ans.size();
        for (int i = 0; i < len; i++) {
            if (i > 0) {
                if (i % 64 == 0) cout << "\n";
                else if (i % 4 == 0) cout << " ";
            }
            cout << ans[i];
        }
        cout << "\n" << len << "\n";
    }
    return 0;
}
