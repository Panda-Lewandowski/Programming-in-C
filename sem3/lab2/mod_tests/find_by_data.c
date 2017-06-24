#include "list.h"


int main()
{
    int m = 0;
    list_node *head;
    list_node *node;
    int a[] = {-6, 0, 9, 13, 24, 69};

    /*head = node_create(-6);
    insert_end(head, 0);
    insert_end(head, 9);
    insert_end(head, 13);
    insert_end(head, 24);
    insert_end(head, 69);*/

    head = arrtolist(a, 6);

    node = find_by_data(head, -7);
    if(!node)
        m++;

    if(m == 1)
        printf("Test #1 passed.\n");

    node = find_by_data(head, 1);
    if(node->data == 0)
        m++;

    if(m == 2)
        printf("Test #2 passed.\n");

    node = find_by_data(head, 69);
    if(node->data == 69)
        m++;

    if(m == 3)
        printf("Test #3 passed.\n");

    node = find_by_data(head, 100);
    if(node->data == 69)
        m++;

    if(m == 4)
        printf("Test #4 passed.\n");

    node = find_by_data(head, 100);
    if(node->data == 69)
        m++;
    if(m == 5)
        printf("Test #5 passed.\n");

    node = find_by_data(head, -6);
    if(node->data == -6)
        m++;

    if(m == 6)
        printf("Test #6 passed.\n");

    destroy(head);

    return 0;

}
