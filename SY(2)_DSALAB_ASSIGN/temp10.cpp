#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define V 5
#define Max 99999

class node{
    public:
    int adj[V][V];

    void addEdge(int s,int d){
        adj[s][d]=1;
        adj[d][s]=1;
    }

    void DFS(int start){
        bool visited[V]={false};
        stack<int>s;

        s.push(start);
        visited[start]=true;

        while(!s.empty()){
            int node=s.top();
            s.pop();

            cout<<node<<" ";

            for(int i=0;i<V;i++){
                if(!visited[i] && adj[node][i]==1){
                    s.push(i);
                    visited[i]=true;
                }
            }
        }
    }
};

int main() {
    node g;
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    cout << "DFS traversal starting from node 0:" << endl;
    g.DFS(0);  

    return 0;
}