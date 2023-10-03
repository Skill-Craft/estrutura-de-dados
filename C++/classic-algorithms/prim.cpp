#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

const int NO_EDGE = INT32_MIN;

struct Graph {
    int V;
    vector<vector<int>> adj;
    
    vector<int>& operator[](int node){
        return adj[node];
    }
};

vector<pair<int,int>> get_frontier(Graph g, vector<int> visited_nodes){
    vector<pair<int, int>> frontier;
    for(auto node: visited_nodes){
        for(auto it=g.adj.at(node).begin(); it!=g.adj.at(node).end(); it++){
            if (*it != NO_EDGE && find(visited_nodes.begin(), visited_nodes.end(), distance(g.adj.at(node).begin(), it)) == visited_nodes.end())
                frontier.push_back(make_pair(node, distance(g.adj.at(node).begin(), it)));
        }
    }
    return frontier;
}

vector<pair<int,int>> prim_algorithm(Graph g, int starter_node){
    vector<int> visited_nodes{starter_node};
    vector<pair<int,int>> res;
    while(visited_nodes.size() != g.V){
        vector<pair<int, int>> frontier = get_frontier(g, visited_nodes);
        int node_append, cost= INT32_MAX, node_in;
        for(auto [node, frontier_node]: frontier){
            if(g.adj.at(node).at(frontier_node) < cost){
                cost = g.adj.at(node).at(frontier_node);
                node_append = frontier_node;
                node_in = node;
            }
        }
        visited_nodes.push_back(node_append);
        res.push_back(make_pair(node_in, node_append));
    }
    return res;
};

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
    
    Graph g {9, gra};
    vector<pair<int, int>> res = prim_algorithm(g, 0);
    for(auto [p1, p2]: res)
        cout << p1 << " " << p2 << endl;
}