#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


typedef struct Node{
	int x;
	struct Node* next;
}node;

typedef struct list{
	node* head;
	node* tail;
}list;


int main(){
	node* tmp = (node*)malloc(sizeof(node));
	tmp->x=1;
	tmp->next=NULL;
	list* ll = (list*)malloc(sizeof(list));
	ll->head=tmp;
	ll->tail=tmp;
	for(int i=2;i<5;i++){
		node* tmp1 = (node*)malloc(sizeof(node));
		tmp1->x=i;
		tmp1->next=NULL;
		ll->tail->next=tmp1;
		ll->tail=tmp1;
	}
	tmp=ll->head;
	for(int i=0;i<4;i++){
		printf("%d ",tmp->x);
		tmp=tmp->next;
	}
}