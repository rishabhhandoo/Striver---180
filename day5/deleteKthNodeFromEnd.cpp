#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    LinkedListNode<int>* new_node = new LinkedListNode<int>(-1);
    new_node->next = head;    
    LinkedListNode<int>* slow = new_node;
    LinkedListNode<int>* fast = new_node;
    if(k==0)    return head;
    if(head==nullptr)    return head;
    
    for(int i=0;i<k;i++)
    {
        fast=fast->next;
    }
//     cout<<" Initial fast position "<<fast->data<<endl;
    while(fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
//     cout<<"slow position "<<slow->data<<endl;
    slow->next=slow->next->next;
    return new_node->next;
}