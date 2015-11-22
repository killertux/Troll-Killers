#include "Configuration.hpp"
//Construtor e destrutor
Configuration::Configuration(){
	ptr=NULL;
	count=0;
	sprintf(buffer,"");
	configLines=0;
	configChanged=false;
}

Configuration::~Configuration(){
	if(configChanged){
		ptr=fopen(configFile,"w");
		for(count=0;count<=configLines;count++){
			sprintf(buffer,"%s = %s\n",configLine[count][0],configLine[count][1]);
			fputs(buffer,ptr);
		}
		fclose(ptr);
	}
}
//Private
void Configuration::get_word(char *stringOut,char *stringIn,int pos){
	int actualPos=0;
	sprintf(stringOut,"");
	for(count=0;count<=strlen(stringIn);count++){
		if(stringIn[count]=='=' && actualPos!=pos)
			actualPos++;
		else if(stringIn[count]=='=' && actualPos==pos)
			break;
		if(actualPos==pos && stringIn[count]!='=' && stringIn[count]!='\n' && stringIn[count]!=' ')
			sprintf(stringOut,"%s%c",stringOut,stringIn[count]);
	}
	stringOut[count]='\0';
	
}

//Public 
bool Configuration::config_load(const char *fileName){
	ptr=fopen(fileName,"r");
	configLines=0;
	sprintf(configFile,"%s",fileName);
	while(fgets(buffer,1024,ptr)!=NULL){
		if(strcmp(buffer,"")!=0){
			get_word(configLine[configLines][0],buffer,0);
			get_word(configLine[configLines][1],buffer,1);
			configLines++;
		}
	}
	configLines--;
	fclose(ptr);
}

bool Configuration::config_found(const char *fileName){
	ptr=fopen(fileName,"r");
	if(ptr==NULL)
		return false;
	else{
		fclose(ptr);
		return true;
	}
	
}

bool Configuration::config_create(const char *fileName){
	ptr=fopen(fileName,"w");
	if(ptr==NULL){
		return false;
	}
	else{
		fclose(ptr);
		return true;
	}
	
}

bool Configuration::config_insert(const char *configTag, const char *data){
	configChanged=true;
	for(count=0;count<=configLines;count++){
		if(strcmp(configLine[count][0],configTag)==0){
			sprintf(configLine[count][1],"%s",data);
			return true;
		}
	}
	configLines++;
	sprintf(configLine[configLines][0],"%s",configTag);
	sprintf(configLine[configLines][1],"%s",data);
}

bool Configuration::config_get(char *stringOut, const char *configTag){
	for(count=0;count<=configLines;count++){
		if(strcmp(configLine[count][0],configTag)==0){
			sprintf(stringOut,"%s",configLine[count][1]);
			return true;
		}
	}
	sprintf(stringOut,"");
	return false;
}

bool Configuration::config_save(){
	ptr=fopen(configFile,"w");
	if(ptr==NULL)
		return false;
	for(count=0;count<=configLines;count++){
		sprintf(buffer,"%s = %s\n",configLine[count][0],configLine[count][1]);
		fputs(buffer,ptr);
	}
	fclose(ptr);
	configChanged=false;
	return true;
}

bool Configuration::config_remove(const char *configTag){
	bool found=false;
	for(count=0;count<=configLines;count++){
		if(strcmp(configLine[count][0],configTag)==0){
			found=true;
			configLines--;
		}
		if(found){
			sprintf(configLine[count][0],"%s",configLine[count+1][0]);
			sprintf(configLine[count][1],"%s",configLine[count+1][1]);
		}	
	}
	if(found)
		return true;
	else
		return false;
}
