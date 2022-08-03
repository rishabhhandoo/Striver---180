bool isPalindrome(LinkedListNode<int> *head) {
    if(!head)    return true;
    //conversion to string
    LinkedListNode<int>* temp1 = head;
    vector<int> val;
//     int i=0;
    while(temp1){
        val.push_back(temp1->data);
//         cout<<"value inserted = "<<temp1->data<<endl;
        temp1=temp1->next;    
    }
    
    
    
    for(int i=0;i<(val.size())/2;i++)
    {
        if(val[i]!=val[val.size()-1-i])    return false;        
    }
    
    return true;

}