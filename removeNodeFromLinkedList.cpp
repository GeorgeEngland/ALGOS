
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
private: 
    int getSize(ListNode* head){
        int ans = 1;
        ListNode* currNode = head;
        while(currNode->next){
            currNode=currNode->next;
            ans++;
        }
        return ans;
        
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = getSize(head);
        ListNode* currNode =head;
        for(int i = 0; i<size;i++){
            if(i==size-1){
                head = head->next;
            }
            
            if(i==size-n-1){
                currNode->next = currNode->next->next ? currNode->next->next : nullptr;
                break;
            }
            currNode = currNode->next;
        }
        return head;
    }
};
int main(){
    Solution s;
    ListNode bot(3);
    ListNode nxt(2,&bot);
    ListNode nxt2(2,&nxt);
    ListNode nxt3(2,&nxt2);
    ListNode head(2,&nxt3);
    ListNode* newNode = s.removeNthFromEnd(&head,2);
    return 0;
}