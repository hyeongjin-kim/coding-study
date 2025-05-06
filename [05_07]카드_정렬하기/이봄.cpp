#include <iostream>
#include <queue>

using namespace std;

#define MAX_N 100005

int n;
int card_size[MAX_N];
priority_queue<int,vector<int>, greater<>> pq;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    int ans = 0;
    
    while(pq.empty() == false){
        int a = pq.top();
        pq.pop();
        if(pq.empty() == true)
            break;
        int b = pq.top();
        pq.pop();
        //cout << a <<" " << b <<"\n";
        ans += (a+b);
        pq.push(a+b);
    }
    
    cout << ans;
    
    return 0;
}

