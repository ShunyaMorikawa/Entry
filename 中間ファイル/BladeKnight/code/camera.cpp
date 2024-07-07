//=======================================
//
//�J����[camera.cpp]
//Author : MORIKAWA SHUNYA
//
//=======================================
#include "camera.h"   
#include "renderer.h"
#include "manager.h"
#include "input.h"
#include "debugproc.h"

//=======================================
// �萔��`
//=======================================
namespace
{
	const float CAMERA_SPEED = 1.5f;	// �J�����̈ړ����x
	const float MOVEFAST = 0.2f;		// �J�����̊���
	const float CAMR = 25.0f;			// �����_�̋���
	const float CAMV_MOVE = 0.03f;		// ���_�̈ړ����x
	const float CAM_DISDTANCE = 400.0f;	// �J�����ƃv���C���[�̋���
	const float CAM_R_INERTIA = 0.2f;	// �����_�̊���
	const float CAM_V_INERTIA = 0.2f;	// ���_�̊���
}

//=======================================
//�R���X�g���N�^
//=======================================
CCamera::CCamera()
{
	m_posV = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//���_
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//�����_
	m_vecU = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//������x�N�g��
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//����
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//�ړ���
	m_fDistance = 0.0f;							//����
}

//=======================================
//�f�X�g���N�^
//=======================================
CCamera::~CCamera()
{

}

//=======================================
//�J�����̏���������
//=======================================
HRESULT CCamera::Init(void)
{
	//���_
	m_posV = D3DXVECTOR3(0.0f, 400.0f, -1000.0f);

	//�����_
	m_posR = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//������x�N�g��
	m_vecU = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

	//����
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//�v���C���[�ƃJ�����̋���
	m_fDistance = CAM_DISDTANCE;

	m_posV.x = m_posR.x + cosf(m_rot.y) * m_fDistance;
	m_posV.z = m_posR.z + sinf(m_rot.y) * m_fDistance;

	//������Ԃ�
	return S_OK;
}

//=======================================
//�J�����̏I������
//=======================================
void CCamera::Uninit(void)
{

}

//=======================================
//�J�����̍X�V����
//=======================================
void CCamera::Update(void)
{	
	//CDebugProc�^�|�C���^
	CDebugProc *pDebugProc = CManager::GetInstance()->GetDebugProc();

	//���_�̈ړ�
	CameraMoveV();

#ifdef _DEBUG
	//�f�o�b�O�\��
	pDebugProc->Print("\n���_�̈ʒu�F%f�A%f�A%f\n", m_posV.x, m_posV.y, m_posV.z);
	pDebugProc->Print("�����_�̈ʒu�F%f�A%f�A%f\n", m_posR.x, m_posR.y, m_posR.z);
	pDebugProc->Print("�J�����̌����F%f�A%f�A%f\n", m_rot.x, m_rot.y, m_rot.z);
#endif
}

//=======================================
//�J�����̐ݒ菈��
//=======================================
void CCamera::SetCamera(void)
{
	//CRenderer�^�̃|�C���^
	CRenderer *pRenderer = CManager::GetInstance()->GetRenderer();

	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�v���W�F�N�V�����}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxProjection);

	//�v���W�F�N�V�����}�g���b�N�X���쐬[�������e]
	D3DXMatrixPerspectiveFovLH(&m_mtxProjection,		//�v���W�F�N�V�����}�g���b�N�X
								D3DXToRadian(100.0f),	//����p
								(float)SCREEN_WIDTH / (float)SCREEN_HEIGHT,		//�A�X�y�N�g��
								10.0f,		//Z�l�̍ŏ��l
								400000.0f);	//Z�l�̍ő�l(�`�拗��)

	////�v���W�F�N�V�����}�g���b�N�X��ݒ�[���s���e]
	//D3DXMatrixOrthoLH(&m_mtxProjection,		//�v���W�F�N�V�����}�g���b�N�X
	//					SCREEN_WIDTH,	//��ʂ̕�
	//					SCREEN_HEIGHT,	//��ʂ̍���
	//					10.0f,		//Z�l�̍ŏ��l
	//					1000.0f);	//Z�l�̍ő�l

	//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection);

	//�r���[�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxView);

	//�r���[�}�g���b�N�X�̍쐬
	D3DXMatrixLookAtLH(&m_mtxView,
						&m_posV,	//���_
						&m_posR,	//�����_
						&m_vecU);	//������x�N�g��

	//�r���[�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &m_mtxView);
}

