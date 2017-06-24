#include "func.h"




int main()
{
    FILE* f;
    f = fopen("test.txt", "r+");
    struct element *head = form_list(f);

    printf("Original:\n");
    print_list(head);

    /*element* foo = create_element("blabla",0);
    head = sorted_insert(head, foo, comp_elem_num);
    print_list(head);*/

    head = insert_sort(head, comp_elem_name);

    head = reverse_list(head);
    printf("nOriginal:\n");
    print_list(head);
    printf("\nFreeing...\n");
    free_list(&head);
    print_list(head);
    //print_list(list);
    fclose(f);
    return 0;
}
