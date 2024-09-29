#include<bits/stdc++.h>
#include<stack>
using namespace std;
bool found =false;
stack<int> stck;
void print()
{
    stack<int> temp;
    while(!stck.empty())
    {
        temp.push(stck.top());
        stck.pop();
    }
    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        stck.push(temp.top());
        temp.pop();
    }
    cout<<endl;


}
void solve(int currsum,int ind,int n,int target,int a[])
{
    if(currsum>target){
        return;}
    if(currsum==target)
    {
        found=true;
        print();
        return;
    }
    for(int i=ind;i<n;i++)
    {
        stck.push(a[i]);
        solve(currsum+a[i],i+1,n,target,a);
        stck.pop();
    }
}
int main()
{
    int n ,target;
    cout<<"Enter the number of elements ";
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array ";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the target sum: ";
    cin>>target;
    solve(0,0,n,target,a);
    if(!found)
    {
        cout<<"No Solution"<<endl;

    }
    return 0;

}
