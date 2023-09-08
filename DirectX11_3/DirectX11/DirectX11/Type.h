#pragma once

//��ü ���� �� ����? ���� why? ���������Լ��� ���ǰ� �����ϱ�
class Scene //�߻�Ŭ���� �������̽� : ���������Լ��θ� �̷���� Ŭ����
{
public:
	virtual ~Scene() {};

	//�����Լ� : �ڽ��� ������ �� ���̶�� ���� �� ��
	//���� ���� �Լ�

	//�� �ʱ�ȭ
	virtual void Init() = 0;

	//�� ����
	virtual void Update() = 0;

	//�� ���
	virtual void Render() = 0;
};