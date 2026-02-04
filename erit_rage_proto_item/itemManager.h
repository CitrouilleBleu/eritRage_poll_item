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
struct ItemTemplate ;
{
	ItemData item;
	sfBool isHold ;
	sfIntRect iRect;
	sfVector2f pos;
	int rarity;
	int durability;

};

{
	unsigned char PlayerID;
};

typedef struct Item Item;
struct Item
{
	char ItemID;
};
typedef struct Entity Entity;
struct Entity
{
	Entity* nextEntity;
	sfVector2f positionEntity;
	union MyUnion
	{
		Player* player;
		Item* item;
	};
};
typedef struct Player Player;
struct Player
{
	unsigned char PlayerID;
};

typedef struct Item Item;
struct Item
{
	char ItemID;
};
typedef struct Entity Entity;
struct Entity
{
	Entity* nextEntity;
	sfVector2f positionEntity;
	union MyUnion
	{
		Player* player;
		Item* item;
	};
};
Entity* firstEntity; *
ItemData* itemBegin;


void initItem();
void ajouteItem(char _name, sfVector2f _itemPos, int _left, int _top);
void addItem(ItemTemplate* _item);
sfIntRect seekItem(char _name);
void updateItem();
void drawItem(sfRenderWindow* _window);
Item* deleteItem(ItemTemplate* _item);
void ItemOnload();
ItemTemplate* getItemById(int _id);
ItemTemplate* getItemByName(char* _name);