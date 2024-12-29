#include<iostream>
using namespace std;

class node
{
    public:
    int vertex;
    node* next;

    node(int v, node* n){
        vertex = v;
        next = n;
    }
};

class graph
{
    public:
    node** adj;
    int v;

    graph(int ver)
    {
        v = ver;
        adj = new node*[ver];
        for (int i=0;i<v;i++){
            adj[i] = nullptr;
        }
    }

    void addEdge(int src, int des)
    {
         
    }
};  



int main()
{

    return 0;
}