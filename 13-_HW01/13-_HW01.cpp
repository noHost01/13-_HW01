// Main.c

#include <iostream>

using namespace std;

// 포션 초기화 함수
void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;
}

void addPotion(int* p_HPPotion, int* p_MPPotion)
{
	(*p_HPPotion)++;
	(*p_MPPotion)++;
}

int main()
{
	int status[7] = { 0 }; // HP, MP, 공격력, 방어력, 민첩, 지능, 운
	int menu;

	// 포션 변수
	int HPPotion = 0;
	int MPPotion = 0;

	int level = 1;

	setPotion(5, &HPPotion, &MPPotion);

	// HP, MP 입력
	while (true)
	{
		cout << "Please enter HP and MP : "; // HP, MP 숫자입력
		cin >> status[0] >> status[1];

		if (status[0] <= 50 || status[1] <= 50)
		{
			cout << "HP and MP values must be greater than 50.\n"; // 출력 표시
		}
		else
		{
			break;
		}
	}

	// 나머지 스테이터스 입력
	while (1)
	{
		cout << "Enter Status : ";
		cin >> status[2] >> status[3] >> status[4] >> status[5] >> status[6];

		bool invalid = false;

		for (int i = 2; i <= 6; i++)
		{
			if (status[i] <= 0)
			{
				invalid = true;
				break;
			}
		}

		if (invalid)
		{
			cout << "Capability must be greater than 0.\n Please re-enter. \n";
		}
		else
		{
			break;
		}
	}


	// Meun 확인 반복문
	while (true)
	{
		cout << "\n1.HP UP / 2.MP UP / 3.Power UP / 4.Defense UP / 5.Speed UP / 6.Intellect UP / 7.Luck UP / 8.Status / 9.Level UP / 0.Exit \n";
		cout << "Please Number : ";
		cin >> menu;

		switch (menu)
		{
		case 0: // 창 종료
			cout << "Program Exit\n";
			return 0;

		case 1: // HP 포션 사용
			if (HPPotion > 0)
			{
				status[0] += 20;
				HPPotion--;
				cout << "Using HP Potion! HP +20 \n";
				cout << "Remaining HP Potion : " << HPPotion << endl;
			}
			else
			{
				cout << "No HP potion \n";
			}
			break;

		case 2: // MP 포션 사용
			if (MPPotion > 0)
			{
				status[1] += 20;
				MPPotion--;
				cout << "Using MP Potion! HP +20 \n";
				cout << "Remaining MP Potion : " << MPPotion << endl;
			}
			else
			{
				cout << "No MP potion \n";
			}
			break;

		case 3: // 공격력 2배 증가
			status[2] *= 2;
			cout << "Power Doubles UP\n";
			break;

		case 4: // 방어력 2배 증가
			status[3] *= 2;
			cout << "Defense Doubles UP\n";
			break;

		case 5: // 민첩 2배 증가
			status[4] *= 2;
			cout << "Speed Doubles UP\n";
			break;

		case 6: // 지능 2배 증가
			status[5] *= 2;
			cout << "Intellect Doubles UP\n";
			break;

		case 7: // 운 1씩 증가
			status[6]++;
			cout << "Luck UP\n";
			break;

		case 8: // 상태창
			cout << "Level : " << level << endl;
			cout << "HP : " << status[0] << endl;
			cout << "MP : " << status[1] << endl;
			cout << "Power : " << status[2] << endl;
			cout << "Defense : " << status[3] << endl;
			cout << "Speed : " << status[4] << endl;
			cout << "Intellect : " << status[5] << endl;
			cout << "Luck : " << status[6] << endl;

			cout << "HP Potion : " << HPPotion << endl;
			cout << "MP Potion : " << MPPotion << endl;
			break;

		case 9: // 레벨 증가
			level++;

			addPotion(&HPPotion, &MPPotion);

			cout << "Level UP! Potion +1 \n";
			cout << "Now Level : " << level << endl;
			break;

		default:
			cout << "Invalid selection.\n";
		}
	}

	//결과 출력
	cout << "\nEntered Status\n";
	cout << "HP : " << status[0] << endl;
	cout << "MP : " << status[1] << endl;
	cout << "Power : " << status[2] << endl;
	cout << "Defense : " << status[3] << endl;
	cout << "Speed : " << status[4] << endl;
	cout << "Intellect : " << status[5] << endl;
	cout << "Luck : " << status[6] << endl;

	return 0;
}