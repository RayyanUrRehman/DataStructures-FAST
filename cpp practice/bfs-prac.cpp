#include<iostream>
using namespace std;

#define maxSize 100

class graph
{
    public:
    int adj[maxSize][maxSize];
    int v;

    graph(int ver):v(ver){
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
        int queue[maxSize];
        bool visited[maxSize] = {false};
        int front = 0; int rear = 0;

        //start queue
        queue[rear++] = start;
        visited[start] = true;

        while(front < rear)
        {
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
    cout<<"vertices: ";
    cin>>vertices;
    graph g(vertices);

    int edges;
    cout<<"Edges: ";
    cin>>edges;

    for (int i=0;i<edges;i++){
        int src; int des;
        cin>>src>>des;
        g.addEdge(src,des);
    }

    g.bfs(0);

    return 0;
}