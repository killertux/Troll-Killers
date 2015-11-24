#include "Menu.hpp"

 MenuPrinc::MenuPrinc(int res_x,int res_y){//Construtor do menu principal , carregando as imagens e testando se não houve erro no carregamento
	this->res_x=res_x;
	this->res_y=res_y;
	fundo = al_load_bitmap("Menu_Img/fundo1.jpg");
	bot1 = al_load_bitmap("Menu_Img/connect1.jpg");
	bot2 = al_load_bitmap("Menu_Img/quit1.jpg");
	bot1_s = al_load_bitmap("Menu_Img/connect2.jpg");
	bot2_s = al_load_bitmap("Menu_Img/quit2.jpg");
	if(fundo == NULL || bot1 == NULL || bot2 == NULL || bot1_s == NULL || bot2_s == NULL){
		std::cout << "Problem loading the menu images\n";
		exit(-1);
	}
}

MenuPrinc::~MenuPrinc(){

	al_destroy_bitmap(fundo);
	al_destroy_bitmap(bot1);
	al_destroy_bitmap(bot1_s);
	al_destroy_bitmap(bot2);
	al_destroy_bitmap(bot2_s);
}


MenuArmas::MenuArmas(int res_x,int res_y){//Construtor do menu armas , carregando as imagens e testando se não houve erro no carregamento
	this->res_x=res_x;
	this->res_y=res_y;
	fundo = al_load_bitmap("Menu_Img/fundo2.jpg");
	bot1 = al_load_bitmap("Menu_Img/pistol1.jpg");
	bot2 = al_load_bitmap("Menu_Img/rifle1.jpg");
	bot3 = al_load_bitmap("Menu_Img/quit1.jpg");
	bot1_s = al_load_bitmap("Menu_Img/pistol2.jpg");
	bot2_s = al_load_bitmap("Menu_Img/rifle2.jpg");
	bot3_s = al_load_bitmap("Menu_Img/quit2.jpg");
	if(fundo == NULL || bot1 == NULL || bot2 == NULL || bot3==NULL || bot1_s == NULL || bot2_s == NULL || bot3_s == NULL){
		std::cout << "Problem loading the menu images\n";
		exit(-1);
	}
}
MenuArmas::~MenuArmas(){
	al_destroy_bitmap(fundo);
	al_destroy_bitmap(bot1);
	al_destroy_bitmap(bot1_s);
	al_destroy_bitmap(bot2);
	al_destroy_bitmap(bot2_s);
	al_destroy_bitmap(bot3);
	al_destroy_bitmap(bot3_s);
}


void MenuPrinc::print_menu(){ //Função que imprime na tela o menu principal
	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_bitmap(fundo, (res_x/2 - al_get_bitmap_width(fundo)/2), 0, 0);
	if(bot1S)
		al_draw_bitmap(bot1_s,(res_x / 2 - al_get_bitmap_width(bot1_s)/2), (res_y /3),0);
	else
		al_draw_bitmap(bot1,(res_x / 2 - al_get_bitmap_width(bot1)/2), (res_y /3),0);
	if(bot2S)
		al_draw_bitmap(bot2_s,(res_x / 2 - al_get_bitmap_width(bot2_s)/2), (res_y *2/3), 0);
	else
		al_draw_bitmap(bot2,(res_x / 2 - al_get_bitmap_width(bot2)/2), (res_y *2/3), 0);
}

void MenuPrinc::botao(ALLEGRO_MOUSE_STATE *mouseState){//Função que testa se o cursor está localizado em cima do botão, sinalizando uma flag usada para a mudança da imagem do botao
	if (mouseState->x >= res_x / 2 - al_get_bitmap_width(bot1_s)/2 &&
		mouseState->x <= res_x / 2 + al_get_bitmap_width(bot1)/2 &&
		mouseState->y>= res_y / 3   &&
		mouseState->y<= res_y / 3 + al_get_bitmap_height(bot1))
	{
		bot1S=true;
	} else
		bot1S=false;
	if (mouseState->x >= res_x / 2 - al_get_bitmap_width(bot2_s)/2 &&
		mouseState->x <= res_x / 2 + al_get_bitmap_width(bot2)/2 &&
		mouseState->y>= (res_y *2/ 3) &&
		mouseState->y <= (res_y *2/ 3) + al_get_bitmap_height(bot2))
	{
		bot2S=true;
	} else
		bot2S=false;
}

int MenuPrinc::botao_action()//Função que diz qual ação será executada quando o botão do mouse for acionado.
{
	if(bot1S)//botao 1 , connect , vai mudar para o proximo menu
		return CHANGE_MENU;

	if(bot2S)//botao 2 , quit , vai sair do jogo
		return EXIT;

	return 0;
}

void MenuArmas::botao(ALLEGRO_MOUSE_STATE *mouseState){//Função que checa se o mouse está em cima do botao , sinalizando uma flag para a mudança de imagem
	if (mouseState->x >= res_x / 3  &&
		mouseState->x <= res_x / 3 + al_get_bitmap_width(bot1) &&
		mouseState->y>= res_y /2  &&
		mouseState->y<= res_y /2+ al_get_bitmap_height(bot1))
	{
		bot1S=true;
	} else
		bot1S=false;
	if (mouseState->x >= res_x*2/ 3  &&
		mouseState->x <= res_x *2/ 3 + al_get_bitmap_width(bot2) &&
		mouseState->y>= (res_y/2) &&
		mouseState->y <= (res_y /2) + al_get_bitmap_height(bot2))
	{
		bot2S=true;
	} else
		bot2S=false;
	if (mouseState->x >= res_x  / 2  &&
		mouseState->x <= res_x  / 2 + al_get_bitmap_width(bot2) &&
		mouseState->y>= (res_y  *3 /4) &&
		mouseState->y <= (res_y  *3 /4) + al_get_bitmap_height(bot2))
	{
		bot3S=true;
	} else
		bot3S=false;
}

void MenuArmas::print_menu(){//Função que imprime o menu , com o fundo e seus botões
	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_bitmap(fundo, (res_x/2 - al_get_bitmap_width(fundo)/2), 0, 0);
	if(bot1S)
		al_draw_bitmap(bot1_s,(res_x / 3), (res_y /2),0);
	else
		al_draw_bitmap(bot1,(res_x / 3), (res_y /2),0);
	if(bot2S)
		al_draw_bitmap(bot2_s,(res_x *2/ 3), (res_y /2), 0);
	else
		al_draw_bitmap(bot2,(res_x *2/ 3), (res_y /2), 0);
	if(bot3S)
		al_draw_bitmap(bot3_s,(res_x / 2), (res_y * 3 /4),0);
	else
		al_draw_bitmap(bot3,(res_x / 2), (res_y * 3 /4),0);

}
int MenuArmas::botao_action()//Função que diz oque cada botão faz
{
	if(bot1S)
		return MENU_PISTOL;
	if(bot2S)
		return MENU_RIFLE;
	if(bot3S)
		return EXIT;
	return 0;
}

