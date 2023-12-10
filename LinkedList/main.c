#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node * next;
};
struct Node * first = NULL;
void createLinkedList (int A[],int size);
void displayLinkedList (struct Node *  );
int countLinkedList (struct Node * );
int sumLinkedList (struct Node * );
int maxLinkedList (struct Node * );
struct Node * searchLinkedList (struct Node * ,int );
int deleteNodeLinkedList (struct Node *,int);

int main(int argc, const char * argv[]) {
    int A[] = {3,5,7,10,15};
    createLinkedList(A, 5);
    
    
    
    
    /*
    int count =  countLinkedList(first);
    printf("\ncount = %d",count);
    int sum =  sumLinkedList(first);
    printf("\nsum = %d\n",sum);
    int max =  maxLinkedList(first);
    printf("\nmax = %d\n",max);
    struct Node * keyPtr = searchLinkedList(first, 100);
    printf("\nkeyPtr = %u\n",keyPtr);
    */
    
    /*
    int delData =  deleteNodeLinkedList(first,1);
    printf("\delData = %d\n",delData);
    */
    
    
    return 0;
}


void createLinkedList (int A[],int size){
   // int i ;
    struct Node * t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first -> data = A[0];
    first->next = NULL;
    last = first;
    
    for (int i = 1; i < size; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void displayLinkedList (struct Node * tmp ){
   while (tmp != NULL) {
        printf("%d\t",tmp->data);
        tmp = tmp -> next;
    }
}


int countLinkedList (struct Node * tmp ){
    int count = 0;
    while (tmp != NULL) {
        count +=1;
         tmp = tmp -> next;
     }
    return  count;
}

int sumLinkedList (struct Node * tmp ){
    int sum = 0;
    while (tmp != NULL) {
        sum = sum + tmp->data;
        tmp = tmp -> next;
     }
    return  sum;
}

int maxLinkedList (struct Node * tmp ){
   int max = INT32_MIN;
    while (tmp != NULL) {
        int data = tmp ->data;
        if(data > max) max = data;
        tmp = tmp -> next;
     }
    return  max;
    
}

struct Node * searchLinkedList (struct Node * p,int key){
    while (p!=NULL) {
        if (p->data == key) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}


int deleteNodeLinkedList (struct Node * p,int index){
    struct Node * q = p;
    int x = INT32_MIN;
    if(index < 1 || index > countLinkedList(p)) return x;
    if(index == 1){
       
        x=q->data;
        first=first->next;
        free(q);
    }else{
        for (int i = 1; i<index; i++) {
            q=p;
            p=p->next;
        }
        x=p->data;
        q->next=p->next;
        free(p);
    }
    return x;
    
}
