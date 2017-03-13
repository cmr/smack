#include <stdio.h>
#include <stdlib.h>
#include <smack.h>
#include <smack-contracts.h>

// @expect verified

#define SIZE 10
int g[SIZE];

void p() {
  ensures(forall("i", qvar("i", int) < 0 || qvar("i", int) >= SIZE || g[qvar("i", int)] == qvar("i", int)));

  for (int i=0; i<SIZE; i++) {
    invariant(forall("x", qvar("x", int) < 0 || qvar("x", int) >= i || g[qvar("x", int)] == qvar("x", int)));
    g[i] = i;
  }
}
