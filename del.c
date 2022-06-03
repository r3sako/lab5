#include "func.h"

void delWay(Graph* graph, int src, int dest){
    Node* del = NULL;
    Node* check = NULL;
    del = graph->array[src].next;

    if(del->dest == dest){
        graph->array[src].next = del->next;
        free(del);
    }
    else{
        while (del->next->dest != dest) {
            del = del->next;
        }
        check = del->next;
        del->next = del->next->next;
        free(check);
    }
}

int delVert(Graph* graph){
    int src;
    printf("Enter vertex for del: ");
    scanf("%d", &src);

    if(graph->array[src].next == NULL){
        printf("Edge doesnt exist\n");
        return;
    }
    Node* del = NULL;
    Node *ptr = NULL;
    del = graph->array[src].next;

    while (del != NULL){
        int i = del->dest;
        delWay(graph, i, src);

        if(del->next == NULL){
            free(del);
            graph->array[src].next = NULL;
            printf("Vertex %d was deleted\n", src);
            return 1;
        }
        ptr = del;
        del = del->next;
        free(ptr);
    }
    graph->array[src].next = NULL;
    printf("Vertex %d was deleted\n", src);
    return 1;
}
