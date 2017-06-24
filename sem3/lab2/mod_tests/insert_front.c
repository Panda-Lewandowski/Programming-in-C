#include "list.h"


int main()
{
    list_node *head;
    int a[] = {-6, 0, 9, 13, 24, 69};
    int control[] = {-16, 1, 125, -6, 0, 9, 13, 24, 69};
    head = arrtolist(a, 6);

    head = insert_front(head, 125);

    head = insert_front(head, 1);

    head = insert_front(head, -16);

    if(comarrlist(control, 10, head) != -1)
        printf("Tests passed\n");

    /*while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }*/

    destroy(head);
    return 0;

}
