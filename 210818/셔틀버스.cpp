#include <bits/stdc++.h>

using namespace std;
string change(int time){
    string ans="";
    int h=time/60;
    int m=time%60;
    
    if(h<10) ans+="0";
    ans+=to_string(h);
    ans+=":";
    if(m<10) ans+="0";
    ans+=to_string(m);
    
    return ans;    
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    sort(timetable.begin(), timetable.end());
    
    vector<int> candi;
    
    for(int i=0;i<n-1;i++){
        int cur_time=60*9+(t*i);
        int cnt=0;
        
        while(!timetable.empty() && cnt!= m){
            int cus_time=stoi(timetable[0].substr(0,2))*60+stoi(timetable[0].substr(3,2));
            if(cus_time<=cur_time){
                timetable.erase(timetable.begin());
                cnt++;
            }
            else break;
        }
        
    }
    
    int cur_time=60*9+(t*(n-1));
    int cnt=0;
  
    while(!timetable.empty()){
        if(cnt==m) break;
        int cus_time=stoi(timetable[0].substr(0,2))*60+stoi(timetable[0].substr(3,2));
        if(cus_time<=cur_time){
                candi.push_back(cus_time);
                timetable.erase(timetable.begin());
                cnt++;
            }
            else break;
    }
    
    int ans_time=0;
    
    if(candi.size()<m) ans_time=60*9+t*(n-1);
    else ans_time=candi.back()-1;

    
    return change(ans_time);
}
