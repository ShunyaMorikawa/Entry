//========================================
//
//�v���C���[����[player.h]
//Author�F�X��x��
//
//========================================
#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "character.h"

class CModel;
class CMotion;
class CEffect;
class CGauge;

//========================================
//�v���C���[�N���X
//========================================
class CPlayer : public CCharacter
{
public:
	CPlayer(int nPriority = 4);		//�R���X�g���N�^
	~CPlayer();		//�f�X�g���N�^

	// �����o�֐�
	HRESULT Init() { return S_OK; }		//�������z
	HRESULT Init(std::string pfile);
	void Uninit();
	void Update();
	void Draw();
	void Act(float fSpeed);
	void Attack();
	void Motion();
	void CollisionEnemy(int nDamage);
	void NockBack();
	void Hit(int nLife);

	float GetRadius() { return m_fRadius; }		// ���a�擾

	int GetLife() { return m_nLife; }

	static CPlayer *Create(std::string pfile);

private:
	//�����o�ϐ�

	int m_apNumModel;		// ���f��(�p�[�c)�̑���
	int m_nLife;			// �̗�
	int m_nOldMotion;		// �O��̃��[�V����

	float m_fRadius;		// ���a

	bool m_bJump;			//�W�����v
	bool m_bMove;			//�ړ�
	bool m_bWait;			//�ҋ@
	bool m_bMowingdown;		// �U��
	bool m_bCutdown;		// �؂艺�낵
	bool m_bStrongAttack;	// ���U��

	CEffect *m_pEffect;				// �G�t�F�N�g�̃|�C���^
	CModel *m_apModel[MAX_PARTS];	// ���f���̃_�u���|�C���^
	CGauge* m_pGauge;				// �Q�[�W�̃|�C���^
};

#endif
