#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> VB;
typedef vector<VB> VVB;
#define ALL(v) v.begin(), v.end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

class Solution {
public:
    
    string longestPalindrome(string s) {
        int len = s.length();
        VVB dp(len, VB(len, false));
        REP(i, len) {
            int j = 0;
            while (i-j >= 0 && i+j <= len-1) {
                if(s[i-j] == s[i+j]) {
                    dp[i-j][i+j] = true;
                    j++;
                    continue;
                }
                else {
                    break;
                }
            }
            j = 0;
            while (i-j >= 0 && i+1+j <= len-1) {
                if(s[i-j] == s[i+1+j]) {
                    dp[i-j][i+1+j] = true;
                    j++;
                    continue;
                }
                else {
                    break;
                }
            }
        }
        int k = len-1;
        while(k >= 1) {
            for(int i = 0; i < len - k; i++) {
                if(dp[i][k+i]) {
                    return s.substr(i, k+1);
                }
            }
            k--;
        }
        return s.substr(0,1);
    }
};

int main() {
    string s;
    cin >> s;
    string out = Solution().longestPalindrome(s);
    cout << out << endl;
    return 0;
}