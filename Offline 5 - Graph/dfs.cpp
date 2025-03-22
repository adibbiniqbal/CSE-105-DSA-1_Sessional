#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;
void dfs(int u, vector<list<int>> &adjList, vector<int> &visited)
{
    visited[u] = 1;
    for (int v : adjList[u])
    {
        if (!visited[v])
            dfs(v, adjList, visited);
    }
}
int main()
{
    ifstream ip("input.txt");
    ofstream op("output.txt");
    cin.rdbuf(ip.rdbuf());
    cout.rdbuf(op.rdbuf());
    if (!ip.is_open() || !op.is_open())
    {
        cout << "Could not open input or output file" << endl;
        return 1;
    }
    int n, m;
    cin >> n >> m;
    vector<list<int>> adjList(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<i;
    //     for(auto it=adjList[i].begin();it!=adjList[i].end();it++)
    //     {
    //         cout<<" -> "<<*it;
    //     }
    //     cout<<endl;
    // }
    vector<int> visited(n + 1, 0);
    vector<int> components;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            components.push_back(i);
            dfs(i, adjList, visited);
        }
    }
    int newTunnels = components.size() - 1;
    cout << newTunnels << endl;
    for (int i = 0; i < newTunnels; i++)
    {
        cout << components[i] << " " << components[i + 1] << endl;
    }
    ip.close();
    op.close();
    return 0;
}