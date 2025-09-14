#include<iostream>
using namespace std;


#define V 4

class node{
    public:

    int count=0;
    int adj[V][V];
    int parent[V];
    int edge1[V],edge2[V],weight[V];

    node(){
        for(int i=0;i<V;i++){
            parent[i]=i;
            for(int j=0;j<V;j++){
                adj[i][j]=0;
            }
        }
    }

    void addedge(int s,int d,int w){
        adj[s][d]=w;
        adj[d][s]=w;
        edge1[count]=s;
        edge2[count]=d;
        weight[count]=w;
        count++;
    }

    int findparent(int a){
        return parent[a];
    }

    bool unionset(int a,int b){
        int x = findparent(a);
        int y = findparent(b);

        if(x==y) return false;

        return true;
    }

    void kruskal(){
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                if(weight[i]>weight[j]){
                    int temp=weight[i];
                    weight[i]=weight[j];
                    weight[j]=temp;
                    int temp1=edge1[i];
                    edge1[i]=edge1[j];
                    edge1[j]=temp1;
                    int temp2=edge2[i];
                    edge2[i]=edge2[j];
                    edge2[j]=temp2;
                }
            }
        }

        for(int i=0;i<V;i++){
            cout<<edge1[i]<<" - "<<edge2[i]<<" : " <<weight[i]<<endl;
        }

        cout<<"MST is:"<<endl;

        bool visited[V]={false};
        int totalCost=0;

        for(int i=0;i<count;i++){
            if(!visited[edge1[i]] || !visited[edge2[i]]){
                if(parent[edge1[i]]==parent[edge2[i]]) continue;
                cout<<edge1[i]<<" - "<<edge2[i]<<" : "<<weight[i]<<endl;
                parent[edge2[i]]=edge1[i];
                visited[edge1[i]]=true;
                visited[edge2[i]]=true;
                totalCost+=weight[i];
            }
        }

        cout<<"TotalCost is : "<<totalCost;
        
    }
};

int main(){
    node n;
    n.addedge(0,1,1);
    n.addedge(0,2,5);
    n.addedge(1,3,3);
    n.addedge(1,2,2);

    n.kruskal();
    return 0;
};