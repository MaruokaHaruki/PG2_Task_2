#pragma once
#include <Novice.h>
///シーン管理クラス
class SceneManager;
///基本シーンクラス
class BaseScene
{
protected:
	SceneManager& sceneManager_;
public:

	///コンストラクタ
	BaseScene(SceneManager& sceneManager);

	///デストラクタ
	virtual ~BaseScene();

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update(char* keys, char* preKeys) = 0;

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void DrawUpdate() = 0;


};
