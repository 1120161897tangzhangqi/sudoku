#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\sudoku\EndProducer.h"
#include "..\sudoku\SolveSudoku.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(End_Test_Swap)
		{
			EndProducer ep(12);
			int x = 2;
			int y = 1;
			ep.Swap(&x, &y);
			Assert::AreEqual(x, 1);
			Assert::AreEqual(y, 2);
		}
		
		TEST_METHOD(End_Test_ROW123)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr, 1, sizeof(int) * 9);
			memset(arr + 9, 2, sizeof(int) * 9);
			memset(arr + 18, 3, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 1,2,3 };
			EP.RowSwap(arr, Type123, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr, 1, sizeof(int) * 9);
			memset(arr + 9, 2, sizeof(int) * 9);
			memset(arr + 18, 3, sizeof(int) * 9);
			for (int i = 0; i < 9; i++) {
				Assert::AreEqual(Real[i] , arr[i]);
				Assert::AreEqual(Real[i+9], arr[i+9]);
				Assert::AreEqual(Real[i+18], arr[i+18]);
			}
		}
		TEST_METHOD(End_Test_ROW132)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr, 1, sizeof(int) * 9);
			memset(arr+9, 2, sizeof(int) * 9);
			memset(arr+18, 3, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 1,3,2 };
			EP.RowSwap(arr, Type123, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr, 1, sizeof(int) * 9);
			memset(arr+9, 2, sizeof(int) * 9);
			memset(arr+18, 3, sizeof(int) * 9);
			for (int i = 0; i < 9; i++) {
				Assert::AreEqual(Real[i] , arr[i]);
				Assert::AreEqual(Real[i+9], arr[i+18]);
				Assert::AreEqual(Real[i+18], arr[i+9]);
			}
		}
		TEST_METHOD(End_Test_ROW456)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr+27, 4, sizeof(int) * 9);
			memset(arr+36, 5, sizeof(int) * 9);
			memset(arr+45, 6, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 4,5,6 };
			EP.RowSwap(arr, Type456, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr + 27, 4, sizeof(int) * 9);
			memset(arr + 36, 5, sizeof(int) * 9);
			memset(arr + 45, 6, sizeof(int) * 9);
			for (int i = 27; i < 36; i++) {
				Assert::AreEqual(Real[i], arr[i]);
				Assert::AreEqual(Real[i + 9], arr[i + 9]);
				Assert::AreEqual(Real[i + 18], arr[i + 18]);
			}
		}
		TEST_METHOD(End_Test_ROW465)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr + 27, 4, sizeof(int) * 9);
			memset(arr + 36, 5, sizeof(int) * 9);
			memset(arr + 45, 6, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 4,6,5 };
			EP.RowSwap(arr, Type456, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr + 27, 4, sizeof(int) * 9);
			memset(arr + 36, 5, sizeof(int) * 9);
			memset(arr + 45, 6, sizeof(int) * 9);
			for (int i = 27; i < 36; i++) {
				Assert::AreEqual(Real[i], arr[i]);
				Assert::AreEqual(Real[i + 9], arr[i + 18]);
				Assert::AreEqual(Real[i + 18], arr[i + 9]);
			}
		}
		TEST_METHOD(End_Test_ROW546)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr + 27, 4, sizeof(int) * 9);
			memset(arr + 36, 5, sizeof(int) * 9);
			memset(arr + 45, 6, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 5,4,6 };
			EP.RowSwap(arr, Type456, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr + 27, 4, sizeof(int) * 9);
			memset(arr + 36, 5, sizeof(int) * 9);
			memset(arr + 45, 6, sizeof(int) * 9);
			for (int i = 27; i < 36; i++) {
				Assert::AreEqual(Real[i + 9], arr[i]);
				Assert::AreEqual(Real[i], arr[i + 9]);
				Assert::AreEqual(Real[i + 18], arr[i + 18]);
			}
		}
		TEST_METHOD(End_Test_ROW564)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr + 27, 4, sizeof(int) * 9);
			memset(arr + 36, 5, sizeof(int) * 9);
			memset(arr + 45, 6, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 5,6,4 };
			EP.RowSwap(arr, Type456, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr + 27, 4, sizeof(int) * 9);
			memset(arr + 36, 5, sizeof(int) * 9);
			memset(arr + 45, 6, sizeof(int) * 9);
			for (int i = 27; i < 36; i++) {
				Assert::AreEqual(Real[i + 18], arr[i]);
				Assert::AreEqual(Real[i + 9], arr[i + 18]);
				Assert::AreEqual(Real[i], arr[i + 9]);
			}	
		}
		TEST_METHOD(End_Test_ROW645)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr + 27, 4, sizeof(int) * 9);
			memset(arr + 36, 5, sizeof(int) * 9);
			memset(arr + 45, 6, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 6,4,5 };
			EP.RowSwap(arr, Type456, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr + 27, 4, sizeof(int) * 9);
			memset(arr + 36, 5, sizeof(int) * 9);
			memset(arr + 45, 6, sizeof(int) * 9);
			for (int i = 27; i < 36; i++) {
				Assert::AreEqual(Real[i + 18], arr[i + 9]);
				Assert::AreEqual(Real[i + 9], arr[i]);
				Assert::AreEqual(Real[i], arr[i + 18]);
			}
		}
		TEST_METHOD(End_Test_ROW654)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr + 27, 4, sizeof(int) * 9);
			memset(arr + 36, 5, sizeof(int) * 9);
			memset(arr + 45, 6, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 6,5,4 };
			EP.RowSwap(arr, Type456, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr + 27, 4, sizeof(int) * 9);
			memset(arr + 36, 5, sizeof(int) * 9);
			memset(arr + 45, 6, sizeof(int) * 9);
			for (int i = 27; i < 36; i++) {
				Assert::AreEqual(Real[i], arr[i + 18]);
				Assert::AreEqual(Real[i + 18], arr[i]);
			}
		}
		TEST_METHOD(End_Test_ROW789)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr+54, 7, sizeof(int) * 9);
			memset(arr+63, 8, sizeof(int) * 9);
			memset(arr+72, 9, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 7,8,9 };
			EP.RowSwap(arr, Type789, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr + 54, 7, sizeof(int) * 9);
			memset(arr + 63, 8, sizeof(int) * 9);
			memset(arr + 72, 9, sizeof(int) * 9);
			for (int i = 54; i < 63; i++) {
				Assert::AreEqual(Real[i], arr[i]);
				Assert::AreEqual(Real[i + 9], arr[i + 9]);
				Assert::AreEqual(Real[i + 18], arr[i + 18]);
			}
		}
		TEST_METHOD(End_Test_ROW798)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr + 54, 7, sizeof(int) * 9);
			memset(arr + 63, 8, sizeof(int) * 9);
			memset(arr + 72, 9, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 7,9,8 };
			EP.RowSwap(arr, Type789, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr + 54, 7, sizeof(int) * 9);
			memset(arr + 63, 8, sizeof(int) * 9);
			memset(arr + 72, 9, sizeof(int) * 9);
			for (int i = 54; i < 63; i++) {
				Assert::AreEqual(Real[i], arr[i]);
				Assert::AreEqual(Real[i + 9], arr[i + 18]);
				Assert::AreEqual(Real[i + 18], arr[i + 9]);
			}
		}
		TEST_METHOD(End_Test_ROW879)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr + 54, 7, sizeof(int) * 9);
			memset(arr + 63, 8, sizeof(int) * 9);
			memset(arr + 72, 9, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 8,7,9 };
			EP.RowSwap(arr, Type789, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr + 54, 7, sizeof(int) * 9);
			memset(arr + 63, 8, sizeof(int) * 9);
			memset(arr + 72, 9, sizeof(int) * 9);
			for (int i = 54; i < 63; i++) {
				Assert::AreEqual(Real[i + 9], arr[i]);
				Assert::AreEqual(Real[i], arr[i + 9]);
				Assert::AreEqual(Real[i + 18], arr[i + 18]);
			}
		}
		TEST_METHOD(End_Test_ROW897)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr + 54, 7, sizeof(int) * 9);
			memset(arr + 63, 8, sizeof(int) * 9);
			memset(arr + 72, 9, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 8,9,7 };
			EP.RowSwap(arr, Type789, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr + 54, 7, sizeof(int) * 9);
			memset(arr + 63, 8, sizeof(int) * 9);
			memset(arr + 72, 9, sizeof(int) * 9);
			for (int i = 54; i < 63; i++) {
				Assert::AreEqual(Real[i + 18], arr[i]);
				Assert::AreEqual(Real[i], arr[i + 9]);
				Assert::AreEqual(Real[i + 9], arr[i + 18]);
			}
		}
		TEST_METHOD(End_Test_ROW978)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr + 54, 7, sizeof(int) * 9);
			memset(arr + 63, 8, sizeof(int) * 9);
			memset(arr + 72, 9, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 9,7,8 };
			EP.RowSwap(arr, Type789, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr + 54, 7, sizeof(int) * 9);
			memset(arr + 63, 8, sizeof(int) * 9);
			memset(arr + 72, 9, sizeof(int) * 9);
			for (int i = 54; i < 63; i++) {
				Assert::AreEqual(Real[i + 18], arr[i + 9]);
				Assert::AreEqual(Real[i + 9], arr[i]);
				Assert::AreEqual(Real[i], arr[i + 18]);
			}
		}
		TEST_METHOD(End_Test_ROW987)
		{
			EndProducer EP(12);
			int arr[81] = { 0 };
			memset(arr + 54, 7, sizeof(int) * 9);
			memset(arr + 63, 8, sizeof(int) * 9);
			memset(arr + 72, 9, sizeof(int) * 9);
			int Real[81] = { 0 };
			int rank[3] = { 9,8,7 };
			EP.RowSwap(arr, Type789, rank);
			memcpy(Real, arr, sizeof(int) * 81);
			memset(arr + 54, 7, sizeof(int) * 9);
			memset(arr + 63, 8, sizeof(int) * 9);
			memset(arr + 72, 9, sizeof(int) * 9);
			for (int i = 54; i < 63; i++) {
				Assert::AreEqual(Real[i], arr[i + 18]);
				Assert::AreEqual(Real[i + 9], arr[i + 9]);
				Assert::AreEqual(Real[i + 18], arr[i]);
			}
		}
		TEST_METHOD(End_Test_DuplicateCheck) 
		{
			EndProducer es(12);
			int arr[10] = { 1,2,3,4,5,5,5,3,2,0 };
			int x = 6;
			int y = 1;
			int Count = 9;
			bool expect_in = es.DuplicateCheck(arr, y, Count);
			bool expect_out = es.DuplicateCheck(arr, x, Count);
			Assert::AreEqual(expect_in, true);
			Assert::AreEqual(expect_out, false);
		}
		TEST_METHOD(End_Test_getInitialSeed) 
		{
			EndProducer ep(12);
			int arr[9] = { 1,2,3,4,5,6,7,8,9 };
			int* arr1 = NULL; 
			arr1 = ep.getInitialSeed();
			for (int i = 0; i < 9; i++) {
				Assert::AreNotEqual(*(arr1 + i), arr[i]);
			}
		}
		TEST_METHOD(End_Test_IndexIndexSubstitution) 
		{
			EndProducer ep(12);
			int arr1[9] = { 4,6,3,2,1,8,9,5,7 };
			int test_seed[9] = { 9,2,4,6,5,1,7,8,3 };
			int arr2[9] = { 0 };
			ep.IndexSubstitution(test_seed, arr1, arr2, 9);
			int expect_arr2[9] = { 6,1,4,2,9,8,3,5,7 };
			for (int i = 0; i < 9; i++) {
				Assert::AreEqual(arr2[i], expect_arr2[i]);
			}
		}
		TEST_METHOD(Sol_Test_setPuzzle) 
		{
			SolveSudoku test_ss;
			int x[81] = { 0 };
			x[1] = 9;
			x[5] = 1;
			x[4] = 2;
			test_ss.setPuzzle(x);
			int* y = test_ss.getPuzzle();
			Assert::AreEqual(x[1], y[1]);
			Assert::AreEqual(x[4], y[4]);
			Assert::AreEqual(x[5], y[5]);
		}
		TEST_METHOD(Sol_Test_NumTransfor)
		{
			SolveSudoku test_ss;
			int x1 = 1;
			int x2 = 4;
			int x3 = 9;
			Assert::AreEqual(test_ss.NumTransfor(x1), 0x1);
			Assert::AreEqual(test_ss.NumTransfor(x2), 0x8);
			Assert::AreEqual(test_ss.NumTransfor(x3), 0x100);
		}
		
	};
}