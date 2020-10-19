/*Name: sanorita
college: IIT BHU(Varanasi)
PROGRAM TO PRINT LOWEST COMMON ANCESTOR IN BST
we will be using recursive approach for it
Time complexity: O(h)
where h represents height of the tree
Space complexity: O(1)
 INPUT:-
         21
        / \
      9   22
     / \
    6   13
       / \
     11  14
  OUTPUT: like for 11 and 14 Lowest common Ancestor is 13 
  for 14 and 9 Lowest common Ancestor is 9 
  for 11 and 22 Lowest common Ancestor is 21 
 
 Approach:
  For Binary search tree, while traversing the tree from top to bottom of the tree the
  first node which lies in between the two given numbers whose lowest common ancestor(LCA) we 
  need to find is that node which lies in between then i.e., let suppose for n1 and n2 we need
  to find lowest common ancestor then it would be the first node n with the lowest depth which 
  lies in between n1 and n2 (n1<=n<=n2)n1 < n2. So just recursively traverse the BST in,
  if node's value is greater than both n1 and n2 then our LCA lies in the left side of the 
  node, if it's is smaller than both n1 and n2, then LCA lies on the right side. 
  Otherwise, the root is LCA,we are assuming that both the numbers i.e.,n1 and n2 are present 
  in BST.  
    
*/

#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
	int data;
    Node* left;
    Node* right;
    
};
//function to create a node 
Node* newNode(int data)  
{  
    Node* temp = new Node(); 
    temp->data = data;  
    temp->left = temp->right = NULL;  
    return temp;  
} 
//function to find the node of lowest common ancestor in BST 
Node* lowestcommonancestor(Node *root, int n1, int n2)
{
   //Your code here
   if(root==NULL)
   {
       return NULL;
   }
  if(root->data>n1 && root->data>n2)
  {
      return lowestcommonancestor(root->left,n1,n2);
  }
  if(root->data<n1 && root->data<n2)
  {
      return lowestcommonancestor(root->right,n1,n2);
  }

  return root;

}

int main() 
{  
    //Let us construct a BST as shown in figure  
   Node *root = newNode(21);  
    root->left = newNode(9);  
    root->right = newNode(22);  
    root->left->left = newNode(6);  
    root->left->right = newNode(13);  
    root->left->right->left = newNode(11);  
    root->left->right->right = newNode(14); 
  
    int n1=11, n2=14;   
    Node* temp =lowestcommonancestor(root, n1, n2);  
    cout << "Lowest common Ancestor of " << n1 << " and " << n2 << " is " << temp->data<<"\n";  
  
    n1=14, n2 =9;  
    temp=lowestcommonancestor(root, n1, n2);  
    cout<<"Lowest common Ancestor of " << n1 << " and " << n2 << " is " << temp->data <<"\n";  
  
    n1 =11, n2 =22;  
     temp=lowestcommonancestor(root, n1, n2);  
    cout << "Lowest common Ancestor of " << n1 << " and " << n2 << " is " <<temp->data <<"\n";  
     
} 
