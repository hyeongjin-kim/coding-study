#include <string>
#include <vector>

using namespace std;

vector<bool> calc;
int targ;
int answ;

void dfs(int depth, vector<int>& numbers){
    if(depth==numbers.size()){
        int ans = 0;
        for(int i=0;i<depth;++i){
            if(calc[i])
                ans += numbers[i];
            else
                ans -= numbers[i];
        }
        if(ans==targ)
            ++answ;
        return;
    }
    calc.push_back(true);
    dfs(depth+1, numbers);
    calc.pop_back();

    calc.push_back(false);
    dfs(depth+1, numbers);
    calc.pop_back();
}

int solution(vector<int> numbers, int target) {
    targ = target;
    answ = 0;
    dfs(0, numbers);
    return answ;
}
