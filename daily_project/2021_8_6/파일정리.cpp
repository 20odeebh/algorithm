#include<iostream>
#include<string.h>
#include<map>

using namespace std;

int main() {
    int fileNum;
    cin >> fileNum;
    map<string, int> extensionToFileNum;

    for(int i = 0; i < fileNum; i++) {
        string fileName;
        cin >> fileName;
        int dot = fileName.find(".");
        string extension = fileName.substr(dot + 1);
        if(extensionToFileNum.find(extension) == extensionToFileNum.end()) {
            extensionToFileNum[extension] = 1;
        } else{
            extensionToFileNum[extension] += 1;
        }
    }
    for(auto p: extensionToFileNum) {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}