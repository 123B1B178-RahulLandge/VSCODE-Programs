#include<iostream>
using namespace std;

#define V 5
#define Inf 9999999

class graph{
    int adj[V][V]={};

    public:

    graph(){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                adj[i][j]=Inf;
            }
        }
    }

    void addEdge(int s,int d,int val){
        adj[s][d]=val;
        adj[d][s]=val;
    }

    void dijkstra(int start) {
        int dist[V];        
        bool visited[V];   
    
        for (int i = 0; i < V; i++) {
            dist[i] = Inf;
            visited[i] = false;
        }
    
        dist[start] = 0;
    
        for (int count = 0; count < V - 1; count++) {
            int u = minDistance(dist, visited); 
    
            visited[u] = true;
    
            for (int v = 0; v < V; v++) {
                if (!visited[v] && adj[u][v] && dist[u] != Inf 
                    && dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    
        for (int i = 0; i < V; i++) {
            cout << "Distance from " << start << " to " << i << " is " << dist[i] << endl;
        }
    }

    int minDistance(int dist[], bool visited[]) {
        int min = Inf, min_index;
    
        for (int v = 0; v < V; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v], min_index = v;
            }
        }
        return min_index;
    }
    
    void display(){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph g;

    g.addEdge(0, 1, 10);  
    g.addEdge(0, 2, 3);   
    g.addEdge(1, 2, 1);   
    g.addEdge(1, 3, 2);   
    g.addEdge(2, 3, 8);   
    g.addEdge(2, 4, 2);   
    g.addEdge(3, 4, 7);   

    g.dijkstra(0);

    return 0;
}