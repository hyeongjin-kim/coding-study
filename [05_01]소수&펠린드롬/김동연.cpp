#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int primelist[1000000];
vector <string> pd;

int main()
{
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int num;
    cin>>num;
    
    primelist[0]=2;
    primelist[1]=3;
    
    int k =2;
    
    for(int i=4; i<=1003001; i++)//1000000
    {
        if(i % 2==0) continue;
        
        int val = i;
        int cnt = 0;
        
        for(int j=2; j<=sqrt(i); j++)
        {
            if(val % j == 0)
            {
                cnt++;
                break;
            }
        }
        
        if(cnt == 0)
        {
            primelist[k] = i;
            k++;
        }
    }
    ///소수 구하는 로직
    
    for(int i = 0; i < k; i++)
    {
        if(primelist[i] < num) continue;
        
        string val= to_string(primelist[i]);
        int len = val.size();
        int flag = 0;

        for(int j = 0; j < len/2 ; j++)
        {
            if(val[j] != val[len-j-1])
            {
                flag = 1;
                break;
            }
        }
        
        if(flag == 0)
            pd.push_back(val);
    }
    
    cout<<pd[0];

    return 0;
}
