#include"lab10.h"

CRectangle* rectangle = 0;
CTriangle* triangle = 0;
CEllipse* ellipse = 0;
void ClassesMenu() {
	UCHAR ch = 0;
	//CRectangle * rectangle = 0;
	do {
		CLEAR;
		ClearScreen();

		cout << " ���� ��� ���������� �������\n\n";
		cout << "1 - ������� ������ \n";
		cout << "2 - �������� �������� �������\n";
		cout << "3 - ���������� ��� �������\n";
		cout << "4 - ������ ������������� ������\n";
		cout << "esc - �����\n";

		ch = _getch();
		switch (ch) {
		case '1': cout << "\n1 - �������������\n";
			cout << "2 - �����������\n";
			cout << "3 - ������\n";
			ch = _getch();
			switch (ch) {
			case '1': rectangle = new CRectangle(100, 200, 50, 45, RGB(150, 92, 255), RGB(255, 255, 255));
				rectangle->Draw();
				cout << rectangle->GetName() << endl; 
				DELAY;
				break;
			case '2': triangle = new CTriangle(250, 300, 50, 50, RGB(45, 96, 211), RGB(255, 255, 0));
				triangle->Draw();
				break;	
			case '3': ellipse = new CEllipse(400, 500, 70, 50, RGB(45, 96, 211), RGB(0, 255, 0));
				ellipse->Draw();
				break;
			}
			ch = 0;
			break;
		case '2': ParamMenu(); break;
		case '3':ClearScreen();
			if (rectangle != 0) rectangle->Draw(); 
			if (triangle != 0) triangle->Draw();
			if (ellipse != 0) ellipse->Draw();
			DELAY;
			break;
		case '4': CFigure * gig = rectangle;
			if (gig == 0) {
				ClearScreen();
				for (int i = 1; i < 32; i++) {
					SetColor(0, i);
					point(5, 10);
					cout << "!!!!!  ��������� = NULL. ������ �� ������  !!!!!";
					Sleep(100);
				}
				break;
			}
			cout << "��������� ������ �� ��������. \n";
			cout << "X=" << gig->Left() << "  Y =" << gig->Top() << endl;
			cout << "Width=" << gig->Width() << "  Height" << gig->Height() << endl;
			cout << "X2=" << gig->Right() << "  Y2=" << gig->Bottom() << endl;
			cout << "BrushColor="  << gig->BrushColor() << "  PenColor=" << gig->PenColor() << endl;
			//CID* cid = rectangle;
			gig->SetId(15);
			cout << "Id = " << gig->GetId() << endl;
			cout << "Name = " << gig->GetName() << endl;
			cout << "������" << endl;
			gig->Draw();
			DELAY;
			break;
		}
	} while (ch != 27);
}

void ParamMenu() {
	UCHAR ch = 0;
	int val = 0;
	
	do {
		CLEAR;

		cout << " ���� ��� ��������� ������� �������\n\n";
		cout << "1 - �������������� �������\n";
		cout << "2 - ������� �������\n";
		cout << "3 - ����� ������� �������\n";
		cout << "esc - �����\n";

		ch = _getch();
		switch (ch) {
		case '1': 
			cout << "������� 0, ���� �������� ��������!!!\n\n";
			cout << "������� ���������� X (" << rectangle->X() << ") "; cin >> val;
			if (val > 0) rectangle->X(val);
			cout << "������� ���������� Y (" << rectangle->Y() << ") "; cin >> val;
			if (val > 0) rectangle->Y(val);
			break;
		case '2':  
			cout << "������� 0, ���� �������� ��������!!!\n\n";
			cout << "������� ������(" << rectangle->Width() << ") "; cin >> val;
			if (val > 0) rectangle->Width(val);
			cout << "������� ������(" << rectangle->Height() << ") "; cin >> val;
			if (val > 0) rectangle->Height(val);
			break;
		case '3': 
			cout << "������� -1, ���� �������� ��������!!!\n\n";
			cout << "������� ���� ����(" << rectangle->BrushColor() << ") "; cin >> val;
			if (val > 0) rectangle->BrushColor(val);
			cout << "������� ���� �������(" << rectangle->Height() << ") "; cin >> val;
			if (val > 0) rectangle->PenColor(val);break;
			if (rectangle != 0) rectangle->Draw();
			break;
		}
	} while (ch != 27);
}

void lab10() {

}