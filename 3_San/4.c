// Compile with: gcc -s -O0 -fsanitize=address
#include <stdio.h>
#include <stdlib.h>

int main() {
  // no buffering, avoids the need for fflush all the time
  setvbuf(stdout, NULL, _IONBF, 0);

  char* command = malloc(3);
  command[0] = 'l';
  command[1] = 's';
  command[2] = '\0';

  char* buffer = malloc(10);

  for (int n = 0; n < 2; n++) {
    int pos;
    char val;
    printf("Which position do you want to write into the buffer, and what do you want to write? ");
    scanf("%d %c", &pos, &val);
    buffer[pos] = val;
  }
  system(command);
}
