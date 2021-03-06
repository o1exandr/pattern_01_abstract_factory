/*
Завдання 1.  Використати шаблон Абстрактна фабрика. Створити фабрики для створення кнопок та прапорців 
для ОС Windows, Macintosh  в залежності від вибору користувача.
Створити клас Клієнт для перевірки роботи фабрик.
Діаграма класів подібно https://refactoring.guru/uk/design-patterns/abstract-factory
*/

#include "stdafx.h"
#include <iostream> 
#include <string>



using namespace std;

//abstract Button
class IButton 
{
protected:

	string name;

public:

	virtual void press() = 0;
	virtual void print() = 0;

};

//Concrete Button1
class WinButton : public IButton  
{

public:

	WinButton(string name)
	{
		this->name = name;
	}

	virtual void press()
	{
		cout << "WinButton " << name << " method Press\n";
	}

	virtual void print()
	{
		cout << "WinButton "<< name << " method Print\n";
	}
};

//Concrete Button2
class MacButton : public IButton
{
public:

	MacButton(string name)
	{
		this->name = name;
	}

	virtual void press()
	{
		cout << "MacButton " << name << " method Press\n";
	}

	virtual void print()
	{
		cout << "MacButton " << name << " method Print\n";
	}
};

//abstract CheckBox 
class ICheckBox 
{
protected:

	string name;
	bool flag;

public:

	virtual void click() = 0;
	virtual void print() = 0;

};

//Concrete CheckBox 1
class WinCheckBox : public ICheckBox
{
public:

	WinCheckBox(string name, bool flag)
	{
		this->name = name;
		this->flag = flag;
	}

	virtual void click()
	{
		cout << "WinCheckBox method Click\n";
		flag = !flag;
	}

	virtual void print()
	{
		cout << "WinCheckBox name: " << name << ", state: " << flag << endl;
	}
};

//Concrete CheckBox 2
class MacCheckBox : public ICheckBox
{
public:

	MacCheckBox(string name, bool flag)
	{
		this->name = name;
		this->flag = flag;
	}

	void click()
	{
		cout << "MacCheckBox Click\n";
		flag = !flag;
	}

	void print()
	{
		cout << "MacCheckBox name: " << name << ", state: " << flag << endl;
	}
};

// Abstract Factory
class GUIFactory
{
public:
	virtual IButton* createButton() = 0;
	virtual ICheckBox* createCheckBox() = 0;
};

// Concrete Factory1
class WinFactory : public GUIFactory
{
public:

	virtual IButton* createButton()
	{
		IButton *pB = new WinButton("'OK'");
		return pB;
	}

	virtual ICheckBox* createCheckBox()
	{
		ICheckBox *pCb = new WinCheckBox("'Reverse'", true);
		return pCb;
	}
};

// Concrete Factory2
class MacFactory : public GUIFactory
{
public:

	virtual IButton* createButton()
	{
		IButton *pB = new MacButton("'Cancel'");
		return pB;
	}

	virtual ICheckBox* createCheckBox()
	{
		ICheckBox *pCb = new MacCheckBox("'Sort'", true);
		return pCb;
	}
};

void use(GUIFactory* f)
{
	IButton* myButton = f->createButton();
	ICheckBox* myCheckBox = f->createCheckBox();
	myButton->press();
	myButton->print();
	cout << "---------\n";
	myCheckBox->print();
	myCheckBox->click();
	myCheckBox->print();
	cout << "-=-=-=-=-\n\n";
}

int main()
{
	WinFactory win;
	MacFactory mac;
	use(&win);
	use(&mac);


	cout << endl;
	system("pause");
	return 0;
}