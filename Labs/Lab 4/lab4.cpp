#include <iostream>

using namespace std;

const int SIZE = 100;

template<typename T>
class stack{
    public:
        stack() {
            peek = 0; 
        }

        void push(T x) {
            if(isFull()) {
                std::cout << "STACK IS FULL" <<std::endl;
                exit(1);
            }
            A[peek++] = x;
        }

        T top() {        
            if(empty()) {
                std::cout << "STACK IS EMPTY" <<std::endl;
                exit(1);
            }
            return A[peek-1];
        }

        T pop() {
            T ret = top();
            peek--;
            return ret;
        }

        bool empty() {
            return peek == 0;
        }

        bool isFull() {
            return peek == 100;
        }

    private:
        T A[SIZE];
        int peek;

};

//reversing the string
string reversing(string str) {
    string newStr;
    for(int i = str.size()-1; i >= 0; i--) {
        if(str[i] == ')') {
            str[i] = '(';
        }
        else if(str[i] == '('){
            str[i] = ')';
        }
        newStr += str[i];
    }

    return newStr;
}

//infix to prefix
string infixToPrefix(string infix) {
    
    infix = reversing(infix);   // reverse

    string prefix;
    stack<char> s;

    for(int i = 0; i < infix.size(); i++) {
        
        if(infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z') {       //if char is operand
            prefix += infix[i];
        }
        else if(infix[i] == ' ') {        //if char is space
            prefix += ' '; 
        }
        else if(infix[i] == '(') {     //if char is opening parentheses
            s.push(infix[i]);
        }
        else if(infix[i] == ')') {                 //if char is closing parentheses
            while(!s.empty() && s.top() != '(') { 
                prefix += s.top();
                s.pop();
            }
            s.pop();
        }
        else {                //if char is operator
            s.push(infix[i]);
        }

    }

    while(!s.empty()) {            //if there is still elements in stack
        prefix += s.top();
        s.pop();
    }

    return reversing(prefix);            //again reverse
    
}

//prefix to infix
string prefix2Infix(string str) {
    string prefix = reversing(str);    //reverse
    
    stack<string> s;    

    for(int i = 0; i < prefix.size(); i++) {
        if(prefix[i] >= 'a' && prefix[i] <= 'z' || prefix[i] >= 'A' && prefix[i] <= 'Z') {     //if its operand
            string pushing;
            pushing += prefix[i];
            s.push(pushing);               //push in stack
        }
        else if(prefix[i] == '-' || prefix[i] == '+' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '%') {    //if its operator
            string first = s.top();      //get first operand from stack
            s.pop();
            string second = s.top();    //get second operand from stack
            s.pop();

            string pushing = "(" + first + prefix[i] + second + ")";
            s.push(pushing);
            
        }
    }

    return s.top();
}

//postfix to infix using recursion
string post2In(string postfix, stack<string> s, int i) {

    if(i == postfix.size()) {         //if i is the size 
        return s.top();
    }

    if(postfix[i] >= 'a' && postfix[i] <= 'z' || postfix[i] >= 'A' && postfix[i] <= 'Z') {     //if its operand
            string pushing;
            pushing += postfix[i];
            s.push(pushing);
    }

    if(postfix[i] == '-' || postfix[i] == '+' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%') {   //if its operator
        string second = s.top();
        s.pop();
        string first = s.top();
        s.pop();

        string pushing = "(" + first + postfix[i] + second + ")";
        s.push(pushing);
        
    }

    return post2In(postfix, s, i+1);

}

int main() {
    std::cout << "infix expression is ((x%d)+(Y-c)) " << "and the prefix is " << infixToPrefix("((x%d)+(Y-c))") << endl;
    std::cout << "infix expression is ((A+ B ) * t ) " << "and the prefix is " << infixToPrefix("((A+ B) *t )") << endl;
    std::cout << endl;

    std::cout << "prefix expression is *+A Bt " << "and the infix is " << prefix2Infix("* + A Bt") << endl;
    std::cout << "prefix expression is +%xd-Yc " << "and the infix is " << prefix2Infix("+ %xd-Yc") << endl;
    std::cout << endl;

    stack<string> s;
    std::cout << "postfix expression is AB+t* " << "and the infix is " << post2In("AB+t*", s, 0) << endl;
    std::cout << "prefix expression is xd%Yc-+ " << "and the infix is " << post2In("x d % Y c - +", s, 0) << endl;




    return 0;
}