#include <iostream>
#include <string>
using namespace std;
int alphaNum[13] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
string alpha[13] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };

int stringToNum(string str) {
	int answer = 0;
	bool Ok = false;
	int strSize = str.size();
	for (int i = 0; i < strSize; i++) {
		Ok = false;
		if (i < strSize - 1) {
			string Two = "";
			Two = Two + str[i] + str[i + 1];
			for (int j = 0; j < 13; j++) {
				if (Two == alpha[j]) {
					answer += alphaNum[j];
					i++;
					Ok = true;
					break;
				}
			}
		}
		if (!Ok) {
			string One = "";
			One += str[i];
			for (int j = 0; j < 13; j++) {
				if (One == alpha[j]) {
					answer += alphaNum[j];
					Ok = true;
					break;
				}
			}
		}
	}
	return answer;
}

string makeString(int Sum) {
	string str = "";
	for (int i = 12; i >= 0; i--) {
		if (Sum >= alphaNum[i]) {
			int divided = Sum / alphaNum[i];
			Sum -= (divided * alphaNum[i]);
			while (divided--) {
				str += alpha[i];
			}
		}
	}
	return str;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	string str2;
	cin >> str2;
	int a = stringToNum(str);
	int b = stringToNum(str2);
	a = a + b;
	cout << a << '\n';
	cout << makeString(a) << '\n';
}