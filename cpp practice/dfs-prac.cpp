#include <iostream>
using namespace std;

#define maxv 100

class graph
{
    public:
    int v;
    int adj[maxv][maxv];

    graph(int ver)
    {
        v = ver;
        for (int i=0;i<v;i++){
            for (int j=0;j<v;j++){
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int des)
    {
        adj[src][des] = 1;
        adj[des][src] = 1;
    }

    void dfsUtil(int vertex, int visited[])
    {
        visited[vertex] = true;
        cout<<vertex<<" ";

        for (int i=0;i<v;i++){
            if (adj[vertex][i]==1 && visited[i]==false){
                dfsUtil(i,visited);
            }
        }
    }

    void dfs(int start)
    {
        int visited[maxv] = {false};
        // cout<<"Starting vertex: "<<start;

        dfsUtil(start,visited);  

    }

};




int main()
{
    int vertices;
    int edges;
    cout<<"Enter vertex and edges: ";
    cin>>vertices>>edges;

    graph g(vertices);

    cout<<"Enter src-des: "<<endl;
    int src; int des;
    for (int i=0;i<edges;i++){
        cin>>src>>des;
        g.addEdge(src,des);
    }   

    int start;
    cout<<"Starting vertex for dfs: ";
    cin>>start;
    g.dfs(start);


    return 0;


}
