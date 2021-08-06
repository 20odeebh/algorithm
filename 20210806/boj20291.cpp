#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<string, int>> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	unordered_map<string, int> um;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		int tmpSize = tmp.size();
		string fileType = "";
		bool Point = false;
		for (int j = 0; j < tmpSize; j++) {
			if (tmp[j] == '.') {
				Point = true;
				continue;
			}
			if (Point) {
				fileType += tmp[j];
			}
		}
		if (um.count(fileType) == 0) {
			um.insert({ fileType,1 });
		}
		else {
			um[fileType]++;
		}

	}
	vector<pair<string, int>> v;
	for (auto i : um) {
		v.push_back({ i.first,i.second });
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		cout << i.first << ' ' << i.second << '\n';
	}
}