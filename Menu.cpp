#include "Menu.hpp"
#include "Defines.hpp"

MenuPrinc::MenuPrinc(){
    fundo = al_load_bitmap("Menu Img\\fundo1");
    bot1 = al_load_bitmap("Menu Img\\connect1");
    bot2 = al_load_bitmap("Menu Img \\quit1");
}

MenuArmas::MenuArmas(){
    fundo = al_load_bitmap("Menu Img\\fundo2");
    bot1 = al_load_bitmap("Menu Img\\pistol1");
    bot2 = al_load_bitmap("Menu Img\\rifle1");
    bot3 = al_load_bitmap("Menu Img \\quit1");

}

void MenuPrinc::print_menu(){
    al_draw_bitmap(fundo1, 0, 0, 0);
    al_draw_bitmap(bot1,(RES_X / 2), (RES_Y /3),0);
    al_draw_bitmap(bot2,(RES_X / 2), (RES_Y *2/3), 0);
}

void MenuArmas::print_menu(){
    al_draw_bitmap(fundo2, 0, 0, 0);
    al_draw_bitmap(bot1,(RES_X / 3), (RES_Y /2),0);
    al_draw_bitmap(bot2,(RES_X *2/ 3), (RES_Y /2), 0);
    al_draw_bitmap(bot3,(RES_X / 2), (RES_Y * 3 /4),0);
}

void MenuPrinc::botao(){//vi na internet desse jeito , no tutorial , que ele nao usava variáveis pra achar a posicao do mouse , vê se dá assim...
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
            if (evento.type == ALLEGRO_EVENT_MOUSE_AXES)
            {
                // Verificamos se ele está sobre o botao 1 , com funcao de conectar
                if (evento.mouse.x >= RES_X / 2 - al_get_bitmap_width(bot1) / 2 &&
                    evento.mouse.x <= RES_X / 2 + al_get_bitmap_width(bot1) / 2 &&
                    evento.mouse.y >= RES_Y / 3 - al_get_bitmap_height(bot1) / 2 &&
                    evento.mouse.y <= RES_Y / 3 + al_get_bitmap_height(bot1) / 2)
                {
                    //implementar como conectar LEMBRAR DE MUDAR A IMAGEM CONNECT1 PARA CONNECT2 ENQUANTO ESTA EM CIMA
                }
                // Verificamos se ele está sobre o botao 2 , com funcao de sair
                if (evento.mouse.x >= RES_X / 2 - al_get_bitmap_width(bot2) / 2 &&
                    evento.mouse.x <= RES_X / 2 + al_get_bitmap_width(bot2) / 2 &&
                    evento.mouse.y >= (RES_Y *2/ 3) - al_get_bitmap_height(bot2) / 2 &&
                    evento.mouse.y <= (RES_Y *2/ 3) + al_get_bitmap_height(bot2) / 2)
                {
                    //implementar como sair LEMBRAR DE MUDAR A IMAGEM QUIT1 PARA QUIT2 ENQUANTO ESTA EM CIMA
                }
}

void MenuArmas::botao(){
    ALLEGRO_EVENT_QUEUE *fila_eventos = NULL;
    fila_eventos = al_create_event_queue();
    al_register_event_source(fila_eventos, al_get_mouse_event_source());
    while (!al_is_event_queue_empty(fila_eventos))
        {
            ALLEGRO_EVENT evento;
            al_wait_for_event(fila_eventos, &evento);
            if (evento.type == ALLEGRO_EVENT_MOUSE_AXES)
            {
                // Verificamos se ele está sobre o botao 1 , com funcao de usar a arma pistola
                if (evento.mouse.x >= RES_X / 3 - al_get_bitmap_width(bot1) / 2 &&
                    evento.mouse.x <= RES_X / 3 + al_get_bitmap_width(bot1) / 2 &&
                    evento.mouse.y >= RES_Y / 2 - al_get_bitmap_height(bot1) / 2 &&
                    evento.mouse.y <= RES_Y / 2 + al_get_bitmap_height(bot1) / 2)
                {
                    //implementar como usar pistola LEMBRAR DE MUDAR A IMAGEM PISTOL1 PARA PISTOL2 ENQUANTO ESTA EM CIMA
                }
                // Verificamos se ele está sobre o botao 2 , com funcao de usar a arma rifle
                if (evento.mouse.x >= (RES_X *2/ 3) - al_get_bitmap_width(bot2) / 2 &&
                    evento.mouse.x <= (RES_X *2/ 3) + al_get_bitmap_width(bot2) / 2 &&
                    evento.mouse.y >= RES_Y / 2 - al_get_bitmap_height(bot2) / 2 &&
                    evento.mouse.y <= RES_Y / 2 + al_get_bitmap_height(bot2) / 2)
                {
                    //implementar como usar rifle LEMBRAR DE MUDAR A IMAGEM RIFLE1 PARA RIFLE2 ENQUANTO ESTA EM CIMA
                }
                // Verificamos se ele está sobre o botao 3 , com funcao de sair
                if (evento.mouse.x >= (RES_X /2) - al_get_bitmap_width(bot2) / 2 &&
                    evento.mouse.x <= (RES_X /2) + al_get_bitmap_width(bot2) / 2 &&
                    evento.mouse.y >= (RES_Y *3/4) - al_get_bitmap_height(bot2) / 2 &&
                    evento.mouse.y <= (RES_Y *3/4) + al_get_bitmap_height(bot2) / 2)
                {
                    //implementar como sair LEMBRAR DE MUDAR A IMAGEM QUIT1 PARA QUIT2 ENQUANTO ESTA EM CIMA
                }

}
