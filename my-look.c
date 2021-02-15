// Copyright 2021 Aksel Torgerson

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 80

static void exit_with_error() {
  printf("my-look: invalid command line\n");
  exit(1);
}

int main(int argc, char **argv) {
  int flag;
  char currLine[MAXLINE];
  FILE *fp;
  while ((flag = getopt(argc, argv, "Vhf:")) != -1) {
    switch (flag) {
      case 'V':
        printf("my-look from CS537 Spring 2021\n");
        exit(0);
        break;
      case 'h':
        printf("NAME\n  my-look\nUSAGE\n  Finish this later\n");
        exit(0);
        break;
      case 'f':
        fp = fopen(optarg, "r");
        if (fp == NULL) {
          printf("my-look: cannot open file\n");
          exit(1);
        }
        break;
      case '?':
        exit_with_error();
        break;
    }
  }
  // check for invalid amount of command line args
  if (optind != argc - 1) {
    exit_with_error();
  }
  // if no -f flag is provided
  if (fp == NULL) {
    fp = stdin;
  }
  // now get each line of the file (or stdin)
  while (fgets(currLine, MAXLINE, fp) != NULL) {
    int result = strncasecmp(argv[argc - 1], currLine, strlen(argv[argc - 1]));
    if (result == 0) {
      printf("%s", currLine);
    }
  }
  fclose(fp);
  return(0);
}
