#include<iostream>
#include<unordered_map>

using namespace std;

int luckyNum = 0;
string target;
bool visited[10] = {0,};

bool isLucky(string s) {
    for(int i = 0; i < s.length() - 1; i++) {
        if(s[i] == s[i + 1]){
            return false;
        }
    }
    return true;
}

void combination(int curLength, int totalLength, string cur, bool * visited) {
    if(curLength == totalLength) {
        if(isLucky(cur)) {
            luckyNum += 1;
        }
    } else {
        for(int i = 0; i < totalLength; i++) {
            if(visited[i] == false) {
                if(cur[curLength - 1] == target[i]) {
                    continue;
                }
                visited[i] = true;
                combination(curLength + 1, totalLength, cur + target[i], visited);
                visited[i] = false;
            } else{
                continue;
            }
        }
    }
}

int factorial(int n) {
    int result = 1;
    for(int i = 1; i <= n; i++) {
        result = result * i;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0);
    unordered_map<char, int> frequency;
    cin >> target;
    bool isAllDifferent = true;

    for(int i = 0; i < target.length(); i++)  {
        if(frequency.find(target[i]) == frequency.end()) {
            frequency[target[i]] = 1;
        } else{
            frequency[target[i]] += 1;
            isAllDifferent = false;
        }
    }

   if(isAllDifferent) {
       luckyNum = factorial(target.length());
   } else{
     

        combination(0, target.length(), "", visited);

        for(auto p: frequency) {
            luckyNum = luckyNum / factorial(p.second);
        }

   }
    cout << luckyNum <<  endl;
    return 0;
}