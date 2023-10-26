#include "framework.h"

ObTileMap::ObTileMap()
{
    SafeRelease(vertexBuffer);
    SafeDeleteArray(vertices);
    for (int i = 0; i < IMAGESLOT; i++)
        SafeDelete(tileImages[i]);

    tileSize.x = 20;
    tileSize.y = 20;
    scale = Vector2(50.0f, 50.0f); //�� Ÿ��ũ��

    //IMAGESLOT ���� �� �ʱ�ȭ �ʼ�!
    tileImages[0] = new ObImage(L"Tile.png");
    tileImages[0]->maxFrame = Int2(8, 6);
    tileImages[1] = new ObImage(L"Tile2.png");
    tileImages[1]->maxFrame = Int2(11, 7);
    tileImages[2] = nullptr;
    tileImages[3] = nullptr;
    tileImages[4] = nullptr;

    file = "map1.txt";

    ResizeTile(tileSize);
}

ObTileMap::~ObTileMap()
{
    SafeRelease(vertexBuffer);
    SafeDeleteArray(vertices);

    for (int i = 0; i < IMAGESLOT; i++)
        SafeDelete(tileImages[i]);
}

//���� ��� �Լ�
void ObTileMap::ResizeTile(Int2 TileSize)
{
    VertexTile* Vertices = new VertexTile[TileSize.x * TileSize.y * 6];

    //Init ����
    for (int i = 0; i < TileSize.y; i++)
    {
        //����
        for (int j = 0; j < TileSize.x; j++)
        {
            //y * size + x
            int tileIdx = TileSize.x * i + j;
            //Ÿ����ǥ ( tileSize.x * y��ǥ + x��ǥ)
            //���� ��ǥ ( tileSize.x * y��ǥ + x��ǥ) * 6

            //0
            Vertices[tileIdx * 6].position.x = 0.0f + j;
            Vertices[tileIdx * 6].position.y = 0.0f + i;
            Vertices[tileIdx * 6].uv = Vector2(0.0f, 1.0f);
            //1                             
            Vertices[tileIdx * 6 + 1].position.x = 0.0f + j;
            Vertices[tileIdx * 6 + 1].position.y = 1.0f + i;
            Vertices[tileIdx * 6 + 1].uv = Vector2(0.0f, 0.0f);
            //2                             
            Vertices[tileIdx * 6 + 2].position.x = 1.0f + j;
            Vertices[tileIdx * 6 + 2].position.y = 0.0f + i;
            Vertices[tileIdx * 6 + 2].uv = Vector2(1.0f, 1.0f);
            //3
            Vertices[tileIdx * 6 + 3].position.x = 1.0f + j;
            Vertices[tileIdx * 6 + 3].position.y = 1.0f + i;
            Vertices[tileIdx * 6 + 3].uv = Vector2(1.0f, 0.0f);
            //4
            Vertices[tileIdx * 6 + 4].position.x = 1.0f + j;
            Vertices[tileIdx * 6 + 4].position.y = 0.0f + i;
            Vertices[tileIdx * 6 + 4].uv = Vector2(1.0f, 1.0f);
            //5
            Vertices[tileIdx * 6 + 5].position.x = 0.0f + j;
            Vertices[tileIdx * 6 + 5].position.y = 1.0f + i;
            Vertices[tileIdx * 6 + 5].uv = Vector2(0.0f, 0.0f);
        }
    }

    //Copy
    if (vertices)
    {
        Int2 Min = Int2(min(TileSize.x, tileSize.x), min(TileSize.y, tileSize.y));

        for (int i = 0; i < Min.y; i++)
        {
            for (int j = 0; j < Min.x; j++)
            {
                int SrcIdx = tileSize.x * i + j;
                int DestIdx = TileSize.x * i + j;
                for (int k = 0; k < 6; k++)
                {
                    Vertices[DestIdx * 6 + k] = vertices[SrcIdx * 6 + k];
                }
            }
        }
    }

    SafeDeleteArray(vertices);
    vertices = Vertices;
    tileSize = TileSize;
    SafeRelease(vertexBuffer);
    //CreateVertexBuffer
    {
        D3D11_BUFFER_DESC desc;
        desc = { 0 };
        desc.Usage = D3D11_USAGE_DEFAULT;
        desc.ByteWidth = sizeof(VertexTile) * tileSize.x * tileSize.y * 6;
        desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
        D3D11_SUBRESOURCE_DATA data = { 0 };
        data.pSysMem = vertices;
        HRESULT hr = D3D->GetDevice()->CreateBuffer(&desc, &data, &vertexBuffer);
        Check(hr);
    }
}

