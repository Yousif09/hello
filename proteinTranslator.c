/**
 *
 * Yousif Alboufradi, Mason Melcher
 * 2025-11-06
 *
 * Implementing functions that involve DNA sequences and translating them
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "file_utils.h"

#include "protein_utils.h"

int main(int argc, char *argv[]) {

  char *dna = getFileContents(argv[1]);
  if(dna == NULL) {
    return 1;
  }


  FILE *f = fopen(argv[2], "w");
  if(f == NULL) {
    return 1;
  }


  char codon[4];
  int i=0;
  int j=0;
  int stop = 0;
  char proteinStr[10000];
  int pIndex = 0;

  while(dna[i] != '\0' && stop == 0) {
    char base = dna[i];

    if(base != ' ' && base != '\n' && base != '\t') {
      if(base=='t' || base == 'T') {
        base = 'U';
      } else if(base >= 'a' && base <= 'z') {
        base -= 32;
      }
      codon[j] = base;
      j++;

      if(j == 3) {
        codon[3] = '\0';
        char protein = rnaToProtein(codon);


      if(protein == 'x') {
        stop = 1;
      } else if(protein != '\0') {
        proteinStr[pIndex] = protein;
        pIndex ++;
      }

      j = 0;
    }


    }
    i++;

  }
  proteinStr[pIndex] = '\0';
  fprintf(f, "%s", proteinStr);

  fclose(f);
  free(dna);


  return 0;
}



