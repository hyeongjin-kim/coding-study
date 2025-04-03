#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string dp[260];
int num;

int main()
{
    // dp[n]=dp[n-1]+[n-2]+[n-2]
    // |이거면 n-1 =랑 ||로 n-2 2개


    dp[0] = "1";//이게 왜 1이야 ??????????????????????????????????????????????????
    //미친 사이코야? 0일떈 0이여야지
    dp[1] = "1";
    dp[2] = "3";
    dp[3] = "5";

    


    for (int i = 4; i < 252; i++) 
    {
        string result;
        int len1 = dp[i - 1].size();
        int len2 = dp[i - 2].size();

        int carry = 0;//올림

        int idx1 = len1 - 1;
        int idx2 = len2 - 1;//0부터 시작

        while (idx1 >= 0 || idx2 >= 0 || carry!=0)
        {
            int digit1 = 0;
            if (idx1 >= 0) {
                digit1 = dp[i - 1][idx1] - '0';
            }

            int digit2 = 0;
            if (idx2 >= 0) {
                digit2 = dp[i - 2][idx2] - '0';
            }

            int sum = digit1 + digit2 * 2 + carry;

            carry = sum / 10;//10으로 나눠야 나머지
            result.push_back((sum % 10) + '0');//스트링으로 저장


            idx1--;
            idx2--;

        }


        reverse(result.begin(), result.end());

        dp[i] = result;
    }

    while (cin >> num) {
        cout << dp[num] << "\n";

    }

    return 0;
}
