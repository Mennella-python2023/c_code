#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



// Redefinizione per SCL con char
typedef char TipoInfoSCL;
struct ElemSCL_char {
    TipoInfoSCL info;
    struct ElemSCL_char *next;
};
typedef struct ElemSCL_char TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;

// Utility functions
TipoSCL list_add_front(TipoSCL p0, char info);
TipoSCL list_add_back(TipoSCL l, char info);
TipoSCL copy_list(TipoSCL list);
TipoSCL create_random_list(int size);
bool equal_lists(TipoSCL l1, TipoSCL l2);
void free_list(TipoSCL list);
void print_list(TipoSCL l);

