#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    // Approach 1: Using Stack
    bool isPalindrome_UsingStack(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        // Push all values into the stack
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Reset temp to head and compare
        temp = head;
        while (temp != nullptr) {
            if (temp->val != st.top()) {
                return false;
            }
            st.pop();
            temp = temp->next;
        }

        return true;
    }

    // Helper function to reverse a list recursively
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* newHead = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    // Approach 2: Reverse second half and compare
    bool isPalindrome_ReverseHalf(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        // Find middle node
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* secondHalfStart = reverse(slow->next);

        // Compare both halves
        ListNode* firstHalf = head;
        ListNode* secondHalf = secondHalfStart;
        bool isPalin = true;

        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                isPalin = false;
                break;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // (Optional) Restore list structure
        // slow->next = reverse(secondHalfStart);

        return isPalin;
    }

    // Approach 3: Store in vector and use two-pointer
    bool isPalindrome_UsingVector(ListNode* head) {
        vector<int> values;

        while (head) {
            values.push_back(head->val);
            head = head->next;
        }

        int left = 0;
        int right = values.size() - 1;

        while (left < right) {
            if (values[left] != values[right]) return false;
            left++;
            right--;
        }

        return true;
    }
};
int main() {
    // Creating list: 1 -> 2 -> 2 -> 1
    ListNode* node4 = new ListNode(1);
    ListNode* node3 = new ListNode(2, node4);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);

    Solution sol;

    cout << "Using Stack: " << sol.isPalindrome_UsingStack(node1) << endl;
    cout << "Using Reverse Half: " << sol.isPalindrome_ReverseHalf(node1) << endl;
    cout << "Using Vector: " << sol.isPalindrome_UsingVector(node1) << endl;

    return 0;
}
