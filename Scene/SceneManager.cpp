#include "SceneManager.h"
#include <cassert>
#include "SceneTest.h"
//#include "Pad.h"
#include "Mouse.h"

SceneManager::SceneManager()
{
	m_pScene = nullptr;
}
SceneManager::~SceneManager()
{

}

void SceneManager::init()
{
	m_pScene = new SceneTest;
	m_pScene->init();
}

void SceneManager::end()
{
	assert(m_pScene);
	if (!m_pScene)	return;

	m_pScene->end();
	delete m_pScene;
}

void SceneManager::update()
{
	assert(m_pScene);
	if (!m_pScene)	return;

//	Pad::update();
	Mouse::update();
	SceneBase* pScene = m_pScene->update();
	if (pScene != m_pScene)
	{
		// �O�̃V�[���̏I������
		m_pScene->end();
		delete m_pScene;

		m_pScene = pScene;
		m_pScene->init();
	}
}

void SceneManager::draw()
{
	assert(m_pScene);
	if (!m_pScene)	return;

	m_pScene->draw();
}