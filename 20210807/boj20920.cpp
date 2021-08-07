#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	unordered_map<string, int> um;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		int strSize = str.size();
		if (strSize < m)continue;
		if (um.count(str) == 0) {
			um.insert({ str,1 });
		}
		else {
			um[str]++;
		}
	}
	vector<pair<int, pair<int, string>>> v;
	for (auto i : um) {
		int Size = -(int)i.first.size();
		int cnt = -i.second;
		string tmpStr = i.first;
		v.push_back({ cnt,{Size,tmpStr} });
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		cout << i.second.second << '\n';
	}
}