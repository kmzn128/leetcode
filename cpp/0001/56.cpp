#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
#define ALL(v) v.begin(), v.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int N = intervals.size();
        VVI ans(0);
        if(!N) return ans;
        sort(ALL(intervals));
        int left = intervals[0][0];
        int left_max = left;
        int i = 0;
        while(i < N) {
            int right_max = intervals[i][1];
            while(i < N && left == intervals[i][0]) {
                chmax(right_max, intervals[i][1]);
                i++;
            }
            left = intervals[i][0];
            if(left <= right_max) {
                continue;
            }
            else {
                ans.push_back({left_max, right_max});
                left_max = left;
                continue;
            }
        }
        return ans;
    }
};

int main() {
    int N;
    cin >> N;
    VVI intervals(N, VI(2));
    REP(i, N) cin >> intervals[i][0] >> intervals[i][1];
    VVI out = Solution().merge(intervals);
    int len = out.size();
    REP(i, len) cout << out[i][0] << ' ' << out[i][1] << endl;
    return 0;
}