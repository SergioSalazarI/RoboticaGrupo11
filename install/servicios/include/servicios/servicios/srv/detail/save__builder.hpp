// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from servicios:srv/Save.idl
// generated code does not contain a copyright notice

#ifndef SERVICIOS__SRV__DETAIL__SAVE__BUILDER_HPP_
#define SERVICIOS__SRV__DETAIL__SAVE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "servicios/srv/detail/save__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace servicios
{

namespace srv
{

namespace builder
{

class Init_Save_Request_save
{
public:
  Init_Save_Request_save()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::servicios::srv::Save_Request save(::servicios::srv::Save_Request::_save_type arg)
  {
    msg_.save = std::move(arg);
    return std::move(msg_);
  }

private:
  ::servicios::srv::Save_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::servicios::srv::Save_Request>()
{
  return servicios::srv::builder::Init_Save_Request_save();
}

}  // namespace servicios


namespace servicios
{

namespace srv
{

namespace builder
{

class Init_Save_Response_result
{
public:
  Init_Save_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::servicios::srv::Save_Response result(::servicios::srv::Save_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::servicios::srv::Save_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::servicios::srv::Save_Response>()
{
  return servicios::srv::builder::Init_Save_Response_result();
}

}  // namespace servicios

#endif  // SERVICIOS__SRV__DETAIL__SAVE__BUILDER_HPP_
