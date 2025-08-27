#include <string>
#include <vector>

using namespace std;

int parent[200];

int find(int a){
    if(a == parent[a])
        return a;
    return parent[a] = find(parent[a]);
}

void Union(int a, int b){
    int rootA = find(a);
    int rootB = find(b);
    if(rootA == rootB)
        return;
    parent[rootA] = rootB;
}

int solution(int n, vector<vector<int>> computers) {
    for(int i=0;i<n;++i)
        parent[i] = i;
    for(int i=0;i<n;++i)
        for(int j=0;j<i;++j)
            if(computers[i][j])
                Union(i,j);


    int answer = 0;
    for(int i=0;i<n;++i)
        if(parent[i]==i)
            ++answer;
    return answer;
}
