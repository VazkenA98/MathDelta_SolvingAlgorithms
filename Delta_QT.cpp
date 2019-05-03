#include "Delta_QT.h"

Delta_QT::Delta_QT(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(OnCLicked()));
	connect(ui.Input_A, SIGNAL(textChanged(const QString&)), this, SLOT(OnTextChanged_A(const QString&)));
	connect(ui.Input_B, SIGNAL(textChanged(const QString&)), this, SLOT(OnTextChanged_B(const QString&)));
	connect(ui.Input_C, SIGNAL(textChanged(const QString&)), this, SLOT(OnTextChanged_C(const QString&)));
}


void Delta_QT::OnCLicked() 
{
	int a = ui.Input_A->text().toInt();
	int b = ui.Input_B->text().toInt();
	int c = ui.Input_C->text().toInt();
	int delta = (b * b) - (4 * a*c);
	QString str_Delta = QString::number(delta);
	ui.Output_D->setText(str_Delta);

		if (delta < 0) {
			ui.Output_x1->setText("Error");
			ui.Output_x2->setText("Error");

			ui.Label_delta->setText(str_Delta);
			ui.Label_symbol->setText("<");
		}
		if (delta > 0) {
			double x1 = (-b + sqrt(delta)) / (2 * a);
			double x2 = (-b - sqrt(delta)) / (2 * a);
			QString s1 = QString::number(x1);
			QString s2 = QString::number(x2);
			ui.Output_x1->setText(s1);
			ui.Output_x2->setText(s2);

			ui.Label_delta->setText(str_Delta);
			ui.Label_symbol->setText(">");
		}

		if (delta == 0) {
			double x1 = (-b + sqrt(delta)) / (2 * a);
			QString s = QString::number(x1);
			ui.Output_x1->setText(s);
			ui.Output_x2->setText(s);

			ui.Label_delta->setText(str_Delta);
			ui.Label_symbol->setText("=");
		}
	

}

void Delta_QT::OnTextChanged_A(const QString& str)
{
	QString txt = ui.Input_A->text();
	ui.label_a->setText(txt);

}

void Delta_QT::OnTextChanged_B(const QString& str)
{
	QString txt = ui.Input_B->text();
	ui.label_b->setText(txt);
}

void Delta_QT::OnTextChanged_C(const QString& str)
{
	QString txt = ui.Input_C->text();
	ui.label_c->setText(txt);
}