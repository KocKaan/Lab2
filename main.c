#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int getword(char *word, int lim);

#define BUFSIZE 300
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
//struct node2d* head=NULL;


void insertFront2D(struct node2d *head, char *word){
  struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
  temp->name = word;
  //temp->down=NULL;

    temp->down = head->down;
    head->down= temp;
    temp->first=NULL;

}
void printAll(struct node2d *head){
  struct node2d *temp = head->down;
  while(temp!=NULL) {
  //  print_list(temp->first);
  printf("2d node: %s\n", temp->name);
  printf("\n");
  if(temp->first!=NULL){
    struct node1d *tempo = temp->first;
    while(tempo!=NULL) {
        printf("1d Node: %s ",tempo->name);
        tempo = tempo->next;
    }
  }
    temp = temp->down;
}
}

void insertBefore2D(struct node2d *head, char *word, char *targetWord){
  if(head->down ==NULL) {
    printf("There is no target string on the list\n");
    exit(0);
  }else{
      struct node2d *node = head ;
      while(strcmp(node->down->name,targetWord)!=0) {

        if(node->down==NULL){
          printf("There is no target string on the list\n");
          exit(0);
        }
        node=node->down;

      }
      struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
      temp->name = word;

      temp->down = node->down;
      node->down = temp;

      temp->first=NULL;
  }
}

void insertFront1D(struct node2d *head, char *word, char *targetWord){

  struct node2d *node = head->down;
  while(strcmp(node->name,targetWord)!=0){

    if(node->down==NULL){
      printf("There is no target string on the list\n" );
      exit(0);
    }
    node=node->down;

  }

  if(node->first==NULL){
    struct node1d *temp = (struct node1d*) malloc(sizeof(struct node1d));
    temp->name= word;
    node->first= temp;
    temp->next= NULL;

  }else{
    struct node1d *temp = (struct node1d*) malloc(sizeof(struct node1d));
    temp->name= word;

    temp->next= node->first;
    node->first=temp;
    temp->next=NULL;
  }
}







int main(){
  char sentence[20];
  char word[20];
  char targetWord[20];
  struct node2d* head = (struct node2d*) malloc(sizeof(struct node2d));
  head->down=NULL;

  while (getword(sentence,20) != EOF){
      //insertFront2D name
    if(strcmp(sentence,"insertFront2D")==0){

      getword(word,20);
      char * word1 =(char*)malloc(strlen(word)*sizeof(char));
      strcpy(word1 ,word);

      insertFront2D(head,word1);

    }

     //insertbefore2D name beforename
    if(strcmp(sentence,"insertBefore2D")==0){
      getword(word,20);
      getword(targetWord,20);

      char * word1 =(char*)malloc(strlen(word)*sizeof(char));
      strcpy(word1 ,word);

      char * targetWord1 =(char*)malloc(strlen(word)*sizeof(char));
      strcpy(targetWord1 ,targetWord);

      insertBefore2D(head, word1, targetWord1);

    }



    //insertFront1D name name2D
    if(strcmp(sentence,"insertBefore1D")==0){
      getword(word,20);
      getword(targetWord,20);

      char * word1 =(char*)malloc(strlen(word)*sizeof(char));
      strcpy(word1 ,word);

      char * targetWord1 =(char*)malloc(strlen(word)*sizeof(char));
      strcpy(targetWord1 ,targetWord);

      insertFront1D(head, word1, targetWord1);

    }

    //printAll
    if(strcmp(sentence,"printAll")==0){
      printAll(head);


      }


      //somethinf

      }
  //    printf("head name: %s\n",head->down->name);
    //  printf("head next name: %s\n",head->down->down->name);
      //printf("head next next name: %s\n",head->down->down->down->name);

  }


  /*insertFront2D name NAME IS VARIABLE AS WORD
  struct node2d* insert_node2d_head(struct node2d *head, char *word) {
      struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
      temp->name = word;
      if(head==NULL) {
          temp->next = NULL;
          head = temp;
      }
      else {
          temp->next = head->next;
          head->next = temp;
      }
      return head;
  }*/


  /* insertbefore2D name beforename
    struct node2d* insert_node2d_tail(struct node2d *head, char *word, char *targetWord) {
      if(head==NULL) {
        printf("There is no target string on the list\n");
        exit(0);
      }else if(head->name==targetWord){
        struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
        temp->name = word;
        temp->next = head->next;
        head->next = temp;
      }

      else {
          struct node2d *node = head;
          while(node->next->name!=targetWord) {

            if(node->next!=NULL){
              printf("There is no target string on the list\n");
              exit(0);
            }
            node=node->next;

          }
          struct node2d *temp = (struct node2d*) malloc(sizeof(struct node2d));
          temp->data = word;

          temp->next = node->next;
          node->next = temp;
          return head;
      }
  }*/

  /*insertFront1D name name2D
  struct node2d* insert_node2d_tail(struct node2d *head, char *word, char *targetWord){

    if(head==NULL){
      printf("There is no target string on the list\n" );
      exit(0);
    }
    struct node2d *node = head;
    while(node->name!=targetWord){

      if(node->next==NULL){
        printf("There is no target string on the list\n" );
        exit(0);
      }
      node=node->next;

    }

    if(node->first==NULL){
      struct node1d *temp = (struct node1d*) malloc(sizeof(struct node1d));
      temp->name= word;
      node->first= temp;
      temp->next= NULL;

    }else{
      struct node1d *temp = (struct node1d*) malloc(sizeof(struct node1d));
      temp->name= word;

      temp->next= node->first;
      node->next=temp;
    }

  }*/

  //insertBefore1D name beforeName1D





/*  void print_list(struct node1d *head);
  void print_list(struct node1d *head) {
      struct node1d *temp = head;
      while(temp!=NULL) {
          printf("%s ",temp->name);
          temp = temp->next;
      }
      printf("\n");
  }*/




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
