#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "geometry_msgs/msg/twist.hpp"

class myTurtle: public rclcpp::Node
{
    public:
        myTurtle(): Node("myTurtle_Node"){
            joy_sub = this->create_subscription<sensor_msgs::msg::Joy>("joy",100,
            std::bind(&myTurtle::callback,this,std::placeholders::_1));

            twist_pub = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel",1);
        }

    private:
        void callback(sensor_msgs::msg::Joy::SharedPtr joy_msgs){
            twist.linear.x = joy_msgs->axes[0];
            twist.linear.x = joy_msgs->axes[1];
            twist.angular.z = joy_msgs->axes[3];
            twist_pub->publish(twist);
        }
        geometry_msgs::msg::Twist twist;
        rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_sub;
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr twist_pub;
        
};

int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<myTurtle>());
    rclcpp::shutdown();

    return 0;
}
