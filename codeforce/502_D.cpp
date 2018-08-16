#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int W[15], N, M, Q;
int queries[1<<12], values[1<<12], ans[1<<12][1<<12];

int to_num(char str[]){
	int ans = 0;
	for(int i = 0; i < N ; i++){
		ans <<= 1;
		ans += str[i] - '0';
	}
	return ans;
}

int main(){
	scanf("%d %d %d",&N,&M,&Q);
	for(int i = 0; i < N ; i++)
		scanf("%d",&W[i]);

	for(int i = 0; i < (1<<N) ; i++){
		int num = i, index = 1;
		while(num){
			if (num&1){
				values[i] += W[N-index];	
			}
			index++, num >>=1;
		}
	}

	char tmp[15];
	for(int i = 0; i < M ; i++){
		scanf("%s",tmp);
		queries[to_num(tmp)]++;
	}
	
	for(int i = 0; i < (1<<N) ; i++){
		for(int j = 0; j < (1<<N) ; j++){
			int num = (i^j), index = 1;
			int tmp_num = 0;
			
			for(int index = 0 ; index < N ; index++)
				if(!((1<<index)&num))
					tmp_num += W[N-index-1];	
			ans[i][tmp_num] += queries[j];
		}
		for(int j = 1 ; j < 101 ; j++)
			ans[i][j] += ans[i][j-1];
	}

	for(int i = 0; i < Q ; i++){
		int bound, num;
		scanf("%s",tmp);
		scanf("%d",&bound);
		num = to_num(tmp);
		//cout << ans[num][bound] << endl;
		printf("%d\n",ans[num][bound]);
	}
}
