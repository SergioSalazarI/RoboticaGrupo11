// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from servicios:srv/End.idl
// generated code does not contain a copyright notice

#ifndef SERVICIOS__SRV__DETAIL__END__STRUCT_H_
#define SERVICIOS__SRV__DETAIL__END__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/End in the package servicios.
typedef struct servicios__srv__End_Request
{
  bool end;
} servicios__srv__End_Request;

// Struct for a sequence of servicios__srv__End_Request.
typedef struct servicios__srv__End_Request__Sequence
{
  servicios__srv__End_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} servicios__srv__End_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/End in the package servicios.
typedef struct servicios__srv__End_Response
{
  bool result;
} servicios__srv__End_Response;

// Struct for a sequence of servicios__srv__End_Response.
typedef struct servicios__srv__End_Response__Sequence
{
  servicios__srv__End_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} servicios__srv__End_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERVICIOS__SRV__DETAIL__END__STRUCT_H_
