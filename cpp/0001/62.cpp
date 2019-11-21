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
    int binomialCoeff(int n, int k) {  
        int res = 1;  
    
        // Since C(n, k) = C(n, n-k)  
        if ( k > n - k )  
            k = n - k;  
    
        // Calculate value of  
        // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]  
        for (int i = 0; i < k; ++i)  
        {  
            res *= (n - i);  
            res /= (i + 1);  
        }  
  
        return res;  
    }

    int uniquePaths(int m, int n) {
        return binomialCoeff(m+n-2, n-1);
    }

};

int main() {
    int M, N;
    cin >> M >> N;
    int out = Solution().uniquePaths(M, N);
    cout << out << endl;
    return 0;
}