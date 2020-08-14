/** 
 * Copyright August 2020: Georg Pohl, 70174 Stuttgart
 * File: cpyFileWoComments.c
 * -------------------------
 * Copies a (skeleton) file with comments into another
 * (working) file without copying annoying comments.
 * Comments must be surrounded by two self-chosen, but
 * equal, single-character delimiters,
 *
 * If delimiters are unequal, you have to provide
 * three arguments, otherwise only two.
 * 
 * Two examples:
 * #comment# =>  ./cpyFileWoComments 'source filename' '#'
 *
 * not possisble a.t.m.
 * <comment> =>  ./cpyFileWoComments 'source filename' '<' '>'
 * 
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

  // Check input arguments
  if ( argc < 2) {
    printf("Usage: ./cpyFileWoComments <source filename> 'startDelimiter', 'endDelimiter' (2nd optional, if the same)\n");
    return EXIT_FAILURE;
  }
  if ( (infile = fopen(argv[1], "r")) == NULL ) {
    fprintf(stderr, "Could not open source file!\n");
    return EXIT_FAILURE;
  }
  // Create output filename and file
  char outFileName[MAX];
  strncpy(outFileName, argv[1], MAX-4);
  strcat(outFileName, "_cpy");
  if ( (outfile = fopen(outFileName, "w")) == NULL ) {
    fprintf(stderr, "Could not open copy file!\n");
    return EXIT_FAILURE;
  }
  // Copy only relevant Bytes
  int ch;
  int del = argv[2][0];
  while ( (ch = fgetc(infile)) != EOF ) {
    if (ch == del) {
      do {
	ch = fgetc(infile);
      } while (ch != del);
      
    }
    else {
      fputc(ch, outfile);
    }
  }
  // Close all opened files
  fclose(infile);
  fclose(outfile);

  return EXIT_SUCCESS;
} /* main {} [] \n ~ | */

/* FUNCTIONS */
