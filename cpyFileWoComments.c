/** 
 * Copyright July 2020: Georg Pohl, 70174 Stuttgart
 * File: cpyFileWoComments.c
 * --------
 * Copies a file with comments into another file without
 * copying annoying comments. Comments must be surrounded
 * by two equal delimiters.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

/* CONSTANTS */

/* STRUCTS */

/* PROTOTYPES */


int main(int argc, const char **argv) {
  FILE *infile, *outfile;

  if ( argc < 2) {
    printf("Usage: ./cpyFileWoComments <source filename> '<startDelimiter>', '<endDelimiter>' (optional)\n");
    return EXIT_FAILURE;
  }
  if ( (infile = fopen(argv[1], "r")) == NULL ) {
    fprintf(stderr, "Fehler beim Oeffnen der Originaldatei!\n");
    return EXIT_FAILURE;
  }

  char outFileName[255];
  strcpy(outFileName, argv[1]);
  strcat(outFileName, "_cpy");
  if ( (outfile = fopen(outFileName, "w")) == NULL ) {
    fprintf(stderr, "Fehler beim Oeffnen der Kopie!\n");
    return EXIT_FAILURE;
  }
 
  int ch;
  int delStart = '%';
  //strcpy(delStart, argv[2]);
  int delEnd = '%';
  //strcpy(delEnd, argv[3]);
  while ( (ch = fgetc(infile)) != EOF ) {
    if (ch == delStart) {
      do {
	ch = fgetc(infile);
      } while (ch != delEnd);
      
    }
    else {
      fputc(ch, outfile);
    }
  }
  fclose(infile);
  fclose(outfile);

  return EXIT_SUCCESS;
} /* main {} [] \n ~ | */

/* FUNCTIONS */
