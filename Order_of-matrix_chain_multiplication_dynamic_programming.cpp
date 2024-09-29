#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of matrices\n";
    cin>> n;
    int r[n+1];
    cout<<"Enter the dimension of matrices (size "<<n+1<<" array)\n";
    for(int i=0;i<=n;i++)
    {
        cin>>r[i];
    }
    int dp[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
                dp[i][j]=0;}

    }
    for(int diag=2;diag<=n;diag++)
    {
        for(int i=0;i<=n-diag;i++)
        {
            int j= i+diag-1;
            int minVal= INT_MAX;
            for(int k=i;k<j;k++)
            {
                int q=dp[i][k]+dp[k+1][j]+r[i]*r[k+1]*r[j+1];
                if(q<minVal){
                    minVal=q;
                }
            }
            dp[i][j]=minVal;
        }
    }
    cout<<"Minimum Number of scalar multiplication is : "<<dp[0][n-1]<<endl;
    cout<<"DP Table:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
