#include "func.h"
//в конец
//в начало v
//в середину
int main()
{
    element* head = create_element("fur", 5);
    head = insert(head, create_element("vogue", 4), head);
    head = insert(head, create_element("geo", 3), head);
    head = insert(head, create_element("purpur", 2), head);
    head = insert(head, create_element("allure", 1), head);

    head = sorted_insert(head, create_element("purpur", 0), comp_elem_num);
    //print_list(head);

    {
        char* str[6] = {"purpur", "allure", "purpur", "geo", "vogue", "fur"};
        int num[6] = {0, 1, 2, 3, 4, 5};
        element* cur = head;

        int i = 0;
        while(cur)
        {
            if(strcmp(ELEM_TO_DATA(cur)->name, str[i]) || ELEM_TO_DATA(cur)->number != num[i])
                break;
            //print_list(cur);
            cur = cur->next;
            i++;

        }

        if(cur == NULL)
            printf("Test #1 passed.\n");


    }

    free_list(&head);

    return 0;
}
