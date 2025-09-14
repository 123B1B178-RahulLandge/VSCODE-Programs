#include<iostream>
using namespace std;

int main(){
    int a[]={5, 8, 9, 3, 5, 7, 1, 3, 4, 9, 3, 5, 1, 8, 4};
    int b[]={3, 5, 7, 2};
    int n1=sizeof(a)/sizeof(a[0]);
    int n=sizeof(b)/sizeof(b[0]);
    int c[n1],d[n1],k=0,m=0;

    for(int i=1;i<n1;i++)
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

    cout<<"\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n1;j++){
            if(b[i]==a[j]){
                c[k]=a[j];
                a[j]=0;
                k++;
            }
        }
    }
    
    for(int i=0;i<n1;i++){
        if(a[i]!=0){
            c[k]=a[i];
            k++;
        }
    }
    for(int i=0;i<k;i++){
        cout<<c[i]<<" ";
    }
}