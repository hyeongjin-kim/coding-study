#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Player {
  int sequence;
  vector<int> play;
};

int N, max_score;
vector<Player> players(9);
vector<bool> base(3, false);

bool compare_fnc(const Player& left, const Player& right) {
  return left.sequence < right.sequence;
}

void input_data() {
  cin >> N;

  for(int i = 0; i < 9; i++) {
    players[i].sequence = i;
  }
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < 9; j++) {
      int play;
      cin >> play;
      players[j].play.push_back(play);
    }
  }
}

int get_next_idx(int player_idx) {
  if (player_idx == 3)
    return 0;
  else if (player_idx == 0)
    return 4;
  else if (player_idx == 8)
    return 1;
  else
    return (player_idx + 1) % 9;
}

void round_end() {
  for(int i = 0; i < 3; i++) {
    if (base[i]) {
      base[i] = false;
    }
  }
}

int hit_1B() {
  vector<bool> temp_base = base;
  int score = 0;
  if(base[2])
    score++;

  // 1칸씩 진루.
  for(int i = 1; i >= 0; i--)
    base[i + 1] = temp_base[i];
  base[0] = true;

  return score;
}

int hit_2B() {
  int score = 0;
  if(base[2])
    score++;
  if(base[1])
    score++;

  // 2칸씩 진루.
  if(base[0])
    base[2] = true;
  else
    base[2] = false;
  base[1] = true;
  base[0] = false;
  return score;
}

int hit_3B() {
  int score = 0;
  if(base[2])
    score++;
  if(base[1])
    score++;
  if(base[0])
    score++;

  // 3칸씩 진루.
  base[2] = true;
  base[1] = false;
  base[0] = false;
  return score;
}

int hit_HR() {
  int score = 1;
  
  for(int i = 0; i < 3; i++) {
    if(base[i])
      score++;
    base[i] = false;
  }
  
  return score;
}

void play_baseball(int round, int score, int out, int player_idx) {
  if (round == N) {
    max_score = max(max_score, score);
    return;
  }

  int play = players[player_idx].play[round];
  int next_idx = get_next_idx(player_idx);

  if (play == 0) {
    out++;
    if (out == 3){
      round_end();
      out = 0;
      play_baseball(round + 1, score, out, next_idx);
    } 
    else 
      play_baseball(round, score, out, next_idx);
  } else if (play == 1) {
    score += hit_1B();
    play_baseball(round, score, out, next_idx);
  } else if (play == 2) {
    score += hit_2B();
    play_baseball(round, score, out, next_idx);
  } else if (play == 3) {
    score += hit_3B();
    play_baseball(round, score, out, next_idx);
  } else if (play == 4) {
    score += hit_HR();
    play_baseball(round, score, out, next_idx);
  }
}

void solution() {
  while(next_permutation(players.begin() + 1, players.end(), compare_fnc)) {
    play_baseball(0, 0, 0, 1);
  }

  cout << max_score;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  input_data();
  solution();

  return 0;
}