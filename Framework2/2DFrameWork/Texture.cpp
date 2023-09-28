#include "framework.h"

Texture::~Texture()
{
    for (auto i = textureList.begin();
        i != textureList.end(); i++)
    {
        if (i->second.srv)
        {
            i->second.srv->Release();
        }
    }
    textureList.clear();
}

ID3D11ShaderResourceView* Texture::LoadTexture(wstring file)
{
    auto iter = textureList.find(file);

    //�ߺ��Ȱ� ����.
    if (iter == textureList.end())
    {
        ID3D11ShaderResourceView* temp;
        wstring path = L"../Contents/Images/" + file;

        ScratchImage image;
        LoadFromWICFile(path.c_str(), WIC_FLAGS_NONE, nullptr, image);

        textureList[file].textureSize.x = image.GetMetadata().width;
        textureList[file].textureSize.y = image.GetMetadata().height;

        HRESULT hr = CreateShaderResourceView(D3D->GetDevice(), image.GetImages(), image.GetImageCount(),
            image.GetMetadata(), &temp);
        Check(hr);

        textureList[file].srv = temp;
        return temp;
    }
    //������ �Ҵ���ִ� �ؽ��ĸ� ��ȯ
    return iter->second.srv;
}

bool Texture::DeleteTexture(wstring file)
{
    auto iter = textureList.find(file);

    //�ߺ��Ȱ� ����.
    if (iter == textureList.end())
    {
        return false;
    }
    //first�� Ű, second ���
    iter->second.srv->Release();

    //�ʿ����� ����
    textureList.erase(iter);

    return true;
}

Int2 Texture::GetTextureSize(wstring file)
{
    return textureList[file].textureSize;
}
