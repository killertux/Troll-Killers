#include "Map.hpp"

Map::Map(){
	n_object=0;
}

Map::Map(std::string name, int max_objects, int length, int width){
	this->name=name;
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
	std::ofstream file(pathname.c_str(),std::ios::out | std::ios::binary);
	file.write(name.c_str(),50);
	file.write((char*)&length,2);
	file.write((char*)&width,2);
	file.write((char*)&max_objects,2);
	file.write((char*)&n_object,2);
	for(int i=0;i<n_object;i++){
		file.write((char*)&objects[i].type,1);
		file.write((char*)&objects[i].x,2);
		file.write((char*)&objects[i].y,2);
		file.write((char*)&objects[i].radius,2);
		file.write((char*)&objects[i].length,2);
		file.write((char*)&objects[i].width,2);
		file.write((char*)&objects[i].r,2);
		file.write((char*)&objects[i].g,2);
		file.write((char*)&objects[i].b,2);
	}
	file.close();
}

bool Map::load_map(std::string pathname)
{
	char buffer[51];
	std::ifstream file(pathname.c_str(),std::ios::in | std::ios::binary);
	file.read(buffer,50);
	name=buffer;
	file.read((char*)&length,2);
	file.read((char*)&width,2);
	file.read((char*)&max_objects,2);
	file.read((char*)&n_object,2);
	for(int i=0;i<n_object;i++){
		file.read((char*)&objects[i].type,1);
		file.read((char*)&objects[i].x,2);
		file.read((char*)&objects[i].y,2);
		file.read((char*)&objects[i].radius,2);
		file.read((char*)&objects[i].length,2);
		file.read((char*)&objects[i].width,2);
		file.read((char*)&objects[i].r,2);
		file.read((char*)&objects[i].g,2);
		file.read((char*)&objects[i].b,2);
	}
}
