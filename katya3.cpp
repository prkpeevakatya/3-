/*
Создайте приложение «Список дел».
Приложение должно позволять:
■ Добавление дел. У дела есть:
• название;
• приоритет;
• описание;
• дата, время исполнения.

■ Удаление дел.

■ Редактирование дел.

■ Поиск дел по:
• названию;
• приоритету;
• описанию;
• дате и времени исполнения.

■ Отображение списка дел:
• на день;
• на неделю;
• на месяц.

■ При отображении должна быть возможность сортировки:
• по приоритету;
• по дате и времени исполнения.*/



//код

#include <iostream>
#include <fstream>
#include <windows.h> 
#include<string>
using namespace std;

struct muz
{
    string name;
    int prior;
    string opis;
    int data;
};

//int op = 0;
int kol = 1;

void vvod(int kol, muz* mass)
{
    kol++;

    muz* mass2 = new muz[kol];

    for (int u = 0; u < kol - 1; u++) {
        mass2[u].name = mass[u].name;
        mass2[u].prior = mass[u].prior;
        mass2[u].opis = mass[u].opis;
        mass2[u].data = mass[u].data;
    }

    cout << "vvedite nazvanie dela: ";
    cin >> mass2[kol - 1].name;
    cout << endl;
    for (;;) {
        cout << "vvedite prioritet dela (from 1 to 10):";
        cin >> mass2[kol - 1].prior;
        if (mass2[kol - 1].prior < 1 or mass2[kol - 1].prior > 10) {
            cout << "vi nepravilno vvveli chislo, poprobuite eche))" << endl;
        }
        else {
            cout << endl;
            break;
        }
    }
    cout << "vvedite opisanie dela: ";
    cin >> mass2[kol - 1].opis;
    cout << endl;
    cout << "vvedite datu dela ( day, mecyac, god bez probelov (151206)) ";
    cin >> mass2[kol - 1].data;
    cout << endl;

    delete[]  mass;

    mass = mass2;
}




void izmenu(int kol, muz* mass)
{

    for (;;) {
        string f;
        int ox;
        cout << "vvvedite to, chto xotite izmenit (name, prior, opis, data) ";
        cin >> f;
        if (f == "name") {
            cout << "vvedite kakoe po chety delo vi xotite izmenit - " << endl;
            cin >> ox;
            cout << "vvedite novoe imya dela - " << endl;
            cin >> mass[ox-1].name;
            break;
        }
        else if (f == "prior") {
            cout << "vvedite kakoe po chety delo vi xotite izmenit - " << endl;
            cin >> ox;
            cout << "vvedite novii prioritet dela - " << endl;
            cin >> mass[ox-1].prior;
            break;
        }
        else if (f == "opis") {
            cout << "vvedite kakoe po chety delo vi xotite izmenit - " << endl;
            cin >> ox;
            cout << "vvedite novoe opisanie dela - " << endl;
            cin >> mass[ox-1].opis;
            break;
        }
        else if (f == "data") {
            cout << "vvedite kakoe po chety delo vi xotite izmenit - " << endl;
            cin >> ox;
            cout << "vvedite novuyu datu dela - " << endl;
            cin >> mass[ox-1].data;
            break;
        }
        else {
            cout << endl << "vi nepravilno napisali.. povtorite eche raz)" << endl;
        }
    }
}





void udalenie(int kol, muz* mass)  //вопросы..
{
    int lol;
    int ho;
    for (;;) {
        cout << "vvedite nomer dela, kotoroe nado ydalit - ";
        cin >> ho;
        if (ho > kol) {
            cout << endl << "vi nepravilno vveli nomer, poprobuite eshe raz))" << endl;
        }
        else if (ho < kol) {
            cout << endl << "vi nepravilno vveli nomer, poprobuite eshe raz))" << endl;
        }
        else {
            break;
        }
    }

    for (;;) {
        cout << "if ti yveren - vvedi 1, esli oshibsya - vvedi 2 :  ";
        cin >> lol;

        if (lol == 1) {
            delete mass;
            break;
        }


        else if (lol == 2) {
            cout << endl << "okay !" << endl;
            break;
        }
        else {
            cout << "vi oshiblis, vvedite eshe raz)" << endl;
        }
    }
}



