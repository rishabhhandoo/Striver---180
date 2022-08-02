#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
Node<int>* solve(Node<int>* first , Node<int>* second){
    
    if(first->next == nullptr){
        first->next = second;
        return first;
    }
    
    Node<int>* c1 = first;
    Node<int>* n1 = c1->next;
    
    Node<int>* c2 = second;
    Node<int>* n2 = c2->next;
    
    while( n1 && c2){
        if(c1->data <= c2->data && c2->data <= n1->data){
            c1->next = c2;
            n2=c2->next;
            c2->next = n1;
            c1=c2;
            c2=n2;
        }else{
            c1=n1;
            n1=n1->next;
            
            if(n1==nullptr){
                c1->next=c2;
                return first;
            }
        }
       
    }
    
     return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    
    if(!first)    return second;
    if(!second)    return first;
    
    if(first->data<=second->data)
    {
        return solve(first,second);
    }else{
        return solve(second,first);
    }
    
}
