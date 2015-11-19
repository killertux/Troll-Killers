#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Menu {
protected:
    ALLEGRO_BITMAP *fundo = NULL;
    ALLEGRO_BITMAP *bot1 = NULL;
    ALLEGRO_BITMAP *bot2 = NULL;
public:
    Menu();
    void print_menu();
};

class MenuPrinc : public Menu{
public:
    MenuPrinc();
};

class MenuArmas : public Menu{
    ALLEGRO_BITMAP *bot3 = NULL;
public:
    MenuArmas();
};
