#include<iostream>
#include<vector>

using namespace std;

int main() {
    string target;
    cin >> target;
    string bomb;
    cin >> bomb;
    bool is_bombed = false;
    string answer;

    for(int i = 0;  i < target.size(); i++) {
        answer += target[i];
        if(answer[answer.length() - 1] == bomb[bomb.length() - 1] ) {
            int b_index = bomb.length() - 2;
            int l = answer.length() - 2;
            int count = 1;
        
            for(; l >= 0 && l >= answer.length() - bomb.length() && b_index >= 0 ; l--, b_index--) {
                //cout << answer[l] <<  " " << bomb[b_index] << endl;
                if(answer[l] != bomb[b_index])  {
                    break;
                } else{
                    count++;
                }
                    
            }

            if(count == bomb.length()){
                for(int k = 0; k < bomb.size(); k++) {
                        answer.pop_back();
                        is_bombed = true;
                }
                
            }

        }
    }

   
    if(answer == "") {
        cout << "FRULA";
    } else{
        cout << answer;
    }
    return 0;
}