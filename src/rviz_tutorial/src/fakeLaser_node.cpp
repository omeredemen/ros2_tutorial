#include <memory>
#include <iostream>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"


class FakeLaser: public rclcpp::Node
{
public:
    FakeLaser() : Node("fakeLaser_pub")
    {
        pub_ = this->create_publisher<sensor_msgs::msg::LaserScan>("fakeLaser", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(1000/laser_frequency),
                                         std::bind(&FakeLaser::callback, this));
    }

private:
    void callback(){
        //generate some fake data for our laser scan
        for(unsigned int i = 0; i < num_readings; ++i){
            ranges[i] = 5;
            intensities[i] = 100 + count;
        }

        rclcpp::Time scan_time = this->get_clock()->now();

        sensor_msgs::msg::LaserScan scan;

        scan.header.stamp = scan_time;
        scan.header.frame_id = "fake_laser_frame";
        scan.angle_min = -1.57;
        scan.angle_max = 1.57;
        scan.angle_increment = 3.14 / num_readings;
        scan.time_increment = (1 / laser_frequency) / (num_readings);
        scan.range_min = 0.0;
        scan.range_max = 100.0;

        scan.scan_time = (1 / laser_frequency);

        scan.ranges.resize(num_readings);
        scan.intensities.resize(num_readings);

        for(unsigned int i = 0; i < num_readings; ++i){
            scan.ranges[i] = ranges[i];
            scan.intensities[i] = intensities[i];
        }

        pub_->publish(scan);
        count++;
    }

    rclcpp::Publisher<sensor_msgs::msg::LaserScan>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_; 

    unsigned int num_readings = 100;
    int laser_frequency = 40;
    double ranges[40];
    double intensities[100];
    int count = 0;
};



int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FakeLaser>());
    rclcpp::shutdown();
    return 0;
}
