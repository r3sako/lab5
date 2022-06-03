#include "func.h"

int main(){
    Graph* graph = create();
    int rc;

    int (*fptr[])(Graph *) = {NULL, addEdge, delVert, D_Show, find};

    while(rc = dialog(msgs, NMsgs)){
        if(!fptr[rc](graph)){
            break;
        }
    }
    printf("That's all. Bye!\n");
    clear(graph);

    return 0;
}
