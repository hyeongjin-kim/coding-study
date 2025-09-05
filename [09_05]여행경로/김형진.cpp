#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

unordered_map<int, multiset<int>> city_set; //같은 경로가 여러개 일 수 있으므로 중복 허용
unordered_map<string, int> city_index; //도시를 인덱스로 바꿔주는 map
stack<int> route; //현재 탐색중인 경로

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    string citys[10000];
    int city_count = 0;
    for(vector<string> path : tickets){ //도시를 배열에 중복없이 담음
        for(string city: path){
            if(city_index[city] == 0){
                city_index[city] = 1;
                citys[city_count] = city;
                city_count++;
            }
        }
    }
    sort(citys, citys + city_count); //이름 순으로 정렬
    
    for(int i = 0; i < city_count; i++){ //정렬된 대로 인덱스 기록
        city_index[citys[i]] = i;
    }
    for(vector<string> path : tickets){ //인덱스로 간선 추가
        city_set[city_index[path[0]]].insert(city_index[path[1]]);
    }
    
    route.push(city_index["ICN"]); //시작점
    
    vector<int> path;
    
    while(!route.empty()){ //탐색할 경로가 없을 때까지
        int cur = route.top();
        //현재 경로에서 더이상 탐색할 곳이 없다
        // => 여기가 종결점 만약 이게 두군데이상이라면 한붓그리기가 불가능!!
        //따라서 미리 경로의 끝에 저장하면 이미 본 곳을 다시 볼 필요가 없음
        if(city_set[cur].empty()){
            path.push_back(cur);
            route.pop();
        }
        else{ //갈 수 있는 곳이 있으면 제일 앞에꺼를 골라가면 됨
            auto itr = city_set[cur].begin();
            int next = *itr;
            city_set[cur].erase(itr);
            route.push(next);
        }
    }
    
    reverse(path.begin(), path.end()); //경로를 정방향으로 돌리기
    
    for(int i : path) answer.push_back(citys[i]); //string으로 변환
    
    return answer;
}
