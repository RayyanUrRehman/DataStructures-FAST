#include <iostream>
using namespace std;

#define Max_vertex 100

class graph
{
    public:
    int v;
    int adj[Max_vertex][Max_vertex];

    graph(int ver){
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

    void bfs(int start)
    {
        int queue[Max_vertex];
        int visited[Max_vertex] = {false};
        int front = 0; int rear = 0;

        queue[rear++] = start;
        visited[start] = true;

        cout<<"Starting vertex is: "<<start<<endl;

        while(front < rear){
            int current = queue[front++];
            cout<<current<<" ";

            for (int i=0;i<v;i++){
                if (adj[current][i]==1 && visited[i]==false){
                    visited[i] = true;
                    queue[rear++] = i;
                }    
                
            }
        }

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
    cout<<"Starting vertex for bfs: ";
    cin>>start;
    g.bfs(start);


    return 0;
}
