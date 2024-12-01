#include<iostream>
using namespace std;

#define maxSize 20

class graph
{
    public:
    int v;
    int adj[maxSize][maxSize];

    graph(int ver)
    {
        v = ver;
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                adj[i][j] = 0;
            }
        }
    }
    

    void addEdge(int src, int des)
    {
        adj[src][des] = 1;
        adj[des][src] = 1;
    }


    void dfsUtil(int start, bool visited[])
    {
        visited[start] = true;

        for (int i=0;i<v;i++){
            if(adj[start][i]==1 && visited[i]==false){
                visited[i] = true;
                cout<<"Visited: "<<i<<endl;
                dfsUtil(i,visited);
            }
        }
    }

    void dfs(int start)
    {
        bool visited[maxSize] = {false};
    
        dfsUtil(start, visited);
        
        
    }
};




int main()
{
    int vertex;
    int edge;
    cout<<"Vertex: ";
    cin>>vertex;
    cout<<"Edges: ";
    cin>>edge;

    graph g(vertex);

    cout<<"enter src & des: ";
    for (int i=0;i<edge;i++){
        int src; int des;
        cin>>src>>des;
        g.addEdge(src,des);
    }

    int start;
    cout<<"start: ";
    cin>>start;

    g.dfs(start);

    //test case
    //input 5 6 0 1 0 2 1 3 1 4 2 4 3 0 0
    //output 0 1 3 4 2

    return 0;

}