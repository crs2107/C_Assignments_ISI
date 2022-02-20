// C program to convert infix expression to postfix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack Stack;
struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};


Stack* creating_Stack( unsigned capacity )
{
    Stack* stack = ( Stack*)malloc(sizeof( Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;

	stack->array = (int*) malloc(stack->capacity *sizeof(int));

	return stack;
}
int is_empty(Stack* stack)
{
	return stack->top == -1 ;
}
char peek( Stack* stack)
{
	return stack->array[stack->top];
}
char pop( Stack* stack)
{
	if (!is_empty(stack))
		return stack->array[stack->top--] ;
	return '$';
}
void push( Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}



int is_operand(char ch)
{
	return (ch >= 'a' && ch <= 'z') ||
		(ch >= 'A' && ch <= 'Z');
}


int Precedence(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

int infix_to_postfix(char* exp)
{
	int i, k;

    Stack* stack = creating_Stack(strlen(exp));
	if(!stack) 
		return -1 ;

	for (i = 0, k = -1; exp[i]; ++i)
	{
		
		if (is_operand(exp[i]))
			exp[++k] = exp[i];
		
		
		else if (exp[i] == '(')
			push(stack, exp[i]);
		
		
		else if (exp[i] == ')')
		{
			while (!is_empty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!is_empty(stack) && peek(stack) != '(')
				return -1; 			
			else
				pop(stack);
		}
		else
		{
			while (!is_empty(stack) && Precedence(exp[i]) <= Precedence(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}

	}

	
	while (!is_empty(stack))
		exp[++k] = pop(stack );

	exp[++k] = '\0';
	printf( "%s", exp );
}


int main()
{
	char exp[] = "a+b*c/b^e+(c-f)";
	infix_to_postfix(exp);
    printf("\n");
	return 0;
}

