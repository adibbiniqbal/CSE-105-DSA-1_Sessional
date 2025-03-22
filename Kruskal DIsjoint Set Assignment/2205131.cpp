#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int wt;
    int u;
    int v;
    Edge(int wt, int u, int v)
    {
        this->wt = wt;
        this->u = u;
        this->v = v;
    }
};
class Graph
{
private:
    vector<Edge> edges;
    int V, E;
    vector<int> parent;
    vector<int> rank;

public:
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
        for (int i = 0; i < V; i++)
        {
            parent.push_back(i);
            rank.push_back(0);
        }
    }
    void addEdge(int wt, int u, int v)
    {
        edges.push_back(Edge(wt, u, v));
    }
    int findParent(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findParent(parent[x]);
    }
    void Union(int u, int v)
    {
        int parentU = findParent(u);
        int parentV = findParent(v);
        if (rank[parentU] == rank[parentV])
        {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
        else if (rank[parentU] > rank[parentV])
        {
            parent[parentV] = parentU;
        }
        else
        {
            parent[parentU] = parentV;
        }
    }
    static bool compare(Edge &a, Edge &b)
    {
        return a.wt < b.wt;
    }
    int kruskal()
    {
        sort(edges.begin(), edges.end(), compare);
        int minCost = 0, count = 0;
        for (int i = 0; i < E && count < V - 1; i++)
        {
            Edge e = edges[i];
            int parentU = findParent(e.u);
            int parentV = findParent(e.v);
            if (parentU != parentV)
            {
                Union(parentU, parentV);
                minCost += e.wt;
                count++;
            }
        }
        return minCost;
    }
};
int main()
{
    ifstream ipFile("input.txt");
    ofstream opFile("output.txt");
    cin.rdbuf(ipFile.rdbuf());
    cout.rdbuf(opFile.rdbuf());
    if (!ipFile.is_open() || !opFile.is_open())
    {
        cout << "Could not open input or output file" << endl;
        return 1;
    }
    int V, E;
    cin >> V >> E;
    Graph graph(V, E);
    while (E--)
    {
        int wt, u, v;
        cin >> wt >> u >> v;
        graph.addEdge(wt, u, v);
    }
    cout << graph.kruskal() << endl;
    ipFile.close();
    opFile.close();
    return 0;
}