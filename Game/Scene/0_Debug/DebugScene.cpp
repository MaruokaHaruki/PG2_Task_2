#include "DebugScene.h"
#include "./Game/Scene/Manager/SceneManager.h"
#include <Novice.h>

///--------------------------------------------------///
///                    デバック処理                    ///
///--------------------------------------------------///

/// コンストラクタ
DebugScene::DebugScene(SceneManager& sceneManager) : BaseScene(sceneManager) {
}

/// デストラクタ
DebugScene::~DebugScene() {
}
/// end

/// 更新処理
void DebugScene::Update(char* keys, char* preKeys) {
    ///シーン変更
    if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
        sceneManager_.SceneChange(SceneID::TITLE);
    }

    if (keys[DIK_W] && !preKeys[DIK_W]) {
        sceneManager_.SetNowStage(0);
    }

}
/// end

/// 描画処理
void DebugScene::DrawUpdate() {
    Novice::ScreenPrintf(10, 10, "SCENE:DEBUG");
    Novice::ScreenPrintf(10, 30, "STAGE:%d", sceneManager_.GetNowStage());

}
/// end