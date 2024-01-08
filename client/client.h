#ifndef CLIENT_H
#define CLIENT_H

#include <QByteArray>
#include <QDateTime>
#include <QHostAddress>
#include <QMessageBox>
#include <QString>
#include <QTcpSocket>
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget {
  Q_OBJECT

 public:
  explicit Widget(QWidget *parent = nullptr);
  ~Widget();

 private slots:
  void conn_button();
  void send_button();
  void recv_message();
  void handle_disconnect();

 private:
  Ui::Widget *ui;
  QTcpSocket *socket;
  bool connect_state;
};

#endif  // CLIENT_H
