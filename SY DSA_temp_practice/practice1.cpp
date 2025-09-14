#include<iostream>
using namespace std;

int main()
{
    int a[]={1,1,0,1,0,1,1,0,1,0,0};
    for(int i=1;i<11;i++)
    {
        int j=i-1;
        int val=a[i];
        while(j>=0 && a[j]>val)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=val;
    }

    for(int i=0;i<11;i++)
    {
        cout<<a[i]<<" ";
    }
    
}