#include<unordered_map>
#include<string.h>
#include<algorithm>
#include<iostream>

using namespace std;

int convertRomanToArabian(string roman, unordered_map<string, pair<int, int>> romanToArabian) {
    int converted = 0;
    int size = roman.size();
    int i = 0;
    
     while(i < size) {
        if(i < size - 1 && romanToArabian[string(1, roman[i])] < romanToArabian[string(1, roman[i + 1])]) {
            string new_str = string(1, roman[i]) + string(1, roman[i + 1]);
            converted += romanToArabian[new_str].first;
            i += 2;
        } else{
            
            converted += romanToArabian[string(1, roman[i])].first;
            i++;
        }
    
    }
    return converted;
}

string findSignFromNumber(int number, unordered_map<string, pair<int, int>> romanToArabian) {
 for(auto & iter: romanToArabian) {
     if(iter.second.first == number)  {
         return iter.first;
     }
 }   
}

string convertArabinaiToRoman(int resultArabian, unordered_map<string, pair<int, int>> romanToArabian, unordered_map<string, string> avoidEachOther, int numbers[13]) {
    string romanResult = "";
    int romanCount = 0;
    while(resultArabian != 0 ){
        int maxPossibleNum = 0;
        string romanNum;
        for(int i = 0; i < 13; i++) {
            if(numbers[i] <= resultArabian && maxPossibleNum <= numbers[i]) {
                maxPossibleNum = numbers[i];
            }
        }
   
         romanCount = resultArabian / maxPossibleNum;
            for(int j = 0; j < romanCount; j++) {
                romanResult += findSignFromNumber(maxPossibleNum, romanToArabian);
            }
        resultArabian = resultArabian % maxPossibleNum;
    }
    return romanResult;
}

int main() {
    unordered_map<string, pair<int, int>> romanToArabian;
    unordered_map<string, string> avoidEachOther;
    int number[] = {1, 5, 10, 50, 100, 500, 1000, 4, 9, 40, 90, 400, 900};
    romanToArabian["I"] = {1, 3};
    romanToArabian["V"] = {5, 1};
    romanToArabian["X"] = {10, 3};
    romanToArabian["L"] = {50, 1};
    romanToArabian["C"] = {100, 3};
    romanToArabian["D"] = {500, 1};
    romanToArabian["M"] = {1000, 3};
    romanToArabian["IV"] = {4, 1};
    romanToArabian["IX"] = {9, 1};
    romanToArabian["XL"] = {40, 1};
    romanToArabian["XC"] = {90, 1};
    romanToArabian["CD"] = {400, 1};
    romanToArabian["CM"] = {900, 1};

    avoidEachOther["IV"] = "IX";
    avoidEachOther["IX"] = "IV";

    avoidEachOther["XL"] = "XC";
    avoidEachOther["XC"] = "XL";
    
    avoidEachOther["CD"] = "CM";
    avoidEachOther["CM"] = "CD";

    string a, b;
    int resultArabian;
    int convertedA = 0;
    int convertedB = 0;
    int a_size, b_size;

    cin >> a >> b;

    a_size = a.size();
    b_size = b.size();

    convertedA = convertRomanToArabian(a, romanToArabian);
    convertedB = convertRomanToArabian(b, romanToArabian);

    resultArabian = convertedA + convertedB;
    string resultRoman = convertArabinaiToRoman(resultArabian, romanToArabian, avoidEachOther, number);
   
   cout << resultArabian << endl;
   cout << resultRoman << endl;
   return 0;
}