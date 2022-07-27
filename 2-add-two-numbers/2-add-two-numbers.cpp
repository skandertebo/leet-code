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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* result_iter;
        ListNode* iter1 = l1;
        ListNode* iter2 = l2;
        int rest=0;
        while(iter1||iter2){
            if((iter1)&&(iter2)){
                int sum = iter1->val+iter2->val+rest;
                if(sum>=10){
                    sum=sum%10;
                    rest=1;
                }
                else{
                    rest=0;
                }
                if(!result){
                    result = new ListNode;
                    result->val = sum;
                    result_iter=result;
                }
                else{
                    result_iter->next = new ListNode;
                    result_iter->next->val = sum;
                    result_iter = result_iter->next;
                }
                iter1=iter1->next;
                iter2=iter2->next;
            }
            else if(iter1){
                result_iter->next = new ListNode;
                int sum = iter1->val+rest;
                result_iter->next->val = sum%10;
                result_iter = result_iter->next;
                rest = sum>=10 ;
                iter1=iter1->next;
            }
            else if(iter2){
                result_iter->next = new ListNode;
                int sum = iter2->val+rest;
                result_iter->next->val = sum%10;
                result_iter = result_iter->next;
                rest= sum>=10;
                iter2=iter2->next;
            }
        }
        if(rest==1){
            result_iter->next = new ListNode;
            result_iter->next->val = 1;
            result_iter = result_iter->next;
        }
        result_iter->next=nullptr;
        return result;
    }
};