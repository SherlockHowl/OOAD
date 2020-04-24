#include<stdio.h>
#include<stdlib.h>
class arr
{
    public:
	int size;
	int a[1000];
};
class node
{
    public:
	int key;
	struct node* lcptr;
	struct node* rcptr;
    void inordertraversal(struct node* ptr);
    node* insert(struct node* parent,int key);
};
arr* pa[100];
node* root=NULL;
int main()
{
	int k,i,j,l,temp;
	int n=0;
	printf("Enter no. of arrays: ");
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		pa[i]=new arr;
		printf("Enter array %d size: ",i+1);
		scanf("%d",&temp);
		if(temp<1)
		pa[i]->size=0;
		else
		{
			pa[i]->size=temp;
			n=n+temp;
		}
		for(j=0;j<(pa[i]->size);j++)
		{
			printf("Element %d-%d: ",i+1,j+1);
			scanf("%d",&temp);
			pa[i]->a[j]=temp;
		}
	}
	int result[n];
	l=0;
	for(i=0;i<k;i++)
	{
		for(j=0;j<(pa[i]->size);j++)
		{
			root=root->insert(root,pa[i]->a[j]);
		}
	}
	root->inordertraversal(root);
}
node* node::insert(struct node* parent,int key)
{
	if(parent==NULL)
	{
		node* temp=new node;
		temp->key=key;
		temp->lcptr=NULL;
		temp->rcptr=NULL;
        return temp;
	}
	else
	{
		if(parent->key<key)
		parent->rcptr=insert(parent->rcptr,key);
		else
		parent->lcptr=insert(parent->lcptr,key);
        return parent;
	}
}
void node::inordertraversal(struct node* ptr)
{
	if(ptr!=NULL)
	{
		inordertraversal(ptr->lcptr);
		printf("%d_",ptr->key);
		inordertraversal(ptr->rcptr);
	}
}