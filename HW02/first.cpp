#include <bits/stdc++.h>
using namespace std;

const int mxn = 1.e5;
bool mark[mxn];
vector<int> adj[mxn];
set<int> nodes;
int moalefe_cnt;

void bfs(int v)
{
    cout << moalefe_cnt << ": ";
    queue<int> q;
    mark[v] = 1;
    q.push(v);
    while(q.size())
    {
        v = q.front();
        q.pop();
        cout << v << ' ';
        for(int i = 0; i < adj[v].size(); i++)
        {
            int u = adj[v][i];
            if (mark[u] == 1)
                continue;
            mark[u] = 1;
            q.push(u);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        nodes.insert(i);
    for(int i=0; i<m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(set<int>::iterator node = nodes.begin(); node != nodes.end(); ++node)
        if(!mark[*node])
        {
            moalefe_cnt++;
            bfs(*node);
            cout << '\n';
        }
    cout << "~~> te\'dad moalefe = " << moalefe_cnt;
}
