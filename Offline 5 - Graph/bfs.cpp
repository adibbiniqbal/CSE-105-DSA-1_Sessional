#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
void bfs(int u, vector<vector<int>> &adjMat, vector<int> &visited)
{
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (visited[u])
            continue;
        visited[u] = 1;
        for (int v = 1; v < adjMat[u].size(); v++)
        {
            if (adjMat[u][v] == 1)
                q.push(v);
        }
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
    vector<vector<int>> adjMat(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = adjMat[v][u] = 1;
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<adjMat[i][j]<<" ";
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
            bfs(i, adjMat, visited);
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