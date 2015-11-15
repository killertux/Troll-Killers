#include "Map.hpp"
#include <stdio.h>
#include "iostream"

Map::Map(){
	n_object=length=width=max_objects=0;
	objects=NULL;
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
		file.read((char*)&objects[i].r,1);
		file.read((char*)&objects[i].g,1);
		file.read((char*)&objects[i].b,1);
	}
	file.close();
	return 1;
}

_data Map::send_serial(){
	_data buffer;
	memset(buffer.buffer,0,sizeof(buffer));
	std::sprintf(buffer.buffer,"%s",name);
	
	data::int_copy(buffer.buffer,length,50,2);
	data::int_copy(buffer.buffer,width,52,2);
	data::int_copy(buffer.buffer,max_objects,54,2);
	data::int_copy(buffer.buffer,n_object,56,2);
	printf("%x%x\n",buffer.buffer[56],buffer.buffer[57]);
	std::cout << "N object="<<n_object<<"\n";
	for(int i=0;i<n_object;i++){
		data::int_copy(buffer.buffer,objects[i].type,58,1);
		data::int_copy(buffer.buffer,objects[i].x,59,2);
		data::int_copy(buffer.buffer,objects[i].y,61,2);
		data::int_copy(buffer.buffer,objects[i].radius,63,2);
		data::int_copy(buffer.buffer,objects[i].length,65,2);
		data::int_copy(buffer.buffer,objects[i].width,67,2);
		data::int_copy(buffer.buffer,objects[i].r,69,1);
		data::int_copy(buffer.buffer,objects[i].g,70,1);
		data::int_copy(buffer.buffer,objects[i].b,71,1);
	}
	buffer.type=PROTOCOL_MAP_FILE;
	
	return buffer;
}

void Map::get_serial(_data &buffer){
	char c_buffer[51];
	memcpy(c_buffer,buffer.buffer,50);
	name=c_buffer;
	std::cout << c_buffer << std::endl;
	length=data::int_get(buffer.buffer,50,2);
	width=data::int_get(buffer.buffer,52,2);
	max_objects=data::int_get(buffer.buffer,54,2);
	n_object=data::int_get(buffer.buffer,56,2);
	printf("%d %d %d %d\n",length,width,max_objects,n_object);
	if(objects!=NULL)
		delete [] objects;
	objects=new _object[max_objects];
	for(int i=0;i<n_object;i++){
		objects[i].type=data::int_get(buffer.buffer,58,1);
		objects[i].x=data::int_get(buffer.buffer,59,2);
		objects[i].y=data::int_get(buffer.buffer,61,2);
		objects[i].radius=data::int_get(buffer.buffer,63,2);
		objects[i].length=data::int_get(buffer.buffer,65,2);
		objects[i].width=data::int_get(buffer.buffer,67,2);
		objects[i].r=data::int_get(buffer.buffer,69,1);
		objects[i].g=data::int_get(buffer.buffer,70,1);
		objects[i].b=data::int_get(buffer.buffer,71,1);
	}
}
