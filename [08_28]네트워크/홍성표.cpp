#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<bool> visited;
int cnt;

void bfs(int st, vector<vector<int>> &nodes){
    queue<int> q;
    q.push(st);
    // cout <<"st node : " << st << "\n";
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        if(visited[front])
            continue;
        
        visited[front] = true;
        for(int i = 0; i < nodes[front].size(); i++){
            if(nodes[front][i] && !visited[i]){
                // cout << "front : " << front << " push : " << i << "\n";
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    visited.resize(computers.size(), false);
    
    for(int i = 0; i < computers.size(); i++){
        if(visited[i] == false){
            cnt++;
            bfs(i, computers);
        }
    }
    
    return cnt;
}