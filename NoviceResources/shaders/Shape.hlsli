#pragma pack_matrix(row_major)

cbuffer cbuff0 : register(b0) {
	matrix mat; // ３Ｄ変換行列
};

// 頂点シェーダーからピクセルシェーダーへのやり取りに使用する構造体
struct VSOutput {
	float4 svpos : SV_POSITION; // システム用頂点座標
	float4 color : COLOR;       // 色(RGBA)
};
