#include <bits/stdc++.h>

using namespace std;

bool check(int idx1,int idx2,char op,int limit){
    int cal=abs(idx1-idx2)-1;
    
    if(op=='='){
        if(cal==limit) return true;
        else return false;
    }
    else if(op=='<'){
        if(cal<limit) return true;
        else return false;        
    }
    else{
        if(cal>limit) return true;
        else return false;        
    }
}

int solution(int n, vector<string> data) {
    int answer = 0;
    string v="ACFJMNRT";
   
    do{
        bool flag=true;
        for(int i=0;i<data.size();i++){            
            char a=data[i][0];
            int idx1=v.find(a);
            
            char b=data[i][2];
            int idx2=v.find(b);
            
            int limit=stoi(data[i].substr(4));
            if(!check(idx1,idx2,data[i][3],limit)) {
                flag=false;
                break;
            }          
        }
        
        if(flag) answer++;
      
    }while(next_permutation(v.begin(),v.end()));
    return answer;
}
