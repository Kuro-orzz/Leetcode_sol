/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node* tmp = head;
        while(tmp){
            Node* newNode = new Node(tmp->val);
            newNode->next = tmp->next;
            tmp->next = newNode;
            tmp = tmp->next->next;
        }
        Node* ans = new Node(0);
        Node* t = ans;
        tmp = head;
        while(tmp){
            if(tmp->random == NULL)
                tmp->next->random = NULL;
            else tmp->next->random = tmp->random->next;
            tmp = tmp->next->next;
        }
        t = ans;
        tmp = head;
        while(tmp){
            t->next = tmp->next;
            t = t->next; 
            tmp->next = tmp->next->next;
            tmp = tmp->next;
        }
        return ans->next;
    }
};