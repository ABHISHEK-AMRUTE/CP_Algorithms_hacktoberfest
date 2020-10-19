/* Name : Rithik Dutt
   College : Dayananda Sagar College of Engineering */

#include<bits/stdc++.h>

using namespace std;

class Node{
    public: int data;
            Node* next;
            Node(int info){
                data = info;
                next = NULL;
            }
};

int main(){
    Node* head;
    Node* tail;
    int n;
    cin>>n;
    int i ;
    cin>>i;
    head = new Node(i);
    tail = head;
    int j = n;
    n-=1;
    while(n){
        cin>>i;
        Node* temp;
        temp = new Node(i);
        tail->next = temp;
        tail = temp;
        n-=1;
    }
    // cout<<"middle";
    int mid = j/2;
    Node* cur;
    cur = head;
    // cout<<mid<<endl;
    mid -= 1;
    while(mid){
        mid -= 1;
        cur = cur->next;
        
        // cout<<cur->data<<" "<<mid<<endl;
    }
    cout<<cur->data<<endl;


}