// Homework 2.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>






int main14()
/*
���������� ������� � ��������� ��� � ��������. 
��������� �������� ��������, ��� �������� ������ ������������ ������� � ������, �������, ������� � �������� �� �� �����.
*/
{
    int time;

    std::cout << "Enter the time (in seconds):\n";
    std::cin >> time;
    int h = time / 3600;
    int minsec = time % 3600;
    int min = minsec / 60;
    int sec = minsec % 60;

    std::cout << h << " hours " << min << " minutes " << sec << " seconds\n";

    return 0;
}

int main13()
/*
����� ��� ����� R1, R2, R3. ���������
�������� ����� R0 �� ��������: 1/R0 = 1/R1+1/R2+1/R3.
����������� �������: R1=2, R2=4, R3=8 R0 = 1.142857.
*/
{
    float R1;
    float R2;
    float R3;
    float R0;

    std::cout << "Enter R1\n" << "Enter R2\n" << "Enter R3\n";
    std::cin >> R1 >> R2 >> R3;
    R0 = 1 / (1 / R1 + 1 / R2 + 1 / R3);
    std::cout << "R0 = " << R0;

    return 0;
}

int main()

// �������� ���������, ������� ��������� ����� ����.

{
    setlocale(LC_ALL, "Russian");
    float r;
    float v;

    
    std::cout << "���������� ������ ����.\n" << "������� ������\n";
    std::cin >> r;
    v = 4/3 * M_PI * pow (r,3);      // �� ���������� �������, �� ��������
    std::cout << "����� ���� = " << v << " .";

    return 0;
}


int main11()
/*
�������� ��������� ���������� ���������� ����� ����������� ��������, ������������� �� �����. 
���� �������� ������������� ��� ������ �� ����� ���������� ���������.
���������� ���������� ����� ����������� ��������
������� �������� ������:
������� ����� (���������� ���������� � ����� ����������) -> 120.
���������� ����� �������, ������������� ���������� ������ (��) -> 3.5.
���������� ����� ����������� �������� 420 ��.
*/
{ 
    setlocale(LC_ALL, "Russian");

    float x;
    float y;
    float z;

    std::cout << "���������� ���������� ����� ����������� ��������\n"
        << "������� �������� ������:\n"
        << "������� ����� (���������� ���������� � ����� ����������) -> ";
    std::cin >> x;
    std::cout << "���������� ����� �������, ������������� ���������� ������ (��) -> ";
    std::cin >> y;
    z = x * y;
    std::cout << "���������� ����� ����������� �������� " << z << " ��.\n";

    return 0;
}

int main10()
/*
 �������� ��������� ���������� ������ ���������������. ���� �������� ������������� ��� ������
�� ����� ���������� ���������.
���������� ������ ���������������.
������� �������� ������:

����� (��) -> 9;
������ (��) -> 7.5;
������ (��) -> 5;
�����: 337.50 ���. ��.
*/
{
    setlocale(LC_ALL, "Russian");

    float l;
    float w;
    float h;
    float v;

        std::cout << "����� ���������������\n" << "������� ����� � ��\n";
        std::cin >> l;
        std::cout << "������� ������ � ��\n";
        std::cin >> w;
        std::cout << "������� ������ � ��\n";
        std::cin >> h;
        v = l * w * h;
        std::cout << "�����: " << v << " ���.��.\n";

    return 0;
}

int main9()
/*
������������ ������ � ���������� ��������
����� � ������� � �������� (������ � ������� ��������
� ������ ����������). ����� ����� ���� ������� ���
��������� (�������� 19 ���. 90 ���), ��� � �����������
(�������� 22 ���. 978 ���). �������� ���������, �������,
��������� ������ �������� ��������, ���������� ������������� ��������� �������� ����� � ���������� �����.
��������, ���� ������������ ���� 11 ���. 150 ���,
��������� ������ ������� �� ����� ����� 12 ���. 50 ���.
*/
{
    int hrn;
    int kop;
    int h;
    int k;

    std::cout << "Enter hryvnia\n";
    std::cin >> hrn;
    std::cout << "Enter kop.\n";
    std::cin >> kop;

    h = hrn + (kop / 100);
    k = kop % 100;

    std::cout << h << " hrn. " << k << " kop. ";

    return 0;
}



int main7()
{
/*
������������ ������ ���. ���������� �������� ���������, ������� ������� ���������� ���� � ���� 
����. ��� ��������� ��������� ������������ �������� 
�������� (����������� ��������� ������ �� ������������). ��������, ������������ ���� ��� 2004, ��������� 
��������, ��� � ���� ���� 366 ���� � ��������� �����:
In 2004 year = 366 days
*/
    int year = 2004;
    int day = 366;
    
    std::cout << "Enter current year, please.\n";
    std::cin >> year;
    std::cout << "In " << year << " = " << day << " days.\n";

    return 0;

}

