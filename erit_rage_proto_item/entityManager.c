
    #include "EntityManager.h"


Entity* firstEntity = NULL;
unsigned char nbPlayer = 0;
sfRectangleShape* entity;

//initialise ce qui doit etre crée une seule fois pour les ennemies
void initEntity()
{
    entity = sfRectangleShape_create();
    sfRectangleShape_setSize(entity, (sfVector2f) { 30, 30 });
    sfRectangleShape_setFillColor(entity, sfBlack);
}
//prepare un ennemie a ajouter
void createEntity(sfVector2f _posEntity, unsigned char _typeEntity)
{
    Entity* tempEntity = (Entity*)malloc(sizeof(Entity));
    tempEntity->positionEntity = _posEntity;
    if (_typeEntity == 0)
    {
        nbPlayer++;
        tempEntity->player = (Player*)malloc(sizeof(Player));
        tempEntity->player->PlayerID = nbPlayer;
    }
    else
    {
        tempEntity->item->ItemID = iRand(0, 100);
    }
    addEntity(tempEntity);
}
//ajoute un ennemie a la liste chainée ennemie
void addEntity(Entity* _entity)
{
    _entity->nextEntity = firstEntity;
    firstEntity = _entity;
}
//met a jour la liste chainée ennemie
void updateEntity()
{

    Entity* tempEntity = firstEntity;
    while (tempEntity != NULL)
    {
        if (tempEntity->player != NULL)
        {
            if (sfKeyboard_isScancodePressed(sfScanD))
                tempEntity->positionEntity.x += 200 * getDeltaTime();
            if (sfKeyboard_isScancodePressed(sfScanA))
                tempEntity->positionEntity.x -= 200 * getDeltaTime();
            if (sfKeyboard_isScancodePressed(sfScanW))
                tempEntity->positionEntity.y -= 200 * getDeltaTime();
            if (sfKeyboard_isScancodePressed(sfScanS))
                tempEntity->positionEntity.y += 200 * getDeltaTime();
        }
        tempEntity = tempEntity->nextEntity;
    }
}
//retire un ennemie donnée de la liste chainée ennemie
Entity* removeEntity(Entity* _entity)
{
    if (_entity == firstEntity)
    {
        Entity* tempEntity = _entity->nextEntity;
        firstEntity = tempEntity;
        free(_entity);
        return tempEntity;
    }
    else
    {
        Entity* tempEntity = firstEntity;
        while (tempEntity->nextEntity != _entity)
        {
            tempEntity = tempEntity->nextEntity;
        }
        tempEntity->nextEntity = _entity->nextEntity;
        free(_entity);
        return tempEntity->nextEntity;
    }
}
//affiche la liste chainée ennemie
void displayEntity(sfRenderWindow* _window)
{
    Entity* tempEntity = firstEntity;
    while (tempEntity != NULL)
    {
        sfRectangleShape_setPosition(entity, tempEntity->positionEntity);
        sfRenderWindow_drawRectangleShape(_window, entity, NULL);
        tempEntity = tempEntity->nextEntity;
    }
}