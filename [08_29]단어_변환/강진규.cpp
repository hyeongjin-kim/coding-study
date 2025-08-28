#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_set<char> charPool[10];
unordered_set<string> wordPool;
unordered_map<string, bool> vis;

int solution(string begin, string target, vector<string> words) {
    bool contains = false;
    for(string word: words){
        for(int i=0;i<word.length();++i){
            charPool[i].insert(word[i]);
        }
        if(word == target)
            contains = true;
        wordPool.insert(word);
        vis[word] = false;
    }
    if(!contains)
        return 0;
    
    queue<pair<string,int>> q;
    q.push({begin, 0});
    vis[begin] = true;
    while(!q.empty()){
        string cur = q.front().first;
        int curCnt = q.front().second;
        q.pop();
        if(cur==target)
            return curCnt;
        
        for(int i=0;i<cur.length();++i){
            for(char letter : charPool[i]){
                string next = cur;
                next[i] = letter;
                if(wordPool.find(next) == wordPool.end()) continue;
                if(vis[next]) continue;
                vis[next] = true;
                q.push({next, curCnt + 1});
            }
        }
    }
    return 0;
}