int main8()
/*
���������� ������, ������ � ��������. ��� ������� ��� ��� �������, ���������� ��� ��� ���????
*/
{
    int year;

    std::cout << "Enter current year, please.\n";
    std::cin >> year;
    if (year % 4 == 0 && year % 100 != 0
        || year % 400 == 0)
        std::cout << "In " << year << " = 366 days.\n";
    else 
        std::cout << "In " << year << " = 365 days.\n";

    return 0;
}

int main6()
/*
������� ����������, ������� ������� �� ����� ��������� �������:

*/
{
    char hz = (char)205;   // horizontal line
    char vr = (char)186;   // vertical line
    char trc = (char)187;  // top right corner
    char tlc = (char)201;  // top left corner
    char brc = (char)188;  // bottom right corner
    char blc = (char)200;  // bottom left corner
    char hd = (char)203;   // horizontal and down
    char hu = (char)202;   // horizontal and up
    char hr = (char)204;   // horizontal and right
    char hl = (char)185;   // horizontal and left

    std::cout << tlc << hz << hz << hz << hz << hz << hz << hz << hz << hz
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hz
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hz
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << trc
        << std::endl
        << std::endl
        << vr
        << std::setw(20) << "Pory roku"
        << std::setw(19)
        << vr
        << std::endl
        << std::endl
        << hr << hz << hz << hz << hz << hz << hz << hz << hz << hd
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hd
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hd
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hl
        << std::endl
        << std::endl
        << vr
        << std::setw(6) << "Zyma"
        << std::setw(3)
        << vr
        << std::setw(7) << "Vesna"
        << std::setw(3)
        << vr
        << std::setw(6) << "Lito"
        << std::setw(4)
        << vr
        << std::setw(7) << "Osin\'"
        << std::setw(3)
        << vr
        << std::endl
        << std::endl
        << blc << hz << hz << hz << hz << hz << hz << hz << hz << hu
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hu
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << hu
        << hz << hz << hz << hz << hz << hz << hz << hz << hz << brc
        << std::endl;

    return 0;

}

int main5()
/*
 ������� ����������, ������� ������� ��
������� �����:
�U lukomor�a dub zelenij,
 Zlataya zep na dupe tom,
 I dnem i nochju kot uchenij
 vse hodit po cepi krugom�
����������� ������ ����� ������� ������� �������� ��������.
*/
{
    std::cout << "\"U lukomor\'a dub zelenij,\n\a\a\a"
        << "Zlataya zep na dupe tom,\n\a\a\a"
        << "I dnem i nochju kot uchenij\n\a\a\a"
        << "vse hodit po cepi krugom.\"\n\a\a\a";

    return 0;

}

int main4()
/*
������� ����������, ������� ������� ���������� � �����, � ��������� �������:
Name        : �The war and the peace�
Avtor       : L.N. Tolstoj
Izdatelstvo : Piter
Pages       : 500.
*/
{
    std::cout << "Name \t\t: \"The war and the peace\"\n"
        << "Avtor \t\t: L.N. Tolstoj\n"
        << "Izdatelstvo\t: Piter\n"
        << "Pages \t\t: 500.\n";

    return 0;
}


int main3()
/*
�������� ��������� �����:
To be, or not to be: that is the question:
Whether 'tis nobler in the mind to suffer
The slings and arrows of outrageous fortune,
Or to take arms against a sea of troubles,
And by opposing end them?
William Shakespeare
*/
{
    std::cout << "To be, or not to be: that is the question:\n"
        << "Whether 'tis nobler in the mind to suffer\n"
        << "The slings and arrows of outrageous fortune,\n"
        << "Or to take arms against a sea of troubles,\n"
        << "And by opposing end them?\n"
        << "William Shakespeare\n";

    return 0;
}



int main2()
/*
�������� ���������, ������� ������� ��
�����:
Hello, World!
\\Dennis Ritchi\\
*/
{
    std::cout << "Hello, World!\n"
        << "\\\\Dennis Ritchi\\\\\n";

    return 0;
}


int main1()
/*
�������� ���������, ������� ������� ��
�����:
�Hello, World!�
/Bjarne Stroustrup/
*/
{
    std::cout << "\"Hello, World!\"\n" 
              << "/Bjarne Stroustrup/\n";

    return 0;
}