void ObTileMap::Render()
{
    if (!isVisible)return;
    GameObject::Render();

    for (int i = 0; i < IMAGESLOT; i++)
    {
        if (tileImages[i]) //�ּҰ� �մٸ�
        {
            //SRV ���� �ȵ� obimage ���� ģ�� �Կ��ֱ�
            D3D->GetDC()->PSSetShaderResources(i, 1, &tileImages[i]->SRV);
            D3D->GetDC()->PSSetSamplers(i, 1, &tileImages[i]->sampler);
        }
    }
    tileMapShader->Set();

    UINT stride = sizeof(VertexTile);
    UINT offset = 0;

    //���ؽ����� ���ε�
    D3D->GetDC()->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
    D3D->GetDC()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    D3D->GetDC()->Draw(tileSize.x * tileSize.y * 6, 0);
}

//uv �ڸ��� �Լ�
void ObTileMap::SetTile(Int2 TileIdx, Int2 FrameIdx, int ImgIdx, int TileState, Color color)
{
    int tileIdx = tileSize.x * TileIdx.y + TileIdx.x;

    //0 1 5 UV.x �� �ּҰ�
    vertices[tileIdx * 6 + 0].uv.x = FrameIdx.x / (float)tileImages[ImgIdx]->maxFrame.x;
    vertices[tileIdx * 6 + 1].uv.x = FrameIdx.x / (float)tileImages[ImgIdx]->maxFrame.x;
    vertices[tileIdx * 6 + 5].uv.x = FrameIdx.x / (float)tileImages[ImgIdx]->maxFrame.x;

    //2 3 4 UV.x �ִ�
    vertices[tileIdx * 6 + 2].uv.x = (FrameIdx.x + 1.0f) / (float)tileImages[ImgIdx]->maxFrame.x;
    vertices[tileIdx * 6 + 3].uv.x = (FrameIdx.x + 1.0f) / (float)tileImages[ImgIdx]->maxFrame.x;
    vertices[tileIdx * 6 + 4].uv.x = (FrameIdx.x + 1.0f) / (float)tileImages[ImgIdx]->maxFrame.x;

    //UV.y �ּ�
    vertices[tileIdx * 6 + 3].uv.y = FrameIdx.y / (float)tileImages[ImgIdx]->maxFrame.y;
    vertices[tileIdx * 6 + 1].uv.y = FrameIdx.y / (float)tileImages[ImgIdx]->maxFrame.y;
    vertices[tileIdx * 6 + 5].uv.y = FrameIdx.y / (float)tileImages[ImgIdx]->maxFrame.y;

    //UV.y �ִ�
    vertices[tileIdx * 6 + 2].uv.y = (FrameIdx.y + 1.0f) / (float)tileImages[ImgIdx]->maxFrame.y;
    vertices[tileIdx * 6 + 0].uv.y = (FrameIdx.y + 1.0f) / (float)tileImages[ImgIdx]->maxFrame.y;
    vertices[tileIdx * 6 + 4].uv.y = (FrameIdx.y + 1.0f) / (float)tileImages[ImgIdx]->maxFrame.y;

    //�̹��� ������ �ٲ� ���
    for (int i = 0; i < 6; i++)
    {
        vertices[tileIdx * 6 + i].tileMapIdx = ImgIdx;
        vertices[tileIdx * 6 + i].color = color;
        vertices[tileIdx * 6 + i].tileState = TileState;
    }

    D3D->GetDC()->UpdateSubresource(vertexBuffer, 0, NULL, vertices, 0, 0);
}

