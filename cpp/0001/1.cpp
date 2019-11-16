#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<pair<int, int>> VII;
#define ALL(v) v.begin(), v.end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

class Solution {
public:
    int bin_search(VI &nums, int left, int right, int target) {
        if(left > right) {
            return -1;
        }
        int mid = (left + right) / 2;
        if(nums[mid] < target) {
            return bin_search(nums, mid+1, right, target);
        }
        else if(nums[mid] > target) {
            return bin_search(nums, left, mid-1, target);
        }
        else {
            return mid;
        }
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        VII nums_indexed;
        REP(i, N) nums_indexed.push_back(make_pair(nums[i], i));
        sort(ALL(nums_indexed));
        sort(ALL(nums));
        VI ans;
        REP(i, N-1) {
            int co_ind = bin_search(nums, i+1, N-1, target-nums[i]);
            if(co_ind >= 0) {
                ans.push_back(nums_indexed[i].second);
                ans.push_back(nums_indexed[co_ind].second);
                break;
            }
        }
        return ans;
    }
};

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    int N;
    cin >> N;
    VI nums(N);
    REP(i, N) cin >> nums[i];
    int target;
    cin >> target;
    VI ret = Solution().twoSum(nums, target);
    string out = integerVectorToString(ret);
    cout << out << endl;
    return 0;
}