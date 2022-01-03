node *load_graph(char *,node *);
node *add(node*);
node *delete(node*,int);
node *get_id(node*,int);
int djikstra(node*,int,int);
int TSP(node*,int *,int ,int,int,int*);
void free_list(node*);