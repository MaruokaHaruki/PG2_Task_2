#pragma once
#include "./Game/Player/Player.h"
#include "./Game/Enemy/Enemy.h"
#include "./Game/Bullet/Bullet.h"
#include "Vector2.h"

class CollisionManager {
public:
    CollisionManager();

    // プレイヤーと敵の当たり判定を行う
    void CheckPlayerEnemyCollision(Player& player, Enemy& enemy);

    // 敵と弾の当たり判定を行う
    void CheckEnemyBulletCollision(Enemy& enemy, Bullet& bullet);
};

