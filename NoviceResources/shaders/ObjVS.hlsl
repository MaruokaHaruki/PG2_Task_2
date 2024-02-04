#include "Obj.hlsli"

VSOutput main(float4 pos : POSITION, float3 normal : NORMAL, float2 uv : TEXCOORD) {
	// 法線にワールド行列によるスケーリング・回転を適用
	// ※スケーリングが一様な場合のみ正しい
	float4 worldNormal = normalize(mul(float4(normal, 0), world));
	float4 worldPos = mul(pos, world);

	VSOutput output; // ピクセルシェーダーに渡す値
	output.svpos = mul(pos, mul(world, mul(view, projection)));

	output.worldpos = worldPos;
	output.normal = worldNormal.xyz;
	output.uv = uv;

	return output;
}