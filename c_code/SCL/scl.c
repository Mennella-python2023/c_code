#include "scl.h"

// Utility functions

// Float SCL

TipoSCL list_add_front(TipoSCL p0, char info)
{
  TipoSCL new_element = (TipoSCL)malloc(sizeof(TipoNodoSCL));
  new_element->next = p0;
  new_element->info = info;
  return new_element;
}


TipoSCL list_add_back(TipoSCL l, char info)
{
  TipoSCL new_element = (TipoSCL)malloc(sizeof(TipoNodoSCL));
  new_element->next = NULL;
  new_element->info = info;

  if (l == NULL)
  {
    return new_element;
  }
  TipoSCL aux = l;
  while (aux->next != NULL)
  {
    aux = aux->next;
  }
  aux->next = new_element;
  return l;
}


TipoSCL copy_list(TipoSCL list)
{
  TipoSCL head = NULL;

  while (list)
  {
    head = list_add_back(head, list->info);
    list = list->next;
  }
  return head;
}


bool equal_lists(TipoSCL l1, TipoSCL l2)
{
	if (l1 == NULL && l2 == NULL) return true;
	if (l1 == NULL || l2 == NULL) return false;
	if (l1->info != l2->info) return false;
	return equal_lists(l1->next, l2->next);
}


void print_float_list(TipoSCL l)
{
  if (l == NULL) {
		puts("NULL");
	}
  TipoSCL aux = l;
	printf("[ ");
  while (aux != NULL)
  {
    printf("%c", aux->info);
    aux = aux->next;
		if (aux != NULL) {
			printf(", ");
		}
  }
	printf(" ]");
}


void free_list(TipoSCL list)
{
  if (list == NULL)
    return;
	free_list(list->next);
	free(list);
}


TipoSCL create_random_list(int size)
{
  TipoSCL random_list = NULL;
  for (int i = 0; i < size; ++i)
  {
    char random_char = 'a' + (rand() % 26); // Genera un carattere casuale tra 'a' e 'z'
    TipoSCL new_element = (TipoSCL)malloc(sizeof(TipoNodoSCL));
    new_element->info = random_char;
    new_element->next = random_list;
    random_list = new_element;
  }
  return random_list;
}

// Print char SCL
void print_list(TipoSCL l) {
    printf("[ ");
    while (l) {
        printf("%c", l->info);
        l = l->next;
    }
    printf("]\n");
}
