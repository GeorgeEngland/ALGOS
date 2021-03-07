#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
//HASHMAP OR FLOYD CYCLE DETECTION: Fast pointer moves 2, slow pointer moves 1. 
//IF POINTERS EQUAL, THEN CYCLE!
// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int> visited;
        ListNode* currNode = head;
        visited.insert({currNode,0});
        int i = 1;
        if(!currNode)return NULL;
        while(currNode->next){
            if(visited.find(currNode->next)==visited.end()){
                visited.insert({currNode->next,i});
                i++;
                currNode= currNode->next;
            }
            else return currNode->next;
        }
        return NULL;
    }
};