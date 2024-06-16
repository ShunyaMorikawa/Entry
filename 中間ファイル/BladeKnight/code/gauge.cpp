//========================================
//
//�Q�[�W[gauge.h]
//Author�F�X��x��
//
//========================================
#include "gauge.h"
#include "texture.h"
#include "renderer.h"
#include "manager.h"

//========================================
// ���O���
//========================================
namespace
{
	float LENGTH = 640.0f;		// �Q�[�W�̒���
}

//========================================
// �R���X�g���N�^
//========================================
CGauge::CGauge(int nPriority) : CObject2D(nPriority)
{
	m_nMaxLife = 0;			// �̗͂̍ő�l
	m_nLife = 0;			// ���݂̗̑�
	m_fLength = 0.0f;		// �Ίp���̒���
	m_fAngle = 0.0f;		// �Ίp���̊p�x
	m_aTexU = 0.0f;			// �e�N�X�`����U�l
}

//========================================
// �f�X�g���N�^
//========================================
CGauge::~CGauge()
{
}

//========================================
// ����
//========================================
CGauge* CGauge::Create(int nMaxLife)
{
	CGauge* pGauge = new CGauge;

	// �̗͂̍ő�l
	pGauge->m_nMaxLife = nMaxLife;

	pGauge->Init();

	return pGauge;
}

//========================================
// ������
//========================================
HRESULT CGauge::Init()
{
	//�e�N�X�`���̃|�C���^
	CTexture* pTexture = CManager::GetInstance()->GetTexture();

	D3DXVECTOR3 pos = GetPos();

	// �̗͂̏����l
	m_nLife = m_nMaxLife;

	// �e�N�X�`�����W�̏�����(U�l)
	m_aTexU = 0.0f;

	// �p���N���X�̏�����
	CObject2D::Init();

	// ���_���̐ݒ�
	SetVertex();

	// �ʒu�ݒ�
	CObject2D::SetPos(pos);

	return S_OK;
}

//========================================
// �I��
//========================================
void CGauge::Uninit()
{
	// �p���N���X�̏I��
	CObject2D::Uninit();
}

//========================================
// �X�V
//========================================
void CGauge::Update()
{
	// �p���N���X�̍X�V
	CObject2D::Update();
}

//========================================
// �`��
//========================================
void CGauge::Draw()
{
	// �p���N���X�̕`��
	CObject2D::Draw();
}

//========================================
// �T�C�Y�ݒ�
//========================================
void CGauge::SetSize(float fWidht, float fHeight)
{
	//�Ίp���̒���(���A�c)
	m_fLength = sqrtf(fWidht * fWidht + fHeight * fHeight) * 0.5f;

	//�Ίp���̌���(���A�c)
	m_fAngle = atan2f(fWidht, fHeight);

	//���_���
	SetVertex();
}

//========================================
// ���_���̐ݒ�
//========================================
void CGauge::SetVertex()
{
	CObject2D::SetVertex();

	D3DXVECTOR3 pos = GetPos();
	D3DXVECTOR3 rot = GetRot();
	D3DXCOLOR col = GetCol();

	// ���_���̎擾
	LPDIRECT3DVERTEXBUFFER9 Vertex = GetVtxBuff();

	//���_���ւ̃|�C���^
	VERTEX_2D* pVtx;

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	Vertex->Lock(0, 0, (void**)&pVtx, 0);

	// �̗͂̔䗦
	float ratio = (float)m_nLife / (float)m_nMaxLife;

	pVtx[0].pos = pos + D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = pos + D3DXVECTOR3(LENGTH * ratio, 0.0f, 0.0f);
	pVtx[2].pos = pos + D3DXVECTOR3(0.0f, m_fLength, 0.0f);
	pVtx[3].pos = pos + D3DXVECTOR3(LENGTH * ratio, m_fLength, 0.0f);

	//���_�J���[�̐ݒ�
	pVtx[0].col = col;
	pVtx[1].col = col;
	pVtx[2].col = col;
	pVtx[3].col = col;

	//�e�N�X�`�����W�̍X�V(U�l)
	m_aTexU += 0.002f;

	pVtx[0].tex = D3DXVECTOR2(m_aTexU, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(m_aTexU + ratio, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(m_aTexU, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(m_aTexU + ratio, 1.0f);

	//���_�o�b�t�@���A�����b�N
	Vertex->Unlock();

	SetPos(pos);
	SetRot(rot);
}
