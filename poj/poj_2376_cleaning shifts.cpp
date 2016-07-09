#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct note
{
	int a;
	int b;
	bool operator < (const note q)
	{
		if (a < q.a)return 1;
		else return 0;
	};
};

int main()
{
	note not1[25001] = {};
	int N, T, n = 0, T1 = 1, state = 0;
	scanf_s("%d%d", &N, &T);
	for (int i = 0; i < N; i++)
		scanf_s("%d%d", &not1[i].a, &not1[i].b);
	sort(not1, not1 + N);//sort
	bool error = 0;
	if (T == 1) {
		if (not1[0].a == 1) {
			n++;
		}
		else error = 1;
	}
	else
		while (T1 <= T)
		{
			int max = 0;
			if (state == N || not1[state].a>T1)
			{
				error = 1;
				break;
			}
			do
			{
				if (not1[state].a > T1)break;
				if (not1[state].b > max)max = not1[state].b;
				state++;
			} while (state<N);
			T1 = max + 1;
			n++;
		}
	if (error)printf_s("-1\n");
	else printf_s("%d\n", n);
	//system("pause");
	return 0;
}