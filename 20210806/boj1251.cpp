#include <iostream>
#include <string>
#include <queue>
using namespace std;

string Swap(string str) {
	int n = str.size();
	string tmp = "";
	for (int i = n - 1; i >= 0; i--) {
		tmp += str[i];
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	int n = str.size();
	priority_queue<string, vector<string>, greater<string>> pq;
	for (int i = 1; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			string a = "", b = "", c = "";
			for (int k = 0; k < i; k++) {
				a += str[k];
			}
			for (int k = i; k < j; k++) {
				b += str[k];
			}
			for (int k = j; k < n; k++) {
				c += str[k];
			}
			a = Swap(a);
			b = Swap(b);
			c = Swap(c);
			string now = a + b + c;
			pq.push(now);
		}
	}
	cout << pq.top() << '\n';
}