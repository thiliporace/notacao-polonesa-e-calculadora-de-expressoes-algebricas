#pragma once
#include <iostream>

using namespace std;

const int STACK_CAPACITY = 10;

struct Stack
{
	int count;
	char elements[STACK_CAPACITY]; 
};

struct Stack_float
{
	int count;
	float elements[STACK_CAPACITY]; 
};

Stack create();

Stack_float create_float();

bool push(Stack& stack, char e);

bool push_float(Stack_float& stack_float,float f);

char pop(Stack& stack);

void print_top(Stack& stack);

int count_stack(Stack &stack);

void print_count(Stack &stack);

bool is_empty(Stack &stack);

int size(Stack &stack);

char top(Stack& stack);

float pop_float(Stack_float &stack_float);

float top_float(Stack_float &stack_float);

void print_top_float(Stack_float &stack_float);

int pop_int(Stack_float &stack_float);