#include "pch.h"
#include "CppUnitTest.h"
#include "..\PR6.2(rec).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCountEven)
        {
            // ϳ�������� �������� �����
            int testArray1[] = { 1, 2, 3, 4, 5, 6 }; // ��������� 3 ������ �����: 2, 4, 6
            int testArray2[] = { 1, 3, 5, 7 }; // ��������� 0 ������ �����
            int testArray3[] = { 2, 4, 6, 8, 10 }; // ��������� 5 ������ �����: 2, 4, 6, 8, 10

            // ���������� ������� CountEven
            int result1 = CountEven(testArray1, 6, 0);
            int result2 = CountEven(testArray2, 4, 0);
            int result3 = CountEven(testArray3, 5, 0);

            // �������� ����������
            Assert::AreEqual(3, result1, L"Expected 3 even numbers in testArray1");
            Assert::AreEqual(0, result2, L"Expected 0 even numbers in testArray2");
            Assert::AreEqual(5, result3, L"Expected 5 even numbers in testArray3");
        }
    };
}
