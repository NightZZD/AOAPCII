#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int caseNum = 0;
    auto check = [](int a,int b){
        int cnt[10]={};
        //5位数，取5次
        for(int i=0;i<5;i++)
        {
            cnt[a%10]++;
            a/=10;
            cnt[b%10]++;
            b/=10;
        }
        //检查是否：用且只用了一次
        for(int i=0;i<10;i++)
            if(cnt[i]!=1) return false;
        return true;
    };
    while(scanf("%d", &n) == 1 && n != 0){
        vector<pair<int,int>> ans;
        if (caseNum++) cout<<'\n';
        for(int fjhik=1234;;fjhik++)
        {
            int abcde = n*fjhik;
            if (abcde>98765) break;
            if(check(abcde,fjhik)) ans.push_back({abcde,fjhik});
        }
        if (ans.size()==0)
            cout<<"There are no solutions for "<<n<<".\n";
        else
            for(auto p:ans)
                printf("%05d / %05d = %d\n",p.first,p.second,n);
    }
    return 0;
}