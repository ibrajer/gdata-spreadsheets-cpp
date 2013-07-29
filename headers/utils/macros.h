#ifndef MACROS_H_
#define MACROS_H_

namespace gdata {
namespace utils {

// C/P from Google C++ Style Guide:
// A macro to disallow the copy constructor and operator= functions
// This should be used in the private: declarations for a class
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
  TypeName(const TypeName&);               \
  void operator=(const TypeName&)

} // namespace gdata
} // namespace utils


#endif /* MACROS_H_ */
