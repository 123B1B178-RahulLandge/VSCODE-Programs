#include<iostream>
using namespace std;

int main()
{
    int a[]={-1,4,-5,9,0,3,-2,-3};
    int n=sizeof(a)/sizeof(a[0]);
    int b[n],c[n];
    int m=0,p=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<0){
            b[m]=a[i];
            m++;
        }
        else{
            c[p]=a[i];
            p++;
        }
    }
    int i=0;
    for(int j=0;j<m;j++)
    {
        a[i]=b[j];
        i++;
    }

    for(int j=0;j<p;j++)
    {
        a[i]=c[j];
        i++;
    }

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}