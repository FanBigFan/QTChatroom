#ifndef SERVER_H
#define SERVER_H

#include <QDateTime>
#include <QList>
#include <QMessageBox>
#include <QNetworkInterface>
#include <QStringList>
#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
  Q_OBJECT

 public:
  Widget(QWidget *parent = nullptr);
  void get_ip();
  ~Widget();

 private slots:
  void handle_connect();
  void handle_disconnect();
  void receive_message();
  void listen_button();
  void send_button();

 private:
  Ui::Widget *ui;
  QTcpServer *server;
  QList<QTcpSocket *> client_fd_list;
  QTcpSocket *client_fd;
};
#endif  // SERVER_H
