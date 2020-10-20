// Name : Rithik Dutt
// College : Dayananda Sagar College of Engineering

#include<bits/stdc++.h>
using namespace std;

class Node{
    public: int data;
            Node* next;
            Node(int info){
                data = info;
            }
};

Node* insert(Node* head , Node* tail){
    int n ;
    cin>>n;
    int i ;
    cin>>i;
    int N= n;
    n -=1;
    head = new Node(i);
    tail = head;
    while(n){
        Node* temp;
        cin>>i;
        temp = new Node(i);
        tail->next = temp;
        tail= temp;
        n-=1;
    }
    return(head);

}
Node* remdup(Node* head){
    Node* temp = head;
    Node* prev = head;
    int var = temp->data;
    temp = temp->next;
    // cout<<var<<endl;
    while(temp != NULL){
        // cout<<"before "<<prev->data<<" "<<temp->data<<" and "<<var<<endl;

        if(prev->data == var){
            prev->next = temp->next;
        }
        else{
            prev = temp;
        }
        temp = temp->next;
        if(temp != NULL){
            var = temp->data;
            // cout<<prev->data<<" "<<temp->data<<endl;
        }
    }
    return(head);
}
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head;
    Node* tail;
    head = insert(head , tail);
    head = remdup(head);
    print(head);
}