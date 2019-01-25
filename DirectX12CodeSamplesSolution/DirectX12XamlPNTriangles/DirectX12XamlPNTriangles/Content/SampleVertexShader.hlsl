//// �洢���ڹ��ɼ���ͼ�ε��������������Ⱦ���ĳ�����������
//cbuffer ModelViewProjectionConstantBuffer : register(b0)
//{
//	matrix model;
//	matrix view;
//	matrix projection;
//	float3 lightDir;
//};

// ����������ɫ�������ÿ����������ݡ�
struct VertexShaderInput
{
	float3 pos : POSITION;
	float3 color : COLOR0;
	float2 uv : TEXCOORD0;
	float3 norm: NORMAL;
};

// ͨ��������ɫ�����ݵ�ÿ�����ص���ɫ���ݡ�
struct VertexShaderOutput
{
	float3 pos : POSITION;
	float3 color : COLOR0;
	float2 uv : TEXCOORD0;
	float3 norm: NORMAL;
	//float3 EyeDir : TEXCOORD1;
};

// ������ GPU ��ִ�ж��㴦��ļ���ɫ����
VertexShaderOutput main(VertexShaderInput input)
{
	VertexShaderOutput output;
	//float4 pos = float4(input.pos, 1.0f);

	//// ������λ��ת��ΪͶӰ�ռ䡣
	//pos = mul(pos, model);
	//pos = mul(pos, view);
	//pos = mul(pos, projection);
	//output.pos = pos;

	////// Store the texture coordinates for the pixel shader.
	//output.uv = input.uv;

	//output.normal = normalize(mul(input.norm, (float3x3)model));		
	//float fLighting = saturate(dot(output.normal, lightDir));	
	//output.color.rgb = fLighting ;// saturate(fLighting + input.color);

	//float4 g_CameraPos = float4(0.0f, 0.7f, 1.5f, 0.0f);
	//output.EyeDir = mul(input.pos, (float3x3)model);
	//output.EyeDir = normalize(g_CameraPos.xyz - output.EyeDir);

	//// �����޸ĵش�����ɫ��
	////output.color = input.color;

	// �����޸ĵش�����ɫ��
	output.pos = input.pos;
	output.color = input.color;
	output.uv = input.uv;
	output.norm = input.norm;

	return output;
}
