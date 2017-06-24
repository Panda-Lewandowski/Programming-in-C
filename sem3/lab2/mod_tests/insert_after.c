#include "list.h"


int main()
{
    list_node *head;
    list_node *node;
    int fc, n = 0;
    int a[] = {-6, 0, 9, 13, 24, 69};
    int control[] = {-6, 0, 1, 9, 13, 24, 69, 69, 100, 100};

    head = arrtolist(a, 6);


    node = find_by_data(head, 1);
    fc = insert_after(node, 1);
    if(fc != ERROR)
        n++;

    node = find_by_data(head, 69);
    fc = insert_after(node, 69);
    if(fc != ERROR)
        n++;

    node = find_by_data(head, 100);
    fc = insert_after(node, 100);
    if(fc != ERROR)
        n++;


    node = find_by_data(head, 100);
    fc = insert_after(node, 100);
    if(fc != ERROR)
        n++;

    if(comarrlist(control, 10, head) == 0 && n == 4)
        printf("Tests passed.\n");
    /*while (list)
    {
       printf("%d ", list->data);
       list = list->next;
    }*/

    destroy(head);
    return 0;

}
