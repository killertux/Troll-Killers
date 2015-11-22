//This is very old
//I need to redo

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <stdio.h>
#include <string.h>

class Configuration {
	private:
	FILE *ptr;
	char buffer[255],configFile[255];
	char configLine[255][2][255];
	int configLines;
	int count;
	bool configChanged;
	
	void get_word(char *,char *,int);
	
	
	public:
	Configuration();
	~Configuration();
	
	bool config_found(const char *);
	bool config_create(const char *);
	bool config_load(const char *);
	bool config_save();
	
	bool config_insert(const char *,const char *);
	bool config_get(char *,const char *);
	bool config_remove(const char *);

};

#endif
