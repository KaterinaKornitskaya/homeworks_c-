
#include <iostream>

int main()
/*
�������� 2. �������� ��������, ��� ���������� �������
� ��������� ������� ����� �� �������� ������. 
���������, ����� 12,5 �� ���� ����������� ���: 12 ��� 50 ���.
*/
{
    {
        double number, hrn, kop;

        std::cout << "Enter your number in hrn,kop\n";
        std::cin >> number;

        kop = number * 10.0;
        hrn = (kop / 10.0); // �� ����������, ������ 0 ������ ���������

        std::cout << hrn << " hrn " << kop << " kop.";


    return 0;

}



int main3()
{
    /*
    �������� 3. ��������� �������� ������� ��� ������������ ���������������� ��� 
    �� �������� S = v*t + (a*t2) / 2, �� v � ��������, t � ���, � � �����������.
    */

    float v;
    float t;
    float a;
    float S;

    std::cout << "Enter v \n";
    std::cin >> v; 
    std::cout << "Enter t \n"; 
    std::cin >> t;
    std::cout << "Enter a \n";
    std::cin >> a;
  
    S = v * t + (a * (t*t)) / 2;

    std::cout << "S = " << S;

    return 0;

}

int main2()
{

/*
�������� 2. �� ������� �������� ��������� ������
����� ���� �� �������� S = pi* R2, ����� ���������
� ������� ������� ����: L = 2*pi*R.
�������: pi = 3.14.
*/

    float pi = 3.14;
    float S;
    float R; 
    float L;

    std::cout << "Enter L = ";
    std::cin >> L;

    R = L / (2 * pi);
    S = pi * (R * R);
    
    std::cout << "S = " << S;

    return 0;

}


int main1()

 /*
 �������� 1. ����� ��� ����� R1, R2, R3. ��������� 
�������� ����� R0 �� ��������: 1/R0 = 1/R1+1/R2+1/R3.
����������� �������: R1=2, R2=4, R3=8 R0 = 1.142857.
 */

{
   
    float R1 = 2;
    float R2 = 4;
    float R3 = 8;
    float R0;
    R0 = 1/(1 / R1 + 1 / R2 + 1 / R3);
    std::cout << "Ro = " << R0;

    return 0;
    
}
