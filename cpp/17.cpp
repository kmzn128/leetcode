#include <bits/stdc++.h>
using namespace std;
typedef vector<string> VS;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

class Solution {
public:
    unordered_map<char, string> TABLE = 
        {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    
    vector<string> letterCombinations(string digits) {
        VS ans(0);
        for(char & digit : digits) {
            letterCombiUtil(digit, ans);
        }
        return ans;
    }

    void letterCombiUtil(char digit, VS &ans) {
        VS new_ans = ans;
        ans.clear();
        for(char &c : TABLE[digit]) {
            if(!new_ans.size()) {
                string s;
                s.push_back(c);
                ans.push_back(s);
            }
            else {
                for(string s : new_ans) {
                    s.push_back(c);
                    ans.push_back(s);
                }
            }
        }
    }
};

int main() {
    string s;
    cin >> s;
    VS out = Solution().letterCombinations(s);
    int N = out.size();
    REP(i, N) cout << out[i];
    cout << endl; 
    return 0;
}