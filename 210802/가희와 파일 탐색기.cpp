//rkdwlss2 풀이 참고!

#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>


using namespace std;

unordered_map<string, int> um;

pair<string, string> get(string a) {
	string fString = "", sString = "";
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

bool comp(pair<string, string> a, pair<string, string> b) {
	string af = a.first;
	string as = a.second;
	string bf = b.first;
	string bs = b.second;

	if (af < bf)return true;
	if (af > bf)return false;
	
	bool a_ok = (um.count(as) > 0) ? true : false;
	bool b_ok = (um.count(bs) > 0) ? true : false;
	
	if ((a_ok && b_ok) || (!a_ok && !b_ok)) {
		if (as < bs)return true;
		return false;
	}
	
	if (a_ok && !b_ok)return true;
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	
	vector<pair<string, string>> v;
	
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		
		pair<string, string> aa = get(tmp);
		v.push_back({ aa.first,aa.second });
	}
	
	for (int i = 0; i < m; i++) {
		string tmp;
		cin >> tmp;
		um.insert({ tmp,0 });
	}
	
	sort(v.begin(), v.end(), comp);
	
	for (auto i : v) {
		cout << i.first << '.' << i.second << '\n';
	}
}
