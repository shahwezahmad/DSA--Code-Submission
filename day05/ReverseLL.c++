class Solution {
public:

    ListNode* reverseList(ListNode* head) {

       //step 1
        ListNode* prev_p = NULL;
        ListNode* current_p = head;
        ListNode* next_p;
       
       //step 2
        while(current_p) {

            next_p = current_p->next;
            current_p->next = prev_p;
            
            prev_p = current_p;
            current_p = next_p;
        }

        head = prev_p; //step 3
        return head;
    }
};
Time Complexity:

Since we are iterating only once through the list and achieving reversed list. Thus, the time complexity is O(N) where N is the number of nodes present in the list.

Space Complexity:

To perform given tasks, no external spaces are used except three-pointers. So, space complexity is O(1).

Reverse a Linked List: Recursive
Intuition: This approach is very similar to the above 3 pointer approach. In the process of reversing, the base operation is manipulating the pointers of each node and at the end, the original head should be pointing towards NULL and the original last node should be the ‘head’ of the reversed Linked List. 

Approach: 

In this type of scenario, we first take a dummy node that will be assigned to NULL. 
Then we take a next pointer which will be initialized to head->next and in future iterations, next will again be set to head->next
Now coming to changes on the head node, as we have set the dummy node as NULL and next to head->next, we can now update the next pointer of the head to the dummy node.

Before moving to the next iteration dummy is set to head and then the head is set to the next node.

Now coming to the next iteration: We’ll follow a similar process to set next as head->next and update head->next = dummy, a dummy set to head, and head set to next

These iterations will keep going while the head of the original Linked List is not NULL, i.e. we’ll reach the end of the original Linked List and the Linked List has been reversed.
Code:

C++ Code
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
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        while (head != NULL) {
            ListNode *next = head->next;
            head->next = newHead;
            newHead = head;
            head = next;
        }
        return newHead;
    }
};
Java Code
Solution 3: Using Recursion

We traverse to the end of the list recursively.

As we reach the end of the list, we make the end node the head. Then receive previous nodes and make them connected to the last one.

At last, we link the second node to the head and the first node to NULL. We return to our new head.

Code:

C++ Code
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

    ListNode* reverseList(ListNode* &head) {

        if (head == NULL||head->next==NULL)
            return head;

        ListNode* nnode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nnode;
    }
};
