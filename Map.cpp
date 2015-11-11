#include "Map.hpp"
#include <iostream>

Map::Map(){
	n_object=0;
}

Map::~Map(){
	delete [] objects;
}

bool Map::save_map(std::string pathname){
	std::ofstream file(pathname.c_str(),std::ios::out | std::ios::binary);
	if(!file)
		return 0;
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
		file.write((char*)&objects[i].r,1);
		file.write((char*)&objects[i].g,1);
		file.write((char*)&objects[i].b,1);
	}
	file.close();
	return 1;
}

bool Map::load_map(std::string pathname)
{
	char buffer[51];
	std::ifstream file(pathname.c_str(),std::ios::in | std::ios::binary);
	if(!file)
		return 0;
	file.read(buffer,50);
	name=buffer;
	file.read((char*)&length,2);
	file.read((char*)&width,2);
	file.read((char*)&max_objects,2);
	file.read((char*)&n_object,2);
	std::cout << n_object<<std::endl;
	for(int i=0;i<n_object;i++){
		std::cout << "ola\n";
		file.read((char*)&objects[i].type,1);
		std::cout << i << std::endl;
		file.read((char*)&objects[i].x,2);
		file.read((char*)&objects[i].y,2);
		file.read((char*)&objects[i].radius,2);
		file.read((char*)&objects[i].length,2);
		file.read((char*)&objects[i].width,2);
		file.read((char*)&objects[i].r,1);
		file.read((char*)&objects[i].g,1);
		file.read((char*)&objects[i].b,1);
	}
	file.close();
	return 1;
}

