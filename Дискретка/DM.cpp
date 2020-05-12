#include <iostream>
#include <MyCrt.h>
#include <Menu.h>
#include <conio.h>
#include <windows.h>
#include "Natural.h"
#include "integer.h"
#include "rational.h"
#include "polinom.h"

using namespace std;


void PrintNatural(Natural& a)
{
	int* pa = a.get_Arr();
	int n = a.get_n();
	for (int i = n - 1; i >= 0; --i)
		cout << pa[i];
}

void PrintInteger(Integer& a)
{
	int* pa = a.get_Arr();
	int n = a.get_n();
	bool z = a.get_sign();
	if (z != 0)
		cout << '-';
	else
		cout << '+';
	for (int i = n - 1; i >= 0; --i)
		cout << pa[i];
}

void PrintRational(Rational& a)
{
	Integer* pnum = a.get_NUM();
	Natural* pdenum = a.get_DENUM();
	PrintInteger(*pnum);
	cout << '/';
	PrintNatural(*pdenum);
}

int main()
{
	ConSize(160, 50);
	setlocale(0, "");
	TextForeground(15);
	Menu StartMenu;

	char Data[6][20] = { {"Натуральные числа"}, {"Целые числа"}, {"Рациональные числа"}, {"Многочлены"}, {"Справка"}, {"Выйти"} };

	InitMenu(StartMenu, 0, 0, 1, 0, 15, 8, 6, 20, (char*)Data);
	Show_Menu(StartMenu);

	Menu Choice_Menu;
	char Data1[4][21] = { {"Ввести числа"}, {"Вывести числа"}, {"Действия над числами"}, {"Назад"} };
	InitMenu(Choice_Menu, 0, 0, 1, 0, 15, 8, 4, 21, (char*)Data1);

	Menu Choice_Menu2;
	char Data12[4][27] = { {"Ввести многочлены"}, {"Вывести многочлены"}, {"Действия над многочленами"}, {"Назад"} };
	InitMenu(Choice_Menu2, 0, 0, 1, 0, 15, 8, 4, 27, (char*)Data12);

	Menu NaturalActions;
	char Data2[15][114] = { {"N-1 Сравнение натуральных чисел : 2 - если первое больше второго, 0, если равно, 1 иначе"}, {"N-2 Проверка на ноль: если число не равно нулю, то «да» иначе «нет»"}, {"N-3 Добавление 1 к натуральному числу"}, {"N-4 Сложение натуральных чисел"}, {"N-5 Вычитание из первого большего натурального числа второго меньшего или равного"}, {"N-6 Умножение натурального числа на цифру"}, {"N-7 Умножение натурального числа на 10^k"}, {"N-8 Умножение натуральных чисел"}, {"N-9 Вычитание из натурального другого натурального, умноженного на цифру для случая с неотрицательным результатом"}, {"N-10 Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k"}, {"N-11 Частное от деления большего натурального числа на меньшее или равное натуральное с остатком"}, {"N-12 Остаток от деления большего натурального числа на меньшее или равное натуральное с остатком"}, {"N-13 НОД натуральных чисел"}, {"N-14 НОК натуральных чисел"}, {"Назад"} };
	InitMenu(NaturalActions, 0, 0, 1, 0, 15, 8, 15, 114, (char*)Data2);

	Menu IntegerActions;
	char Data3[11][120] = { {"Z-1 Абсолютная величина числа, результат - натуральное"},{"Z-2 Определение положительности числа (2 - положительное, 0 — равное нулю, 1 - отрицательное)"}, {"Z-3 Умножение целого на (-1)"}, {"Z-4 Преобразование натурального в целое"}, {"Z-5 Преобразование целого неотрицательного в натуральное"}, {"Z-6 Сложение целых чисел"}, {"Z-7 Вычитание целых чисел"}, {"Z-8 Умножение целых чисел"}, {"Z-9 Частное от деления большего целого числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)"}, {"Z-10 Остаток от деления большего целого числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)"}, {"Назад"} };
	InitMenu(IntegerActions, 0, 0, 1, 0, 15, 8, 11, 120, (char*)Data3);

	Menu RationalActions;
	char Data4[9][120] = { {"Q-1 Сокращение дроби"},{"Q-2 Проверка на целое, если рациональное число является целым, то «да», иначе «нет»"},{"Q-3 Преобразование целого в дробное"},{"Q-4 Преобразование дробного в целое (если знаменатель равен 1)"},{"Q-5 Сложение дробей"},{"Q-6 Вычитание дробей"},{"Q-7 Умножение дробей"},{"Q-8 Деление дробей (делитель отличен от нуля)"},{"Назад"} };
	InitMenu(RationalActions, 0, 0, 1, 0, 15, 8, 9, 120, (char*)Data4);


	Menu PolynomActions;
	char Data5[14][120] = { {"P-1 Сложение многочленов"},{"P-2 Вычитание многочленов"},{"P-3 Умножение многочлена на рациональное число"},{"P-4 Умножение многочлена на x^k"},{"P-5 Старший коэффициент многочлена"},{"P-6 Степень многочлена"},{"P-7 Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей"},{"P-8 Умножение многочленов"},{"P-9 Частное от деления многочлена на многочлен при делении с остатком"},{"P-10 Остаток от деления многочлена на многочлен при делении с остатком"},{"P-11 НОД многочленов"},{"P-12 Производная многочлена"},{"P-13 Преобразование многочлена — кратные корни в простые"}, {"Назад"}};
	InitMenu(PolynomActions, 0, 0, 1, 0, 15, 8, 14, 120, (char*)Data5);

	int a=0,b=0,k=0;
	double a1, b1;

	string str1, str2;
	Natural nat1, nat2;
	Integer int1, int2;

	Integer num1, num2;
	Natural denum1, denum2;
	Rational rat1, rat2, ratbuff;
	

	do
	{
		ItemChoice(StartMenu);
		//Натуральные числа
		if (StartMenu.Item == 0)
		{
			HideMenu(StartMenu,0);
			Show_Menu(Choice_Menu);
			do
			{
				ItemChoice(Choice_Menu);
				if (Choice_Menu.Item == 0)//Ввести числа
				{
					GoToXY(0, 0);
					HideMenu(Choice_Menu, 0);
					cout << "Введите 1-е число: " << endl;
					cin >> str1;
					nat1 = Natural(str1);
					cout << "Введите 2-е число(случайное, если не нужно): " << endl;
					cin >> str2;
					nat2 = Natural(str2);

					system("pause");

					ClrScr();
					Show_Menu(Choice_Menu);
				}

				if (Choice_Menu.Item == 1)//Вывести числа
				{
					GoToXY(0, 0);
					HideMenu(Choice_Menu, 0);
					cout << "1-е число: ";
					PrintNatural(nat1);
					cout << endl;
					
					cout << "2-е число: ";
					PrintNatural(nat2);
					cout << endl;

					system("pause");

					ClrScr();
					Show_Menu(Choice_Menu);
				}

				if (Choice_Menu.Item == 2)//Действия над числами
				{
					HideMenu(Choice_Menu, 0);
					Show_Menu(NaturalActions);
					do
					{
						ItemChoice(NaturalActions);
						if (NaturalActions.Item == 0)//N-1
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);

							cout << "Сравнение натуральных чисел : 2 - если первое больше второго, 0, если равно, 1 иначе" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl;
							cout << "Результат: " << nat1.COM_NN_D(nat2) << endl;
							
							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}

						if (NaturalActions.Item == 1)//N-2
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);

							cout << "Проверка на ноль : если число не равно нулю, то 1 иначе 0" << endl;

							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl;

							cout << "Какое число проверить (1/2)" << endl;

							char c;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl;
							if (c == '1')
							{
								cout << "Результат: ";
									cout << nat1.NZER_N_B() << endl;
							}
							else
							{
								cout << "Результат: ";
									cout << nat2.NZER_N_B() << endl;
							}
							
							

							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}

						if (NaturalActions.Item == 2)//N-3
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);
							cout << "Добавление единицы к натуральному числу" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl;
							cout << "К какому числу прибавить единицу? (1/2)" << endl;

							char c;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl;

							if (c == '1')
							{
								cout << "Результат: ";
								PrintNatural(nat1.ADD_1N_N());
								cout << endl;
							}
							else
							{
								cout << "Результат: ";
								PrintNatural(nat2.ADD_1N_N());
								cout << endl;
							}

							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}
						if (NaturalActions.Item == 3)//N-4
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);

							cout << "Сложение натуральных чисел" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl << "Результат: ";
							PrintNatural(nat1.ADD_NN_N(nat2));
								cout << endl;


							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}
						if (NaturalActions.Item == 4)//N-5
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);

							cout << "Вычитание из первого большего натурального числа второго меньшего или равного " << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl << "Результат: ";
							PrintNatural(nat1.SUB_NN_N(nat2));
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}
						if (NaturalActions.Item == 5)//N-6
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);

							cout << "Умножение натурального числа на цифру" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl;

							cout << "Введите цифру: ";
							
							char c;
							int n = 0;

							do
							{
								c = _getch();

								if ((c >= '0') && (c <= '9') && (n < 1))
								{
									++n;
									k = c - '0';
									cout << k;
								}
								if ((c == 8)&&(n > 0))
								{
									cout << "\b \b";
									--n;
								}
								
							} while (c != 13);
							
							cout << endl << "Какое число умножить на введённую цифру? (1/2)" << endl;

							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl;

							if (c == '1')
							{
								cout << "Результат: ";
								PrintNatural(nat1.MUL_ND_N(k));
								cout << endl;
							}
							else
							{
								cout << "Результат: ";
								PrintNatural(nat2.MUL_ND_N(k));
								cout << endl;
							}

							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}
						if (NaturalActions.Item == 6)//N-7
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);

							cout << "Умножение натурального числа на 10^k " << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl;
							char c;
					
							cout << "Введите степень k" << endl;
							k = 0;

							do
							{
								c = _getch();

								if ((c >= '0') && (c <= '9'))
								{
									k = k * 10 + c - '0';
									cout << c;
								}
								if ((c == 8))
								{
									cout << "\b \b";
									k = k / 10;
								}

							} while (c != 13);
							cout << endl << "Выберите число (1/2)" << endl;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl;

							if (c == '1')
							{
								cout << "Результат: ";
								PrintNatural(nat1.MUL_Nk_N(k));
								cout << endl;
							}
							else
							{
								cout << "Результат: ";
								PrintNatural(nat2.MUL_Nk_N(k));
								cout << endl;
							}
							
							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}
						if (NaturalActions.Item == 7)//N-8
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);
							cout << "Перемножение чисел " << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl << "Результат: ";
							PrintNatural(nat1.MUL_NN_N(nat2));
								cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}
						if (NaturalActions.Item == 8)//N-9
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);
							cout << "Вычитание из натурального другого натурального, умноженного на цифру " << endl;
							
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl;
							cout << "Введите цифру, на которую хотите умножить число" << endl;
							char c;
							int n = 0;

							do
							{
								c = _getch();

								if ((c >= '0') && (c <= '9') && (n < 1))
								{
									++n;
									k = c - '0';
									cout << k;
								}
								if ((c == 8) && (n > 0))
								{
									cout << "\b \b";
									--n;
								}

							} while (c != 13);
							cout << endl << "Результат: ";
							PrintNatural(nat1.SUB_NDN_N(nat2, k));
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}
						if (NaturalActions.Item == 9)//N-10
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);
						    
							cout << "Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10 ^ k.  " << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl;
							cout << "Введите число, степень 10ти" << endl;
							cout << "Введите степень k" << endl;
							k = 0;
							char c;

							do
							{
								c = _getch();

								if ((c >= '0') && (c <= '9'))
								{
									k = k * 10 + c - '0';
									cout << c;
								}
								if ((c == 8))
								{
									cout << "\b \b";
									k = k / 10;
								}

							} while (c != 13);

							cout << endl << "Результат: ";
							cout << nat1.DIV_NN_Dk(nat2, k);
							cout << endl;


							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}
						if (NaturalActions.Item == 10)//N-11
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);

							cout << "Частное от деления большего натурального числа на меньшее или равное натуральное с остатком" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl << "Результат: ";
							PrintNatural(nat1.DIV_NN_N(nat2));
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}
						if (NaturalActions.Item == 11)//N-12
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);

							cout << " Остаток от деления большего натурального числа на меньшее или равное натуральное с остатком" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl << "Результат: ";
							PrintNatural(nat1.MOD_NN_N(nat2));
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}
						if (NaturalActions.Item == 12)//N-13
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);

							cout << "НОД натуральных чисел" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl << "Результат: ";
							PrintNatural(nat1.GCF_NN_N(nat2));
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}
						if (NaturalActions.Item == 13)//N-14
						{
							GoToXY(0, 0);
							HideMenu(NaturalActions, 0);

							cout << "НОК натуральных чисел" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl << "Результат: ";
							PrintNatural(nat1.LCM_NN_N(nat2));
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(NaturalActions);
						}
						if (NaturalActions.Item == 14)//Назад
						{
							HideMenu(NaturalActions, 0);
							Show_Menu(Choice_Menu);
						}
					} while (NaturalActions.Item != 14);
				}
				if (Choice_Menu.Item == 3)//Назад
				{
					HideMenu(Choice_Menu,0);
					Show_Menu(StartMenu);
				}
			} while (Choice_Menu.Item != 3);
		}
		//Целые числа
		if (StartMenu.Item == 1)
		{
			HideMenu(StartMenu, 0);
			Show_Menu(Choice_Menu);
			do
			{
				ItemChoice(Choice_Menu);
				if (Choice_Menu.Item == 0)//Ввести числа
				{
					GoToXY(0, 0);
					HideMenu(Choice_Menu, 0);
					cout << "Введите 1-е число: " << endl;
					cin >> str1;
					int1 = Integer(str1);
					cout << "Введите 2-е число(случайное, если не нужно): " << endl;
					cin >> str2;
					int2 = Integer(str2);

					system("pause");

					ClrScr();
					Show_Menu(Choice_Menu);
				}

				if (Choice_Menu.Item == 1)//Вывести числа
				{
					GoToXY(0, 0);
					HideMenu(Choice_Menu, 0);
					cout << "1-е число: ";
					PrintInteger(int1);
					cout << endl;

					cout << "2-е число: ";
					PrintInteger(int2);
					cout << endl;

					system("pause");

					ClrScr();
					Show_Menu(Choice_Menu);
				}

				if (Choice_Menu.Item == 2)//Действия над числами
				{
					HideMenu(Choice_Menu, 0);
					Show_Menu(IntegerActions);
					do
					{
						ItemChoice(IntegerActions);
						if (IntegerActions.Item == 0)//Z-1
						{
							GoToXY(0, 0);
							HideMenu(IntegerActions, 0);

							cout << "Абсолютная величина числа, результат - натуральное" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintInteger(int1);
							cout << endl << "2-ое: ";
							PrintInteger(int2);
							cout << endl;
							cout << "C каким числом работать? (1/2)" << endl;

							char c;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl;
							if (c == '1')
							{
								cout << "Результат: ";
								PrintNatural(int1.ABS_Z_N());
							}
							else
							{
								cout << "Результат: ";
								PrintNatural(int2.ABS_Z_N());
							}
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(IntegerActions);
						}

						if (IntegerActions.Item == 1)//Z-2
						{
							GoToXY(0, 0);
							HideMenu(IntegerActions, 0);

							
							cout << "Определение положительности числа. 2-полож., 1-отриц. иначе 0" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintInteger(int1);
							cout << endl << "2-ое: ";
							PrintInteger(int2);
							cout << endl;
							cout << "C каким числом работать? (1/2)" << endl;

							char c;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl;
							if (c == '1')
							{
								cout << "Результат: " << int1.POZ_Z_D() << endl;
							}
							else
							{
								cout << "Результат: " << int2.POZ_Z_D() << endl;
							}
							
							system("pause");

							ClrScr();
							Show_Menu(IntegerActions);
						}

						if (IntegerActions.Item == 2)//Z-3
						{
							GoToXY(0, 0);
							HideMenu(IntegerActions, 0);
							
							cout << "Умножение целого на(-1)" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintInteger(int1);
							cout << endl << "2-ое: ";
							PrintInteger(int2);
							cout << endl;
							cout << "C каким числом работать? (1/2)" << endl;

							char c;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl << "Результат: ";
							if (c == '1')
							{
								PrintInteger(int1.MUL_ZM_Z());
							}
							else
							{
								PrintInteger(int2.MUL_ZM_Z());
							}
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(IntegerActions);
						}
						if (IntegerActions.Item == 3)//Z-4
						{
							GoToXY(0, 0);
							HideMenu(IntegerActions, 0);

							cout << "Преобразовнаие натурального числа в целое.\nУбедитесь, что натуральные числа введены в разделе \"Натуральные числа\"" << endl;
							cout << "Ваши числа(натуральные):" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl;
							cout << "C каким числом работать? (1/2)" << endl;

							char c;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl << "Результат: ";
							if (c == '1')
							{
								PrintInteger(int1.TRANS_N_Z(nat1));
							}
							else
							{
								PrintInteger(int2.TRANS_N_Z(nat2));
							}
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(IntegerActions);
						}
						if (IntegerActions.Item == 4)//Z-5
						{
							GoToXY(0, 0);
							HideMenu(IntegerActions, 0);

							cout << "Преобразование целого неотрицательного в натуральное" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintInteger(int1);
							cout << endl << "2-ое: ";
							PrintInteger(int2);
							cout << endl;
							cout << "C каким числом работать? (1/2)" << endl;

							char c;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl << "Результат: ";
							if (c == '1')
							{
								PrintNatural(int1.TRANS_Z_N());
							}
							else
							{
								PrintNatural(int2.TRANS_Z_N());
							}
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(IntegerActions);
						}
						if (IntegerActions.Item == 5)//Z-6
						{
							GoToXY(0, 0);
							HideMenu(IntegerActions, 0);

							cout << "Сложение целых чисел" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintInteger(int1);
							cout << endl << "2-ое: ";
							PrintInteger(int2);
							cout << endl << "Результат: ";
							PrintInteger(int1.ADD_ZZ_Z(int2));
							cout << endl;


							system("pause");

							ClrScr();
							Show_Menu(IntegerActions);
						}
						if (IntegerActions.Item == 6)//Z-7
						{
							GoToXY(0, 0);
							HideMenu(IntegerActions, 0);

							cout << "Вычитание целых чисел" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintInteger(int1);
							cout << endl << "2-ое: ";
							PrintInteger(int2);
							cout << endl << "Результат: ";
							PrintInteger(int1.SUB_ZZ_Z(int2));
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(IntegerActions);
						}
						if (IntegerActions.Item == 7)//Z-8
						{
							GoToXY(0, 0);
							HideMenu(IntegerActions, 0);
							
							cout << "Умножение целых чисел" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintInteger(int1);
							cout << endl << "2-ое: ";
							PrintInteger(int2);
							cout << endl << "Результат: ";

							PrintInteger(int1.MUL_ZZ_Z(int2));
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(IntegerActions);
						}
						if (IntegerActions.Item == 8)//Z-9
						{
							GoToXY(0, 0);
							HideMenu(IntegerActions, 0);

							cout << "Частное от деления большего целого числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)" << endl;
							
							cout << "Ваши целые числа:" << endl << "1-ое: ";
							PrintInteger(int1);
							cout << endl << "2-ое: ";
							PrintInteger(int2);
							cout << "C каким числом работать? (1/2)" << endl;

							char c;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl;

							cout << "Ваши натуральные числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl;
							cout << "C каким числом работать? (1/2)" << endl;

							char d;
							do
							{
								d = _getch();
							} while ((d != '1') && (d != '2'));
							cout << d << endl;

							cout << endl << "Результат: ";

							if ((c=='1')&&(d=='1'))
							PrintInteger(int1.DIV_ZZ_Z(nat1));
							if ((c == '1') && (d == '2'))
								PrintInteger(int1.DIV_ZZ_Z(nat2));
							if ((c == '2') && (d == '1'))
								PrintInteger(int2.DIV_ZZ_Z(nat1));
							if ((c == '2') && (d == '2'))
								PrintInteger(int2.DIV_ZZ_Z(nat2));
							cout << endl;


							system("pause");

							ClrScr();
							Show_Menu(IntegerActions);
						}
						if (IntegerActions.Item == 9)//Z-10
						{
							GoToXY(0, 0);
							HideMenu(IntegerActions, 0);

							cout << "Остаток от деления большего целого числа на меньшее или равное натуральное с остатком(делитель отличен от нуля)" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintInteger(int1);
							cout << endl << "2-ое: ";
							PrintInteger(int2);
							cout << endl;
							cout << "C каким числом работать? (1/2)" << endl;

							char c;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl;

							cout << "Ваши натуральные числа:" << endl << "1-ое: ";
							PrintNatural(nat1);
							cout << endl << "2-ое: ";
							PrintNatural(nat2);
							cout << endl;
							cout << "C каким числом работать? (1/2)" << endl;

							char d;
							do
							{
								d = _getch();
							} while ((d != '1') && (d != '2'));
							cout << d << endl;

							cout << endl << "Результат: ";

							if ((c == '1') && (d == '1'))
								PrintInteger(int1.MOD_ZZ_Z(nat1));
							if ((c == '1') && (d == '2'))
								PrintInteger(int1.MOD_ZZ_Z(nat2));
							if ((c == '2') && (d == '1'))
								PrintInteger(int2.MOD_ZZ_Z(nat1));
							if ((c == '2') && (d == '2'))
								PrintInteger(int2.MOD_ZZ_Z(nat2));
							cout << endl;


							system("pause");

							ClrScr();
							Show_Menu(IntegerActions);
						}
						
						if (IntegerActions.Item == 10)//Назад
						{
							HideMenu(IntegerActions, 0);
							Show_Menu(Choice_Menu);
						}
					} while (IntegerActions.Item != 10);
				}
				if (Choice_Menu.Item == 3)//Назад
				{
					HideMenu(Choice_Menu, 0);
					Show_Menu(StartMenu);
				}
			} while (Choice_Menu.Item != 3);
		}
		//Рациональные
		if (StartMenu.Item == 2)
		{
			HideMenu(StartMenu, 0);
			Show_Menu(Choice_Menu);
			do
			{
				ItemChoice(Choice_Menu);
				if (Choice_Menu.Item == 0)//Ввести числа
				{
					GoToXY(0, 0);
					HideMenu(Choice_Menu, 0);
					cout << "1-е число: " << endl;
					cout << "Введите числитель(целое число): ";
					cin >> str1;
					num1 = Integer(str1);
					cout << endl;
					cout << "Введите знаменатель(натуральное число): ";
					cin >> str2;
					denum1 = Natural(str2);
					cout << endl;

					rat1 = Rational(num1, denum1);

					cout << "2-е число(случайные значения, если не нужно): " << endl;
					cout << "Введите числитель(целое число): ";
					cin >> str1;
					num2 = Integer(str1);
					cout << endl;
					cout << "Введите знаменатель(натуральное число): ";
					cin >> str2;
					denum2 = Natural(str2);
					cout << endl;

					rat2 = Rational(num2, denum2);

					system("pause");

					ClrScr();
					Show_Menu(Choice_Menu);
				}

				if (Choice_Menu.Item == 1)//Вывести числа
				{
					GoToXY(0, 0);
					HideMenu(Choice_Menu, 0);
					cout << "1-е число: ";
					PrintRational(rat1);
					cout << endl;
					cout << "2-е число: ";
					PrintRational(rat2);
					cout<< endl;

					system("pause");

					ClrScr();
					Show_Menu(Choice_Menu);
				}

				if (Choice_Menu.Item == 2)//Действия над числами
				{
					HideMenu(Choice_Menu, 0);
					Show_Menu(RationalActions);
					do
					{
						ItemChoice(RationalActions);
						if (RationalActions.Item == 0)//Q-1
						{
							GoToXY(0, 0);
							HideMenu(RationalActions, 0);

							cout << "Сокращение дроби:" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintRational(rat1);
							cout << endl << "2-ое: ";
							PrintRational(rat2);
							cout << endl;
							cout << "С каким числом производить действия?(1/2)" << endl;
							char c;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
								cout << c << endl << "Результат: ";
								if (c == '1')
									PrintRational(rat1.RED_Q_Q());
								else
									PrintRational(rat2.RED_Q_Q());
								cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(RationalActions);
						}

						if (RationalActions.Item == 1)//Q-2
						{
							GoToXY(0, 0);
							HideMenu(RationalActions, 0);

							cout << "Проверка на целое, если рациональное число является целым, то «да», иначе «нет»" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintRational(rat1);
							cout << endl << "2-ое: ";
							PrintRational(rat2);
							cout << endl;
							cout << "С каким числом производить действия?(1/2)" << endl;
							char c;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl << "Результат: ";
							if (c == '1')
								switch (rat1.INT_Q_B())
								{
								case true: cout << "да";
									break;
								case false: cout << "нет";
									break;
								}
							else
								switch (rat2.INT_Q_B())
								{
								case true: cout << "да";
									break;
								case false: cout << "нет";
									break;
								}
								
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(RationalActions);
						}

						if (RationalActions.Item == 2)//Q-3
						{
							GoToXY(0, 0);
							HideMenu(RationalActions, 0);

							cout << "Преобразование целого в дробное" << endl;
							cout << "Ваши целые числа(убедитесь, что они были введены):" << endl << "1-ое: ";
							PrintInteger(int1);
							cout << endl << "2-ое: ";
							PrintInteger(int2);
							cout << endl;
							cout << "С каким числом производить действия?(1/2)" << endl;
							char c;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl << "Результат: ";
							if (c == '1')
								ratbuff = Rational(int1);
							else
								ratbuff = Rational(int2);
							PrintRational(ratbuff);
							cout << endl;
												
							system("pause");

							ClrScr();
							Show_Menu(RationalActions);
						}
						if (RationalActions.Item == 3)//Q-4
						{
							GoToXY(0, 0);
							HideMenu(RationalActions, 0);

							cout << "Преобразование дробного в целое (если знаменатель равен 1)" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintRational(rat1);
							cout << endl << "2-ое: ";
							PrintRational(rat2);
							cout << endl;
							cout << "С каким числом производить действия?(1/2)" << endl;
							char c;
							do
							{
								c = _getch();
							} while ((c != '1') && (c != '2'));
							cout << c << endl << "Результат: ";
							if (c == '1')
								PrintInteger(rat1.TRANS_Q_Z());
							else
								PrintInteger(rat2.TRANS_Q_Z());
							cout << endl;
							

							system("pause");

							ClrScr();
							Show_Menu(RationalActions);
						}
						if (RationalActions.Item == 4)//Q-5
						{
							GoToXY(0, 0);
							HideMenu(RationalActions, 0);

							cout << "Сложение дробей" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintRational(rat1);
							cout << endl << "2-ое: ";
							PrintRational(rat2);
							cout << endl << "Результат: ";
							PrintRational(rat1.ADD_QQ_Q(rat2));
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(RationalActions);
						}
						if (RationalActions.Item == 5)//Q-6
						{
							GoToXY(0, 0);
							HideMenu(RationalActions, 0);

							cout << "Вычитание дробей" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintRational(rat1);
							cout << endl << "2-ое: ";
							PrintRational(rat2);
							cout << endl;
							cout << endl << "Результат: ";
							PrintRational(rat1.SUB_QQ_Q(rat2));
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(RationalActions);
						}
						if (RationalActions.Item == 6)//Q-7
						{
							GoToXY(0, 0);
							HideMenu(RationalActions, 0);

							cout << "Умножение дробей" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintRational(rat1);
							cout << endl << "2-ое: ";
							PrintRational(rat2);
							cout << endl;
							cout << endl << "Результат: ";
							PrintRational(rat1.MUL_QQ_Q(rat2));
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(RationalActions);
						}
						if (RationalActions.Item == 7)//Q-8
						{
							GoToXY(0, 0);
							HideMenu(RationalActions, 0);

							cout << "Деление дробей (делитель отличен от нуля)" << endl;
							cout << "Ваши числа:" << endl << "1-ое: ";
							PrintRational(rat1);
							cout << endl << "2-ое: ";
							PrintRational(rat2);
							cout << endl;
							cout << endl << "Результат: ";
							PrintRational(rat1.DIV_QQ_Q(rat2));
							cout << endl;

							system("pause");

							ClrScr();
							Show_Menu(RationalActions);
						}

						if (RationalActions.Item == 8)//Назад
						{
							HideMenu(RationalActions, 0);
							Show_Menu(Choice_Menu);
						}
					} while (RationalActions.Item != 8);
				}
				if (Choice_Menu.Item == 3)//Назад
				{
					HideMenu(Choice_Menu, 0);
					Show_Menu(StartMenu);
				}
			} while (Choice_Menu.Item != 3);
		}
		//Многочлены
		if (StartMenu.Item == 3)
		{
			HideMenu(StartMenu, 0);
			Show_Menu(Choice_Menu2);
				do
				{
					ItemChoice(Choice_Menu2);
					if (Choice_Menu2.Item == 0)//Ввести многочлены
					{
						GoToXY(0, 0);
						HideMenu(Choice_Menu2, 0);
						cout << "Введите 1-й многочлен: " << endl;
						
						cout << "Введите 2-й многочлен: " << endl;
					

						system("pause");

						ClrScr();
						Show_Menu(Choice_Menu2);
					}

					if (Choice_Menu2.Item == 1)//Вывести многочлены
					{
						GoToXY(0, 0);
						HideMenu(Choice_Menu2, 0);
						cout << "1-й многочлен: " << a << endl;

						cout << "2-й многочлен: " << b << endl;

						system("pause");

						ClrScr();
						Show_Menu(Choice_Menu2);
					}

					if (Choice_Menu2.Item == 2)//Действия над многочленами
					{
						HideMenu(Choice_Menu2, 0);
						Show_Menu(PolynomActions);
						do
						{
							ItemChoice(PolynomActions);
							if (PolynomActions.Item == 0)//P-1
							{
								GoToXY(0, 0);
								HideMenu(PolynomActions, 0);


								system("pause");

								ClrScr();
								Show_Menu(PolynomActions);
							}

							if (PolynomActions.Item == 1)//P-2
							{
								GoToXY(0, 0);
								HideMenu(PolynomActions, 0);


								system("pause");

								ClrScr();
								Show_Menu(PolynomActions);
							}

							if (PolynomActions.Item == 2)//P-3
							{
								GoToXY(0, 0);
								HideMenu(PolynomActions, 0);



								system("pause");

								ClrScr();
								Show_Menu(PolynomActions);
							}
							if (PolynomActions.Item == 3)//P-4
							{
								GoToXY(0, 0);
								HideMenu(PolynomActions, 0);



								system("pause");

								ClrScr();
								Show_Menu(PolynomActions);
							}
							if (PolynomActions.Item == 4)//P-5
							{
								GoToXY(0, 0);
								HideMenu(PolynomActions, 0);




								system("pause");

								ClrScr();
								Show_Menu(PolynomActions);
							}
							if (PolynomActions.Item == 5)//P-6
							{
								GoToXY(0, 0);
								HideMenu(PolynomActions, 0);


								system("pause");

								ClrScr();
								Show_Menu(PolynomActions);
							}
							if (PolynomActions.Item == 6)//P-7
							{
								GoToXY(0, 0);
								HideMenu(PolynomActions, 0);


								system("pause");

								ClrScr();
								Show_Menu(PolynomActions);
							}
							if (PolynomActions.Item == 7)//P-8
							{
								GoToXY(0, 0);
								HideMenu(PolynomActions, 0);


								system("pause");

								ClrScr();
								Show_Menu(PolynomActions);
							}
							if (PolynomActions.Item == 8)//P-9
							{
								GoToXY(0, 0);
								HideMenu(PolynomActions, 0);


								system("pause");

								ClrScr();
								Show_Menu(PolynomActions);
							}
							if (PolynomActions.Item == 9)//P-10
							{
								GoToXY(0, 0);
								HideMenu(PolynomActions, 0);


								system("pause");

								ClrScr();
								Show_Menu(PolynomActions);
							}
							if (PolynomActions.Item == 10)//P-11
							{
								GoToXY(0, 0);
								HideMenu(PolynomActions, 0);


								system("pause");

								ClrScr();
								Show_Menu(PolynomActions);
							}
							if (PolynomActions.Item == 11)//P-12
							{
								GoToXY(0, 0);
								HideMenu(PolynomActions, 0);


								system("pause");

								ClrScr();
								Show_Menu(PolynomActions);
							}
							if (PolynomActions.Item == 12)//P-13
							{
								GoToXY(0, 0);
								HideMenu(PolynomActions, 0);


								system("pause");

								ClrScr();
								Show_Menu(PolynomActions);
							}

							if (PolynomActions.Item == 13)//Назад
							{
								HideMenu(PolynomActions, 0);
								Show_Menu(Choice_Menu2);
							}
						} while (PolynomActions.Item != 13);
					}
					if (Choice_Menu2.Item == 3)//Назад
					{
						HideMenu(Choice_Menu2, 0);
						Show_Menu(StartMenu);
					}
				} while (Choice_Menu2.Item != 3);
		}
		//Справка
		if (StartMenu.Item == 4)
		{
			HideMenu(StartMenu, 0);
			GoToXY(0, 0);
			cout << "Справка" << endl;
			TextForeground(4);
			cout << "Программа не ведёт проверку корректности введённых данных. Перед выполнением задачи убедитесь, что числа введены верно.\n";
			TextForeground(15);
			cout << "Перед выполнением программы убедитесь, что числа выбранного типа были введены.\nПри вводе чисел, отличных от натуральных, указывайте знак явно!\nПримеры:\n123 - натуральное число\n+123 и -123 - положительное и отрицательное целые числа\n  " << endl;
			system("pause");
			ClrScr();
			Show_Menu(StartMenu);
		}
		//Выйти
		if (StartMenu.Item == 5)
		{
			ClrScr();
		}

	} while (StartMenu.Item != 5);
	return 0;
}


