#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define ALL(v) v.begin(), v.end()

class Solution {
public:
    bool isValid(string s) {
        stack<char> lefts;
        for(char &c : s) {
            if(c == '(' || c == '[' || c == '{') {
                lefts.push(c);
            }
            else {
                if(c == ')') {
                    if(lefts.top() == '(') {
                        lefts.pop();
                    }
                    else {
                        return false;
                    }
                }
                if(c == ']') {
                    if(lefts.top() == '[') {
                        lefts.pop();
                    }
                    else {
                        return false;
                    }
                }
                if(c == '}') {
                    if(lefts.top() == '{') {
                        lefts.pop();
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return !lefts.size();
    }
};

int main() {
    string s;
    cin >> s;
    bool out = Solution().isValid(s);
    cout << out << endl;
    return 0;
}