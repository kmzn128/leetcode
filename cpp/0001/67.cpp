#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REP2(i, a, b) for (int i = (a); i < (int)(b); i++)
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<char> VC;
#define ALL(v) v.begin(), v.end()
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }



class Solution {
public:
    char itoc(int i) {
        return (char)(i + (int)'0');
    }
    int ctoi(char c) {
        return (int)c - (int)'0';
    }
    
    string addBinary(string a, string b) {
        string ans;
        int i = a.size()-1;
        int j = b.size()-1;
        int sum = 0;
        int div = 0;
        int mod = 0;
        while(i >= 0 && j >= 0) {
            sum = ctoi(a[i]) + ctoi(b[j]) + div;
            mod = sum % 2;
            div = sum / 2;
            ans.insert(ans.begin(), itoc(mod));
            i--;
            j--;
        }
        while(i >= 0) {
            sum = ctoi(a[i]) + div;
            mod = sum % 2;
            div = sum / 2;
            ans.insert(ans.begin(), itoc(mod));
            i--;
        }
        while(j >= 0) {
            sum = ctoi(b[j]) + div;
            mod = sum % 2;
            div = sum / 2;
            ans.insert(ans.begin(), itoc(mod));
            j--;
        }
        if(div) ans.insert(ans.begin(), '1');
        return ans;
    }
};

int main() {
    string a, b;
    cin >> a;
    cin >> b;
    string out = Solution().addBinary(a, b);
    cout << out << endl;
    return 0;
}