#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
#define ALL(v) v.begin(), v.end()


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* intVecToListNode(VI list) {

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* next_to_head = head->next;
        ListNode* next_to_next = next_to_head->next;
        next_to_head->next = head;
        head->next = swapPairs(next_to_next);
        return next_to_head;        
    }
};

int main() {
    ListNode* head = intVecToListNode({1,2,3,4,5,6});
    
    ListNode* ret = Solution().swapPairs(head);

    string out = listNodeToString(ret);
    cout << out << endl;

    return 0;
}