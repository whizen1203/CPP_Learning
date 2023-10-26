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
	int         F, G, H;//타일 비용
	Int2        idx;    //타일 인덱스
	Tile*		P; //나를 갱신시킨 타일
	bool        isFind; //검사한적이 있는가?
	int         state;
	Vector2     Pos;

	void ClearCost();         //비용 초기화
	void ClacH(Int2 DestIdx); //H계산해라
	void ClacF(); //F계산해라
};

//별명
//typedef int a;
//a b;
//WORD c;
//typedef 
//               타일주소, 비교값
using PTile = pair<Tile*, int>;

//비교함수
struct compare
{
	//연산자 오버로딩
	bool operator()(PTile& a, PTile& b)
	{
		//오름차순
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

