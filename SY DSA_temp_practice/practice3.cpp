#include<iostream>
using namespace std;

int main()
{
    int a[]={-1,9,3,8,-3,-2,4,-2,-6};
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
    int k=0,l=0,i=0;
    while(i<n)
    {
        if(k<m){
            a[i]=b[k];
            i++;
            k++;}
        if(l<p){
            a[i]=c[l];
            i++;
            l++;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}