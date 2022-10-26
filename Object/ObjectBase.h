#pragma once

#include "Vec2.h"

class SceneMain;

// ��`�����蔻������Q�[���I�u�W�F�N�g���N���X
class ObjectBase
{
public:
	// ���̂̕���
	enum class ColType
	{
		kNone,
		kPlayer,
		kEnemy,
		kPlayerShot,
		kEnemyShot,
	};

public:
	ObjectBase();
	virtual ~ObjectBase() {}

	virtual void init() = 0;
	virtual void end() = 0;

	virtual void update() = 0;
	virtual void draw() = 0;

	void setMain(SceneMain* pMain) { m_pMain = pMain; }

	void setExist(bool isExist) { m_isExist = isExist; }
	bool isExist() const { return m_isExist; }

	// ���̕��̂Ƃ̓����蔻��
	bool isCol(ObjectBase& target);

	// �Ԃ������Ƃ��̂Ԃ��鑤�̏���	�e���G�̏ꍇ�̒e
	virtual void hit() {};
	// �Ԃ������Ƃ��̂Ԃ����鑤�̏���	�e���G�̏ꍇ�̓G
	virtual void beHit() {};

	// ���擾
	Vec2 getPos() const { return m_pos; }
	Vec2 getColSize() const { return m_colSize; }

	// �����蔻��Ɏg�p������
	virtual float getLeft() const { return m_pos.x; }
	virtual float getRight() const { return m_pos.x + m_colSize.x; }
	virtual float getTop() const { return m_pos.y; }
	virtual float getBottom() const { return m_pos.y + m_colSize.y; }
	// ���g�̓����蔻����
	virtual ColType getColType() const { return ColType::kNone; }
	// ���g�����ɂԂ��邩	�����̒e���G�ɂԂ���
	virtual ColType getTargetColType() const { return ColType::kNone; }

protected:
	SceneMain* m_pMain;

	// ���݂��邩
	bool m_isExist;

	// ������W
	Vec2	m_pos;
	// �����蔻��T�C�Y(��`)
	Vec2	m_colSize;
};