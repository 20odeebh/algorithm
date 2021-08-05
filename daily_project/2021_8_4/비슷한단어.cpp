#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

bool isSimilar(unordered_map<string, int> target, unordered_map<string, int> compared) {
    unordered_map<string, int> diff;
    unordered_map<string, bool> visited;

    for( const auto& p : compared) {
        if(target.find(p.first) == target.end()) {
            diff[p.first] = - 1 * p.second;
        }
        else if( p.second != target[p.first]) {
            diff[p.first] = target[p.first] - p.second;

        }
        visited[p.first] = true;
    }

    for(const auto & p: target) {
        if(visited.find(p.first) == visited.end()) {
            diff[p.first] = p.second;
        }
    }

    int count = 0;
    int arr[10];
    for(const auto & key: diff) {
        arr[count] = key.second;
        count++;
    }

   

    if(count == 0) {
        return true;
    }
    else if(count >= 3) {
        return false;
    } else if(count == 1) {
        if(arr[0] == 1 || arr[0] == -1) {
            return true;
        }
        return false;
    } else{
        int a = arr[0];
        int b = arr[1];
        if(a * b == -1) {
            return true;
        }
        return false;
    }
}

unordered_map<string, int> convertToMapFrom(string s) {
    unordered_map<string, int> m;

    for(int i = 0; i < s.length(); i++) {
        if(m.find(string(1, s[i])) == m.end()) {
            m[string(1, s[i])] = 1;
        } else{
            m[string(1, s[i])] += 1;
        }
    }

    return m;
}

int main() {
    int wordNumber;
    string target;
    cin >> wordNumber;
    cin >> target;
    int count = 0;

    for(int i = 0; i < wordNumber - 1; i++) {
        string new_str;
        cin >> new_str;
        if(isSimilar(convertToMapFrom(target), convertToMapFrom(new_str))) {
            count++;
        }
    }
    cout << count << endl;
}