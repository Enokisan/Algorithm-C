#include <stdio.h>
#include <stdlib.h>

typedef struct list {
	int data;
	struct list *next;
	struct list *prev;
} LIST;

LIST *new_list(int x) {
	LIST *z = (LIST *)malloc(sizeof(LIST));
	z->data = x;
	z->next = NULL;
	return z;
}

void print_list(LIST *y) {
	printf("[ "); fflush(stdout);
	while (y!=NULL) {
		printf("%d ", y->data); fflush(stdout);
		y = y->next;
	}
	printf("]\n"); fflush(stdout);
}


void print_adr(LIST *y) {
	printf("[ "); fflush(stdout);
	while (y!=NULL) {
		printf("%p ", y);  fflush(stdout);
		y = y->next;
	}
	printf("]\n"); fflush(stdout);
}

void append_list(int x, LIST *y){
	while(y->next != NULL){
		y = y->next;
	}
	y->next = new_list(x);
}

void insert_list(int x, int n, LIST *y){
	int i = 0;
	LIST *z = (LIST *)malloc(sizeof(LIST));

	while (y!=NULL) {
		 if (i == n){
			z->data = x;
			z->next = y->next;
			y->next = z;
			break;
		}
		if (y->next != NULL){
			y = y->next;
			i += 1;
		}
	}
}

void delete_list(int k, LIST *y){
	while (y->next!=NULL){
		if (y->next->data == k){
			printf("%d was deleted.\n", k);
			y->next = y->next->next;
			break;
		}else{
			y = y->next;
		}
	}
}

void search_list(int k, LIST *y){
	int i = 0;
	while (y!=NULL){
		if (y->data == k){
			printf("%d is in index %d.\n", k, i);
			break;
		}else if(y->next!=NULL){
			y = y->next;
			i += 1;
		}
	}
}

int main(int argc, const char * argv[]) {
	LIST *p=NULL;
	int mode=3;
	int x, n;
	while(mode > 0){
		printf("end:0, insert:1, delete:2, search:3\n"); fflush(stdout);
		scanf("%d",&mode); fflush(stdout);
		if(mode==1){
			printf("insert value\n"); fflush(stdout);
			scanf("%d",&x);
			printf("insert index\n"); fflush(stdout);
			scanf("%d",&n);
			if(p==NULL){
				p=new_list(x);
			}else{
				insert_list(x,n,p);
			}
		}else if (mode == 2){
			printf("delete value\n"); fflush(stdout);
			scanf("%d",&x);
			if(p!=NULL){
				delete_list(x, p);
			}
		}else if (mode == 3){
			printf("search value\n"); fflush(stdout);
			scanf("%d",&x);
			if(p!=NULL){
				search_list(x, p);
			}
		}

		print_list(p);
		print_adr(p); // For test
	}
	printf("\nend this program\n"); fflush(stdout);
	return 0;
}

