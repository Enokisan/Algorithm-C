#include <stdio.h>
#define SIZE 10
int queue[SIZE];
int head; // queue head pointer
int tail; // queue tail pointer
void print_queue();
void enqueue(int n);
int dequeue();
int main(int argc, const char * argv[]) {
	head = 0;
	tail = 0;
	int mode=3;
	int x;
	while(mode > 0){
		printf("end:0, enqueue:1, dequeue:2\n"); fflush(stdout);
		scanf("%d",&mode);
		if(mode==1){
			printf("input key\n"); fflush(stdout);
			scanf("%d",&x);
			enqueue(x);
		}
		if(mode==2){
			dequeue();
		}
	}
	printf("\nend this program"); fflush(stdout);
	return 0;
}
	
void print_queue() {
	int i;
	printf("[ "); fflush(stdout);
	for (i=head; i< tail; i++) {
		printf("%d ", queue[i]); fflush(stdout);
	}
	printf("]\n"); fflush(stdout);
}

void enqueue(int n) {
	if (tail < SIZE) { // 1
		queue[tail] = n; // 2
		tail += 1;
		printf("enqueue(%d) => ", n); print_queue(); fflush(stdout);
	} else {
		printf("enqueue(%d): Queue full! data: %d discarded.\n", n, n); fflush(stdout);
	}
}

int dequeue() {
	int n;
	if (head < tail) { // 3
		n = queue[head]; // 4
		head += 1;
		printf("dequeue():%d => ", n); print_queue(); fflush(stdout);
		return n; // 5
	} else {
		printf("dequeue(): Queue empty! No data dequeued.\n"); fflush(stdout);
		return 0;
	}
}
