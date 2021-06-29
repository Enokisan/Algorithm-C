#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *right;
	struct node *left;
} NODE;

NODE *new_node(int x) {
	NODE *z = (NODE *)malloc(sizeof(NODE));
	z->data = x;
	z->right = NULL;
	z->left = NULL;
	return z;
}

void print_tree(NODE *root, int depth) {
	int i;
	if (root != NULL){
		print_tree(root->right, depth+1);

		for (i=0; i<depth; i++){ //深さをスペースを用いて表現
			printf("  ");
		}

		printf("%3d\n", root->data);

		print_tree(root->left, depth+1);

		depth += 1;
	}
}

NODE *insert_node(int x, NODE *root){
	NODE *z;

	if (root == NULL){ //ノードがない時
		root = new_node(x);
		return root;
	}

	z = root;
	while(1){
		if (x < z->data){
			if (z->left == NULL){
				z->left = new_node(x);
				break;
			}else{
				z = z->left;
				continue;
			}
		}else if(x > z->data){
			if (z->right == NULL){
				z->right = new_node(x);
				break;
			}else{
				z = z->right;
				continue;
			}
		}else{ //xがすでにある時
			printf("%d cannot be inserted.\n", x);
			break;
		}
	}
	return root;
}

NODE *deleteNoChildNode(NODE *root, NODE *node, NODE *parent){
	if(parent != NULL){
    	if(parent->left ==  node){
			parent->left = NULL;
    }else{
		parent->right = NULL;
    }
    free(node);
  }else{
    free(node);
    root = NULL;
  }
  return root;
}

NODE *deleteOneChildNode(NODE *root, NODE *node, NODE *child){
	node->data = child->data;
	node->left = child->left;
	node->right = child->right;
    
	free(child);
  
	return root;
}

NODE *deleteTwoChildNode(NODE *root, NODE *node){
	NODE *max;
	NODE *maxParent;

	max = node->left; //左の子孫から最大ノードを探索する
	maxParent = node;
    
	while(max->right != NULL){
    	maxParent = max;
    	max = max->right;
	}

	node->data = max->data;

	if(max->left == NULL){
    	root = deleteNoChildNode(root, max, maxParent);      
	}else{
    	root = deleteOneChildNode(root, max, max->left);
    }
    return root;
}

void *delete_node(int k, NODE *root){
	NODE *z, *parent;

	z = root;
	parent = NULL;

	while(z != NULL){
		if (k < z->data){
			parent = z;
			z = z->left;
		}else if(k > z->data){
			parent = z;
			z = z->right;
		}else{
			break;
		}
	}

	if (z == NULL){
		printf("%d was not found.", k);
		return root;
	}

	if (z->left == NULL && z->right == NULL){
		root = deleteNoChildNode(root, z, parent);
	}else if((z->left != NULL && z->right == NULL) || (z->left == NULL && z->right != NULL)){
		if (z->left != NULL){
			root = deleteOneChildNode(root, z, z->left);
		}else{
			root = deleteOneChildNode(root, z, z->right);
		}
	}else{
		root = deleteTwoChildNode(root, z);
	}

	printf("%d was deleted.\n", k);
	return root;
}

NODE *search_node(int k, NODE *root){
	NODE *z;

	z = root;

	while(z!=NULL){
		if (k < z->data){
			z = z->left;
		}else if(k > z->data){
			z = z->right;
		}else{
			printf("%d was found.\n", k);
			return z;
		}
	}
	printf("%d was not found.\n", k);
	return NULL;
}

int main(int argc, const char * argv[]) {
	NODE *p=NULL;
	int mode = 3;
	int x, n;
	while(mode > 0){
		printf("end:0, insert:1, delete:2, search:3\n"); fflush(stdout);
		scanf("%d",&mode); fflush(stdout);
		if(mode==1){
			printf("insert value\n"); fflush(stdout);
			scanf("%d",&x);
			if(p==NULL){
				p=new_node(x);
			}else{
				insert_node(x,p);
			}
		}else if (mode == 2){
			printf("delete value\n"); fflush(stdout);
			scanf("%d",&x);
			if(p!=NULL){
				delete_node(x, p);
			}
		}else if (mode == 3){
			printf("search value\n"); fflush(stdout);
			scanf("%d",&x);
			if(p!=NULL){
				search_node(x, p);
			}
		}

		print_tree(p,0);
	}
	printf("\nend this program\n"); fflush(stdout);
	return 0;
}