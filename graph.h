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

typedef struct queue{
    int prio;
    node *info;
    struct queue *next;
}priorityQueue;