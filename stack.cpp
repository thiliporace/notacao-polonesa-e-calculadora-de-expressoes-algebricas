#include "stack.h"

Stack create(){ // Coloca o valor \0 em todos os index da pilha
    Stack stack;
    stack.count = 0;
    for (int i = 0;i < STACK_CAPACITY;i++){
        stack.elements[i] = '\0';
    }
    return stack;
}

Stack_float create_float(){ // Coloca o valor \0 em todos os index da pilha
    Stack_float stack_float;
    stack_float.count = 0;
    for (int i = 0;i < STACK_CAPACITY;i++){
        stack_float.elements[i] = 0;
    }
    return stack_float;
}

bool push(Stack &stack, char e){ // Empurra um elemento para cima da pilha
    if (stack.count == STACK_CAPACITY){
        return false;
    }
    else{
        stack.elements[stack.count] = e;
        stack.count++;
        return true;
    } 
}

bool push_float(Stack_float &stack_float, float f){ // Empurra um elemento para cima da pilha
    if (stack_float.count == STACK_CAPACITY){
        return false;
    }
    else{
        stack_float.elements[stack_float.count] = f;
        stack_float.count++;
        return true;
    } 
}

char pop(Stack &stack){ // Apaga o ultimo elemento colocado na pilha
    if (stack.count == 0){
        return '\0';
    }
    char value = stack.elements[stack.count-1];
    stack.elements[stack.count-1] = '\0'; 
    stack.count--;
    return value;
}

float pop_float(Stack_float &stack_float){ // Apaga o ultimo elemento colocado na pilha
    if (stack_float.count == 0){
        return 0;
    }
    float value = stack_float.elements[stack_float.count-1];
    stack_float.elements[stack_float.count-1] = 0; 
    stack_float.count--;
    return value;
}

int pop_int(Stack_float &stack_float){ // Apaga o ultimo elemento colocado na pilha
    if (stack_float.count == 0){
        return 0;
    }
    int value = stack_float.elements[stack_float.count-1];
    stack_float.elements[stack_float.count-1] = 0; 
    stack_float.count--;
    return value;
}

char top(Stack &stack){ // Checa o valor da do ultimo elemento da pilha
    if (stack.count == 0){
        return '\0';
    }
    return stack.elements[stack.count-1];
}

float top_float(Stack_float &stack_float){ // Checa o valor da do ultimo elemento da pilha
    if (stack_float.count == 0){
        return 0;
    }
    return stack_float.elements[stack_float.count-1];
}

void print_top(Stack &stack) { // Apenas printa o valor do ultimo elemento para o usuario
    char topo = top(stack);
    if (topo == '\0')
        cout << "Pilha vazia. \n";
    else
        cout << "Topo da pilha: " << topo << '\n';
}

void print_top_float(Stack_float &stack_float) { // Apenas printa o valor do ultimo elemento para o usuario
    float topo = top_float(stack_float);
    if (topo == 0)
        cout << "Pilha vazia. \n";
    else
        cout << "Topo da pilha: " << topo << '\n';
}

int count_stack(Stack &stack){ // Retorna quantos elementos a pilha possui
    if (stack.count > 0){
        return stack.count;
    }
    else{
        cout << "A pilha nao possui elementos.";
        return 0;
    }
}

void print_count(Stack &stack){ // Printa para o usuario quantos elementos a pilha possui
    int count = count_stack(stack);
    cout << "Quantidade de elementos na pilha: " << count << "\n";
}

bool is_empty(Stack &stack){ // Checa se a pilha esta vazia
    if (stack.count == 0){
      return true;
    }
    return false;
}

int size(Stack &stack){
    return STACK_CAPACITY;
}