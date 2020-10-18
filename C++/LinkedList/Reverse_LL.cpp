
// Name : Rithik Dutt 
// College : Dayanandan Sagar College of Engineering

#include<bits/stdc++.h>

using namespace std;

class Node{
    public: int data;
            Node* next;
};

int main(){
    Node* Head = NULL;
    Node* Tail = NULL;
    Head = new Node();
    Tail = new Node();
    int n;
    cout<<"Enter the size"<<endl;
    cin>>n;
    int r = n;
    while(n){
        cout<<"Enter Value"<<endl;
        int temp;
        cin>>temp;
        if( r == n ){
            Head->data = temp;
            Tail = Head;
        }
        else{
            Node* prev = NULL;
            prev = new Node();
            prev->data = temp;
            Tail->next = prev;
            Tail = prev;
        }
        n -= 1;
    }
    Node* p = NULL;
    p = Head;
    while(p != NULL){
        cout<<p->data<<endl;
        p = p->next;
    }
    cout<<"reverse"<<endl;
    Node* pre = new Node();
    Node* cur = new Node();
    cur = Head;
    pre = Head;
    cur = cur->next;
    Head = Head->next;
    pre->next = NULL;
    Head = cur->next;
    cur->next = pre;
    pre = cur;
    cur = Head;
    while(cur != Tail){
        Head = cur->next;
        cur->next = pre;
        pre = cur;
        cur = Head;   
    }
    cur->next = pre;
    while(Tail != NULL){
        cout<<Tail->data<<endl;
        Tail = Tail->next;
    }
    return 0;
}
