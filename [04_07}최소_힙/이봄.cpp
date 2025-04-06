#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
priority_queue<long long,vector<long long>,greater<long long> > pq;
vector<long long> vec;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        long long x;
        cin >> x;
        if(x == 0){
            if(pq.empty())
                vec.push_back(0);
            else{
                vec.push_back(pq.top());
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }
    
    for(int i=0; i<vec.size(); i++)
        cout << vec[i] <<"\n";
    return 0;
}
