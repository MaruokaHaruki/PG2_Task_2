#include "./Game/Scene/1_Title/TitleScene.h"
#include "./Game/Scene/Manager/SceneManager.h"
#include <Novice.h>

///--------------------------------------------------///
///                    タイトル処理                    ///
///--------------------------------------------------///

///コンストラクタ
TitleScene::TitleScene(SceneManager& sceneManager) : BaseScene(sceneManager) {
}

///デストラクタ
TitleScene::~TitleScene() {
}

///更新処理
void TitleScene::Update(char* keys, char* preKeys) {

	///自機
	

	///シーン変更
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		sceneManager_.SceneChange(SceneID::GAME);
	}

}

///描画処理
void TitleScene::DrawUpdate() {
	Novice::ScreenPrintf(10, 10, "SCENE:TITLE");
	Novice::ScreenPrintf(640, 10, "Start Is Press SPACE !");
}
