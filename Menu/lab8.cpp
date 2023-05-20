#include "lab8.h"

CODEMODEL nCode = CD_Cesar;
char TextCode[128]{ "Скотт Тревор"},
TextCording[128]{ 0 };
int Limit = 1;
void CordingMenu() {
	UCHAR ch = 0;
	do {
		CLEAR;
		SetColor(CL_BLACK, CL_LIGHT_YELLOW);
		cout << " Меню Кодирования Текста \n\n";
		SetColor(0, 15);
		cout<< "1 - Метод \"Цезаря\"\n";
		cout<< "2 - Динамическое кодирование\n";
		cout<< "3 - Битовое смещение\n";
		cout<< "4 - Декодирование\n";
		cout<< "5 - Определить строку кодирования\n";
		cout<< "6 - Отобразить текст для шифрования\n";
		cout<< "7 - Отобразить шифрованный текст\n";
		cout<< "8 - Подготовить строку для битового кодирования\n\n";
		cout<< "Для выхода из программы нажмите ESC";


		ch = _getch();

		switch (ch) {
		case '1':Cording(); break;
		case '2':DinCording(); break;
		case '3':BitCording(); break;
		case '4':DeCording(); break;
		case '5':
			CLEAR;
			SetColor(CL_BLACK, CL_LIGHT_RED);
			cout << "Введите текст для Шифрования\n=>";
			SetColor(0, 15);
			cin.getline(TextCode, 128); break;
			SetColor(CL_BLACK, CL_LIGHT_RED);
		case '6': CLEAR; cout << "Текст для шифрования\n=>" << TextCode << endl; PAUSE; break;
			SetColor(0, 15);

		case '7': CLEAR; SetColor(CL_BLACK, CL_LIGHT_RED); cout << "Текст после шифрования\n=>" << TextCording << endl; PAUSE;break;
		case '8':strcpy_s(TextCording, 128, TextCode); break;
		}
	} while (ch != 27);
}

void Cording() {
	nCode = CD_Cesar;
	TextCording[0] = 0;
	CLEAR;

	SetColor(CL_BLACK, CL_LIGHT_PURPLE);
	cout << "Кодирование текста методом \"Цезаря\"\n\n";
	SetColor(0, 15);
	cout << "Текст для шифрования =>" << TextCode << endl;
	cout << "На сколько символов смещать шифр?\n=>"; cin >> Limit;

	for (int i = 0; i < strlen(TextCode); i++) {
		UCHAR ch = TextCode[i], cch = 0;
		UCHAR bc = 'А', ec = 'я', chE = 'Ё', che = 'ё';
		if (ch >= bc && ch <= ec) {
			cch = bc + (ch + Limit - bc) % (ec - bc + 1);
			TextCording[i] = cch;
		}
		else if (ch == chE) {
			TextCording[i] = '#';
		}
		else if (ch == che) {
			TextCording[i] = '*';
		}
		else /*if (ch == ' ')*/ TextCording[i] = ch;
	}
	TextCording[strlen(TextCode)] = 0;
	SetColor(CL_BLACK, CL_LIGHT_YELLOW);
	cout << endl << "Текст после шифрования: " << TextCording << endl;	DELAY;
	SetColor(0, 15);
}

void DinCording() {
	nCode = CD_Dinamic;
	TextCording[0] = 0;

	CLEAR;
	SetColor(CL_BLACK, CL_LIGHT_PURPLE);
	cout << "Кодирование текста методом \"Цезаря с динамическим смещением\"\n\n";
	SetColor(0, 15);
	cout << "Текст для шифрования =>" << TextCode << endl;


	for (int i = 0; i < strlen(TextCode); i++) {
		UCHAR ch = TextCode[i], cch = 0;
		UCHAR bbc = 'A', eec = 'z';
		UCHAR bc = 'А', ec = 'я', chE = 'Ё', che = 'ё';
		if (ch >= bc && ch <= ec) {
			Limit = i + 1;
			cch = bc + (ch + Limit - bc) % (ec - bc + 1);
			TextCording[i] = cch;
		}
		else if (ch == chE) {
			TextCording[i] = '#';
		}
		else if (ch == che) {
			TextCording[i] = '*';
		}
		else if (ch >= bbc && ch <= eec) {
			Limit = i + 1;
			cch = bbc + (ch + Limit - bbc) % (eec - bbc + 1);
			TextCording[i] = cch;
		}
		else TextCording[i] = ch;
	}
	TextCording[strlen(TextCode)] = 0;
	SetColor(CL_BLACK, CL_LIGHT_YELLOW);
	cout << endl << "Текст после шифрования: " << TextCording << endl;	DELAY;
	SetColor(0, 15);

}

void BitCording(bool pToLeft) {
	nCode = CD_Bit;


	CLEAR;
	int nLen = strlen(TextCording);
	UCHAR sbit = 0;
	switch (pToLeft) {
	case true:
		sbit = TextCording[0] & 0x80;
		for (int i = 0; i < nLen - 1; i++) {
			TextCording[i] <<= 1;
			TextCording[i] |= ((UCHAR)TextCording[i + 1] & 0x80) >> 7;
		}
		TextCording[nLen - 1] <<= 1;
		TextCording[nLen - 1] |= sbit >> 7;
		break;
	case false:
		sbit = TextCording[nLen - 1] & 0x01;
		for (int i = nLen - 1; i > 0; i--) {
			TextCording[i] = (UCHAR)TextCording[i] >> 1;
			TextCording[i] |= (TextCording[i - 1] & 0x01) << 7;
		}
		TextCording[0] = (UCHAR)TextCording[0] >> 1;
		TextCording[0] |= sbit << 7;
		break;
	}
	cout << "Результат кодирования или декодирования =>" << TextCording << endl << endl;
	PAUSE;
}

void DeCording() {
	CLEAR;
	SetColor(CL_BLACK, CL_LIGHT_RED);
	cout << "Строка до декодирования: " << TextCording << endl << endl;
	SetColor(0, 15);
	switch (nCode) {
	case CD_Cesar:
		for (int i = 0; i < strlen(TextCording); i++) {
			UCHAR ch = TextCording[i], cch = 0;
			UCHAR bc = 'А', ec = 'я', chE = 'Ё', che = 'ё';
			if (ch >= bc && ch <= ec) {
				cch = (ch - Limit < bc) ? ec - (bc - (ch - Limit + 1)) : ch - Limit;
				TextCording[i] = cch;
			}
			else if (ch == '#') {
				TextCording[i] = chE;
			}
			else if (ch == '*') {
				TextCording[i] = che;
			}
			else /*if (ch == ' ')*/ TextCording[i] = ch;
		}break;
	case CD_Dinamic:
		for (int i = 0; i < strlen(TextCording); i++) {
			UCHAR ch = TextCording[i], cch = 0;
			UCHAR bc = 'А', ec = 'я', chE = 'Ё', che = 'ё';
			if (ch >= bc && ch <= ec) {
				Limit = i + 1;
				cch = (ch - Limit < bc) ? ec - (bc - (ch - Limit + 1)) : ch - Limit;
				TextCording[i] = cch;
			}
			else if (ch == '#') {
				TextCording[i] = chE;
			}
			else if (ch == '*') {
				TextCording[i] = che;
			}
			else /*if (ch == ' ')*/ TextCording[i] = ch;
		}
		break;
	case CD_Bit:
		BitCording(false);
		break;
	}
	if (nCode != CD_Bit) {
		SetColor(CL_BLACK, CL_LIGHT_YELLOW);
			cout << "Строка после декодирования: " << TextCording;
			SetColor(0, 15);
			PAUSE;
	}
}