#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;

struct INFO {
	string str;
	int size;

	bool operator<(const INFO& a)const {
		return size < a.size;
	}
};

vector<INFO> v;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;
		v.push_back({ t,(int)t.size() });
	}

	sort(v.begin(), v.end());

	int no_case = 0;
	for (int i = 0; i < n - 1; i++) {
		bool flag = false;
		for (int j = i+1; j < n; j++) {
			if (v[j].str.find(v[i].str) ==0) {
				flag = true;
				break;
			}
		}
		if (flag)no_case++;
	}
	cout << n - no_case;
	
}
