#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class publisher_node: public rclcpp::Node
{
    public:
        publisher_node(): Node("publisher_node"), counter_(1){
            publisher_ = this-> create_publisher<std_msgs::msg::String>("topic", 10);
            timer_ = this -> create_wall_timer(std::chrono::milliseconds(1000),
                                               std::bind(&publisher_node::callBack,this));
        }


    private:
        void callBack(){
            auto message = std_msgs::msg::String();
            message.data = "This mesagge is the "+ std::to_string(counter_) + ". published message from publisher node" ;
            publisher_->publish(message);
            counter_++;
        }
        
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        uint64_t counter_;
};

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<publisher_node>());
    rclcpp::shutdown();
    return 0;
}
