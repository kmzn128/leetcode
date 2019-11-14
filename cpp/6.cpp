#include <bits/stdc++.h>
using namespace std;
typedef vector<string> VS;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int len = s.length();
        VS M(numRows, "");
        REP(i, len) {
            int div = i / (numRows-1);
            int mod = i % (numRows-1);
            if(!(div % 2)) {
                M[mod].push_back(s[i]);
            } 
            else {
                M[numRows-1-mod].push_back(s[i]);
            }
        }
        string ans = "";
        REP(i, numRows) ans += M[i];
        return ans;
    }
};

int main() {
    string s;
    cin >> s;
    int numRows;
    cin >> numRows;
    string out = Solution().convert(s, numRows);
    cout << out << endl;
    return 0;
}