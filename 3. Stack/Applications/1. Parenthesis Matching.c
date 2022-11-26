//
//  Parenthesis Matching.c
//  C++ course
//
//  Created by Kunal Dutta on 26/11/22.
//

#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

//typedef struct node node;
//struct node {
//    char data;
//    node *next;
//}*top = NULL;    //one global pointer, iff one stack is to be created


int isBalanced(char *exp)
{
    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i] == '(')
        {
            push(exp[i]);
        }
        else if(exp[i] == ')')
        {
            if(top == NULL)
            {
                return 0;
            }
            pop();
        }
    }
    return top==NULL;
}

int isBalancedPlus(char *exp)
{
    for(int i=0; exp[i] != '\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
            push(exp[i]);
        else if((exp[i]==')' || exp[i]==']' || exp[i]=='}') ) {
                if(top == NULL) return 0;
                else if((exp[i]==')' && top->data == '(')||
                        (exp[i]==']' && top->data == '[')||
                        (exp[i]=='}' && top->data == '{') )
                    pop();
            }
    }
    return top==NULL;
}

int main(void)
{
    char *exp = "((a+b)*(c-d))";
    char *expPlus = "{(a+b)/[a+(b-c)]}";
    printf("%d ", isBalancedPlus(exp));
    printf("%d ", isBalancedPlus(expPlus));
    display();
}

