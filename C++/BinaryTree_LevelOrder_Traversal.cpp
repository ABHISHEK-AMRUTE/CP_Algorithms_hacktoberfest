// Implementation of Binary Tree in level wise Order in c++
#include <iostream>
#include <queue>
using namespace std;

class BinaryTreeNode     // A binary tree node
{
public :
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)          //Constructor to initialise the value
    {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode* takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1)          //if the rootdata is -1 the user doesn't want any of the node to be inserted further
    {
        return NULL;
    }
    BinaryTreeNode *root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode*> q;       // Create an empty queue for level order traversal
    q.push(root);       //push the node in the queue
    while(!q.empty())
    {
        BinaryTreeNode *currentNode = q.front();      // take the front of the queue and pop it from the queue
        q.pop();
        int leftChild, rightChild;
        cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1)
        {
            BinaryTreeNode* leftNode = new BinaryTreeNode(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);       //Enqueue left child
        }
        cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1)
        {
            BinaryTreeNode* rightNode = new BinaryTreeNode(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);        //Enqueue right child
        }
    }
    return root;
}

void printLevelWise(BinaryTreeNode *root)
{
    if(root==NULL)    //base case
    {
        return;
    }
    queue<BinaryTreeNode*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        BinaryTreeNode* front=pendingnodes.front();
        cout<<front->data<<":";
        pendingnodes.pop();
        if(front->left)
        {
            cout<<"L:"<<front->left->data<<",";
            pendingnodes.push(front->left);
        }
        else
        {
            cout<<"L:"<<"-1"<<",";
        }
        if(front->right)
        {
            cout<<"R:"<<front->right->data;
            pendingnodes.push(front->right);
        }
        else
        {
            cout<<"R:"<<"-1";
        }
        cout<<endl;
    }
    return;
}

int main()
{
    BinaryTreeNode* root = takeInputLevelWise();
    printLevelWise(root);
}
