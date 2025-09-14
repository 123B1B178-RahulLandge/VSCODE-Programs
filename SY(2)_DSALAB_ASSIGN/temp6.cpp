#include<iostream>
using namespace std;

#define V 4
#define Max 9999999

class node{
    public:
    int adj[V][V];

    node(){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                adj[i][j]=Max;
            }
        }
    }

    void addedge(int s,int d,int val){
        adj[s][d]=val;
        adj[d][s]=val;
    }

    void Prims(int start){
        bool visited[V]={false};
        int totalCost=0;
        int row,col;
        int no_edge=0;

        visited[start]=true;

        while(no_edge < V-1){
            int min=Max;
            row=0;
            col=0;

            for(int i=0;i<V;i++){
                if(visited[i]){
                    for(int j=0;j<V;j++){
                        if(visited[j]==false && adj[i][j]!=Max && adj[i][j]<=min){
                            min=adj[i][j];
                            row=i;
                            col=j;
                        }
                    }
                }
            }
            cout<<row<<" - "<<col<<" : "<<adj[row][col]<<endl;
            visited[col]=true;
            totalCost+=adj[row][col];
            no_edge++;
        }

        cout<<"Total Cost is: "<<totalCost;
    }
};

int main(){
    node n;

    n.addedge(0,1,1);
    n.addedge(0,2,5);
    n.addedge(1,2,2);
    n.addedge(1,3,3);

    n.Prims(0);
    cout<<endl;

    return 0;
}