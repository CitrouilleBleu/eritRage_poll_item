#include "tools.h"
#include "itemManager.h"
#include "entityManager.h"




int main()
{

    sfVideoMode mode = { 1920,1080,32 };
    sfRenderWindow* window = sfRenderWindow_create(mode, "Titre", sfResize | sfClose, NULL);
    sfEvent events;
    initTools();
    initItem();
    ItemOnload();
	printf("%d\n", getItemById(10)->id);
    printf("%d\n", getItemByName("liasseBillets")->id);
    ajouteItem(2, (sfVector2f){500,500});
    ajouteItem(5, (sfVector2f){400,400});
    ajouteItem(3, (sfVector2f){100,100});
    ajouteItem(6, (sfVector2f){300,300});
    ajouteItem(40, (sfVector2f){600,600});


    while (sfRenderWindow_isOpen(window))
    {
        restartClock();
        while (sfRenderWindow_pollEvent(window, &events))
        {
            if (events.type == sfEvtClosed)
            {
                sfRenderWindow_close(window);
            }

        }  
      //  updateItem();

        sfRenderWindow_clear(window, sfBlack);
        drawItem(window);
        sfRenderWindow_display(window);
    }
}
