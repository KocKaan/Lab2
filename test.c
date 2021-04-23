#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int getword(char *word, int lim);
#define BUFSIZE 100
  char buf[BUFSIZE];
  int  bufp = 0;
int main(){

  //insertFront2D kaan
 char sentence[20];
 char sentence2[20];
  int counter=0;
    while (getword(sentence,20) != EOF){
  //  if(getword(sentence2,20))

       if(strcmp(sentence,"insertFront2D")==0){
         getword(sentence2,20);

         printf("sentence1 is: %s and 2 is %s\n",sentence,sentence2 );

       }
  //    printf("first line %s\n",sentence);



    //  printf("second line %s\n",newString[1]);
      //printf("third line %s\n",newString[2]);



  }
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
int getch(void) {
    return (bufp>0) ? buf[--bufp] : getchar();
  }
  void ungetch(int c) {
    if (bufp >= BUFSIZE)
      printf("ungetch: too many chars\n");
    else
      buf[bufp++] = c;
  }
