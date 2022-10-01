// Lucas Goulart de Farias Meres - 42127459
// Thiago Leandro Liporace, 42128481
// ------------Referencias---------------
// Usamos de referencia as tabelas de exemplo disponibilizadas nos PDFs sobre a atividade 
// no moodle, que foram essenciais para que o codigo funcionasse.


#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

const char alfabeto[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

const char operators[5] = {'+','*','/','^','-'};

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
        break;
      }
      else if(equation_posfixa[i] == '+'){
        x = pop_int(stack_int);
        y = pop_int(stack_int);
        new_value = x+y;
        push_int(stack_int,new_value);
        break;
      }
      else if(equation_posfixa[i] == '-'){
        x = pop_int(stack_int);
        y = pop_int(stack_int);
        new_value = y-x;
        push_int(stack_int,new_value);
        break;
      }
      else if(equation_posfixa[i] == '*'){
        x = pop_int(stack_int);
        y = pop_int(stack_int);
        new_value = x*y;
        push_int(stack_int,new_value);
        break;
      }
      else if(equation_posfixa[i] == '/'){
        x = pop_int(stack_int);
        y = pop_int(stack_int);
        new_value = y/x;
        push_int(stack_int,new_value);
        break;
      }
      else if(equation_posfixa[i] == '^'){
        x = pop_int(stack_int);
        y = pop_int(stack_int);
        new_value = y^x;
        push_int(stack_int,new_value);
        break;
      }
    }
  }
  result = top_int(stack_int);
  pop_int(stack_int);
  return result;
}

bool check_equation(string equation){
  int count_parenteses1 = 0,count_parenteses2 = 0,count = 0,count_variables = 0;
  for (int i = 0;i < equation.length();i++){
    equation[i] = toupper(equation[i]);
  }
  for (int i = 0;i < equation.length();i++){
    count = 0;
    for (int j = 0;j < 26;j++){
      for (int z = 0;z < 5;z++){
        if ((equation[0] == '*') || (equation[0] == '^') || (equation[0] == '/') || equation[0] == ')'){
          cout << "G";
          cout << "A equacao inserida eh invalida.\n";
          return false;
        }
        else{
          if ((equation[i] == alfabeto[j]) || (equation[i] == operators[z]) || (equation[i] == '(') || (equation[i] == ')')){
            if (i == equation.length()-1){
              if ((equation[i] == alfabeto[j]) && (equation[i+1] == alfabeto[j])){
                cout << "A equacao inserida eh invalida.\n";
                return false;
              }
              else if ((equation[i] == operators[z]) && (equation[i+1] == operators[z])){
                cout << "A equacao inserida eh invalida.\n";
                return false;
              }
              else{
                if (equation[i] == '(') count_parenteses1++;
                if (equation[i] == ')') count_parenteses2++;
              }
            }
            else {
              if ((equation[i] == alfabeto[j]) && (equation[i+1] == alfabeto[j])){
                cout << "C";
                cout << "A equacao inserida eh invalida.\n";
                return false;
              }
              else if ((equation[i] == operators[z]) && (equation[i+1] == operators[z])){
                cout << "A equacao inserida eh invalida.\n";
                return false;
              }
              else{
                if (equation[i] == '(') count_parenteses1++;
                if (equation[i] == ')') count_parenteses2++;
              }
            }
          }
          else{
            count++;
            if (count == 130){
              cout << "A equacao inserida eh invalida.\n";
              return false;
            }
          }
        }
      } 
    }
  }
  if (count_parenteses1 == count_parenteses2){
    return true;
  }
  else{
    cout << "A equacao inserida eh invalida.\n";
    return false;
  }
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
    cin.ignore(256,'\n');
    if (entry == 1){
      while (true){
        cout << "----------------------------------------------------\nDigite sua equacao:\n";
        getline(cin,equation);
        if (check_equation(equation) == true) break;
      }
      for (int i = 0;i < equation.length();i++){
        equation[i] = toupper(equation[i]);
      }
    }
      
    else if(entry == 2){
      if (equation == "") {
        cout << "\n----------------------------------------------------\nNao ha uma equacao definida para isso.\n----------------------------------------------------\n";
      }
      for(int i = 0;i < equation.length();i++){
        for (int j = 0;j < 26;j++){
          if (toupper(equation[i]) == alfabeto[j]){
            cout << "----------------------------------------------------\nDigite o valor de " << alfabeto[j] << ":";
            cin >> value;
            value_list[j] = value;
          }
        }
      }
      cout << "\n";
    }

    else if(entry == 3){
      cout << "----------------------------------------------------\nExpressao inicial:" << equation << "\n";
      equation_posfixa = posfixa(stack,equation);
      cout << "Expressao posfixa:" << equation_posfixa << "\n----------------------------------------------------\n";
    }
 
    else if(entry == 4){
      if (equation_posfixa == ""){
        cout << "\n----------------------------------------------------\nNao ha uma equacao definida para isso.\n----------------------------------------------------\n";
      }
      else{
        result = calculo(stack_int,equation_posfixa,value_list);
        cout << "----------------------------------------------------\nResultado da equacao: " << result << "\n";
        cout << "----------------------------------------------------\n";
      }      
    }

    else if (entry == 5){
      cout << "\n";
      cout << "Fechando terminal...";
      break;
    }
  
    else{
      cout << "Digite uma opcao valida.\n";
    }
  }
}