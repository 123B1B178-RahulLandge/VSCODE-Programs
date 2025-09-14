#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int x[n],y[m],u[n],v[m],collision_count=0;
    bool red[n]={false},blue[m]={false};

    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>u[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>y[i]>>v[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if(red[i] || blue[j]){
                if (x[i] * v[j] == y[j] * u[i]) {
                collision_count++;
                    red[i]=true;
                    blue[j]=true;
                }
            }
            
        }
    }
    cout<<collision_count;
    return 0;
}