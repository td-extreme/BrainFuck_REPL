#include "stdio.h"
#include "stdlib.h"

char *cells;
char *cell;


void executeCommand(char command);

void runLoop(char * start) {
  while (*start != ']') {
    executeCommand(*start);
    ++start;
  }
}

void brainFuckLoop() {
  char wLoop[1024];
  char * ptrwLoop = wLoop;

  while (*ptrwLoop != ']') {
    ++ptrwLoop;
    *ptrwLoop = getchar();
  }

  while ( *cell != 0) {
    runLoop(wLoop);
  }
  return;
}

void printCells() {
  int current_cell = cell - cells;
  printf("Current Cell : %d\n", current_cell);
  int i;
  printf("\n|");
  for (i = 0; i < 32; ++i) {
    printf("%3d|", i);
  }
  printf("\n|");
  for (i = 0; i < 127; ++i) {
    printf("-");
  }
  printf("|\n|");
  for (i = 0; i < 32; ++i) {
    printf("%3u|", cells[i]);
  }
  printf("\n");
}

void executeCommand(char command) {
   switch(command) {
      case '<':
        --cell;
        break;

      case '>':
        ++cell;
        break;

      case '+':
        ++*cell;
        break;

      case '-':
        --*cell;
        break;

      case '.':
        printf("%c", *cell);
        break;

      case ',':
        *cell = getchar();
        break;

      case 'm':
        printCells();
        break;

      case 'r':
        cell = cells;
        break;

      case 'q':
        exit(0);
        break;
   }
}

void executeStream(unsigned char * stream) {
  unsigned char * iterStream = stream;
  do {
    executeCommand(*iterStream);
    ++iterStream;
  } while (*iterStream != '\n');
  printf("\n");
}

int main() {
  cells = malloc(sizeof(char) * 30000);
  cell = cells;
  unsigned char input;
  unsigned char * inputStream;
  unsigned char * iterInputStream;

  while (1) {
    printf("cell= %d value= %d $) ", (int)(cell - cells), *cell);
    inputStream = malloc(sizeof(char) * 1024);
    iterInputStream = inputStream;
    while (*iterInputStream != '\n') {
      ++iterInputStream;
      *iterInputStream = getchar();
    }
    executeStream(inputStream);
    free(inputStream);
   }
  return 0;
}
