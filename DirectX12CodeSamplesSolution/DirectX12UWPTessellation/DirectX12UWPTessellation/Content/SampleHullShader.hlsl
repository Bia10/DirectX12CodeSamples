
//��VertexShader�����
struct HullShaderInput
{
	float3 pos:POSITION;
	float3 color : COLOR0;
};


struct HullShaderOutput
{
	float3 pos:POSITION;
	float3 color : COLOR0;
};

struct ConstantOutputType
{
	float edges[3] : SV_TessFactor;
	float inside : SV_InsideTessFactor;
};

ConstantOutputType ColorPathConstantFunction(InputPatch<HullShaderInput, 3> inputPatch, uint patchId : SV_PrimitiveID)
{
	ConstantOutputType outa;
	//���������������ߵ�����ϸ������
	outa.edges[0] = 15;
	outa.edges[1] = 15;
	outa.edges[2] = 15;
	//�������������������ϸ������
	outa.inside = 15;
	return outa;
}

[domain("tri")]    //������
[partitioning("integer")]  //����
[outputtopology("triangle_cw")]  //˳ʱ��
[outputcontrolpoints(3)]  //�������Ƶ�
[patchconstantfunc("ColorPathConstantFunction")]    // �����������溯����
HullShaderOutput main(InputPatch<HullShaderInput, 3> patch, uint pointId : SV_OutputControlPointID, uint patchId : SV_PrimitiveID)
{
	HullShaderOutput outa;
	outa.pos = patch[pointId].pos;	
	outa.color = patch[pointId].color;
	return outa;
}

