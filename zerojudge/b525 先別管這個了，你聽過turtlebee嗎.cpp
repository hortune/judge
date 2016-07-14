#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL prime =100000007;
struct matrix
{
	LL value[2][2];
}I,I2;
matrix multiply(matrix &a, matrix &b)
{
	matrix c;
	c.value[0][0]=a.value[0][0]*b.value[0][0]+a.value[1][0]*b.value[0][1];
	c.value[1][0]=a.value[0][0]*b.value[1][0]+a.value[1][0]*b.value[1][1];
	c.value[0][1]=a.value[0][1]*b.value[0][0]+a.value[1][1]*b.value[0][1];
	c.value[1][1]=a.value[0][1]*b.value[1][0]+a.value[1][1]*b.value[1][1];
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			c.value[i][j]%= 100000007;
	return c;
}
matrix fast_multiply(int m)
{
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			I2.value[i][j]=I.value[i][j];
	matrix ans;
	ans.value[0][0]=1;
	ans.value[1][1]=1;
	ans.value[0][1]=0;
	ans.value[1][0]=0;
	while(m)
	{
		if(m&1)
			ans=multiply(ans,I2);
		I2=multiply(I2,I2);
		m>>=1;
	}
	return ans;
}
int main()
{
	I.value[0][0]=1;
	I.value[0][1]=1;
	I.value[1][0]=1;
	I.value[1][1]=0;
	int m,f,k;
	ios::sync_with_stdio(false);
	while(cin>>m>>f>>k)
	{
		matrix temp=fast_multiply(k);
		LL ans=f*temp.value[0][0]+m*temp.value[0][1]+f*temp.value[1][0]+m*temp.value[1][1];
		ans%=prime;
		cout<<ans<<endl;
	}
}


