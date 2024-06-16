//========================================
//
//���U���g[result.cpp]
//Author�F�X��x��
//
//========================================
#include "renderer.h"
#include "manager.h"
#include "texture.h"
#include "result.h"
#include "object2D.h"
#include "input.h"
#include "fade.h"

//=======================================
//�}�N����`
//=======================================
#define TITLE_TEX	"data\\TEXTURE\\result.png"

//=======================================
//�R���X�g���N�^
//=======================================
CResult::CResult() : 
	m_nCnt(0),
	m_Counter(0),
	m_pObj2D(nullptr)
{
}

//=======================================
//�f�X�g���N�^
//=======================================
CResult::~CResult()
{
}

//=======================================
//����
//=======================================
CResult* CResult::Create(void)
{
	//�^�C�g���̃|�C���^
	CResult* pResult = nullptr;

	//�C���X�^���X����
	pResult = new CResult;

	//������
	pResult->Init();

	//�|�C���^��Ԃ�
	return pResult;
}

//=======================================
//������
//=======================================
HRESULT CResult::Init(void)
{
	//�e�N�X�`���̃|�C���^
	CTexture *pTexture = CManager::GetInstance()->GetTexture();

	if (m_pObj2D == nullptr)
	{
		//CObject2D�̃|�C���^
		m_pObj2D = CObject2D::Create();

		//�ʒu�擾
		D3DXVECTOR3 pos = m_pObj2D->GetPos();

		//���_���
		m_pObj2D->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);

		//�|���S���̈ʒu
		pos = (D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));

		//�ʒu�ݒ�
		m_pObj2D->SetPos(pos);

		//�e�N�X�`�����蓖��
		m_pObj2D->BindTexture(pTexture->Regist("data\\TEXTURE\\result.png"));
	}

	m_Counter = 0;

	//������Ԃ�
	return S_OK;
}

//=======================================
//�I��
//=======================================
void CResult::Uninit(void)
{
	if (m_pObj2D != nullptr)
	{
		m_pObj2D->Uninit();
		m_pObj2D = nullptr;
	}
}

//=======================================
//�X�V
//=======================================
void CResult::Update(void)
{
	//CInputKeyboard�^�̃|�C���^
	CInputKeyboard *pInputKeyboard = nullptr;
	pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	//CInputPad�^�̃|�C���^
	CInputPad *pInputPad = nullptr;
	pInputPad = CManager::GetInstance()->GetInputPad();			//�R���g���[���[�̏��擾

	m_Counter++;

	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true 
		|| pInputPad->GetTrigger(CInputPad::BUTTON_START, 0) == true
		|| pInputPad->GetTrigger(CInputPad::BUTTON_A, 0) == true
		|| m_Counter >= 180)
	{//�Q�[����ʂɑJ��
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TITLE);
	}
}

//=======================================
//�`��
//=======================================
void CResult::Draw(void)
{
}
