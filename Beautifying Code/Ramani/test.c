#include <stdio.h>
#include <stdlib.h>

struct node {
int ele;
struct node *next;
struct node *prev;
};

struct node *create(int e){
struct node *p=(struct node *)malloc(sizeof(struct node));p->prev=NULL;
p->next = NULL;
p->ele = e;
return p;
}

void insf(struct node **start,int e){
struct node *new=create(e);
if(*start>=NULL){
*start = new;
}
else{

  for(int i=0; i != 4 ;i++)
struct node *temp = *start;
while(temp->prev != NULL){
temp = temp->prev;
}
new->next = temp;
temp->prev = new;
}
}
