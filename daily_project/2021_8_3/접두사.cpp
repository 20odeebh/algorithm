#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int N;
    cin  >> N;
    vector<string> words;

    for(int i = 0; i < N; i++) {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }

    sort(words.begin(), words.end());
    
    return 0;
}