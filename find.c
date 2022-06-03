#include "func.h"

typedef struct Que{
	int head;
	int tail;
	int *vect;
}Que;

int find(Graph *graph){
	int i, j;
	printf("Enter vertex from: ");
	scanf("%d", &i);
	printf("Enter vertex to: ");
        scanf("%d", &j);

	Que *o =(Que*)malloc(sizeof(Que));
	o->vect = (int *)malloc(sizeof(int)* (graph->V + 1));
	o->vect[0] = i;
	o->head = 0;
	o->tail = 1;

	int mas[graph->V];
	int p;
	for(p = 0; p < graph->V; p++)
	mas[p] = 2147483648;
	mas[i] = 0;

	for(p = 0; p < graph->V - 1; p++){
			i = o->vect[o->head];
			Node *ptr = graph->array[i].next;
			++o->head;
			while (ptr != NULL){
				int m = ptr->dest;
				if(mas[m] > (ptr->h + mas[i])){
					o->vect[o->tail] = m;
					++o->tail;
					mas[m] = mas[i] + ptr->h;
				}
				ptr = ptr->next;
			}
			mas[i] = 0;
	}
	free(o->vect);
	free(o);
	printf("Min way: %d\n", mas[j]);
	return 1;
}
