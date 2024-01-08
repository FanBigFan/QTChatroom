#include "client.h"

#include "ui_client.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  this->ui->ip->setPlaceholderText("Input IP");
  this->ui->port->setText("8888");
  this->ui->port->setPlaceholderText("Input Port");
  this->ui->send_text->setPlaceholderText("Input Message");
  this->ui->recv_text->setPlaceholderText("History Message");
  socket = new QTcpSocket(this);
  connect_state = false;
  connect(socket, &QTcpSocket::readyRead, this, &Widget::recv_message);
  connect(socket, &QTcpSocket::disconnected, this, &Widget::handle_disconnect);
  connect(ui->conn_btn, &QPushButton::clicked, this, &Widget::conn_button);
  connect(ui->send_btn, &QPushButton::clicked, this, &Widget::send_button);
}

Widget::~Widget() { delete ui; }

void Widget::recv_message() {
  QByteArray arr = socket->readAll();
  QString str;
  str = QDateTime::currentDateTime().toString("dddd.yyyy.MM.dd HH:mm:ss") +
        " [" + this->socket->peerAddress().toString() + ":" +
        QString::number(this->socket->peerPort()) + "]\n > " + arr.data();
  ui->recv_text->append(str);
}

void Widget::handle_disconnect() {
  QString str = "[-]" + this->socket->peerAddress().toString() + ":" +
                QString::number(this->socket->peerPort());
  this->ui->widget_list->addItem(str);
}

void Widget::conn_button() {
  QString ip = ui->ip->text();
  quint16 curr_port = ui->port->text().toInt();
  if (!connect_state) {
    socket->connectToHost(ip, curr_port);
    if (socket->waitForConnected()) {
      QString str = "[+]" + this->socket->peerAddress().toString() + ":" +
                    QString::number(this->socket->peerPort());
      this->ui->widget_list->addItem(str);
      ui->conn_btn->setText("Close");
      connect_state = true;
    } else {
      QMessageBox::warning(this, "Link Failed", socket->errorString());
    }
  } else {
    socket->close();
    ui->conn_btn->setText("Link");
  }
}

void Widget::send_button() {
  QString msg = ui->send_text->toPlainText();
  if (socket->isOpen() && socket->isValid()) {
    socket->write(msg.toUtf8());
    ui->send_text->clear();
  }

  QString str =
      QDateTime::currentDateTime().toString("dddd.yyyy.MM.dd HH:mm:ss") +
      " [Local]"
      "\n < " +
      msg;
  ui->recv_text->append(str);
}
