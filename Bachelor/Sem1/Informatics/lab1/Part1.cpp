#include <iostream>
#include <cmath>
#include <clocale>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, ".UTF8");
    // ==================== ��� FLOAT ====================
    float a_f = 100.0f;
    float b_f = 0.001f;

    float term1_f = pow(a_f + b_f, 4);
    float term2_f = pow(a_f, 4) + 4 * pow(a_f, 3) * b_f
                  + 6 * pow(a_f, 2) * pow(b_f, 2);
    float numerator_f   = term1_f - term2_f;
    float denominator_f = 4 * a_f * pow(b_f, 3) + pow(b_f, 4);
    float result_f      = numerator_f / denominator_f;

    cout << "========================================" << endl;
    cout << "������� 1. ��� float:" << endl;
    cout << "========================================" << endl;
    cout << "a = " << a_f << ", b = " << b_f << endl;

    cout << scientific << setprecision(15);
    cout << "term1       = " << term1_f << endl;
    cout << "term2       = " << term2_f << endl;
    cout << "���������   = " << numerator_f << endl;
    cout << "����������� = " << denominator_f << endl;
    cout << "���������   = " << result_f << endl;

    cout << fixed << setprecision(6);
    cout << "��������� (fixed) = " << result_f << endl << endl;

    // ==================== ��� DOUBLE ====================
    double a_d = 100.0;
    double b_d = 0.001;

    double term1_d = pow(a_d + b_d, 4);
    double term2_d = pow(a_d, 4) + 4 * pow(a_d, 3) * b_d
                   + 6 * pow(a_d, 2) * pow(b_d, 2);
    double numerator_d   = term1_d - term2_d;
    double denominator_d = 4 * a_d * pow(b_d, 3) + pow(b_d, 4);
    double result_d      = numerator_d / denominator_d;

    // ������ �������� ����������� 4ab^3 + b^4
    double exact = 4 * a_d * b_d * b_d * b_d + b_d * b_d * b_d * b_d;

    cout << "========================================" << endl;
    cout << "������� 1. ��� double:" << endl;
    cout << "========================================" << endl;
    cout << "a = " << a_d << ", b = " << b_d << endl;

    cout << scientific << setprecision(17);
    cout << "term1       = " << term1_d << endl;
    cout << "term2       = " << term2_d << endl;
    cout << "���������   = " << numerator_d << endl;
    cout << "����������� = " << denominator_d << endl;
    cout << "������ ��.  = " << exact << endl;
    cout << "|���� ? ����| = " << fabs(numerator_d - exact) << endl;
    cout << "���������   = " << result_d << endl;

    cout << fixed << setprecision(6);
    cout << "��������� (fixed)   = " << numerator_d << endl;
    cout << "����������� (fixed) = " << denominator_d << endl;
    cout << "��������� (fixed)   = " << result_d << endl << endl;

    return 0;
}