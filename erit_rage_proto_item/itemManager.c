#include "itemManager.h"




sfSprite* item;
sfTexture* spriteSheet;



void initItem()
{
	item = sfSprite_create();
	spriteSheet = sfTexture_createFromFile("..\\ressoursces\\textures\\items\\spriteSheet_items.png", NULL);
	sfSprite_setTexture(item, spriteSheet, sfTrue);
}

void ajouteItem(int _id, sfVector2f _itemPos)
{
	ItemTemplate* tempItem = (ItemTemplate*)calloc(1, sizeof(ItemTemplate));
	tempItem->pos = _itemPos;
	tempItem->item = getItemById(_id);
	tempItem->iRect = (sfIntRect){ tempItem->item->iRect.left * widthSpriteSheetPart,  tempItem->item->iRect.top * heightSpriteSheetPart, tempItem->item->iRect.width,  tempItem->item->iRect.height };
	addItem(tempItem);
}
void addItemData(ItemData* _itemData)
{
	_itemData->pNext = itemDataBegin;
	itemDataBegin = _itemData;
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
		sscanf(tmpligne, "%s %d %d %d %d %d %d", tmpname, &tmphitbox.x, &tmphitbox.y, &tmprect.left, &tmprect.top, &tmpdura, &tmpvalue);
		ItemData* tempItem = (ItemData*)calloc(1, sizeof(ItemData));
		strcpy(tempItem->name, &tmpname);
		tempItem->id = tmpid;
		tempItem->iRect = tmprect;

		tempItem->hitbox = tmphitbox;
		tempItem->durability = tmpdura;
		tempItem->rarity = tmpvalue;
			addItemData(tempItem);
		tmpid++;
	}
	fclose(file);
}
void addItem(ItemTemplate* _item)
{
	_item->pNext = itemBegin;
	itemBegin = _item;
}

ItemData* getItemById(int _id)
{
	ItemData* tempItem = itemDataBegin;
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
ItemData* getItemByName(char* _name)
{
	ItemData* tempItem = itemDataBegin;
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
	ItemTemplate* tempItem = itemBegin;
	while (tempItem != NULL)
	{
		tempItem->pos.x += 50 * getDeltaTime();
		tempItem = tempItem->pNext;
	}
}

void drawItem(sfRenderWindow* _window)
{
	ItemTemplate* tempItem = itemBegin;
	while (tempItem != NULL)
	{

		sfSprite_setPosition(item, tempItem->pos);
		sfSprite_setTextureRect(item, tempItem->iRect);
		sfRenderWindow_drawSprite(_window, item, NULL);

		tempItem = tempItem->pNext;
	}
}

ItemTemplate* deleteItem(ItemTemplate* _item)
{
	if (_item == itemBegin)
	{
		ItemTemplate* tempItem = _item->pNext;
		itemBegin = tempItem;
		free(_item);
		return tempItem;
	}
	else
	{
		ItemTemplate* tempItem = itemBegin;
		while (tempItem->pNext != _item)
		{
			tempItem = tempItem->pNext;
		}
		tempItem->pNext = _item->pNext;
		free(_item);
		return tempItem->pNext;
	}
}
