#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
#define RREP(i, n) for (int i = (n); i >= 0; i--)
#define RREP2(i, a, b) for (int i = (a); i > (int)(b); i--)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
#define ALL(v) v.begin(), v.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        if(!n) return 0;
        int counter = 0;
        RREP(i, n-1) {
            if(!counter && s[i] == ' ') {
                continue;
            }
            else if(counter && s[i] == ' ') {
                break;
            }
            else {
                counter++;
            }
        }
        return counter;
    }
};

int main() {
    string s;
    cin >> noskipws >> s;
    int out = Solution().lengthOfLastWord(s);
    cout << out << endl;
    return 0;
}