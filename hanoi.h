#ifndef HANOI_H
#define HANOI_H

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

class Peg {
	
	private:
		int top; //Index of the top of the peg
		
	public:
		Peg(); //Constructor
		int stack[20]; //Holds the discs on the peg
		int pop(); //Get value on top of stack
		void push(int n); //Put disc at the top of the stack
		bool isEmpty() { return top < 0; } //Check if peg is empty
		int getTop() { return top; } //Find index of top of stack
		void draw(int n, ALLEGRO_DISPLAY *display); //Draw peg to screen
		~Peg() {} //Deconstructor
	
};

#endif
