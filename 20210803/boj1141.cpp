#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int ox[51][51];

string arr[51];

int getSet(int i, int j) {
	string strL = arr[i];
	string strR = arr[j];
	int numL = strL.size();
	int numR = strR.size();
	int Small = (numL < numR) ? numL : numR;
	string str1 = "", str2 = "";
	for (int i = 0; i < Small; i++) {
		str1 += strL[i];
		str2 += strR[i];
	}
	if (str1 == str2) {
		return 1;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		arr[i] = str;
	}
	sort(arr, arr + n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		bool ok = false;
		for (int j = i + 1; j < n; j++) {
			if (getSet(i, j) == 1)ok = true;
		}
		if (ok)cnt++;
	}
	cout << n - cnt << '\n';
}