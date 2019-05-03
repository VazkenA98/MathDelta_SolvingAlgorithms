#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Delta_QT.h"

class Delta_QT : public QMainWindow
{
	Q_OBJECT

public:
	Delta_QT(QWidget *parent = Q_NULLPTR);

public slots:
	void OnCLicked();
	void OnTextChanged_A(const QString&);
	void OnTextChanged_B(const QString&);
	void OnTextChanged_C(const QString&);



private:
	Ui::Delta_QTClass ui;
};
