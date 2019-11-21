#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<char> VC;
#define ALL(v) v.begin(), v.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



class Solution {
public:
    VI getFactorials(int n) {
        VI ans(n);
        ans[0] = 1;
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1]*(i+1);
        }
        return ans;
    }

    void getPermutationUtil(int n, int k, string &ans, VC &numChars, VI &facts) {
        if(n == 1) {
            ans.push_back(numChars[0]);
            return;
        }
        int div = k / facts[n-2];
        int mod = k % facts[n-2];
        ans.push_back(numChars[div]);
        numChars.erase(numChars.begin()+div);
        getPermutationUtil(n-1, mod, ans, numChars, facts);
        return;
    }

    string getPermutation(int n, int k) {
        string ans;
        VC numChars = {'1','2','3','4','5','6','7','8','9'};
        VI facts = getFactorials(n);
        getPermutationUtil(n, k-1, ans, numChars, facts);
        return ans;
    }

};

int main() {
    int N, K;
    cin >> N >> K;
    string out = Solution().getPermutation(N, K);
    cout << out << endl;      
    return 0;
}