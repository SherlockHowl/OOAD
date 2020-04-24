#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct process
{
    int i,s;
};
struct schedule
{
    int start,end,i;
    schedule* next;
};
schedule* minimize_waiting(process list[],int n,int waiting_time[]);
schedule* minimize_waiting(process list[],int n,int waiting_time[])
{
    int remaining[n],status=0,t=0,min=INT_MAX,shortest=0,finish_time;
    schedule* hptr=(schedule*)malloc(sizeof(schedule));
    hptr->next=NULL;
    hptr->start=t;
    schedule* tptr=hptr;
    bool flag=true;
    for(int i=0;i<n;i++)
    remaining[i]=list[i].s;
    while(status!=n)
    {
        for(int i=0;i<n;i++)
        {
            if((remaining[i]<min)&&(remaining[i]>0))
            {
                min=remaining[i];
                shortest=i;
                flag=true;
                tptr->end=t;
                if(tptr->next==NULL)
                {
                    tptr->next=(schedule*)malloc(sizeof(schedule));
                    tptr->next->next=NULL;
                }
                tptr->next->start=t;
                tptr->next->i=shortest;
            }
        }
        if(tptr->next!=NULL)
        tptr=tptr->next;
        if(flag==false)
        {
            t++;
            continue;
        }
        remaining[shortest]--;
        min=remaining[shortest];
        if(min==0)
        min=INT_MAX;
        if(remaining[shortest]==0)
        {
            status++;
            flag=false;
            finish_time=t+1;
            waiting_time[shortest]=finish_time-list[shortest].s;
            if(waiting_time[shortest]<0)
            waiting_time[shortest]=0;
            tptr->end=t;
            tptr->i=shortest;
        }
        t++;
    }
    return hptr;
}
int main()
{
    int n=-1;
    int total=0;
    while(n<0)
    {
        cout<<"Enter the no. of tasks:";
        cin>>n;
    }
    process list[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter process "<<i+1<<":\nService Time:";
        cin>>list[i].s;
    }
    int waiting_time[n];
    schedule* hptr=minimize_waiting(list,n,waiting_time);
    cout<<"The waiting time for each process is:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"Process "<<i+1<<": "<<waiting_time[i]<<endl;
        total=waiting_time[i]+total;
    }
    cout<<"With total: "<<total<<endl;
    cout<<"Schedule:"<<endl;
    hptr=hptr->next;
    while(hptr!=NULL)
    {
        cout<<"Process "<<hptr->i+1<<" from "<<hptr->start<<" to"<<hptr->end<<endl;
        hptr=hptr->next;
    }
    return 0;
}
/*
Logic:
The process are scheduled at every time cycle
The process with least service time is chosen
if a process finishes then a new process with least service time is chosen
The above code is based on Question 3 code Please see that for more clarification
Arrival time used in q3 is discarded in this code since its the same for each process

So simply its a sorting of nondecreasing time with selection of least cost;


Code doesnt work if service time is given in negative

*/