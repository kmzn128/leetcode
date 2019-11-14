#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define ALL(v) v.begin(), v.end()

int nthMostRare(const std::vector<int>& elements, int n) 
{
    VI sorted = elements;
    sort(ALL(sorted));
    map<int, int> counter;
    int val = 0;
    for(int &num : sorted) {
        if(counter.find(num) == counter.end()) {
            counter.insert({num,1});
            val = 1;
        }
        else {
            val++;
            counter[num] = val;
        }
    }
    vector<pair<int, int>> res;
    for(auto &e : counter) {
        res.push_back(make_pair(e.second, e.first));
    }
    return res[n-1].second;
}

int main()
{
    std::vector<int> input;
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(2);
    input.push_back(1);
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(2);
    input.push_back(5);
    input.push_back(4);
    input.push_back(3);
    input.push_back(5);
    input.push_back(4);
    input.push_back(5);
    input.push_back(5);

    int x = nthMostRare(input, 2);
    std::cout << x;
}