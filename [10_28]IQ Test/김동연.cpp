#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n;
vector<int> list;
vector<pair<int, int>> a_and_b;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		list.push_back(val);
	}

	if (n == 1)
	{
		cout << "A";
		return 0;
	}

	else if (n == 2)
	{
		if (list[0] == list[1])
		{
			cout << list[0];
			return 0;
		}

		else
		{
			cout << "A";
			return 0;
		}
	}

    else
    {
        int x1 = list[0], x2 = list[1], x3 = list[2];

        int denom = (x2 - x1);
        int a, b;

        if (denom == 0)
        {
            for (int i = 1; i < n; ++i)
            {
                if (list[i] != list[0]) 
                { 
                    cout << "B"; return 0; 
                }
            }
            cout << list.back(); // 상수수열 -> 다음 값도 동일
            return 0;
        }

        if ((x3 - x2) % denom != 0)
        {
            cout << "B";
            return 0;
        }

        a = (x3 - x2) / denom;
        b = x2 - x1 * a;

        // 전체 검증
        for (int i = 1; i < n; i++)
        {
            if (list[i] != list[i - 1] * a + b)
            {
                cout << "B";
                return 0;
            }
        }
        // 수열 규칙이 맞으면 다음 수 출력
        cout << list[n - 1] * a + b;
    }

	return 0;
}
