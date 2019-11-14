#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
#define ALL(v) v.begin(), v.end()


class Solution {
public:
    int strStr(string haystack, string needle) {
        int H = haystack.size();
        int N = needle.size();
        if(!N) return 0;
        int i = 0;
        int j = 0;
        int ans = 0;
        while(i < H) {
            if(haystack[i+j] == needle[j]) {
                if(!j) ans = i;
                if(j == N-1) {
                    return ans;
                }
                j++;
            }
            else {
                i++;
                j = 0;
            }
        }
        return -1;
    }
};

int main() {
    string haystack;
    cin >> haystack;
    string needle;
    cin >> needle;
    int out = Solution().strStr(haystack, needle);
    cout << out << endl;
    return 0;
}