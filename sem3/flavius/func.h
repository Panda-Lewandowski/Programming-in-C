#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>
struct list_int {
    int num;
    struct list_int *next;
    struct list_int *prev;

};

struct list_int* add_after(struct list_int* head, struct list_int * elem) ;
struct list_int* del_elem(struct list_int * head) ;
struct list_int* create_node(int n);
void print(struct list_int *head);
#endif // FUNC_H
