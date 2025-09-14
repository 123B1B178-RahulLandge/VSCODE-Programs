#include<iostream>
using namespace std;

void insertion(int arr[],int n){
    for(int i=0;i<n;i++){
        int j=i-1;
        int val=arr[i];
        while(j>=0 && arr[j]>val){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=val;
    }
}

void shell(int arr[],int n)
{
    int gap=n/2;
    while(gap>=1){
        for(int j=gap;j<n;j++){
            for(int i=j-gap;i>=0;i=i-gap){
                if(arr[i+gap]>arr[i]){
                    break;
                }
                else{
                    int temp;
                    temp=arr[i];
                    arr[i]=arr[i+gap];
                    arr[i+gap]=temp;
                }
            }
        }
        gap=gap/2;    
    }
    
}


void qs(int arr[],int f,int l){
    if(f<l)
    {
        int pivot=f;
        int i=f+1;
        int j=l;
        while(i<=j)
        {
            while(arr[i]<arr[pivot]){
                i++;
            }
            while(arr[j]>arr[pivot]){
                j--;
            }
            if(i<j){
                int t;
                t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
        int temp=arr[j];
        arr[j]=arr[pivot];
        arr[pivot]=temp;
        qs(arr,f,j-1);
        qs(arr,j+1,l);
    }
}

void merge(int arr[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int L[n1],R[n2];

    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[m+j+1];
    }
    int x=0,y=0,k=l;
    while(x<n1 && y<n2){
        if(L[x]<R[y]){
            arr[k]=L[x];
            k++;
            x++;
        }else{
            arr[k]=R[y];
            k++;
            y++;
        }
    }

    while(x<n1){
        arr[k]=L[x];
        x++;
        k++;
    }

    while(y<n2){
        arr[k]=R[y];
        y++;
        k++;
    }
}

void merge_sort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int main(){
    int arr[]={2,76,32,85,89};
    int n=sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<",";
    }
    return 0;
}