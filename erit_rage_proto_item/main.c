#include "tools.h"
#include "item.h"




int main()
{

    sfVideoMode mode = { 1920,1080,32 };
    sfRenderWindow* window = sfRenderWindow_create(mode, "Titre", sfResize | sfClose, NULL);
    sfEvent events;
    initTools();
    initItem();
    ItemOnload();
	printf("%d\n", getItemById(10)->id);
    printf("%d\n", getItemByName("liasse billets")->id);
    ajouteItem("liasse billets", (sfVector2f){500,500}, 0, 0);
    ajouteItem("liasse billets", (sfVector2f){400,400}, 1, 0);
    ajouteItem("liasse billets", (sfVector2f){100,100}, 2, 2);
    ajouteItem("liasse billets", (sfVector2f){300,300}, 3, 0);
    ajouteItem("liasse billets", (sfVector2f){600,600}, 4, 1);
    ajouteItem("liasse billets", (sfVector2f){700,700}, 5, 0);

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
         updateItem();

        sfRenderWindow_clear(window, sfBlack);
        drawItem(window);
        sfRenderWindow_display(window);
    }
}
