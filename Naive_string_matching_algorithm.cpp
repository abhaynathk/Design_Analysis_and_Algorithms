#include<bits/stdc++.h>
using namespace std;
int main()
{
    int flag=0;
    string s,p;
    cout<<"Enter the string\n";
    cin>>s;
    cout<<"Enter the pattern\n";
    cin>>p;
    int plen=p.length();
    int slen=s.length();

    for(int i=0;i<=slen-plen;i++)
    {

        int j=0;
        while(j<plen&&s[i+j]==p[j])
            j++;
        if(j==plen)
        {
            flag=1;
            cout<<"Match found at "<<i+1<<" position"<<endl;
        }
    }
    if(flag==0)
    {
        cout<<"No Match\n";
    }
    return 0;
}
