#include <bits/stdc++.h>
using namespace std;

int main() {
    int i = 0;
    int j = 0;
    while(i < 5) {
        cout << i++ << endl;
        while (i < 10) {
            cout << j++ << endl;
            break;
        }
        cout << i << endl;
    }
}