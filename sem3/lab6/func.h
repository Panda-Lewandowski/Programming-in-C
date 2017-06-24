#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOT_GIVEN_FILE -1
#define NON_EXISTENT_FILE -2
//Напишите функцию insert, которая вставляет элемент перед указанным элементом списка
//(в качетсве параметров указываются адреса обоих элементов). (2)

//Напишите функцию поиска элемента в списке (нужна функция сравнения элементов). (1)

//Напишите функцию reverse, которая обращает список.

//Напишите функцию sorted_insert, которая получает упорядоченный список, и элемент,
//который нужно вставить в этот список, чтобы не нарушить его упорядоченности.

//Напишите функцию insert_sort, которая получает список и упорядочивает
//его по возрастанию, используя функцию sorted_insert. (3)


struct magazine
{
    char* name;
    int number;
};

typedef struct element
{
    void *data;
    struct element *next;
}element;

#define ELEM_TO_DATA(elem) ((struct magazine*) (elem)->data)


element* create_element(char* new_name, int new_number);
element* insert( element *head,  element* elem, element* before);
element *find_elem( element *head,  element *elem,
                          int (*comp)( element* , element *));
void print_list( element* head);
void free_data( struct magazine **mag);
void free_element( element **target);
void free_list( element **head);
int comp_elem( element *A, element *B);
element* sorted_insert(element *head, element *elem,
                   int (*comp)( element* , element *));
int comp_elem_name(element *A, element *B);
int comp_elem_num( element *A, element *B);
element* insert_after(element* head, element* elem, element* after);
element* insert_sort(element *head, int (*comp)( element* , element *));
element* reverse_list(element* head);
void get_name(char* name, int n, FILE* f);
element *form_list(FILE* f);
void fprint_list( element* head, FILE* f);
int a_to_i(char *str);
#endif // FUNC_H

