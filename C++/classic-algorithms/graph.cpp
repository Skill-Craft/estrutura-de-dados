#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

const int NO_FRONTIER = -65535;


struct Graph{
    int V;
    int E;
    pair<int,int> ge;
    
    vector<vector<int>> adj;
    
    Graph(pair<int,int> ge){
        
    }

    Graph(vector<vector<int>> adj){
        this->adj = adj;
        // this->ge = ge;
    }

    vector<T>& operator[](int node){
        return adj[node];
    }

    void prim();
    vector<int> kruskal();
    vector<int> dijkstra();
    vector<int> bellman_ford();
    vector<int> floyd_warshall();
    vector<int> ford_fulkerson();
    vector<int> edmonds_karp();
    vector<int> khan();

    private:


};
