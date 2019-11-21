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
    vector<int> plusOne(vector<int>& digits) {
        int N = digits.size();
        int div = 1;
        REP(i, N) {
            int mod = (digits[N-1-i] + div) % 10;
            div = (digits[N-1-i] + div) / 10;
            digits[N-1-i] = mod;
            if(!div) {
                return digits;
            }
        }
        if(div) digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {
    int N;
    cin >> N;
    VI digits(N, 0);
    REP(i, N) cin >> digits[i];
    VI out = Solution().plusOne(digits);
    int M = out.size();
    REP(i, M) cout << out[i];
    cout << endl;
    return 0;
}