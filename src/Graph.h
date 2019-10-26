#pragma once
#include <vector>
#include <list>
using namespace std;
class Graph{
    int V;
    vector<vector<int>> adj;
public:
    Graph(int V){
        V = V;
        adj = vector<vector<int>>(V, vector<int>()); 
    }
    ~Graph(){;}

    void addEdge(int a, int b){
        adj[a].push_back(b);
    }

    void print(){
        for(int i=0; i<(int)adj.size(); i++){
            vector<int>& v = adj[i];
            for(int j=0; j<(int)v.size(); j++)
                cout << "edge ("<< i <<"->"<<v[j]<<")"<<endl;
        }
    }


    /*
    start from a node, visit all it's siblings before moving to it's children
    */
    void BFS(int s){
        //cout << "printing BFS "<< s <<   endl;

        vector<bool> visited(V, false);
        visited[s] = true;
        list<int> queue;
        queue.push_back(s);

        while(!queue.empty()){
            s = queue.front();
            cout <<"bfs -> "<<  s << " "<<endl;
            queue.pop_front();

            for(int j=0; j<(int)adj[s].size(); j++){
                int idx = adj[s][j];
                //cout << "idx : "<< idx << endl;
                if(!visited[idx]){
                    visited[idx]=true;
                    queue.push_back(idx);

                }
            }
        }
        //cout << endl;
    }
    /*
    start from a node, visit all it's children before moving on to it's siblings 
    */
    void DFSUtil(int s, vector<bool>& visited){
        if(visited[s]) return;
        visited[s] = true; // mark visited
        cout <<"dfs -> "<< s << endl;

        for(int j=0; j<(int)adj[s].size(); j++){
            int idx = adj[s][j];
            DFSUtil(idx, visited);
        }
    }
    void DFS(int s){
        vector<bool> visited(V, false);
        DFSUtil(s, visited);
    }

    static void Run(){
        cout << "Running graph algos "<< endl;
        Graph g(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
        g.print();

        int s = 2;
        cout << "BFS starting from node "<< s <<   endl;
        g.BFS(2);

        cout << "DFS starting from node "<< s <<   endl;
        g.DFS(2);
    }
private:
};
