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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyRoot = new ListNode(0);
        ListNode* curr = dummyRoot;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                curr->next = new ListNode(l1->val);
                curr = curr->next;
                l1 = l1->next;
            }
            else if(l1->val > l2->val) {
                curr->next = new ListNode(l2->val);
                curr = curr->next;
                l2 = l2->next;
            }
            else {
                curr->next = new ListNode(l1->val);
                curr = curr->next;
                l1 = l1->next;
                curr->next = new ListNode(l2->val);
                curr = curr->next;
                l2 = l2->next;
            }
        }
        while(l1) {
            curr->next = new ListNode(l1->val);
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2) {
            curr->next = new ListNode(l2->val);
            curr = curr->next;
            l2 = l2->next;
        }
        curr = dummyRoot->next;
        delete dummyRoot;
        return curr;
    }
};

int main() {
    ListNode* l1 = intVecToListNode({1,2,4});
    ListNode* l2 = intVecToListNode({1,3,4});
    
    ListNode* ret = Solution().mergeTwoLists(l1, l2);

    string out = listNodeToString(ret);
    cout << out << endl;

    return 0;
}