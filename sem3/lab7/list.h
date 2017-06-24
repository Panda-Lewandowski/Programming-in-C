#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#define NO_DATA -1
#define NON_EXISTENT_FILE -2
#define NOT_GIVEN_FILE -3
#define ERROR -4
typedef struct list_node {
    int data;
    struct list_node *next;
} list_node;

list_node* node_create(const int data);
void destroy(list_node *list);
int insert_after(list_node *node,const int data);
list_node* insert_front(list_node *list,const int data);
void insert_end(list_node *list, int data);
list_node* find_by_data(list_node *list,const int data);
list_node*  insert(list_node *list, const int data);
list_node* arrtolist(int a[], int n);
int comarrlist(int a[], int n, list_node *list);
int isDigit(char c);
int a_to_i(char *str);
#endif // FUNC_H
