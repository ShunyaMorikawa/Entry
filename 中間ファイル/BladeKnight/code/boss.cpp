//========================================
//
// �{�X[boss.cpp]
// Author�F�X��x��
//
//========================================
#include "boss.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"
#include "camera.h"
#include "debugproc.h"
#include "motion.h"
#include "model.h"
#include "game.h"
#include "player.h"

//========================================
//�}�N����`
//========================================
#define MOTION_PATH	"data\\FILE\\boss.txt"	//�ǂݍ��ރt�@�C���̃p�X
#define ENEMY_MOVE	(1.0f)

//========================================
// �R���X�g���N�^
//========================================
CBoss::CBoss() :
	m_move(0.0f, 0.0f, 0.0f),		// �ړ���
	m_pos(0.0f, 0.0f, 0.0f),		// �ʒu
	m_rot(0.0f, 0.0f, 0.0f),		// ����
	m_RotDest(0.0f, 0.0f, 0.0f),	// �ړI�̌���
	m_vtxMin(0.0f, 0.0f, 0.0f),		// �ŏ��l
	m_vtxMax(0.0f, 0.0f, 0.0f),		// �ő�l
	m_fAngle(0.0f),					// �ړI�̌���
	m_fSize(0.0f),					// �T�C�Y
	m_nLife(0),						// �̗�
	m_nState(STATE_NONE),			// ���
	m_pMotion(nullptr)
{// �l�N���A
	memset(&m_apModel[0], 0, sizeof(m_apModel));	//���f���̃|�C���^
}

//========================================
// �f�X�g���N�^
//========================================
CBoss::~CBoss()
{
}

//========================================
// ����
//========================================
CBoss *CBoss::Create()
{
	CBoss *pBoss = nullptr;

	if (pBoss == nullptr)
	{
		// �C���X�^���X����
		pBoss = new CBoss;

		// ������
		pBoss->Init();
	}

	return pBoss;
}

//========================================
// ������
//========================================
HRESULT CBoss::Init(void)
{
	// �ړ���
	m_move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// �ʒu
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// ����
	m_rot = D3DXVECTOR3(0.0f, -1.7f, 0.0f);

	// �����̐ݒ�
	m_RotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// �ŏ��l
	m_vtxMin = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// �ő�l
	m_vtxMax = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// �ʒu�ݒ�
	SetPosition(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	// �T�C�Y
	m_fSize = 250.0f;

	// �̗�
	m_nLife = 10;

	// ���
	m_nState = STATE_NONE;

	//���[�V�����̃|�C���^
	m_pMotion = nullptr;

	if (m_pMotion == nullptr)
	{
		//���[�V��������
		m_pMotion = CMotion::Create();

		//���[�V�����ǂݍ���
		m_pMotion->Load("data\\FILE\\boss.txt");

		// �ҋ@
		m_bWait = true;
	}

	return S_OK;
}

//========================================
// �I��
//========================================
void CBoss::Uninit(void)
{
	if (m_pMotion != nullptr)
	{//���[�V�����j��
		m_pMotion->Uninit();
		delete m_pMotion;
		m_pMotion = nullptr;
	}

	//�I�u�W�F�N�g(�������g)�̔j��
	Release();
}

//========================================
// �X�V
//========================================
void CBoss::Update(void)
{
	// �ʒu�擾
	D3DXVECTOR3 posEnemy = Getpos();

	// �ړ��ʎ擾
	D3DXVECTOR3 moveEnemy = GetMove();

	//�ړI�̌���
	D3DXVECTOR3 DiffRot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	// �U��
	m_bAttack = false;

	// �˂�
	m_bThrust = false;

	// �؂�グ
	m_bRoundup = true;

	//�v���C���[�̏��擾
	CPlayer* pPlayer = CGame::GetPlayer();

	if (pPlayer == NULL)
	{
		return;
	}
	// �v���C���[�̈ʒu
	D3DXVECTOR3 posPlayer = pPlayer->GetPosition();

	//�v���C���[�Ƃ̊p�x
	m_fAngle = atan2f(posPlayer.x - posEnemy.x, posPlayer.z - posEnemy.z);

	//�v���C���[�̕����Ɍ�����
	m_rot.y = m_fAngle;

	//�v���C���[�����Ɉړ�
	m_move.x = sinf(m_rot.y) * ENEMY_MOVE;
	m_move.z = cosf(m_rot.y) * ENEMY_MOVE;

	// �ʒu�X�V
	m_pos += m_move;

	//if (m_bAttack)
	//{// �U�����[�V����
	//	m_pMotion->Set(CMotion::MOTIONTYPE_ATTACK);
	//}
	//else if (m_bThrust)
	//{// �˂��U�����[�V����
	//	m_pMotion->Set(CMotion::MOTIONTYPE_THRUST);
	//}
	if (m_bRoundup)
	{// �؂�グ���[�V����
		m_pMotion->Set(CMotion::ENEMY_MOTIONTYPE_ROUNDUP);

		// �v���C���[�Ƃ̓����蔻��
		//CollisionPlayer();
	}
	else
	{// �ҋ@���[�V����
		m_pMotion->Set(CMotion::ENEMY_MOTIONTYPE_WALK);
	}

	if (m_pMotion != nullptr)
	{//���[�V�����X�V
		m_pMotion->Update();
	}

	if (m_nLife <= 0)
	{// �̗͂�0�ȉ�
		// ���S���
		m_nState = STATE_DEATH;
	}

	//�|�C���^
	CDebugProc *pDebugProc = CManager::GetInstance()->GetDebugProc();

	//�f�o�b�O�\��
	pDebugProc->Print("\n�G�̈ʒu�F%f�A%f�A%f\n", posEnemy.x, posEnemy.y, posEnemy.z);
	pDebugProc->Print("�G�̈ړ��ʁF%f�A%f�A%f\n", moveEnemy.x, moveEnemy.y, moveEnemy.z);
	pDebugProc->Print("�G�̌����F%f�A%f�A%f\n", m_rot.x, m_rot.y, m_rot.z);
	pDebugProc->Print("�G�̗̑́F%d\n", m_nLife);
}

//========================================
// �`��
//========================================
void CBoss::Draw(void)
{
	//�`��
	D3DXMATRIX mtxRot, mtxTrans;	//�v�Z�p�}�g���b�N�X

	//CRenderer�^�̃|�C���^
	CRenderer *pRenderer = CManager::GetInstance()->GetRenderer();

	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = pRenderer->GetDevice();

	//�ʒu�擾
	D3DXVECTOR3 pos = Getpos();

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, pos.z);
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);

	//���[�V�����`��
	m_pMotion->Draw();
}

