#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
std::vector<int> findUniqueNumbers(const std::vector<int>& numbers)
{
    set<int> identifier;
    VI ans;
    for (const int &num : numbers) {
        if(identifier.find(num) == identifier.end()) {
           identifier.insert(num); 
        }
        else {
            identifier.erase(num);
        }
    } 
    for(const int &num : identifier) ans.push_back(num);
    return ans;
        
}

int main()
{
    std::vector<int> numbers = { 1, 2, 1, 3 };
    std::vector<int> result = findUniqueNumbers(numbers);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << '\n';
}