void poisk(int kol, muz* mass)
{
    string cool;
    cout << "POISK" << endl;
    for (;;) {
        cout << "what do you want(name, prior, opis or data)?" << endl;
        cin >> cool;
        //имя
        if (cool == "name") {
            string you;
            cout << "enter nazvanie dela - ";
            cin >> you;
            cout << endl;
            for (int i = 0; i < kol; i++) {
                if (mass[i].name == you) {
                    cout << mass[i].name;
                    cout << endl << mass[i].prior;
                    cout << endl << mass[i].opis;
                    cout << endl << mass[i].data;
                }
                else {
                    cout << "net takix del !!! " << endl;
                }
            }
            break;
        }
        //приоритет
        else if (cool == "prior") {
            int she;
            cout << "enter prioritet dela - ";
            cin >> she;
            cout << endl;
            for (int i = 0; i < kol; i++) {
                if (mass[i].prior == she) {
                    cout << mass[i].name;
                    cout << endl << mass[i].prior;
                    cout << endl << mass[i].opis;
                    cout << endl << mass[i].data;
                }
                else {
                    cout << "net takix del !!! " << endl;
                }
            }
            break;
        }
        //описаие
        else if (cool == "opis") {
            string he;
            cout << "enter opisanie dela - ";
            cin >> he;
            cout << endl;
            for (int i = 0; i < kol; i++) {
                if (mass[i].opis == he) {
                    cout << mass[i].name;
                    cout << endl << mass[i].prior;
                    cout << endl << mass[i].opis;
                    cout << endl << mass[i].data;
                }
                else {
                    cout << "net takix del !!! " << endl;
                }
            }
            break;
        }
        //дата
        else if (cool == "data") {
            int it;
            cout << "enter data dela - ";
            cin >> it;
            cout << endl;
            for (int i = 0; i < kol; i++) {
                if (mass[i].data == it) {
                    cout << mass[i].name;
                    cout << endl << mass[i].prior;
                    cout << endl << mass[i].opis;
                    cout << endl << mass[i].data;
                }
                else {
                    cout << "net takix del !!! " << endl;
                }
            }
            break;
        }
        else {
            cout << "vi nepravilno napisali, poprobuite eche raz))" << endl;
        }
    }
}


void pokazdel(int kol, muz* mass)
{
    int za;
    for (;;) {
        cout << "what do you want??"<<endl<<"pokaz del(1) ili poisk po date(2) / prioritety(3) vvedite chislo - ";
        cin >> za;
        if (za == 1) {
            for (int po = 0; po < kol; po++) {
                cout << po + 1 << ". name - " << mass[po].name;
                cout << endl << "- prioritet - " << mass[po].prior;
                cout << endl << "- opisanie - " << mass[po].opis;
                cout << endl << "- data - " << mass[po].data;
            }
        }
        else if (za == 2) {
            int fof;
            cout << "vvedite zhelaemuyu datu - ";
            cin >> fof;
            for (int i = 0; i < kol; i++) {
                if (mass[i].data == fof) {
                    cout << mass[i].name;
                    cout << endl << mass[i].prior;
                    cout << endl << mass[i].opis;
                    cout << endl << mass[i].data;
                }
            }
            break;
        }
        else if (za == 3) {
            int fuf;
            cout << "vvedite zhelaemui prioritet - ";
            cin >> fuf;
            for (int i = 0; i < kol; i++) {
                if (mass[i].prior == fuf) {
                    cout << mass[i].name;
                    cout << endl << mass[i].prior;
                    cout << endl << mass[i].opis;
                    cout << endl << mass[i].data;
                }
            }
            break;
        }
        else {
            cout << "vi neprsvilno vveli chislo.. povtorite esho raz)" << endl;
        }
    }
}


int main()
{
    
    muz* mass = new muz[kol];

    vvod(kol, mass);



    int vib;
    for (;;) {
        cout << "---MENU---" << endl;
        cout << "1 - dobavit delo" << endl;
        cout << "2 - ydalit delo" << endl;
        cout << "3 - redactirovat delo" << endl;
        cout << "4 - poisk dela" << endl;
        cout << "5 - pokazat dela" << endl;
        cout << "6 - zakrit spisok" << endl;
        cin >> vib;

        if (vib == 1) {
            vvod(kol, mass);
        }
        else if (vib == 2) {
            udalenie(kol, mass);
        }
        else if (vib == 3) {
            izmenu(kol, mass);
        }
        else if (vib == 4) {
            poisk(kol, mass);
        }
        else if (vib == 5) {
            pokazdel(kol, mass);
        }
        else if (vib == 6) {
            break;
        }
        else {
            cout << "vi nepravilno vveli chislo.. povtorite eche raz !" << endl;
        }
    }
}
