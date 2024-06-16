//========================================
//
//�^�C�g��[title.cpp]
//Author�F�X��x��
//
//========================================
#include "title.h"
#include "texture.h"
#include "input.h"
#include "fade.h"

//=======================================
//�}�N����`
//=======================================
#define TITLE_TEX	"data\\TEXTURE\\title.png"

//=======================================
//�R���X�g���N�^
//=======================================
CTitle::CTitle(int nPriority)
{
}

//=======================================
//�f�X�g���N�^
//=======================================
CTitle::~CTitle()
{
}

//=======================================
//����
//=======================================
CTitle* CTitle::Create(void)
{
	//�^�C�g���̃|�C���^
	CTitle* pTitle = nullptr;

	//�C���X�^���X����
	pTitle = new CTitle;

	//������
	pTitle->Init();

	//�|�C���^��Ԃ�
	return pTitle;
}

//=======================================
//������
//=======================================
HRESULT CTitle::Init(void)
{
	//�e�N�X�`���̃|�C���^
	CTexture *pTexture = CManager::GetInstance()->GetTexture();

	if (pObj2D == nullptr)
	{
		//CObject2D�̃|�C���^
		pObj2D = CObject2D::Create();

		//�ʒu�擾
		D3DXVECTOR3 pos = pObj2D->GetPos();

		//���_���
		pObj2D->SetSize(SCREEN_WIDTH, SCREEN_HEIGHT);

		//�|���S���̈ʒu
		pos = (D3DXVECTOR3(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f));

		//�ʒu�ݒ�
		pObj2D->SetPos(pos);

		//�e�N�X�`�����蓖��
		pObj2D->BindTexture(pTexture->Regist(TITLE_TEX));
	}

	//������Ԃ�
	return S_OK;
}

//=======================================
//�I��
//=======================================
void CTitle::Uninit(void)
{
}

//=======================================
//�X�V
//=======================================
void CTitle::Update(void)
{
	//CInputKeyboard�^�̃|�C���^
	CInputKeyboard *pInputKeyboard = pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();
	
	//CInputPad�^�̃|�C���^
	CInputPad *pInputPad = pInputPad = CManager::GetInstance()->GetInputPad();
	
	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true || 
		pInputPad->GetTrigger(CInputPad::BUTTON_A, 0) == true ||
		pInputPad->GetTrigger(CInputPad::BUTTON_START, 0) == true)
	{
		// ��ʑJ��(�t�F�[�h)
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TUTORIAL);
	}
}

//=======================================
//�`��
//=======================================
void CTitle::Draw(void)
{
}
