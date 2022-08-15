#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"

class publisher_node: public rclcpp::Node
{
    public:
        publisher_node(): Node("publisher_node"),counter_(1){
            publisher_ = this-> create_publisher<tutorial_interfaces::msg::Num>("topic", 10);
            timer_ = this -> create_wall_timer(std::chrono::milliseconds(1000),
                                               std::bind(&publisher_node::callBack,this));
        }


    private:
        void callBack(){
            auto message = tutorial_interfaces::msg::Num();
            message.num = counter_;
            publisher_->publish(message);
            counter_++;
        }
        
        rclcpp::Publisher<tutorial_interfaces::msg::Num>::SharedPtr publisher_;
        rclcpp::TimerBase::SharedPtr timer_;
        int counter_;
};

int main(int argc, char** argv){
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<publisher_node>());
    rclcpp::shutdown();
    return 0;
}
