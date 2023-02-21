// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from servicios:srv/SaveRoute.idl
// generated code does not contain a copyright notice

#ifndef SERVICIOS__SRV__DETAIL__SAVE_ROUTE__BUILDER_HPP_
#define SERVICIOS__SRV__DETAIL__SAVE_ROUTE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "servicios/srv/detail/save_route__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace servicios
{

namespace srv
{

namespace builder
{

class Init_SaveRoute_Request_c
{
public:
  explicit Init_SaveRoute_Request_c(::servicios::srv::SaveRoute_Request & msg)
  : msg_(msg)
  {}
  ::servicios::srv::SaveRoute_Request c(::servicios::srv::SaveRoute_Request::_c_type arg)
  {
    msg_.c = std::move(arg);
    return std::move(msg_);
  }

private:
  ::servicios::srv::SaveRoute_Request msg_;
};

class Init_SaveRoute_Request_b
{
public:
  explicit Init_SaveRoute_Request_b(::servicios::srv::SaveRoute_Request & msg)
  : msg_(msg)
  {}
  Init_SaveRoute_Request_c b(::servicios::srv::SaveRoute_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_SaveRoute_Request_c(msg_);
  }

private:
  ::servicios::srv::SaveRoute_Request msg_;
};

class Init_SaveRoute_Request_a
{
public:
  Init_SaveRoute_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SaveRoute_Request_b a(::servicios::srv::SaveRoute_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_SaveRoute_Request_b(msg_);
  }

private:
  ::servicios::srv::SaveRoute_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::servicios::srv::SaveRoute_Request>()
{
  return servicios::srv::builder::Init_SaveRoute_Request_a();
}

}  // namespace servicios


namespace servicios
{

namespace srv
{

namespace builder
{

class Init_SaveRoute_Response_sum
{
public:
  Init_SaveRoute_Response_sum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::servicios::srv::SaveRoute_Response sum(::servicios::srv::SaveRoute_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::servicios::srv::SaveRoute_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::servicios::srv::SaveRoute_Response>()
{
  return servicios::srv::builder::Init_SaveRoute_Response_sum();
}

}  // namespace servicios

#endif  // SERVICIOS__SRV__DETAIL__SAVE_ROUTE__BUILDER_HPP_
