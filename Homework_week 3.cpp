// Homework_week 3.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include <iostream>
#include <iomanip>

int main()
/*
���������� ������� � ��������� ��� � ��������, �� ����� � ������� �������� ���. 
����������, ������ ����� ����� ���� ���������� ����� �� �����, ���� ������� ���� � 8 �����.
*/
{
    setlocale(LC_ALL, "Russian");
    int time;

    std::cout << "������� �����, ������� ������ � ������ �������� ���, � ��������\n";
    std::cin >> time;

    int h = time / 3600;
    int minsec = time % 3600;
    int min = minsec / 60;
    int sec = minsec % 60;

    int h_l = 7 - h;       // �������� ����� �� ����� 8-�������� ���. ���
    int min_l = 59 - min;  // �������� ����� �� ����� 8-�������� ���. ���
    int sec_l = 59 - sec;  // �������� ������ �� ����� 8-�������� ���. ���

    std::cout << "�� ����� �������� ��� �������� " << h_l << " �����, " << min_l << " �����, " << sec_l << " ������.";


    return 0;
}


int main4()
/*
���������� ������� � ��������� ��� � ��������, �� ����� � ������� ���. 
������� �� ����� �������� ��� � �������, �������� � ��������. 
����������, ������ �����, ������ � ������ ���������� �� ������.
*/
{
    setlocale(LC_ALL, "Russian");
    int time;

    std::cout << "������� �����, ������� ������ � ������ ���, � ��������\n";
    std::cin >> time;

    int h = time / 3600;
    int minsec = time % 3600;
    int min = minsec / 60;
    int sec = minsec % 60;

    int h_l = 23 - h;      // hours left to 00:00
    int min_l = 59 - min;  // minutes left to 00:00
    int sec_l = 59 - sec;  // secundes left to 00:00

    std::cout << "�� �������� �������� " << h_l << " �����, " << min_l << " �����, " << sec_l << " ������.";


    return 0;
}

int main3()
/*
 ���������� ������� � ��������� �������, ������� ������� �� 100 �� � ������� ����� ���� �������.
������� �� ����� ���������� ������� � ������� ������� �� ����� ����� ������.
*/
{
    setlocale(LC_ALL, "Russian");
    float distance;
    float cons; // consumption - ������
    float A92;
    float A95;
    float DP;

     

     std::cout << "������� ����������, ������ ������� �� 100 ��, � ���������\n"
         << "����������, �� => ";
     std::cin >> distance;
     std::cout << "\n������ ������� �� 100 ��, � => ";
     std::cin >> cons;
     std::cout << "\n��������� �92, ��� => ";
     std::cin >> A92;
     std::cout << "\n��������� �95, ��� => ";
     std::cin >> A95;
     std::cout << "\n��������� ��, ��� => ";
     std::cin >> DP;

     float a = ((cons * 100) / distance) * A92;  // ����������� a �� �92
     float b = ((cons * 100) / distance) * A95;  // ����������� b �� �95
     float c = ((cons * 100) / distance) * DP;   // ����������� c �� ��

     std::cout << std::endl << "��������� �������" << std::endl 
         << "A92 => " << a  << " ���." << std::endl << "A95 => " << b << " ���." << std::endl << "�� => " << c << " ���." << std::endl;

    return 0;
}

int main2()
/*
���������� ������� � ��������� ��� ������� � ��� ���������� ������������ ������� 
(������, ������� �� �������). 
���������� ������� �������, ���� ������� ������� � 2 �����.
*/
{
    setlocale(LC_ALL, "Russian");
    float h_s;      // hours at start
    float min_s;    // minutes at start
    float sec_s;    // seconds at start
    float h_end;    // hours on end
    float min_end;  // minutes on end
    float sec_end;  // seconds on end
    float ppm = 2;  // price per min
    float distance;
    float price;

    std::cout << "������� ����� ������ ����������� � ������� --> \n"
        << "����\n"
        << "������\n"
        << "�������\n";
    std::cin >> h_s >> min_s >> sec_s;
    std::cout << "������� ����� ��������� ����������� � ������� --> \n"
        << "����\n"
        << "������\n"
        << "�������\n";
    std::cin >> h_end >> min_end >> sec_end;
    distance = ((h_end - h_s) * 60) + (min_end - min_s) + ((sec_end - sec_s) / 60);
    price = distance * ppm;
    std::cout << "��������� ����������� = " << price << " ���.\n";

    return 0;
}

int main1()
/*
���������� ������� � ��������� ������� �� ��������� � ���, �� ���� ������� ������. 
��������� ��������, � ���� ���� ������� �����.
*/
{
    float dictance;
    float time;
    float speed;


    std::cout << "Enter distance, km\n";
        std::cin >> dictance;
        std::cout << "Enter time, hours\n";
        std::cin >> time;
    
    speed = dictance / time;
    std::cout << "Your speed should be " << speed << "km per hour.\n";

    return 0;
}

