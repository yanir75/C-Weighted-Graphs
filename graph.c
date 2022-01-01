#include <stdio.h>
#include <stdlib.h>

typedef struct edge{
    int weight;
    struct node* dest;
    struct edge *next_edge;
}edge;

typedef struct node{
    int id;
    struct node *next;
    edge *edges;
}node;


node* allocate_graph(int num)
{
    // allocates the node list
    node *head = (node*)malloc(sizeof(num));
    if(head==NULL)
    {
        exit(1);
    }
    node *tmp =head;
    for(int i=0;i<num-1;i++){
        tmp->id=i;
        tmp->edges=NULL;
        node *n = (node*)malloc(sizeof(num));
        if(n==NULL){
            exit(1);
        }
        tmp->next=n;
        tmp=tmp->next;
    }
    tmp->id=num-1;
    tmp->edges=NULL;
    tmp->next=NULL;
    return head;
}

//returns the num node
node* get(node *head,int num){
    node *tmp =head;
    int i=0;
    while(i<num && tmp->next!=NULL)
    {
        i++;
        tmp=tmp->next;
    }
    if(i<num)
    {
        return NULL;
    }
    return tmp;
}
//free  the memory of the edges
void free_edges(node *head){
    edge *e=head->edges;
    edge *tmp=e;
    while(tmp!=NULL){
        e=tmp;
        tmp=tmp->next_edge;
        free(e);
    }
}
void free_list(node *head){
    node *tmp=head;
    while(tmp!=NULL){
        head=tmp;
        free_edges(head);
        tmp=tmp->next;
        free(head);
    }
}

// adds a node 
node *add(node *head){
        int i;
        scanf("%d",&i);
        node *added = (node*)malloc(sizeof(node));
        if(added==NULL)
        {
            exit(1);
        }
        added->edges=NULL;
        added->next=NULL;
        added->id=i;
        node *tmp=head;
        edge *e=NULL;
        while(scanf("%d",&i)){
            if(e==NULL){
                
                added->edges=(edge*)malloc(sizeof(edge));
                if(added->edges==NULL)
                {exit(1);}
                e=added->edges;
            }
            else{
                edge *tmp_edge = (edge*)malloc(sizeof(edge));
                if(tmp_edge==NULL)
                {exit(1);}
                e->next_edge=tmp_edge;
                e=tmp_edge;
            }
            e->dest = get(head,i);
            scanf("%d",&i);
            e->weight=i;
            e->next_edge=NULL;
        } 
        if(head->id==added->id)
        {
            added->next=head->next;
            free_edges(head);
            free(head);
            head=added;
            return head;
        }
        else {
        while(tmp->next!=NULL && tmp->next->id!=added->id){
            tmp=tmp->next;
        }
        if(tmp->next==NULL){
            tmp->next=added;
        }
        else{
                node *deleted = tmp->next;
                added->next=deleted->next;
                tmp->next=added;
                free_edges(deleted);
                free(deleted);
        }
        }
        return head;
}

node* load_graph(char *ch_copy,node *f){
    if(f!=NULL){
    free_list(f);
    }
    char numOfNodes[20];
    //gets how many nodes in the graph
    scanf("%s",numOfNodes);
    int num = atoi(numOfNodes);
    //initiates the graph
    node *head = allocate_graph(num);
    char ch;
    // takes the char
    scanf(" %c",&ch);
    // updates the info of the node
    while(ch=='n'){
        int i;
        // gets the node you want to work on
        scanf("%d",&i);
        node *tmp = get(head,i);
        edge *e = tmp->edges;
        while(scanf("%d",&i)){
            if(e==NULL){
                tmp->edges=(edge*)malloc(sizeof(edge));
                if(tmp->edges==NULL)
                {exit(1);}
                e=tmp->edges;
            }
            else{
                edge *tmp_edge = (edge*)malloc(sizeof(edge));
                if(tmp_edge==NULL)
                {exit(1);}
                e->next_edge=tmp_edge;
                e=tmp_edge;
            }
            e->dest = get(head,i);
            scanf("%d",&i);
            e->weight=i;
            e->next_edge=NULL;
        }
        scanf(" %c",&ch);
    }
    *ch_copy=ch;
    return head;
    
}

void print(node *head){
    while(head!=NULL){
        int id = head->id;
        printf("Node: %d\n  edges:\n    {",head->id);
        edge *e = head->edges;
        while(e!=NULL){
            printf("dest: %d, weight: %d",e->dest->id,e->weight);
            e=e->next_edge;
        }
        printf("}\n");
        head=head->next;
    }
}

int main()
{
    char ch;
    scanf(" %c",&ch);
    node *head=NULL;
    while(ch!= 'k'){
        // receiving a graph
        if(ch=='A'){
            head = load_graph(&ch,head);
            print(head);
        }
        if(ch=='B')
        {
            head=add(head);
            print(head);
        }
        scanf(" %c",&ch);
    }
}
