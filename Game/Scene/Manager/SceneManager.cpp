#include "./Game/Scene/Manager/SceneManager.h"

///↓シーン追加
#include "./Game/Scene/0_Debug/DebugScene.h"
#include "./Game/Scene/1_Title/TitleScene.h"
#include "./Game/Scene/2_GamePlay/GamePlayScene.h"
///end

///シングルトン
SceneManager* SceneManager::GetInstance(){
	static SceneManager instance;
	return &instance;
}

/// <summary>
/// コンストラクタ　
/// </summary>
SceneManager::SceneManager() : nowScene_(new TitleScene(*this)) {
	nowStage_ = 0;
}


/// <summary>
/// デストラクタ
/// </summary>
SceneManager::~SceneManager() {
	// 終了時に最後のシーンを削除
	delete nowScene_;
}


/// <summary>
/// 現在のステージの更新
/// </summary>
/// <param name="NowStage">変更したステージを代入</param>
void SceneManager::SetNowStage(int selectStage) {
	///DELETE:意味がないので消しておく///
	nowStage_ += selectStage + 1;
}


/// <summary>
/// 選択したシーンの処理
/// </summary>
void SceneManager::SceneUpdate(char* keys, char* preKeys) {

	// 通常時は現在のシーンに更新と描画を委譲
	nowScene_->Update(keys, preKeys);
	///RE:更新処理と描画処理をここも分けるか検討///
	nowScene_->DrawUpdate();

}


/// <summary>
/// シーン変更処理
/// </summary>
void SceneManager::SceneChange(SceneID newScene) {

	///ADD:トランジションの処理を追加すること///

	// 新しいシーン
	BaseScene* nextScene = nullptr;

	//シーンのインスタンス生成
	switch (newScene) {
	case SceneID::DEBUG:
		nextScene = new DebugScene(*this);
		break;
	case SceneID::TITLE:
		nextScene = new TitleScene(*this);
		break;
	case SceneID::GAME:
		nextScene = new GamePlayScene(*this);
		break;
	}

	//次シーンが生成されていれば代入を行う
	if (nextScene != nullptr) {
		// 以前のシーンの削除。絶対やれ。nullチェックもするぞ
		if (nowScene_ != nullptr) {
			delete nowScene_;
			nowScene_ = nullptr;
		}

		// 現在のシーンを新しいシーンに切り替え
		if (nowScene_ == nullptr) {
			nowScene_ = nextScene;
		}
	}
}