#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_flag() {
	printf("Getting Flag:\n");
	fflush(stdout);
	char *cat_flag[3] = {"/bin/cat", "flag.txt", NULL};
	execve("/bin/cat", cat_flag,  NULL);
	exit(0);
}

void start(){
	char name[24];
	gets(name);
}


int main(){
	printf("I run as dizmas.\n");
	printf("Who are you?: ");
	start();

}
