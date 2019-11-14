#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<pair<int, int>> VII;
#define ALL(v) v.begin(), v.end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0.0;
        for(int & i : nums2) {
            auto it = lower_bound(ALL(nums1), i);
            nums1.insert(it, i);
        }
        int len = nums1.size();
        if(len % 2) {
            return nums1[len/2];
        }
        else {
            return (nums1[len/2-1] + nums1[len/2])/2.0;
        }
    }
};

int main() {
    int N1;
    int N2;
    cin >> N1;
    cin >> N2;
    VI num1(N1);
    VI num2(N2);
    REP(i, N1) cin >> num1[i];
    REP(i, N2) cin >> num2[i];
    int out = Solution().findMedianSortedArrays(num1, num2);
    cout << out << endl;
    return 0;
}