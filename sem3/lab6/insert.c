#include "func.h"
//в начало v
//в середину v
//из одного элемента v
int main()
{

    element* head = create_element("allure", 465);
    element* buf = insert(head, NULL, head);
    if(buf == head)
        printf("Test #0 passed.\n");
    head = insert(head, create_element("vogue", 789), head);
    if(head && !strcmp(ELEM_TO_DATA(head)->name, "vogue") && ELEM_TO_DATA(head)->number == 789)
        printf("Test #1 passed.\n");

    head = insert(head, create_element("geograff", 159), head->next);
    if(head && !strcmp(ELEM_TO_DATA(head->next)->name, "geograff") && ELEM_TO_DATA(head->next)->number == 159)
        printf("Test #2 passed.");



    free_list(&head);


    return 0;
}
