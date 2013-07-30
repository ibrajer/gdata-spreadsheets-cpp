#ifndef GDATA_SPREADSHEETS_CPP_SPREADSHEETS_SERVICE_H_
#define GDATA_SPREADSHEETS_CPP_SPREADSHEETS_SERVICE_H_

#include <string>

namespace gdata {
namespace service {

class SpreadsheetsService
{
 public:
	SpreadsheetsService();
	~SpreadsheetsService();

	std::string get_spreadsheets_feed();

	void set_authorization_token(const std::string& token);

 private:
	std::string m_token;
};

} // namespace service
} // namespce gdata

#endif /* GDATA_SPREADSHEETS_CPP_SPREADSHEETS_SERVICE_H_ */
