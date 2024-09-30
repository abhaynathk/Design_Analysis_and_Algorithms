#include<bits/stdc++.h>
using namespace std;
void calcLPS(string p,int LPS[])
{

    LPS[0]=0;
    int i=0,j=1;
    while(j<p.length())
    {
        if(p[i]==p[j])
        {
            LPS[j]=1+i;
            i++;
            j++;
        }
        else{
            if(i==0)
            {
                LPS[j]=0;
                j++;
            }
            else
            {
                i=LPS[i-1];
            }
        }
    }
}
int main()
{

    string s,p;
    cout<<"Enter the string\n";
    cin>>s;
    cout<<"Enter the pattern\n";
    cin>>p;
    int plen=p.length();
    int slen=s.length();

    int LPS[plen];
    calcLPS(p,LPS);
    int i=0,j=0;
    //KMP Search Algorithm

    while(i<slen)
    {
        if(p[j]==s[i])
        {
            i++;
            j++;
        }
        if(j==plen)
        {
            cout<<(i-plen)<<" is the index\n";
            j=LPS[j-1];
        }
        else if(i<slen&&p[j]!=s[i])
        {
            if(j==0)
            {
                i++;
            }
            else{
                j=LPS[j-1];
            }

        }
    }
    return 0;
}
