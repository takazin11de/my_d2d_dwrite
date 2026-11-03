#ifndef COM_H
#define COM_H

#include <stdbool.h>
#include <stdint.h>

#define DLLEXPORT __declspec(dllexport)
#define DLLIMPORT __declspec(dllimport)
#define STDCALL   __stdcall
#define COMCALL   __stdcall

typedef struct {
  uint64_t x, y;
} Uuid;

static inline bool Uuid_eq(const Uuid *a, const Uuid *b) {
  return (*a).x == (*b).x && (*a).y == (*b).y;
}

#define UUID_VALUE(A, B)                                                                                                                                       \
  ((Uuid){((uint64_t)(0xFFFFFFFF00000000 & (A)) >> 32) | ((uint64_t)(0x00000000FFFF0000 & (A)) << 16) | ((uint64_t)(0x000000000000FFFF & (A)) << 48),          \
          ((uint64_t)(0xFF00000000000000 & (B)) >> 56) | ((uint64_t)(0x00FF000000000000 & (B)) >> 40) | ((uint64_t)(0x0000FF0000000000 & (B)) >> 24) |         \
              ((uint64_t)(0x000000FF00000000 & (B)) >> 8) | ((uint64_t)(0x00000000FF000000 & (B)) << 8) | ((uint64_t)(0x0000000000FF0000 & (B)) << 24) |       \
              ((uint64_t)(0x000000000000FF00 & (B)) << 40) | ((uint64_t)(0x00000000000000FF & (B)) << 56)})

#define DECLARE_UUID(NAME, A, B) const Uuid NAME = UUID_VALUE(A, B)

#define INTERFACE_UUID(Interface)   Interface_iid_##Interface
#define INTERFACE_VTABLE(Interface) Interface_Vtable_##Interface
#define DECLARE_INTERFACE_BASE(Interface, uuid_a, uuid_b)                                                                                                      \
  static const Uuid INTERFACE_UUID(Interface) = UUID_VALUE(uuid_a, uuid_b);                                                                                    \
  typedef struct Interface Interface;                                                                                                                          \
  typedef struct INTERFACE_VTABLE(Interface) INTERFACE_VTABLE(Interface);                                                                                      \
  struct Interface {                                                                                                                                           \
    INTERFACE_VTABLE(Interface) * vtable;                                                                                                                      \
  };                                                                                                                                                           \
  struct INTERFACE_VTABLE(Interface) {
#define DECLARE_INTERFACE(Interface, uuid_a, uuid_b, Inheritance) DECLARE_INTERFACE_BASE(Interface, uuid_a, uuid_b) INTERFACE_VTABLE(Inheritance) _base_;
#define DECLARE_INTERFACE_END                                     }


#endif