#pragma once
class Texture :public Singleton<Texture>
{
private:
    map<wstring, ID3D11ShaderResourceView*> textureList;

    int textureWidth;
    int textureHeight;

public:
    ~Texture();
    ID3D11ShaderResourceView* LoadTexture(wstring file);
    bool DeleteTexture(wstring file);

    int GetTxWidth() { return textureWidth; }
    int GetTxHeight() { return textureHeight; }
};

