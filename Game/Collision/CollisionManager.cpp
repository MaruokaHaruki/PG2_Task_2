#include <corecrt_math.h>
#include "./Game/Object/BaseObject.h"
#include "./Game/Collision/CollisionManager.h"

CollisionManager::CollisionManager() {
}

void CollisionManager::CheckPlayerEnemyCollision(Player& player, Enemy& enemy) {
	// プレイヤーと敵の当たり判定を行う
	// プレイヤーと敵の位置を取得
	Vector2 playerPos = player.GetPosition();
	Vector2 enemyPos = enemy.GetPosition();

	// プレイヤーと敵の半径を取得
	float playerRadius = player.GetRadius();
	float enemyRadius = enemy.GetRadius();

	// 円形当たり判定
	float circleCollisionX = enemyPos.x - playerPos.x;
	float circleCollisionY = enemyPos.y - playerPos.y;
	float distance = static_cast<float>(sqrt(circleCollisionX * circleCollisionX + circleCollisionY * circleCollisionY));

	// プレイヤーと敵の半径の和を計算
	float radiusSum = playerRadius + enemyRadius;

	// 中心間の距離が半径の和よりも小さい場合は当たっている
	if (distance <= radiusSum) {
		// プレイヤーと敵が衝突した場合の処理
		player.SetIsHit(true);
	}
}

void CollisionManager::CheckEnemyBulletCollision(Enemy& enemy, Bullet& bullet) {
	// 敵と弾の当たり判定処理
	Vector2 enemyPos = enemy.GetPosition();
	Vector2 bulletPos = bullet.GetPosition();
	float enemyRadius = enemy.GetRadius();
	float bulletRadius = bullet.GetRadius();

	// 弾と敵の位置の差を計算
	float diffX = enemyPos.x - bulletPos.x;
	float diffY = enemyPos.y - bulletPos.y;

	// 弾と敵の距離を計算
	float distance = static_cast<float>(sqrt(diffX * diffX + diffY * diffY));

	// 弾と敵の半径の和を計算
	float radiusSum = enemyRadius + bulletRadius;

	// 当たり判定
	if (distance <= radiusSum) {
		// 当たった場合の処理
		enemy.SetIsHit(true); // 敵のisHit_をtrueに設定
		bullet.SetIsShot(false); // 弾を消すなどの処理
	}
}

