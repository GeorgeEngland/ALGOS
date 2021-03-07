
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
    ListNode* swapNodes(ListNode* head, int k) {
        int size = getSize(head);
        ListNode* parentOfStartNode = nullptr;
        ListNode* parentOfEndNode = nullptr;
        ListNode* nodeToSwapStart = head;
        ListNode* nodeToSwapEnd = head;
        
        ListNode* currNode = head;
        ListNode* parentCurrNode = nullptr;
        for(int i = 0;i<size;i++){
            if(i==k-1){
                //Set next Node as node to swap and remember its parent
                nodeToSwapStart = currNode;
            }
            if(i==size-k){
                nodeToSwapEnd = currNode;
            }
            parentCurrNode = currNode;
            currNode=currNode->next;
        }
       int tmpVal;
        tmpVal=nodeToSwapStart->val;
        nodeToSwapStart->val = nodeToSwapEnd->val;
        nodeToSwapEnd->val = tmpVal;
        

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
    ListNode* newNode = s.swapNodes(&head,2);
    return 0;
}