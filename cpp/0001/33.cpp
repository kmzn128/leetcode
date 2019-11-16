#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
#define RREP2(i, a, b) for (int i = (a); i > (int)(b); i--)
#define ALL(v) v.begin(), v.end()


class Solution {
public:

    int searchUtil(VI &nums, int left, int right, int target) {        if(left > right) return -1;
        int mid = (right-left) / 2 + left;
        if(nums[mid] == target) return mid;
        if(nums[mid] >= nums[left]) { // left is ordered
            if(nums[mid] >= target && target >= nums[left]) {
                return searchUtil(nums, left, mid-1, target);
            }
            else {
                return searchUtil(nums, mid+1, right, target);
            }
        }
        else { // right is ordered
            if(nums[mid] <= target && target <= nums[right]) {
                return searchUtil(nums, mid+1, right, target);
            }
            else {
                return searchUtil(nums, left, mid-1, target);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return searchUtil(nums, 0, nums.size()-1, target);
    }
};

int main() {
    int N;
    cin >> N;
    VI nums(N);
    REP(i, N) cin >> nums[i];
    int T;
    cin >> T;
    int out = Solution().search(nums, T);
    cout << out << endl;
    return 0;
}