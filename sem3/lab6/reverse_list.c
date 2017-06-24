#include "func.h"
//один элемент v
//два v
//много v
int main()
{
    {
        element* head = create_element("vogue", 864);

        head = reverse_list(head);
        if(head->next == NULL && head)
            printf("Test #1 passed.\n");

        free_list(&head);
    }

    {
        element* head = create_element("vogue", 864);
        head = insert(head, create_element("geo", 145), head);
        head = reverse_list(head);
        if(!strcmp(ELEM_TO_DATA(head)->name,"vogue") && ELEM_TO_DATA(head)->number == 864
                && !strcmp(ELEM_TO_DATA(head->next)->name,"geo") && ELEM_TO_DATA(head->next)->number == 145)
            printf("Test #2 passed.\n");

        //print_list(head);
        free_list(&head);
    }

    {
        element* head = create_element("vogue", 864);
        head = insert(head, create_element("geo", 145), head);
        head = insert(head, create_element("top", 46), head);
        char* str[3] = {"vogue", "geo", "top"};
        int num[3] = {864, 145, 46};
        head = reverse_list(head);
        //print_list(head);
        element* cur = head;
        int i = 0;
        while(cur)
        {
            if(strcmp(ELEM_TO_DATA(cur)->name, str[i]) || ELEM_TO_DATA(cur)->number != num[i]){
                break;printf("fidjobj");}
            //print_list(cur);
            cur = cur->next;
            i++;

        }

        if(cur == NULL)
            printf("Test #3 passed.\n");

        //print_list(head);
        free_list(&head);
    }


}
