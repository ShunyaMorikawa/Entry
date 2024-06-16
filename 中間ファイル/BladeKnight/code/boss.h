//========================================
//
// �{�X[boss.h]
//Author�F�X��x��
//
//========================================
#ifndef _BOSS_H_
#define _BOSS_H_

#include "main.h"
#include "input.h"
#include "manager.h"
#include "model.h"
#include "motion.h"
#include "enemy.h"

//========================================
// �{�X�N���X
//========================================
class CBoss : public CEnemy
{
public:
	enum BOSSSTATE
	{// �{�X�̏��
		STATE_NONE = 0,		// �ʏ���
		STATE_DEATH,		// ���S���
		STATE_MAX
	};

	CBoss();		// �R���X�g���N�^
	~CBoss();		// �f�X�g���N�^

	// �����o�֐�
	static CBoss *Create();	// �`���[�g���A���G�l�~�[����

	HRESULT Init(void);		// ������
	void Uninit(void);		// �I��
	void Update(void);		// �X�V
	void Draw(void);		// �`��

	void Move(float fSpeed);

	float RotNormalize(float RotN, float Rot);		// rot�̐��K��

	float GetSize(void) { return m_fSize; }		// �T�C�Y�擾

	void SetVertex(void);
	void SetSize(float fWidht, float fHeight);

	int GetLife() { return m_nLife; }	//�̗͎擾

	void CollisionPlayer();

private:
	//�����o�ϐ�

	//�ꊇ�Ǘ�
	LPDIRECT3DTEXTURE9 m_pTexture;	// ���L�e�N�X�`��
	int m_nIdxTexture;				// �e�N�X�`���̔ԍ�
	D3DXMATRIX m_mtxWorld;			// ���[���h�}�g���b�N�X
	LPD3DXMESH m_pMesh;				// ���b�V��(���_���)�ւ̃|�C���^
	LPD3DXBUFFER m_pBuffMat;		// �}�e���A���ւ̃|�C���^
	DWORD m_dwNumMat;				// �}�e���A���̐�

	//�I�u�W�F�N�g
	D3DXVECTOR3 m_pos;		// ����
	D3DXVECTOR3 m_move;		// ����
	D3DXVECTOR3 m_rot;		// ����
	D3DXVECTOR3 m_vtxMin, m_vtxMax;	// ���f���̍ő�A�ŏ��l

	D3DXVECTOR3 m_RotDest;	// �ړI�̌���

	CModel *m_apModel[MAX_PARTS];	//���f���ւ̃|�C���^
	CMotion *m_pMotion;		// ���[�V�����̃|�C���^
	int m_nLife;			// �̗�
	int m_nState;			// �{�X�̏��
	float m_fAngle;			// �ړI�̌���
	float m_fSize;			// �T�C�Y
	bool m_bMove;			// �ړ�
	bool m_bWait;			// �ҋ@
	bool m_bAttack;			// �U��
	bool m_bThrust;			// �˂�
	bool m_bRoundup;		// �؂�グ
};

#endif