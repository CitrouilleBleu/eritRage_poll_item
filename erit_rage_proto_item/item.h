#pragma once
#include "tools.h"

static int widthSpriteSheetPart = 25;
static int heightSpriteSheetPart = 31;

typedef struct ItemTemplate ItemTemplate;
struct ItemTemplate
{

	ItemTemplate* pNext;
	sfIntRect iRect;
	sfVector2f hitbox;
	char name[40];
	int rarity;
	int durability;
	int id;

};

typedef struct Item Item;
struct Item
{

	Item* pNext;
	sfIntRect iRect;
	sfVector2f pos;
	ItemTemplate* item;
	int rarity;
	int durability;

};

Item* itemBegin;


void initItem();
void ajouteItem(char _name, sfVector2f _itemPos, int _left, int _top);
void addItem(Item* _item);
sfIntRect seekItem(char _name);
void updateItem();
void drawItem(sfRenderWindow* _window);
Item* deleteItem(Item* _item);
void ItemOnload();
ItemTemplate* getItemById(int _id);
ItemTemplate* getItemByName(char* _name);