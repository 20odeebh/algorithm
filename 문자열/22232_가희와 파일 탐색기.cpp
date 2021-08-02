#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

int n, m;
vector<string> files;
vector<string> ext;
set<string> s;
vector<tuple<string, int, string>> v;
void getFileName() {
    for(int i = 0; i < n; i++) {
        int point = files[i].find(".");
        string Extension = files[i].substr(point+1);
        if(s.count(Extension)) {
            v.push_back({files[i].substr(0, point), 1, files[i].substr(point+1)});
        }
        else v.push_back({files[i].substr(0, point), 2, files[i].substr(point+1)});
    }
}

void pro() {
    getFileName();
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        string name, ext;
        tie(name, ignore, ext) = v[i];
        cout << name << "." << ext << "\n";
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string name;
        cin >> name;
        files.push_back(name);
    }
    for(int i = 0; i < m; i++) {
        string extension;
        cin >> extension;
        s.insert(extension);
    }
    pro();
}