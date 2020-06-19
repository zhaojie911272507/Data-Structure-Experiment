#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSTRLEN 40 // �û�����40���ڶ�����󴮳� 
typedef char SString[MAXSTRLEN+1]; // �����ַ�������������0�ŵ�Ԫ��Ŵ��ĳ���

//����������

// ����һ����ֵ����chars�Ĵ�T����������е���઩������Ҫ���þ������û�������ַ����ӵ�1����Ԫ��ʼ�洢�����õ�0����Ԫ�洢�ַ����ĳ���
int StrAssign(SString T,char *chars) {
	int i;

	if(strlen(chars) > MAXSTRLEN)
		return 0;
	else {
		T[0] = strlen(chars); // ��¼����,һ��һ���Ŀ���,�ַ���������Ҳ������
		for(i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);
		return 1;
	}
}


void StrPrint(SString T) { // ����ַ�����ַ���T��
	int i;
	for(i=1; i<=T[0]; i++)
		printf("%c,",T[i]);
	printf("\n");
}

int StrLength(SString S) { // ���ش���Ԫ�ظ���
	return S[0];
}
void get_next(SString T,int next[]) {
	int i = 1,j = 0;

	next[1] = 0;
	while(i < T[0])// һ��һ������⪩T[0]Ϊģʽ���ĳ���
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
	while(i < T[0])// һ��һ������⪩T[0]Ϊģʽ���ĳ���
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
	int i = pos, // �����е�ǰ�Ƚϵ�λ��
	    j = 1;  // ģʽ���е�ǰ�Ƚϵ�λ��
	while(i <= S[0] && j <= T[0]) {
		if(j == 0 || S[i] == T[j]) { // ��S[i],T[j]ƥ��ʱ����ǰλ��ǰ��һ�μ����ȽϺ���ַ�
			++i;
			++j;
		} else // ģʽ�������ƶ�����һ��T�ĵ�ǰ�Ƚ�λ��Ϊnext[j]
			j = nextval[j];
	}
	if(j > T[0])  // ���jһֱ�ӵ�����T�ĳ��Ȫ���֤��ģʽ��T�е������ַ���ƥ���ˣ�����ƥ��ɹ�
		return i - T[0];  //��ʱS�ĵ�ǰ�Ƚ�λi��ȥT�ĳ��Ȫ�����ƥ��ʱS�еĿ�ʼλ��
	else
		return 0; //Tû�����ꪩ���Բ��ɹ�
}

int main() {
	int i,j,*p,l;
	char m[40],n[40];
	SString s1,s2;
	printf("\t\t\t********************************\t\t\n");
	printf("\t\t\t!    ��ӭʹ�ñ�ģʽƥ�����    !\n");
	printf("\t\t\t********************************\n\n");
	printf("����������:");
	gets(m);
	StrAssign(s1,m);
	printf("�����������Ϊ: ");
	StrPrint(s1);
	printf("\n");
	printf("�������Ӵ�:");
	gets(n);
	StrAssign(s2,n);
	printf("��������Ӵ�Ϊ: ");
	StrPrint(s2);
	printf("\n");
	i=StrLength(s2);
// ����s2��nextval����
	p = (int*)malloc((i+1)*sizeof(int));
	get_nextval(s2, p);
	l=strlen(n);
	printf("--------------------------\n");
	printf("\nƥ����Ϊ��\n");
	printf("\t\t  j: ");
	for( j=1; j<=l; j++)
		printf("%d ",j);
	printf("\n");
	printf("�Ӵ���nextval����Ϊ: ");
	for(j = 1; j <= i; j++)
		printf("%d ",*(p+j));
	printf("\n");
	printf("\n");
	i=StrLength(s2);// ����s2��next����

	p = (int*)malloc((i+1)*sizeof(int));
	get_next(s2, p);
	printf("�Ӵ���next����Ϊ   : ");
	for(j = 1; j <= i; j++)
		printf("%d ",*(p+j));
	printf("\n");
	printf("\n");
	i = Index_KMP(s1,s2,1,p);
	if(i)
		printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n",i);
	else
		printf("�������Ӵ�ƥ�䲻�ɹ�\n");
	printf("\n");
	return 0;
}

