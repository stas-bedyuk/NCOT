#ifndef UserDto_hpp
#define UserDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)
 

class UserDto : public oatpp::DTO {
  
  DTO_INIT(UserDto, DTO)

  DTO_FIELD(Int32, id);
  DTO_FIELD(String, phone, "phone");
  DTO_FIELD(String, name, "name");
  DTO_FIELD(String, address, "address");

};

#include OATPP_CODEGEN_END(DTO)

#endif /* UserDto_hpp */
