#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str, boom;
	cin >> str >> boom;
	int strSize = str.size();
	int boomSize = boom.size();
	vector<char> st;
	for (int i = 0; i < str.size(); i++) {
		char tmp = str[i];
		st.push_back(tmp);
		if (st[st.size()-1] == boom[boomSize - 1]) {
			bool Ok = false;
			if (st.size() < boomSize)Ok = true;
			else {
				for (int i = 0; i < boomSize;i++) {
					char sta=st[st.size()-1-i];
					char boo = boom[boomSize-1-i];
					if (sta != boo) {
						Ok = true;
						break;
					}
				}
				if (!Ok) {
					int tmpBoomSize = boomSize;
					while (tmpBoomSize--) {
						st.pop_back();
					}
				}
			}


		}
	}
	if (st.size() == 0) {
		cout << "FRULA" << '\n';
	}
	else {
		for (auto i : st) {
			cout << i;
		}
	}
	
}#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str, boom;
	cin >> str >> boom;
	int strSize = str.size();
	int boomSize = boom.size();
	vector<char> st;
	for (int i = 0; i < str.size(); i++) {
		char tmp = str[i];
		st.push_back(tmp);
		if (st[st.size()-1] == boom[boomSize - 1]) {
			bool Ok = false;
			if (st.size() < boomSize)Ok = true;
			else {
				for (int i = 0; i < boomSize;i++) {
					char sta=st[st.size()-1-i];
					char boo = boom[boomSize-1-i];
					if (sta != boo) {
						Ok = true;
						break;
					}
				}
				if (!Ok) {
					int tmpBoomSize = boomSize;
					while (tmpBoomSize--) {
						st.pop_back();
					}
				}
			}


		}
	}
	if (st.size() == 0) {
		cout << "FRULA" << '\n';
	}
	else {
		for (auto i : st) {
			cout << i;
		}
	}
	
}