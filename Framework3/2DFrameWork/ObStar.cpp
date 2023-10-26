#include "framework.h"
ID3D11Buffer* ObStar::fillVertexBuffer = nullptr;
ID3D11Buffer* ObStar::vertexBuffer = nullptr;

void ObStar::CreateStaticMember()
{
    VertexPC* Vertex;
    Vertex = new VertexPC[5 * 3];

    for (UINT i = 0; i < 5; i++)
    {
        Vertex[i * 3].position.x = 0.0f;
        Vertex[i * 3].position.y = 0.0f;
        Vertex[i * 3].color = Color(1.0f, 1.0f, 1.0f, 1.0f);

        Vertex[i * 3 + 1].position.x = cosf(i * 144 * ToRadian) * 0.5f;
        Vertex[i * 3 + 1].position.y = sinf(i * 144 * ToRadian) * 0.5f;
        Vertex[i * 3 + 1].color = Color(0.0f, 0.0f, 0.0f, 1.0f);

        Vertex[i * 3 + 2].position.x = cosf((i + 1) * 144 * ToRadian) * 0.5f;
        Vertex[i * 3 + 2].position.y = sinf((i + 1) * 144 * ToRadian) * 0.5f;
        Vertex[i * 3 + 2].color = Color(0.0f, 0.0f, 0.0f, 1.0f);
    }
    //�������� ���۷� �Ű����� �ڵ�
    {
        D3D11_BUFFER_DESC desc;
        desc = { 0 }; //������� ���� 0����
        desc.Usage = D3D11_USAGE_DEFAULT;//���۸� �а� ���� ���
        desc.ByteWidth = sizeof(VertexPC) * 5 * 3; //���� ũ�� (����Ʈ)�Դϴ�.
        desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;//���۰� ������ ���ο� ���ε��Ǵ� ����� �ĺ��Ͻʽÿ�

        D3D11_SUBRESOURCE_DATA data = { 0 };
        //���� ���ҽ��� �ʱ�ȭ�ϱ����� �����͸� �����մϴ�.
        data.pSysMem = Vertex;
        //�ʱ�ȭ �������� ������.

        //���� �����
        //                                           ����    ����       ������   
        HRESULT hr = D3D->GetDevice()->CreateBuffer(&desc, &data, &fillVertexBuffer);
        assert(SUCCEEDED(hr));

    }

    delete[] Vertex;

    Vertex = new VertexPC[6];

    //�ΰ��� ������ �� �����
    for (UINT i = 0; i < 6; i++)
    {
        Vertex[i].color = Color(1.0f, 1.0f, 1.0f, 1.0f);
        Vertex[i].position.x = cosf(i * 144.0f * ToRadian) * 0.5f;
        Vertex[i].position.y = sinf(i * 144.0f * ToRadian) * 0.5f;
    }


    {
        D3D11_BUFFER_DESC desc;
        desc = { 0 };
        desc.Usage = D3D11_USAGE_DEFAULT;//���۸� �а� ���� ���
        desc.ByteWidth = sizeof(VertexPC) * 6; //���� ũ�� (����Ʈ)�Դϴ�.
        desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;//���۰� ������ ���ο� ���ε��Ǵ� ����� �ĺ��Ͻʽÿ�

        D3D11_SUBRESOURCE_DATA data = { 0 };
        //���� ���ҽ��� �ʱ�ȭ�ϱ����� �����͸� �����մϴ�.
        data.pSysMem = Vertex;
        //�ʱ�ȭ �������� ������.

        //���� �����
        HRESULT hr = D3D->GetDevice()->CreateBuffer(&desc, &data, &vertexBuffer);
        assert(SUCCEEDED(hr));

    }
    delete[] Vertex;
}

void ObStar::DeleteStaticMember()
{
    vertexBuffer->Release();
    fillVertexBuffer->Release();
}

ObStar::ObStar()
{
}

void ObStar::Render()
{
    if (!isVisible)return;
    GameObject::Render();

    basicShader->Set();

    UINT stride = sizeof(VertexPC);
    UINT offset = 0;

    if (isFilled)
    {
        D3D->GetDC()->IASetVertexBuffers(0,
            1,
            &fillVertexBuffer,
            &stride,
            &offset);
        D3D->GetDC()->IASetPrimitiveTopology
        (D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
        D3D->GetDC()->Draw(5 * 3, 0);
    }
    else
    {
        D3D->GetDC()->IASetVertexBuffers(0,//�Է½���(16~32������ ��������)
            1,//�Է½��Կ� ���̰��� �ϴ� ������ ����
            &vertexBuffer,
            &stride,//���������� �� ������ ����Ʈ���� ũ��
            &offset);
        D3D->GetDC()->IASetPrimitiveTopology
        (D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
        D3D->GetDC()->Draw(6, 0);
    }
}

