#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSTRLEN 40 // 用户可在40以内定义最大串长 
typedef char SString[MAXSTRLEN+1]; // 定义字符串变量并且0号单元存放串的长度

//程序主界面

// 生成一个其值等于chars的串T这个函数有点多余在这主要作用就是让用户输入的字符串从第1个单元开始存储好让第0个单元存储字符串的长度
int StrAssign(SString T,char *chars) {
	int i;

	if(strlen(chars) > MAXSTRLEN)
		return 0;
	else {
		T[0] = strlen(chars); // 记录长度,一个一个的拷贝,字符串结束符也拷贝了
		for(i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return 1;
	}
}


void StrPrint(SString T) { // 逐个字符输出字符串T。
	int i;
	for(i=1; i<=T[0]; i++)
		printf("%c,",T[i]);
	printf("\n");
}

int StrLength(SString S) { // 返回串的元素个数
	return S[0];
}
void get_next(SString T,int next[]) {
	int i = 1,j = 0;

	next[1] = 0;
	while(i < T[0])// 一个一个的求解T[0]为模式串的长度
		if(j == 0 || T[i] == T[j]) {
			++i;
			++j;
			next[i]=j;
		} else
			j = next[j];
}

void get_nextval(SString T,int nextval[]) {
	int i = 1,j = 0;
	nextval[1] = 0;
	while(i < T[0])// 一个一个的求解T[0]为模式串的长度
		if(j == 0 || T[i] == T[j]) {
			++i;
			++j;
			if(T[i]!=T[j])
				nextval[i]=j;
			else  nextval[i]=nextval[j];
		} else
			j = nextval[j];
}

int Index_KMP(SString S,SString T,int pos,int nextval[]) {
	int i = pos, // 主串中当前比较的位置
	    j = 1;  // 模式串中当前比较的位置
	while(i <= S[0] && j <= T[0]) {
		if(j == 0 || S[i] == T[j]) { // 当S[i],T[j]匹配时当前位都前移一次继续比较后继字符
			++i;
			++j;
		} else // 模式串向右移动下一次T的当前比较位则为next[j]
			j = nextval[j];
	}
	if(j > T[0])  // 如果j一直加到大于T的长度则证明模式串T中的所有字符都匹配了，所以匹配成功
		return i - T[0];  //此时S的当前比较位i减去T的长度就是匹配时S中的开始位置
	else
		return 0; //T没遍历完所以不成功
}

int main() {
	int i,j,*p,l;
	char m[40],n[40];
	SString s1,s2;
	printf("\t\t\t********************************\t\t\n");
	printf("\t\t\t!    欢迎使用本模式匹配程序    !\n");
	printf("\t\t\t********************************\n\n");
	printf("请输入主串:");
	gets(m);
	StrAssign(s1,m);
	printf("您输入的主串为: ");
	StrPrint(s1);
	printf("\n");
	printf("请输入子串:");
	gets(n);
	StrAssign(s2,n);
	printf("您输入的子串为: ");
	StrPrint(s2);
	printf("\n");
	i=StrLength(s2);
// 生成s2的nextval数组
	p = (int*)malloc((i+1)*sizeof(int));
	get_nextval(s2, p);
	l=strlen(n);
	printf("--------------------------\n");
	printf("\n匹配结果为\n");
	printf("\t\t  j: ");
	for( j=1; j<=l; j++)
		printf("%d ",j);
	printf("\n");
	printf("子串的nextval函数为: ");
	for(j = 1; j <= i; j++)
		printf("%d ",*(p+j));
	printf("\n");
	printf("\n");
	i=StrLength(s2);// 生成s2的next数组

	p = (int*)malloc((i+1)*sizeof(int));
	get_next(s2, p);
	printf("子串的next函数为   : ");
	for(j = 1; j <= i; j++)
		printf("%d ",*(p+j));
	printf("\n");
	printf("\n");
	i = Index_KMP(s1,s2,1,p);
	if(i)
		printf("主串和子串在第%d个字符处首次匹配\n",i);
	else
		printf("主串和子串匹配不成功\n");
	printf("\n");
	return 0;
}

