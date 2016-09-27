#include "stdio.h"

char cells[32] = {0};
char *cell = cells;

unsigned char input;

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

      case '[':
        brainFuckLoop();
        break;

      case 'm':
        printCells();
        break;
//      case 10:
//        printf(" $ ");
   }
}

int main() {
  while ( input != 'q' ) {
    input = getchar();
    executeCommand(input);
   }
  return 0;
}