void ObTileMap::RenderGui(Int2& GuiPickingIdx, int& ImgIdx)
{
    if (ImGui::InputInt("ImgIdx", &ImgIdx))
    {
        ImgIdx = Utility::Saturate(ImgIdx, 0, IMAGESLOT - 1);

        if (not tileImages[ImgIdx])
        {
            ImgIdx = 0;
        }
    }

    Int2 MF = tileImages[ImgIdx]->maxFrame;
    ImVec2 size;

    size.x = 300.0f / (float)MF.x;
    size.y = 300.0f / (float)MF.y;

    //�ؽ��� ��ǥ
    ImVec2 LT, RB;
    int index = 0;
    for (UINT i = 0; i < MF.y; i++)
    {
        for (UINT j = 0; j < MF.x; j++)
        {
            if (j != 0)
            {
                //�����ٿ� ��ġ
                ImGui::SameLine();
            }

            //�ؽ��� ��ǥ
            LT.x = 1.0f / MF.x * j;
            LT.y = 1.0f / MF.y * i;
            RB.x = 1.0f / MF.x * (j + 1);
            RB.y = 1.0f / MF.y * (i + 1);

            ImGui::PushID(index);
            if (ImGui::ImageButton((void*)tileImages[ImgIdx]->SRV, size, LT, RB))
            {
                GuiPickingIdx.x = j;
                GuiPickingIdx.y = i;
            }
            index++;
            ImGui::PopID();
        }
    }
}

bool ObTileMap::WorldPosToTileIdx(Vector2 WPos, Int2& TileIdx)
{
    WPos -= GetWorldPos();

    Vector2 tileCoord;
    tileCoord.x = WPos.x / scale.x;
    tileCoord.y = WPos.y / scale.y;

    if ((tileCoord.x < 0) or (tileCoord.y < 0) or
        (tileCoord.x >= tileSize.x) or (tileCoord.y >= tileSize.y))
    {
        return false;
    }

    TileIdx.x = tileCoord.x;
    TileIdx.y = tileCoord.y;

    return true;
}

void ObTileMap::Save()
{
    ofstream fout;
    string path = "../Contents/TileMap/" + file;
    //ios::out ���� ������ ���ٴ�
    fout.open(path.c_str(), ios::out);

    //������
    if (fout.is_open())
    {
        for (int i = 0; i < IMAGESLOT; i++)
        {
            fout << i << " ";
            if (tileImages[i])
            {
                string imgFile = "";
                imgFile.assign(tileImages[i]->file.begin(), tileImages[i]->file.end());

                fout << imgFile << " ";
                fout << tileImages[i]->maxFrame.x << " " << tileImages[i]->maxFrame.y << endl;
            }
            else
            {
                fout << "N" << endl;
            }
        }

        fout << "TileSize " << tileSize.x << " " << tileSize.y << endl;
        fout << "TileScale " << scale.x << " " << scale.y << endl;
        fout << "TilePosition " << GetWorldPos().x << " " << GetWorldPos().y << endl;

        for (int i = 0; i < tileSize.y; i++)
        {
            //����
            for (int j = 0; j < tileSize.x; j++)
            {
                int tileIdx = tileSize.x * i + j;
                fout << j << " " << i << " "
                    << vertices[tileIdx * 6 + 1].uv.x << " " << vertices[tileIdx * 6 + 1].uv.y << " "
                    << vertices[tileIdx * 6 + 2].uv.x << " " << vertices[tileIdx * 6 + 2].uv.y << " "
                    << vertices[tileIdx * 6].color.x << " " << vertices[tileIdx * 6].color.y << " "
                    << vertices[tileIdx * 6].color.z << " " << vertices[tileIdx * 6].color.w << " "
                    << vertices[tileIdx * 6].tileMapIdx << " " << vertices[tileIdx * 6].tileState << endl;
            }
        }

        fout.close();
    }
}

