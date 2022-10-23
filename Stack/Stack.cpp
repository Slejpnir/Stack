// Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
const int MAX = 100;
using namespace std;

template <class T>
struct Stack {
	int top;
	T arr[MAX];
};

template <typename T>
void init(Stack<T>* s) {
	s->top = 0;
}

template <typename T>
void push(Stack<T>* s, T x) {
	if (s->top == MAX) {
		cout << "Stack is full" << endl;
		return;
	}
	s->arr[s->top] = x;
	s->top++;
}

template <typename T>
T pop(Stack<T>* s) {
	if (s->top == 0) {
		cout << "Stack is empty" << endl;
		return 0;
	}
	s->top--;
	return s->arr[s->top];
}

template <typename T>
T peek(Stack<T>* s) {
	if (s->top == 0) {
		cout << "Stack is empty" << endl;
		return 0;
	}
	return s->arr[s->top - 1];
}

template <typename T>
int size(Stack<T>* s) {
	return s->top;
}

template <typename T>
bool isEmpty(Stack<T>* s) {
	return s->top == 0;
}

template <typename T>
void printStack(Stack<T>* s) {
	{
		if(isEmpty(s))
		{
			cout << "Stack is empty" << endl;
			return;
		}
		for (int i = 0; i < s->top; i++) {
			cout << s->arr[i] << " ";
		}
		cout << endl;
	}
}

int main()
{
	/*Stack<int>* stk = new Stack<int>;
	init(stk);
	int n;
	int elem;
	cout << "Input number of elements: ";
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "Input element " << i+1<<" ";
		cin >> elem;
		push(stk, elem);
	}
	cout << "Stack consists of " << size(stk) << " elements" << endl;
	cout << "Top element is " << peek<int>(stk)<<endl;
	do
	{
		cout << pop<int>(stk)<<endl;
		cout <<"Stack consists of "<< size(stk) << " elements" << endl;
	} while (!isEmpty(stk));
	delete stk;*/
	Stack<int>* stk = new Stack<int>;
	init(stk);
	int value, base;
	cout << "Input value: ";
	cin >> value;
	cout << "Input base: ";
	cin >> base;
	while (value > 0)
	{
		push(stk, value % base);
		value /= base;
	}
	while (!isEmpty(stk))
	{
		cout << pop(stk);
	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
