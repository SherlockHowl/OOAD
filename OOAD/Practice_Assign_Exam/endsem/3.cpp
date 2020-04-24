#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct process
{
    int i,s,a;
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
    cout<<"flag1"<<endl;
    while(status!=n)
    {
        for(int i=0;i<n;i++)
        {
            if((list[i].a<=t)&&(remaining[i]<min)&&(remaining[i]>0))
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
            waiting_time[shortest]=finish_time-list[shortest].s-list[shortest].a;
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
        cout<<"Arrival Time:";
        cin>>list[i].a;
        list[i].i=i;
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
    while(hptr!=NULL)
    {
        cout<<"Process "<<hptr->i+1<<" from "<<hptr->start<<" to"<<hptr->end<<endl;
        hptr=hptr->next;
    }
    return 0;
}
/*
Logic:
For(time varying from 0 time cycle to completion of all process)
{
    for all processes who have already arrived
    {
        choose process with least remaining time
        remaining time is the time required to complete the "REST" of process
        since process are assumed to be partially finished and queued
        The schedule is saved whenever a change of process from a to b happens
    }
    if(no process is available)
    {
        Then move on to next time cycle
    }
    if(current process is completed)
    {
        then save the waiting time and free the variables and continue the loop
    }
}

code doesnt work for negative service times
code will give right schedule for negative arrival times but the waiting time value
reported would be wrong only for negative arrival process since it gets -1*-1 positived in line 60
*/