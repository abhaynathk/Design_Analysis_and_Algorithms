#include<bits/stdc++.h>
using namespace std;
int chess[20][20];
bool found=false;
int n;
bool is_safe(int row,int col)
{
    //checking the left side of the same row
    for(int j=col;j>=0;j--)
    {
        if(chess[row][j]==1)
            return false;
    }
    //check  upper diagonal on the left side
    for(int i=row,j=col;i>=0&& j>=0;i--,j--)
    {
        if(chess[i][j]==1)
            return false;
    }
    //check lower left diagonal
    for(int i=row,j=col;i<n&&j>=0;i++,j--)
    {
        if(chess[i][j]==1)
            return false;
    }
    return true;
}
void print()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(chess[i][j]==1){
                cout<<"Q\t";}
            else
            {
            cout<<"-\t";}
        }
        cout<<endl;

    }
    cout<<"########################################"<<endl;
}
void solve(int col)
{
    if(col==n)
    {
        found =true;
        print();
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(is_safe(i,col))
        {
            chess[i][col]=1;
            solve(col+1);
            chess[i][col]=0;
        }
    }
    return;
}
int main()
{

    cout<<"Enter the size if chess board (n)\n";
    cin>>n;
    memset(chess,0,sizeof(chess));
    solve(0);
    if(!found)
        cout<<"Not able to place Queens";
    return 0;
}
