#include <bits/stdc++.h>

using namespace std;

string change(int num,int n){
    string ans="";
    if(num==0) return "0";
    
    while(num){
        int na=num%n;
        if(na==10) ans='A'+ans;
        else if(na==11) ans='B'+ans;
        else if(na==12) ans='C'+ans;
        else if(na==13) ans='D'+ans;
        else if(na==14) ans='E'+ans;
        else if(na==15) ans='F'+ans;
        else ans=to_string(na)+ans;
        num/=n;
    }
    
    
    return ans;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string temp="";
    for(int i=0;i<m*t;i++){
        temp+=change(i,n);
    }
 
    int start=p-1;
    while(answer.size()!=t){
        answer+=temp[start];
        start+=m;
    }
    return answer;
}#include <bits/stdc++.h>

using namespace std;

string change(int num,int n){
    string ans="";
    if(num==0) return "0";
    
    while(num){
        int na=num%n;
        if(na==10) ans='A'+ans;
        else if(na==11) ans='B'+ans;
        else if(na==12) ans='C'+ans;
        else if(na==13) ans='D'+ans;
        else if(na==14) ans='E'+ans;
        else if(na==15) ans='F'+ans;
        else ans=to_string(na)+ans;
        num/=n;
    }
    
    
    return ans;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string temp="";
    for(int i=0;i<m*t;i++){
        temp+=change(i,n);
    }
 
    int start=p-1;
    while(answer.size()!=t){
        answer+=temp[start];
        start+=m;
    }
    return answer;
}
