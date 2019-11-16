#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<pair<int, int>> VII;
#define ALL(v) v.begin(), v.end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> char_set;
        int left = 0;
        int right = 0;
        int N = s.length();
        int ans = 0;
        while(right < N) {
            if(char_set.find(s[right]) == char_set.end()) {
                char_set.insert(s[right++]);
                chmax(ans, right-left);
            }
            else {
                char_set.erase(s[left++]);
            }
        }
        return ans;
    }
};

int main() {
    string S;
    cin >> S;
    int out = Solution().lengthOfLongestSubstring(S);
    cout << out << endl;
    return 0;
}