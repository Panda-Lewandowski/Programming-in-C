#include "func.h"

int main(void)
{
    int fc = 0, m, n;
    struct list_int *head = NULL;
    struct list_int *elem;

    printf("Input n  and  m:  \n");
    fc = scanf("%d %d", &n, &m);
    if(fc != 2 || (n == 0 || m == 0))
        printf("ERROR\n");
    else {

            for (int i=0; i<n; i++)
            {
                elem = create_node(i+1);
                head = add_after(head, elem);
            }
            head = head->next;
            print(head);

            while (head->next != head)
            {
               for (int i=1; i<m; i++)
               {
                   head = head->next;
               }
               head = del_elem(head);
               print(head);
            }


            printf("\nThe survivor:  %d\n", head->num);

            while (head)
            {
               head = del_elem(head);
            }

               return 0;

        }

    return -1;
}
