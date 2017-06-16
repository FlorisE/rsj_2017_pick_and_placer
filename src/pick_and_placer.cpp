// Copyright 2017 Geoffrey Biggs (geoffrey.biggs@aist.go.jp)

#include <ros/ros.h>
#include <moveit/move_group_interface/move_group_interface.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "pickandplacer");
  ros::NodeHandle nh;

  ros::AsyncSpinner spinner(2);
  spinner.start();

  moveit::planning_interface::MoveGroupInterface arm("arm");
  arm.setPoseReferenceFrame("base_link");
  arm.setNamedTarget("vertical");
  arm.move();

  ros::shutdown();
  return 0;
}
