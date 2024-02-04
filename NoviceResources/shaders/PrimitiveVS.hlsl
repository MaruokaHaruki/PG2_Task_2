#include "Primitive.hlsli"

VSOutput main(float4 pos : POSITION, float4 color : COLOR) {
	VSOutput output; // ピクセルシェーダーに渡す値
	output.svpos = mul(pos, mul(view, projection));
	output.color = color;

	return output;
}