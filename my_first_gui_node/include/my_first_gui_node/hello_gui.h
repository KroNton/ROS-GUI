#ifndef HELLO_GUI_H
#define HELLO_GUI_H

#include <QWidget>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <qtimer.h>
#include <sstream>

namespace Ui {
class HelloGui;
}

class HelloGui : public QWidget
{
  Q_OBJECT

public:
  explicit HelloGui(QWidget *parent = nullptr);
  ~HelloGui();
  void chatter_callback(const std_msgs::String::ConstPtr& msg);

public slots:
 void spinOnce();

private slots:
 void on_pub_Button_clicked();

private:
  Ui::HelloGui *ui;
  QTimer *ros_timer;
  
  ros::NodeHandlePtr nh_;
  ros::Subscriber chatter_sub_;
  ros::Publisher  srting_pub_;
  std_msgs::String string_msg;


};

#endif // HELLO_GUI_H
