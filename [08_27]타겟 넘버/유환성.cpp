#include <string>
#include <vector>

using namespace std;

int answer = 0;
vector<int> vect;
void init(vector<int> &numbers){
    for(auto now : numbers){
        vect.push_back(now);
    }
}

void recursion(int total, int idx, int target){
    if(idx == vect.size()){
        if(total == target)answer++;
        return;
    }

    recursion(total+vect[idx], idx+1, target);
    recursion(total-vect[idx], idx+1, target);

}

int solution(vector<int> numbers, int target) {
    init(numbers);
    recursion(0,0, target);
    return answer;
}