void ObTileMap::Load()
{
    ifstream fin;
    string path = "../Contents/TileMap/" + file;
    fin.open(path.c_str(), ios::in);
    string temp;

    if (fin.is_open())
    {
        for (int i = 0; i < IMAGESLOT; i++)
        {
            SafeDelete(tileImages[i]);

            int idx; string Imgfile;
            fin >> idx;
            fin >> Imgfile;

            if (Imgfile != "N")
            {
                wstring wImgFile = L"";
                wImgFile.assign(Imgfile.begin(), Imgfile.end());
                tileImages[i] = new ObImage(wImgFile);
                fin >> tileImages[i]->maxFrame.x >> tileImages[i]->maxFrame.y;
            }
        }

        Int2 TileSize;
        fin >> temp >> TileSize.x >> TileSize.y;

        ResizeTile(TileSize);

        fin >> temp >> scale.x >> scale.y;

        Vector2 pos;
        fin >> temp >> pos.x >> pos.y;
        SetWorldPos(pos);

        for (int i = 0; i < tileSize.y; i++)
        {
            //����
            for (int j = 0; j < tileSize.x; j++)
            {
                int temp; Vector2 MinUV, MaxUV; Color color; float tileMapIdx, tileMapState;

                fin >> temp >> temp >> MinUV.x >> MinUV.y >> MaxUV.x >> MaxUV.y
                    >> color.x >> color.y >> color.z >> color.w >> tileMapIdx >> tileMapState;

                int tileIdx = tileSize.x * i + j;

                vertices[tileIdx * 6].uv = Vector2(MinUV.x, MaxUV.y);
                vertices[tileIdx * 6 + 1].uv = Vector2(MinUV.x, MinUV.y);
                vertices[tileIdx * 6 + 2].uv = Vector2(MaxUV.x, MaxUV.y);
                vertices[tileIdx * 6 + 3].uv = Vector2(MaxUV.x, MinUV.y);
                vertices[tileIdx * 6 + 4].uv = Vector2(MaxUV.x, MaxUV.y);
                vertices[tileIdx * 6 + 5].uv = Vector2(MinUV.x, MinUV.y);

                for (int k = 0; k < 6; k++)
                {
                    vertices[tileIdx * 6 + k].color = color;
                    vertices[tileIdx * 6 + k].tileMapIdx = tileMapIdx;
                    vertices[tileIdx * 6 + k].tileState = tileMapState;
                }
            }
        }
        D3D->GetDC()->UpdateSubresource(vertexBuffer, 0, NULL, vertices, 0, 0);

        fin.close();
    }
}

