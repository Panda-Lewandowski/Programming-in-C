#include "list.h"
#include <stdlib.h>
#include <string.h>

/// \details  Creates a list (node) and returns it
/// \param  The data the list will contain or NULL to create an empty
/// list/node

list_node* node_create(const int data)
{
    list_node *l = malloc(sizeof(list_node));
    if (l != NULL)
    {
        l->next = NULL;
        l->data = data;
    }

    return l;
}

/// \details Completely destroys a list
///  \param A pointer to a list

void destroy(list_node *list)
{
    list_node *next;
    for (; list; list = next)
    {
        next = list->next;
        free(list);
    }
}

/* Creates a new list node and inserts it at the end of the list
 * Arguments: The list the node will be inserted to and the data the node will
 * contain
 */
void insert_end(list_node *list, int data)
{

    list_node *new_node = node_create(data);
    if (new_node != NULL)
    {
        for(list_node *it = list; it != NULL; it = it->next)
        {
            if (it->next == NULL)
            {
                it->next = new_node;
                break;
            }
        }
    }
}
/// \details Creates a new list node and inserts it in the beginning of the list
/// \param The list the node will be inserted to and the data the node will
///  contain

list_node* insert_front(list_node *list,const int data)
{
    list_node *new_node = node_create(data);
    if (new_node != NULL)
        new_node->next = list;
    return new_node;
}

/// \details Creates a list node and inserts it after the specified node
/// \param A node to insert after and the data the new node will contain
int insert_after(list_node *node,const int data)
{
    list_node *new_node = node_create(data);
    if (new_node)
    {
        new_node->next = node->next;
        node->next = new_node;
        return 0;
    }
    else
        return ERROR;
}





/// \details Finds an element in a list by the data
/// \param A pointer to a list and a pointer to the data

list_node* find_by_data(list_node *list,const int data)
{
    if(list->data > data)
        return NULL;
    while (list->next != NULL && data >= (*(list->next)).data)
        list = list->next;

    return list;
}
///
/// \brief insert
/// \details create and insert elelment into right position
/// \param list head of list
/// \param data
/// \return 0 if success or ERROR if not
///
list_node* insert(list_node *list, const int data)
{
    list_node *node;
    int fc = 0;

    node = find_by_data(list, data);

    if(node == NULL)
        list = insert_front(list, data);
    else
    {
        fc = insert_after(node, data);
        if(fc == ERROR)
            return NULL;

    }

    return list;
}

int isDigit(char c)
{
    return (c >= '0') && (c <= '9');
}

int a_to_i(char *str)
{
    int result = 0;
    int neg_multiplier = 1;

    while (*str && (
            (*str == ' ') ||
            (*str == '\t')))
        str++;


    if (*str && *str == '-') {
        neg_multiplier = -1;
        str++;
    }


    for (; *str && isDigit(*str); str++) {
        result = (result * 10) + (*str - '0');
    }

    return result * neg_multiplier;
}

list_node* arrtolist(int a[], int n)
{
    list_node *head = node_create(a[0]);
    int i = 1;

    while(i < n)
    {
        head = insert(head, a[i]);
        if(!head)
            break;
        i++;
    }

    return head;

}

int comarrlist(int a[], int n, list_node *list)
{
    int rc = 0;
    int i = 0;
    while (list && i < n)
    {
       if(list->data != a[i])
            rc = -1;
       list = list->next;
       i++;

    }

    return rc;

}
