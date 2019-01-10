#pragma once

#include <list>
#include <map>  
#include <string>  
using namespace std;

#include "ConstantBufferViewHeapManager.h"

namespace DirectX12XAMLTranslucent
{
	//������Դ������
	class TextureManager 
	{
	private:
		//һ��������Դ
		struct TextureInformationStruct
		{
			Microsoft::WRL::ComPtr<ID3D12Resource> m_texture;			
			Microsoft::WRL::ComPtr<ID3D12Resource> m_pTextureUpload;	
			//����Ķ���������ַ��ƫ����
			int offsetInDescriptors;
		};
		//������Դ��Ŷ���
		map<LPCWSTR, shared_ptr<TextureInformationStruct>> m_textureMap;
		// �����DirectX12�豸ָ�롣	
		Microsoft::WRL::ComPtr<ID3D12Device>			m_pD3dDevice;	
	public:
		TextureManager();
		// ������Դ��������	
		void Initialize(Microsoft::WRL::ComPtr<ID3D12Device> device);
		// �Ӵ��̼���һ������	
		void LoadTexture(ConstantBufferViewHeapManager *cbvHeapManager, LPCWSTR szFile, Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList);	
		//���������ص�GPU�󣬾Ϳ����ͷŵ�����Դ��
		void RemoveUselessContent();
		//������󶨵���Ⱦ��ϵ��
		void BindTexture(ConstantBufferViewHeapManager *cbvHeapManager, LPCWSTR szFile, UINT rootParameterIndex,  Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList> commandList);
	};
}

