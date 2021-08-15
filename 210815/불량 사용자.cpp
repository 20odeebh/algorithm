#include <bits/stdc++.h>

using namespace std;
int n,m;
bool selected[8];
string arr[8];
set<string> s;

void go(int cnt,string a[],vector<string> user_id, vector<string> banned_id){
    if(cnt==m){
        bool flag=true;
        
        for(int i=0;i<m;i++){
            if(a[i].size()!=banned_id[i].size()){
                flag=false;
                break;
            }
            
            
            for(int j=0;j<banned_id[i].size();j++){
                    if(banned_id[i][j]=='*') continue;
                    if(banned_id[i][j]!=a[i][j]){
                        flag=false;
                        break; 
                }
            }
            if(!flag)break;   
                                   
        }
        if(flag){
                    vector<string> v;
                    for(int i=0;i<m;i++){
                        v.push_back(a[i]);
                    }
                    sort(v.begin(),v.end());
                    string temp="";
                    for(auto a:v){
                        temp+=a;
                    }
                    s.insert(temp);
        }
        return;
    }
    
    for(int i=0;i<n;i++){
        if(selected[i]) continue;
        a[cnt]=user_id[i];
        selected[i]=true;
        go(cnt+1,a,user_id,banned_id);
        selected[i]=false;
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    n=user_id.size();
    m=banned_id.size();
    
    go(0,arr,user_id,banned_id);
    
    return s.size();
}
