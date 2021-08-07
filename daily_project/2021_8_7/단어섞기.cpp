#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string result, first, second;
int resultLength;
int dp[205][205];

int findWord(int resultIndex, int firstWordIndex, int secondWordIndex) {
	if (resultIndex == resultLength) {
		return 1;
	}
	
	int & value = dp[firstWordIndex][secondWordIndex];
    if(value != -1) {
        return value;
    }


	if (result[resultIndex] == first[firstWordIndex]) {
		if (findWord(resultIndex + 1, firstWordIndex + 1, secondWordIndex) == 1) {
            return value = 1;
        }
	}
	if (result[resultIndex] == second[secondWordIndex]) {
		if (findWord(resultIndex + 1, firstWordIndex, secondWordIndex + 1) == 1){
            return value = 1;
        }
	}
	return 0;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> first >> second >> result;
		resultLength = result.size();
        memset(dp, -1, sizeof(dp));

		cout << "Data set " << i + 1 << ": ";
		if (findWord(0, 0, 0) == 1) {
			cout << "yes" << '\n';
		}
		else {
			cout << "no" << '\n';
		}
	}
}