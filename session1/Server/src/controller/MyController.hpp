//
//  MyController.hpp
//  web-starter-project
//
//  Created by Leonid on 2/12/18.
//  Copyright © 2018 oatpp. All rights reserved.
//

#ifndef MyController_hpp
#define MyController_hpp

#include "../dto/DTOs.hpp"

#include <oatpp/web/server/api/ApiController.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/macro/component.hpp>

/**
 * Sample Api Controller.
 */
class MyController : public oatpp::web::server::api::ApiController {
public:
  /**
   * Constructor with object mapper.
   * @param objectMapper - default object mapper used to serialize/deserialize DTOs.
   */
  MyController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
    : oatpp::web::server::api::ApiController(objectMapper)
  {}
public:
  
/**
 *  Begin ENDPOINTs generation ('ApiController' codegen)
 */
#include OATPP_CODEGEN_BEGIN(ApiController)
  
  ENDPOINT("GET", "/", root) {
    auto dto = MyDto::createShared();
    dto->statusCode = 200;
    dto->message = "Hello World!";
    return createDtoResponse(Status::CODE_200, dto);
   }
    ENDPOINT("GET", "/users/{my-path-variable}", getUserById,
         PATH(Int64, userId, "my-path-variable")) 
  {
      OATPP_LOGD("Test", "userId=%d", userId->getValue());
      return createResponse(Status::CODE_200, 87);
  }

  ENDPOINT("GET", "/users", getUsers,
         QUERY(Int32, age, "user-age")) 
{
  OATPP_LOGD("Test", "age=%d", age->getValue());
  return createResponse(Status::CODE_200, "55");
}

ENDPOINT("GET", "/usersInfo", getUsersInfo,
         QUERY(Int32, Id, "user-id")) 
{
  OATPP_LOGD("Test", "id = %d", Id->getValue());
  auto userInfoDto = UserInfoDto::createShared();
  userInfoDto->age = 24;
  userInfoDto->name = "Yang chao";
  userInfoDto->address = "China";
  return createDtoResponse(Status::CODE_200, userInfoDto);
}
  
  // TODO Insert Your endpoints here !!!
  
/**
 *  Finish ENDPOINTs generation ('ApiController' codegen)
 */
#include OATPP_CODEGEN_END(ApiController)
  
};

#endif /* MyController_hpp */
