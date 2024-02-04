#pragma once

/// <summary>
/// シーンID
/// </summary>
enum class SceneID {
    DEBUG,
    PAUSE,
    TITLE,
    SELECT,
    GAME,
    CLEAR
};

class BaseScene;

class SceneManager final{
protected:
private:

    ///シーン管理変数
    BaseScene* nowScene_;

    ///ステージ管理変数
    int nowStage_;

    ///ADD:スコア情報はここで持たせる

public:
    static SceneManager* GetInstance();


private:
    /// コンストラクタ
    SceneManager();

    /// デストラクタ
    ~SceneManager();

public:

    /// ゲッター
    // ステージ管理変数の取得
    int GetNowStage() { return nowStage_; }

    /// セッター
    void SetNowStage(int selectStage);

    /// シーンの更新処理
    void SceneUpdate(char* keys, char* preKeys);

    /// <summary>
    /// シーン変更処理
    /// </summary>
    /// <param name="newSceneID">新しいシーンのID </param>
    /// <param name="">SceneID::DEBUG, TITLE, SELECT, GAME, CLEAR</param>
    void SceneChange(SceneID newSceneID);
};


