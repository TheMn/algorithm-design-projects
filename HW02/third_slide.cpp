#include <bits/stdc++.h>
using namespace std;

int n, m;
const int mxn=1.e5;
vector<int> g[mxn];
vector<int> bg[mxn];
int comps;
short used[mxn];
bool its_out[mxn];

void bfs(int v)
{
    queue<int> q;
    used[v]++;
    q.push(v);
    while(q.size())
    {
        v = q.front();
        q.pop();
        for(int i = 0; i < g[v].size(); i++)
        {
            int u = g[v][i];
            if (used[u] >= 1)
                continue;
            used[u]++;
            q.push(u);
        }
    }
}

void sfb(int v)
{
    queue<int> q;
    used[v]++;
    q.push(v);
    while(q.size())
    {
        v = q.front();
        q.pop();
        for(int i = 0; i < bg[v].size(); i++)
        {
            int u = bg[v][i];
            if(used[u] != 1)
                continue;
            used[u]++;
            q.push(u);
        }
    }
}

void show_used(){
    for(int i=0; i<n; i++)
        cout << used[i];
    cout << endl;
}

int main()
{
    cin >> n >> m;
    for(int i=0, a, b; i<m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        bg[b].push_back(a);
    }

    ofstream time_out("third/slide_time.txt", ios::app);
    clock_t Start = clock();

    for(int i=0; i<n; i++){
        if(its_out[i])
            continue;
        bfs(i);
        sfb(i);
        for(int j=0; j<n; j++){
            if(used[j] >= 2){
                its_out[j] = true;
                cout << j << ' ';
            }
        }
        fill(used, used+n, 0);
        cout << '\n';
    }
    time_out << clock() - Start << '\n';
    return 0;
}
