#include <bits/stdc++.h>

using namespace std;

int get_len(string s1, string s2){
    int h1=stoi(s1.substr(0,2));
    int m1=stoi(s1.substr(3,2));
    int h2=stoi(s2.substr(0,2));
    int m2=stoi(s2.substr(3,2));
    
    if(m1>m2){
        h2-=1;
        m2+=60;
    }
    return 60*(h2-h1)+(m2-m1);
}

string solution(string m, vector<string> musicinfos) {
    int size=0;
    string answer ="(None)";
  
    for(int i=0;i<musicinfos.size();i++){        
        string time1 = musicinfos[i].substr(0,5);
        string time2 = musicinfos[i].substr(6,5);
        
        int pos=0,cnt=0;
        for(int j=12;j<musicinfos[i].size();j++){
            if(musicinfos[i][j]==','){
                pos=j;
                break;
            }
            else cnt++;
        }
      
        string song=musicinfos[i].substr(12,cnt);
        string code=musicinfos[i].substr(pos+1);
        
       int len=get_len(time1,time2);
        
        string change = "";
        int idx=0;
        while(change.size()!=len){
            if(code[idx+1]=='#'){
                change+=tolower(code[idx]);
                idx++;
            }
            else change+=code[idx];
            idx=(idx+1)%code.size();
        }
        
        string m_change="";
        for(int j=0;j<m.size()-1;j++){
            if(m[j+1]=='#'){
                m_change+=tolower(m[j]);
                j++;
            }
            else m_change+=m[j];
        }
      
       if(m.back()!='#') m_change+=m.back();
        
        if(change.find(m_change)!=string::npos&&size<len){
            size=len;
            answer=song;
        }        
    }   
    return answer;
}
