#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

string makeLower(string str) {
    for (int i = 0; i < str.length(); ++i)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = tolower(str[i]);

    return str;
}

vector<string> makeValidPair(string str) {
    vector<string> str_set;

    for (int i = 0; i < str.length() - 1; ) {
        string temp = str.substr(i, 2);
        if (temp[0] >= 'a' && temp[0] <= 'z') {
            if (temp[1] >= 'a' && temp[1] <= 'z') {
                str_set.push_back(temp);
                i++;
            }
            else i += 2;
        }
        else {
            if (temp[1] >= 'a' && temp[1] <= 'z') i++;
            else i += 2;
        }
    }
    return str_set;
}

int solution(string str1, string str2) {
    int answer = 0;
    int intersect_num = 0;   // (교집합의 원소 수)
    int union_num = 0;        // (합집합의 원소 수)
    vector<string> str1Pair;
    vector<string> str2Pair;
    unordered_map<string, int> count;
    str1 = makeLower(str1);
    str2 = makeLower(str2);
    str1Pair = makeValidPair(str1);
    str2Pair = makeValidPair(str2);
  
    for(int i = 0; i < str1Pair.size(); i++) {
        count[str1Pair[i]] += 1;
    }
    
    for(int i = 0; i < str2Pair.size(); i++){
        if (count.find(str2Pair[i]) != count.end()){
            if (count[str2Pair[i]] == 0)
                continue;
            count[str2Pair[i]] -= 1;
            intersect_num += 1;
        }
    }
    

    union_num = str1Pair.size() + str2Pair.size() - intersect_num;
   
    if (union_num == 0) {
        answer = 65536;
    }
    else{
        answer = (int)((float)intersect_num / union_num * 65536);
    }

    return answer;
}
