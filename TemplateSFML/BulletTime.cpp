#include "BulletTime.h"
#include "Player.h"

BulletTime::BulletTime(float posX, float posY, sf::Font* textFont, int timeBulletTime) : PowerUp(posX, posY, "BulletTime", textFont, timeBulletTime) {

	this->namePowerUp.setPosition(this->posX - 20, this->posY - 45);
	this->namePowerUp.setCharacterSize(20);
}

void BulletTime::ApplyPowerUp(Player* player)
{
	player->bulletTimeDuration = this->powerUp;
	player->onBulletTime = true;
}