//多開一個陣列
//紀錄次數 因此可以用遞推一個一個做
//用 TOP DOWN 時間複雜度太高
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a, b;
	bool dp[100001] = {};
	int  mem[100001] = {};
	while (scanf_s("%d%d", &a, &b),a+b)
	{
		int A[101], C[101];
		for (int i = 0; i < a; i++)
			scanf_s("%d", &A[i]);
		for (int i = 0; i < a; i++)
			scanf_s("%d", &C[i]);

		for (int i = 0; i <= b; i++)
			dp[i] = 0;
		dp[0] = 1;
		for (int j = 0; j < a; j++) {
			for (int i = 0; i <= b-A[j]; i++)
				mem[i] = 0;
			for (int i = 0; i <= b-A[j]; i++)
				if (dp[i] && mem[i] < C[j] && dp[i + A[j]] == 0)// 如果原先可以的 就不用特地讓他多限制
				{
					dp[i + A[j]] = 1;
					mem[i + A[j]] = mem[i] + 1;
				}
		}
		int ans = 0;
		for (int i = 1; i <= b; i++)
			if (dp[i])
				ans++;
		printf_s("%d\n", ans);
	}
}