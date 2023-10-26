#pragma once
#define IMAGESLOT 5

enum TileState
{
	TILE_NONE,
	TILE_WALL,
	TILE_DOOR,
	TILE_TRAP,
	TILE_WATER,
	TILE_SIZE
};

class Tile
{
public:
	int         F, G, H;//Ÿ�� ���
	Int2        idx;    //Ÿ�� �ε���
	Tile*		P; //���� ���Ž�Ų Ÿ��
	bool        isFind; //�˻������� �ִ°�?
	int         state;
	Vector2     Pos;

	void ClearCost();         //��� �ʱ�ȭ
	void ClacH(Int2 DestIdx); //H����ض�
	void ClacF(); //F����ض�
};

//����
//typedef int a;
//a b;
//WORD c;
//typedef 
//               Ÿ���ּ�, �񱳰�
using PTile = pair<Tile*, int>;

//���Լ�
struct compare
{
	//������ �����ε�
	bool operator()(PTile& a, PTile& b)
	{
		//��������
		return a.second > b.second;
	}
};

class ObTileMap : public GameObject
{
protected:
	VertexTile*				vertices;
	ID3D11Buffer*			vertexBuffer;
	Int2					tileSize; // 4x4  10x10
	vector<vector<Tile>>    Tiles;

public:
	ObImage*		tileImages[IMAGESLOT];
	string			file;
public:
	ObTileMap();
	virtual ~ObTileMap();
	virtual void        ResizeTile(Int2 TileSize);
	virtual void        Load();
	virtual bool WorldPosToTileIdx(Vector2 WPos, Int2& TileIdx);
	virtual void        CreateTileCost();

public:
	void                Render() override;
	void                SetTile(Int2 TileIdx, Int2 FrameIdx, int ImgIdx = 0,
		int TileState = TILE_NONE, Color color = Color(0.5f, 0.5f, 0.5f, 0.5f));
	void RenderGui(Int2& GuiPickingIdx, int& ImgIdx);
	void                Save();	
	bool                PathFinding(Int2 sour, Int2 dest, OUT vector<Tile*>& way);
	int                 GetTileState(Int2 TileIdx);
	Int2				GetTileSize() { return tileSize; }
};

