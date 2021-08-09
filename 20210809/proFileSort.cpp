#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool isNum(char tmp) {
	return tmp >= '0' && tmp <= '9';
}
bool isUpper(char tmp) {
	return tmp >= 'A' && tmp <= 'Z';
}
vector<pair<string, pair<int, int>>> v;

vector<string> solution(vector<string> files) {
	vector<string> answer;
	for (int i = 0; i < files.size(); i++) {
		string head = "";
		string num = "";
		int intNum;
		bool showNum = false;
		for (int j = 0; j < files[i].size(); j++) {
			if (!showNum && !isNum(files[i][j])) {
				if (isUpper(files[i][j])) {
					head += files[i][j] - 'A' + 'a';
				}
				else {
					head += files[i][j];
				}
			}
			else if (isNum(files[i][j])) {
				showNum = true;
				num += files[i][j];
			}
			else break;
		}
		intNum = atoi(num.c_str());
		v.push_back({ head,{intNum,i} });
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		answer.push_back(files[i.second.second]);
	}
	return answer;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

}