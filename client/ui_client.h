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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget {
 public:
  QLineEdit *ip;
  QLineEdit *port;
  QPushButton *conn_btn;
  QTextBrowser *recv_text;
  QListWidget *widget_list;
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

    ip = new QLineEdit(Widget);
    port = new QLineEdit(Widget);
    conn_btn = new QPushButton(Widget);
    recv_text = new QTextBrowser(Widget);
    widget_list = new QListWidget(Widget);
    send_text = new QPlainTextEdit(Widget);
    send_btn = new QPushButton(Widget);

    ip->setObjectName(QString::fromUtf8("ip"));
    port->setObjectName(QString::fromUtf8("port"));
    conn_btn->setObjectName(QString::fromUtf8("conn_btn"));
    recv_text->setObjectName(QString::fromUtf8("recv_text"));
    widget_list->setObjectName(QString::fromUtf8("widget_list"));
    send_text->setObjectName(QString::fromUtf8("send_text"));
    send_btn->setObjectName(QString::fromUtf8("send_btn"));

    ip->setGeometry(QRect(110, 15, 151, 28));
    port->setGeometry(QRect(300, 15, 101, 28));
    conn_btn->setGeometry(QRect(460, 15, 81, 28));
    recv_text->setGeometry(QRect(20, 60, 500, 290));
    widget_list->setGeometry(QRect(530, 60, 200, 290));
    send_text->setGeometry(QRect(20, 360, 710, 130));
    send_btn->setGeometry(QRect(640, 455, 81, 28));

    ip->setFont(font);
    port->setFont(font);
    conn_btn->setFont(font);
    recv_text->setFont(font);
    widget_list->setFont(font);
    send_text->setFont(font);
    send_btn->setFont(font);

    retranslateUi(Widget);
    QMetaObject::connectSlotsByName(Widget);
  }  // setupUi

  void retranslateUi(QWidget *Widget) {
    Widget->setWindowTitle(
        QCoreApplication::translate("Widget", "Linux Course Design", nullptr));
    ip->setText(QCoreApplication::translate("Widget", "10.3.1.39", nullptr));
    port->setText(QCoreApplication::translate("Widget", "8888", nullptr));
    conn_btn->setText(
        QCoreApplication::translate("Widget", "Connect", nullptr));
    send_btn->setText(QCoreApplication::translate("Widget", "Send", nullptr));
  }  // retranslateUi
};

namespace Ui {
class Widget : public Ui_Widget {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_WIDGET_H
