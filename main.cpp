#include "hanoi.h"
#include "hanoi.cpp"

using namespace std;

void solve(int n, int s, int d, int i);
void move(int n, int s, int d);
void draw();

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *event_queue;
Peg board[3];
ALLEGRO_COLOR colours[20];
int numDiscs;

int main () {
	
	srand(time(NULL));
	
	cout << "How many discs? ";
	cin >> numDiscs;
		
	al_init();
	al_init_primitives_addon();
	
	al_install_keyboard();
	
	display = al_create_display(1024, 576);
	event_queue = al_create_event_queue();
	
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	
	for(int i = numDiscs; i > 0; i--) {
		
		board[0].push(i);
		colours[i] = al_map_rgb(rand() % 256, rand() % 256, rand() % 256);
		
	}
	
	while(true) {
	
		draw();
	
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
	
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			
			return 0;
			
		} else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			
			if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
				
				return 0;
				
			} else {
				
				solve(numDiscs, 1, 3, 2);
				
			}
			
		}
	
	}
	
	return 0;
	
}

void solve(int n, int s, int d, int i) {
	
	if (n > 0) {
	
		solve(n - 1, s, i, d);
		move(n, s, d);
		solve(n - 1, i, d, s);
		
	}
			
}

void move(int n, int s, int d) {
			
	board[d - 1].push(board[s - 1].pop());
	cout << n << " from " << s << " to " << d << endl;
	
	draw();
	
	//Sleep(50);	
	
}

void draw() {	
	
	al_clear_to_color(al_map_rgb(137, 207, 240));
	
	for(int i = 0; i <= 2; i++) {
	
		board[i].draw(i + 1, display);
		for(int j = 0; j <= board[i].getTop(); j++) {
					
			al_draw_filled_rectangle(((i + 1) / 4.) * al_get_display_width(display) - (120 / numDiscs) * board[i].stack[j], al_get_display_height(display) - (160 / numDiscs) * j, ((i + 1) / 4.) * al_get_display_width(display) + (120 / numDiscs) * board[i].stack[j], al_get_display_height(display) - (160 / numDiscs) * j - (160 / numDiscs), colours[board[i].stack[j]]);
					
		}
	
	}
	
	al_flip_display();
	
}
