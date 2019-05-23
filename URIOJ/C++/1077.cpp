/*
 Macacário ITA
*/

#include <bits/stdc++.h>

using namespace std;


bool isOp(char c){

	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';

}

bool isCarac(char c){

	return (c >= 'a' && c <= 'z') || ( c >='A' && c <='Z' ) || (c>= '0' && c<= '9');

}

int paren2polish(char *paren, char *polish){
	map <char,int> prec;
	prec['('] = 0;
	prec['+'] = prec ['-'] = 1;
	prec['*'] = prec ['/'] = 2;
	prec['^'] = 3;
	int len = 0;
	stack <char> op; 
	for(int i = 0 ; paren[i]>0 ; i++){
		if(isOp(paren[i])){
			while(!op.empty() && prec[op.top()] >= prec[paren[i]]){
				polish[len++] = op.top();
				op.pop();
			}
			op.push(paren[i]);
		}
		else if(paren[i] == '(')
			op.push('(');
		else if(paren[i] == ')'){
			while(op.top() != '('){
				polish[len++] = op.top();
				op.pop();
			}
			op.pop();
		}
		else if(isCarac(paren[i]))
			polish[len++] = paren[i];
	}
	while(!op.empty()){
		polish[len++] = op.top();
		op.pop();

	}
	polish[len] = 0;
	return len = 0;
}
int main(){
	int N;
	scanf("%d",&N);
	while(N--){ 
		char paren[255], polish[255];
		scanf("%s",paren);
		paren2polish(paren,polish);
		printf("%s\n",polish);
	}


	return 0;
}

