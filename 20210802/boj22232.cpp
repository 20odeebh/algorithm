#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
unordered_map<string, int> um;

pair<string, string> getTwo(string a) {
	string fString="", sString="";
	bool Ok = false;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '.') {
			Ok = true;
		}
		else {
			if (Ok) {
				sString += a[i];
			}
			else {
				fString += a[i];
			}
		}
		
	}
	return { fString,sString };
}

bool sorting(pair<string,string> a, pair<string, string> b) {
	string aFirst, aSecond,bFirst,bSecond;
	aFirst = a.first;
	aSecond = a.second;
	bFirst = b.first;
	bSecond = b.second;

	if (aFirst < bFirst)return true;
	if (aFirst > bFirst)return false;
	bool aOk = (um.count(aSecond) > 0) ? true : false;
	bool bOk = (um.count(bSecond) > 0) ? true : false;
	if ((aOk && bOk) || (!aOk && !bOk)) {
		if (aSecond < bSecond)return true;
		return false;
	}
	if (aOk && !bOk)return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<pair<string,string>> v;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		pair<string, string> aa = getTwo(tmp);
		v.push_back({aa.first,aa.second});
	}
	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		um.insert({ tmp,0 });
	}
	sort(v.begin(), v.end(), sorting);
	for (auto i : v) {
		cout << i.first<<'.'<<i.second << '\n';
	}
}