#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	string ans = "";
	bool Ok = false;
	bool Java = false;
	bool Clan = false;
	if (str[0] == '_' || str[str.size() - 1] == '_' || (str[0] >= 'A' && str[0] <= 'Z')) {
		cout << "Error!" << '\n';
		exit(0);
	}
	for (int i = 0; i < str.size(); i++) {
		char now = str[i];
		int nowInt = 0;
		if (Ok) {
			if (now == '_') {
				cout << "Error!" << '\n';
				exit(0);
			}
			if (now >= 'A' && now <= 'Z') {
				cout << "Error!" << '\n';
				exit(0);
			}
			ans += (now - 'a' + 'A');
			Ok = false;
			continue;
		}
		if (!Ok && now >= 'A' && now <= 'Z') {
			Java = true;
			nowInt = str[i] - 'A';
			ans += ('_');
			ans += (nowInt + 'a');
		}
		else if (!Ok && now >= 'a' && now <= 'z') {
			nowInt = str[i] - 'a';
			ans += (nowInt + 'a');
		}
		else if (now == '_') {
			Clan = true;
			Ok = true;
			continue;
		}
	}
	if (Java && Clan) {
		cout << "Error!" << '\n';
	}
	else {
		cout << ans << '\n';
	}

}