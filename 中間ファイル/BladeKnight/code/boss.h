//========================================
//
// ボス[boss.h]
//Author：森川駿弥
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
// ボスクラス
//========================================
class CBoss : public CEnemy
{
public:
	enum BOSSSTATE
	{// ボスの状態
		STATE_NONE = 0,		// 通常状態
		STATE_DEATH,		// 死亡状態
		STATE_MAX
	};

	CBoss();		// コンストラクタ
	~CBoss();		// デストラクタ

	// メンバ関数
	static CBoss *Create();	// チュートリアルエネミー生成

	HRESULT Init(void);		// 初期化
	void Uninit(void);		// 終了
	void Update(void);		// 更新
	void Draw(void);		// 描画

	void Move(float fSpeed);

	float RotNormalize(float RotN, float Rot);		// rotの正規化

	float GetSize(void) { return m_fSize; }		// サイズ取得

	void SetVertex(void);
	void SetSize(float fWidht, float fHeight);

	int GetLife() { return m_nLife; }	//体力取得

	void CollisionPlayer();

private:
	//メンバ変数

	//一括管理
	LPDIRECT3DTEXTURE9 m_pTexture;	// 共有テクスチャ
	int m_nIdxTexture;				// テクスチャの番号
	D3DXMATRIX m_mtxWorld;			// ワールドマトリックス
	LPD3DXMESH m_pMesh;				// メッシュ(頂点情報)へのポインタ
	LPD3DXBUFFER m_pBuffMat;		// マテリアルへのポインタ
	DWORD m_dwNumMat;				// マテリアルの数

	//オブジェクト
	D3DXVECTOR3 m_pos;		// 向き
	D3DXVECTOR3 m_move;		// 向き
	D3DXVECTOR3 m_rot;		// 向き
	D3DXVECTOR3 m_vtxMin, m_vtxMax;	// モデルの最大、最小値

	D3DXVECTOR3 m_RotDest;	// 目的の向き

	CModel *m_apModel[MAX_PARTS];	//モデルへのポインタ
	CMotion *m_pMotion;		// モーションのポインタ
	int m_nLife;			// 体力
	int m_nState;			// ボスの状態
	float m_fAngle;			// 目的の向き
	float m_fSize;			// サイズ
	bool m_bMove;			// 移動
	bool m_bWait;			// 待機
	bool m_bAttack;			// 攻撃
	bool m_bThrust;			// 突き
	bool m_bRoundup;		// 切り上げ
};

#endif