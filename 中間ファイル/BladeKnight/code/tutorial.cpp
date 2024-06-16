//========================================
//
//�`���[�g���A��[tutorial.h]
//Author�F�X��x��
//
//========================================
#include "tutorial.h"
#include "manager.h"
#include "player.h"
#include "field.h"
#include "bullet.h"
#include "fade.h"
#include "texture.h"

//========================================
//�ÓI�����o�ϐ�
//========================================

//=======================================
//�R���X�g���N�^
//=======================================
CTutorial::CTutorial()
{
}

//=======================================
//�f�X�g���N�^
//=======================================
CTutorial::~CTutorial()
{
}

//=======================================
//����
//=======================================
CTutorial* CTutorial::Create(void)
{
	//�^�C�g���̃|�C���^
	CTutorial* pTutorial = nullptr;

	//�C���X�^���X����
	pTutorial = new CTutorial;

	//�|�C���^��Ԃ�
	return pTutorial;
}

//=======================================
//������
//=======================================
HRESULT CTutorial::Init(void)
{
	//�e�N�X�`���̃|�C���^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	// �v���C���[����
	m_pPlayer = CPlayer::Create("data\\FILE\\player.txt");

	// �t�B�[���h����
	m_pField = CField::Create();

	m_pObj2D = CObject2D::Create();

	// �ʒu�ݒ�
	m_pObj2D->SetPos(D3DXVECTOR3(1000.0f, 200.0f, 0.0f));

	// �T�C�Y�ݒ�
	m_pObj2D->SetSize(300.0f, 350.0f);

	// �e�N�X�`���ݒ�
	m_pObj2D->BindTexture(pTexture->Regist("data\\texture\\guide.png"));

	//������Ԃ�
	return S_OK;
}

//=======================================
//�I��
//=======================================
void CTutorial::Uninit(void)
{
}

//=======================================
//�X�V
//=======================================
void CTutorial::Update(void)
{
	//CInputKeyboard���擾
	CInputKeyboard* pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//CInputPad���擾
	CInputPad* pInputPad = CManager::GetInstance()->GetInputPad();

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true ||
		pInputPad->GetTrigger(CInputPad::BUTTON_START, 0) == true)
	{
		// ��ʑJ��(�t�F�[�h)
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_GAME);
	}
}

//=======================================
//�`��
//=======================================
void CTutorial::Draw(void)
{
}
