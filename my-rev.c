// Copyright 2021 Aksel Torgerson

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

static void exit_with_error() {
  printf("my-rev: invalid command line\n");
  exit(1);
}

int main(int argc, char **argv) {
  int flag;
  char currLine[MAXLINE];
  FILE *fp;
  while ((flag = getopt(argc, argv, "Vhf:")) != -1) {
    switch (flag) {
      case 'V':
        printf("my-rev from CS537 Spring 2021\n");
        exit(0);
        break;
      case 'h':
        printf("NAME\n  my-rev\nUSAGE\n Finish this later\n");
        exit(0);
        break;
      case 'f':
        fp = fopen(optarg, "r");
        if (fp == NULL) {
          printf("my-rev: cannot open file\n");
          exit(1);
        }
        break;
      default:
        exit_with_error();
        break;
    }
  }
  if (optind != argc) {
    exit_with_error();
  }
  // if no -f flag is provided
  if (fp == NULL) {
    fp = stdin;
  }
  // now we will reverse each line of the file (or stdin)
  while (fgets(currLine, MAXLINE, fp) != NULL) {
    char *startChar = currLine;
    char *endChar = startChar + strlen(currLine) - 1;
    char tempChar;
    while (endChar > startChar) {
      if (*endChar == '\n') {
        endChar--;
      }
      tempChar = *startChar;
      *startChar = *endChar;
      *endChar = tempChar;
      startChar++;
      endChar--;
    }
    printf("%s", currLine);
  }
  fclose(fp);
  return(0);
}
