#include "Map.hpp"

Map::Map(){
	n_object=length=width=max_objects=0;
	objects=NULL;
}

Map::~Map(){
	delete buffer;
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

_data *Map::send_serial(){
	buffer=new _data;
	std::ostringstream bufferStream;
	
	bufferStream.write(name.c_str(),50);
	bufferStream.write((char*)&length,2);
	bufferStream.write((char*)&width,2);
	bufferStream.write((char*)&max_objects,2);
	bufferStream.write((char*)&n_object,2);
	for(int i=0;i<n_object;i++){
		bufferStream.write((char*)&objects[i].type,1);
		bufferStream.write((char*)&objects[i].x,2);
		bufferStream.write((char*)&objects[i].y,2);
		bufferStream.write((char*)&objects[i].radius,2);
		bufferStream.write((char*)&objects[i].length,2);
		bufferStream.write((char*)&objects[i].width,2);
		bufferStream.write((char*)&objects[i].r,1);
		bufferStream.write((char*)&objects[i].g,1);	
		bufferStream.write((char*)&objects[i].b,1);
	}
	std::string tmp=bufferStream.str();
	memcpy(buffer->buffer,tmp.c_str(),tmp.size());
	buffer->type=PROTOCOL_MAP_FILE;
	
	return buffer;
}

void Map::get_serial(_data &buffer){
	std::ostringstream bufferStream;
	std::string tmp;
	memcpy(tmp.data(),buffer.buffer,sizeof(buffer));

}
