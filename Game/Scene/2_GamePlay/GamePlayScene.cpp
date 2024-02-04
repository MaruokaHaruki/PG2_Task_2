#include "./Game/Scene/2_GamePlay/GamePlayScene.h"
#include "./Game/Scene/Manager/SceneManager.h"
#include <Novice.h>

///--------------------------------------------------///
///                    ゲームプレイ処理                 ///
///--------------------------------------------------///

/// コンストラクタ
GamePlayScene::GamePlayScene(SceneManager& sceneManager) : BaseScene(sceneManager) {
    player = new Player();
    enemy = new Enemy();
    collisionManager = new CollisionManager(); // コリジョンマネージャーのインスタンスを作成
}

/// デストラクタ
GamePlayScene::~GamePlayScene() {
    delete collisionManager; //解放!
    delete player;//解放!
    delete enemy;//解放!
}

/// 更新処理
void GamePlayScene::Update(char* keys, char* preKeys) {
    if (!player->GetIsHit()) {
        // 自機
        player->Update(keys, preKeys);
    }

    if (player->GetIsHit()) {
        player->GetBullet()->SetIsShot(false);
    }
    // 敵
    enemy->Update();

    if (!enemy->GetIsHit()) {
        // コリジョンマネージャーを起動し、プレイヤーと敵の当たり判定を確認
        collisionManager->CheckPlayerEnemyCollision(*player, *enemy);
    }

    // 敵と弾の当たり判定を確認
    collisionManager->CheckEnemyBulletCollision(*enemy, *player->GetBullet());

    // シーン変更
    if (player->GetIsHit()) {
        if (keys[DIK_R] && !preKeys[DIK_R]) {
            sceneManager_.SceneChange(SceneID::TITLE);
        }
    } else if (enemy->GetIsHit()) {
        if (keys[DIK_R] && !preKeys[DIK_R]) {
            sceneManager_.SceneChange(SceneID::TITLE);
        }
    } 

}

/// 描画処理
void GamePlayScene::DrawUpdate() {
    // 自機
    player->DrawUpdate();
    // 敵
    enemy->DrawUpdate();

    // シーン情報の表示
    Novice::ScreenPrintf(10, 10, "SCENE:GAMEPLAY");

    if (player->GetIsHit()) {
        Novice::ScreenPrintf(640, 10, "Retry Is Press R !");
    } else if (enemy->GetIsHit()) {
        Novice::ScreenPrintf(640, 10, "Return Is Press R !");
    }
}