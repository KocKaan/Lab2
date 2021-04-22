#include <stdio.h>

int getword(char *word, int lim)
int main(){
  struct node1d {
      struct node1d *next;
      char *name;
    };
    struct node2d {
      struct node1d *first;
      char *name;
      struct node2d *down;
    };




}
int getword(char *word, int lim) {
int c, getch(void);
void ungetch(int);
char *w = word;
while (isspace(c = getch())) ;
if (c != EOF)
  *w++ = c;
if (!isalpha(c)) {
  *w = '\0';
  return c;
}
for ( ; --lim > 0; w++)
  if (!isalnum(*w = getch())) {
    ungetch(*w);
    break;
  }
*w = '\0';
return word[0];
}
