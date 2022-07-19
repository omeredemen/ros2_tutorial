#include "std_msgs/msg/string.hpp"
#include "rclcpp/rclcpp.hpp"


class subscriber_node : public rclcpp::Node{
public:
	subscriber_node(): Node("subscriber_node"){
		subscription_ = this->create_subscription<std_msgs::msg::String>("topic", 10, 
						std::bind(&subscriber_node::callBack, this,std::placeholders::_1));
	}
	
private:
	void callBack(const std_msgs::msg::String::SharedPtr message){
		RCLCPP_INFO(this->get_logger(), "%s", message->data.c_str());	
	}
	
	rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char** argv){
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<subscriber_node>());
	rclcpp::shutdown();
	return 0;
}
