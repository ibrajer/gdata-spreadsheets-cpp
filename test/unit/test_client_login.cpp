#include <gtest/gtest.h>

#include "../../headers/auth/client_login.h"
#include "mocks/http_query_mock.h"

namespace gdata {
namespace test {

TEST(ClientLogin, GetAuthorizationToken)
{
	auth::ClientLogin login("user@gmail.com", "password");
	std::string mock_output = "SID=DQAAAGgA...7Zg8CTN\nLSID=DQAAAGsA...lk8BBbG\nAuth=DQAAAGgA...dk3fA5N";

	std::unique_ptr<service::HTTPQueryInterface> query(new HTTPQueryMock());

	HTTPQueryMock* mock = dynamic_cast<HTTPQueryMock*>(query.get());

	EXPECT_CALL(*mock, set_uri(::testing::_)).Times(1);
	EXPECT_CALL(*mock, set_method(::testing::_)).Times(1);
	EXPECT_CALL(*mock, add_header(::testing::_, ::testing::_)).Times(2);
	EXPECT_CALL(*mock, add_query_field(::testing::_, ::testing::_)).Times(5);
	EXPECT_CALL(*mock, run()).WillOnce(::testing::Return(mock_output));

	EXPECT_STREQ(login.get_authorization_token(query).c_str(), "DQAAAGgA...dk3fA5N");
}

} // namespace test
} // namespace gdata
