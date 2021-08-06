#include<iostream>
#include<string.h>
#include<regex>

using namespace std;

bool isCStyle(string s) {
    bool isSlash = false;
    s[0] = tolower(s[0]);
    for(int i = 0; i < s.length(); i++) {
        if(i == s.length() - 1 && s[i] == '_')  {
            return false;
        }
        if(isSlash == false && s[i] == '_') {
            return false;
        }
        if(isSlash && s[i] == '_') {
            isSlash = false;
            continue;
        } else{
            isSlash = true;
        }

        if(islower(s[i]) == false) {
            return false;
        }

    }
    return true;
}

int main() {
    string target;
    regex java_style ("([A-Z]{1}[a-z]{0,}){1,}");
   
    string converted;
    cin >> target;
    char first = target[0];
    target[0] = toupper(target[0]);
    
 
    if(isupper(first)) {
        cout << "Error!" << endl;
    }
    else if(regex_match(target, java_style)) {
        for(int i = 0; i < target.length(); i++) {
            if(isupper(target[i]) && i != 0) {
                converted += "_"; 
                converted += tolower(target[i]);
            } else{
                converted += tolower(target[i]);
            }          
        }
      
         cout << converted << endl;
    } else if(isCStyle(target)) {
        int i = 0;
        while(i < target.length()) {
            if(target[i] == '_')  {
                converted += toupper(target[i + 1]);
                i += 2;
            } else{
                converted += tolower(target[i]);
                i++;
            }
        }
        cout << converted << endl;
    } else{
        cout << "Error!" << endl;
    }
    
    return 0;
}