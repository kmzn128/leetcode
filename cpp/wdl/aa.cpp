#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define ALL(v) v.begin(), v.end()
std::vector<int> findUniqueNumbers(const std::vector<int>& numbers)
{
    VI sorted = numbers;
    sort(ALL(sorted));
    int N = sorted.size();
    int before = sorted[0];
    VI ans;
    for (int i = 1; i < N; i++) {
        if(sorted[i] == before) {
            continue;
        }
        else {
            ans.push_back(sorted[i]);
            before = sorted[i];
        }
    } 
    return ans;
        
}

int main()
{
    std::vector<int> numbers = { 1, 2,3,3,4,5 };
    std::vector<int> result = findUniqueNumbers(numbers);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << '\n';
}