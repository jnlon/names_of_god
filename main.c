#include <stdio.h>
#include <string.h>

// P(18, 9) returns 17 billion, which should get us close to 9 billion if we filter
// out combinations with more than 3 consecutive duplicate letters. There are
// supposedly more rules (and perhaps more letters) that are not detailed in the short story
// START_LETTER - END_LETTER = 18
#define START_LETTER 65
#define END_LETTER 83

// Does buf have at least maxdup consecutive duplicate letters?
int has_cons_dups(char* buf, int maxdup) {

  int i = 0;
  char last = 0;
  int dups = 0;
  while (buf[i] != 0) {

    if (last == buf[i]) {
      dups += 1;
      if (dups == maxdup-1)
        return 1;
    }

    last = buf[i];
    i += 1;
  }
  return 0;
}

void permute(char* buf, int limit, int at) {

  if (at >= limit) {
    if (has_cons_dups(buf, 3)) 
      return;
    puts(buf);
    return;
  }

  int letter;
  for (letter = START_LETTER; letter <= END_LETTER ; letter++) {
    buf[at] = letter;
    permute(buf, limit, at+1);
  }
}

int main(int argc, char *argv[]) {

  char names[9];
  memset(names, 0, 9);
  int limit;
  for (limit=1;limit<=9;limit++) {
    memset(names, START_LETTER, limit);
    permute(names, limit, 0);
  }

  puts("You may want to check the stars...\n");

  return 0;
}
