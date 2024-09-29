#include<bits/stdc++.h>
using namespace std;
int karat(int a, int b)
{

    string as=to_string(a);
    string bs=to_string(b);
    int alen=as.length();
    int blen=bs.length();
    if(alen==1&&blen==1)
    {

        return a*b;
    }
    int n=alen>blen?alen:blen;
    while(alen!=n)
    {
        as="0"+as;
        alen=as.length();

    }
    while(blen!=n)
    {
        bs="0"+bs;
        blen=bs.length();
    }
    int aL=stoi(as.substr(0,n/2));
    int aR=stoi(as.substr(n/2,n-(n/2)));
    int bL=stoi(bs.substr(0,n/2));
    int bR=stoi(bs.substr(n/2,n-(n/2)));
    int x1=karat(aL,bL);
    int x2=karat(aL+aR,bL+bR);
    int x3=karat(aR,bR);
    int m=ceil(n/2.0);
    int prod= x1*pow(10,2*m)+(x2-x1-x3)*pow(10,m)+x3;
    return prod;
}
int main()
{

    cout<<"Give input\n ";
    cout<<"First Integer ";
    int a;
    cin>>a;
    cout<<"Second Integer ";
    int b;
    cin>>b;
    cout<<"Answer= "<<karat(a,b);
    return 0;


}
