#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.2(rec)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72REC
{
	TEST_CLASS(UnitTest72REC)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int rowCount = 3; 
            const int colCount = 4;
            const int Low = 5;
            const int High = 55;
            int** a = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            CreateColumns(a, rowCount, colCount, Low, High, 0);
            int expectedSum = 0;
            for (int colNo = 0; colNo < colCount; colNo++) {
                int maxInColumn = FindMaxInColumn(a, rowCount, colCount, colNo, a[0][colNo]);
                expectedSum += maxInColumn;
            }
            int actualSum = Sum(a, rowCount, colCount, 0);
            Assert::AreEqual(expectedSum, actualSum);
            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
		}
	};
}
