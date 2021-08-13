#include <bits/stdc++.h>

using namespace std;
deque<string> dq;
set<string> s;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    for(int i=0;i<cities.size();i++){
        for(int j=0;j<cities[i].size();j++){
            cities[i][j]=tolower(cities[i][j]);
        }
      
        if(cacheSize==0) return cities.size()*5;
        
        if(s.find(cities[i])!=s.end()){
            answer+=1;
            for(int j=0;j<dq.size();j++){
                if(dq[j]==cities[i]){
                    string temp=dq[j];
                    dq.erase(dq.begin()+j);
                    dq.push_back(temp);
                    break;
                }
            }
        }
        
        else{
            answer+=5;
                    
            if(dq.size()==cacheSize){
                string temp=dq[0];
                dq.pop_front();
                s.erase(temp);
            }
            dq.push_back(cities[i]);
            s.insert(cities[i]);
        }              
    }    
    return answer;
}
