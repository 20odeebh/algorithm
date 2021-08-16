//https://yjyoon-dev.github.io/kakao/2021/07/24/kakao-tableedit/참고
#include <bits/stdc++.h>

using namespace std;
set<int> table;
stack<int> stk;

string solution(int n, int k, vector<string> cmd) {
    
    string answer(n,'X');
    
    for(int i=0;i<n;i++){
        table.insert(i);
    }
    
    auto cur=table.find(k);
    
    for(int i=0;i<cmd.size();i++){
        if(cmd[i][0]=='U'||cmd[i][0]=='D'){
            int num=stoi(cmd[i].substr(2));
            if(cmd[i][0]=='U'){
                while(num--){
                    cur= prev(cur);
                }
            }
            else{
                while(num--){
                    cur= next(cur);
                }
            }
        }
        else if(cmd[i][0]=='C'){
            stk.push(*cur);
            cur=table.erase(cur);
            if(cur==table.end()) cur=prev(cur);
        }
        else if(cmd[i][0]=='Z'){
            table.insert(stk.top());
            stk.pop();
        }
        else ;
        
    }
     for(int a:table)  answer[a]='O';
    return answer;
}