//=======================================
//�J�����̈ړ�
//=======================================
void CCamera::Move(void)
{
	//CInputKeyboard�^�̃|�C���^
	CInputKeyboard *pInputKeyboard = nullptr;
	pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//A�L�[�������ꂽ
	if (pInputKeyboard->GetPress(DIK_A) == true)
	{
		if (pInputKeyboard->GetPress(DIK_W) == true)
		{//����
			m_posV.x += cosf(m_rot.y + (-D3DX_PI * 0.75f)) * CAMERA_SPEED;
			m_posV.z += sinf(m_rot.y + (-D3DX_PI * 0.75f)) * CAMERA_SPEED;

			m_posR.x = m_posV.x - cosf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z - sinf(m_rot.y) * m_fDistance;
		}
		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{//����
			m_posV.x += cosf(m_rot.y + (-D3DX_PI * 0.25f)) * CAMERA_SPEED;
			m_posV.z += sinf(m_rot.y + (-D3DX_PI * 0.25f)) * CAMERA_SPEED;

			m_posR.x = m_posV.x - cosf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z - sinf(m_rot.y) * m_fDistance;
		}
		else
		{//��
			m_posV.x += cosf(m_rot.y + (-D3DX_PI * 0.5f)) * CAMERA_SPEED;
			m_posV.z += sinf(m_rot.y + (-D3DX_PI * 0.5f)) * CAMERA_SPEED;

			m_posR.x = m_posV.x - cosf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z - sinf(m_rot.y) * m_fDistance;
		}
	}
	//D�L�[�������ꂽ
	else if (pInputKeyboard->GetPress(DIK_D) == true)
	{
		if (pInputKeyboard->GetPress(DIK_W) == true)
		{//�E��
			m_posV.x += cosf(m_rot.y + (D3DX_PI * 0.75f)) * CAMERA_SPEED;
			m_posV.z += sinf(m_rot.y + (D3DX_PI * 0.75f)) * CAMERA_SPEED;

			m_posR.x = m_posV.x - cosf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z - sinf(m_rot.y) * m_fDistance;
		}
		else if (pInputKeyboard->GetPress(DIK_S) == true)
		{//�E��
			m_posV.x += cosf(m_rot.y + (D3DX_PI * 0.25f)) * CAMERA_SPEED;
			m_posV.z += sinf(m_rot.y + (D3DX_PI * 0.25f)) * CAMERA_SPEED;

			m_posR.x = m_posV.x - cosf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z - sinf(m_rot.y) * m_fDistance;
		}
		else
		{//�E
			m_posV.x += cosf(m_rot.y + (+D3DX_PI * 0.5f)) * CAMERA_SPEED;
			m_posV.z += sinf(m_rot.y + (+D3DX_PI * 0.5f)) * CAMERA_SPEED;

			m_posR.x = m_posV.x - cosf(m_rot.y) * m_fDistance;
			m_posR.z = m_posV.z - sinf(m_rot.y) * m_fDistance;
		}
	}
	//W�L�[�������ꂽ
	else if (pInputKeyboard->GetPress(DIK_W) == true)
	{
		m_posV.x -= cosf(m_rot.y) * CAMERA_SPEED;
		m_posV.z -= sinf(m_rot.y) * CAMERA_SPEED;

		m_posR.x = m_posV.x - cosf(m_rot.y) * m_fDistance;
		m_posR.z = m_posV.z - sinf(m_rot.y) * m_fDistance;
	}
	//S�L�[�������ꂽ
	else if (pInputKeyboard->GetPress(DIK_S) == true)
	{
		m_posV.x += cosf(m_rot.y) * CAMERA_SPEED;
		m_posV.z += sinf(m_rot.y) * CAMERA_SPEED;

		m_posR.x = m_posV.x - cosf(m_rot.y) * m_fDistance;
		m_posR.z = m_posV.z - sinf(m_rot.y) * m_fDistance;
	}

	//Y�L�[�������ꂽ
	if (pInputKeyboard->GetPress(DIK_Y) == true)
	{
		m_posV.y += CAMERA_SPEED;
		m_posV.z += CAMERA_SPEED;
	}
	//N�L�[�������ꂽ
	else if (pInputKeyboard->GetPress(DIK_N) == true)
	{
		m_posV.y -= CAMERA_SPEED;
		m_posV.z -= CAMERA_SPEED;
	}

	//�ʒu���X�V
	m_posV.x += m_move.x;
	m_posV.y += m_move.y;
	m_posV.z += m_move.z;

	m_posR.x += m_move.x;
	m_posR.y += m_move.y;
	m_posR.z += m_move.z;

	//�ړ��ʂ��X�V(����������)
	m_move.x += (0.0f - m_move.x) * MOVEFAST;
	m_move.y += (0.0f - m_move.y) * MOVEFAST;
	m_move.z += (0.0f - m_move.z) * MOVEFAST;
}

