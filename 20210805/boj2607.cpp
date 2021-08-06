#include <iostream>
#include <string>
using namespace std;
int firstStr[26];
int tmpStr[26];
int extStr[26];
void setString(string inStr) {
	for (int k = 0; k < 26; k++) {
		tmpStr[k] = 0;
	}
	for (int i = 0; i < inStr.size(); i++) {
		int tmp = inStr[i] - 'A';
		tmpStr[tmp]++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string str;
	cin >> str;
	int strSize = str.size();
	for (int i = 0; i < strSize; i++) {
		int tmp = str[i] - 'A';
		firstStr[tmp]++;
	}
	int ans = 0;

	for (int i = 0; i < n - 1; i++) {
		string now;
		cin >> now;
		int nowSize = now.size();
		setString(now);
		int cnt = 0;
		for (int j = 0; j < 26; j++) {
			if (firstStr[j] > 0 && tmpStr[j] > 0)cnt += ((firstStr[j] > tmpStr[j]) ? tmpStr[j] : firstStr[j]);
		}
		int bigSize = (nowSize > strSize) ? nowSize : strSize;
		cnt = bigSize - cnt;

		if (nowSize - 1 == strSize) {
			if (cnt == 1) {
				ans++;
			}
		}
		if (nowSize + 1 == strSize) {
			if (cnt == 1) {
				ans++;
			}
		}
		if (nowSize == strSize) {
			if (cnt == 0)ans++;
		}
		//if (cnt==0&&(strSize==nowSize)) {
		//	int cnt2 = 0;
		//	for (int k = 0; k < strSize; k++) {
		//		if (now[k] != str[k])cnt2++;
		//	}
		//	if (cnt2 == 2)ans++;f
		//	continue;
		//}
		if (strSize == nowSize && cnt == 1) {
			ans++;
		}
	}
	cout << ans << '\n';
}