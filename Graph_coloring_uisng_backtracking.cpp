#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int adj[20][20];
int color[20];
bool issafe(int v, int c)
{
    for(int i=0;i<n;i++)
    {
        if(adj[v][i]==1 && color[i]==c)
        {
            return false;
        }

    }
    return true;
}

bool solve(int v)
{
    if(v==n)
    {
        return true;
    }
    for(int i=1;i<=m;i++)
    {
        if(issafe(v,i))
        {
            color[v]=i;
            if(solve(v+1)==true)
                return true;
            color[v]=0;
        }
    }
    return false;
}
void print()
{
    for(int i=0;i<n;i++)

    {
        cout<<"vertex "<<i<<" is colored with "<<color[i]<<endl;
    }
}
int main()
{
    cout<<"Enter the number of vertices \n";
    cin>>n;
    cout<<"Enter the number of colors \n";
    cin>>m;
    cout<<"Enter adjacency matrix\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>adj[i][j];
        }
    }
    if(solve(0)==false)
        cout<<"Unambe to color the graph with "<<m<< " colores"<<endl;
    else
        print();
    return 0;
}








