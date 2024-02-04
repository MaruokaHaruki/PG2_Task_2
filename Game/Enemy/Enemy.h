#pragma once
#include <Novice.h>
#include "./Game/Object/BaseObject.h"

class Enemy : public BaseObject {
private:
    Enemy* destructor_;

    ///リスポーンタイマー
    int respawnTimer_;
    
public:
    /// コンストラクタ
    Enemy();

    /// デストラクタ
    ~Enemy();

    /// 更新処理
    void Update();

    /// 描画処理
    void DrawUpdate();

    // 位置の取得
    Vector2 GetPosition() const { return pos_; }

    // 半径の取得
    float GetRadius() const { return radius_; }

    // isHit_ のセッター
    void SetIsHit(int value) { isHit_ = value; }

    // isHit_ のゲッター
    int GetIsHit()const { return isHit_; }

};

