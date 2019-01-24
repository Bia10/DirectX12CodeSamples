// ͨ��������ɫ�����ݵ�ÿ�����ص���ɫ���ݡ�
struct PlanePixelShaderInput
{
	float4 pos : SV_POSITION;
	float3 color : COLOR0;
	float2 uv : TEXCOORD0;
};

Texture2D shaderTexture_plane : register(t0);
SamplerState SampleType_plane : register(s0);

// (�ڲ�)��ɫ���ݵĴ��ݺ�����
//����һ����ũ,��ҵʮ���أ��侤��ҵҵ�����������ɣ���ƣ�ڱ��������������Ѿã�����δ����־������!������Ҳ����������˵����Ϊ��������
float4 main(PlanePixelShaderInput input) : SV_TARGET
{
	//return float4(input.color, 1.0f);
	float4 textureColor;
	textureColor = shaderTexture_plane.Sample(SampleType_plane, input.uv);// *float4(input.color, 1.0f);
	//textureColor =  float4(input.color, 1.0f);
	return textureColor;
}
