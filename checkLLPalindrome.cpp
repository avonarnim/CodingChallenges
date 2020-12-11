/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#import <iostream>
#import <string>

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode * fast = head;
        ListNode * slow = head;
        while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = slow->next;
        
        slow = reverse(slow);
        
        fast = head;
        while (slow != NULL && fast != NULL) {
            if (slow->val == fast->val) {
                slow = slow->next;
                fast = fast->next;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
    
    ListNode* reverse(ListNode* startingHead) {
        ListNode * temp = new ListNode();
        temp->next = startingHead;
        while (startingHead != NULL && startingHead->next != NULL) {
            ListNode * temp2 = temp->next;
            temp->next = startingHead->next;
            startingHead->next = startingHead->next->next;
            temp->next->next = temp2;
        }
        return temp->next;
    }
    
    
};