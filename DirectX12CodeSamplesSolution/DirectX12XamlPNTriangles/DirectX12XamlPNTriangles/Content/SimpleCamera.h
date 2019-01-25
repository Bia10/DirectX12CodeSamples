#pragma once
using namespace DirectX;

namespace DirectX12XamlPNTriangles
{

	class SimpleCamera
	{
	public:
		SimpleCamera();
		~SimpleCamera();

	private:
		XMMATRIX  m_view;        // �Ӿ�����		
		XMMATRIX  m_projection;  // ͶӰ����
		bool m_orthogonal;

	public:
		void GetViewMatrix(XMMATRIX  *viewMatrix);
		void GetProjectionMatrix(XMMATRIX  *projectionMatrix);

		// ����������������Ը����Ӿ�����
		void SetViewParameters(
			XMVECTOR eyePosition,    // �����λ��
			XMVECTOR lookPosition,   // ����۲��λ��
			XMVECTOR up              // ���ϵ�����
		);

		// ������׶������Ը���ͶӰ����͸��ͶӰ��
		void SetProjectionParameters(
			float minimumFieldOfView,  // �������Ұ�Ƕ�
			float aspectRatio,         // ͶӰƽ����ݺ��
			float nearPlane,           // ���ü���
			float farPlane             // Զ�ü���
		);
		//����ͶӰ
		void SetOrthographicParameters(
			float viewWidth,   // ͶӰƽ��Ŀ�
			float viewHeight,  // ͶӰƽ��ĸ�  
			float nearPlane,   // ���ü���   
			float farPlane     // Զ�ü���        
		);

	};
}

