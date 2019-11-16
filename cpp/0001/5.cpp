#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> VB;
typedef vector<VB> VVB;
#define ALL(v) v.begin(), v.end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

class Solution {
public:
    string longestPalindrome(string s) {
        int N = s.length();
        int i, j;
        if(N % 2) {
            i = j = N/2;
        }
        else {
            i = N/2-1;
            j = N/2;
        }
        int i_bound = i;
        int j_bound = j;
        VVB dp(N, VB(N, false));
        while(i >= 0 || j <= N-1)
                if(j == i) {
                    dp[i][j] = true;
                    chmin(i_min, i);
                    chmax(j_max, j);
                }
                else if(j == i+1) {
                    if(s[i] == s[j]) {
                        dp[i][j] = true;
                        chmin(i_min, i);
                        chmax(j_max, j);    
                    }
                }
                i--;
                j++;
                if(dp[i][j-1] && (s[i+1] == s[j-1])) {
                    dp[i][j] = true;
                    chmin(i_min, i+1);
                    chmax(j_max, j-1);  
                }
                
        }
        return s.substr(i_min, j_max);

    }
};

int main() {
    string s;
    cin >> s;
    string out = Solution().longestPalindrome(s);
    cout << out << endl;
    return 0;
}