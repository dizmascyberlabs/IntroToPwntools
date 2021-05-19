#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void start(){
	char buffer[64];
	gets(buffer);
}


int main(){
	printf("Hello There. Do you have an input for me?\n");
	start();

}
