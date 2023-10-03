#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int NO_EDGE = INT32_MAX / 100;

struct Graph {
    int V;
    vector<vector<int>> adj;
};

vector<int> dijkstra(Graph g, int init_node){
    vector<int> dist(g.V, INT32_MAX);
    dist[init_node] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(0, init_node));
    while(!pq.empty()){
        auto [cost, node] = pq.top();
        pq.pop();
        if(dist[node] < cost) continue;
        for(int i=0; i<g.V; i++){
            if(dist[i] > dist[node] + g.adj[node][i]){
                dist[i] = dist[node] + g.adj[node][i];
                pq.push(make_pair(dist[i], i));
            }
        }
    }
    return dist;
}

int main(){

    vector<vector<int>> gra;

    vector<int> v0{NO_EDGE, 4, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 8, NO_EDGE};
    vector<int> v1{4, NO_EDGE, 8, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 11, NO_EDGE};
    vector<int> v2{NO_EDGE, 8, NO_EDGE, 7, NO_EDGE, 4, NO_EDGE, NO_EDGE, 2};
    vector<int> v3{NO_EDGE, NO_EDGE, 7, NO_EDGE, 9, 14, NO_EDGE, NO_EDGE, NO_EDGE};
    vector<int> v4{NO_EDGE, NO_EDGE, NO_EDGE, 9, NO_EDGE, 10, NO_EDGE, NO_EDGE, NO_EDGE};
    vector<int> v5{NO_EDGE, NO_EDGE, 4, 14, 10, NO_EDGE, 2, NO_EDGE, NO_EDGE};
    vector<int> v6{NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 2, NO_EDGE, 1, 6};
    vector<int> v7{8, 11, NO_EDGE, NO_EDGE, NO_EDGE, NO_EDGE, 1, NO_EDGE, 7};
    vector<int> v8{NO_EDGE, NO_EDGE, 2, NO_EDGE, NO_EDGE, NO_EDGE, 6, 7, NO_EDGE};

    gra.push_back(v0);
    gra.push_back(v1);
    gra.push_back(v2);
    gra.push_back(v3);
    gra.push_back(v4);
    gra.push_back(v5);
    gra.push_back(v6);
    gra.push_back(v7);
    gra.push_back(v8);

    Graph g{9, gra};

    vector<int> res = dijkstra(g, 0);
    for (auto p1 : res)
        cout << p1 << endl;
}