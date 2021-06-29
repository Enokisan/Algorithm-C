#include <stdio.h>
#define SIZE 10
int stk[SIZE];
int sp; // stack pointer
void print_stack();
void push(int n);
int pop();
int main(int argc, const char * argv[]) {
	sp=0;
	int mode=3;
	int x;
	while(mode > 0){
		printf("end:0, push:1, pop:2\n"); fflush(stdout);
		scanf("%d",&mode);
		if(mode==1){
			printf("input key\n"); fflush(stdout);
			scanf("%d",&x);
			push(x);
		}
		if(mode==2){
			pop();
		}
	}
	printf("\nend this program"); fflush(stdout);
	return 0;
}
	
void print_stack() {
	int i;
	printf("[ "); fflush(stdout);
	for (i=0; i< sp; i++) {
		printf("%d ", stk[i]); fflush(stdout);
	}
	printf("]\n"); fflush(stdout);
}

void push(int n) {
	if (sp < SIZE) { // 1
		stk[sp] = n; // 2
		sp += 1;
		printf("push(%d) => ", n); print_stack(); fflush(stdout);
	} else {
		printf("push(%d): Stack full! data: %d discarded.\n", n, n); fflush(stdout);
	}
}

int pop() {
	int n;
	if (sp > 0) { // 3
		n = stk[sp-1]; // 4
		sp -= 1;
		printf("pop():%d => ", n); print_stack(); fflush(stdout);
		return n; // 5
	} else {
		printf("pop(): Stack empty! No data popped.\n"); fflush(stdout);
		return 0;
	}
}
