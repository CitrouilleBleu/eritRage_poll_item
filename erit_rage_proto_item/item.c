#include "item.h"




sfSprite* item;
sfTexture* spriteSheet;



void initItem()
{
	item = sfSprite_create();
	spriteSheet = sfTexture_createFromFile("..\\ressoursces\\textures\\items\\spriteSheet_items.png", NULL);
	sfSprite_setTexture(item, spriteSheet, sfTrue);
}

void ajouteItem(int _id, sfVector2f _itemPos, int _left, int _top)
{
	Item* tempItem = (Item*)calloc(1, sizeof(Item));
	tempItem->pos = _itemPos;
	tempItem->iRect = (sfIntRect){ _left * 25, _top * 31, 25, 31 };
	tempItem->item = getItemById(_id);

	addItem(tempItem);
}
void ItemOnload()
{
	
	char tmpligne[200];
	char tmpname[40];
	sfIntRect tmprect;
	 tmprect.height = heightSpriteSheetPart;
	 tmprect.width = widthSpriteSheetPart;
	sfVector2f tmphitbox;
	int tmpdura;
	int tmpvalue;
	int tmpid = 1;

	FILE* file = fopen("data2.tsv", "r");
	fgets(tmpligne, sizeof(tmpligne), file); // Skip header line
	while (fgets(tmpligne, sizeof(tmpligne), file))
	{
		sscanf(tmpligne, "%s,%d,%d,%d,%d,%d,%d", tmpname, &tmprect.left, &tmprect.top, &tmphitbox.x, &tmphitbox.y, &tmpdura, &tmpvalue);
		ItemTemplate* tempItem = (ItemTemplate*)calloc(1, sizeof(ItemTemplate));
		strcpy(tempItem->name, &tmpname);
		tempItem->id = tmpid;
		tempItem->iRect = tmprect;
		tempItem->hitbox = tmphitbox;
		tempItem->durability = tmpdura;
		tempItem->rarity = tmpvalue;
			addItem(tempItem);
		tmpid++;
	}
	fclose(file);
}
void addItem(Item* _item)
{
	_item->pNext = itemBegin;
	itemBegin = _item;
}
ItemTemplate* getItemById(int _id)
{
	ItemTemplate* tempItem = itemBegin;
	while (tempItem != NULL)
	{
		if (_id == tempItem->id)
		{
			return tempItem;
		}
		tempItem = tempItem->pNext;
	}
	return NULL;
}
ItemTemplate* getItemByName(char* _name)
{
	ItemTemplate* tempItem = itemBegin;
	while (tempItem != NULL)
	{
		if ((strcmp(_name, tempItem->name)) == 0)
		{
			return tempItem;
		}
		tempItem = tempItem->pNext;
	}
	return NULL;
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
