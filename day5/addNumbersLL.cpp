#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
	        Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *addTwoNumbers(Node *head1, Node *head2)
{
    if(!head1)    return head2;
    if(!head2)    return head1;
    
    Node* newNode = nullptr;
    
    Node * newNodeHead = nullptr;
     int carry = 0;
    while(head1 && head2){
        int val = head1->data + head2->data;
        val = val +carry;
        Node* ins = new Node(val%10);
        val = val/10;
        carry = val; 
        if(!newNode){
            newNode = ins;
            newNodeHead = ins;
        }
        else{
            newNode->next = ins;
            newNode = ins;
        }
        head1=head1->next;
        head2=head2->next;        
    }
    
    while(head1!=nullptr){
        int val = head1->data ;
        val = val +carry;
        Node* ins = new Node(val%10);
        val = val/10;
        carry = val; 
        newNode->next = ins;
            newNode = ins;
        head1=head1->next;
    }
    
    while(head2!=nullptr){
        int val = head2->data ;
        val = val +carry;
        Node* ins = new Node(val%10);
        val = val/10;
        carry = val; 
        newNode->next = ins;
            newNode = ins;
        head2=head2->next;
    }
    if(carry != 0 ){
        Node* ins = new Node(carry);
        newNode ->next = ins;
    }
    
    return newNodeHead;
    
    
    
}

