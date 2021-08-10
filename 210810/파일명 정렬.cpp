//1시간 5분

#include <bits/stdc++.h>

using namespace std;

struct INFO{
    string head,tail,file_name;
    int number, order;
    
    bool operator<(const INFO& a){
        if(head==a.head){
            if(number==a.number){
                return order<a.order;
            }
            return number<a.number;
        }
        return head<a.head;
    }
};

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<INFO> v;
    for(int i=0;i<files.size();i++){
        int num_start=-1;
        for(int j=0;j<files[i].size();j++){
            
            if(files[i][j]>='0'&&files[i][j]<='9'){
                num_start=j;
                break;
            }
        }
        
        string head=files[i].substr(0,num_start);
        for(int j=0;j<head.size();j++){
            if(head[j]>='A'&&head[j]<='Z') head[j]+='a'-'A';
        }
        
        int cnt=0;
        for(int j=num_start;j<files[i].size();j++){
            if(!(files[i][j]>='0'&&files[i][j]<='9')){
                break;
            }
            else cnt++;
        }
        string temp=files[i].substr(num_start,cnt);
        int number=stoi(temp);
        
        string tail=files[i].substr(num_start+cnt);
        v.push_back({head,tail,files[i],number,i});
    }
    sort(v.begin(),v.end());
    for(auto a:v){
        answer.push_back(a.file_name);
    }
    return answer;
}
