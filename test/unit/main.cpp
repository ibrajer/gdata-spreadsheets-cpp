#include <gtest/gtest.h>

namespace gdata {
namespace test {

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} // namespace test
} // namespace gdata
