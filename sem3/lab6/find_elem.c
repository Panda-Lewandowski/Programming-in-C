#include "func.h"
//первый v
//в середине v
// конец v
//не нашел v
// по названию v
//по номеру v
int main()
{
    FILE* f;
    f = fopen("test.txt", "r+");
    if(f)
    {
        element *head = form_list(f);
        element* ptr;

        {
            element *foo = create_element("furfur", 30);
            ptr = find_elem(head, foo, comp_elem);
            if(ptr && !strcmp(ELEM_TO_DATA(ptr)->name, "furfur") && ELEM_TO_DATA(ptr)->number == 30)
                printf("Test #1 passed.\n");

            free_list(&foo);
        }

        {
            element *foo = create_element("vogue", 45);
            ptr = find_elem(head, foo, comp_elem);
            if(ptr && !strcmp(ELEM_TO_DATA(ptr)->name, "vogue") && ELEM_TO_DATA(ptr)->number == 45)
                printf("Test #2 passed.\n");

            free_list(&foo);
        }

        {
            element *foo = create_element("geo", 89);
            ptr = find_elem(head, foo, comp_elem);
            if(ptr && !strcmp(ELEM_TO_DATA(ptr)->name, "geo") && ELEM_TO_DATA(ptr)->number == 89)
                printf("Test #3 passed.\n");

            free_list(&foo);
        }

        {
            element *foo = create_element("elementary", 800);
            ptr = find_elem(head, foo, comp_elem);
            if(ptr == NULL)
                printf("Test #4 passed.\n");

            free_list(&foo);
        }

        {
            element *foo = create_element("geo", 1000);
            ptr = find_elem(head, foo, comp_elem_name);
            if(ptr && !strcmp(ELEM_TO_DATA(ptr)->name, "geo"))
                printf("Test #5 passed.\n");

            free_list(&foo);
        }

        {
            element *foo = create_element("geo", 45);
            ptr = find_elem(head, foo, comp_elem_num);
            if(ptr && !strcmp(ELEM_TO_DATA(ptr)->name, "vogue") && ELEM_TO_DATA(ptr)->number == 45)
                printf("Test #6 passed.\n");

            free_list(&foo);
        }
        fclose(f);
        free_list(&head);

    }


    return 0;
}
