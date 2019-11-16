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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, VS> smap;
        for(string s : strs) {
            string sorted = s;
            sort(ALL(sorted));
            if(smap.find(sorted) == smap.end()) {
                VS vs;
                vs.push_back(s);
                smap.insert({sorted, vs});
            }
            else {
                smap[sorted].push_back(s);
            }
        }
        VVS ans;
        for(auto it = smap.begin(); it != smap.end(); it++) {
            VS sub_ans = it->second;
            ans.push_back(sub_ans);
        }
        return ans;
    }
};

int main() {
    int N;
    cin >> N;
    VS strs(N);
    REP(i, N) cin >> strs[i];
    VVS out = Solution().groupAnagrams(strs);
    int M = out.size();
    REP(i, M) {
        int m = out[i].size();
        REP(j, m) cout << out[i][j] << " ";
        cout << endl;
    }
    return 0;
}