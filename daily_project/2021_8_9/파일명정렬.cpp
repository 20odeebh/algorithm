#include <cstring>
#include <string.h>
#include <vector>
#include <regex>
#include <iostream>
#include <sstream>
#include<stdio.h>

using namespace std;

bool compare(string a, string b) {
    regex head ("[^0-9]{1,}");
    std::smatch matchA;
    std::smatch matchB;
    
    regex_search(a, matchA, head);
    regex_search(b, matchB, head);
    
    string head_a = matchA.str(0);
    string head_b = matchB.str(0);
    string headA, headB;
    
    for(int i = 0; i < head_a.length(); i++) {
        headA += tolower(head_a[i]);
    }
    
    for(int i = 0; i < head_b.length(); i++) {
        headB += tolower(head_b[i]);
    }
    

    
    if(headA != headB) {
        return headA < headB;
    }
    
    regex number("[0-9]{1,6}");
    
    std::smatch match1;
    std::smatch match2;
    
    regex_search(a, match1, number);
    regex_search(b, match2, number);
    string numberA, numberB;
    
     string match_1 = match1.str(0);
    string match_2 = match2.str(0);
    

    
    stringstream ss;
    int number_a;
    int number_b;
    
    ss << match_1;
    ss >>  number_a;
    
    stringstream ss1;
    ss1 << match_2;
    ss1 >> number_b;
    
    return number_a < number_b;
}
vector<string> solution(vector<string> files) {
    vector<string> answer = files;
    stable_sort(answer.begin(), answer.end(), compare);
    return answer;
}