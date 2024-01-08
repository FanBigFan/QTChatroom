/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget {
 public:
  QListWidget *ip_widget;
  QComboBox *ip_box;
  QLineEdit *port;
  QPushButton *listen_btn;
  QTextBrowser *recv_text;
  QPlainTextEdit *send_text;
  QPushButton *send_btn;

  void setupUi(QWidget *Widget) {
    QFont font;
    font.setFamily(QString::fromUtf8("Courier New"));
    font.setBold(false);
    font.setItalic(false);
    font.setWeight(50);

    if (Widget->objectName().isEmpty())
      Widget->setObjectName(QString::fromUtf8("Widget"));
    Widget->resize(750, 510);

    ip_widget = new QListWidget(Widget);
    ip_box = new QComboBox(Widget);
    port = new QLineEdit(Widget);
    listen_btn = new QPushButton(Widget);
    recv_text = new QTextBrowser(Widget);
    send_text = new QPlainTextEdit(Widget);
    send_btn = new QPushButton(Widget);

    ip_widget->setObjectName(QString::fromUtf8("ip_widget"));
    ip_box->setObjectName(QString::fromUtf8("ip_box"));
    port->setObjectName(QString::fromUtf8("port"));
    listen_btn->setObjectName(QString::fromUtf8("listen_btn"));
    recv_text->setObjectName(QString::fromUtf8("recv_text"));
    send_text->setObjectName(QString::fromUtf8("send_text"));
    send_btn->setObjectName(QString::fromUtf8("send_btn"));

    ip_widget->setGeometry(QRect(530, 60, 200, 290));
    ip_box->setGeometry(QRect(110, 15, 151, 28));
    port->setGeometry(QRect(300, 15, 101, 28));
    listen_btn->setGeometry(QRect(460, 15, 81, 28));
    recv_text->setGeometry(QRect(20, 60, 500, 290));
    send_text->setGeometry(QRect(20, 360, 710, 130));
    send_btn->setGeometry(QRect(640, 455, 81, 28));

    ip_widget->setFont(font);
    ip_box->setFont(font);
    port->setFont(font);
    listen_btn->setFont(font);
    recv_text->setFont(font);
    send_text->setFont(font);
    send_btn->setFont(font);

    retranslateUi(Widget);
    QMetaObject::connectSlotsByName(Widget);
  }  // setupUi

  void retranslateUi(QWidget *Widget) {
    Widget->setWindowTitle(
        QCoreApplication::translate("Widget", "Linux Course Design", nullptr));
    listen_btn->setText(
        QCoreApplication::translate("Widget", "Listen", nullptr));
    send_btn->setText(QCoreApplication::translate("Widget", "Send", nullptr));
  }  // retranslateUi
};

namespace Ui {
class Widget : public Ui_Widget {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_WIDGET_H
