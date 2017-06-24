#include "list.h"


int main()
{
    list_node *head;
    int n = 0;
    int a[] = {-6, 0, 9, 13, 24, 69};
    int control[] = {-10, -7, -6, 0, 1, 9, 13, 24, 69, 69, 100, 100};

    head = arrtolist(a, 6);


    head = insert(head, 1);
    if(head)
        n++;


    head = insert(head, 69);
    if(head)
        n++;


    head = insert(head, 100);
    if(head)
        n++;


    head = insert(head, 100);
    if(head)
        n++;

    head = insert(head, -10);
    if(head)
        n++;

    head = insert(head, -7);
    if(head)
        n++;



    if(comarrlist(control, 12, head) == 0 && n == 6)
        printf("Tests passed.\n");
    printf("n = %d\n ", n);
    /*while (head)
    {
       printf("%d ", head->data);
       head = head->next;
    }*/

    destroy(head);
    return 0;


}
