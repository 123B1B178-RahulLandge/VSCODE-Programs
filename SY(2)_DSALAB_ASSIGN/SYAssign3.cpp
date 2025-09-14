#include <iostream>
using namespace std;

class Node {
private:
    static const int MAX_NODES = 25;
    int adj[MAX_NODES][MAX_NODES];
    int v;

public:

    Node(int size){
        v=size;
        for (int i = 0; i < MAX_NODES; i++) {
            for (int j = 0; j < MAX_NODES; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int s, int d) {
        adj[s][d] = 1;
        adj[d][s] = 1;
    }

    void BFS(int start) {
        int visited[MAX_NODES] = {0};
        int queue[MAX_NODES];
        int front = 0, rear = 0;

        visited[start] = 1;
        queue[rear] = start;
        rear++;

        while (front < rear) {
            int node = queue[front];
            front++;
            cout << node << " ";

            for (int i = 0; i < v; i++) {
                if (adj[node][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    queue[rear] = i;
                    rear++;
                }
            }
        }
    }
};

int main() {
    Node n(16);
    
    n.addEdge(0, 1); 
    n.addEdge(1, 2);  
    n.addEdge(2, 3); 
    n.addEdge(3, 7); 
    n.addEdge(7, 11);
    n.addEdge(11, 10);
    n.addEdge(10, 6); 
    n.addEdge(6, 2);  
    n.addEdge(6, 5);
    n.addEdge(5, 9);  
    n.addEdge(9, 13); 
    n.addEdge(13, 14);
    n.addEdge(14, 15);
    
    
    cout << "Path is: \n";
    n.BFS(0);
    
    return 0;
}