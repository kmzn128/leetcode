#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
#define RREP2(i, a, b) for (int i = (a); i > (int)(b); i--)
#define ALL(v) v.begin(), v.end()


class Solution {
public:

    string countAndSayUtil(string s) {
        if(s == "") return "1";
        string out;
        int counter = 1;
        char num = s[0];
        int len = s.size();
        REP2(i, 1, len) {
            if(s[i] == num) {
                counter++;
                continue;
            }
            else {
                out.push_back(to_string(counter)[0]);
                out.push_back(num);
                num = s[i];
                counter = 1;
            }
        }
        out.push_back(to_string(counter)[0]);
        out.push_back(num);
        return out;
    }

    string countAndSay(int n) {
        string s = "";
        REP(i, n) {
            string next_s = countAndSayUtil(s);
            s = next_s;
        }
        return s;
    }
};

int main() {
    int N;
    cin >> N;
    string out = Solution().countAndSay(N);
    cout << out << endl;
    return 0;
}