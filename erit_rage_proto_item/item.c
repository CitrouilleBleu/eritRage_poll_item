#include "item.h"




sfSprite* item;
sfTexture* spriteSheet;



void initItem()
{
	item = sfSprite_create();
	spriteSheet = sfTexture_createFromFile("..\\ressoursces\\textures\\items\\spriteSheet_items.png", NULL);
	sfSprite_setTexture(item, spriteSheet, sfTrue);
}

void ajouteItem(char _name, sfVector2f _itemPos, int _left, int _top)
{
	Item* tempItem = (Item*)calloc(1, sizeof(Item));
	tempItem->pos = _itemPos;
	tempItem->iRect = (sfIntRect){ _left * 25, _top * 31, 25, 31 };
	tempItem->name = _name;

	addItem(tempItem);
}

void addItem(Item* _item)
{
	_item->pNext = itemBegin;
	itemBegin = _item;
}

void updateItem()
{
	Item* tempItem = itemBegin;
	while (tempItem != NULL)
	{
		tempItem->pos.x += 50 * GetDeltaTime();
		tempItem = tempItem->pNext;
	}
}

void drawItem(sfRenderWindow* _window)
{
	Item* tempItem = itemBegin;
	while (tempItem != NULL)
	{
		sfSprite_setPosition(item, tempItem->pos);
		sfSprite_setTextureRect(item, tempItem->iRect);
		sfRenderWindow_drawSprite(_window, item, NULL);

		tempItem = tempItem->pNext;
	}
}

Item* deleteItem(Item* _item)
{
	if (_item == itemBegin)
	{
		Item* tempItem = _item->pNext;
		itemBegin = tempItem;
		free(_item);
		return tempItem;
	}
	else
	{
		Item* tempItem = itemBegin;
		while (tempItem->pNext != _item)
		{
			tempItem = tempItem->pNext;
		}
		tempItem->pNext = _item->pNext;
		free(_item);
		return tempItem->pNext;
	}
}
