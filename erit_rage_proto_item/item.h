#pragma once
#include "tools.h"



typedef struct Item Item;
struct Item
{
	Item* pNext;
	sfTexture* texture;
	sfIntRect iRect;
	sfVector2f pos;
	char rarity;
	char durability;
	char name;

};

Item* itemBegin;


void initItem();
void ajouteItem(char _name, sfVector2f _itemPos, int _left, int _top);
void addItem(Item* _item);
sfIntRect seekItem(char _name);
void updateItem();
void drawItem(sfRenderWindow* _window);
Item* deleteItem(Item* _item);