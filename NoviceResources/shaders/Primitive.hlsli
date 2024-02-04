#pragma pack_matrix(row_major)

cbuffer ViewProjection : register(b0) {
	matrix view;       // ビュー変換行列
	matrix projection; // プロジェクション変換行列
	float3 cameraPos;  // カメラ座標（ワールド座標）
};

// 頂点シェーダーからピクセルシェーダーへのやり取りに使用する構造体
struct VSOutput {
	float4 svpos : SV_POSITION; // システム用頂点座標
	float4 color : COLOR;       // 色(RGBA)
};
