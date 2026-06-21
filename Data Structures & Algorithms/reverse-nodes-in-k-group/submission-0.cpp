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

class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr){
            ListNode* next = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k){
        k=k-1;
        while (temp != NULL && k > 0){
            k--;
            temp = temp -> next;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;

        while (temp != NULL){
            ListNode* kthNode=getKthNode(temp, k);
            if (kthNode == NULL){
                if (prevNode){
                    prevNode->next = temp;
                }
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);
            if (temp == head) { head = kthNode; }
            else prevNode->next = kthNode;

            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
