// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from servicios:srv/Save.idl
// generated code does not contain a copyright notice

#ifndef SERVICIOS__SRV__DETAIL__SAVE__STRUCT_H_
#define SERVICIOS__SRV__DETAIL__SAVE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Save in the package servicios.
typedef struct servicios__srv__Save_Request
{
  bool save;
} servicios__srv__Save_Request;

// Struct for a sequence of servicios__srv__Save_Request.
typedef struct servicios__srv__Save_Request__Sequence
{
  servicios__srv__Save_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} servicios__srv__Save_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Save in the package servicios.
typedef struct servicios__srv__Save_Response
{
  bool result;
} servicios__srv__Save_Response;

// Struct for a sequence of servicios__srv__Save_Response.
typedef struct servicios__srv__Save_Response__Sequence
{
  servicios__srv__Save_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} servicios__srv__Save_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERVICIOS__SRV__DETAIL__SAVE__STRUCT_H_
