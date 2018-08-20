#pragma once
#include "DXUT.h"

using namespace DirectX;

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
		XMFLOAT3 eyePosition,    // �����λ��
		XMFLOAT3 lookPosition,   // ����۲��λ��
		XMFLOAT3 up              // ���ϵ�����
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

