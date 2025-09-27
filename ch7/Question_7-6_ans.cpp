#include<bits/stdc++.h>
using namespace std;

using Graph = std::unordered_map<char, std::set<char>>;

Graph parseGraph(const string& line) {
    Graph g;
    istringstream ss(line);// 构造输入流，为解析做准备
    string record;// 临时保存
    
    while (std::getline(ss, record, ';')) {// record记录组内字符串
        // 找到 ':' 的位置
        int pos = record.find(':');
        if (pos == string::npos) continue;
        
        char node = record[0]; // 如record="A:FB"
        std::string neighbors = record.substr(pos + 1);//提取字符串 = 从':'的下一个字符开始到结尾
        
        // 初始化节点（即使没有邻居也要存在）
        // if (g.find(node) == g.end()) {
        //     g[node] = std::set<char>();
        // }

        g[node]; // 返回引用，不存在则插入默认值
        for (char nb : neighbors) {
            if (nb >= 'A' && nb <= 'Z') { // 题目保证
                g[node].insert(nb);
                // g[nb].insert(node);
                g[nb]; // 返回引用，不存在则插入默认值
            }
        }
    }
    return g;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        if (line == "#") break;
        if (line.empty()) continue;
        
        Graph g = parseGraph(line);
        vector<char> keys;
        vector<char> ans;
        int cur_max;
        int best_bw = 0x3f3f3f3f;
        for(auto&[k,v] : g){
            keys.push_back(k);
        }
        std::sort(keys.begin(),keys.end());
        int pos[26];
        do{
            cur_max = 0;
            // memset(pos,-1,sizeof(pos));
            fill(pos,pos+26,-1);
            for(int i=0;i<keys.size();i++){
                pos[keys[i]-'A'] = i; // 记录位置
            }
            for(auto&[k,v_set] : g){
                for(auto& c : v_set){
                    // maxnum = std::max(maxnum,pos[k]-pos[c-'A']);
                    int d = abs(pos[k-'A']-pos[c-'A']);
                    cur_max = max(cur_max,d);
                }
            }
            if(cur_max<best_bw){
                best_bw = cur_max;
                ans = keys; // 保存最优答案
            }
        }while (next_permutation(keys.begin(),keys.end()));//枚举图中所有节点的排列
        //next_permutation生成当前序列的下一个字典序排列。如果存在下一个排列，它会将其就地修改为下一个排列并返回 true；如果当前已经是最大字典序排列（即降序），则将其重置为最小字典序排列（升序）并返回 false。
        for(auto&c :ans){
            cout<<c<<" ";
        }
        cout<<"-> " <<best_bw<<'\n';
    }
    return 0;
}