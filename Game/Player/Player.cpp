#include "Player.h"

///コンストラクタ
Player::Player() {
	pos_.x = 1280 / 2;
	pos_.y = 720 / 2;
	Velocity_ = 8;
	acceleration_ = 0;
	radius_ = 16;
	isHit_ = false;
	bullet_ = new Bullet();
}

///デストラクタ
Player::~Player() {
	delete destructor_;
}

///更新処理
void Player::Update(char* keys, char* preKeys) {
	//上入力
	if (keys[DIK_W] && preKeys[DIK_W]) {
		pos_.y += Velocity_;
	}
	//下入力
	if (keys[DIK_S]) {
		pos_.y -= Velocity_;
	}
	//右入力
	if (keys[DIK_A]) {
		pos_.x -= Velocity_;
	}
	//左入力
	if (keys[DIK_D]) {
		pos_.x += Velocity_;
	}

	// スペースキーでBulletを発射
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE] && !bullet_->GetIsShot()) {
		// Bulletの位置を設定
		Vector2 bulletPos;
		bulletPos.x = pos_.x;
		bulletPos.y = pos_.y - radius_; // プレイヤーの中心から発射する

		// Bulletの発射状態を設定
		bullet_->SetPosition(bulletPos);
		bullet_->SetIsShot(true);
	}

	// Bulletの更新処理
	bullet_->Update();

}

///描画処理
void Player::DrawUpdate() {
	if (isHit_ == false) {
		Novice::DrawEllipse(static_cast<int>(pos_.x), static_cast<int>(pos_.y) * -1 + 500, static_cast<int>(radius_), static_cast<int>(radius_), 0.0f, 0xAAAAAAFF, kFillModeSolid);
	}

	bullet_->DrawUpdate();
}
