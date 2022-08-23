#include <memory>
#include <stdio.h>
#include <unistd.h>
#include <iostream>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/range.hpp"

class fakeRange : public rclcpp::Node
{
public:
    fakeRange() : Node("fakeRange_pub")
    {
        pub_ = this->create_publisher<sensor_msgs::msg::Range>("fakeRange", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(1000/freq),
                                         std::bind(&fakeRange::ToFCallback, this));

    }

private:
    void ToFCallback(){
        
        rclcpp::Time now = this->get_clock()->now();
        auto message = sensor_msgs::msg::Range();
        message.header.frame_id = "fake_range";
        message.header.stamp = now;
        message.radiation_type = sensor_msgs::msg::Range::INFRARED;
        message.field_of_view = 0.47;              // Typically 27 degrees or 0,471239 radians
        message.min_range = 0.19;                  // 190 mm.  
        message.max_range = 3.00;                  // 3.6 m. 
        
        message.range = range[count_];
        
        RCLCPP_INFO(this->get_logger(), "range is %f\n", message.range);

        if((message.range >= message.min_range) && (message.range <= message.max_range)) {
            pub_->publish(message);
        }
        count_++;
        if (count_==7)count_ = 0;
        
    }

    rclcpp::Publisher<sensor_msgs::msg::Range>::SharedPtr pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    int freq = 50;
    float range[7] = {0.2,0.5, 1, 1.5, 2, 2.5, 3};
    int count_ = 0;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<fakeRange>());
    rclcpp::shutdown();
    return 0;
}
