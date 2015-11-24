#include "MenuManager.hpp"

MenuManager::MenuManager(int res_x,int res_y){
	menu=new MenuPrinc(res_x,res_y);
	this->res_x=res_x;
	this->res_y=res_y;
}


int MenuManager::main_loop(ALLEGRO_TIMER *timer,ALLEGRO_EVENT_QUEUE *event_queue,Client *myDad){
	bool done=false;
	bool redraw=false;
	ALLEGRO_EVENT ev;
	ALLEGRO_MOUSE_STATE mouseState;

	al_clear_to_color(al_map_rgb(255,255,255));
	al_start_timer(timer);
	while(!done){
		al_wait_for_event(event_queue, &ev);
		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			exit(0);
		else if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
			if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				exit(0);
			}
		}
		else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN){
			int result=menu->botao_action();
			if(result==EXIT)
				exit(0);
			else if(result==CHANGE_MENU){
				delete menu;
				menu=new MenuArmas(res_x,res_y);
			}
			else if(result == MENU_RIFLE){
				myDad->setWeapon(RIFLE);
				if(!myDad->connect()){
					std::cout << "Error connecting to the server\n";
					exit(-1);
				}
				myDad->main_loop();
				exit(0);
			}
			else if(result == MENU_PISTOL){
				myDad->setWeapon(PISTOL);
				if(!myDad->connect()){
					std::cout << "Error connecting to the server\n";
					exit(-1);
				}
				myDad->main_loop();
				exit(0);
			}
		}
		else if(ev.type == ALLEGRO_EVENT_TIMER){
			al_get_mouse_state(&mouseState);
			menu->botao(&mouseState);
			redraw=true;
		}

		if(redraw && al_is_event_queue_empty(event_queue)){
			menu->print_menu();
			al_flip_display();
			redraw=false;
		}
	}
}

