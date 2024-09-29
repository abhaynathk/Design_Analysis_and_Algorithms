#include<bits/stdc++.h>
using namespace std;

typedef struct job{
char id;
int dead,profit;
}task;
int main()
{

    task a[]={{'a',2,50},{'b',1,9},{'c',2,17},{'d',1,15},{'e',3,5}};
    int n=sizeof(a)/sizeof(a[0]);

    for(int i=0; i<n-1;i++){
        int max=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j].profit>a[max].profit)
                max=j;
        }
        task temp=a[max];
        a[max]=a[i];
        a[i]=temp;
    }
    bool selected[n]={false};
    bool slot[n+1]={false};
    for(int i=0;i<n;i++)
    {
        for(int j=a[i].dead;j>=1;j--)
        {

            if(slot[j]==false)
            {
                slot[j]=true;
                selected[i]=true;
                break;
            }
        }
    }
    int total=0;
    for(int i=0;i<n;i++)
    {

        if(selected[i])

        {
            cout<<"Job "<<a[i].id<<" is selected\n";
            total=total+a[i].profit;
        }
    }
    cout<<"Total= "<<total;
}