//=======================================
// �G�̈ړ�
//=======================================
void CBoss::Move(float fSpeed)
{
	fSpeed = 0.0f;
}

//=======================================
// rot�̐��K��
//=======================================
float CBoss::RotNormalize(float RotN, float Rot)
{
	//�p�x�̐��K��
	if (RotN > D3DX_PI)
	{//3.14�𒴂����Ƃ��ɔ��΂ɂ���
		RotN -= D3DX_PI * 2;
	}

	//-3.14�𒴂����Ƃ��ɔ��΂ɂ���
	if (RotN < -D3DX_PI)
	{
		RotN += D3DX_PI * 2;
	}

	//Diff�ɕ␳�W����������
	Rot += RotN * 0.1f;

	//�p�x�̐��K��
	if (Rot > D3DX_PI)
	{//3.14�𒴂����Ƃ��ɔ��΂ɂ���
		Rot -= D3DX_PI * 2;
	}

	//-3.14�𒴂����Ƃ��ɔ��΂ɂ���
	if (Rot < -D3DX_PI)
	{
		Rot += D3DX_PI * 2;
	}

	return RotN, Rot;
}

//========================================
// 3D�I�u�W�F�N�g�̐���
//========================================
void CBoss::SetVertex(void)
{
}

//========================================
// 3D�I�u�W�F�N�g�̐���
//========================================
void CBoss::SetSize(float fWidht, float fHeight)
{
	fWidht = 0.0f;
	fHeight = 0.0f;
}

//========================================
// �ʒu�ݒ�
//========================================
void CBoss::SetPosition(D3DXVECTOR3 pos)
{
	pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
}

//========================================
// �v���C���[�Ƃ̓����蔻��
//========================================
void CBoss::CollisionPlayer()
{
	//�ϐ��錾
	float fLength;		//����

	//�v���C���[�̏��擾
	CPlayer *pPlayer = CGame::GetPlayer();

	//�v���C���[�̈ʒu�擾
	D3DXVECTOR3 posPlayer = pPlayer->GetPosition();

	// �v���C���[�̃T�C�Y�擾
	float sizePlayer = pPlayer->GetSize();

	//�x�N�g�������߂�
	D3DXVECTOR3 vec = posPlayer - this->GetPosition();

	//�x�N�g�����
	fLength = D3DXVec3Length(&vec);

	if (fLength <= sizePlayer)
	{

	}
}
