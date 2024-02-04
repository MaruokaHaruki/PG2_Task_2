#pragma once
#include "./Game/Scene/Base/BaseScene.h"
#include "./Game/Player/Player.h"
#include "./Game/Enemy/Enemy.h"
#include "./Game/Collision/CollisionManager.h"

class GamePlayScene :public BaseScene{
private:
    ///自機生成
    Player* player;
    ///敵生成
    Enemy* enemy;
    ///判定
    CollisionManager* collisionManager;
    
public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    GamePlayScene(SceneManager& sceneManager);

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~GamePlayScene();

    /// <summary>
    /// 更新処理
    /// </summary>
    virtual void Update(char* keys, char* preKeys) override;

    /// <summary>
    /// 描画処理
    /// </summary>
    virtual void DrawUpdate() override;

};

