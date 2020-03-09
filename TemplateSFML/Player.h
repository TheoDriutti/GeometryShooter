#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "Arena.h"
#include "Enemy.h"

enum class ACTION
{
	UP, DOWN, LEFT, RIGHT, NONE, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT, IDLE, DEAD
};

class Player : public Character
{
public:
	bool hasBulletTime = false;
	bool canMove = true;
	bool isDashing = false;
	bool hasTakenDamage = false;
	bool canDash;
	bool isInvincible = false;
	float dashFactor;
	float baseSpeed;
	float dashDuration;
	float dashCD = 0.0f;
	float baseCD = 0.0f;
	float colorChangeDamage = 0.1f;
	sf::CircleShape cercle;
	ACTION typeMovement;
	sf::CircleShape spawnCircle;


public:
	Player(int _posX, int _posY, Weapon* weapon);
	void Dash();
	void DrawPlayer(sf::RenderWindow* window);
	void PerformAction(Arena* arene, std::list<Enemy*> listEnemy, float _deltaTime);
	void MoveTo(float _posX, float _posY) override;
	void SetTypeMovment(ACTION _newAction);
	bool CheckForMovement(ACTION _action);
	void SetComboMovement(ACTION _action);
	void SetWeapon(Weapon* weapon);
	void RotationPlayer(float angleRotation);
	void FeedbackDamageTaken(float _deltaTime);
private:
	void UpdateCerclePos();
};