#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>

#define StackLimit 100

typedef char StackElementType;

typedef struct{
int Top;
StackElementType Elements[StackLimit];
}StackType;

struct Transition{
int source;
char c;
int target;
char push;
char pop;
};

    FILE *fin;
    char inputfilename[30],input[255],ans;
    struct  Transition *transitions;
    struct StackType *stack1;
    int n,i,j;
    int nTrasitions;
    int initial;
    int nfinals;



void CreateStack(StackType *Stack){
  Stack->Top= -1;
}
bool EmptyStack(StackType Stack){
  return (Stack.Top==-1);
}
bool FullStack(StackType Stack){
  return (Stack.Top == (StackLimit-1));
}
void Pop(StackType *Stack, StackElementType *item){
  if(!EmptyStack(*Stack)){
      *item=Stack->Elements[Stack->Top];
      Stack->Top--;
  }
  else{
      printf("The Stack is Empty!");
      printf("\n");
  }
}
void Push(StackType *Stack, StackElementType item){
    if(!FullStack(*Stack)){
         Stack->Top++;
         Stack->Elements[Stack->Top] = item;
    }
    else{
         printf("The Stack is Full!");
         printf("\n");
   }
}



void check_input(char *s,struct Transition *transitions,int current){
    /*create a new stack every time we read a word*/
    StackType a;
    CreateStack(&a);
    char S='S';

    Push(&a,S);
    j=0;
    current=transitions[0].target;
    /*check every one char until the end of the string*/
   for(i=0; j<=strlen(input); i++){
        for(i=0; i<nTrasitions; i++){
          if(transitions[i].source==current  && input[j]==transitions[i].c ){
                /*if the transitions[i].push=='e' we do not want it to push it in the stack because its the space*/
                if(transitions[i].push!='e'){
                       Push(&a,transitions[i].push);
                       /*current take the value of the target state*/
                       current=transitions[i].target;
                       break;
                }
                 /*if the transitions[i].pop=='e' we do not want it to pop it out of the stack because its the space*/
                else if( transitions[i].pop!='e' && !EmptyStack(a)){
                     /*with this if we check if the pop item is the right according to the transition*/
                     if(transitions[i].pop==a.Elements[a.Top]){
                           Pop(&a,&a.Elements[a.Top]);
                           /*current take the value of the target state*/
                           current=transitions[i].target;
                     }
                     /*if not then the word is wrong and the checks stops*/
                     else {
                           printf("Not accepted!\n");
                           printf("Current state:%d\n",current+1);

                            return 0;
                     }
                     if(EmptyStack(a))current=transitions[i+1].target;
                         break;
                }
                else current=transitions[i].target;
          }/*this if check if the word has reach the end*/
          else if(transitions[i].source==current && transitions[i].c=='#'  && input[j]=='\0'){
              current = transitions[i].target;
              j=0;
              break;
          }
          else if(transitions[i].source==current && transitions[i].c=='e'){
                    if(transitions[i].push!='e'){
                       Push(&a,transitions[i].push);
                       current=transitions[i].target;
                       break;
                    }
                    else if( transitions[i].pop!='e' && !EmptyStack(a)){
                       if(transitions[i].pop==a.Elements[a.Top]){
                           Pop(&a,&a.Elements[a.Top]);
                           current=transitions[i].target;
                           break;
                       }
                    }/*if the transition is source e e target*/
                    else{
                        current=transitions[i].target;
                    }
         }
        }
  j++;}

        if(EmptyStack(a) && current==nfinals ){
          printf("WORD ACCEPTED\n");
          printf("Current state:%d\n",current+1);
        }
        else{
          printf("Not accepted!\n");
          printf("Current state:%d\n",current+1);
        }
}






int main(){

     while (TRUE){
              printf("Give input file name: ");
              gets(inputfilename);
              fin = fopen(inputfilename, "r");
              if (fin!='\0')break;
              printf("cannot open input file %s. Try again.\n", inputfilename);
     }
     /*number of initial states*/
     fscanf(fin,"%d",&n);
     fscanf(fin,"%d",&initial);
     initial--;
     /*number of finals states*/
     fscanf(fin,"%d",&nfinals);
     nfinals--;

     /*read and fill the transitions into the structure*/
     fscanf(fin,"%d",&nTrasitions);
     struct Transition  *transitions =malloc(nTrasitions*sizeof(struct Transition));

     for(i=0; i<nTrasitions; i++){
         fscanf(fin,"%d",&transitions[i].source);
         fscanf(fin,"%c",&transitions[i].c);
         fscanf(fin,"%c",&transitions[i].pop);
         fscanf(fin,"%c",&transitions[i].push);
         fscanf(fin,"%d",&transitions[i].target);
         transitions[i].source--;
         transitions[i].target--;
     }
     fclose(fin);
     do{
            printf("Give a word:");
            scanf("%s",input);
            check_input(input,transitions,initial);
            printf("Continue Y/N: ");
            do{
                scanf("%c", &ans);
            } while (toupper(ans)!= 'N' && toupper(ans)!= 'Y');
    } while (toupper(ans)!='N');
return 1;}
