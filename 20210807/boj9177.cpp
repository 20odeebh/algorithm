#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string str1, str2, str3;
int n1, n2, n3;
int cache[205][205];

int go(int index, int index2, int index3) {
	if (index == n1) {
		return 1;
	}
	int& ret = cache[index2][index3];
	if (ret != -1)return ret;
	ret = 0;
	if (str1[index] == str2[index2]) {
		if (go(index + 1, index2 + 1, index3) == 1)return ret = 1;
	}
	if (str1[index] == str3[index3]) {
		if (go(index + 1, index2, index3 + 1) == 1)return ret = 1;
	}
	return ret;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str2 >> str3 >> str1;
		n1 = str1.size();
		n2 = str2.size();
		n3 = str3.size();
		memset(cache, -1, sizeof(cache));
		cout << "Data set " << i + 1 << ": ";
		if (go(0, 0, 0) == 1) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}
}