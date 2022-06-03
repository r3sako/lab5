#include "func.h"

const char *msgs[] = {"0. Quit", "1. Add", "2. Del Vertex", "3. Show", "4. Min Way"};
const int NMsgs = sizeof(msgs) / sizeof(msgs[0]);

int D_Show(Graph* graph){
        int v;
	printf("\n");
        for (v = 0; v < graph->V ; v++) {
	    if(graph->array[v].next){
                Node* pCrawl = graph->array[v].next;
                printf("%d| ", v);
                while (pCrawl) {
                        printf(" %d(%d)", pCrawl->dest, pCrawl->h);
                        pCrawl = pCrawl->next;
                }
                printf("\n");
	    }
        }
	return 1;
}

void clear(Graph *graph){
	int i, j;
	for(i = 0; i < graph->V; i++){
		Node *ptr = graph->array[i].next;
		Node *tmp;
		while(ptr != NULL){
			tmp = ptr;
			ptr = ptr->next;
			free(tmp);
		}
	}
	free(graph->array);
	free(graph);
}

Graph* create(){
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V = 1;
    graph->array = (Node*)malloc(sizeof(Node));
    graph->array[0].next = NULL;
    return graph;
}

int getInt(int *a){
    int e;

    do{
        e = scanf("%d", a);
        if (e < 0){
            return 0;
        }
        if (e == 0){
            printf("%s\n", "Error! Repeat input");
            scanf("%*c");
        }
    } while (e == 0);
    return 1;
}

int dialog(const char *msgs[], int N){
    char *errmsg = "";
    int rc;
    int i, n;

    for(i = 0; i < N; ++i)
    puts(msgs[i]);

    do{
        puts(errmsg);
        errmsg = "You are wrong. Repeate, please!";
        puts("Make your choice: ");
        n = getInt(&rc);
        if(n == 0)
        rc = 0;
    } while(rc < 0 || rc >= N);

    return rc;
}
