#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

struct file {
    string name;
    string extension;
    bool perceivedByOs;
    file(string _name, string _extension) : name(_name), extension(_extension){
        
    };
};

vector<file> files;


bool compare(const file & a, const file & b) {
    if(a.name.compare(b.name) == 0) {
        if(a.perceivedByOs && b.perceivedByOs) {
            return a.extension.compare(b.extension) < 0;
        } else if(a.perceivedByOs) {
            return true;
        } else if(b.perceivedByOs) {
            return false;
        } else{
            a.extension.compare(b.extension) < 0;
        }
    } else{
        return a.name.compare(b.name) < 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int fileNum;
    int extensionNum;
    unordered_map<string, bool> extensionToPerceivedStates;
    cin >> fileNum >> extensionNum;

    for(int i = 0; i < fileNum; i++) {
        string temp;
        cin >> temp;
        int index = temp.find(".");
        string name = temp.substr(0, index);
        string extension = temp.substr(index + 1);
        file * f = new file(name, extension);
        f->perceivedByOs = false;
        files.push_back(*f);
        
        extensionToPerceivedStates[extension] = false;
    }

    for(int i = 0; i < extensionNum; i++) {
        string extension;
        cin >> extension;
       
        extensionToPerceivedStates[extension] = true;
      
    }

    for(auto file: files)  {
        file.perceivedByOs = extensionToPerceivedStates[file.extension];
    }
    
    sort(files.begin(), files.end(), compare);

    for(vector<file>::iterator iter = files.begin(); iter != files.end(); iter++) {
        cout << (*iter).name + "." + (*iter).extension << "\n";
    }
    

}




