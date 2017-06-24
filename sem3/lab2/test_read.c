#include "list.h"

int main()
{
    FILE *f;
    FILE *g;
    list_node *head;
    f = fopen("test.txt", "r");
    g = fopen("result.txt", "w");
    int buf, fc;
    list_node *node;

    fc = fscanf(f, "%d", &buf);
    if(fc == 1)
    {
        head = node_create(buf);
        while (fscanf(f, "%d", &buf) == 1)
        {
            node = find_by_data(head, buf);
            if(node == NULL)
                head = insert_front(head, buf);
            else
                insert_after(node, buf);
        }
    }
    node = find_by_data(head, 16);
    if(node == NULL)
        head = insert_front(head, 16);
    else
        insert_after(node, 16);

    while (head) {
            fprintf(g, "%d ", head->data);
            head = head->next;
        }

    destroy(head);
    return 0;
}
