#include<iostream>
#include<unordered_map>
#include<string.h>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std;

int main() {
    unordered_map<string, int> strToInt;
    int luckyStrNum = 0;
    unordered_map<int, int> frequency;
    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++) {
        if(strToInt.find(string(s[i], 1)) == strToInt.end()) {
            strToInt[string(s[i], 1)] = 1;
        } else{
            strToInt[string(s[i], 1)] += 1;
        }
    }
    for(const auto &p: strToInt) {
        if(frequency.find(p.second) == frequency.end()) {
            frequency[p.second] = 1;
        } else{
            frequency[p.second] += 1;
        }
    }

    map<int, int> ordered(frequency.begin(), frequency.end());
    int prevFrequency = -1;
    vector<int> count;
    int prevCount = 0;

    for(auto it = ordered.begin(); it != ordered.end(); ++it) {

        if(prevFrequency == -1) {
            prevFrequency = it->first;
            prevCount += 1;
            if(it->second >= 2) {
                count.push_back(it->second);
            }
        } else{
            if(prevFrequency == 1 && abs(prevCount - it->first) >= 2) {
                break;
            }
             if(it->second >= 2) {
                count.push_back(it->second);
            }
           
        }
         prevFrequency = it->second;
        prevCount = it->first;
    }

    if(count.empty()) {
        cout << 0  << endl;
    } else{

    }
        
    return 0;
}