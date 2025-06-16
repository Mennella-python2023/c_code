#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "soluzione_scl_funzionale.h"

int main() {
    printf("\n==== TEST LISTA DI CARATTERI ====\n");

    // Test sclstring_create
    TipoSCL s = sclstring_create("string");
    printf("Stringa creata: ");
    print_list(s);

    // Test sclstring_remove
    TipoSCL r = sclstring_create("Test");
    printf("Stringa originale: ");
    print_list(r);
    TipoSCL rm = sclstring_remove(r, 't');
    printf("Dopo la rimozione di 't': ");
    print_list(rm);

    // Test sclstring_add_underscore
    TipoSCL r2 = sclstring_create("StriNgA");
    printf("Stringa originale: ");
    print_list(r2);
    TipoSCL us = sclstring_add_underscore(r2);
    printf("Dopo l'aggiunta di underscore prima delle maiuscole: ");
    print_list(us);

    // Test sclstring_remove_duplicates
    TipoSCL r3 = sclstring_create("SttrinngaA");
    printf("Stringa con duplicati: ");
    print_list(r3);
    TipoSCL nodup = sclstring_remove_duplicates(r3);
    printf("Dopo la rimozione dei duplicati: ");
    print_list(nodup);

    // Test alterna_con_step
    TipoSCL alt1 = sclstring_create("Stin");
    TipoSCL alt2 = sclstring_create("rghe");
    printf("Stringa 1: ");
    print_list(alt1);
    printf("Stringa 2: ");
    print_list(alt2);
    TipoSCL merged = alterna_con_step(alt1, alt2, 2);
    printf("Dopo l'alternanza con passo 2: ");
    print_list(merged);

    // Test alterna_reverse
    TipoSCL alt3 = sclstring_create("abcd");
    char rev_arr[] = "efghi";
    printf("Stringa: ");
    print_list(alt3);
    printf("Array: %s\n", rev_arr);
    TipoSCL revmerge = alterna_reverse(alt3, rev_arr);
    printf("Dopo l'alternanza con array invertito: ");
    print_list(revmerge);

    // Test aggiungi_caratteri
    TipoSCL sorted = sclstring_create("adfiz");
    printf("Stringa ordinata: ");
    print_list(sorted);
    TipoSCL inserted = aggiungi_caratteri(sorted, "cegh");
    printf("Dopo l'aggiunta dei caratteri: ");
    print_list(inserted);

    return 0;
}
