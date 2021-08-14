#include <string>
#include <vector>

using namespace std;

bool selected[50];
int rs=987654321,n;

int check(string a,string b){
    int cnt=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i]) cnt++;
    }
    return cnt;
}

void go(string begin,string target,int cnt,string temp,vector<string> words){
    if(temp==target){
        if(rs>cnt)rs=cnt;
        return;
    }
    
    if(cnt == n) return;
    
    for(int i=0;i<n;i++){
        if(selected[i]) continue;
      
        if(check(temp,words[i])==1){
            selected[i]=true;
            go(begin,target,cnt+1,words[i],words);
            selected[i]=false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    n=words.size();
    go(begin,target,0,begin,words);
    if(rs==987654321) rs=0;
    return rs;
}
