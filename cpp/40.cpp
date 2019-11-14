#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef set<VI> SVI;
typedef vector<SVI> VSVI;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = n-1; i >= 0; i--)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
#define RREP2(i, a, b) for (int i = (a); i > (int)(b); i--)
#define ALL(v) v.begin(), v.end()


class Solution {
public:

    SVI combinationSum2Util(VI &nums, int t, VSVI &memo) {
        SVI ans;
        VI new_nums;
        VI conums;
        for(int &i : nums) {
            if(t-i >= 0) {
                new_nums.push_back(i);
                conums.push_back(t-i);
            }
        }
        int N = conums.size();
        REP(i, N) {
            SVI sub_ans = combinationSum2Util(new_nums, conums[i], memo);
            for(auto it = sub_ans.begin(); it != sub_ans.end(); it++) {
                VI v = *it;
                v.push_back(new_nums[i]);
                ans.insert(v);
            }
        }
        return ans;

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        VSVI memo(target+1, SVI());
        SVI ans = combinationSum2Util(candidates, target, memo);
        int N = ans.size();
        VVI vans;
        for(auto it = ans.begin(); it != ans.end(); it++) {
            VI v = *it;
            vans.push_back(v);
        }
        return vans;
    }
};

int main() {
    int N;
    cin >> N;
    VI cand(N);
    REP(i, N) cin >> cand[i];
    int T;
    cin >> T;
    VVI out = Solution().combinationSum2(cand, T);
    for(VI & v : out) {
        int len = v.size();
        REP(i, len) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}