#include "Enemy.h"

Enemy::Enemy(){
	pos_.x = 1280 / 3;
	pos_.y = 720 / 3;
	Velocity_ = 8;
	acceleration_ = 0;
	radius_ = 32;

	respawnTimer_ = 180;
}

Enemy::~Enemy(){
	delete destructor_;
}

void Enemy::Update(){
	pos_.x += Velocity_;
	if (pos_.x + static_cast<int>(radius_) >= 1280) {
		Velocity_ *= -1;
	} else if (pos_.x - static_cast<int>(radius_) <= 0) {
		Velocity_ *= -1;
	}

	///リスポーン処理
	if (isHit_) {
		respawnTimer_ -= 1;
		if (respawnTimer_ <= 0) {
			isHit_ = false;
		}
	} else {
		respawnTimer_ = 180;
	}

}

void Enemy::DrawUpdate(){
	if (!isHit_) {
		Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y) + 20, static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, 0x0000FFFF, kFillModeSolid);
	}
}
