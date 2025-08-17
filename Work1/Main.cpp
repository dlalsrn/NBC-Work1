#include <bits/stdc++.h>
using namespace std;

void InitStatus(int status[])
{
	int hp, mp, att, def;

	while (true)
	{
		cout << "HP와 MP를 입력해주세요: ";
		cin >> hp >> mp;

		if (hp <= 50 || mp <= 50)
		{
			cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n";
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
		cout << "공격력과 방어력을 입력해주세요: ";
		cin >> att >> def;

		if (att <= 0 || def <= 0)
		{
			cout << "공격력이나 방어력 값이 너무 작습니다. 다시 입력해주세요.\n"; \
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
	cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 " << count << "개)\n";
	*p_HPPotion = count;
	*p_MPPotion = count;
}

void UsePotion(int status[], int potionType, int* potion) // potionType 0: HP, 1: MP
{
	if (*potion) // 포션이 있다면
	{
		string type = potionType ? "MP" : "HP";
		(*potion)--;
		status[potionType] += 20;

		cout << "* " << type << "가 20 회복되었습니다. 포션이 1개 차감됩니다.\n";
		cout << "현재 " << type << ": " << status[potionType] << '\n';
		cout << "남은 포션 수: " << *potion << '\n';
	}
	else
	{
		cout << "포션이 부족합니다.\n";
	}
}

void UpgradeStatus(int status[], int statusType)
{
	string type = statusType ? "MP" : "HP";
	status[statusType] *= 2;
	
	cout << "* " << type << "가 2배로 증가되었습니다.\n";
	cout << "현재 " << type << ": " << status[statusType] << '\n';
}

void UseAttackSkill(int* mp)
{
	if (*mp >= 50)
	{
		*mp -= 50;
		cout << "* 스킬을 사용하여 MP가 50 소모되었습니다.\n";
		cout << "현재 MP: " << *mp << '\n';
	}
	else
	{
		cout << "스킬 사용이 불가합니다.\n";
	}
}

void UseUltimate(int* mp)
{
	if (*mp >= 1)
	{
		*mp /= 2;
		cout << "* 스킬을 사용하여 MP가 50% 소모되었습니다.\n";
		cout << "현재 MP: " << *mp << '\n';
	}
	else
	{
		cout << "필살기 사용이 불가합니다.\n";
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);

	// 스탯 선언 및 초기화
	int status[4] = { 0 }; // HP, MP, ATT, DEF
	int hpPotion, mpPotion;
	InitStatus(status);
	SetPotion(5, &hpPotion, &mpPotion);
	cout << "=============================================\n";

	// 스탯 관리 시스템 시작
	cout << "<스탯 관리 시스템>\n";
	cout << "1. HP 회복\n";
	cout << "2. MP 회복\n";
	cout << "3. HP 강화\n";
	cout << "4. MP 강화\n";
	cout << "5. 공격 스킬 사용\n";
	cout << "6. 필살기 사용\n";
	cout << "7. 나가기\n";

	while (true)
	{
		int choice;
		cout << "번호를 선택해주세요: ";
		cin >> choice;
		switch (choice)

		{
			case 1: // HP 회복
				UsePotion(status, 0, &hpPotion);
				break;
			case 2: // MP 회복
				UsePotion(status, 1, &mpPotion);
				break;
			case 3: // HP 강화
				UpgradeStatus(status, 0);
				break;
			case 4: // MP 강화
				UpgradeStatus(status, 1);
				break;
			case 5: // 공격 스킬 사용
				UseAttackSkill(&status[1]);
				break;
			case 6: // 팔살기 사용
				UseUltimate(&status[1]);
				break;
			case 7: // 나가기
				cout << "프로그램을 종료합니다.\n";
				return 0;
			default:
				cout << "잘못 입력하셨습니다. 다시 입력해주세요.\n";
				break;
		}
	}

	return 0;
}