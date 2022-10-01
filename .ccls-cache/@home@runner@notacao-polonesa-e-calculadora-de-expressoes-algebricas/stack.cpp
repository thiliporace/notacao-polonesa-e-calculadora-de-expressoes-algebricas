#include "stack.h"

Stack create(){ // Coloca o valor \0 em todos os index da pilha
    Stack stack;
    stack.count = 0;
    for (int i = 0;i < STACK_CAPACITY;i++){
        stack.elements[i] = '\0';
    }
    return stack;
}

Stack_int create_int(){ // Coloca o valor \0 em todos os index da pilha
    Stack_int stack_int;
    stack_int.count = 0;
    for (int i = 0;i < STACK_CAPACITY;i++){
        stack_int.elements[i] = 0;
    }
    return stack_int;
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

bool push_int(Stack_int &stack_int, int f){ // Empurra um elemento para cima da pilha
    if (stack_int.count == STACK_CAPACITY){
        return false;
    }
    else{
        stack_int.elements[stack_int.count] = f;
        stack_int.count++;
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

int pop_int(Stack_int &stack_int){ // Apaga o ultimo elemento colocado na pilha
    if (stack_int.count == 0){
        return 0;
    }
    int value = stack_int.elements[stack_int.count-1];
    stack_int.elements[stack_int.count-1] = 0; 
    stack_int.count--;
    return value;
}

char top(Stack &stack){ // Checa o valor da do ultimo elemento da pilha
    if (stack.count == 0){
        return '\0';
    }
    return stack.elements[stack.count-1];
}

int top_int(Stack_int &stack_int){ // Checa o valor da do ultimo elemento da pilha
    if (stack_int.count == 0){
        return 0;
    }
    return stack_int.elements[stack_int.count-1];
}

void print_top(Stack &stack) { // Apenas printa o valor do ultimo elemento para o usuario
    char topo = top(stack);
    if (topo == '\0')
        cout << "Pilha vazia. \n";
    else
        cout << "Topo da pilha: " << topo << '\n';
}

void print_top_int(Stack_int &stack_int) { // Apenas printa o valor do ultimo elemento para o usuario
    int topo = top_int(stack_int);
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