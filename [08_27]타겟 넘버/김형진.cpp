#include <string>
#include <vector>

using namespace std;

vector<int> nums; //주어지는 정수를 복사할 벡터
int count = 0; //정답 개수
int tar; //목표 숫자

void recursion(int index, int sum){
    if(index == nums.size()){ //숫자를 끝까지 봤을 때
        count += (tar == sum); //목표 숫자가 만들어졌으면 정답 개수 증가
        return;
    }
    
    sum += nums[index]; //지금 보는 숫자를 더하기
    recursion(index + 1, sum); //다음 숫자 보기
    sum -= 2 * nums[index]; //(더했던 만큼 + 지금 보는 숫자)를 빼기
    recursion(index + 1, sum); //다음 숫자 보기
}


int solution(vector<int> numbers, int target) {
    nums = numbers;
    tar = target;
  
    recursion(0, 0);
    
    int answer =  count;
    return answer;
}
