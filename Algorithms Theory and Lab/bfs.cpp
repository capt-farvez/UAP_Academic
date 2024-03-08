#include<bits/stdc++.h>
using namespace std;


vector<int>bsfofgraph(int v, vector<int>adj[]){
    queue<int>q;
    vector<int>bfs;
    int vis[v+1]= {0};
    int x; cin >> x;
    q.push(x);
    vis[x] = 1;
    while(!q.empty()){
        int u = q.front();
        for(int i = 0; i < adj[u].size(); i++){
            if(vis[adj[u][i]] == 0){
                vis[adj[u][i]] = 1;
                q.push(adj[u][i]);
            }
        }
        q.pop();
        bfs.push_back(u);
    }
    return bfs;
}


int main()
{
    int v, e; cin >> v >> e;
    vector<int>adj[v+1];
    for(int i = 0; i < e; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int>bfs = bsfofgraph(v, adj);
    for(auto &x : bfs){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}