#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 1;
        int N = nums.size();
        if(!N) return 0;
        int before = nums[0];
        int i = 1;
        while(i < N) {
            if(nums[i] == before) {
                nums.erase(nums.begin()+i);
                N--;
            }
            else {
                before = nums[i];
                i++;
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    int N;
    cin >> N;
    VI v(N);
    REP(i, N) cin >> v[i];
    int out = Solution().removeDuplicates(v);
    cout << out << endl;
    return 0;
}