bool ObTileMap::PathFinding(Int2 sour, Int2 dest, OUT vector<Tile*>& way)
{
    //���߿� �ϳ��� ���̸� �� �� �ִ±��� ����.
    if (Tiles[dest.x][dest.y].state == TILE_WALL ||
        Tiles[sour.x][sour.y].state == TILE_WALL)
    {
        return false;
    }

    //������ �ִ� ���� ���� ����.
    way.clear();

    //����� ������ ������
    if (sour == dest)
    {
        return false;
    }

    //Ÿ�� ��� �ʱ�ȭ
    for (int i = 0; i < tileSize.x; i++)
    {
        for (int j = 0; j < tileSize.y; j++)
        {
            Tiles[i][j].ClearCost();
        }
    }

    //             ����Ÿ��, �����̳�Ÿ��, ���Լ�
    priority_queue<PTile, vector<PTile>, compare> List;

    //����Ʈ�� ������� �߰�
    Tile* pTemp = &Tiles[sour.x][sour.y];
    pTemp->G = 0; //����� �������� 0
    pTemp->ClacH(dest);//���������� ������ �����
    pTemp->ClacF(); //�ѿ����� �����

    //          �ּ� , �� ������
    List.push({ pTemp ,pTemp->F });

    //���������� ����� ���涧 ���� �ݺ�
    while (1)
    {
        //�����ߵ� F���� ���̻� ������
        if (List.empty())
        {
            return false;
        }

        //Ž����� �޾ƿ���
        PTile Temp = List.top();

        //Ž����Ͽ��� ����
        Temp.first->isFind = true;

        //������ ��������
        List.pop();

        //�������� �������̸� ����(��ã�� ��������)
        if (Temp.first->idx == dest)
        {
            break;
        }

        //���� Ÿ�� ���˻�
        vector<Int2> LoopIdx;

        //����Ÿ���� �����Ҷ�
        if (Temp.first->idx.x > 0)
        {
            LoopIdx.push_back(Int2(Temp.first->idx.x - 1,
                Temp.first->idx.y));
        }
        //�Ʒ���Ÿ���� �����Ҷ�
        if (Temp.first->idx.y > 0)
        {
            LoopIdx.push_back(Int2(Temp.first->idx.x,
                Temp.first->idx.y - 1));
        }

        //������Ÿ���� �����Ҷ�
        if (Temp.first->idx.x < tileSize.x - 1)
        {
            LoopIdx.push_back(Int2(Temp.first->idx.x + 1,
                Temp.first->idx.y));
        }

        //����Ÿ���� �����Ҷ�
        if (Temp.first->idx.y < tileSize.y - 1)
        {
            LoopIdx.push_back(Int2(Temp.first->idx.x,
                Temp.first->idx.y + 1));
        }

        //�����¿�Ÿ�� ���˻�
        for (int i = 0; i < LoopIdx.size(); i++) //LoopIdx.size() 4��
        {
            Tile* loop = &Tiles[LoopIdx[i].x][LoopIdx[i].y];

            //���� �ƴҶ�
            if (loop->state != TILE_WALL)
            {
                //������ �����
                loop->ClacH(dest);

                //���� �������ִ� ����� Ŭ��
                if (loop->G > Temp.first->G + 10)
                {
                    //��밻��
                    loop->G = Temp.first->G + 10;
                    loop->ClacF();

                    //�����κ��� �������� ǥ��
                    loop->P = Temp.first;

                    //�� Ÿ���� ã���� ���� Ÿ���̸� ����Ʈ�� �߰�
                    if (!loop->isFind)
                    {
                        List.push({ loop,loop->F });
                    }
                }
            }
        }
        LoopIdx.clear();
    }

    //�������� ������ �Ǿ�����
    Tile* p = &Tiles[dest.x][dest.y]; //�̰� ������
    //dest 3,0 2,0 1,0 0,0
    while (1)
    {
        way.emplace_back(p);

        p = p->P;

        if (p == nullptr)
        {
            break;
        }
    }
    return true;
}


void ObTileMap::CreateTileCost()
{
    for (int i = 0; i < Tiles.size(); i++)
    {
        Tiles[i].clear();
    }
    Tiles.clear();

    Tiles.resize(tileSize.x);

    for (int i = 0; i < Tiles.size(); i++)
    {
        Tiles[i].resize(tileSize.y);
    }

    Vector2 half = scale * 0.5f;
    Update();
    for (int i = 0; i < tileSize.x; i++)
    {
        for (int j = 0; j < tileSize.y; j++)
        {
            Tiles[i][j].idx = Int2(i, j);
            Tiles[i][j].state = GetTileState(Tiles[i][j].idx);
            Tiles[i][j].Pos.x = i * scale.x + GetWorldPos().x + half.x;
            Tiles[i][j].Pos.y = j * scale.y + GetWorldPos().y + half.y;
        }
    }
}

void Tile::ClearCost()
{
    F = G = H = INT_MAX;

    P = nullptr;
    isFind = false;
}

void Tile::ClacH(Int2 DestIdx)
{
    int tempX = abs(idx.x - DestIdx.x) * 10;
    int tempY = abs(idx.y - DestIdx.y) * 10;

    H = tempX + tempY;
}

void Tile::ClacF()
{
    F = G + H;
}

int ObTileMap::GetTileState(Int2 TileIdx)
{
    int tileIdx = tileSize.x * TileIdx.y + TileIdx.x;
    return vertices[tileIdx * 6].tileState;
}