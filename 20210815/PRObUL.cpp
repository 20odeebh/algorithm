#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;
int userN;
int banN;
int answer = 0;
bool visited[9];

unordered_map<int, int> um;
vector<string> user;
vector<string> ban;
bool Check(string str, string str1) {
    if (str.size() != str1.size())return false;
    for (int i = 0; i < str.size(); i++) {
        if (str1[i] == '*')continue;
        if (str[i] != str1[i])return false;
    }
    return true;
}
void go(int index, int cnt, int now) {
    if (cnt == banN) {
        if (um.count(now) > 0) {
            return;
        }
        else {
            answer++;
            um.insert({ now,0 });
        }
        return;
    }
    if (index == userN)return;
    for (int i = 0; i < banN; i++) {
        if (!Check(user[index], ban[i]))continue;
        if (visited[i])continue;
        visited[i] = true;
        go(index + 1, cnt + 1, now + (1 << index));
        visited[i] = false;
    }
    go(index + 1, cnt, now);
}

int solution(vector<string> user_id, vector<string> banned_id) {
    userN = user_id.size();
    banN = banned_id.size();
    user = user_id;
    ban = banned_id;
    go(0, 0, 0);
    return answer;
}