//=======================================
//�����_�̈ړ�
//=======================================
void CCamera::CameraMoveV(void)
{
	// �L�[�{�[�h�̏��擾
	CInputKeyboard *pInputKeyboard = nullptr;
	pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// �R���g���[���[�̏��擾
	CInputPad *pInputPad = nullptr; 
	pInputPad = CManager::GetInstance()->GetInputPad();

	//C�L�[�������ꂽ
	if (pInputKeyboard->GetPress(DIK_C) == true
		|| pInputPad->GetRStickXPress(CInputPad::BUTTON_R_STICK, 0) > 0)
	{
		m_rot.y += CAMV_MOVE;

		//�p�x�̐��K��
		m_rot.y = RotNor(m_rot.y);
	}
	//Z�L�[�������ꂽ
	else if (pInputKeyboard->GetPress(DIK_Z) == true
			 || pInputPad->GetRStickXPress(CInputPad::BUTTON_R_STICK, 0) < 0)
	{
		m_rot.y -= CAMV_MOVE;

		//�p�x�̐��K��
		m_rot.y = RotNor(m_rot.y);
	}

	////Y�L�[�������ꂽ
	//if (pInputKeyboard->GetPress(DIK_Y) == true)
	//{
	//	m_rot.x += CAMV_MOVE;

	//	//�p�x�̐��K��
	//	m_rot.x = RotNor(m_rot.x);

	//	m_posV.y = m_posR.y + cosf(m_rot.x) * m_fDistance;
	//	m_posV.z = m_posR.z + sinf(m_rot.x) * m_fDistance;
	//}
	////N�L�[�������ꂽ
	//else if (pInputKeyboard->GetPress(DIK_N) == true)
	//{
	//	m_rot.x -= CAMV_MOVE;

	//	//�p�x�̐��K��
	//	m_rot.x = RotNor(m_rot.x);

	//	m_posV.y = m_posR.y + cosf(m_rot.x) * m_fDistance;
	//	m_posV.z = m_posR.z + sinf(m_rot.x) * m_fDistance;
	//}

	//�ʒu���X�V
	m_posV.x += m_move.x;
	m_posV.y += m_move.y;
	m_posV.z += m_move.z;

	m_posR.x += m_move.x;
	m_posR.y += m_move.y;
	m_posR.z += m_move.z;

	//�ړ��ʂ��X�V(����������)
	m_move.x += (0.0f - m_move.x) * MOVEFAST;
	m_move.y += (0.0f - m_move.y) * MOVEFAST;
	m_move.z += (0.0f - m_move.z) * MOVEFAST;
}

//=======================================
//rot�̐��K��
//=======================================
float CCamera::RotNor(float RotN)
{
	//3.14�𒴂����Ƃ��ɔ��΂ɂ���
	if (RotN > D3DX_PI)
	{
		RotN -= D3DX_PI * 2;
	}

	//-3.14�𒴂����Ƃ��ɔ��΂ɂ���
	if (RotN < -D3DX_PI)
	{
		RotN += D3DX_PI * 2;
	}
	return RotN;
}

//=======================================
//�J�����Ǐ]
//=======================================
void CCamera::following(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	//�����_
	D3DXVECTOR3 Diff;

	//���_
	D3DXVECTOR3 VDiff;

	//�����_
	m_RDest = D3DXVECTOR3(pos.x + -sinf(rot.y) 
		* CAMR, 
		pos.y, 
		pos.z + -cosf(rot.y) * 25.0f);

	m_VDest.x = m_RDest.x + sinf(m_rot.y) * m_fDistance;
	m_VDest.z = m_RDest.z + cosf(m_rot.y) * m_fDistance;

	//�����_
	Diff = D3DXVECTOR3(m_RDest.x - m_posR.x, 
		0.0f, 
		m_RDest.z - m_posR.z);

	//�����_�̊���
	m_posR += Diff * CAM_R_INERTIA;

	//���_
	VDiff = D3DXVECTOR3(m_VDest.x - m_posV.x, 
		0.0f,
		m_VDest.z - m_posV.z);

	//���_�̊���
	m_posV += VDiff * CAM_V_INERTIA;
}

//=======================================
//�����̎擾
//=======================================
D3DXVECTOR3 CCamera::GetRot(void)
{
	return m_rot;
}

//=======================================
//���_�̎擾
//=======================================
D3DXVECTOR3 CCamera::GetPosV(void)
{
	return m_posV;
}

//=======================================
//�����_�̎擾
//=======================================
D3DXVECTOR3 CCamera::GetPosR(void)
{
	return m_posR;
}
