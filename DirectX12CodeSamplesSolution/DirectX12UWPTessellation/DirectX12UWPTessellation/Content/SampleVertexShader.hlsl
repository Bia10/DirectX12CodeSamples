// ����������ɫ�������ÿ����������ݡ�
struct VertexShaderInput
{
	float3 pos : POSITION;
	float3 color : COLOR0;
};

// ͨ��������ɫ�����ݵ�ÿ�����ص���ɫ���ݡ�
struct VertexShaderOutput
{
	//float4 pos : SV_POSITION;
	//float3 color : COLOR0;
	float3 pos : POSITION;
	float3 color : COLOR0;
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
	output.pos = input.pos;
	// �����޸ĵش�����ɫ��
	output.color = input.color;
	return output;
}
