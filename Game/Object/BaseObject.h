#pragma once
#include "Vector2.h"
class BaseObject{
protected:
	///座標
	Vector2 pos_;
	///速さ
	float Velocity_;
	///加速度
	float acceleration_;
	///半径
	float radius_;
	///当たり判定フラグ
	int isHit_;
};

