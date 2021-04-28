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
  printf("2d node name= %s\n", temp->name);

  if(temp->first!=NULL){
    struct node1d *tempo = temp->first;
    while(tempo!=NULL) {
        printf("   1d Node name= %s \n",tempo->name);
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

void insertFront1D(struct node2d *head, char *word, char *targetWord2D){

  if(head->down ==NULL) {
    printf("There is no target string on the list\n");
    exit(0);
  }

  struct node2d *node = head->down;
  while(strcmp(node->name,targetWord2D)!=0){

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

  }
}

void insertBefore1D(struct node2d *head,char *word, char *targetWord1D){
  if(head->down ==NULL) {
    printf("There is no target string on the listt\n");
    exit(0);
  }
  struct node2d *node = head->down;
  while(node!=NULL){


    if(node->first!=NULL){
      struct node1d *node1d= node->first;


      if(strcmp(node1d->name,targetWord1D)==0){
        struct node1d *temp = (struct node1d*) malloc(sizeof(struct node1d));
        temp->name= word;

        temp->next= node->first;
        node->first=temp;
        return;
      }else{
        while(strcmp(node1d->next->name,targetWord1D)!=0){
          node1d=node1d->next;
        }

        if(strcmp(node1d->next->name,targetWord1D)==0){
          struct node1d *temp = (struct node1d*) malloc(sizeof(struct node1d));
          temp->name= word;

          temp->next= node1d->next;
          node1d->next=temp;
          return;
        }

      }

    }
    node=node->down;
  }
    printf("There is no target string on the list.\n");
    exit(0);


}
void print1DList(struct node2d *head, char *targetWord2D){

  if(head->down ==NULL) {
    printf("There is no target string on the list\n");
    exit(0);
  }

  struct node2d *node = head->down;
  while(strcmp(node->name,targetWord2D)!=0){

    if(node->down==NULL){
      printf("There is no target string on the list\n" );
      exit(0);
    }
    node=node->down;

  }
  if(node->first!=NULL){
    struct node1d *tempo = node->first;
    while(tempo!=NULL) {
        printf("1d Node name= %s \n",tempo->name);
        tempo = tempo->next;
    }
  }

}

void find1D(struct node2d *head, char *targetWord1D){
  struct node2d *temp = head->down;
  while(temp!=NULL) {

  if(temp->first!=NULL){
    struct node1d *tempo = temp->first;
    while(tempo!=NULL) {
      if(strcmp(tempo->name,targetWord1D)==0){
        printf("found\n");
        return;
      }
        tempo = tempo->next;
    }
  }
    temp = temp->down;
}
printf("not found\n" );

}

void find2D(struct node2d *head, char *targetWord2D){
  struct node2d *temp = head->down;
  while(temp!=NULL) {
  if(strcmp(temp->name,targetWord2D)==0){
    printf("found\n");
    return;
  }
    temp = temp->down;
  }
  printf("not found\n");
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
    if(strcmp(sentence,"insertFront1D")==0){
      getword(word,20);
      getword(targetWord,20);

      char * word1 =(char*)malloc(strlen(word)*sizeof(char));
      strcpy(word1 ,word);

      char * targetWord1 =(char*)malloc(strlen(word)*sizeof(char));
      strcpy(targetWord1 ,targetWord);

      insertFront1D(head, word1, targetWord1);

    }
    //insertBefore1D name beforeName1D
    if(strcmp(sentence,"insertBefore1D")==0){
      getword(word,20);
      getword(targetWord,20);

      char * word1 =(char*)malloc(strlen(word)*sizeof(char));
      strcpy(word1 ,word);

      char * targetWord1 =(char*)malloc(strlen(word)*sizeof(char));
      strcpy(targetWord1 ,targetWord);

      insertBefore1D(head,word1,targetWord1);

    }

    //printAll
    if(strcmp(sentence,"printAll")==0){
      printAll(head);


      }


      //print1DList name2D
      if(strcmp(sentence,"print1DList")==0){
         getword(targetWord,20);

         char * targetWord1 =(char*)malloc(strlen(word)*sizeof(char));
         strcpy(targetWord1 ,targetWord);

         print1DList(head,targetWord1);

      }


      //find1D name1D
      if(strcmp(sentence,"find1D")==0){
        getword(targetWord,20);

        char * targetWord1 =(char*)malloc(strlen(word)*sizeof(char));
        strcpy(targetWord1 ,targetWord);

        find1D(head, targetWord1);
      }

      //find2D name2D
      if(strcmp(sentence,"find2D")==0){
        getword(targetWord,20);

        char * targetWord1 =(char*)malloc(strlen(word)*sizeof(char));
        strcpy(targetWord1 ,targetWord);

        find2D(head,targetWord1);
      }

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
