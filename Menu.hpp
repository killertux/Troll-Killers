#ifndef MENU_HPP
#define MENU_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Defines.hpp"
//#include "Client.hpp"
#include <iostream>

#define CHANGE_MENU 1
#define EXIT 2
#define MENU_RIFLE 3
#define MENU_PISTOL 4

class IMenu { //Declaração da interface Menu
public:
	virtual void print_menu()=0;
	virtual ~IMenu(){}
	virtual void botao(ALLEGRO_MOUSE_STATE *mouseState)=0;
 	virtual int botao_action()=0;
};

class MenuPrinc : public IMenu{//Declaração da classe , Menu Principal , que possui imagem de fundo , botões e flags para sinalizar se o mouse está em cima dos botões
	ALLEGRO_BITMAP *fundo;
	ALLEGRO_BITMAP *bot1;
	ALLEGRO_BITMAP *bot2;
	ALLEGRO_BITMAP *bot1_s;
	ALLEGRO_BITMAP *bot2_s;
	bool bot1S,bot2S;
	int res_x,res_y;
public:
	MenuPrinc(int res_x,int res_y);
	virtual ~MenuPrinc();
	virtual void botao(ALLEGRO_MOUSE_STATE *mouseState);
	virtual void print_menu();
	virtual int botao_action();
};

class MenuArmas : public IMenu{//Declaração da classe , Menu de Armas, que possui imagem de fundo , botões e flags para sinalizar se o mouse está em cima dos botões
	ALLEGRO_BITMAP *fundo;
	ALLEGRO_BITMAP *bot1;
	ALLEGRO_BITMAP *bot2;
	ALLEGRO_BITMAP *bot3;
	ALLEGRO_BITMAP *bot1_s;
	ALLEGRO_BITMAP *bot2_s;
	ALLEGRO_BITMAP *bot3_s;
	bool bot1S,bot2S,bot3S;
	int res_x,res_y;
public:
	MenuArmas(int res_x,int res_y);
	virtual ~MenuArmas();
	virtual void botao(ALLEGRO_MOUSE_STATE *mouseState);
	virtual void print_menu();
	virtual int botao_action();
};
#endif
