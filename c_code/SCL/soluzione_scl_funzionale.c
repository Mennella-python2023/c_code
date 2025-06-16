#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "soluzione_scl_funzionale.h"


// scl_fun.3
TipoSCL sclstring_create(const char *s) {
    TipoSCL result = NULL;
    
    for (int i = 0; s[i] != '\0'; i++) {
        result = list_add_back(result, s[i]);
    }
    
    return result;
}

// scl_fun.4
TipoSCL sclstring_remove(TipoSCL scl_p, char val) {
    if (!scl_p) return NULL;
    
    TipoSCL result = NULL;
    TipoSCL curr = scl_p;
    
    while (curr) {
        if (curr->info != val) {
            result = list_add_back(result, curr->info);
        }
        curr = curr->next;
    }
    
    return result;
}

// scl_fun.5
TipoSCL sclstring_add_underscore(TipoSCL scl_p) {
    if (!scl_p) return NULL;
    
    TipoSCL result = NULL;
    TipoSCL curr = scl_p;
    
    while (curr) {
        if (isupper(curr->info)) {
            result = list_add_back(result, '_');
        }
        result = list_add_back(result, curr->info);
        curr = curr->next;
    }
    
    return result;
}

// scl_fun.6
int char_in_list(TipoSCL list, char c) {
    TipoSCL curr = list;
    while (curr) {
        if (curr->info == c) return 1;
        curr = curr->next;
    }
    return 0;
}

TipoSCL sclstring_remove_duplicates(TipoSCL scl_p) {
    if (!scl_p) return NULL;
    
    TipoSCL result = NULL;
    TipoSCL seen = NULL;
    TipoSCL curr = scl_p;
    
    while (curr) {
        if (!char_in_list(seen, curr->info)) {
            result = list_add_back(result, curr->info);
            seen = list_add_front(seen, curr->info);
        }
        curr = curr->next;
    }
    
    free_list(seen);
    return result;
}

// scl_fun.7
TipoSCL alterna_con_step(TipoSCL scl1, TipoSCL scl2, int step) {
    TipoSCL result = NULL;
    TipoSCL curr1 = scl1;
    TipoSCL curr2 = scl2;
    int count = 0;
    
    while (curr1 || curr2) {
        if (count == step && curr2) {
            result = list_add_back(result, curr2->info);
            curr2 = curr2->next;
            count = 0;
        } else if (curr1) {
            result = list_add_back(result, curr1->info);
            curr1 = curr1->next;
            count++;
        } else if (curr2) {
            result = list_add_back(result, curr2->info);
            curr2 = curr2->next;
            count = 0;
        }
    }
    
    return result;
}

// scl_fun.8
TipoSCL alterna_reverse(TipoSCL scl_1, const char *array) {
    TipoSCL result = NULL;
    TipoSCL curr = scl_1;
    int array_len = strlen(array);
    int i = array_len - 1;
    int toggle = 0; // 0 per SCL, 1 per array
    
    while (curr || i >= 0) {
        if (toggle == 0 && curr) {
            result = list_add_back(result, curr->info);
            curr = curr->next;
            toggle = 1;
        } else if (toggle == 1 && i >= 0) {
            result = list_add_back(result, array[i]);
            i--;
            toggle = 0;
        } else if (curr) {
            result = list_add_back(result, curr->info);
            curr = curr->next;
        } else if (i >= 0) {
            result = list_add_back(result, array[i]);
            i--;
        }
    }
    
    return result;
}

// scl_fun.9
TipoSCL aggiungi_caratteri(const TipoSCL scl, const char *str) {
    if (!scl && !*str) return NULL;
    
    TipoSCL result = NULL;
    TipoSCL curr = scl;
    int str_index = 0;
    
    while (curr || str[str_index]) {
        if (!curr || (str[str_index] && str[str_index] < curr->info)) {
            result = list_add_back(result, str[str_index]);
            str_index++;
        } else {
            result = list_add_back(result, curr->info);
            curr = curr->next;
        }
    }
    
    return result;
}
