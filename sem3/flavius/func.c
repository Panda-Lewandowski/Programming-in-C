#include "func.h"
///
/// \brief create_node создания узла списка
/// \param n значение
/// \return  узел
///
struct list_int *create_node(int n)
{
    struct list_int *elem = malloc(sizeof(struct list_int));

    if (elem)
    {
        elem->num = n;
        elem->next = NULL;
        elem->prev = NULL;
    }

    return elem;
}
///
/// \brief add_after добавление узла после другого
/// \param head голова списка
/// \param elem узел, после которого необходимо добавить
/// \return добавленный узел
///
struct list_int* add_after(struct list_int *head, struct list_int *elem)
{
    if (!head)
    {
        elem->next = elem;
        elem->prev = elem;
    }
    else
    {
        elem->next = head->next;
        elem->prev = head;
        head->next->prev = elem;
        head->next = elem;
    }

    return elem;
}
///
/// \brief del_elem удаление элемента списка
/// \param head голова списка
/// \return удаленный узел
///
struct list_int* del_elem(struct list_int *head)
{
    struct list_int *tmp;

    if (head->next == head->prev && head->next == head)
    {
        free(head);
        return NULL;
    }
    else
    {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        tmp = head->next;
        free(head);
    }

    return tmp;
}
///
/// \brief print печать списка
/// \param head голова списка
///
void print(struct list_int *head)
{
    struct list_int *tmp = head;
    printf("\nList now: ");

    if (head)
    {
        do
        {
           printf("%d ", head->num);
           head = head->next;
        }
        while(head != tmp);
    }
}
