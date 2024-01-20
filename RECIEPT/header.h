#ifndef HEADER_H
#define HEADER_h

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

struct product {
	char ProductName[50];
	float UnitPrice;
	int Quantity;
	float TotalPrice;
};

struct shop {
	char ShopName[50];
	char Address[100];
};

struct customer {
	char CustomerName[50];
	char PhoneNumber[15];
};

struct Person {
	shop shopInfo;
	customer customerInfo;
	product productInfo;
};
#endif /* HEADER_H */