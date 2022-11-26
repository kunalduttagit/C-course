//
//  InfixToPostfixC.c
//  C++ course
//
//  Created by Kunal Dutta on 26/11/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/*========== FUNCTION PROTOTYPES ============*/

int precedence(char);
int isOperand(char);
char *infixToPostfix(char *);

int isOperandPlus(char);
char *infixToPostfixPlus(char *);
int precedenceOutStackPlus(char);
int precedenceInStackPlus(char);

/*========== MAIN FUNCTION============*/

int main(void)
{
    char *infix = "a+b*c-d/e";
    //push('#');
    char *infixPlus = "((a+b)*c)-d^e^f";    //pointer to a char string
    char *postfix = infixToPostfixPlus(infix);
    char *postfixPlus = infixToPostfixPlus(infixPlus);
    printf("%s\n", postfix);
    printf("%s\n", postfixPlus);
}

/*========== INFIX TO POSTFIX ============*/

int precedence(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if (x=='*' || x=='/')
        return 2;
    return 0;
}

int isOperand(char x)
{
    if(x=='+' || x=='-'|| x=='*' || x=='/')
        return 0;
    return 1;
}

char *infixToPostfix(char *infix)
{
    int i=0, j=0;
    char *postfix;
    int length = (int)strlen(infix);    //typcasted to silence warning "Implicit conversion loses integer precision: 'unsigned long' to 'int'"
    postfix = (char *)malloc((length+1)*sizeof(char));
    
    while(infix[i] != '\0')
    {
        if(isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(precedence(infix[i]) > precedence(stackTop()) )
               push(infix[i++]);
            else
               postfix[j++] = pop();
        }
    }
    while(top)
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

/*========== INFIX TO POSTFIX PLUS ============*/

int precedenceOutStackPlus(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if (x=='*' || x=='/')
        return 3;
    else if (x=='^')
        return 6; //R-L, so value increases from in to out
    else if (x=='(')
        return 7;
    return 0;
}

int precedenceInStackPlus(char x)
{
    if(x=='+' || x=='-')
        return 2;
    else if (x=='*' || x=='/')
        return 4;
    else if (x=='^')
        return 5; //R-L, so value decreses from out to in
    return 0;
}

int isOperandPlus(char x)
{
    if(x=='+' || x=='-'|| x=='*' || x=='/' || x=='^' || x=='(' || x==')')
        return 0;
    return 1;
}

char *infixToPostfixPlus(char *infix)
{
    //push('#'); // push an arbitary character in the stack ('#' in this case)
    int i=0, j=0;   // 'i' for indexing infix, 'j' for indexing postfix
    char *postfix;
    int length = (int)strlen(infix);    //typcasted to silence warning "Implicit conversion loses integer precision: 'unsigned long' to 'int'"
    postfix = (char *)malloc((length+2)*sizeof(char)); // +1 for '\0', +1 for arbitary char(if required)
    
    while(infix[i] != '\0')
    {
        if(isOperandPlus(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if(precedenceOutStackPlus(infix[i]) > precedenceInStackPlus(stackTop()) )
                    push(infix[i++]);
            else
            {
                if(precedenceInStackPlus(stackTop()) != 0)
                    postfix[j++] = pop();
                else
                {
                    pop();
                    i++;
                }
            }// end of operand else
        }//end of first else
    }//end of while
    while(top)
        postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}
