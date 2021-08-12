#include <string.h>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> wordToIndex;
    
    int nextIndex;
    char alphabet;
    
    for(int i = 65; i <= 90; i++) {
        char alphabet = i;
        wordToIndex[string(1, alphabet)] = i - 64;
    }
    
    nextIndex = 27;
    int size = msg.size();
    int i = 0;
    while(i < size) {
        string word = string(1, msg[i]);

        while(wordToIndex.find(word) != wordToIndex.end()) {
            i += 1;
            word += string(1, msg[i]);   
        }
        
        answer.push_back(wordToIndex[word.substr(0, word.size() - 1)]);
        wordToIndex[word] = nextIndex;
        nextIndex += 1;
    }
  
    return answer;
}