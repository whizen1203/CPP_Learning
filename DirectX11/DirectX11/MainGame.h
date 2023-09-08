#pragma once
class MainGame : public Scene
{
private:
	~MainGame();

	ObRect		rc;
	//ObStar		st;
	ObCircle	cc[5];

public:
	//æ¿ √ ±‚»≠
	virtual void Init() override;

	//æ¿ ∞ªΩ≈
	virtual void Update() override;

	//æ¿ √‚∑¬
	virtual void Render() override;
};

