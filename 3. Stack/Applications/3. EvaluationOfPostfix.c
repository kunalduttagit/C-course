//
//  EvaluationOfPostfix.c
//  C++ course
//
//  Created by Kunal Dutta on 26/11/22.
//

#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>

int isOperand(char);
int evaluate(char *);

int main(void)
{
    char *postfix = "234+*82/-";
    printf("Result is: %d\n", evaluate(postfix));
}

int evaluate(char *postfix)
{
    int leftOperand, rightOperand, result = 0;
    
    for(int i=0; postfix[i] != '\0'; i++)
    {
        if(isOperand(postfix[i]))
            push(postfix[i] - '0');
        else
        {
            rightOperand = pop();
            leftOperand = pop();
            switch(postfix[i])
            {
                case '+': result = leftOperand + rightOperand; break;
                case '-': result = leftOperand - rightOperand; break;
                case '*': result = leftOperand * rightOperand; break;
                case '/': result = leftOperand / rightOperand; break;
            }
            push(result);
        }
    }
    
    return result;
}

int isOperand(char x)
{
    if(x=='+' || x=='-'|| x=='*' || x=='/')
        return 0;
    return 1;
}
