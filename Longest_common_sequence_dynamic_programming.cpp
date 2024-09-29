#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cout<<"Enter the first string  ";
    cin>>s1;
    cout<<"Enter the the second String  ";
    cin>>s2;
    int m=s1.size();
    int n=s2.size();
    int dp[m+1][n+1],seq[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            dp[i][j]=0;
            seq[i][j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {

        for(int j=1;j<=n;j++)
        {
            if(s1.at(i-1)==s2.at(j-1))
            {
                dp[i][j]=1+dp[i-1][j-1];
                seq[i][j]=3;
            }
            else
            {
                int top=dp[i-1][j];
                int left=dp[i][j-1];
                dp[i][j]=(top>left)?top:left;
                seq[i][j]=(top>left)?2:1;
            }
        }
    }
    int last=seq[m][n];
    string result="";
    int i=m,j=n;
    while(i!=0&&j!=0)
    {
        if(last==3)
        {
            result+=s1.at(i-1);
            i--;
            j--;
        }
        else if(last==2)
        {
            i--;
        }
        else if(last==1)
        {
            j--;
        }
        last=seq[i][j];
    }
    reverse(result.begin(),result.end());
    cout<<"Length of common subsequence: "<<dp[m][n]<<endl;
    cout<<"Longest common subsequence: "<<result<<endl;
    return 0;


}
