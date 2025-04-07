#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int i=0; i<t; i++)
    {
        long long int val;
        cin>>val;
        
        if(val == 0)
        {
            if(pq.size()==0)
                cout<<0<<"\n";
            else
            {
                cout<<pq.top()<<"\n";
                pq.pop();
            }
            continue;
        }
        pq.push(val);
    }
    
    
    return 0;
}
