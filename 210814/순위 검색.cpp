#include <bits/stdc++.h>

using namespace std;

map<string,int> m;
vector<int> v[4][3][3][3];

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    m["-"]=0;
    m["cpp"]=1;
    m["java"]=2;
    m["python"]=3;    
    m["backend"]=1;
    m["frontend"]=2;    
    m["junior"]=1;
    m["senior"]=2;    
    m["chicken"]=1;
    m["pizza"]=2;
    
    for(int i=0;i<info.size();i++){
        stringstream s(info[i]);
        string a,b,c,d;
        int e;        
        s>>a>>b>>c>>d>>e;
        
        int idx[4]={m[a],m[b],m[c],m[d]};
        
        for(int j=0;j<(1<<4);j++){            
            int arr[4]={0,};
            
            for(int k=0;k<4;k++){
                if(j&(1<<k)) arr[k]=idx[k];
            }
            
            v[arr[0]][arr[1]][arr[2]][arr[3]].push_back(e);                        
        }        
    }
    
    for(int a=0;a<4;a++){
        for(int b=0;b<3;b++){
            for(int c=0;c<3;c++){
                for(int d=0;d<3;d++){
                    sort(v[a][b][c][d].begin(),v[a][b][c][d].end());
                }
            }
        }
    }
    
    for(auto i:query){
        stringstream s(i);
        string a,b,c,d,e;
        int f;        
        s>>a>>e>>b>>e>>c>>e>>d>>f;
        
        vector<int> temp=v[m[a]][m[b]][m[c]][m[d]];
        auto it=lower_bound(temp.begin(),temp.end(),f);
        answer.push_back(temp.end()-it);
        
    }
    return answer;
}
