#include <bits/stdc++.h>

using namespace std;

int count_bit(int a){
    int cnt=0;
    
    while(a){
        if(a&1) cnt++;
        a=a>>1;
    }
    return cnt;
}

bool check(vector<vector<string>> relation, int rowsize, int colsize, int i){
    for(int a=0;a<rowsize-1;a++){        
        for(int b=a+1;b<rowsize;b++){
            bool flag=true;    
            
            for(int c=0;c<colsize;c++){
                if((i&(1<<c))==0)continue;
                
                if(relation[a][c] != relation[b][c]){
                    flag=false;
                    break;
                }
            }
            if(flag) return false;
        }
    }
    return true;
}

bool comp(int a,int b){
    int a1=count_bit(a);
    int b1=count_bit(b);
    return a1>b1;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int rowsize= relation.size();
    int colsize= relation[0].size();
    
    vector<int> candi;
    
    for(int i=0;i<(1<<colsize);i++){
        if(check(relation,rowsize,colsize,i)){
            candi.push_back(i);
        }
    }
    
    sort(candi.begin(),candi.end(),comp);
    
    int cnt=0;
    while(!candi.empty()){
        int n=candi.back();
        candi.pop_back();
        cnt++;
        
        for(vector<int>::iterator it=candi.begin();it!=candi.end();){
            if((n&(*it))==n) it=candi.erase(it);
            else it++;
        }
        
    }
    return cnt;
}
