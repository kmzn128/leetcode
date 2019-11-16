#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
#define ALL(v) v.begin(), v.end()


class Solution {
public:
    void inc(int& x) {
        if(x < INT_MAX) x++;
    }
    void dec(int& x) {
        if(x > INT_MIN) x--;
    }

    int divide(int dividend, int divisor) {
        int ans = 0;
        if(!dividend) return ans;
        else if(dividend > 0) {
            if(divisor > 0) {
                while(dividend >= divisor ) {
                    dividend -= divisor;
                    inc(ans);
                }
            }
            else {
                while(dividend >= -divisor ) {
                    dividend += divisor;
                    dec(ans);
                }
            }
        }
        else {
            if(divisor > 0) {
                while(dividend <= -divisor ) {
                    dividend += divisor;
                    dec(ans);
                }
            }
            else {
                while(dividend <= divisor ) {
                    dividend -= divisor;
                    inc(ans);
                }
            }           
        }
        return ans;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    int out = Solution().divide(N, M);
    cout << out << endl;
    return 0;
}