#include <iostream>

using namespace std;

#define MAX_N 100005

int zero[MAX_N];
int l[MAX_N];
int r[MAX_N];
int n;

int main(){
        
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    zero[1] = 1;
    l[1] = 1;
    r[1] = 1;
    
    for(int i=2; i<=n; i++){
        zero[i] = ( l[i-1] + zero[i-1] + r[i-1] ) % 9901;
        l[i] = ( zero[i-1] + r[i-1] ) % 9901;
        r[i] = ( l[i-1] + zero[i-1] ) % 9901;
    }
    
    cout << (zero[n] + l[n] + r[n]) % 9901;
    
    return 0;
}

/*
 i칸에 사자 0마리
 i+1칸에 사자 왼쪽 or 오른쪽 or 0마리
 
 i칸에 사자 왼쪽
 i+1칸에 사자 오른쪽 or 0마리
 
 i칸에 사자 오른쪽
 i+1칸에 사자 왼쪽 or 0마리
 */
