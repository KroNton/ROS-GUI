# ROS-GUI
template packages to create GUI for ROS applications using QT-creator in C++

## install ROS Qt Creator 

```
sudo snap install qtcreator-ros --classic
```
##  Qt ROS project

### create Qt-ROS project
1. open Qt-ROS application then ->  "create  project"
2. from "other project" -> "ROS Workspace"

![New project](./images/image1.png)

### Configure ROS Workspace
After selecting "ROS Workspace," you need to configure the ROS workspace for your project.

1. Specify the project name.

2. Select the ROS distribution that you are using.

3. Choose or create a ROS workspace directory where your project will be stored.


4. Set the build system (usually 'CatkinMake' for ROS1 or 'colcon' for ROS2).

![Configure project](./images/image2.png)

