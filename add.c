#include "func.h"

Node* neww(int dest){
        Node* node = (Node*)malloc(sizeof(Node));
        node->dest = dest;
        node->next = NULL;
        return node;
}


int addEdge(Graph* graph){
        int src, dest, h;
        printf("Enter first vertex: ");
        scanf("%d", &src);
        printf("Enter second vertex: ");
        scanf("%d", &dest);
        printf("Enter ves : ");
        scanf("%d", &h);

        Node* check = NULL;
        Node *newNode = neww(dest);
        graph->array = (Node*)realloc(graph->array, sizeof(Node) *(graph->V+1));
        newNode->h = h;

        if (graph->array[src].next == NULL){
                newNode->next = NULL;
                graph->array[src].next = newNode;
        }
        else {
        check = graph->array[src].next;
                while (check->next != NULL) {
                        check = check->next;
                }
                check->next = newNode;
        }

        newNode = neww(src);
        newNode->h = h;

        if (graph->array[dest].next == NULL) {
                ++graph->V;
                newNode->next = NULL;
                graph->array[dest].next = newNode;
        }
        else {
                check = graph->array[dest].next;
                while (check->next != NULL) {
                        check = check->next;
                }
                check->next = newNode;
        }
        return 1;
}

