#include "Mouse.h"
#include "DxLib.h"

namespace
{
	constexpr int kLogNum = 16;
	// ���̓��O	0���ŐV�̏��
	int mouseLog[kLogNum];
}

namespace Mouse
{
	// �}�E�X�̓��͏�Ԏ擾
	void update()
	{
		// ���O�̍X�V
		for (int i = kLogNum - 1; i >= 1; i--)
		{
			mouseLog[i] = mouseLog[i-1];
		}
		// �ŐV�̏��
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			mouseLog[0] = 1;
		}
		else
		{
			mouseLog[0] = 0;
		}
	}

	// ���݂̃}�E�X�ʒu�擾
	Vec2 getPos()
	{
		Vec2 mousePos{ 0,0 };
		int mouseX = 0;
		int mouseY = 0;
		if (GetMousePoint(&mouseX, &mouseY) == -1)
		{
			// �G���[����
			return mousePos;
		}
		mousePos.x = static_cast<float>(mouseX);
		mousePos.y = static_cast<float>(mouseY);
		return mousePos;
	}

	// ������������
	bool isPressLeft()
	{
		return (mouseLog[0]);
	}
	// �g���K�[����
	bool isTriggerLeft()
	{
		bool isNow = (mouseLog[0]);	// ���݂̏��
		bool isLast = (mouseLog[1]);	// �P�t���[���O�̏��
		return (isNow && !isLast);
	}
	// ����������
	bool isRelaseLeft()
	{
		bool isNow = (mouseLog[0]);	// ���݂̏��
		bool isLast = (mouseLog[1]);	// �P�t���[���O�̏��
		return (!isNow && isLast);
	}
}