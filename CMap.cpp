#include "CMap.hpp"

CMap::CMap(std::string name, int max_objects, int length, int width){
	this->name=name;
	this->max_objects=max_objects;
	this->length=length;
	this->width=width;
	objects=new _object[max_objects];
	drawCircles=false;
	n_object=0;
}

CMap::CMap(){
	drawCircles=false;
	n_object=0;
}


CMap::~CMap(){
	delete [] objects;
}

void CMap::new_object(_object object){			//Add a new object to the map.
	objects[n_object]=object;
	n_object++;
}

void CMap::destroy_object(int x, int y){		//Delete an object that is in the x,y position.
	for(int i=0;i<n_object;i++)
		if(objects[i].x==x && objects[i].y==y){
			for(int j=i;j<n_object;j++)
				objects[i]=objects[j];
			n_object--;
		}
}

void CMap::draw_map(int x,int y){
	al_clear_to_color(al_map_rgb(255,255,255));
	for(int i=0;i<n_object;i++){
		if(objects[i].type==RECTANGLE)
			al_draw_filled_rectangle(objects[i].x-x,objects[i].y-y,objects[i].x-x+objects[i].length,
					objects[i].y-y+objects[i].width,al_map_rgb(objects[i].r,objects[i].g,objects[i].b));
		else if (objects[i].type==CIRCLE && drawCircles==true)
			al_draw_filled_circle(objects[i].x-x,objects[i].y-y,objects[i].radius,al_map_rgb(objects[i].r,objects[i].g,objects[i].b));
	}
}
