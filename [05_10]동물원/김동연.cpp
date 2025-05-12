#include <iostream>
using namespace std;
int dp[100001]={1,3};

int main()
{
    //1,3,7,17,41 ---- n-1*2+n-2
    int N;
    cin>>N;
    
    for(int i=2;i<=N;i++)
    {
        dp[i]=(dp[i-1]*2+dp[i-2])%9901;
    }
    
    cout<<dp[N];
    
    return 0;
}
