#include "hello_gui.h"
#include "ui_hello_gui.h"

HelloGui::HelloGui(QWidget *parent) : QWidget(parent),
                                      ui(new Ui::HelloGui)
{
  ui->setupUi(this);

  nh_.reset(new ros::NodeHandle("~"));

  // setup the timer that will signal ros stuff to happen
  ros_timer = new QTimer(this);
  connect(ros_timer, SIGNAL(timeout()), this, SLOT(spinOnce()));
  ros_timer->start(100); // set the rate to 100ms  You can change this if you want to increase/decrease update rate

  // setup subscriber by according to the ~/chatter_topic param
  std::string listen_topic;
  nh_->param<std::string>("listen_topic", listen_topic, "/talker/chatter");
  chatter_sub_ = nh_->subscribe<std_msgs::String>(listen_topic, 1, &HelloGui::chatter_callback, this);

  std::string publish_topic;
  nh_->param<std::string>("publish_topic", publish_topic, "/chatter");
  srting_pub_ = nh_->advertise<std_msgs::String>("/chatter", 10);
}

HelloGui::~HelloGui()
{
  delete ui;
}

void HelloGui::spinOnce()
{
  if (ros::ok())
  {
    ros::spinOnce();
  }
  else
    QApplication::quit();
}

void HelloGui::chatter_callback(const std_msgs::String::ConstPtr &msg)
{
  auto qstring_msg = QString::fromStdString(msg->data.c_str());
  ui->chatter->setText(qstring_msg);

}

void HelloGui::on_pub_Button_clicked()
{
   std::stringstream ss;
 ss << "hello KroNton " << ui->count_Box->value();
 string_msg.data= ss.str();
 srting_pub_.publish(string_msg);
 ui->count_Box->setValue(ui->count_Box->value()+1);
}

