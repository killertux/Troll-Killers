#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class IMenu {
public:
	virtual void print_menu()=0;
	virtual ~IMenu(){}
};

class MenuPrinc : public IMenu{
	ALLEGRO_BITMAP *fundo;
	ALLEGRO_BITMAP *bot1;
	ALLEGRO_BITMAP *bot2;
public:
	MenuPrinc();
};

class MenuArmas : public IMenu{
	ALLEGRO_BITMAP *fundo;
	ALLEGRO_BITMAP *bot1;
	ALLEGRO_BITMAP *bot3;
public:
	MenuArmas();
};
