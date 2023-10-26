#pragma once
#define TWODIVROOT3			1.1547005f
#define TWODIVROOT3QUARTER	0.2886751f
#define ROOT3				1.7320510f

class ObIso : public ObTileMap
{
public:
	ObIso();
	~ObIso();

	bool    WorldPosToTileIdx(Vector2 WPos, Int2& TileIdx) override;
	void    ResizeTile(Int2 TileSize) override;
	void    CreateTileCost() override;
};

