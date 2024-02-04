#pragma once
#include <Novice.h>
#include "./Game/Object/BaseObject.h"
#include "./Game/Bullet/Bullet.h"

class Player : public BaseObject {
private:
	Player* destructor_;

	Bullet* bullet_;

public:
	/// コンストラクタ
	Player();

	/// デストラクタ
	~Player();

	void Update(char* keys, char* preKeys);

	void DrawUpdate();

	// 位置の取得
	Vector2 GetPosition() const { return pos_; }

	// 半径の取得
	float GetRadius() const { return radius_; }

	// isHit_ のセッター
	void SetIsHit(int value) { isHit_ = value; }

	// isHit_ のゲッター
	int GetIsHit()const { return isHit_; }

	// 弾オブジェクトへのポインタを取得するメソッド
	Bullet* GetBullet() const { return bullet_; }

};

