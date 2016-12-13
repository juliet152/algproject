#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "RedBlackTree.h"
#include "UIManager.h"

int main()
{
	Submodule *Sub = new Submodule();
	UIManager *UI = new UIManager(*Sub);
	while (1) {
		UI->print();
		UI->handleInput();
	}

	return 0;
}