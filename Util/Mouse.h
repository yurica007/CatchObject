#pragma once

#include "Vec2.h"

// �}�E�X�̓��͏�Ԃ��擾����
namespace Mouse
{
	// �}�E�X�̓��͏�Ԏ擾
	void update();

	// ���݂̃}�E�X�ʒu�擾
	Vec2 getPos();

	// ������������
	bool isPressLeft();
	// �g���K�[����
	bool isTriggerLeft();
	// ����������
	bool isRelaseLeft();
}
