#include "framework.h"

Utility::RECT::RECT(Vector2 pivot, Vector2 scale)
{
    min.x = pivot.x - scale.x * 0.5f;
    min.y = pivot.y - scale.y * 0.5f;
    max.x = pivot.x + scale.x * 0.5f;
    max.y = pivot.y + scale.y * 0.5f;

}

Utility::CIRCLE::CIRCLE(Vector2 pivot, Vector2 scale)
{
    this->pivot = pivot;
    radius = scale.x * 0.5f;
}

bool Utility::IntersectRectCoord(RECT & rc, Vector2 coord)
{
    if (rc.min.x < coord.x && rc.max.x > coord.x && 
        rc.min.y < coord.y && rc.max.y > coord.y)
    {
        return true;
    }

    return false;
}

bool Utility::IntersectRectRect(RECT & rc1, RECT & rc2)
{
    if (rc2.max.x > rc1.min.x && rc2.min.x < rc1.max.x && 
        rc2.max.y > rc1.min.y && rc2.min.y < rc1.max.y)
    {
        return true;
    }

    return false;
}

bool Utility::IntersectRectRect(GameObject* ob1, GameObject* ob2)
{
    //�߽���
    Vector2 rc1Pivot = ob1->GetWorldPivot();
    Vector2 rc2Pivot = ob2->GetWorldPivot();

    //�� �߽������� ���� ����
    Vector2 dis = rc1Pivot - rc2Pivot;

    //�簢������ 2���� ����ũ���� ����
    Vector2 Rc1Up =
        ob1->GetUp() * ob1->scale.y * 0.5f;
    Vector2 Rc1Right =
        ob1->GetRight() * ob1->scale.x * 0.5f;

    Vector2 Rc2Up =
        ob2->GetUp() * ob2->scale.y * 0.5f;
    Vector2 Rc2Right =
        ob2->GetRight() * ob2->scale.x * 0.5f;

    //ob1�� right�� ��
    //       ���밪(���� a . b)
    float c = fabs(dis.Dot(ob1->GetRight()));

    //ob2���� �κ��Ͱ� ������ ����
    float a = fabs(Rc2Up.Dot(ob1->GetRight()))
        + fabs(Rc2Right.Dot(ob1->GetRight()));

    //ob1���� �κ��Ͱ� ������ ����
    float b = ob1->scale.x * 0.5f;

    if (c > a + b)return false;

    //ob1�� Up�� ��
    //       ���밪(���� a . b)
    c = fabs(dis.Dot(ob1->GetUp()));

    //ob2���� �κ��Ͱ� ������ ����
    a = fabs(Rc2Up.Dot(ob1->GetUp()))
        + fabs(Rc2Right.Dot(ob1->GetUp()));
    //ob1���� �κ��Ͱ� ������ ����
    b = ob1->scale.y * 0.5f;

    if (c > a + b)return false;

    //ob2�� Right�� ��
    //       ���밪(���� a . b)
    c = fabs(dis.Dot(ob2->GetRight()));

    //ob1���� �κ��Ͱ� ������ ����
    a = fabs(Rc1Up.Dot(ob2->GetRight()))
        + fabs(Rc1Right.Dot(ob2->GetRight()));
    //ob2���� �κ��Ͱ� ������ ����
    b = ob2->scale.x * 0.5f;

    if (c > a + b)return false;

    //ob2�� Up�� ��
    //       ���밪(���� a . b)
    c = fabs(dis.Dot(ob2->GetUp()));

    //ob1���� �κ��Ͱ� ������ ����
    a = fabs(Rc1Up.Dot(ob2->GetUp()))
        + fabs(Rc1Right.Dot(ob2->GetUp()));
    //ob2���� �κ��Ͱ� ������ ����
    b = ob2->scale.y * 0.5f;

    if (c > a + b)return false;

    return true;
}

bool Utility::IntersectRectCircle(RECT & rc, CIRCLE & cc)
{
    Vector2 pivot = (rc.min + rc.max) * 0.5f;
    Vector2 scale = rc.max - rc.min;

    //���� Ȯ�� �簢��
    RECT rc1(pivot, scale + Vector2(cc.radius * 2.0f, 0.0f));
    if (IntersectRectCoord(rc1, cc.pivot))
    {
        return true;
    }

    //���� Ȯ�� �簢��
    RECT rc2(pivot, scale + Vector2(0.0f, cc.radius * 2.0f));
    if (IntersectRectCoord(rc2, cc.pivot))
    {
        return true;
    }
    
    //�𼭸�
    Vector2 edge[4];
    edge[0] = rc.min;
    edge[1] = rc.max;
    edge[2] = Vector2(rc.max.x, rc.min.y);
    edge[3] = Vector2(rc.min.x, rc.max.y);

    for (int i = 0; i < 4; i++)
    {
        if (IntersectCircleCoord(cc, edge[i]))
        {
            return true;
        }
    }

    return false;
}

bool Utility::IntersectCircleCoord(CIRCLE & cc, Vector2 coord)
{
    Vector2 length = cc.pivot - coord;

    if (length.Length() < cc.radius)
    {
        return true;
    }

    return false;
}

bool Utility::IntersectCircleCircle(CIRCLE & cc1, CIRCLE & cc2)
{
    float length = cc1.radius + cc2.radius;
    Vector2 dis = cc1.pivot - cc2.pivot;

    if (dis.Length() < length)
    {
        return true;
    }

    return false;
}

float Utility::DirToRadian(Vector2 Dir)
{
    //���� �������Ͱ� �ƴ϶��
    Dir.Normalize(); //����ȭ
    return atan2f(Dir.y, Dir.x);
}
