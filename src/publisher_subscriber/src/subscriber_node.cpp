#include "rclcpp/rclcpp.hpp"
#include "tutorial_interfaces/msg/num.hpp"

class subscriber_node : public rclcpp::Node{
public:
	subscriber_node(): Node("subscriber_node"){
		subscription_ = this->create_subscription<tutorial_interfaces::msg::Num>("topic", 10, 
						std::bind(&subscriber_node::callBack, this,std::placeholders::_1));
	}
	
private:
	void callBack(const tutorial_interfaces::msg::Num message){
		RCLCPP_INFO(this->get_logger(), "%ld", message.num);	
	}
	
	rclcpp::Subscription<tutorial_interfaces::msg::Num>::SharedPtr subscription_;
};

int main(int argc, char** argv){
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<subscriber_node>());
	rclcpp::shutdown();
	return 0;
}
