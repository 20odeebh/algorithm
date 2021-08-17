#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;    
    vector<int> start,end;
    
    for(int i=0;i<lines.size();i++){        
        lines[i].pop_back();
        string h = lines[i].substr(11,2);
        string m = lines[i].substr(14,2);
        string s = lines[i].substr(17,2);
        string mil = lines[i].substr(20,3);
        int c_h = stoi(h)*60*60*1000;
        int c_m = stoi(m)*60*1000;
        int c_s = stoi(s)*1000 + stoi(mil);
        
        int c_p =stod(lines[i].substr(24,5))*1000;
                
        start.push_back(c_h+c_m+c_s-c_p+1);
        end.push_back(c_h+c_m+c_s);
    }
    
   for(int i=0;i<lines.size();i++){ 
        int end_time=end[i]+1000;
       
       int cnt=0;
        for(int j=i;j<lines.size();j++){
            if(end_time>start[j])cnt++;
        }
       if(cnt>answer)answer=cnt;
   }
    return answer;
}
