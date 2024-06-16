//========================================
//
//�Q�[��������[game.cpp]
//Author�F�X��x��
//
//========================================
#include "game.h"
#include "manager.h"
#include "camera.h"
#include "input.h"
#include "player.h"
#include "field.h"
#include "bullet.h"
#include "enemy.h"
#include "fade.h"

//========================================
//�ÓI�����o�ϐ�
//========================================
CGame *CGame::m_pGame = nullptr;			// �Q�[���̃|�C���^

//========================================
// ���O���
//========================================
namespace
{
	const int TransitionTime = 120;
}

//========================================
//�R���X�g���N�^
//========================================
CGame::CGame() : 
	m_bPause(false),
	m_nTransition(0)
{
}

//========================================
//�f�X�g���N�^
//========================================
CGame::~CGame()
{
}

//========================================
//����
//========================================
CGame *CGame::Create(void)
{
	if (m_pGame == nullptr)
	{
		//�C���X�^���X����
		m_pGame = new CGame;
	}

	//�|�C���^��Ԃ�
	return m_pGame;
}

//========================================
//������
//========================================
HRESULT CGame::Init(void)
{
	// �v���C���[����
	m_pPlayer = CPlayer::Create("data//FILE//player.txt");

	// �t�B�[���h����
	m_pField = CField::Create();

	// �G�l�~�[����
	m_pEnemy = CEnemy::Create("data//FILE//motion.txt");

	// �J�ڎ���
	m_nTransition = 0;

	//�|�[�Y�̏��
	m_bPause = false;

	return S_OK;
}

//========================================
//�I��
//========================================
void CGame::Uninit(void)
{
	m_pGame = nullptr;
}

//========================================
//�X�V
//========================================
void CGame::Update(void)
{
	// CInputKeyboard�^�̃|�C���^
	CInputKeyboard* pInputKeyboard = nullptr;
	pInputKeyboard = CManager::GetInstance()->GetInputKeyboard();

	// �G�̗͎̑擾
	int EnemyLife = m_pEnemy->GetLife();

	if (EnemyLife <= 0 || m_pPlayer == nullptr)
	{// �G���v���C���[�̗̑͂�0�ȉ��ɂȂ�����
		m_nTransition++;

		if (m_nTransition >= TransitionTime)
		{
			// ��ʑJ��(�t�F�[�h)
			CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TITLE);

			m_nTransition = 0;
		}
	}

#ifdef _DEBUG
	if (pInputKeyboard->GetTrigger(DIK_RETURN) == true)
	{// �Q�[����ʂɑJ��
		CManager::GetInstance()->GetFade()->SetFade(CScene::MODE_TITLE);
	}
#endif
}

//========================================
//�`��
//========================================
void CGame::Draw(void)
{
}

//========================================
//�ݒ�
//========================================
void CGame::SetPlayer(CPlayer* pPlayer)
{
	m_pPlayer = pPlayer;
}

//========================================
// �V���O���g��
//========================================
CGame *CGame::GetInstance(void)
{
	if (m_pGame == nullptr)
	{//�C���X�^���X����

		return m_pGame = new CGame;
	}
	else
	{//�|�C���^��Ԃ�
		return m_pGame;
	}
}
