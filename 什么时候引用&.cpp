#include<stdio.h>
void test(int x){
	x=1024;
	printf("test�����ڲ� x=%d\n",x);
}
void test2(int &y){
	y=1024;
	printf("test2�����ڲ� y=%d\n",y);
}
int main(){
	int x=1;
	printf("����testǰx=%d\n",x);
	test(x);
	printf("����test��x=%d\n",x);
	printf("\n\n�������ú�\n");
	int y=1;
	printf("����test2ǰy=%d\n",y);
	test2(y);
	printf("����test2��y=%d\n",y);
	return 0;
}
/*
����testǰx=1
test�����ڲ� x=1024
����test��x=1


�������ú�
����test2ǰy=1
test2�����ڲ� y=1024
����test2��y=1024
*/
