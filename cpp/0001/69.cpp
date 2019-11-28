#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<char> VC;
#define ALL(v) v.begin(), v.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



class Solution {
public:
    int mySqrt(int x) {
        if(!x) return 0;
        int i = 1;
        ll sq = 1L;
        while(sq <= (ll)x) {
            i++;
            sq = (ll)i*i;
        }
        return i-1;
    }
};

int main() {
    int x;
    cin >> x;
    int out = Solution().mySqrt(x);
    cout << out << endl;
    return 0;
}