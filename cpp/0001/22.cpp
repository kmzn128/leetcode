#include <bits/stdc++.h>
using namespace std;
typedef vector<string> VS;
typedef set<string> SS;
#define ALL(v) v.begin(), v.end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

class Solution {
public:

    VS generateParenthesisUtil(int n) {
        VS ans(0);
        SS ans_set;
        if(n == 0) return ans;
        if(n == 1) {
            ans.push_back("()");
            return ans;
        } 
        else {
            VS before = generateParenthesisUtil(n-1);
            for (string s: before) {
                s.insert(0, "(");
                int N = s.length();
                for(int i = 1; i < N; i++) {
                    if(s[i-1] == '(') {
                        string ss = s;
                        ss.insert(i, ")");
                        ans_set.insert(ss);
                    }
                }
            }
        }
        for(string s: ans_set) ans.push_back(s);
        return ans;
    }

    vector<string> generateParenthesis(int n) {
        return generateParenthesisUtil(n);
    }
};

int main() {
    VS out = Solution().generateParenthesis(3);
    for(string s: out) cout << s << endl;
    return 0;
}

