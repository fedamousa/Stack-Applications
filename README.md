
# Stack-Applications
### First Application 
## Converting Infix Expression into Postfix Expression
To convert infix expression to postfix expression, we will use the stack data structure. By scanning the infix expression from left to right, when we will get any operand, simply add them to the postfix form, and for the operator and parenthesis, add them in the stack maintaining the precedence of them.
### Input and Output
#### With character
![image](https://user-images.githubusercontent.com/95087254/177017640-bd01ca81-51de-449e-9530-cdddae72953d.png)
#### With number

![image](https://user-images.githubusercontent.com/95087254/177017643-9dc370ae-005a-437e-be32-c745f4d34735.png)

### Algorithm
```

opstk= the empty stack;

while (not end of input)
{

symb=next input character;

if (symb is an operand)

add symb to the postfix string

 else
 {
while (!empty()&&prcd(stacktop(), symb))

{
topsym=pop();

add topsymbto the postfix string;

 } /*end while*/
 
 if (empty() II symb != ‘)’)
 
 push(symb);
 
 else /* pop the open parenthesis and discard it */
 
 topsymb= pop();
 
} /* end else*/

} /* end while*/

/*output any remaining operators*/

while (!empty())
{
topsymb=pop();

add topsymb to the postfix string;
} /* end while*/ 
```
### Second Application 
## Evaluating a postfix expression
From the postfix expression, when some operands are found, pushed them in the stack. When some operator is found, two items are popped from the stack and the operation is performed in correct sequence. After that, the result is also pushed in the stack for future use. After completing the whole expression, the final result is also stored in the stack top.
### Input and Output
![image](https://user-images.githubusercontent.com/95087254/177017687-fb52a745-164d-4347-b206-ec635caebdf7.png)
### Algorithm
```
Opndstk= the empty stack;
/* scan the input string reading one element at a time into
symb*/
while (not end of input)
{
symb=next input character;
if (symb is an operand)
push(symb);
else
{
/* symb is an operator*/
opnd2=pop();
opnd1=pop();
value=resulr of applying symb to opnd1 and
opnd2;
push(value);
} /* end else*/
} /* end while*/
return (pop());
```
