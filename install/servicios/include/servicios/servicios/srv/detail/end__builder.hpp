// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from servicios:srv/End.idl
// generated code does not contain a copyright notice

#ifndef SERVICIOS__SRV__DETAIL__END__BUILDER_HPP_
#define SERVICIOS__SRV__DETAIL__END__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "servicios/srv/detail/end__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace servicios
{

namespace srv
{

namespace builder
{

class Init_End_Request_end
{
public:
  Init_End_Request_end()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::servicios::srv::End_Request end(::servicios::srv::End_Request::_end_type arg)
  {
    msg_.end = std::move(arg);
    return std::move(msg_);
  }

private:
  ::servicios::srv::End_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::servicios::srv::End_Request>()
{
  return servicios::srv::builder::Init_End_Request_end();
}

}  // namespace servicios


namespace servicios
{

namespace srv
{

namespace builder
{

class Init_End_Response_result
{
public:
  Init_End_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::servicios::srv::End_Response result(::servicios::srv::End_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::servicios::srv::End_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::servicios::srv::End_Response>()
{
  return servicios::srv::builder::Init_End_Response_result();
}

}  // namespace servicios

#endif  // SERVICIOS__SRV__DETAIL__END__BUILDER_HPP_
