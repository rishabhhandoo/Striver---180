
int findIntersection(Node *firstHead, Node *secondHead)
{
    Node* len1 = firstHead;
    Node* temp1 = firstHead;
    int length1=0;
    Node* len2 = secondHead;
    Node* temp2 = secondHead;
    int length2=0;
    while(len1){
        len1 = len1->next;
        length1++;
    }
    while(len2){
        len2 = len2->next;
        length2++;
    }
    int diff = abs(length1-length2);
   
    if(length1>length2){
        while(diff--)
            temp1=temp1->next;
    }
    else if(length2>length1){
            while(diff--)
                temp2=temp2->next;
        }
    
    while(temp2 && temp1)
    {
        if(temp2 ==  temp1)    return temp1->data;
        temp1=temp1->next;
        temp2=temp2->next;        
    }
    return -1;
    
    }
