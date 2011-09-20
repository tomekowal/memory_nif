#include<stdlib.h>
#include<stdio.h>

int main(int argc, char** argv) {
	while(1) {
		malloc(5000000);
		printf("*");
		fflush(NULL);
		sleep(1);
	}
}
