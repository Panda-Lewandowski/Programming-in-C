#include "func.h"
element* create_element(char* new_name, int new_number)
{
    struct magazine *new_magazine;
    element *new_element;

    new_magazine = malloc(sizeof(struct magazine));
    new_element = malloc(sizeof( element));

    if (!new_magazine || !new_element)
        return NULL;

    new_magazine->name = malloc(30);

    strncpy(new_magazine->name, new_name, 30);
    new_magazine->number = new_number;

    new_element->data = new_magazine;
    new_element->next = NULL;
    return new_element;
}

int comp_elem(element *A,  element *B)
{
    //printf("%d %d\n\n", ELEM_TO_DATA(A)->number, ELEM_TO_DATA(B)->number);
    if (ELEM_TO_DATA(A)->number == ELEM_TO_DATA(B)->number
            && !strcmp(ELEM_TO_DATA(A)->name, ELEM_TO_DATA(B)->name))
        return 0;

    return -1;
}

int comp_elem_num( element *A, element *B)
{
    //printf("%d %d\n\n", ELEM_TO_DATA(A)->number, ELEM_TO_DATA(B)->number);
    if (ELEM_TO_DATA(A)->number == ELEM_TO_DATA(B)->number)
        return 0;
    else if (ELEM_TO_DATA(A)->number > ELEM_TO_DATA(B)->number)
        return 1;
    else
        return -1;
}

int comp_elem_name(element *A, element *B)
{
    if (!strcmp(ELEM_TO_DATA(A)->name, ELEM_TO_DATA(B)->name))
        return 0;
    if (strcmp(ELEM_TO_DATA(A)->name, ELEM_TO_DATA(B)->name) == 1)
        return 1;

    return -1;

}

element* insert(element *head, element* elem,  element* before)
{
    element *cur = head;
    if (!elem)
        return head;
    elem->next = before;

    if (head == before)
    {
        head = elem;
        return head;
    }
    if (head->next)
    {
        while ((cur->next != before))
            cur = cur->next;
        cur->next = elem;
        return head;
    }

    return NULL;
}

element *find_elem( element *head, element *elem,
                          int (*comp)( element* a,  element* b))
{
     element *cur = head;

    while (cur)
    {
        if (!comp(elem, cur))
            break;
        cur = cur->next;
    }
    return cur;
}


void print_list( element* head)
{
    if (!head)
    {
        printf("> Empty list.\n");
        return;
    }
    do {

        printf("\n %s: %d  ", ELEM_TO_DATA(head)->name, ELEM_TO_DATA(head)->number);

        head = head->next;
    } while (head);
    puts("\n");
}

void free_data(struct magazine **mag)
{
    if (!mag || !(*mag))
        return;

    free((*mag)->name);
    free(*mag);
    *mag = NULL;
}

void free_element( element **mag)
{
    if (!mag || !(*mag))
        return;

    free(*mag);
    *mag = NULL;
}

void free_list( element **head)
{
    struct element *delE;
    struct magazine *delD;
    if (!head || !(*head))
        return;

    while (*head)
    {
        delD = ELEM_TO_DATA(*head);
        free_data(&delD);
        delE = *head;
        *head = (*head)->next;
        free_element(&delE);
    }
}



element* sorted_insert(element* head, element *elem,int (*comp)( element* , element *))
{
    struct element *cur = head;
    while (cur && (comp(cur,elem) <= 0))
    {
        if(cur->next)
            cur = cur->next;
        else
        {
            head = insert_after(head, elem, cur);
            return head;
        }
    }


    //printf("%d \n\n", ELEM_TO_DATA(cur)->number);
    head = insert(head, elem, cur);


    return head;
}

element* insert_after(element* head, element* elem, element* after)
{
    if (!after)
    {
        head = elem;
        return head;
    }
    else
    {
        if(head)
        {
            elem->next = after->next;
            after->next = elem;
            return head;
        }
    }

    return NULL;
}

element* insert_sort(element *head, int (*comp)( element* , element *))
{
    element	*new_head = create_element(ELEM_TO_DATA(head)->name,ELEM_TO_DATA(head)->number);
    element *New = NULL;
    element *cur = head->next;

    if(new_head)
    {
        while (cur)
        {
            New = create_element(ELEM_TO_DATA(cur)->name,ELEM_TO_DATA(cur)->number);
            new_head = sorted_insert(new_head, New, comp);
            cur = cur->next;
        }

        free_list(&head);
    }

    return new_head;
}

element* reverse_list(element* head)
{
    element *cur, *prev, *next;
    prev = head;
    cur = head->next;
    if (!cur)
        return head;
    prev->next = NULL;

    do
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    while (cur);
    return prev;
}

element *form_list(FILE* f)
{
    element *head = NULL,
            *work_elem,*cur = NULL;
    int num;
    char* name;

    while (!feof(f))
    {
        name = malloc(30);
        memset(name,'\0',30);
        get_name(name, 30, f);
        fscanf(f, "%d", &num);

        work_elem = create_element(name,num);
        if(work_elem)
        {
            head = insert_after(head,work_elem,cur);
            if (!cur)
                cur = head;
            else
                cur = cur->next;
            free(name);
        }
    }

    return head;
}

void get_name(char* name, int n, FILE* f)
{
    int i=0;
    char c;
    do
    {
        c = fgetc(f);
    }
    while (c == ' ' || c == '\t' || c == EOF || c == '\n');

    *(name+(i++)) = c;
    if (i == n)
        return;

    do
    {
        c = fgetc(f);
        if (c == '\n' || c == ' ' || c == '\t' || c == EOF)
            return;
        *(name+(i++)) = c;
    }
    while (i<n);
}


void fprint_list( element* head, FILE* f)
{
    if(f)
    {
        if (!head)
        {
            fprintf(f, "> Empty list.\n");
            return;
        }
        do {

            fprintf(f, "\n %s: %d  ", ELEM_TO_DATA(head)->name, ELEM_TO_DATA(head)->number);

            head = head->next;
        } while (head);
        puts("\n");
    }
    else
        printf("Problems with file!\n");
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
