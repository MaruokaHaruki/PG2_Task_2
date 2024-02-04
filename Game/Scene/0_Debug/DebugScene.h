#pragma once
#include "./Game/Scene/Base/BaseScene.h"

class DebugScene : public BaseScene {
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	DebugScene(SceneManager& sceneManager);

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~DebugScene();

	/// <summary>
	/// 更新処理
	/// </summary>
	virtual void Update(char* keys, char* preKeys) override;

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void DrawUpdate() override;
};
