#include <iostream>
#include <climits>

#define MAX_NM 10

using namespace std;

int n,m;
int arr[MAX_NM][MAX_NM];
int dp[MAX_NM][MAX_NM][3];

// 같은 방향으로 2번 연속으로 움직일 수 없다.
int main(){
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }
    
    // dp[n][m][0] 좌하 방향으로 갈 애들..그니까 하, 우하 방향에서만 와야함
    // dp[n][m][1] 하 방향
    // dp[n][m][2] 우하 방향
    
    // dp 배열 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<3; k++){
                dp[i][j][k] = INT_MAX; // 처음에 arr 값의 최댓값인 105로 했다가 틀림 앗콩~ 
            }
        }
    }
    for(int i=0; i<m; i++){
        dp[0][i][0] = arr[0][i];
        dp[0][i][1] = arr[0][i];
        dp[0][i][2] = arr[0][i];
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            // 좌하
            dp[i][j][0] = min(dp[i][j][0], dp[i-1][j][1] + arr[i][j]); //하
            if(j-1 >= 0)
                dp[i][j][0] = min(dp[i][j][0], dp[i-1][j-1][2] + arr[i][j]); // 우하
            
            //하
            if(j+1 < m)
                dp[i][j][1] = min(dp[i][j][1], dp[i-1][j+1][0] + arr[i][j]); // 좌하
            if(j-1 >=0)
                dp[i][j][1] = min(dp[i][j][1], dp[i-1][j-1][2] + arr[i][j]); // 우하
            
            // 우하
            if(j+1 < m)
                dp[i][j][2] = min(dp[i][j][2], dp[i-1][j+1][0] + arr[i][j]); // 좌하
            dp[i][j][2] = min(dp[i][j][2], dp[i-1][j][1] + arr[i][j]);
            //cout <<"i : " << i <<" j : " << j <<"\n";
            //cout << dp[i][j][0] <<" " << dp[i][j][1] <<" " << dp[i][j][2] <<"\n";
        }
        //cout <<"\n";
    }
    
    int ans = INT_MAX;
    for(int j=0; j<m; j++){
        for(int k=0; k<3; k++){
            ans = min(ans, dp[n-1][j][k]);
        }
    }

    cout << ans ;
    return 0;
}
