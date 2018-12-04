#include <bits/stdc++.h>
using namespace std;

const int mxn = 1.e5;
vector<int> g[mxn];
stack<int> s;
bool in_stack[mxn];
int n, m, loc, cnt;
int index[mxn], lowlink[mxn];
int component[mxn];

void colorful(){
    ofstream color_out("third/color.txt", ios::out | ios::trunc);
    for(int i=0; i<n; i++)
        color_out << component[i] << endl;
}

void dfs(int v)
{
    loc++;
    index[v] = loc;
    lowlink[v] = loc;
    s.push(v);
    in_stack[v] = true;
    for (int j=0; j<g[v].size(); j++)
    {
        int u = g[v][j];
        if (index[u] == 0)
        {
            dfs(u);
            lowlink[v] = min(lowlink[v], lowlink[u]);
        }
        else if (in_stack[u])
            lowlink[v] = min(lowlink[v], index[u]);
    }
    if (lowlink[v] == index[v])
    {
        int u = 0;
        do
        {
            u = s.top();
            s.pop();
            component[u] = cnt;
            in_stack[u] = false;
        }
        while (v != u && !s.empty());
        cnt++;
    }
}

void tarjan()
{
    loc = 0;
    while (!s.empty())
        s.pop();
    for (int i=n; i>0; i--)
        in_stack[i] = lowlink[i] = index[i] = 0;
    cnt = 0;
    for (int i=n; i>0; i--)
        if (index[i] == 0)
            dfs(i);
}

int main()
{
    ofstream vertex_edge("third/n+m.txt", ios::app);
    ofstream graph_out("third/in.txt", ios::out | ios::trunc);
    cin >> n >> m;
    vertex_edge << n+m << '\n';
    for(int i=0, x, y; i<m; i++)
    {
        cin >> x >> y;
        graph_out << x << ' ' << y << '\n';
        g[x].push_back(y);
    }

    ofstream time_out("third/tarjan_time.txt", ios::app);
    clock_t Start = clock();
    tarjan();
    time_out << clock() - Start << '\n';

    colorful();
    return 0;
}

