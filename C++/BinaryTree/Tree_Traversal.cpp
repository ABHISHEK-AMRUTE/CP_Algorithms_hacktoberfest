/*
    Name: Rithik Dutt
    College : Dayananda Sagar College of Engineering
*/
#include<bits/stdc++.h>
using namespace std;

class Node {
    public : int data;
            Node* left;
            Node* right;
            Node(int info){
                data =info;
                Node* left = NULL;
                Node* right = NULL;
            }
};
void inorder(Node* root){
    if(root == NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<endl;
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);
    cout<<"Inorder traversal"<<endl;
    inorder(root);
    cout<<"Preorder traversal"<<endl;
    preorder(root);
    cout<<"Postorder traversal"<<endl;
    postorder(root);
}