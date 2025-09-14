#include<iostream>
using namespace std;

#define V 4

class node{
    public:
    int adj[V][V];

    node(){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                adj[i][j]=0;
            }
        }
    }

    void addedge(int s,int d){
        adj[s][d]=1;
        adj[d][s]=1;
    }

    void BFS(int start){
        bool visited[V]={false};
        int queue[V];
        int front=0,rear=0;

        queue[rear]=start;
        rear++;
        visited[start]=true;
        
        while(front<rear){
            int node=queue[front];
            cout<<node<<" ";
            front++;

            for(int i=0;i<V;i++){
                if(adj[node][i]==1 && !visited[i]){
                    queue[rear]=i;
                    rear++;
                    visited[i]=true;
                }
            }  
        }
    }
};

int main(){
    node n;

    n.addedge(0,1);
    n.addedge(0,2);
    n.addedge(1,2);
    n.addedge(1,3);

    n.BFS(0);

    return 0;
}