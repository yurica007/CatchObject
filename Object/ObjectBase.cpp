#include "ObjectBase.h"

ObjectBase::ObjectBase()
{
	m_pMain = nullptr;
	m_isExist = false;
}

bool ObjectBase::isCol(ObjectBase& target)
{
	// ���݂��Ȃ����͓̂�����Ȃ�
	if (!m_isExist)	return false;
	if (!target.isExist())	return false;
	// None�͉��ɂ��Ԃ���Ȃ�
	if (getColType() == ColType::kNone)	return false;
	if(getTargetColType() == ColType::kNone)	return false;
	// ���g���Ԃ���ΏۈȊO�ɂ͂Ԃ���Ȃ�
	if (getTargetColType() != target.getColType())	return false;

	if (target.getRight() < getLeft())	return false;
	if (target.getLeft() > getRight())	return false;
	if (target.getTop() > getBottom())	return false;
	if (target.getBottom() < getTop())	return false;
	return true;
}