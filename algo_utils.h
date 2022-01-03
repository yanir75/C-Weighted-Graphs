node *load_graph(char *ch,node *head);
node *add(node *head);
int djikstra(node *head,int src,int dest);
node *delete(node *head,int id);
node *get_id(node *head,int id);
int TSP(node *head,int *arr,int start,int end,int count,int *max);
void free_list(node *head);