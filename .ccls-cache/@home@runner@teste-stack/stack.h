#pragma once
#include <iostream>

using namespace std;

const int STACK_CAPACITY = 10;

struct Stack
{
	int count;
	char elements[STACK_CAPACITY]; 
};

struct Stack_int
{
	int count;
	int elements[STACK_CAPACITY]; 
};

Stack create();

Stack_int create_int();

bool push(Stack& stack, char e);

bool push_int(Stack_int& stack_int,int f);

char pop(Stack& stack);

void print_top(Stack& stack);

int count_stack(Stack &stack);

void print_count(Stack &stack);

bool is_empty(Stack &stack);

int size(Stack &stack);

char top(Stack& stack);

int pop_int(Stack_int &stack_int);

int top_int(Stack_int &stack_int);

void print_top_int(Stack_int &stack_int);