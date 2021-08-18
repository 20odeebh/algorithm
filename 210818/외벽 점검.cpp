//https://yjyoon-dev.github.io/kakao/2021/01/04/kakao-wallcheck/참고

#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 987654321;
    
    int w_size=weak.size();
    
    weak.resize(2*w_size);
    
    for(int i=w_size;i<weak.size();i++){
        weak[i]=weak[i-w_size]+n;
    }
    
    
    sort(dist.begin(),dist.end());
    
    do{
        for(int i=0;i<w_size;i++){
            int start=weak[i];
            int end=weak[i+w_size-1];
          
            for(int j=0;j<dist.size();j++){
                start+=dist[j];
              
                if(start>=end) {
                    answer=min(answer,j+1);
                    break;
                }
              
                int idx = upper_bound(weak.begin(),weak.end(),start)-weak.begin();
                start=weak[idx];
            }          
        }    
    }while(next_permutation(dist.begin(),dist.end()));
    
    if(answer==987654321) return -1;
    return answer;
}
