#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct node {
    int info;
    node* next; };

class opndstk {
    private :
        node* top;
    public :
        opndstk(){ top=NULL;}

        bool isempty() { return (top == NULL);}

        void push(int item){
            node* p = new node;
            p->info=item;
             p->next = top; top=p;}

        int pop(){
            if (isempty()) {
                    cout<<"underflow";
                    return -1; }

            node* t = top;
            int temp = top->info;
            top=top->next;
            delete t;
            return temp; } }; //class end

int operation(int a, int b, char op){ //Perform operation
    if(op == '+')
        return a+b;
    else if(op == '-')
        return a-b;
    else if(op == '*')
        return a*b;
    else if(op == '/')
        return a/b;
    else if(op == '^')
        return pow(a,b);
    else
        cout<<"Unexpected Error \n";
        return -1; }


int main() {
    opndstk staack;
    string postfix;
cout<<"Enter Postfix Expression : ";

getline(cin,postfix);
int symbol, opnd2, opnd1, i =0, value;

while (i != postfix.length() ) {
        symbol = postfix[i];
   if(symbol == ' ' ){
        i++; continue; }
   else if (isdigit(symbol)) {
       staack.push(symbol-'0'); }

   else {
        opnd2 = staack.pop();
        opnd1 = staack.pop();
 value = operation(opnd1,opnd2,symbol);
 staack.push(value); } //end else

i++; }//end while

cout << "Evaluation Of Postfix = " << staack.pop(); }//main end
