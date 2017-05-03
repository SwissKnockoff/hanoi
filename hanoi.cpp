#include "hanoi.h"

//Initialize stack, top
Peg::Peg() {
	
	for(int i = 0; i < 20; i++) {
		
		stack[i] = 0;
		
	}
	
	top = -1;
	
}

//Return top of stack and deincrement top
int Peg::pop() {

	return stack[top--];
	
}

//Increment top and push n to top
void Peg::push(int n) {
	
	stack[++top] = n;
	
}

void Peg::draw(int n, ALLEGRO_DISPLAY *display) {
	
	al_draw_filled_rectangle((n / 4.) * al_get_display_width(display) - 7, al_get_display_height(display) / 4, (n / 4.) * al_get_display_width(display) + 7, al_get_display_height(display), al_map_rgb(160, 82, 45));
		
}
