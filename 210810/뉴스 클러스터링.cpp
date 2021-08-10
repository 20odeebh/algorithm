//51분
#include <bits/stdc++.h>

using namespace std;
bool check[10000];

int solution(string str1, string str2) {
    int answer = 0;    
    vector<string> a,b;
    
    for(int i=0;i<str1.size();i++){
        bool flag=true;
        string temp="";
        for(int j=0;j<=1;j++){
            if(str1[i+j]>='A'&&str1[i+j]<='Z'){
                str1[i+j]+=('a'-'A');
                temp+=str1[i+j];
            }
          
            else if(str1[i+j]>='a'&&str1[i+j]<='z'){  
                temp+=str1[i+j];
            }
          
            else{
               flag=false;
                break;
            }
        }
        if(flag) a.push_back(temp);       
    }
    
    for(int i=0;i<str2.size();i++){
        bool flag=true;
        string temp="";
      
        for(int j=0;j<=1;j++){
            if(str2[i+j]>='A'&&str2[i+j]<='Z'){
                str2[i+j]+=('a'-'A');
                temp+=str2[i+j];
            }
          
            else if(str2[i+j]>='a'&&str2[i+j]<='z'){  
                temp+=str2[i+j];
            }
          
            else{
               flag=false;
                break;
            }
        }
        if(flag) b.push_back(temp);
    }    
    if(a.size()+b.size()==0) return 65536;
    
    int cnt=0;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            if(!check[j]&&a[i]==b[j]){
                cnt++;
                check[j]=true;
                break;
            }
        }
    }
    
    int all_case=a.size()+b.size()-cnt;
    double avg =(double)cnt/all_case;    
    answer=avg*65536;
    return answer;
}
