#include<stdio.h>
#include<stdlib.h>
struct arr
{
	int size;
	int a[1000];
};
struct node
{
	int key;
	struct node* lcptr;
	struct node* rcptr;
};
struct arr* pa[100];
struct node* root=NULL;
struct node* insert(struct node* parent,int key);
void inordertraversal(struct node* ptr);
void main()
{
	int k,i,j,l,temp;
	int n=0;
	printf("Enter no. of arrays: ");
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		pa[i]=malloc(sizeof(struct arr));
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
			root=insert(root,pa[i]->a[j]);
		}
	}
	inordertraversal(root);
}
struct node* insert(struct node* parent,int key)
{
	if(parent==NULL)
	{
		struct node* temp=malloc(sizeof(struct node));
		temp->key=key;
		temp->lcptr=NULL;
		temp->rcptr=NULL;
	}
	else
	{
		if(parent->key<key)
		parent->rcptr=insert(parent->rcptr,key);
		else
		parent->lcptr=insert(parent->lcptr,key);
	}
}
void inordertraversal(struct node* ptr)
{
	if(ptr!=NULL)
	{
		inordertraversal(ptr->lcptr);
		printf("%d_",ptr->key);
		inordertraversal(ptr->rcptr);
	}
}
