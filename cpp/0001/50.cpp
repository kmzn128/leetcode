#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
#define ALL(v) v.begin(), v.end()


class Solution {
public:
    void calcPowerNums(int n, VI &powers) {
        if (n == 0) return;
        int ans = 1;
        int i = 0;
        while(ans <= n) {
            ans *= 2;
            i++;
        }
        powers.push_back(--i);
        return calcPowerNums(n-ans/2, powers);
        
    }
    
    double myPow(double x, int n) {
        if(n == 0) return 1.0;
        VI powers;
        calcPowerNums(abs(n), powers);
        sort(ALL(powers));
        int ind = 0;
        double ans = 1.0;
        for(int &power : powers) {
            double sub_ans = (n > 0) ? x : 1/x;
            REP(i, power) {
                sub_ans *= sub_ans;
            }
            ans *= sub_ans;
        }
        return ans;   
    }
};

int main() {
    double x;
    cin >> x;
    int N;
    cin >> N;
    double out = Solution().myPow(x, N);
    cout << out << endl;
    return 0;
}