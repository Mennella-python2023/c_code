#include <stdio.h>

int main(int argc, char **argv) {
  int a = 10;
  int b = -1;
  int c;
  int *pa;
  int *pb;
  int *pc;
  // Fai in modo che p1, p2 e p3 puntino ad a, b e c rispettivamente.
  pa = &a;
  pb = &b;
  pc = &c;
  // Usa i puntatori per completare l'operazione.
  *pc = *pa + *pb;
  printf("c == a + b == %d\n", c);
  
  return 0;
}
