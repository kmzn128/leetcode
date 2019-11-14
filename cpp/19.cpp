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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int N = 0;
        ListNode* curr = head;
        while(curr) {
            N++;
            curr = curr->next;
        }
        ListNode* prev = head;
        curr = head;
        for(int i = 0; i < N-n; i++) {
            prev = curr;
            curr = curr->next;
        }
        if(N == n) {
            head = head->next;
        }
        else {
            prev->next = curr->next;
        }
        return head;        
    }
};

int main() {
    ListNode* head = intVecToListNode({1,2});
    int n = 2;
    
    ListNode* ret = Solution().removeNthFromEnd(head, n);

    string out = listNodeToString(ret);
    cout << out << endl;

    return 0;
}