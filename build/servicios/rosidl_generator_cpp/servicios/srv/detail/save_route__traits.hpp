// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from servicios:srv/SaveRoute.idl
// generated code does not contain a copyright notice

#ifndef SERVICIOS__SRV__DETAIL__SAVE_ROUTE__TRAITS_HPP_
#define SERVICIOS__SRV__DETAIL__SAVE_ROUTE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "servicios/srv/detail/save_route__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace servicios
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveRoute_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << ", ";
  }

  // member: c
  {
    out << "c: ";
    rosidl_generator_traits::value_to_yaml(msg.c, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveRoute_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }

  // member: c
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "c: ";
    rosidl_generator_traits::value_to_yaml(msg.c, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveRoute_Request & msg, bool use_flow_style = false)
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
  const servicios::srv::SaveRoute_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  servicios::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use servicios::srv::to_yaml() instead")]]
inline std::string to_yaml(const servicios::srv::SaveRoute_Request & msg)
{
  return servicios::srv::to_yaml(msg);
}

template<>
inline const char * data_type<servicios::srv::SaveRoute_Request>()
{
  return "servicios::srv::SaveRoute_Request";
}

template<>
inline const char * name<servicios::srv::SaveRoute_Request>()
{
  return "servicios/srv/SaveRoute_Request";
}

template<>
struct has_fixed_size<servicios::srv::SaveRoute_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<servicios::srv::SaveRoute_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<servicios::srv::SaveRoute_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace servicios
{

namespace srv
{

inline void to_flow_style_yaml(
  const SaveRoute_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: sum
  {
    out << "sum: ";
    rosidl_generator_traits::value_to_yaml(msg.sum, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SaveRoute_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sum
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "sum: ";
    rosidl_generator_traits::value_to_yaml(msg.sum, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SaveRoute_Response & msg, bool use_flow_style = false)
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
  const servicios::srv::SaveRoute_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  servicios::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use servicios::srv::to_yaml() instead")]]
inline std::string to_yaml(const servicios::srv::SaveRoute_Response & msg)
{
  return servicios::srv::to_yaml(msg);
}

template<>
inline const char * data_type<servicios::srv::SaveRoute_Response>()
{
  return "servicios::srv::SaveRoute_Response";
}

template<>
inline const char * name<servicios::srv::SaveRoute_Response>()
{
  return "servicios/srv/SaveRoute_Response";
}

template<>
struct has_fixed_size<servicios::srv::SaveRoute_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<servicios::srv::SaveRoute_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<servicios::srv::SaveRoute_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<servicios::srv::SaveRoute>()
{
  return "servicios::srv::SaveRoute";
}

template<>
inline const char * name<servicios::srv::SaveRoute>()
{
  return "servicios/srv/SaveRoute";
}

template<>
struct has_fixed_size<servicios::srv::SaveRoute>
  : std::integral_constant<
    bool,
    has_fixed_size<servicios::srv::SaveRoute_Request>::value &&
    has_fixed_size<servicios::srv::SaveRoute_Response>::value
  >
{
};

template<>
struct has_bounded_size<servicios::srv::SaveRoute>
  : std::integral_constant<
    bool,
    has_bounded_size<servicios::srv::SaveRoute_Request>::value &&
    has_bounded_size<servicios::srv::SaveRoute_Response>::value
  >
{
};

template<>
struct is_service<servicios::srv::SaveRoute>
  : std::true_type
{
};

template<>
struct is_service_request<servicios::srv::SaveRoute_Request>
  : std::true_type
{
};

template<>
struct is_service_response<servicios::srv::SaveRoute_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SERVICIOS__SRV__DETAIL__SAVE_ROUTE__TRAITS_HPP_