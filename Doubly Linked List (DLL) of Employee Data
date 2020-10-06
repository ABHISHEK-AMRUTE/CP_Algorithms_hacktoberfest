#include<stdio.h>
#include<conio.h>
int MAX=4, count;
struct emp
{
int ssn;
char name[20];
char dept[10];
char desig[15];
int sal;
char phno[10];
struct emp *left;
struct emp *right;
};
typedef struct emp NODE;
int countnodes(NODE *head)
{
NODE *p;
count=0;
p=head;
while(p!=NULL)
{
p=p->right;
count++;
}
return count;
}
NODE* getnode(NODE *head)
{
NODE *newnode;
newnode=(NODE*)malloc(sizeof(NODE));
newnode->right=newnode->left=NULL;
printf("\nEnter SSN, Name, Dept, Designation, Sal, Ph.No\n");
scanf("%d",&newnode->ssn);
flushall();
gets(newnode->name);
flushall(); 
gets(newnode->dept);
flushall();
gets(newnode->desig);
scanf("%d",&newnode->sal);
flushall();
 gets(newnode->phno);
head=newnode;
return head;
}
NODE* display(NODE *head)
{
NODE *p;
if(head==NULL)
printf("\nNo Employee data\n");
else
{
p=head;
printf("\n----EMPLOYEE DATA----\n");
printf("\nSSN\tNAME\tDEPT\tDESINGATION\tSAL\t\tPh.NO.");
while(p!=NULL)
{
printf("\n%d\t%s\t%s\t%s\t\t%d\t\t%s", p->ssn, p->name, p->dept, p->desig,
p->sal, p->phno);
p = p->right; 
}
printf("\nThe no. of nodes in list is: %d",countnodes(head));
}
return head;
}
NODE* create(NODE *head)
{
NODE *p, *newnode;
p=head;
if(head==NULL)
{
newnode=getnode(head);
head=newnode;
}
else
{
newnode=getnode(head);
while(p->right!=NULL)
{
p=p->right;
}
p->right=newnode;
newnode->left=p;
}
return head;
}
NODE* insert_end(NODE *head)
{
if(countnodes(head)==MAX)
printf("\nList is Full!!");
else
head=create(head);
return head;
}
NODE* insert_front(NODE *head)
{
NODE *p, *newnode;
if(countnodes(head)==MAX)
printf("\nList is Full!!");
else
{
if(head==NULL)
{
newnode=getnode(head);
head=newnode; 
}
else
{
}
}
return head;
}
newnode=getnode(head);
newnode->right=head;
head->left=newnode;
head=newnode;
NODE* insert(NODE *head)
{
int ch;
do
{
printf("\n 1.Insert at Front(First) \t 2.Insert at End(Rear/Last)\t3.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch(ch)
{
case 1: head=insert_front(head); break;
case 2: head=insert_end(head); break;
case 3: break;
}
head=display(head);
}while(ch!=3);
return head;
}
NODE* delete_front(NODE *head)
{
NODE *p;
if(head==NULL)
printf("\nList is Empty (QUEUE)");
else
{
p=head;
head=head->right;
head->right->left=NULL;
free(p);
printf("\nFront(first)node is deleted");
}
return head;
}
NODE* delete_end(NODE *head)
{
NODE *p, *q;
p=head;
while(p->right!=NULL)
{
p=p->right; 
}
q=p->left;
q->right=NULL;
p->left=NULL;
free(p);
printf("\nLast(end) entry is deleted");
return head;
}
NODE *del(NODE *head)
{
int ch;
do {
printf("\n1.Delete from Front(First)\t2. Delete from End(Rear/Last))\t3.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch(ch)
{
case 1: head=delete_front(head);
break;
case 2: head=delete_end(head);
break;
case 3: break;
}
head=display(head);
}while(ch!=3);
return head;
}
NODE* queue(NODE *head)
{
int ch, ch1, ch2;
do
{
printf("\nDLL used as Double Ended Queue");
printf("\n1.QUEUE- Insert at Rear & Delete from Front");
printf("\n2.QUEUE- Insert at Front & Delete from Rear");
printf("\n3.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch(ch)
{
case 1: do{
printf("\n1.Insert at Rear\t2.Delete from From Front\t3.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch1);
switch(ch1)
{
case 1: head=insert_end(head); break;
case 2: head=delete_front(head); break;
case 3: break;
}
}while(ch1!=3);
break;
case 2: do{
printf("\n1.Insert at Front\t2.Delete from Rear\t3.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch2);
switch(ch2)
{
case 1: head=insert_front(head); break;
case 2: head=delete_end(head); break;
case 3: break;
}
}while(ch2!=3);
break;
case 3: break;
}
}while(ch!=3);
head=display(head);
return head;
}
void main()
{
int ch, i, n;
NODE *head;
head=NULL;
clrscr();
printf("\n----------Employee Database-----------");
do
{
printf("\n1.Create\t2.Display\t3.Insert\t4.Delete\t5.Queue\t6.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch(ch)
{
case 1: printf("\nHow many employees data you want to create: ");
scanf("%d", &n);
for(i=0;i<n;i++)
head=create(head);
break;
case 2: head=display(head); 
break;
case 3: head=insert(head); 
break;
case 4: head=del(head); 
break;
case 5: head=queue(head);
break;
case 6: exit(0); 
break;
}
}while(ch!=6);
}
