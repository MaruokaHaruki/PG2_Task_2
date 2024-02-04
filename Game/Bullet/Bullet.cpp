#include "./Game/Bullet/Bullet.h"

Bullet::Bullet() {
	pos_.x = 0;
	pos_.y = 0;
	Velocity_ = 16;
	acceleration_ = 0;
	radius_ = 4;
	isShot_ = false;
}

Bullet::~Bullet() {
	delete destructor_;
}

void Bullet::Update() {
	if (isShot_) {
		pos_.y += Velocity_;
	}

	if (pos_.y >= 512) {
		isShot_ = false;
	}
}

void Bullet::DrawUpdate() {
	if (isShot_) {
		Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y) * -1 + 500, static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, 0xFF0000FF, kFillModeSolid);
	}
}
