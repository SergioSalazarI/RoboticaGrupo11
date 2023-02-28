// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from servicios:srv/Save.idl
// generated code does not contain a copyright notice

#ifndef SERVICIOS__SRV__DETAIL__SAVE__TRAITS_HPP_
#define SERVICIOS__SRV__DETAIL__SAVE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "servicios/srv/detail/save__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace servicios
{

namespace srv
{

inline void to_flow_style_yaml(
  const Save_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: save
  {
    out << "save: ";
    rosidl_generator_traits::value_to_yaml(msg.save, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Save_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: save
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "save: ";
    rosidl_generator_traits::value_to_yaml(msg.save, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Save_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace servicios

namespace rosidl_generator_traits
{

[[deprecated("use servicios::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const servicios::srv::Save_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  servicios::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use servicios::srv::to_yaml() instead")]]
inline std::string to_yaml(const servicios::srv::Save_Request & msg)
{
  return servicios::srv::to_yaml(msg);
}

template<>
inline const char * data_type<servicios::srv::Save_Request>()
{
  return "servicios::srv::Save_Request";
}

template<>
inline const char * name<servicios::srv::Save_Request>()
{
  return "servicios/srv/Save_Request";
}

template<>
struct has_fixed_size<servicios::srv::Save_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<servicios::srv::Save_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<servicios::srv::Save_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace servicios
{

namespace srv
{

inline void to_flow_style_yaml(
  const Save_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Save_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Save_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace servicios

namespace rosidl_generator_traits
{

[[deprecated("use servicios::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const servicios::srv::Save_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  servicios::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use servicios::srv::to_yaml() instead")]]
inline std::string to_yaml(const servicios::srv::Save_Response & msg)
{
  return servicios::srv::to_yaml(msg);
}

template<>
inline const char * data_type<servicios::srv::Save_Response>()
{
  return "servicios::srv::Save_Response";
}

template<>
inline const char * name<servicios::srv::Save_Response>()
{
  return "servicios/srv/Save_Response";
}

template<>
struct has_fixed_size<servicios::srv::Save_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<servicios::srv::Save_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<servicios::srv::Save_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<servicios::srv::Save>()
{
  return "servicios::srv::Save";
}

template<>
inline const char * name<servicios::srv::Save>()
{
  return "servicios/srv/Save";
}

template<>
struct has_fixed_size<servicios::srv::Save>
  : std::integral_constant<
    bool,
    has_fixed_size<servicios::srv::Save_Request>::value &&
    has_fixed_size<servicios::srv::Save_Response>::value
  >
{
};

template<>
struct has_bounded_size<servicios::srv::Save>
  : std::integral_constant<
    bool,
    has_bounded_size<servicios::srv::Save_Request>::value &&
    has_bounded_size<servicios::srv::Save_Response>::value
  >
{
};

template<>
struct is_service<servicios::srv::Save>
  : std::true_type
{
};

template<>
struct is_service_request<servicios::srv::Save_Request>
  : std::true_type
{
};

template<>
struct is_service_response<servicios::srv::Save_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SERVICIOS__SRV__DETAIL__SAVE__TRAITS_HPP_
