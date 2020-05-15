#include "pc2grid.h"

Pc2Grid::Pc2Grid(){
	NodeHandle nh;
	depth_cam.reset(new PointCloud<PointXYZ>());
	pc_map = nh.advertise<sensor_msgs::PointCloud2> ("transform_d435_pc", 1);

	float leaf_size = 0.1;
	voxel.setLeafSize(leaf_size, leaf_size, leaf_size);

    passZ.setFilterFieldName("z");

	sub_map = nh.subscribe("/camera/depth_registered/points", 1, &Pc2Grid::pcCallback, this);

}

void Pc2Grid::pcCallback(const sensor_msgs::PointCloud2ConstPtr &pc){
	fromROSMsg(*pc, *depth_cam);

	passZ.setInputCloud(depth_cam);
	passZ.setFilterLimits(0,7);
    passZ.filter(*depth_cam);

	voxel.setInputCloud(depth_cam);
    voxel.filter(*depth_cam);
	
	try{
		ros::Duration timeout(1.0);
		listener.waitForTransform("base_footprint", pc->header.frame_id , ros::Time(0), timeout);
		listener.lookupTransform("base_footprint", pc->header.frame_id, ros::Time(0), transform);
	}
	catch (tf::TransformException ex){
		ROS_ERROR("%s",ex.what());
		return;
	}
	pcl_ros::transformAsMatrix(transform, trans);
	pcl::transformPointCloud (*depth_cam, *depth_cam, trans);

	passZ.setInputCloud(depth_cam);
	passZ.setFilterLimits(0.2,2);
    passZ.filter(*depth_cam);

	toROSMsg(*depth_cam, ros_cloud_msg);
	ros_cloud_msg.header.frame_id = "base_footprint";
	ros_cloud_msg.header.stamp = ros::Time::now();
	pc_map.publish(ros_cloud_msg);
	depth_cam->points.clear();

}



int main(int argc, char** argv){
	init(argc, argv, "pc2grid");
	Pc2Grid global_map;
	spin();
	return 0;
}