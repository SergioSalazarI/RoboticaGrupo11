// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from servicios:srv/Save.idl
// generated code does not contain a copyright notice

#ifndef SERVICIOS__SRV__DETAIL__SAVE__STRUCT_HPP_
#define SERVICIOS__SRV__DETAIL__SAVE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__servicios__srv__Save_Request __attribute__((deprecated))
#else
# define DEPRECATED__servicios__srv__Save_Request __declspec(deprecated)
#endif

namespace servicios
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Save_Request_
{
  using Type = Save_Request_<ContainerAllocator>;

  explicit Save_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->save = false;
    }
  }

  explicit Save_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->save = false;
    }
  }

  // field types and members
  using _save_type =
    bool;
  _save_type save;

  // setters for named parameter idiom
  Type & set__save(
    const bool & _arg)
  {
    this->save = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    servicios::srv::Save_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const servicios::srv::Save_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<servicios::srv::Save_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<servicios::srv::Save_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      servicios::srv::Save_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<servicios::srv::Save_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      servicios::srv::Save_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<servicios::srv::Save_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<servicios::srv::Save_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<servicios::srv::Save_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__servicios__srv__Save_Request
    std::shared_ptr<servicios::srv::Save_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__servicios__srv__Save_Request
    std::shared_ptr<servicios::srv::Save_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Save_Request_ & other) const
  {
    if (this->save != other.save) {
      return false;
    }
    return true;
  }
  bool operator!=(const Save_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Save_Request_

// alias to use template instance with default allocator
using Save_Request =
  servicios::srv::Save_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace servicios


#ifndef _WIN32
# define DEPRECATED__servicios__srv__Save_Response __attribute__((deprecated))
#else
# define DEPRECATED__servicios__srv__Save_Response __declspec(deprecated)
#endif

namespace servicios
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Save_Response_
{
  using Type = Save_Response_<ContainerAllocator>;

  explicit Save_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  explicit Save_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = false;
    }
  }

  // field types and members
  using _result_type =
    bool;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const bool & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    servicios::srv::Save_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const servicios::srv::Save_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<servicios::srv::Save_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<servicios::srv::Save_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      servicios::srv::Save_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<servicios::srv::Save_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      servicios::srv::Save_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<servicios::srv::Save_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<servicios::srv::Save_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<servicios::srv::Save_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__servicios__srv__Save_Response
    std::shared_ptr<servicios::srv::Save_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__servicios__srv__Save_Response
    std::shared_ptr<servicios::srv::Save_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Save_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Save_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Save_Response_

// alias to use template instance with default allocator
using Save_Response =
  servicios::srv::Save_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace servicios

namespace servicios
{

namespace srv
{

struct Save
{
  using Request = servicios::srv::Save_Request;
  using Response = servicios::srv::Save_Response;
};

}  // namespace srv

}  // namespace servicios

#endif  // SERVICIOS__SRV__DETAIL__SAVE__STRUCT_HPP_
