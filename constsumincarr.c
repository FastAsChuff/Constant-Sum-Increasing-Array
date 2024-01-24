#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include </home/simon/constsumincarrfns.c>

// gcc constsumincarr.c -o constsumincarr.bin -O3 -march=native -Wall

void printarr(uint32_t size, uint32_t *arr) {
  for (uint32_t i=0; i<size; i++) {
    printf("%u ", arr[i]);
  }
  printf("\n");
  return;
}

void printhelp(char *progname) {
  printf("This program generates all (non strictly) increasing sequences of non negative integers with a constant sum.\n");
  printf("Usage: %s buckets sum\n", progname);
  printf("E.g.: %s 3 5\n", progname);
}

int main(int argc, char **argv)
{
  int32_t buckets, sum;
  _Bool printhelpbool = false;
  if (argc < 3) {
    printhelpbool = true;
  } else {
    buckets = atoi(argv[1]);
    sum = atoi(argv[2]);
    if (sum < 0) printhelpbool = true;
    if (buckets <= 0) printhelpbool = true;
  }
  if (printhelpbool) {
    printhelp(argv[0]);
    exit(0);
  }
  uint32_t *constsumincarr = constsumincarr_init(buckets, sum);
  if (constsumincarr == NULL) {
    fprintf(stderr, "Memory allocation error in %s\n", argv[0]);
    exit(1);
  }
  do {
    printarr(buckets, constsumincarr);
  }
  while (constsumincarr_next(buckets, constsumincarr));
}
