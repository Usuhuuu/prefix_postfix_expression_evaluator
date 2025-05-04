#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop()
{
    if (!top)
    {
        printf("Error: Stack underflow.\n");
        exit(1);
    }
    int val = top->data;
    Node *temp = top;
    top = top->next;
    free(temp);
    return val;
}

void clearStack()
{
    while (top)
    {
        pop();
    }
}

// ---------------- Expression Evaluation ----------------
int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return (int)pow(a, b);
    default:
        printf("Invalid operator: %c\n", op);
        exit(1);
    }
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int evaluatePostfix(const char *expr)
{
    clearStack();
    for (int i = 0; expr[i]; i++)
    {
        char ch = expr[i];
        if (isspace(ch))
            continue;
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else if (isOperator(ch))
        {
            int b = pop();
            int a = pop();
            push(applyOp(a, b, ch));
        }
        else
        {
            printf("Invalid character: %c\n", ch);
            exit(1);
        }
    }
    return pop();
}

int evaluatePrefix(const char *expr)
{
    clearStack();
    int len = strlen(expr);
    for (int i = len - 1; i >= 0; i--)
    {
        char ch = expr[i];
        if (isspace(ch))
            continue;
        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else if (isOperator(ch))
        {
            int a = pop();
            int b = pop();
            push(applyOp(a, b, ch));
        }
        else
        {
            printf("Invalid character: %c\n", ch);
            exit(1);
        }
    }
    return pop();
}

int detectType(const char *expr)
{
    int i = 0;
    while (expr[i] && isspace(expr[i]))
        i++;
    if (isOperator(expr[i]))
        return 2; // prefix

    int len = strlen(expr);
    int j = len - 1;
    while (j >= 0 && isspace(expr[j]))
        j--;
    if (isOperator(expr[j]))
        return 1; // postfix

    return 0;
}

int main()
{
    char expr[100];
    printf("Enter prefix or postfix expression :\n> ");
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';

    int type = detectType(expr);

    int result;
    if (type == 1)
    {
        result = evaluatePostfix(expr);
        printf("Postfix Result = %d\n", result);
    }
    else if (type == 2)
    {
        result = evaluatePrefix(expr);
        printf("Prefix Result = %d\n", result);
    }
    else
    {
        printf("Could not detect expression type.\n");
    }

    return 0;
}