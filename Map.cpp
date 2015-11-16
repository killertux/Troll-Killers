#include "Map.hpp"
#include <stdio.h>
#include "iostream"

Map::Map(){
	n_object=length=width=max_objects=0;
	type=PROTOCOL_MAP_FILE;
	objects=NULL;
}

Map::~Map(){
	delete [] objects;
}

bool Map::save_map(std::string pathname){
	std::ofstream file(pathname.c_str(),std::ios::out | std::ios::binary);
	if(!file)
		return 0;
	file.write(name,50);
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
	return 1;
}

bool Map::load_map(std::string pathname)
{
	std::ifstream file(pathname.c_str(),std::ios::in | std::ios::binary);
	if(!file)
		return 0;
	file.read(name,50);
	file.read((char*)&length,2);
	file.read((char*)&width,2);
	file.read((char*)&max_objects,2);
	file.read((char*)&n_object,2);
	if(objects!=NULL)
		delete [] objects;
	objects=new _object[max_objects];
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
	file.close();
	return 1;
}


int Map::serielize(char* buffer){
	std::stringstream stream;
	std::string tmp;
	stream << type << " "<<length << " "<<width << " "<<max_objects<< " " << n_object;
	sprintf(buffer,"%s%s",buffer,stream.str().c_str());
	stream.str(std::string());
	for(int i=0;i<n_object;i++){
		stream << objects[i].type << " " << objects[i].x<< " " << objects[i].y << " "<< objects[i].radius 
		<< " "<< objects[i].length << " "<< objects[i].width<< " " << objects[i].r << " "<< objects[i].g 
		<< " "<< objects[i].b << " ";
		sprintf(buffer,"%s%s",buffer,stream.str().c_str());
		stream.str(std::string());
	}
	std::cout << buffer <<std::endl;
	return std::strlen(buffer);
}

void Map::deserielize(char* buffer){
	std::stringstream stream;
	std::cout << buffer << std::endl;
	stream << buffer;
	stream >> type >>length >>width >>max_objects >> n_object;
	if(objects!=NULL)
		delete [] objects;
	objects=new _object[max_objects];
	for(int i=0;i<n_object;i++){
		stream >>objects[i].type>> objects[i].x>> objects[i].y>> objects[i].radius>> objects[i].length>> objects[i].width>> objects[i].r>> objects[i].g >>objects[i].b;
	}
	std::cout << objects[0].r << std::endl;
	std::cout << objects[0].g << std::endl;
	std::cout << objects[0].b << std::endl;
}

