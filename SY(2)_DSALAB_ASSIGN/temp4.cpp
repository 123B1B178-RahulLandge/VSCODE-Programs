#include <iostream>
#include <stack>

using namespace std;

#define V 6

class Graph {
    int adj[V][V]; 

public:
    Graph() {
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                adj[i][j]=0;
            }
        }
    }

    void addEdge(int v, int w) {
        adj[v][w] = 1;
        adj[w][v] = 1; 
    }

    void DFS(int start) {
        bool visited[V];
        stack<int> s;
        
        s.push(start);
        visited[start] = true;
        
        while (!s.empty()) {
            int v = s.top();
            s.pop();
            cout << v << " ";
            
            for (int i = V - 1; i >= 0; i--) { 
                if (adj[v][i] == 1 && !visited[i]) {
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    
    cout << "Depth First Traversal (starting from vertex 0): ";
    g.DFS(0);
    cout << endl;
    
    return 0;
}
int vertices;
int arr[5][5];

void DFS(int start){
    int visited[vertices]={0};
    int stack[vertices];
    int top=-1;
    visited[start]=1;
    stack[++top]=start;
    while(top>=0){
         int node=stack[top];
         top--;
         cout<<node<<" ";
         for(int i=0;i<vertices;i++){
              if(arr[node][i]==1&&visited[i]==0){
              visited[i]=1;
              stack[++top]=i;
             }
         }
      }
      cout<<endl;
}