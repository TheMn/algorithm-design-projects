#include <bits/stdc++.h>
using namespace std;

const int mxn = 1.e5;
int n, m, cnt;
vector<int> adj[mxn];
bool situ[mxn], mark[mxn];

void show_situ(){
    ofstream color_out("second/color.txt", ios::out | ios::trunc);
    for(int i=0; i<n; i++){
        cout << situ[i];
        if(situ[i])
            color_out << "gold" << '\n';
        else
            color_out << "beige" << '\n';
    }
    cout << '\n';
}

void init_situ(){
    for(int i=0; i<=n; i++)
        situ[i] = 1;
}

bool is_ok = 1;
void update_situ(int i=0){
    if(situ[i] == 1){
        situ[i] = 0;
        cnt--;
        is_ok = 1;
    }
    else{
        situ[i] = 1;
        cnt++;
        update_situ(i+1);
    }
}

void check_situ(int v=0){
    mark[v] = true;
    for(int i=0; i<adj[v].size(); i++){
        int u = adj[v][i];

        if(situ[v] == situ[u] && situ[v])
            is_ok = false;

        if(!mark[u])
            check_situ(u);
    }
}

void fill_false(){
    for(int i=0; i<n; i++)
        mark[i] = 0;
}

int main()
{
    ofstream vertex_out("second/n.txt", ios::app);
    ofstream edge_out("second/m.txt", ios::app);
    ofstream graph_out("second/in.txt", ios::out | ios::trunc);
    cin >> n >> m;
    vertex_out << n << '\n';
    edge_out << m << '\n';
    cnt = n;
    //*
    int x, y;
    for(int i=0; i<m; i++)
    {
        cin >> x >> y;
        graph_out << x << ' ' << y << '\n';
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    //*/
    ofstream time_out("second/time.txt", ios::app);
    clock_t Start = clock();
    init_situ();
    while(situ[n] != 0){
        check_situ();
        if(is_ok){
            cout << "~~ max k=" << cnt << endl;
            show_situ();
            break;
        }
        // cout << "ones: " << cnt << endl;
        // cout << (is_ok ? "yeah\n": "no\n");
        update_situ();
        fill_false();
    }
    time_out << clock() - Start << '\n';
}
