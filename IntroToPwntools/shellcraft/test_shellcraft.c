#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void start(){
	char input[64];
	gets(input);
}


int main(){
	printf("Hello There. Do you have an input for me?\n");
	start();

}
