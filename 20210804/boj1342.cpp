#include <iostream>
#include <string>
#include <unordered_map>
#define lli long long int
using namespace std;
string aa;
lli n;
int visited[27];
lli answer = 0;
unordered_map<lli, lli> um;
void go(lli index, lli prev) {
	if (index == n) {
		answer++;
		return;
	}
	for (lli i = 0; i < 26; i++) {
		if (visited[i] == 0)continue;
		visited[i]--;
		if (index != 0 && prev == i) {
			visited[i]++;
			continue;
		}
		go(index + 1, i);
		visited[i]++;

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> aa;
	n = aa.size();
	for (int i = 0; i < aa.size(); i++) {
		int tmp = aa[i] - 'a';
		visited[tmp]++;
	}
	go(0, -1);
	cout << answer << '\n';
}