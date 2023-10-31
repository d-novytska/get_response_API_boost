#include "Client.h"
#include <boost/property_tree/ptree.hpp>  
#include <boost/property_tree/json_parser.hpp>

std::string getFieldFromJson(std::string json, std::string field);

int main() {

	Client client;
	
	std::string res = client.getResponse("google.com");
	//std::cout << res << std::endl;
	std::cout << getFieldFromJson(res, "as"); 

	return 0;
}

std::string getFieldFromJson(std::string json, std::string field)
{
	std::stringstream jsonEncoded(json); 
	boost::property_tree::ptree root; 
	boost::property_tree::read_json(jsonEncoded, root); 

	if (root.empty()) {
		return "";
	}

	return root.get<std::string>(field);
}
