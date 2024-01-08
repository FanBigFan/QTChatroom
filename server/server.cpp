#include "server.h"

#include "ui_server.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);
  this->ui->port->setPlaceholderText("Input Port");
  this->ui->send_text->setPlaceholderText("Input Message");
  this->ui->recv_text->setPlaceholderText("History Message");
  this->server = new QTcpServer(this);
  this->get_ip();
  connect(this->server, &QTcpServer::newConnection, this,
          &Widget::handle_connect);
  connect(ui->listen_btn, &QPushButton::clicked, this, &Widget::listen_button);
  connect(ui->send_btn, &QPushButton::clicked, this, &Widget::send_button);
}

Widget::~Widget() { delete ui; }

void Widget::get_ip() {
  QList<QHostAddress> addr_list = QNetworkInterface::allAddresses();
  QStringList addr_str_list;

  for (int i = 0; i < addr_list.size(); ++i) {
    if (addr_list.at(i).isNull() ||
        addr_list.at(i).protocol() != QAbstractSocket::IPv4Protocol) {
      continue;
    }
    addr_str_list.append(addr_list.at(i).toString());
  }
  ui->ip_box->addItems(addr_str_list);
}

void Widget::handle_connect() {
  this->client_fd = this->server->nextPendingConnection();
  this->client_fd_list.push_back(this->client_fd);
  QString str = "[+]" + this->client_fd->peerAddress().toString() + ":" +
                QString::number(this->client_fd->peerPort());
  this->ui->ip_widget->addItem(str);
  connect(this->client_fd, &QTcpSocket::readyRead, this,
          &Widget::receive_message);
  connect(this->client_fd, &QTcpSocket::disconnected, this,
          &Widget::handle_disconnect);
}

void Widget::handle_disconnect() {
  QString str = "[-]" + this->client_fd->peerAddress().toString() + ":" +
                QString::number(this->client_fd->peerPort());
  this->ui->ip_widget->addItem(str);
}

void Widget::receive_message() {
  QTcpSocket *curr_client;
  QByteArray arr;
  QString str;
  if (!this->client_fd_list.isEmpty()) {
    for (int i = 0; i < this->client_fd_list.count(); ++i) {
      arr = this->client_fd_list.at(i)->readAll();
      if (arr.isNull()) {
        continue;
      }
      curr_client = this->client_fd_list.at(i);
      str = QDateTime::currentDateTime().toString("dddd.yyyy.MM.dd HH:mm:ss") +
            " [" + this->client_fd->peerAddress().toString() + ":" +
            QString::number(this->client_fd->peerPort()) + "]\n > " +
            arr.data();
      break;
    }
    this->ui->recv_text->append(str);
    for (int i = 0; i < this->client_fd_list.count(); ++i) {
      QTcpSocket *temp = this->client_fd_list.at(i);
      if (curr_client != temp) {
        temp->write(str.toUtf8());
      }
    }
  }
}

void Widget::listen_button() {
  QString curr_ip = this->ui->ip_box->currentText();
  quint16 curr_port = this->ui->port->text().toInt();
  QHostAddress curr_host_ip = QHostAddress(curr_ip);
  if (this->server->isListening()) {
    this->server->close();
    this->ui->listen_btn->setText("Listen");
  } else {
    if (this->server->listen(curr_host_ip, curr_port)) {
      this->ui->listen_btn->setText("Close");
    } else {
      QMessageBox::warning(this, "Listen error", this->server->errorString());
    }
  }
}

void Widget::send_button() {
  QString msg = this->ui->send_text->toPlainText();
  for (int i = 0; i < this->client_fd_list.count(); ++i) {
    this->client_fd_list.at(i)->write(msg.toUtf8());
    this->ui->send_text->clear();
  }
  QString str =
      QDateTime::currentDateTime().toString("dddd.yyyy.MM.dd HH:mm:ss") +
      " [Local]"
      "\n < " +
      msg;
  this->ui->recv_text->append(str);
}
