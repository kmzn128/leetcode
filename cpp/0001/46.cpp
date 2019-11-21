#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i, n) for (int i = n-1; i >= 0; i--)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
#define RREP2(i, a, b) for (int i = (a); i > (int)(b); i--)
#define ALL(v) v.begin(), v.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int N = nums.size();
        VVI ans;
        if(N == 1) {
            ans.push_back(nums);
            return ans;
        }
        REP(i, N) {
            VI nums2 = nums;
            int popped = nums2[i];
            nums2.erase(nums2.begin()+i);
            VVI ans2 = permute(nums2);
            for(VI &v : ans2) {
                v.insert(v.begin(), popped);
                ans.push_back(v);
            }
        }
        return ans;
    }
};

int main() {
    int N;
    cin >> N;
    VI nums(N);
    REP(i, N) cin >> nums[i];
    VVI out = Solution().permute(nums);
    for(VI & v : out) {
        int len = v.size();
        REP(i, len) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}