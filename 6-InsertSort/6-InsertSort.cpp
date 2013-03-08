// 6-InsertSort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <conio.h>

typedef char Item;
void sort(Item *a, int n);

int _tmain(int argc, _TCHAR* argv[])
{
	Item a[] = "This library is free software; you can redistribute it and/or\
    modify it under the terms of the GNU Lesser General Public\
    License as published by the Free Software Foundation; either\
    version 2.1 of the License, or (at your option) version 3, or any\
    later version accepted by the membership of KDE e.V. (or its\
    successor approved by the membership of KDE e.V.), Nokia Corporation \
    (or its successors, if any) and the KDE Free Qt Foundation, which shall\
    act as a proxy defined in Section 6 of version 3 of the license.";
	int len = strlen(a);

	LARGE_INTEGER freq;
	LONGLONG start;
	LONGLONG end;
	QueryPerformanceFrequency(&freq);
	printf("freq: %lld\n", freq.QuadPart);
	QueryPerformanceCounter(&freq);
	start = freq.QuadPart;

	sort(a, len);

	QueryPerformanceCounter(&freq);
	end = freq.QuadPart;
	printf("%s\n", a);
	printf("count: %lld", end - start);

	getch();
	return 0;
}


void sort(Item *a, int n)
{
	//for (int i = 1; i < n; i++) {
	//	for (int j = i; j > 0; j--) {
	//		if (a[j] < a[j - 1]) {
	//			Item temp;
	//			temp = a[j]; a[j] = a[j - 1]; a[j - 1] = temp;
	//		}
	//	}
	//}

	for (int i = 1; i < n; i++) {
		Item temp;
		int j = i;
		temp = a[j];
		while (j > 0 && a[j - 1] > temp) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}
}