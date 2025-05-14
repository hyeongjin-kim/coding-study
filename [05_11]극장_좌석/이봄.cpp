#include <iostream>

using namespace std;

#define MAX_N 45

int n,m;
int dp[MAX_N][3];
bool vip[MAX_N];

int main(){
    cin >> n;
    cin >> m;
    for(int i=0; i<m; i++){
        int tmp;
        cin >> tmp;
        vip[tmp] = true;
    }
    dp[1][0] = 0; // i-1 사람과 자리 바꾼 경우
    dp[1][1] = 1; // i가 앉은 경우
    if(!(vip[1] || vip[2]))
        dp[1][2] = 1; // i+1 사람과 자리 바꾼 경우

    for(int i=2; i<=n; i++){
        if(vip[i]){
            dp[i][0] = 0;
            dp[i][1] = dp[i-1][0] + dp[i-1][1];
            dp[i][2] = 0;
            continue;
        }
        // 이전 사람이 내 자리 앉은 경우
        dp[i][0] = dp[i-1][2];
        // i가 i 앉은 경우
        dp[i][1] = dp[i-1][0] + dp[i-1][1];
        // i가 i+1 앉은 경우
        if( i+1 <= n && vip[i+1] == false)
            dp[i][2] = dp[i-1][0] + dp[i-1][1];
        else
            dp[i][2] = 0;
    }
    cout << dp[n][0] + dp[n][1];
    return 0;
}
