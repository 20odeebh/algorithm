#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<string> files;

void pro() {
    
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string name;
        cin >> name;
        files.push_back(name);
    }
    pro();
}