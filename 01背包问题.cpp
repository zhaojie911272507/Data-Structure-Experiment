#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn =100;//��Ʒ������
const int maxv=1000; //v������
int w[maxn],c[maxn],dp[maxn];
int main() {
	int n , V;
	scanf("%d %d" ,&n,&V);
	for(int i = 0; i < n ; i++) {
		scanf("%d",&w[i]);
	}
	for(int i = 0; i < n ; i++) {
		scanf("%d",&c[i]);
	}
	//�߽�
	for(int v = 0; v <= V; v++) {
		dp[v]=0;
	}
	for(int i = 1; i <= n; i++) {
		for(int v = V; v>= w[i]; v--) {
			//״̬ת�Ʒ���
			dp[v] = max(dp[v],dp[v-w[i]]+c[i]);
		}
	}
	//Ѱ��dp[0.....V]�����ļ�Ϊ��
	int max=0;
	for(int v = 0; v <= V; v++) {
		if(dp[v]>max) {
			max=dp[v];
		}
	}
	printf("%d\n",max);
	return 0;
}
