#include<iostream>
using namespace std;

int main()
{
    int a[]={5,2,0,7,0,0,0,13,89,4,0,0,1,2};
    int n=sizeof(a)/sizeof(a[0]);
    int b[n];
    int m;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            m=i;
            break;
        }
    }
        int j=m+1;
        while(j<n){
            if(a[j]!=0){
            int temp=a[j];
            a[j]=a[m];
            a[m]=temp;
            m++;
            j++;
            }
            else{
                j++;
            }
         }

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
