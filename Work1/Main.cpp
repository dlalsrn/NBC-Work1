#include <bits/stdc++.h>
using namespace std;

void InitStatus(int status[])
{
	int hp, mp, att, def;

	while (true)
	{
		cout << "HP�� MP�� �Է����ּ���: ";
		cin >> hp >> mp;

		if (hp <= 50 || mp <= 50)
		{
			cout << "HP�� MP�� ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���.\n";
		}
		else
		{
			status[0] = hp;
			status[1] = mp;
			break;
		}
	}

	while (true)
	{
		cout << "���ݷ°� ������ �Է����ּ���: ";
		cin >> att >> def;

		if (att <= 0 || def <= 0)
		{
			cout << "���ݷ��̳� ���� ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���.\n"; \
		}
		else
		{
			status[2] = att;
			status[3] = def;
			break;
		}
	}
}

void SetPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	cout << "* ������ ���޵Ǿ����ϴ�. (HP, MP ���� �� " << count << "��)\n";
	*p_HPPotion = count;
	*p_MPPotion = count;
}

void UsePotion(int status[], int potionType, int* potion) // potionType 0: HP, 1: MP
{
	if (*potion) // ������ �ִٸ�
	{
		string type = potionType ? "MP" : "HP";
		(*potion)--;
		status[potionType] += 20;

		cout << "* " << type << "�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�.\n";
		cout << "���� " << type << ": " << status[potionType] << '\n';
		cout << "���� ���� ��: " << *potion << '\n';
	}
	else
	{
		cout << "������ �����մϴ�.\n";
	}
}

void UpgradeStatus(int status[], int statusType)
{
	string type = statusType ? "MP" : "HP";
	status[statusType] *= 2;
	
	cout << "* " << type << "�� 2��� �����Ǿ����ϴ�.\n";
	cout << "���� " << type << ": " << status[statusType] << '\n';
}

void UseAttackSkill(int* mp)
{
	if (*mp >= 50)
	{
		*mp -= 50;
		cout << "* ��ų�� ����Ͽ� MP�� 50 �Ҹ�Ǿ����ϴ�.\n";
		cout << "���� MP: " << *mp << '\n';
	}
	else
	{
		cout << "��ų ����� �Ұ��մϴ�.\n";
	}
}

void UseUltimate(int* mp)
{
	if (*mp >= 1)
	{
		*mp /= 2;
		cout << "* ��ų�� ����Ͽ� MP�� 50% �Ҹ�Ǿ����ϴ�.\n";
		cout << "���� MP: " << *mp << '\n';
	}
	else
	{
		cout << "�ʻ�� ����� �Ұ��մϴ�.\n";
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);

	// ���� ���� �� �ʱ�ȭ
	int status[4] = { 0 }; // HP, MP, ATT, DEF
	int hpPotion, mpPotion;
	InitStatus(status);
	SetPotion(5, &hpPotion, &mpPotion);
	cout << "=============================================\n";

	// ���� ���� �ý��� ����
	cout << "<���� ���� �ý���>\n";
	cout << "1. HP ȸ��\n";
	cout << "2. MP ȸ��\n";
	cout << "3. HP ��ȭ\n";
	cout << "4. MP ��ȭ\n";
	cout << "5. ���� ��ų ���\n";
	cout << "6. �ʻ�� ���\n";
	cout << "7. ������\n";

	while (true)
	{
		int choice;
		cout << "��ȣ�� �������ּ���: ";
		cin >> choice;
		switch (choice)

		{
			case 1: // HP ȸ��
				UsePotion(status, 0, &hpPotion);
				break;
			case 2: // MP ȸ��
				UsePotion(status, 1, &mpPotion);
				break;
			case 3: // HP ��ȭ
				UpgradeStatus(status, 0);
				break;
			case 4: // MP ��ȭ
				UpgradeStatus(status, 1);
				break;
			case 5: // ���� ��ų ���
				UseAttackSkill(&status[1]);
				break;
			case 6: // �Ȼ�� ���
				UseUltimate(&status[1]);
				break;
			case 7: // ������
				cout << "���α׷��� �����մϴ�.\n";
				return 0;
			default:
				cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���.\n";
				break;
		}
	}

	return 0;
}