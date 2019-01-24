#pragma once
#include "ShaderStructures.h"
#include "ConstantBufferViewHeapManager.h"
namespace DirectX12XAMLAlphaBlend
{
	//������ɫ��������
	class ConstantPixelShaderBufferInformation
	{
	private:
		//��������ָ��
		Microsoft::WRL::ComPtr<ID3D12Resource>				m_constantPSBuffer;
		//������������ݽṹ
		ConstantPSBuffer									m_constantPSBufferData;
		//���������ӳ��ָ��
		UINT8*												m_mappedConstantPSBuffer;
		//�˳�����������Ӧ����������ƫ����
		int offsetInDescriptors;

		float m_x=-1;

	public:
		ConstantPixelShaderBufferInformation();
		//������ӳ�䳣��������ͼ
		void PixelConstantBuffer(ConstantBufferViewHeapManager *cbvHeapManager, Microsoft::WRL::ComPtr<ID3D12Device>	pD3dDevice, const UINT alignedConstantPSBufferSize);
		//ȡ��ӳ����ͷ���Դ
		void ClearConstantBuffer();
		//��������������Ӧ���������󶨵���Ⱦ��ϵ
		void BindPSConstantBuffer(ConstantBufferViewHeapManager *cbvHeapManager, Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> pCommandList, UINT rootParameterIndex);
		//���ó���������Ϣ
		void Update();
		void  HandleXChanged(float x) { m_x = x; }
	};

}