//========================================
//
//�Q�[��������[game.h]
//Author�F�X��x��
//
//========================================
#ifndef _GAME_H_
#define _GAME_H_
#include "main.h"
#include "manager.h"

//========================================
//�O���錾
//========================================
class CObjectX;
class CObject3D;
class CLight;
class CPlayer;
class CIdxMeshField;
class CField;
class CEnemy;
class CFade;
class CGauge;

//========================================
//�}�N��
//========================================
#define MAX_ITEM	(256)	//�A�C�e���̍ő吔

//========================================
//�Q�[���N���X
//========================================
class CGame : public CScene
{
public:
	CGame();	//�R���X�g���N�^
	~CGame();	//�f�X�g���N�^

	//�����o�֐�
	static CGame *Create(void);

	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void PauseState(bool bPauseState) { m_bPause = bPauseState; }	//�|�[�Y��Ԃ��ǂ���

	void SetPlayer(CPlayer* pPlayer);
	CPlayer *GetPlayer() { return m_pPlayer; }	// �v���C���[�̎擾
	CPlayer **GetPlayerPtr() { return &m_pPlayer; }	// �v���C���[�̎擾
	CEnemy* GetEnemy() { return m_pEnemy; }		// �G�̏��擾
	static CGame *GetInstance(void);		// �Q�[���}�l�[�W���[�̏��
	
private:
	static CGame *m_pGame;				// �Q�[���}�l�[�W���[�̃|�C���^

	int m_nTransition;

	bool m_bPause;				// �|�[�Y��Ԃ�ON/OFF

	CObjectX *m_pObjectX;		// X�t�@�C���I�u�W�F�N�g�̃|�C���^
	CPlayer *m_pPlayer;			// �v���C���[�̃|�C���^
	CIdxMeshField *m_pIdxMesh;	// ���b�V���t�B�[���h�̃|�C���^
	CField *m_pField;			// �|���S���̃|�C���^
	CEnemy* m_pEnemy;			// �G�̃|�C���^
	CFade* m_pFade;				// �t�F�[�h�̃|�C���^
};

#endif