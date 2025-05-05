#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>


using namespace std;
priority_queue <int,vector<int>,greater<int>> numlist;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int num;
    cin>>num;
    
    for(int i = 0; i < num; i++)
    {
        int val;
        cin>>val;
        
        numlist.push(val);
    }
    
    int sum=0;
    
    while(1)
    {
        if(numlist.size() == 1)
        {
            cout<<sum;
            return 0;
        }
        
        int min1 = numlist.top();
        //cout<<min1<<" ";
        numlist.pop();
        int min2 = numlist.top();
        //cout<<min2<<"\n";
        numlist.pop();
        
        sum+=min1+min2;
        
        numlist.push(min1+min2);
        
    }
}
