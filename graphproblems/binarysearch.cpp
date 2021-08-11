#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int flag = 0;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        int x ;
        cin>>x;
        arr[i] = x;
    }

    int target;
    cin>>target;

    for(int i=0;i<n;i++)
    {
        if(arr[i] == target)
        {cout<<"Element is found"; flag = 1;}
    }

    if(flag == 0)
    {cout<<"Element not found";}
  
    

}