#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Car
{
    static int const SIZE = 10;
    string id;
    string title;
    string color;
    string number;

   
    static void Print(Car arrCars)
    {
        if (arrCars.id == to_string(1))
        {
            cout.width(7);
            cout << "ID |" << " Название\t|" << " Цвет\t\t|" << " Номер\t\t|" << endl;
            for (int i = 0; i < 57; i++)
            {
                cout << "-";
            }
            cout << endl;
        }

        cout.width(5);
        cout << arrCars.id << " | ";
        cout << arrCars.title << "\t\t| ";
        cout << arrCars.color << "\t\t| ";
        cout << arrCars.number << "\t\t| ";
        cout << endl;
    }

   
    void EditCar()
    {
        cout << "Введите модель машины: "; cin >> title; cout << endl;
        this->title = title;
        cout << "Введите цвет машины: "; cin >> color; cout << endl;
        this->color = color;
        cout << "Введите номер: "; cin >> number; cout << endl;
        this->number = number;
    }

    
    void SearchForANumber(Car car[], string number)
    {
        bool flag = true;

        cout << "Машины с указанным номером:" << endl << endl;

        cout.width(7);
        cout << "ID |" << " Название\t|" << " Цвет\t\t|" << " Номер\t\t|" << endl;
        for (int i = 0; i < 57; i++)
        {
            cout << "-";
        }
        cout << endl;

        for (int i = 0; i < SIZE; i++)
        {
            if (car[i].number == number)
            {
                Print(car[i]);
                flag = false;
            }
        }

        if (flag)
        {
            cout << "Машины с указанным номером нет в базе." << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Car arrCar[Car::SIZE];
    Car cars;
    srand(time(0));

    bool yesNo = true;
    int numMenu = 0;
    int temp;
    string tempStr;

    
    for (int i = 0; i < Car::SIZE; i++)
    {
        arrCar[i].id = to_string(i + 1);
        arrCar[i].title = to_string(rand() % 10);
        arrCar[i].color = to_string(rand() % 10);
        arrCar[i].number = to_string(rand() % 10);
    }

    do
    {
        cout << "\t\tМЕНЮ" << endl;
        cout << "\t1. Печать всех машин; " << endl; 
        cout << "\t2. Редактирование машины; " << endl;
        cout << "\t3. Поиск машины по номеру; " << endl;
        cout << "\t4. Выход." << endl; cout << endl;

        cout << "\tВведите номер меню: "; cin >> numMenu; cout << endl;

        if (numMenu == 1)
        {
            for (Car number : arrCar)
            {
                Car::Print(number);
            }

            cout << endl;
            cout << "Нажми любую кнопку для возврата к меню.";
            system("pause>null");
            system("cls");
            continue;
        }
        if (numMenu == 2)
        {
            cout << "Машины в базе: " << endl;
            for (Car number : arrCar)
            {
                Car::Print(number);
            }
            cout << endl;

            cout << "Введите номер id машины для изменения: "; cin >> temp;

            if (temp > 0 || temp <= 10)
            {
                arrCar[temp - 1].EditCar();
            }
            else
            {
                cout << "Машины с таким Id нет в базе." << endl;
            }

            cout << endl;
            cout << "Нажми любую кнопку для возврата к меню.";
            system("pause>null");
            system("cls");
            continue;
        }
        if (numMenu == 3)
        {
            cout << "Введите номер для поиска: "; cin >> tempStr;

            cars.SearchForANumber(arrCar, tempStr);

            cout << endl;
            cout << "Нажми любую кнопку для возврата к меню.";
            system("pause>null");
            system("cls");
            continue;
        }
        if (numMenu == 4)
        {
            yesNo = false;
        }
    } while (yesNo);

    cout << endl << endl;
    system("pause>null");
}











enum Type { bird = 1, cattle, human }tp;
static int const SIZE = 2; 

union Characteristic
{
    double flightSpeed;
    bool artiodactyl;
    int iqLevel;
}ch[SIZE];

struct LivingEntity
{
private:
    string color = "";
    string type = "";
    double MovementSpeed = 0;
    int tempNum = 0;
    int count;
    bool flag = true;
public:
    
    void Create(int count)
    {
        do
        {
            cout << endl;
            cout << "Выберете тип 'Живой сущности': " << endl;
            cout << "1) Птица;" << endl;
            cout << "2) Скот;" << endl;
            cout << "3) Человек;" << endl << endl;
            cout << "Введите номер: "; cin >> tempNum; cout << endl;

            if (tempNum > 0 && tempNum < 4)
            {
                if (tempNum == bird)
                {
                    type = "bird";

                    cout << "Введите скорость птицы в км/ч: "; cin >> ch[count - 1].flightSpeed; cout << endl;
                    

                    if (ch[count - 1].flightSpeed > 200)
                    {
                        cout << "Вы ввели недопустимую скорость" << endl;
                        continue;
                    }
                    else
                    {
                        cout << "Введите цвет: "; cin >> color; cout << endl;

                        MovementSpeed = ch[count - 1].flightSpeed;
                        flag = false;
                    }
                }
                else if (tempNum == cattle)
                {
                    type = "cattle";

                    cout << "Введите 1-если парнокопытное или 0-если нет: "; cin >> tempNum; cout << endl;

                    if (tempNum == 0 || tempNum == 1)
                    {
                        ch[count - 1].artiodactyl = tempNum;

                        cout << "Введите цвет: "; cin >> color; cout << endl;

                        cout << "Введите скорость передвижения: "; cin >> MovementSpeed; cout << endl;
                        flag = false;
                    }
                    else
                    {
                        cout << "Вы ввели недопустимое значение" << endl;
                        continue;
                    }
                }
                else if (tempNum == human)
                {
                    type = "human";

                    cout << "Введите уровень IQ: "; cin >> ch[count - 1].iqLevel; cout << endl;
                    

                    if (ch[count - 1].iqLevel > 200 || ch[count - 1].iqLevel < 10)
                    {
                        cout << "Такого уровня IQ не существует. Введите iq от 10 до 200." << endl;
                        continue;
                    }
                    {
                        cout << "Введите цвет: "; cin >> color; cout << endl;

                        cout << "Введите скорость передвижения: "; cin >> MovementSpeed; cout << endl;
                        flag = false;
                    }
                }
            }
            else
            {
                cout << "Вы ввели неверный номер" << endl;
                continue;
            }
        } while (flag);
    }

   
    void Print(LivingEntity livingEntity, int id)
    {
        if (id == 1)
        {
            cout.width(7);
            cout << "ID\t\t|" << " Тип\t\t|" << " Цвет\t\t\t|" << " Характеристика\t|" << " Скорость передвижения\t|" << endl;
            for (int i = 0; i < 105; i++)
            {
                cout << "-";
            }
            cout << endl;
        }

        if (type == "bird")
        {
            cout.width(5);
            cout << id << "\t\t| ";
            cout << type << "\t\t| ";
            cout << livingEntity.color << "\t\t\t| ";
            cout << " " << "\t\t\t| ";
            cout << livingEntity.MovementSpeed << " км.ч" << "\t\t| ";
            cout << endl;
        }
        else if (type == "cattle")
        {
            cout.width(5);
            cout << id << "\t\t| ";
            cout << type << "\t| ";
            cout << livingEntity.color << "\t\t\t| ";

            if (ch[id - 1].artiodactyl)
            {
                cout << "Парнокопытное: да" << "\t| ";
            }
            else
            {
                cout << "Парнокопытное: нет" << "\t| ";
            }

            cout << livingEntity.MovementSpeed << " км.ч" << "\t\t| ";
            cout << endl;
        }
        else if (type == "human")
        {
            cout.width(5);
            cout << id << "\t\t| ";
            cout << type << "\t\t| ";
            cout << livingEntity.color << "\t\t\t| ";
            cout << "Уровень IQ: " << ch[id - 1].iqLevel << "\t| ";
            cout << livingEntity.MovementSpeed << " км.ч" << "\t\t| ";
            cout << endl;
        }
    }

   
    void EditLivingEntity(int temp)
    {
        Create(temp);
    }

    
    static void SearchLivingEntityCharacteristic(LivingEntity arrLivingEntity[], int temp)
    {
        string type;

        if (temp > 1)
        {
            cout.width(7);
            cout << "ID\t\t|" << " Тип\t\t|" << " Цвет\t\t|" << " Характеристика\t|" << " Скорость передвижения\t|" << endl;
            for (int i = 0; i < 97; i++)
            {
                cout << "-";
            }
            cout << endl;
        }

        if (temp < 0 || temp > 3)
        {
            cout << "Такой характеристики нет" << endl;
        }
        else
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (temp == 1)
                {
                    type = "bird";
                }
                else if (temp == 2)
                {
                    type = "cattle";
                }
                else if (temp == 3)
                {
                    type = "human";
                }

                if (arrLivingEntity[i].type == type)
                {
                    arrLivingEntity[i].Print(arrLivingEntity[i], i + 1);
                }
            }
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    LivingEntity arrLivingEntity[SIZE];
    bool yesNo = true;
    int numMenu = 0;
    int temp;

    

    cout << "\t Наполните массив сущьностями:" << endl;

    LivingEntity livingEntity1;
    livingEntity1.Create(1);
    LivingEntity livingEntity2;
    livingEntity2.Create(2);

    arrLivingEntity[0] = livingEntity1;
    arrLivingEntity[1] = livingEntity2;

    system("cls");

    do
    {
        cout << "\t\tМЕНЮ" << endl;
        cout << "\t1. Печать всех сущностей; " << endl;
        cout << "\t2. Редактирование сущностей; " << endl;
        cout << "\t3. Поиск по характеристике; " << endl;
        cout << "\t4. Выход." << endl; cout << endl;

        cout << "\tВведите номер меню: "; cin >> numMenu; cout << endl;

        if (numMenu == 1)
        {
            for (int i = 0; i < SIZE; i++)
            {
                arrLivingEntity[i].Print(arrLivingEntity[i], i + 1);
            }

            cout << endl;
            cout << "Нажми любую кнопку для возврата к меню.";
            system("pause>null");
            system("cls");
            continue;
        }
        if (numMenu == 2)
        {
            int temp = 0;

            cout << "Сущностей в базе: " << endl;
            for (int i = 0; i < SIZE; i++)
            {
                arrLivingEntity[i].Print(arrLivingEntity[i], i + 1);
            }
            cout << endl;

            cout << "Введите номер id сущьности для изменения: "; cin >> temp;

            if (temp > 0 && temp <= SIZE)
            {
                arrLivingEntity[temp - 1].EditLivingEntity(temp);
            }
            else
            {
                cout << "Сущьности с таким Id нет в базе." << endl;
            }

            cout << endl;
            cout << "Нажми любую кнопку для возврата к меню.";
            system("pause>null");
            system("cls");
            continue;
        }
        if (numMenu == 3)
        {
            cout << "Доступные характеристики" << endl << endl;
            cout << "1) Cкорость полета;" << endl;
            cout << "2) Парнокапытное;" << endl;
            cout << "3) Уровень IQ;" << endl << endl;

            cout << "Введите номер для поиска: "; cin >> temp;

            LivingEntity::SearchLivingEntityCharacteristic(arrLivingEntity, temp);

            cout << endl;
            cout << "Нажми любую кнопку для возврата к меню.";
            system("pause>null");
            system("cls");
            continue;
        }
        if (numMenu == 4)
        {
            yesNo = false;
        }
    } while (yesNo);

    cout << endl << endl;
    system("pause>null");
}