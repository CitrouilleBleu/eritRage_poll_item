#pragma once
#include "tools.h"

static int widthSpriteSheetPart = 25;
static int heightSpriteSheetPart = 31;

typedef struct ItemData ItemData;
struct ItemData
{

	ItemData* pNext;
	sfIntRect iRect;
	sfVector2f hitbox;
	char name[40];
	int rarity;
	int durability;
	int id;

};

typedef struct ItemTemplate ItemTemplate;
struct ItemTemplate
{
	ItemTemplate* pNext;
	ItemData* item;
	sfBool isHold ;
	sfIntRect iRect;
	sfVector2f pos;
	int rarity;
	int durability;

};


ItemData* itemDataBegin;
ItemTemplate* itemBegin;


void initItem();
void ajouteItem(int _id, sfVector2f _itemPos);
void addItem(ItemTemplate* _item);
sfIntRect seekItem(char _name);
void updateItem();
void drawItem(sfRenderWindow* _window);
ItemTemplate* deleteItem(ItemTemplate* _item);
void ItemOnload();
ItemData* getItemById(int _id);
ItemData* getItemByName(char* _name);