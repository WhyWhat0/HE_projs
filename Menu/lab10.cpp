#include"lab10.h"

//CRectangle* rectangle = 0;
//CTriangle* triangle = 0;
//CEllipse* ellipse = 0;
CFigure* GetFigure(CManager& manager) {
	int id = 0;
	cout << "Укажите идентификатор объекта==>"; cin >> id;
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

		cout << " Меню для реализации классов\n\n";
		cout << "1 - Создать объект \n";
		cout << "2 - Изменить свойства объекта\n";
		cout << "3 - Нарисовать объекты\n";
		cout << "4 - Модель родительского класса\n";
		cout << "5 - Соединить линией\n";
		cout << "esc - Назад\n";

		ch = _getch();
		switch (ch) {
		case '1': cout << "\n1 - прямоугольник\n";
			cout << "2 - треугольник\n";
			cout << "3 - эллипс\n";
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
			cout << "1 - Отобразить все фигуры\n";
			cout << "2 - Отобразить фигуру по идентификатору\n";
			cout << "3 - Отобразить фигуру класса\n";
			cout << "4 - Отобразить соединенные фигуры\n";
			ch = _getch();
			ClearScreen();
			switch (ch) {
			case '1': manager.Draw(); break;
			case '2':hig = GetFigure(manager);
				if (hig == NULL) {
					cout << "Объект по идентификатору не найден\n"; DELAY;
					break;
				}
				hig->Draw();
				break;
			case '3':
				cout << "Введите наименование класса ==> "; cin >> sclass;
				manager.Draw(sclass);
				break;
			case '4': manager.DrawGraph();
				DELAY;
				break;
			}
			DELAY;
			break;
		case '5': {
			cout << "Введите идентификатор первой фигуры => "; cin >> id;
			hig = manager.GetFigure(id);
			cout << "\nВведите идентификатор второй фигуры => "; cin >> id;
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
					cout << "!!!!!  Указатель = NULL. ОБЪЕКТ НЕ СОЗДАН  !!!!!";
					Sleep(100);
				}
				break;
			}
			cout << "Параметры класса от родителя. \n";
			cout << "X=" << gig->Left() << "  Y =" << gig->Top() << endl;
			cout << "Width=" << gig->Width() << "  Height" << gig->Height() << endl;
			cout << "X2=" << gig->Right() << "  Y2=" << gig->Bottom() << endl;
			cout << "BrushColor="  << gig->BrushColor() << "  PenColor=" << gig->PenColor() << endl;
			//CID* cid = rectangle;
			gig->SetId(15);
			cout << "Id = " << gig->GetId() << endl;
			cout << "Name = " << gig->GetName() << endl;
			cout << "Фигура" << endl;
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

		cout << " Меню для изсенения классов классов\n\n";
		cout << "1 - Местоположение объекта\n";
		cout << "2 - Размеры объекта\n";
		cout << "3 - Цвета заливки объекта\n";
		cout << "esc - Назад\n";

		ch = _getch();
		switch (ch) {
		case '1': 
			gig = GetFigure(pmanager);
			if (gig == NULL) {
				cout << "ЭТО ФИАСКО! ID НЕ НАЙДЕН!!!";
				break;
			}
			cout << "Введите 0, если параметр меняется!!!\n\n";
			cout << "Введите координату X (" << gig->X() << ") "; cin >> val;
			if (val > 0) gig->X(val);
			cout << "Введите координату Y (" << gig->Y() << ") "; cin >> val;
			if (val > 0) gig->Y(val);
			break;
		case '2':  
			gig = GetFigure(pmanager);
			if (gig == NULL) {
				cout << "ЭТО ФИАСКО! ID НЕ НАЙДЕН!!!";
				break;
			}
			cout << "Введите 0, если параметр меняется!!!\n\n";
			cout << "Введите ширину(" << gig->Width() << ") "; cin >> val;
			if (val > 0) gig->Width(val);
			cout << "Введите высоту(" << gig->Height() << ") "; cin >> val;
			if (val > 0) gig->Height(val);
			break;
		case '3': 
			gig = GetFigure(pmanager);
			if (gig == NULL) {
				cout << "ЭТО ФИАСКО! ID НЕ НАЙДЕН!!!";
				break;
			}
			cout << "Введите -1, если параметр меняется!!!\n\n";
			cout << "Введите цвет фона(" << gig->BrushColor() << ") "; cin >> val;
			if (val > 0) gig->BrushColor(val);
			cout << "Введите цвет контура(" << gig->Height() << ") "; cin >> val;
			if (val > 0)gig->PenColor(val);break;
			if (gig != 0) gig->Draw();
			break;
		}
	} while (ch != 27);
}

