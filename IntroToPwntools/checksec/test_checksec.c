#include <stdio.h>

int main(){
	char name[12];
	printf("Please input your name: ");
	gets(name);
	printf("Hello %s!\n", name);
	return 0;
}
