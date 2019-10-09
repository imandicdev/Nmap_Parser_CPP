#include "pugixml.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
  std::string XML_FILE_PATH = "test.xml";
  pugi::xml_document doc;
  pugi::xml_parse_result result = doc.load_file(XML_FILE_PATH.c_str());
  if (!result)
    {
      std::cout << "Parse error:" << result.description() << ", character pos=" << result.offset;
    }
  
   
 pugi::xpath_node_set titleNode = doc.select_nodes("//elem[@key='title']");
 for (pugi::xpath_node_set::const_iterator itr =titleNode.begin(); itr!= titleNode.end();++itr)
 {
  
   pugi::xml_node node = itr->node();

      

  std::string data = node.child_value();
  
  std::cout << "title :" << data << std::endl;
}

 pugi::xpath_node_set stateNode = doc.select_nodes("//elem[@key='state']");
for (pugi::xpath_node_set::const_iterator itr = stateNode.begin(); itr!= stateNode.end();++itr)
 {
   pugi::xml_node node = itr->node();
  
   std::string data = node.child_value();
   
   std::cout << "state :" << data << std::endl;
}


return 0;  
}
  
