#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> alpha[128];

int main() {
	int T;
	cin >> T;
	string str;
	int length;

	//��Ȯ�� K���� �����ϰ� ���� ª�� ���ڿ��� ����
	//���ڿ��� ù ��°�� ������ ���ڰ� �ش� ���ڷ� ���� ���� ��
	// ���� ���ڿ��� ����

	for (int tc = 1; tc <= T; tc++) {
		
		int Min = 100000;
		int Max = 0;

		cin >> str>>length;
		for (int i = 0; i < 128; i++) {
			alpha[i].resize(0);
		}
		//�� ���ĺ� ��ġ �ֱ�
		for (int i = 0; i < str.size(); i++) {
			alpha[str[i]].push_back(i);
		}

		//length���� ������ ���� ª�� ���ڿ��� ���� ���ϱ�
		for (int i = 'a'; i <= 'z'; i++) {
			if (alpha[i].size() < length) continue; //K������ ���ڶ�� pass

			int sum = alpha[i][length - 1] - alpha[i][0]+1;
			if (Min > sum) Min = sum;
			if (Max < sum) Max = sum;

			for (int j = length; j < alpha[i].size(); j++) {
				sum = alpha[i][j] - alpha[i][j-length+1]+1;
				if (Min > sum) Min = sum;
				if (Max < sum) Max = sum;

			}
		}

		if (Min == 100000 || Max == 0) cout << -1 << "\n";
		else cout << Min <<" "<< Max << "\n";
	}
}