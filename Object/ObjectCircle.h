#pragma once

#include "ObjectBase.h"

class SceneTest;

class ObjectCircle : public ObjectBase
{
public:
	ObjectCircle();
	virtual ~ObjectCircle();

	virtual void init() override;
	virtual void end() override;

	virtual void update() override;
	virtual void draw() override;

	void setSceneTest(SceneTest* pSceneTest) { m_pSceneTest = pSceneTest; }

	// �\���ʒu�̐ݒ�
	void setPos(Vec2 pos) { m_pos = pos; }
	// �\���F�̐ݒ�
	void setColor(int color) { m_color = color; }

private:
	SceneTest* m_pSceneTest;
	// �\�����
	int		m_color;
};