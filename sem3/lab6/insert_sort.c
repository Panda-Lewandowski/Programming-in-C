#include "func.h"
//сортированные v
//перевернутый v
//случайный
//один элемент
//по буквам
int main()
{
    {


        {
            element* head = create_element("fur", 6);
            for(int i = 5; i > 0; i--)
            {
                head = insert(head, create_element("furfur", i), head);
            }
            //print_list(head);
            head = insert_sort(head, comp_elem_num);
            element* cur = head;
            while(cur)
            {
                if(cur->next && ELEM_TO_DATA(cur)->number > ELEM_TO_DATA(cur->next)->number)
                    break;

                cur = cur->next;
            }
            if(cur == NULL)
                printf("Test #1 passed.\n");

            free_list(&head);
        }

        {
            element* head = create_element("fur", -100);
            for(int i = 0; i < 5; i++)
            {
                head = insert(head, create_element("furfur", i), head);
            }
            //print_list(head);
            head = insert_sort(head, comp_elem_num);
            element* cur = head;
            while(cur)
            {
                if(cur->next && ELEM_TO_DATA(cur)->number > ELEM_TO_DATA(cur->next)->number)
                    break;

                cur = cur->next;
            }
            if(cur == NULL)
                printf("Test #2 passed.\n");


            free_list(&head);
        }

        {
            element* head = create_element("fur", -100);
            head = insert(head, create_element("vogue", 44), head);
            head = insert(head, create_element("geo", 746), head);
            head = insert(head, create_element("purpur", 55), head);
            head = insert(head, create_element("allure", 132), head);
            head = insert_sort(head, comp_elem_num);
            element* cur = head;
            while(cur)
            {
                if(cur->next && ELEM_TO_DATA(cur)->number > ELEM_TO_DATA(cur->next)->number)
                    break;

                cur = cur->next;
            }
            if(cur == NULL)
                printf("Test #3 passed.\n");


            free_list(&head);
        }

        {
            element* head = create_element("vogue", 864);

            head = insert_sort(head, comp_elem_num);
            if(head->next == NULL && head)
                printf("Test #4 passed.\n");

            free_list(&head);
        }


        {
            element* head = create_element("fur", -100);
            head = insert(head, create_element("vogue", 44), head);
            head = insert(head, create_element("geo", 746), head);
            head = insert(head, create_element("allure", 132), head);
            head = insert_sort(head, comp_elem_name);
            char* str[4] = {"allure", "fur", "geo", "vogue" };
            int num[4] = {132, -100, 746, 44};
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
                printf("Test #5 passed.\n");



            free_list(&head);
        }
    }

    return 0;
}
