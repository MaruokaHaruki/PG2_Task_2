#include "Terrain.hlsli"

VSOutput main(float4 pos : POSITION, float3 normal : NORMAL, float2 uv : TEXCOORD) {
	VSOutput output; // ピクセルシェーダーに渡す値
	output.svpos = mul(pos, mul(world, mul(view, projection)));

	output.normal = normal;
	output.uv = uv;

	return output;
}