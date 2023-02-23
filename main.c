#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"
#include "stack.h"
char *checkParenthesis(StackPtr s, char *str);

int main(int argc, char **argv){
  Stack s;
  s.top = NULL;
  s.size = 0;

  for(int i=1; i<argc; i++){
    printf("argv %d %s\n", i, checkParenthesis(&s,argv[i]));
    pop_all(&s);
  }
  return 0;
}

char *checkParenthesis(StackPtr s, char *str){
  for(int i=0; i<strlen(str); i++){
    //push open parenthesis
    if(str[i]=='(' || str[i]=='{' || str[i]=='[') push(s,str[i]);
    //pop closed parenthesis
    else if(str[i]==')' || str[i]=='}' || str[i]==']'){

      if(s->size == 0) return "incorrect: too many closed parenthesis";
      
      else{
        char temp = pop(s);
        if(temp == '(' && str[i]!=')') return "incorrect: mismatch";
        if(temp == '{' && str[i]!='}') return "incorrect: mismatch";
        if(temp == '[' && str[i]!=']') return "incorrect: mismatch";
      }

    }
  }
  if(s->size == 0) return "correct";
  else return "incorrect: too many open parenthesis";
}