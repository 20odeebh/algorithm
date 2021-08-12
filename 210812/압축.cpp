#include <bits/stdc++.h>

using namespace std;
map<string,int> m;

vector<int> solution(string msg) {
    vector<int> answer;
    
     for(int i=1;i<=26;i++){
        string temp;
        temp+='A'+i-1;
        m[temp]=i;
    }
    
    int idx=27;
    for(int i=0;i<msg.size();i++){
        string temp;
        temp+=msg[i];
        
        int next=i;
        while(m.find(temp)!=m.end()){
            temp+=msg[++next];          
        }
        
        i=next-1; 
        temp.pop_back();
        answer.push_back(m[temp]);
               
        if(i!=msg.size()-1) m[temp+msg[i+1]]=idx++;
           
    }
    return answer;
}
