#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

struct windowFile {
    string content;
    windowFile(string content) : content(content) {};
};

bool compare(windowFile & w1, windowFile & w2)  {
    int length = min(w1.content.size(), w2.content.size());
    string c1, c2;
    bool is_number1 = false;
    bool is_number2 = false;
    int i = 0;
    int j = 0;
    int w1_size = w1.content.size();
    int w2_size = w2.content.size();

    while(i < w1_size && j < w2_size) {
        is_number1 = false;
        is_number2 = false;
        cout << i << " " << j << endl;
        c1 = "";
        c2 = "";

        while('0' <= w1.content[i]  && w1.content[i]  <= '9' && i < w1_size) {
            is_number1 = true;
            c1 += w1.content[i];
            i++;
        } 
        if(!is_number1) {
            c1 = w1.content[i];
            i++;
        }

        while('0' <= w2.content[j] && w2.content[i] <= '9'  && j < w2_size) {
            is_number2 = true;
            c2 += w2.content[j];
            j++;
        } 
        cout << c1  << "           ddddddddd      " << c2 << endl;
        if(!is_number2) {
            c2 = w2.content[j];
            j++;
        }

        if(is_number1 ^ is_number2) {
            if(is_number1) {
                return true;
            } else{
                return false;
            }
        } else if(is_number1 && is_number2)  {
            long long w1_number;
            long long w2_number;
            stringstream ss;
            ss << c1;
            ss >> w1_number;

            ss << c2;
            ss >> w2_number;

            if(w1_number == w2_number) {
                long long w1_zero = 0;
                long long w2_zero = 0;

                for(int ii = 0; ii < c1.size(); ii++) {
                    if(c1[ii] == '0') {
                        w1_zero += 1;
                    } else{
                        break;
                    }
                }
                for(int ii = 0; ii < c2.size(); ii++) {
                    if(c2[ii] == '0')  {
                        w2_zero += 1;
                    } else{
                        break;
                    }
                }

                return w1_zero <= w2_zero;
            } else{
                return w1_number < w2_number;
            }

        } else{
           return c1.compare(c2)  <= 0;
        }
    }

    cout << c1 << " " << c2;
    return true;
}

int main() {
    int N;
    cin >> N;
    vector<windowFile> windowFiles;

    for(int i = 0; i < N; i++)  {
        string s;
        cin >> s;
        windowFiles.push_back(windowFile(s));
    }

    sort(windowFiles.begin(), windowFiles.end(), compare);

    for(auto file: windowFiles) {
        cout << file.content << endl;
    }
    
    cout << ('0' <= '8' && '8' <= '9')  << "dsf" << endl;
    return 1;
}