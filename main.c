#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "graph.h"
#include "algo.h"


int main()
{
    char ch='k';
    node *head=NULL;
    while((ch=getchar())!=EOF){
        // receiving a graph
        if(ch=='A'){
            head = load_graph(&ch,head);
        }
        if(ch=='B')
        {
            head=add(head);
        }
        if(ch=='D')
        {
            int id;
            scanf(" %d",&id);
            head=delete(head,id);
        }
        if(ch=='S')
        {
            int src,dest;
            scanf(" %d%d",&src,&dest);
            int weight=djikstra(head,src,dest);
            printf("Dijsktra shortest path: %d \n",weight);
        }
        if(ch=='T')
        {
            // list *x=NULL;
            // int i;
            int count;
            // while(scanf(" %d",&i)){
            //     x=add_list(x,i,0);
            //     count++;
            // }
            scanf(" %d",&count);
            int *arr = (int*)malloc(sizeof(int)*count);
            for(int i=0;i<count;i++){
                int id;
                scanf(" %d",&id);
                node *n=get_id(head,id);
                arr[i]=n->id;
            }
            //free_li(x);
            int *max;
            int k=-1;
            max=&k;
            TSP(head,arr,0,count-1,count,max);
            free(arr);
            printf("TSP shortest path: %d \n",*max);
        }
    }
    free_list(head);
    return 0;
}
