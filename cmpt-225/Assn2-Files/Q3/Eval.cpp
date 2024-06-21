/* 
 * Eval.cpp
 *
 * Description: Evaluation of infix expressions using two Stacks.
 *
 * Author: Wonchan Kim & Jaclyin Sunardi
 * Date: JUN 11th, 2024
 */

#include <iostream>
#include "Scanner.h"
#include "Stack.h"  // TEMPLATE STACK

using std::cout;
using std::endl;
using std::cin;

void operation(Stack<Token>& numstack, Stack<Token>& opstack) {
    int peek_val = numstack.peek().val;
    numstack.pop();
    int second_val = numstack.peek().val;
    numstack.pop();
    Token operand = opstack.peek();
    opstack.pop();
    Token result;
    if (operand.tt == pltok) {
        result.val = second_val + peek_val;
    }
    else if (operand.tt == mitok) {
        result.val = second_val - peek_val;
    }
    else if (operand.tt == asttok) {
        result.val = second_val * peek_val;
    }
    else if (operand.tt == slashtok) {
        result.val = second_val / peek_val;
    }
    numstack.push(result);
}

int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    t = S.getnext();
    //while T is not EOF or the operator stack is non empty
    while(!opstack.isEmpty() || t.tt != eof) {
        //if T is a number:
        if (t.tt == integer) { 
        //push T to the number stack
            numstack.push(t);
        }
        //else if T is a left parenthesis:
        else if (t.tt == lptok) {
            //push T to the operator stack
            opstack.push(t);
        }
        //else if T is a right parenthesis
        else if (t.tt == rptok) {
            //if the top of the operator stack is not a left parenthesis
            //pop the top two numbers and the top operator
            //perform the operation
            //push the result to the number stack
            while (opstack.peek().tt != lptok) {
                operation(numstack, opstack);
            }
            //if the top of the operator stack is a left parenthesis
            //pop it from the operator stack
            opstack.pop();   
        }
        //else if T is +, - or EOF
        else if (t.tt == pltok || t.tt == mitok || t.tt == eof) {
            //if the operator stack is nonempty and the top is one of +, -, *, /:
            //pop the top two numbers and the top operator
            //perform the operation
            //push the result to the number stack
            while (!opstack.isEmpty() && (opstack.peek().tt == pltok || opstack.peek().tt == mitok || opstack.peek().tt == asttok || opstack.peek().tt == slashtok)) {
                operation(numstack, opstack);
            }
            if (t.tt != eof) {
            //else: push T to the operator stack
                opstack.push(t);
            }
        }
        // else if T is * or /
        else if (t.tt == slashtok || t.tt == asttok) {
            //if the operator stack is nonempty and the top is one of *, /:
            //pop the top two numbers and the top operator
            //perform the operation
            //push the result to the number stack
            while (!opstack.isEmpty() && (opstack.peek().tt == asttok || opstack.peek().tt == slashtok)) {
                operation(numstack, opstack);
            }
            //else:
            //push T to the operator stack
            opstack.push(t);
        }
        //get the next token
        t = S.getnext();
    }
    //finish the left operations
    while (!opstack.isEmpty()) {
        operation(numstack, opstack);
    }
    //print the result
    if (!numstack.isEmpty()) {
        Token result = numstack.peek();
        numstack.pop();
        cout << result.val << endl;
    }

    return 0;
}