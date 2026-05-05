// Problem: Rotate List
// URL: https://leetcode.com/problems/rotate-list/?envType=daily-question&envId=2026-05-05

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
    int len(ListNode* head){
        int length=0;

        while(head!=NULL){
            length++;
            head=head->next;
        }

        return length;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int length=len(head);
        k=k%length;

        if(k==0) return head;

        ListNode* curr=head;
        ListNode* prev=nullptr;

        ListNode* newHead=nullptr;
        int cnt=length-k;
        while(curr->next!=NULL){
            cnt--;
            prev=curr;
            curr=curr->next;
            if(cnt==0){
                newHead=curr;
                prev->next=NULL;
                break;
            }
        }

        while(curr->next!=NULL){
            curr=curr->next;
        }

        curr->next=head;

        return newHead;

    }
};