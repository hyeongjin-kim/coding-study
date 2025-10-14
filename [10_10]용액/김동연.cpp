#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int arr[100000];
int t;

int main()
{
    scanf("%d", &t);
    
    for(int i =0; i<t ; i++)
        scanf("%d", &arr[i]);
    
    sort(arr,arr+t);
    int s = 0;
    int e = t - 1;
    int m = 21e8;
    pair<int,int>res ={0,0};
    for(;;)
    {
        if(s >= e || e <= s) break;
        
        int p1 = arr[s];
        int p2 = arr[e];
        int sum = abs(p1 + p2);
        //cout<<sum <<" "<<m<<"\n";

        
        if(sum <= m)
        {
            if(p1 + p2<0)
            {
                m = sum;
                res={s,e};
                s++;
            }
            if(p1 + p2>=0)
            {
                m = sum;
                res={s,e};
                e--;
            }

        }
            
        if(sum > m)
        {
            if(p1 + p2<0)
            {
                s++;
            }
            if(p1 + p2>=0)
            {
                e--;
            }
        }
    }
    
    cout<<arr[res.first]<<" "<<arr[res.second];
    
    return 0;
}
