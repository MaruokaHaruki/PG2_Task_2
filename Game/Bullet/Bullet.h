#pragma once
#include<Novice.h>
#include "./Game/Object/BaseObject.h"
class Bullet :public BaseObject {
private:

	///発射フラグ
	int isShot_;

	///デストラクタ
	Bullet* destructor_;

public:
	///コンストrクタ
	Bullet();
	///デストラクタ
	~Bullet();

	///更新処置
	void Update();
	///描画処理
	void DrawUpdate();

	// 位置を設定するセッター
	void SetPosition(Vector2 position) { pos_ = position; }

	// 位置の取得
	Vector2 GetPosition() const { return pos_; }

	// 発射状態を見るゲッター
	int GetIsShot()const { return isShot_; }

	// 発射状態を設定するセッター
	void SetIsShot(int shot) { isShot_ = shot; }

	// 半径の設定
	void SetRadius(float radius) { radius_ = radius; }

	// 半径の取得
	float GetRadius() const { return radius_; }

};

