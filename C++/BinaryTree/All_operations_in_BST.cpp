// Name      :   Neeraj Mirji
// College   :   National Institute of Technology Karnataka



#include<iostream>
#define space 5
using namespace std;


class TreeNode
{
public:
	int value;
	TreeNode *left;
	TreeNode *right;

	TreeNode()
	{
		value = 0;
		left = NULL;
		right = NULL;
	}

	TreeNode(int v)
	{
		value = v;
		left = NULL;
		right = NULL;

	}


};

class BST
{
public:
	TreeNode *root;

	BST()
	{
		root = NULL;
	}

	bool isEmpty()
	{
		return(root==NULL);
	}


	void insertNode(TreeNode *new_node)
	{
		if(root==NULL)
		{
			root = new_node;
			cout<<"Node added as a root node "<<endl;
		}
		else
		{
			TreeNode *temp = root;
			while(temp!=NULL)
			{
				if(temp->value == new_node->value)
				{
					cout<<"Node already exists with given value "<<endl;
					return;
				}
				else if(temp->value > new_node->value  && temp->left == NULL)
					  {
                          temp->left = new_node;
                          cout<<"value added to the left "<<endl;
                          break ;
					  }
					  else if(temp->value > new_node->value )
					       {
                               temp = temp->left;
					       }
					       else if(temp->value < new_node->value  && temp->right == NULL)
					            {
                                    temp->right = new_node;
                                    cout<<"value added to the right "<<endl;
                                    break ;
					            }
					            else if(temp->value < new_node->value )
					                 {
                                         temp = temp->right;
					                 }

			}
		}
	}





void printPreorder(TreeNode *r)
{
	if(r==NULL) return;
	cout<<r->value<<endl;
	printPreorder(r->left);
	printPreorder(r->right);

}


void printInorder(TreeNode *r)
{
	if(r==NULL) return;
	printInorder(r->left);
	cout<<r->value<<endl;
	printInorder(r->right);

}

void printPostorder(TreeNode *r)
{
	if(r==NULL) return;
	printPostorder(r->left);
	printPostorder(r->right);
	cout<<r->value<<endl;
}

void print2D(TreeNode *r,int sp)
{
	if(r==NULL) return;
	sp = sp + space;
	print2D(r->right,sp);
	cout<<endl;
	for(int i = space;i<sp;i++) cout<<" ";
	cout<<r->value<<endl;
    print2D(r->left,sp);
}

TreeNode *Search(int val)
{
	if(root == NULL) return NULL;
	else
	{
	 TreeNode *temp = root;
	 while(temp!=NULL)
	 {
	 	if(temp->value == val) return temp;
	 	else
	 	{
	 	 if(val > temp->value) temp = temp->right;
	 	 else temp = temp->left;	
	 	}
	 }
	 return NULL;	
	}
}


int height(TreeNode *r)
{
	if(r==NULL) return -1;
	else
	{
		int lheight = height(r->left);
		int rheight = height(r->right);
		if(lheight > rheight) return (lheight+1);
		else return(rheight+1);
	}

}


void printBFS(TreeNode *r)
{
	int i,h = height(r);
    for(i=0;i<=h;i++) printGivenLevel(r,i);
}

void printGivenLevel(TreeNode *r,int lvl)
{
	if(r==NULL) return;
    else if(lvl == 0) cout<<r->value<<endl;
         else 
         {
         	printGivenLevel(r->left,lvl-1);
         	printGivenLevel(r->right,lvl-1);
         }
}

  TreeNode * maxValueNode(TreeNode * node) {
    TreeNode * current = node;
    /* loop down to find the leftmost leaf */
    while (current -> right != NULL) {
      current = current -> right;
    }
    return current;
  }

TreeNode *deleteNode(TreeNode *r,int v )
{

	if(r == NULL) return r;
	else if(v < r->value)   r->left = deleteNode(r->left,v);
	else if(v > r->value)   r->right = deleteNode(r->right,v);
	else if(r->left == NULL) 
	{
		TreeNode *temp = r->right;
		delete r;
		return temp;
	}
	else if(r->right == NULL)
	{
		TreeNode *temp = r->left;
		delete r;
		return temp;
	}
	else{

		TreeNode *temp = maxValueNode(r->left);
		r->value = temp->value;
		r->right = deleteNode(r->right , temp->value);
	}
	return r;
	}
	
};


int main()
{
  BST obj;
  int option, val;
 
  do {
    cout << "What operation do you want to perform? " <<" Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print the Tree in a 2d way" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Print Preorder traversal " << endl;
    cout << "7. Print Inorder traversal " << endl;
    cout << "8. Print Postorder traversal " << endl;
    cout << "9. Print in BSF order " << endl;
    cout << "10. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;
 
    cin >> option;
    
    TreeNode * new_node = new TreeNode();
 
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "INSERT" << endl;
      cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
      cin>>val;
      new_node->value = val;
      obj.insertNode(new_node);
      cout<<endl;
      break;
    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
      cin>>val;
      new_node = obj.Search(val);
      if(new_node!=NULL)
      {
       cout<<" Node with the given value succesfully found "<<endl;
      }
      else cout<<"Node with the given value not found "<<endl;
     
      break;
    case 3:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      cin>>val;
      new_node = obj.Search(val);
      if(new_node!=NULL)
      {
       obj.deleteNode(obj.root,val);
       cout<<" Node with the given value succesfully deleted "<<endl;
      }
      else cout<<"Node with the given value not found "<<endl;
      break;
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root,5);
      break;
    case 5:
      cout << "TREE HEIGHT" << endl;
      cout << "Height : " << obj.height(obj.root) << endl;
      break;
    case 6:
      cout<<"printing Preorder Tree traversal "<<endl;
      obj.printPreorder(obj.root);
      break;
    case 7:
      cout<<"printing Inorder Tree traversal "<<endl;
      obj.printInorder(obj.root);
      break;
    case 8:
      cout<<"printing Postorder Tree traversal "<<endl;
      obj.printPostorder(obj.root);
      break;  
    case 9:
      cout<<"printing in BSF order "<<endl;
      obj.printBFS(obj.root);
      break;    
    case 10:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);
 
  return 0;
}