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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        ListNode* iter1=head;
        ListNode* iter2=head;
        while((iter1)){
            while((iter2)&&(k<n)){
                iter2 = iter2->next;
                k++;
            }
            if(!iter2){
                ListNode* temp = head->next;
                delete head;
                return temp ;
            }
            else if(iter2->next==nullptr){
                ListNode* temp = iter1->next;
                iter1->next=iter1->next->next;
                delete temp ;
                break;
            }
            else{
                iter1=iter1->next;
                iter2=iter1;
                k=0;
            }
        }
        return head;
    }
};