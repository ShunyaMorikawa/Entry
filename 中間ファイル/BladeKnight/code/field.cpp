//========================================
//
//�V���[�e�B���O�A�N�V����[polygon.cpp]
//Author�F�X��x��
//
//========================================
#include "field.h"
#include "manager.h"
#include "renderer.h"
#include "texture.h"

//========================================
//�}�N����`
//========================================
#define POLYGON_TEX		"data\\texture\\soil.jpg"

//========================================
//�ÓI�����o�ϐ�
//========================================
LPDIRECT3DTEXTURE9 CField::m_pTexture = nullptr;

//========================================
//�R���X�g���N�^
//========================================
CField::CField(int nPriority) :
	CObject3D(nPriority)
{
}

//========================================
//�f�X�g���N�^
//========================================
CField::~CField()
{
}

//========================================
//�|���S������
//========================================
CField *CField::Create(void)
{
	//CPlayer�^�̃|�C���^
	CField *pPolygon = nullptr;

	if (pPolygon == nullptr)
	{
		//�v���C���[����
		pPolygon = new CField;

		//������
		pPolygon->Init();
	}

	//�|�C���^��Ԃ�
	return pPolygon;
}

//========================================
//������
//========================================
HRESULT CField::Init(void)
{
	//�e�N�X�`���̃|�C���^
	CTexture *pTexture = CManager::GetInstance()->GetTexture();

	// �p���̏�����
	CObject3D::Init();

	//�e�N�X�`�����蓖��
	BindTexture(pTexture->Regist(POLYGON_TEX));

	return S_OK;
}

//========================================
//�I��
//========================================
void CField::Uninit(void)
{
}

//========================================
//�X�V
//========================================
void CField::Update(void)
{
}

//========================================
//�`��
//========================================
void CField::Draw(void)
{
	//�`��
	CObject3D::Draw();
}