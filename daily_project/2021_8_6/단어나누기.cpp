#include<iostream>
#include<string.h>
#include <assert.h>  

using namespace std;

string reverse(string s) {
    string reversed = "";
    int length = s.length();
    for(int i = length - 1; i >= 0; i--)  {
        reversed += s[i];
    }

    return reversed;
}

int main() {

   
        string word;
        cin >> word;
        string answer = "";

        int length = word.length();
        
        for(int firstLength = 1; firstLength <= length - 2; firstLength++) {
            for(int secondLength = 1; secondLength <= length - firstLength - 1; secondLength++) {
                int thirdLength = length - (firstLength + secondLength);

                string firstWord = reverse(word.substr(0, firstLength));
                string secondWord = reverse(word.substr(firstLength, secondLength));
                string thirdWord = reverse(word.substr(firstLength + secondLength, thirdLength));
                // 왠만하면 길이 제한 두기
                assert(firstWord.length() + secondWord.length() + thirdWord.length() == length);
                string totalWord = firstWord + secondWord + thirdWord;

                if(answer == "") {
                    answer = totalWord;
                } else if(totalWord < answer) {
                    answer = totalWord;
                }

            }
        }

        cout << answer << endl;
    
    return 0;
}