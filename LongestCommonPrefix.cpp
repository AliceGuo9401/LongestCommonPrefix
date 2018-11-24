#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0)
        return "";
    if (strs.size() == 1)
        return strs[0];

    int minLength = strs[0].size();
    for (int i = 1; i < strs.size(); ++i) {
        if (strs[i].size() < minLength)
            minLength = strs[i].size();
    }

    int longest(0);
    int flag(0);
    for (int i = 0; i < minLength; ++i) {
        char temp = strs[0][i];
        for (int j = 1; j < strs.size(); ) {
            if (temp == strs[j][i])
                ++j;
            else if (temp != strs[j][i]) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            if (i == 0)
                return "";
            else if (i != 0)
                longest = i;
            break;
        }
    }
    
    if (flag == 0) {
        longest = minLength;
    }
    
    string str(strs[0].begin(), strs[0].begin() + longest);
    return str;
}

int main() {
    vector<string> strs{"f", "f"};
    string str = longestCommonPrefix(strs);
    cout << str;
    return 0;
}
