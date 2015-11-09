#include "Cursor.hpp"

Cursor::Cursor(int x, int y, int resX, int resY, int timer){
	this->x=x;
	this->y=y;
	this->resX=resX;
	this->resY=resY;
	this->timer=timer;
	cTimer=0;
	dir=STOPED;
	moved=true;
	objSelected=false;
}

void Cursor::draw_cursor(){
	if(objSelected)
		al_draw_filled_rectangle(objCursor.x,objCursor.y,objCursor.x+objCursor.length,
						 objCursor.y+objCursor.width,al_map_rgb(objCursor.r,objCursor.g,objCursor.b));
	else {
		al_draw_line(x-10,y,x+10,y,al_map_rgb(0,0,100),4);
		al_draw_line(x,y-10,x,y+10,al_map_rgb(0,0,100),4);
	}
}

void Cursor::move_cursor(ALLEGRO_KEYBOARD_STATE keyState){
	if(!al_key_down(&keyState, ALLEGRO_KEY_LCTRL) && !al_key_down(&keyState, ALLEGRO_KEY_ALT)){
		if(dir==STOPED){
			if(al_key_down(&keyState, ALLEGRO_KEY_UP) && y>0){
				y-=GRID;
				dir=UP;
			}
			else if(al_key_down(&keyState, ALLEGRO_KEY_DOWN) && y<resY-GRID){
				y+=GRID;
				dir=DOWN;
			}
			else if(al_key_down(&keyState, ALLEGRO_KEY_LEFT) && x>0){
				x-=GRID;
				dir=LEFT;
			}
			else if(al_key_down(&keyState, ALLEGRO_KEY_RIGHT) && x<resX-GRID){
				x+=GRID;
				dir=RIGHT;
			}
		}
	}
	
	if(dir!=STOPED){
		cTimer++;
		if(al_key_down(&keyState, ALLEGRO_KEY_UP) && y>0)
			dir=UP;
		else if(al_key_down(&keyState, ALLEGRO_KEY_DOWN) && y<resY-GRID)
			dir=DOWN;
		else if(al_key_down(&keyState, ALLEGRO_KEY_LEFT) && x>0)
			dir=LEFT;
		else if(al_key_down(&keyState, ALLEGRO_KEY_RIGHT) && x<resX-GRID)
			dir=RIGHT;
		else {
			dir=STOPED;
			cTimer=0;
		}
		
	}

	if(cTimer>=timer*3){
		if(dir==UP && y>0)
			y-=GRID;
		else if(dir==DOWN && y<resY)
			y+=GRID;
		if(dir==LEFT && x>0)
			x-=GRID;
		else if(dir==RIGHT && y<resX)
			x+=GRID;
		cTimer=timer*2;
	}
	objCursor.x=x;
	objCursor.y=y;
}

void Cursor::change_cursor(){
	objSelected=!objSelected;
	if(objSelected){
		objCursor.type=RECTANGLE;
		objCursor.x=x;
		objCursor.y=y;
		objCursor.length=GRID;
		objCursor.width=GRID;
		objCursor.r=objCursor.g=objCursor.b=0;
	}
	lengthInc=1;
	widthInc=1;
}

void Cursor::increase_object(Direction incDir){
	if(objSelected){
		if(incDir==RIGHT){
			lengthInc++;
			objCursor.length=GRID*lengthInc;
		}
		else if(incDir==LEFT && lengthInc>1){
			lengthInc--;
			objCursor.length=GRID*lengthInc;
		}
		else if(incDir==DOWN){
			widthInc++;
			objCursor.width=GRID*widthInc;
		}
		else if(incDir==UP && widthInc>1){
			widthInc--;
			objCursor.width=GRID*widthInc;
		}
		
	}
}
