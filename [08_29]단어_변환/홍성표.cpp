#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int words_size, cnt, target_idx = -1;
vector<bool> visited;
vector<vector<int>> graph;

bool can_change(string left, string right){
    int diff = 0;
    
    for(int i = 0; i < left.length(); i++){
        if(left[i] != right[i])
            diff++;
    }
    
    
    // cout << "left : " << left << " right : " << right << " diff : " << diff << "\n";

    if(diff < 2){
        return true;
    }
    else
        return false;
}

void init_val(string target, vector<string> &words){
    for(int i = 0; i < words.size(); i++){
        if(words[i] == target){
            target_idx = i;
            break;
        }
    }
    
    words_size = words.size();
    visited.resize(words_size, false);
    graph.resize(words_size);
    
    for(int i = 0; i < words_size; i++){
        for(int j = i + 1; j < words_size; j++){
            if(can_change(words[i], words[j])){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
}

void bfs(string begin, vector<string> &words){
    queue<int> q;
    
    // cout << "begin : " << begin << "\n";
    // cout << "target : " << target_idx << "\n";
    for(int i = 0; i < words_size; i++){
        if(can_change(begin, words[i])){
            if(i == target_idx){
                cnt = 1;
                return;
            }
            q.push(i);
            visited[i] = true;
            // cout << i << " ";
        }
    }
    
    while(!q.empty()){
        cnt++;
        int q_size = q.size();
        // cout << "\ncnt : " << cnt << " size : " << q_size << " ";
        
        for(int i = 0; i < q_size; i++){
            
            int front = q.front();
            q.pop();
            cout << words[front] << " ";
            
            for(int j = 0; j < graph[front].size(); j++){
                if(!visited[graph[front][j]]){
                    visited[graph[front][j]] = true;
                    if(graph[front][j] == target_idx){
                        cnt++;
                        cout << "catch\n";
                        return;
                    }
                    q.push(graph[front][j]);
                }
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    
    
    init_val(target, words);
    
    // cout << "words size : " << words_size << "\n";
    // cout << "size : " << words[words_size].size() << "\n";
    
    if(target_idx == -1)
        return 0;
    
    bfs(begin, words);
    
    
    return cnt;
}