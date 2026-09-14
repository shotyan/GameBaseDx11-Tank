#include "Enemy.h"
#include "Engine\\Model.h"
#include "Engine\\SphereCollider.h"
#include "Ground.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"),hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");
	//モデルハンドル、開始フレーム、終了フレーム、アニメーション速度
	Model::SetAnimFrame(hModel_, 1, 100, 1.0f);
	assert(hModel_ >= 0);//モデルの読み込みに失敗してないか確認
	SphereCollider* collider = new SphereCollider({ 0,0,0 }, 0.5f); //コライダーを作る
	AddCollider(collider); //コライダーをEnemyに追加する
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
