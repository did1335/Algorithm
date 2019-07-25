// ConsoleApplication1.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include "pch.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int length,ptr,state;
int arr[10] = { 53,92,66,59,52,59,92,66,89,59 };

int main()
{
	length = sizeof(arr) / sizeof(arr[0]); //求矩陣大小

	/*依序顯示原始矩陣數值*/
	cout << "Original Array:" << endl;
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl <<endl;

	/*插入排序法*/
	do {
		ptr = 0;
		state = 0;
		for (int i = 0; i < length - 1; i++) {
			ptr = arr[i];
			if (ptr > arr[i + 1]) {
				arr[i] = arr[i + 1];
				arr[i + 1] = ptr;
				state += 0;
			}
			else {
				state += 1;
			}
			ptr = 0;
		}
	} while (state < length - 2);
	
		/*將重複的元素放在一起*/
		ptr = 0;
		for (int i = 0; i < length - 2; i++) {
			int j = i + 1;
			do {
				if (arr[i] == arr[j]) {
					ptr = arr[i + 1];
					arr[i + 1] = arr[j];
					arr[j] = ptr;
				}
				j = j + 1;
				ptr = 0;
				if ((i == length - 3) && (j == length - 1)) {
					goto SECTIONA;
				}
			} while (j < length);
		}

		/*插入排序法*/
	SECTIONA:
		do {
			ptr = 0;
			state = 0;
			for (int i = 0; i < length - 1; i++) {
				ptr = arr[i];
				if (ptr > arr[i + 1]) {
					arr[i] = arr[i + 1];
					arr[i + 1] = ptr;
					state += 0;
				}
				else {
					state += 1;
				}
				ptr = 0;
			}
		} while (state < length - 2);
	
	/*依序顯示排序後矩陣數值*/
	cout << "After Insertion Sort:" << endl;
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的秘訣: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
