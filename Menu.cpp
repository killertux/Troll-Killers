#include "Menu.hpp"
#include "Defines.hpp"

MenuPrinc::MenuPrinc(){
    fundo = al_load_bitmap("Menu Img\\fundo1");
    bot1 = al_load_bitmap("Menu Img\\connect1");
    bot2 = al_load_bitmap("Menu Img \\quit1");
}

MenuArmas::MenuArmas(){
    fundo = al_load_bitmap("Menu Img\\fundo1");
    bot1 = al_load_bitmap("Menu Img\\pistol1");
    bot2 = al_load_bitmap("Menu Img\\rifle1");
    bot3 = al_load_bitmap("Menu Img \\quit1");
}

Menu::print_menu(){

}
