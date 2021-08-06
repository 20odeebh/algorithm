#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;
unordered_map<string, int> frequencyOfWord;

bool cmp(string a, string b) {
    if(frequencyOfWord[a] == frequencyOfWord[b]) {
        if(a.length() == b.length()) {
            if(a == b) {
                return true;
            } else{
                return a < b;
            }
        } else{
            return a.length() > b.length();
        }
    } else{
        return frequencyOfWord[a] > frequencyOfWord[b];
    }
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int wordNum;
    int minimumLength;
    

    cin >> wordNum >> minimumLength;
    vector<string> dictionary;
  

    string word;

    for(int i = 0; i < wordNum; i++) {
        
        cin >> word;
        if(word.length() >= minimumLength) {
          
            if(frequencyOfWord.find(word) == frequencyOfWord.end()) {
                frequencyOfWord[word] = 1;
                 dictionary.push_back(word);
            } else{
                frequencyOfWord[word] += 1;
            }

        }
    }
    sort(dictionary.begin(), dictionary.end(), cmp);

    for(auto p: dictionary) {
        cout << (p) << "\n";
    }

    return 0;
}