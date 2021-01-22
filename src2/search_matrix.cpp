#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;



void search_dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& seen, vector<vector<int>>& directions){
    if(row < 0) return;
    if(col < 0) return;
    if(row >= 3) return;
    if(col >= 4) return;
    if(seen[row][col] != 0) return;
    seen[row][col] = 1;
    cout << matrix[row][col]<<", ";
    for(auto dir : directions)
        search_dfs(matrix, row+dir[0], col+dir[1], seen, directions);
}

void search_bfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& seen, vector<vector<int>>& directions){
    queue<vector<int>> queue;
    queue.push({0,0});

    while(!queue.empty()){
        int n = queue.size();
        for(int i=0; i<n; i++){
            vector<int> current = queue.front();
            queue.pop();
            int row = current[0];
            int col = current[1];
            if(row < 0) continue;
            if(col < 0) continue;
            if(row >= 3) continue;
            if(col >= 4) continue;
            if(seen[row][col] != 0) continue;
            seen[row][col] = 1;
            cout << matrix[row][col]<<", ";
            for(auto dir : directions)
                queue.push({row+dir[0], col+dir[1]});
    
        }

    }
}


int main(){
    vector<vector<int>> directions{ {-1,0}, {0, 1}, {1, 0}, {0, -1}};

    vector<vector<int>> matrix{{0,1,2,3}, {4,5,6,7}, {8,9,10,11}};

    vector<vector<int>> seen1{{0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
    cout << "DFS "; search_dfs(matrix, 0, 0, seen1, directions); cout << endl;
    vector<vector<int>> seen2{{0,0,0,0}, {0,0,0,0}, {0,0,0,0}};
    cout << "BFS "; search_bfs(matrix, 0, 0, seen2, directions); cout << endl;


    return 0;
}
