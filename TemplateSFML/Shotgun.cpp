#include "Shotgun.h"

ShotGun::ShotGun() : Weapon(1, 1.0f, 1.0f) {

}

void ShotGun::Shoot(sf::Vector2f targetProjectile, std::list<Projectile*>* listProjectile)
{
	if (_fireRate < 0) {
		listProjectile->push_back(new Projectile(this->weaponDamage, this->speedBullet, this->origin, targetProjectile));

		listProjectile->push_back(CreateProjectile(targetProjectile, 0.05f));
		listProjectile->push_back(CreateProjectile(targetProjectile, 0.1f));
		listProjectile->push_back(CreateProjectile(targetProjectile, -0.05f));
		listProjectile->push_back(CreateProjectile(targetProjectile, -0.1f));
		_fireRate = fireRate;
	}
	
}

Projectile* ShotGun::CreateProjectile(sf::Vector2f targetProjectile, float angleOffset)
{
	int max = 5 + (this->speedBullet * 100);
	int min = -5 + (this->speedBullet * 100);
	if (min < 9)
	{
		min = 9;
	}
	float randomSpeed = (min + rand() % (max - min));
	double angle = atan2(targetProjectile.y - origin.y, targetProjectile.x - origin.x) + angleOffset;

	sf::Vector2f newTargetProjectile = sf::Vector2f(cos(angle) + this->origin.x, sin(angle) + this->origin.y);
	return new Projectile(this->weaponDamage, randomSpeed / 100, this->origin, newTargetProjectile);
}
