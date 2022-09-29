#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

const char alfabeto[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

const char operators[5] = {'+','*','/','^','-'};

//int cont = 0;
  //for (int i = 0;i < equation.length();i++){
    //if (toupper(equation[i]) == letter){
     // equation[i] = value_list[cont];
     // ++cont;

string posfixa(Stack &stack,string equation){
  string output;
  for (int i = 0;i < equation.length();i++){
    if ((equation[i] != '+') && (equation[i] != '-') && (equation[i] != '^') &&  (equation[i] != '/') && (equation[i] != '*') && (equation[i] != '(') &&(equation[i] != ')') && (equation[i] != ' ')){
      output = output + equation[i];
    }
    else{
      if (stack.count == 0){
        push(stack,equation[i]);
      }
      else if (equation[i] == '('){
        push(stack,equation[i]);
      }
      else if ((equation[i] == '*') ||(equation[i] == '/') || (equation[i] == '^')){
        if ((top(stack) == '*') ||(top(stack) == '/') || (top(stack) == '^')){
          output = output + pop(stack);
        }
        push(stack,equation[i]);
      }
      else if ((equation[i] == '+') ||(equation[i] == '-')){
        if ((top(stack) == '*') ||(top(stack) == '/') ||(top(stack) == '+') ||(top(stack) == '-') || (equation[i] == '^')){
          output = output + pop(stack);
        }
        push(stack,equation[i]);
      }
      else if (equation[i] == ')'){
        while (top(stack) != '('){
          output = output + pop(stack);
        }
        pop(stack);
      }
    }
  }
  for (int i = 0;i < STACK_CAPACITY;i++){
    if (stack.count == 0){
      break;
    }
    output = output + pop(stack);
  }
  return output;
}

int calculo (Stack_int &stack_int,string equation_posfixa,int value_list[26]){
  int result,cont,x,y,new_value;
  for (int i = 0;i < equation_posfixa.length();i++){
    for (int j = 0;j < 26;j++){
      if (equation_posfixa[i] == alfabeto[j]){
        push_int(stack_int,value_list[j]);
        continue;
      }
      else if(equation_posfixa[i] == '+'){
        x = pop_int(stack_int);
        y = pop_int(stack_int);
        new_value = x+y;
        push_int(stack_int,new_value);
        continue;
      }
      else if(equation_posfixa[i] == '-'){
        x = pop_int(stack_int);
        y = pop_int(stack_int);
        new_value = y-x;
        cout << "Valor do x: " << x << "\n";
        cout << "Valor do y: " << y << "\n";
        cout << "Topo da pilha: " << top_int(stack_int) << "\n";
        push_int(stack_int,new_value);
        continue;
      }
      else if(equation_posfixa[i] == '*'){
        x = pop_int(stack_int);
        y = pop_int(stack_int);
        new_value = x*y;
        push_int(stack_int,new_value);
        continue;
      }
      else if(equation_posfixa[i] == '/'){
        x = pop_int(stack_int);
        y = pop_int(stack_int);
        new_value = y/x;
        push_int(stack_int,new_value);
        continue;
      }
      else if(equation_posfixa[i] == '^'){
        x = pop_int(stack_int);
        y = pop_int(stack_int);
        new_value = y^x;
        push_int(stack_int,new_value);
        continue;
      }      
    }
  }
  result = top_int(stack_int);
  pop_int(stack_int);
  return result;
}

int main() {
  int value_list[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  bool flag = false;
  int entry,num,result,value;
  string equation = "",equation_posfixa = "";
  Stack stack = create();
  Stack_int stack_int = create_int();
  cout << "-------------------- Bem-vindo ao sistema! --------------------\n";
  while (true){
    cout << "Escolha uma das opcoes abaixo:\n" << "1. Entrada da expressão aritmética na notação infixa.\n2. Entrada dos valores numéricos associados às variáveis.\n3. Conversão da expressão, da notação infixa para a notação posfixa, e exibição da expressão convertida para posfixa.\n4. Avaliação da expressão (apresentação do resultado do cálculo, mostrando a expressão e os valores das variáveis).\n5. Encerramento do programa.\n";
    cin >> entry;
    if (entry == 1){
      cout << "Digite sua equacao:\n";
      cin.ignore(256,'\n');
      getline(cin,equation);
      for (int i = 0;i < equation.length();i++){
        equation[i] = toupper(equation[i]);
      }
      cout << equation << '\n';
    }
    else if(entry == 2){
      if (equation == "") cout << "Nao ha uma equacao definida para isso.";
      for(int i = 0;i < equation.length();i++){
        for (int j = 0;j < 26;j++){
          if (toupper(equation[i]) == alfabeto[j]){
            cout << "Digite o valor de " << alfabeto[j] << ":";
            cin >> value;
            value_list[j] = value;
          }
        }
      }
    }
    else if(entry == 3){
      cout << "Expressao inicial:" << equation << "\n";
      equation_posfixa = posfixa(stack,equation);
      cout << "Expressao posfixa:" << equation_posfixa << "\n";
    }
    else if(entry == 4){
      if (equation_posfixa == ""){
        cout << "Nao ha uma equacao definida para isso.\n";
      }
      else{
        result = calculo(stack_int,equation_posfixa,value_list);
        cout << "Resultado da equacao: " << result << "\n";
      }      
    }
    else if (entry == 5){
      cout << "Fechando terminal...";
      break;
    }
    else{
      cout << "Digite uma opcao valida.\n";
    }
  }
}