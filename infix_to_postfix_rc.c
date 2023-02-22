#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100
struct stack
{
    char arr[MAX];
    int top;
};
void init(struct stack *s)
{
    for(int i=0;i<MAX;i++)

        {
            s->arr[i] ='\0';
        }
    s->top = -1;
}
int is_empty(struct stack *s)
{
    if (s->top == -1)
        return 1;
    else 
        return 0;

}
int is_full(struct stack *s)
{
    if(s->top == MAX-1)
        {
            return 1;
        }
    else
        {
            return 0;
        }

}
void push(struct stack *s,char val)
{
    if(!is_full(s))
    {
        s->top++;
        s->arr[s->top] = val;

    } 
    else{
        printf("Stack is full.\n");
    }
}
char pop(struct stack *s)
{
    if(!is_empty(s))
    {
        s->top = s->top - 1;
        return s->arr[s->top+1];
    }
    else {
        printf("Stack is empty.\n");

    }
}
int is_operand(char c)
{
    if(c == '^' || c == '%'|| c == '*'|| c == '/'|| c == '+'|| c == '-'|| c == '('|| c == ')')

        return 0;
    else 
        return 1;
}
int priority(char d)
{
    if(d == '^')
    {
        return 3;
    }
    if(d == '*'|| d == '/'|| d == '%')
    {
        return 2;
    }
    if(d == '+'|| d == '-')
    {
        return 1;
    }
    if(d == '('|| d == ')')
    {
        return 0;
    }
}
void infix_to_postfix(struct stack *in,struct stack *po,struct stack *op)
{
    while(!is_empty(in))
    {
    if(is_operand(in->arr[in->top])==1)
    {
        push(po,pop(in));
    }
    else if(in->arr[in->top]=='(')
    {
        push(op,pop(in));
    }
    else if(in->arr[in->top]==')')
    {
        while(op->arr[op->top]!='(')
        {
            push(po,pop(op));
            
        }
        int x = pop(op);
        x = pop(in);
    }
    else if(priority(in->arr[in->top])>priority((op->arr[op->top])))
    {
        push(op,pop(in));
    }
    else{
        push(po,pop(op));
    }
    

    }
    while(!is_empty(op))
    {
        push(po,pop(op));
    }
}
int main()
{
    char *ar=(char *)calloc(MAX,sizeof(char));
    printf("Enter the infix expression: \n");
    scanf("%[^\n]s",ar);
    struct stack *infix,*postfix,*operator;
    infix=(struct stack *)malloc(sizeof(struct stack));
    postfix=(struct stack *)malloc(sizeof(struct stack));
    operator=(struct stack *)malloc(sizeof(struct stack));
    init(infix);
    init(postfix);
    init(operator);
    for(int i=strlen(ar)-1;i>=0;i--)
    {
        if(ar[i]!='\0')
            push(infix,ar[i]);
    }
    infix_to_postfix(infix,postfix,operator);

    printf("The postfix expression is: \n%s",postfix);

    return 0;
}
/*Enter the infix expression: 
a+b/c*(d+e)-f
The postfix expression is: 
abc/de+*+f-
Enter the infix expression: 
a^b*c/(d*e-f)
The postfix expression is: 
ab^c*de*f-/
*/