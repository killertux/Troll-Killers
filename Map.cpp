#include "Map.hpp"

Map::Map(){
	n_object=0;
}

Map::Map(std::string Name, int max_objects, int length, int width){
	this->Name=Name;
	this->max_objects=max_objects;
	this->length=length;
	this->width=width;
	objects=new _object[max_objects];
	
	n_object=0;
}

Map::~Map(){
	delete [] objects;
}

void Map::new_object(_object object){			//Add a new object to the map.
	objects[n_object]=object;
	n_object++;
}

void Map::destroy_object(float x, float y){		//Delete an object that is in the x,y position.
	for(int i=0;i<n_object;i++)
		if(objects[i].x==x && objects[i].y==y){
			for(int j=i;j<n_object;j++)
				objects[i]=objects[j];
			n_object--;
		}
}

void Map::draw_map(){
	for(int i=0;i<n_object;i++){
		if(objects[i].type==RECTANGLE)
			al_draw_filled_rectangle(objects[i].x,objects[i].y,objects[i].x+objects[i].length,
					objects[i].y+objects[i].width,al_map_rgb(objects[i].r,objects[i].g,objects[i].b));
		else if (objects[i].type==CIRCLE)
			al_draw_filled_circle(objects[i].x,objects[i].y,objects[i].radius,al_map_rgb(objects[i].r,objects[i].g,objects[i].b));
	}
}

bool Map::save_map(std::string pathname){
	std::ofstream(pathname.c_str(),std::ios::in | std::ios::binary);
}

bool Map::load_map(std::string pathname)
{

}
