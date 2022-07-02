#include <iostream>
#include <string>
using namespace std;


struct node {
char info;
node* next; };


class StackOfOperations {
    private :
        node* top;
    public :
        StackOfOperations(){ top=NULL; }

        bool isempty() { return (top == NULL);}

        void push(char item){
            node* p = new node;
            p->info=item;
            p->next = top;
            top=p; }

        char pop(){
            if (isempty()) {
                    cout<<"underflow";
            return -1; }
            node* t = top;
            char temp = top->info;
            top=top->next;
            delete t;
            return temp; }

            char peak (){
                if(isempty()){
                        cout<<"empty";
                return -1; }
                return top->info; } }; //class end

            int priority (char operand){
                if(operand == '+' || operand =='-')
                    return 1;
                if(operand == '*' || operand =='/')
                    return 2;
                if(operand == '^')
                    return 3;
                    return 0; }

             bool Precedence(char op1, char op2) {
                 int op1_priority = priority(op1);
                 int op2_priority = priority(op2);
                 if (op1== '(' || op2 =='(')
                                return false;
                 else if (op2 == ')')
                    return true ;
                 else if ( op1== '^' || op2 =='^')
                    return false;
                 else return op1_priority > op2_priority ? true: false; }

int main(){
string infix,postfix; int i =0;

StackOfOperations stackk;
char symbol, topp;

cout<<"Enter Infix Expression : "<<infix;

getline(cin,infix);

 while (i != infix.length()) {
        symbol = infix[i];
 if(symbol == ' ' ){ i++; continue; }

 else if((infix[i]>='a' && infix[i]<='z')|| (infix[i]>='A'&& infix[i]<='Z') || (infix[i]>='1'&& infix[i]<='9')) {
        postfix += symbol; i++; }
 else {
        while (!stackk.isempty() && Precedence(stackk.peak(), symbol) ){
            topp = stackk.pop();
            postfix+= topp; }
            if (stackk.isempty() || symbol != ')')
                stackk.push(symbol);
            else { topp= stackk.pop(); } i++; }//end else
            }//end while

while(!stackk.isempty()){
        topp= stackk.pop();
        postfix+= topp; }

cout<<"\nInfix Expression into Postfix Expression = "<<postfix; } // end main
