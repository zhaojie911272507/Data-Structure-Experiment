#include<stdio.h>
void test(int x){
	x=1024;
	printf("test函数内部 x=%d\n",x);
}
void test2(int &y){
	y=1024;
	printf("test2函数内部 y=%d\n",y);
}
int main(){
	int x=1;
	printf("调用test前x=%d\n",x);
	test(x);
	printf("调用test后x=%d\n",x);
	printf("\n\n加入引用后：\n");
	int y=1;
	printf("调用test2前y=%d\n",y);
	test2(y);
	printf("调用test2后y=%d\n",y);
	return 0;
}
/*
调用test前x=1
test函数内部 x=1024
调用test后x=1


加入引用后：
调用test2前y=1
test2函数内部 y=1024
调用test2后y=1024
*/
