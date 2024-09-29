#include<iostream>
using namespace std;
#define n 5
int adj[n][n]={ {0,1,1,1,1},{1,0,1,1,1},{1,1,0,1,0},{1,1,1,0,1},{1,1,0,1,0} };
int color[n];
applycolor(int v)
{

    int used[n];
    int i;
    for(i=0;i<n;i++)
    {
        used[i]=0;
    }
    for(i=0;i<n;i++)
    {
        if(adj[v][i]==1&&color[i]!=-1)
            used[color[i]]=1;

    }
    for(i=0;i<n;i++)
    {
        if(used[i]==0)
        {

            color[v]=i;
            break;
        }
    }
}

int main()
{
    for(int i=0;i<n;i++)
    {

        color[i]=-1;
    }
    color[0]=0;
    for(int i=1;i<n;i++)
    {
        applycolor(i);
    }
    for(int i=0;i<n;i++){
    cout <<"Vertex "<<i<<" colored with color  "<<color[i]<<"\n";}
    return 0;
}
