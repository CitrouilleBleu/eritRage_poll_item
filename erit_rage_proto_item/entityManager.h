#pragma once
#include "tools.h"
extern unsigned char nbPlayer;

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


void initEntity();
void createEntity(sfVector2f _posEntity, unsigned char _typeEntity);
void addEntity(Entity* _entity);
void updateEntity();
Entity* removeEntity(Entity* _entity);
void displayEntity(sfRenderWindow* _window);