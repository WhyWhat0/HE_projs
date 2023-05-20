#include"lab10.h"

//CRectangle* rectangle = 0;
//CTriangle* triangle = 0;
//CEllipse* ellipse = 0;
CFigure* GetFigure(CManager& manager) {
	int id = 0;
	cout << "������� ������������� �������==>"; cin >> id;
	return manager.GetFigure(id);
}
void ClassesMenu() {
	int id = 0;
	CManager manager;
	CFigure* hig = 0, * dig = 0;
	UCHAR ch = 0;
	string sclass{};

	//CRectangle * rectangle = 0;
	do {
		CLEAR;
		ClearScreen();

		cout << " ���� ��� ���������� �������\n\n";
		cout << "1 - ������� ������ \n";
		cout << "2 - �������� �������� �������\n";
		cout << "3 - ���������� �������\n";
		cout << "4 - ������ ������������� ������\n";
		cout << "5 - ��������� ������\n";
		cout << "esc - �����\n";

		ch = _getch();
		switch (ch) {
		case '1': cout << "\n1 - �������������\n";
			cout << "2 - �����������\n";
			cout << "3 - ������\n";
			ch = _getch();
			switch (ch) {
			case '1': hig = new CRectangle(100, 200, 50, 45, RGB(150, 92, 255), RGB(255, 255, 255));
				manager.AddFigure(hig);
				hig->SetId(manager.Count());
				hig->Draw();
				cout << hig->GetName() << endl;
				DELAY;
				break;
			case '2': hig = new CTriangle(250, 300, 50, 50, RGB(45, 96, 211), RGB(255, 255, 0));
				manager.AddFigure(hig);
				hig->SetId(manager.Count());
				hig->Draw();
				cout << hig->GetName() << endl;
				DELAY;
				break;
			case '3': hig = new CEllipse(400, 500, 70, 50, RGB(45, 96, 211), RGB(0, 255, 0));
				manager.AddFigure(hig);
				hig->SetId(manager.Count());
				hig->Draw();
				cout << hig->GetName() << endl;
				DELAY;
				break;
			}
			ch = 0;
			break;
		case '2': ParamMenu(manager); break;
		case '3':ClearScreen();
			cout << "1 - ���������� ��� ������\n";
			cout << "2 - ���������� ������ �� ��������������\n";
			cout << "3 - ���������� ������ ������\n";
			cout << "4 - ���������� ����������� ������\n";
			ch = _getch();
			ClearScreen();
			switch (ch) {
			case '1': manager.Draw(); break;
			case '2':hig = GetFigure(manager);
				if (hig == NULL) {
					cout << "������ �� �������������� �� ������\n"; DELAY;
					break;
				}
				hig->Draw();
				break;
			case '3':
				cout << "������� ������������ ������ ==> "; cin >> sclass;
				manager.Draw(sclass);
				break;
			case '4': manager.DrawGraph();
				DELAY;
				break;
			}
			DELAY;
			break;
		case '5': {
			cout << "������� ������������� ������ ������ => "; cin >> id;
			hig = manager.GetFigure(id);
			cout << "\n������� ������������� ������ ������ => "; cin >> id;
			dig = manager.GetFigure(id);
			manager.AddUnion(hig, dig);
			manager.DrawGraph();

		}break;
		case '4':
			CFigure* gig = GetFigure(manager);
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

void ParamMenu(CManager& pmanager) {
	UCHAR ch = 0;
	int val = 0;
	CFigure* gig = 0;
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
			gig = GetFigure(pmanager);
			if (gig == NULL) {
				cout << "��� ������! ID �� ������!!!";
				break;
			}
			cout << "������� 0, ���� �������� ��������!!!\n\n";
			cout << "������� ���������� X (" << gig->X() << ") "; cin >> val;
			if (val > 0) gig->X(val);
			cout << "������� ���������� Y (" << gig->Y() << ") "; cin >> val;
			if (val > 0) gig->Y(val);
			break;
		case '2':  
			gig = GetFigure(pmanager);
			if (gig == NULL) {
				cout << "��� ������! ID �� ������!!!";
				break;
			}
			cout << "������� 0, ���� �������� ��������!!!\n\n";
			cout << "������� ������(" << gig->Width() << ") "; cin >> val;
			if (val > 0) gig->Width(val);
			cout << "������� ������(" << gig->Height() << ") "; cin >> val;
			if (val > 0) gig->Height(val);
			break;
		case '3': 
			gig = GetFigure(pmanager);
			if (gig == NULL) {
				cout << "��� ������! ID �� ������!!!";
				break;
			}
			cout << "������� -1, ���� �������� ��������!!!\n\n";
			cout << "������� ���� ����(" << gig->BrushColor() << ") "; cin >> val;
			if (val > 0) gig->BrushColor(val);
			cout << "������� ���� �������(" << gig->Height() << ") "; cin >> val;
			if (val > 0)gig->PenColor(val);break;
			if (gig != 0) gig->Draw();
			break;
		}
	} while (ch != 27);
}

