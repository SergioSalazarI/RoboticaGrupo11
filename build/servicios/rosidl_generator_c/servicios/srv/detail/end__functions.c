// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from servicios:srv/End.idl
// generated code does not contain a copyright notice
#include "servicios/srv/detail/end__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
servicios__srv__End_Request__init(servicios__srv__End_Request * msg)
{
  if (!msg) {
    return false;
  }
  // end
  return true;
}

void
servicios__srv__End_Request__fini(servicios__srv__End_Request * msg)
{
  if (!msg) {
    return;
  }
  // end
}

bool
servicios__srv__End_Request__are_equal(const servicios__srv__End_Request * lhs, const servicios__srv__End_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // end
  if (lhs->end != rhs->end) {
    return false;
  }
  return true;
}

bool
servicios__srv__End_Request__copy(
  const servicios__srv__End_Request * input,
  servicios__srv__End_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // end
  output->end = input->end;
  return true;
}

servicios__srv__End_Request *
servicios__srv__End_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  servicios__srv__End_Request * msg = (servicios__srv__End_Request *)allocator.allocate(sizeof(servicios__srv__End_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(servicios__srv__End_Request));
  bool success = servicios__srv__End_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
servicios__srv__End_Request__destroy(servicios__srv__End_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    servicios__srv__End_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
servicios__srv__End_Request__Sequence__init(servicios__srv__End_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  servicios__srv__End_Request * data = NULL;

  if (size) {
    data = (servicios__srv__End_Request *)allocator.zero_allocate(size, sizeof(servicios__srv__End_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = servicios__srv__End_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        servicios__srv__End_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
servicios__srv__End_Request__Sequence__fini(servicios__srv__End_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      servicios__srv__End_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

servicios__srv__End_Request__Sequence *
servicios__srv__End_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  servicios__srv__End_Request__Sequence * array = (servicios__srv__End_Request__Sequence *)allocator.allocate(sizeof(servicios__srv__End_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = servicios__srv__End_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
servicios__srv__End_Request__Sequence__destroy(servicios__srv__End_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    servicios__srv__End_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
servicios__srv__End_Request__Sequence__are_equal(const servicios__srv__End_Request__Sequence * lhs, const servicios__srv__End_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!servicios__srv__End_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
servicios__srv__End_Request__Sequence__copy(
  const servicios__srv__End_Request__Sequence * input,
  servicios__srv__End_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(servicios__srv__End_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    servicios__srv__End_Request * data =
      (servicios__srv__End_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!servicios__srv__End_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          servicios__srv__End_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!servicios__srv__End_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
servicios__srv__End_Response__init(servicios__srv__End_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  return true;
}

void
servicios__srv__End_Response__fini(servicios__srv__End_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
}

bool
servicios__srv__End_Response__are_equal(const servicios__srv__End_Response * lhs, const servicios__srv__End_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
servicios__srv__End_Response__copy(
  const servicios__srv__End_Response * input,
  servicios__srv__End_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  output->result = input->result;
  return true;
}

servicios__srv__End_Response *
servicios__srv__End_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  servicios__srv__End_Response * msg = (servicios__srv__End_Response *)allocator.allocate(sizeof(servicios__srv__End_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(servicios__srv__End_Response));
  bool success = servicios__srv__End_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
servicios__srv__End_Response__destroy(servicios__srv__End_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    servicios__srv__End_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
servicios__srv__End_Response__Sequence__init(servicios__srv__End_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  servicios__srv__End_Response * data = NULL;

  if (size) {
    data = (servicios__srv__End_Response *)allocator.zero_allocate(size, sizeof(servicios__srv__End_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = servicios__srv__End_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        servicios__srv__End_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
servicios__srv__End_Response__Sequence__fini(servicios__srv__End_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      servicios__srv__End_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

servicios__srv__End_Response__Sequence *
servicios__srv__End_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  servicios__srv__End_Response__Sequence * array = (servicios__srv__End_Response__Sequence *)allocator.allocate(sizeof(servicios__srv__End_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = servicios__srv__End_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
servicios__srv__End_Response__Sequence__destroy(servicios__srv__End_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    servicios__srv__End_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
servicios__srv__End_Response__Sequence__are_equal(const servicios__srv__End_Response__Sequence * lhs, const servicios__srv__End_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!servicios__srv__End_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
servicios__srv__End_Response__Sequence__copy(
  const servicios__srv__End_Response__Sequence * input,
  servicios__srv__End_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(servicios__srv__End_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    servicios__srv__End_Response * data =
      (servicios__srv__End_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!servicios__srv__End_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          servicios__srv__End_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!servicios__srv__End_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
