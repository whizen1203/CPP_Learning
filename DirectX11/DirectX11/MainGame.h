#pragma once
class MainGame : public Scene
{
private:
	~MainGame();

	ObRect		rc;
	//ObStar		st;
	ObCircle	cc[5];

public:
	//�� �ʱ�ȭ
	virtual void Init() override;

	//�� ����
	virtual void Update() override;

	//�� ���
	virtual void Render() override;
};

