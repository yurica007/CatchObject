#pragma once

// �Q�[���V�[�����N���X
class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase() {}


	virtual void init() {}
	virtual void end()	{}

	virtual SceneBase* update() { return this; }
	virtual void draw() {}

	// �t�F�[�h�֘A
	void updateFade();
	void drawFade() const;

	bool isFadingIn() const;	// �t�F�[�h�C����
	bool isFadingOut() const;	// �t�F�[�h�A�E�g��
	bool isFading() const { return isFadingIn() || isFadingOut(); }	// �t�F�[�h�C��or�A�E�g��

	void startFadeOut();	// �t�F�[�h�A�E�g�J�n

private:
	// �t�F�[�h�֘A����
	int m_fadeColor;
	int m_fadeBright;
	int m_fadeSpeed;
};