#pragma once
#include "./Game/Scene/Base/BaseScene.h"

class TitleScene : public BaseScene {

public:

    /// <summary>
    /// コンストラクタ
    /// </summary>
    TitleScene(SceneManager& sceneManager);

    /// <summary>
    /// デストラクタ
    /// </summary>
    virtual ~TitleScene();

    /// <summary>
    /// 更新処理
    /// </summary>
    virtual void Update(char* keys, char* preKeys) override;

    /// <summary>
    /// 描画処理
    /// </summary>
    virtual void DrawUpdate() override;

};
