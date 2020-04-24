#include<iostream>
#include<bits/stdc++.h>
using namespace std;
float Fact[31];
float P[31];
float p[31];
float fact(int i);
float calc_P(int i);
void calc_p(int i);
float Value();
float fact(int i)
{
    if(i==0)
    {
        Fact[i]=1;
        return Fact[i];
    }
    else
    {
        Fact[i]=i*fact(i-1);
        return Fact[i];
    }
}
float calc_P(int i)
{
    if(i==0)
    {
        P[0]=1;
        return P[0];
    }
    float temp=1/Fact[i];
    if(i%2==1)
    temp=(-1)*temp;
    P[i]=calc_P(i-1)+temp;
    return P[i];
}
void calc_p()
{
    for(int i=0;i<31;i++)
    {
        p[i]=P[30-i]/Fact[i];
    }
}
float Value()
{
    float value=0;
    for(int i=0;i<31;i++)
    value=value+(i*p[i]);
    return value/30;
}
int main()
{
    fact(30);
    calc_P(30);
    calc_p();
    int value=Value();
    cout<<"Expected Value: "<<value<<endl;
    for (int i = 0; i < 31; i++)
    {
        cout<<p[i]<<endl;
    }
    
}
/*
Logic 
probability that no number matches for n numbers
P[n]= 1 -1/(1!) +1/(2!) -1/(3!) +...+((-1)^n)/n!
P[n] saves the value for all nos. from 0 to 30
p[i] saves the probability of geting exactly i hits out of 30
p[i]=P[30-i]/Fact[i]
Expected value=sumation i*p[i];

p[i]
gets distorted
*/