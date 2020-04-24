#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int printset(int* set[],int n);
int irreflexive(int a,int b,int n,int* set[]);
int printset(int* set[],int n)
{
    cout<<"Relation: {";
    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(set[i][j]==1)
            {
                cout<<"("<<i<<","<<j<<"),";
            }
        }
    }
    cout<<"}"<<endl;
    return 1;
}
int irreflexive(int a,int b,int n,int* set[])
{
    int count=0;
    if((a==n-1) && (b==n-1))
    count=1;
    if(a<n)
    {
        set[a][b]=0;
        if(b<n-1)
        count=count+irreflexive(a,b+1,n,set);
        else
        count=count+irreflexive(a+1,0,n,set);
        if(a!=b)
        {
            set[a][b]=1;
            if(b<n-1)
            count=count+irreflexive(a,b+1,n,set);
            else
            count=count+irreflexive(a+1,0,n,set);
        }
    }
    return count;
}
int main()
{
    int n,count;
    cout<<"Enter Size of set:";
    cin>>n;
    int* set[n];
    for(int i=0;i<n;i++)
    set[i]=new int[n];
    count=irreflexive(0,0,n,set);
    cout<<"Number of Irreflexive relations: "<<count<<endl;
    return 0;
}
/*
Logic:
Of the n^2 possible combinations all (a,a) have single possible value 0 
i.e (a,a) is not present in relation
for all other combinations 2 possible value 0,1 present/not present
we traverse a complete row from a[i,0] to a[i,n-1] then move on to next row a[i+1,0]
This is done in recursive manner i.e a[i,j] calls a[i,j+1] twice
T(m)=2*T(m-1)  where max value of m is m^2-m
Count is taken while printing set


For n>6 the process takes too much time(But it gives correct value)
*/