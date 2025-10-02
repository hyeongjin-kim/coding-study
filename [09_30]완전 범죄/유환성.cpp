#include <string>
#include <vector>
#include <cstring>
using namespace std;

/*

dp[a][b];
a : 행으로만 이동
b : 열로만 이동


a가 훔칠 때 na = a + info[i][0]; 
b가 훔칠 때 nb = b + info[i][1];

*/
int dp[45][125][125] ={0,};
int solution(vector<vector<int>> info, int n, int m) {
    int answer = -1;
    int size = info.size();
   
    int na,nb;
    //dp[a][b]에 도착했나 안했나 확인하기
    
    dp[0][info[0][0]][0] = true;
    dp[0][0][info[0][1]] = true;
    
    for(int i=0; i<size-1; i++){
        
        for(int a=0; a<n; a++){
           for(int b=0; b<m; b++){
               //없는 흔적 데이터 pass
               if(dp[i][a][b] == false) continue;
               
               int na = a + info[i+1][0];
               int nb = b + info[i+1][1];
               
               // a흔적 누적하기
               dp[i+1][na][b] = true;
               // b흔적 누적하기
               dp[i+1][a][nb] = true;
               
           }   
        }
    }
    
    for(int b=0; b<m;b++){
        for(int a=0; a<n; a++){
            if(dp[size-1][a][b] == true) {
                answer = a;
                break;
            }
        }    
    }
    
    
    return answer;
}
