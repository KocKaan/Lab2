#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int getword(char *word, int lim);
#define BUFSIZE 100
  char buf[BUFSIZE];
  int  bufp = 0;
struct node1d {
    struct node1d *next;
    char *name;
  };
  struct node2d {
    struct node1d *first;
    char *name;
    struct node2d *down;
  };
int main(){

  //insertFront2D name
 char sentence[20];

  while (getword(sentence,20) != EOF){
    printf("looped times\n");

    char newString[20][20];
    int i,j,ctr;

    j=0; ctr=0;
    for(i=0;i<=(strlen(sentence));i++){
        // if space or NULL found, assign NULL into newString[ctr]
        if(sentence[i]==' '||sentence[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            newString[ctr][j]=sentence[i];
            j++;
        }
    }
    printf("first line %s\n",newString[0]);
    printf("second line %s\n",newString[1]);
    printf("third line %s\n",newString[2]);
  /*  if("inserFront2D"){
      struct node2d* head=NULL;
      head= (struct node2d*)malloc(sizeof(struct node2d));
      head->data ="name";
      head->first= NULL;
      head->down= NULL;*/
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