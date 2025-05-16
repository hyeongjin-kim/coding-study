#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Seat{
  int y;
  int x;
  int empty;
  int like;
  
  Seat(int y, int x, int empty, int like) : y(y), x(x), empty(empty), like(like) {}
  
  bool operator<(const Seat& right) const {
    // 자리 선택.
    // 1. 좋아하는 학생이 많은 자리.
    if(like < right.like) return true;
    else if(like > right.like) return false;
    // 2. 인접한 자리 중 비어있는 곳이 많은 자리.
    else if(empty < right.empty) return true;
    else if(empty > right.empty) return false;
    // 3. 행 -> 열 순으로 작은 자리.
    else if(y > right.y) return true;
    else if(y < right.y) return false;
    else if(x > right.x) return true;
    else if(x < right.x) return false;
    else return false;
  }
};

int N, satisfaction;
int satisfy[5] = {0, 1, 10, 100, 1000}; 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<vector<int>> student;
vector<vector<int>> student_idx;
vector<vector<int>> map;

void input_data(){
  cin >> N;
  student.resize(N*N, vector<int>(5));
  student_idx.resize(N*N + 1);
  map.resize(N, vector<int>(N, 0));

  int target;
  int likes[4];
  for(int i=0; i<N*N; i++){
    for(int j=0; j<5; j++)
      cin >> student[i][j];
    for(int j=1; j<5; j++)
      student_idx[student[i][0]].push_back(student[i][j]);
  }
}

bool is_like_student(int me, int target) {
  for(int i=1; i<5; i++){
    if(student[me][i] == target)
      return true;
  }
  return false;
}

bool is_like_student_idx(int me, int target) {
  for(int i=0; i<4; i++){
    if(student_idx[me][i] == target)
      return true;
  }
  return false;
}

void seat_student(int idx){
  priority_queue<Seat> pq;

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      // 이미 자리에 학생이 앉아있으면 continue
      if(map[i][j] != 0) continue;

      Seat seat(i, j, 0, 0);
      for(int d = 0; d < 4; d++){
        int ny = i + dy[d];
        int nx = j + dx[d];

        // 범위 체크
        if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

        // 인접한 자리가 비어있는 지 체크
        if(map[ny][nx] == 0)
          seat.empty++;
        // 비어있는 자리가 아니면 좋아하는 학생인지 체크
        else if(is_like_student(idx, map[ny][nx]))
          seat.like++;
      }
      pq.push(seat);
    }
  }

  Seat top = pq.top();
  map[top.y][top.x] = student[idx][0];
  // cout << "학생 : " << student[idx][0] << " 자리 : " << top.y << " " << top.x << " " << "비어있는 자리 : " << top.empty << " 좋아하는 학생 : " << top.like << endl;
  return;
}

void seat_students(){
  for(int i=0; i<N*N; i++){
    seat_student(i);
  }

  // cout << "학생 자리 배치" << endl;
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++){
  //     cout << map[i][j] << " ";
  //   }
  //   cout << endl;
  // }
}

int count_like_student(int i, int j){
  int cnt = 0;
  for(int d = 0; d < 4; d++){
    int ny = i + dy[d];
    int nx = j + dx[d];

    // 범위 체크
    if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

    // 인접한 자리가 비어있는 지 체크
    if(is_like_student_idx(map[i][j], map[ny][nx]))
      cnt++;
  }
  return cnt;
};
void calculate_satisfaction(){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      int like_cnt = count_like_student(i, j);

      // cout << "학생 : " << map[i][j] << " 좋아하는 학생 수 : " << like_cnt << endl;
      // 만족도 계산
      satisfaction += satisfy[like_cnt];
    }
  }
}


// 시간 복잡도 : O(N^4), 
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  input_data();
  seat_students();
  calculate_satisfaction();

  // 결과 출력
  cout << satisfaction;

  return 0;
}